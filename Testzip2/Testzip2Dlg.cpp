
// Testzip2Dlg.cpp : 实现文件
//

#include "stdafx.h"
#include "Testzip2.h"
#include "Testzip2Dlg.h"

#include "zip\ZipImplement.h"
#include <vector>
#include <string>
using namespace std;

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// 用于应用程序“关于”菜单项的 CAboutDlg 对话框

class CAboutDlg : public CDialog
{
public:
	CAboutDlg();

// 对话框数据
	enum { IDD = IDD_ABOUTBOX };

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 支持

// 实现
protected:
	DECLARE_MESSAGE_MAP()
};

CAboutDlg::CAboutDlg() : CDialog(CAboutDlg::IDD)
{
}

void CAboutDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
}

BEGIN_MESSAGE_MAP(CAboutDlg, CDialog)
END_MESSAGE_MAP()


// CTestzip2Dlg 对话框




CTestzip2Dlg::CTestzip2Dlg(CWnd* pParent /*=NULL*/)
	: CDialog(CTestzip2Dlg::IDD, pParent)
{
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void CTestzip2Dlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
}

BEGIN_MESSAGE_MAP(CTestzip2Dlg, CDialog)
	ON_WM_SYSCOMMAND()
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	//}}AFX_MSG_MAP
	ON_BN_CLICKED(IDC_BTN_ZIP, &CTestzip2Dlg::OnBnClickedBtnZip)
	ON_BN_CLICKED(IDC_BTN_UZIP, &CTestzip2Dlg::OnBnClickedBtnUzip)
	ON_BN_CLICKED(IDC_BTN_RARZ, &CTestzip2Dlg::OnBnClickedBtnRarz)
	ON_BN_CLICKED(IDC_RARUZ, &CTestzip2Dlg::OnBnClickedRaruz)
END_MESSAGE_MAP()


// CTestzip2Dlg 消息处理程序

BOOL CTestzip2Dlg::OnInitDialog()
{
	CDialog::OnInitDialog();

	// 将“关于...”菜单项添加到系统菜单中。

	// IDM_ABOUTBOX 必须在系统命令范围内。
	ASSERT((IDM_ABOUTBOX & 0xFFF0) == IDM_ABOUTBOX);
	ASSERT(IDM_ABOUTBOX < 0xF000);

	CMenu* pSysMenu = GetSystemMenu(FALSE);
	if (pSysMenu != NULL)
	{
		BOOL bNameValid;
		CString strAboutMenu;
		bNameValid = strAboutMenu.LoadString(IDS_ABOUTBOX);
		ASSERT(bNameValid);
		if (!strAboutMenu.IsEmpty())
		{
			pSysMenu->AppendMenu(MF_SEPARATOR);
			pSysMenu->AppendMenu(MF_STRING, IDM_ABOUTBOX, strAboutMenu);
		}
	}

	// 设置此对话框的图标。当应用程序主窗口不是对话框时，框架将自动
	//  执行此操作
	SetIcon(m_hIcon, TRUE);			// 设置大图标
	SetIcon(m_hIcon, FALSE);		// 设置小图标

	// TODO: 在此添加额外的初始化代码

	return TRUE;  // 除非将焦点设置到控件，否则返回 TRUE
}

void CTestzip2Dlg::OnSysCommand(UINT nID, LPARAM lParam)
{
	if ((nID & 0xFFF0) == IDM_ABOUTBOX)
	{
		CAboutDlg dlgAbout;
		dlgAbout.DoModal();
	}
	else
	{
		CDialog::OnSysCommand(nID, lParam);
	}
}

// 如果向对话框添加最小化按钮，则需要下面的代码
//  来绘制该图标。对于使用文档/视图模型的 MFC 应用程序，
//  这将由框架自动完成。

void CTestzip2Dlg::OnPaint()
{
	if (IsIconic())
	{
		CPaintDC dc(this); // 用于绘制的设备上下文

		SendMessage(WM_ICONERASEBKGND, reinterpret_cast<WPARAM>(dc.GetSafeHdc()), 0);

		// 使图标在工作区矩形中居中
		int cxIcon = GetSystemMetrics(SM_CXICON);
		int cyIcon = GetSystemMetrics(SM_CYICON);
		CRect rect;
		GetClientRect(&rect);
		int x = (rect.Width() - cxIcon + 1) / 2;
		int y = (rect.Height() - cyIcon + 1) / 2;

		// 绘制图标
		dc.DrawIcon(x, y, m_hIcon);
	}
	else
	{
		CDialog::OnPaint();
	}
}

