
// Testzip2Dlg.cpp : ʵ���ļ�
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


// ����Ӧ�ó��򡰹��ڡ��˵���� CAboutDlg �Ի���

class CAboutDlg : public CDialog
{
public:
	CAboutDlg();

// �Ի�������
	enum { IDD = IDD_ABOUTBOX };

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV ֧��

// ʵ��
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


// CTestzip2Dlg �Ի���




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


// CTestzip2Dlg ��Ϣ�������

BOOL CTestzip2Dlg::OnInitDialog()
{
	CDialog::OnInitDialog();

	// ��������...���˵�����ӵ�ϵͳ�˵��С�

	// IDM_ABOUTBOX ������ϵͳ���Χ�ڡ�
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

	// ���ô˶Ի����ͼ�ꡣ��Ӧ�ó��������ڲ��ǶԻ���ʱ����ܽ��Զ�
	//  ִ�д˲���
	SetIcon(m_hIcon, TRUE);			// ���ô�ͼ��
	SetIcon(m_hIcon, FALSE);		// ����Сͼ��

	// TODO: �ڴ���Ӷ���ĳ�ʼ������

	return TRUE;  // ���ǽ��������õ��ؼ������򷵻� TRUE
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

// �����Ի��������С����ť������Ҫ����Ĵ���
//  �����Ƹ�ͼ�ꡣ����ʹ���ĵ�/��ͼģ�͵� MFC Ӧ�ó���
//  �⽫�ɿ���Զ���ɡ�

void CTestzip2Dlg::OnPaint()
{
	if (IsIconic())
	{
		CPaintDC dc(this); // ���ڻ��Ƶ��豸������

		SendMessage(WM_ICONERASEBKGND, reinterpret_cast<WPARAM>(dc.GetSafeHdc()), 0);

		// ʹͼ���ڹ����������о���
		int cxIcon = GetSystemMetrics(SM_CXICON);
		int cyIcon = GetSystemMetrics(SM_CYICON);
		CRect rect;
		GetClientRect(&rect);
		int x = (rect.Width() - cxIcon + 1) / 2;
		int y = (rect.Height() - cyIcon + 1) / 2;

		// ����ͼ��
		dc.DrawIcon(x, y, m_hIcon);
	}
	else
	{
		CDialog::OnPaint();
	}
}

//���û��϶���С������ʱϵͳ���ô˺���ȡ�ù��
//��ʾ��
HCURSOR CTestzip2Dlg::OnQueryDragIcon()
{
	return static_cast<HCURSOR>(m_hIcon);
}


void CTestzip2Dlg::OnBnClickedBtnZip()
{
	// TODO: �ڴ���ӿؼ�֪ͨ����������

	//OID.2.5.4.88=00001, OID.2.5.4.26=��Ͻ��, OID.2.5.4.45=entCert2, C=CN, S=����ʡ, 
	//L=�Ͼ���, O=����sm2֤��20170427, OU=666, CN=����sm2֤��20170427
	CString strTmp = "OID.2.5.4.88=00001, OID.2.5.4.26=��Ͻ��, OID.2.5.4.45=entCert2, C=CN, S=����ʡ, L=�Ͼ���, O=����sm2֤��20170427, OU=666, CN=����sm2֤��20170427";
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
	compress.Zip_PackFiles(strDirPath,strZipFilePath);//ֻ�Ǹ�Demo�Ͳ����߳�ȥ����
	GetLocalTime(&sys2);
	CString strInfo;
	strInfo.Format("ѹ����ɣ�����ʱ��%d",(sys2.wMinute*60+sys2.wSecond)-(sys.wMinute*60+sys.wSecond));

	MessageBox(strInfo,_T("���"),MB_ICONINFORMATION);
}

void CTestzip2Dlg::OnBnClickedBtnUzip()
{
	// TODO: �ڴ���ӿؼ�֪ͨ����������
	SYSTEMTIME sys,sys2;
	GetLocalTime(&sys);
	CZipImplement compress;
	CString strDirPath = "D:\\csm\\session3";
	CString strZipFilePath ="D:\\11.zip";
	compress.Zip_UnPackFiles(strZipFilePath,strDirPath);//ֻ�Ǹ�Demo�Ͳ����߳�ȥ����
	GetLocalTime(&sys2);
	CString strInfo;
	strInfo.Format("��ѹ��ɣ�����ʱ��%d",(sys2.wMinute*60+sys2.wSecond)-(sys.wMinute*60+sys.wSecond));
	MessageBox(strInfo,_T("���"),MB_ICONINFORMATION);
}

void CTestzip2Dlg::OnBnClickedBtnRarz()
{
	// TODO: �ڴ���ӿؼ�֪ͨ����������
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


//����      ��С    ѹ����   ����   ʱ��   У���  ����
//----------- ---------  -------- ----- -------- -----  --------  ----
//*   ..A....        24        48 200%  22-05-17 13:47  7016A1A4  qq20170522134750.txt
//*   ..A....        10        32 320%  22-05-17 13:49  427B7148  �½��ļ���\qq2017052213475020170522134910.txt
//*   ..A....        24        48 200%  24-05-17 17:03  7016A1A4  �½��ļ���\qq20170524170343.txt
//*   ..A....        10        32 320%  22-05-17 13:52  427B7148  qq2017052213475020170522135208.txt
//...D...         0         0   0%  26-05-17 10:12  00000000  �½��ļ���       
//----------- ---------  -------- ----- -------- -----  --------  ----
//68       160 235%                            5

BOOL GetFileNames(char* chBuf)
{
	vector<string> vecNames;
	string szInfo = chBuf;
	string szLable="----------- ---------  -------- ----- -------- -----  --------  ----\r\n";//��ʼ�ı�ʶ
	size_t nFind = 0;
	nFind = szInfo.find(szLable);
	if (nFind == string::npos)
	{
		return FALSE;
	}

	int nEnd = szInfo.find(szLable, nFind+szLable.length());//�ҵ�������ʶ
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

		//�õ�һ��ѹ����¼
		szData = szInfo.substr(0,nFind);
		trimString(szData);

		//���ļ��л����ļ�
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
	PROCESS_INFORMATION pi;																						//�̵߳���Ϣ
	STARTUPINFO siStartInfo;																					//�ýṹ����ָ���½��̵�����������
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
	siStartInfo.hStdError	= hWrite;																			//�Ѵ������̵ı�׼��������ض��򵽹ܵ�����  
	siStartInfo.hStdOutput	= hWrite;																			//�Ѵ������̵ı�׼����ض��򵽹ܵ�����  
	siStartInfo.dwFlags		= STARTF_USESHOWWINDOW | STARTF_USESTDHANDLES;
	// ��������
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
		char	buffer[4096] = {0};																//��4K�Ŀռ����洢��������ݣ�ֻҪ������ʾ�ļ����ݣ�һ��������ǹ����ˡ�  
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
			nOntimeCount = 3 * 10;				// Ĭ��3��
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
	// TODO: �ڴ���ӿؼ�֪ͨ����������
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