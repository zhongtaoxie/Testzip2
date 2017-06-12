
// Testzip2Dlg.h : 头文件
//

#pragma once


// CTestzip2Dlg 对话框
class CTestzip2Dlg : public CDialog
{
// 构造
public:
	CTestzip2Dlg(CWnd* pParent = NULL);	// 标准构造函数

// 对话框数据
	enum { IDD = IDD_TESTZIP2_DIALOG };

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV 支持

	DWORD DoCreateProcessHandle_WaitMsg(CString sAppsPath, CString sAppsPar, int dlg_flags, int nTimes, CString& csMsg, CString csCommandKey);

private:
	int test1();
	int test2();//zhongguoren

// 实现
protected:
	HICON m_hIcon;

	// 生成的消息映射函数
	virtual BOOL OnInitDialog();
	afx_msg void OnSysCommand(UINT nID, LPARAM lParam);
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnBnClickedBtnZip();
	afx_msg void OnBnClickedBtnUzip();
	afx_msg void OnBnClickedBtnRarz();
	afx_msg void OnBnClickedRaruz();
};