//当用户拖动最小化窗口时系统调用此函数取得光标
//显示。
HCURSOR CTestzip2Dlg::OnQueryDragIcon()
{
	return static_cast<HCURSOR>(m_hIcon);
}


void CTestzip2Dlg::OnBnClickedBtnZip()
{
	// TODO: 在此添加控件通知处理程序代码

	//OID.2.5.4.88=00001, OID.2.5.4.26=市辖区, OID.2.5.4.45=entCert2, C=CN, S=江苏省, 
	//L=南京市, O=测试sm2证书20170427, OU=666, CN=测试sm2证书20170427
	CString strTmp = "OID.2.5.4.88=00001, OID.2.5.4.26=市辖区, OID.2.5.4.45=entCert2, C=CN, S=江苏省, L=南京市, O=测试sm2证书20170427, OU=666, CN=测试sm2证书20170427";
	int nFind = strTmp.Find("CN=");
	if (nFind != -1)
	{
		strTmp = strTmp.Right(strTmp.GetLength()-(nFind+3));
	}


	SYSTEMTIME sys,sys2;
	GetLocalTime(&sys);

	CZipImplement compress;
	CString strDirPath = "D:\\csm\\session";
	CString strZipFilePath ="D:\\csm\\session.zip";
	compress.Zip_PackFiles(strDirPath,strZipFilePath);//只是个Demo就不开线程去做了
	GetLocalTime(&sys2);
	CString strInfo;
	strInfo.Format("压缩完成！花费时间%d",(sys2.wMinute*60+sys2.wSecond)-(sys.wMinute*60+sys.wSecond));

	MessageBox(strInfo,_T("完成"),MB_ICONINFORMATION);
}

void CTestzip2Dlg::OnBnClickedBtnUzip()
{
	// TODO: 在此添加控件通知处理程序代码
	SYSTEMTIME sys,sys2;
	GetLocalTime(&sys);
	CZipImplement compress;
	CString strDirPath = "D:\\csm\\session3";
	CString strZipFilePath ="D:\\11.zip";
	compress.Zip_UnPackFiles(strZipFilePath,strDirPath);//只是个Demo就不开线程去做了
	GetLocalTime(&sys2);
	CString strInfo;
	strInfo.Format("解压完成！花费时间%d",(sys2.wMinute*60+sys2.wSecond)-(sys.wMinute*60+sys.wSecond));
	MessageBox(strInfo,_T("完成"),MB_ICONINFORMATION);
}

void CTestzip2Dlg::OnBnClickedBtnRarz()
{
	// TODO: 在此添加控件通知处理程序代码
}

void trimString(std::string & str )
{
	int s = str.find_first_not_of(" ");
	int e = str.find_last_not_of(" ");
	str = str.substr(s,e-s+1);
	return;
}

BOOL IsFile(const std::string& szBuf)
{
	int nFind = szBuf.find('A');
	if (nFind ==std::string::npos)
	{
		return FALSE;
	}

	if (nFind>20)
	{
		return FALSE;
	}

	return TRUE;
}


//属性      大小    压缩率   日期   时间   校验和  名称
//----------- ---------  -------- ----- -------- -----  --------  ----
//*   ..A....        24        48 200%  22-05-17 13:47  7016A1A4  qq20170522134750.txt
//*   ..A....        10        32 320%  22-05-17 13:49  427B7148  新建文件夹\qq2017052213475020170522134910.txt
//*   ..A....        24        48 200%  24-05-17 17:03  7016A1A4  新建文件夹\qq20170524170343.txt
//*   ..A....        10        32 320%  22-05-17 13:52  427B7148  qq2017052213475020170522135208.txt
//...D...         0         0   0%  26-05-17 10:12  00000000  新建文件夹       
//----------- ---------  -------- ----- -------- -----  --------  ----
//68       160 235%                            5

BOOL GetFileNames(char* chBuf)
{
	vector<string> vecNames;
	string szInfo = chBuf;
	string szLable="----------- ---------  -------- ----- -------- -----  --------  ----\r\n";//开始的标识
	size_t nFind = 0;
	nFind = szInfo.find(szLable);
	if (nFind == string::npos)
	{
		return FALSE;
	}

	int nEnd = szInfo.find(szLable, nFind+szLable.length());//找到结束标识
	if (string::npos == nEnd)
	{
		szInfo = szInfo.substr(nFind+ szLable.length());
	}
	else
	{
		szInfo = szInfo.substr(nFind+ szLable.length(),(nEnd-nFind-szLable.length()));
	}

	nFind = -1;
	int nBegin = -1;
	string szData;
	while(1)
	{
		nFind = szInfo.find("\r\n");
		if (string::npos == nFind)
		{
			break;
		}

		//得到一条压缩记录
		szData = szInfo.substr(0,nFind);
		trimString(szData);

		//是文件夹还是文件
		if (IsFile(szData))
		{
			nBegin = szData.rfind(' ');
			if (string::npos == nBegin)
			{
				break;
			}

			int nFind2 = szData.rfind('\\');
			if (string::npos == nFind2)
			{
				vecNames.push_back(szData.substr(nBegin+1));
			}
			else
			{
				vecNames.push_back(szData.substr(nFind2+1));
			}
		}	

		szInfo = szInfo.substr(nFind+2);
		nFind = szInfo.find("\r\n");	
	}

	return TRUE;
}

DWORD CTestzip2Dlg::DoCreateProcessHandle_WaitMsg(CString sAppsPath, CString sAppsPar, int dlg_flags, int nTimes, CString& csMsg, CString csCommandKey)
{
	SECURITY_ATTRIBUTES sa;  
	HANDLE hRead,hWrite;  
	sa.nLength				= sizeof(SECURITY_ATTRIBUTES);  
	sa.lpSecurityDescriptor = NULL;  
	sa.bInheritHandle		= TRUE;  
	if (!CreatePipe(&hRead, &hWrite, &sa, 0))   
	{  
		return -1;  
	}

	HANDLE hHand = NULL;
	PROCESS_INFORMATION pi;																						//线程的信息
	STARTUPINFO siStartInfo;																					//该结构用于指定新进程的主窗口特性
	memset(&pi, 0, sizeof(pi));
	ZeroMemory( &siStartInfo, sizeof(STARTUPINFO) );  	

	siStartInfo.cb = sizeof(STARTUPINFO);
	GetStartupInfo(&siStartInfo); 
	if(dlg_flags >= 1)
	{
		siStartInfo.wShowWindow =SW_SHOW;    
	}
	else 
	{
		siStartInfo.wShowWindow =SW_HIDE;									
	}
	siStartInfo.hStdError	= hWrite;																			//把创建进程的标准错误输出重定向到管道输入  
	siStartInfo.hStdOutput	= hWrite;																			//把创建进程的标准输出重定向到管道输入  
	siStartInfo.dwFlags		= STARTF_USESHOWWINDOW | STARTF_USESTDHANDLES;
	// 创建进程
	if (!CreateProcess(	NULL,
						(sAppsPath + sAppsPar).GetBuffer(), 
						NULL, 
						NULL, 
						true,
						CREATE_NEW_CONSOLE, 
						NULL, 
						NULL, 
						&siStartInfo, 
						&pi))
	{
		return -1;
	}


	{
		Sleep(250);
		char	buffer[4096] = {0};																//用4K的空间来存储输出的内容，只要不是显示文件内容，一般情况下是够用了。  
		DWORD	bytesRead;   
		DWORD	dwTotalArrival = 0;
		BOOL	bRet = FALSE;
		int nOntimeCount = 20;
		if(nTimes >= 1)
		{
			nOntimeCount = nTimes * 10;
		}
		else
		{
			nOntimeCount = 3 * 10;				// 默认3秒
		}



		while (nOntimeCount >= 1)   
		{  
			dwTotalArrival = -1;
			bRet = PeekNamedPipe(hRead, NULL, 0, NULL, &dwTotalArrival, NULL);
			if (bRet && (dwTotalArrival > 0))
			{
				if (ReadFile(hRead, buffer, 4095, &bytesRead,NULL) != NULL)
				{
					GetFileNames(buffer);
					break;
				}
			}
			Sleep(100);
			nOntimeCount --;
		}  
		if(pi.hProcess != NULL)
		{
			//TerminateProcess(pi.hProcess, 0);
		}
	}

	CloseHandle(hRead);
	CloseHandle(hWrite);

	//CloseHandle(pi.hThread);	
	//CloseHandle(pi.hProcess);

	return 1;
} 


void CTestzip2Dlg::OnBnClickedRaruz()
{
	// TODO: 在此添加控件通知处理程序代码
	CString csMsg,strKey;

	DoCreateProcessHandle_WaitMsg("D:\\Tool\\WinRAR\\UnRAR.exe",
		                          " v D:\\recvfile\\testfile.rar D:\\csm\\",
								  0,
								  10,
								  csMsg,
								  strKey);
//	system("C:\\Program Files (x86)\\WinRAR\\UnRAR.exe v D:\\testfile\\33.rar D:\\csm\\ >D:\\csm\\data.txt");
}


int CTestzip2Dlg::test1()
{
	return 11;
}