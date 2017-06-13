
// Testzip2Dlg.h : 
//

#pragma once


// CTestzip2Dlg 
class CTestzip2Dlg : public CDialog
{

public:
	CTestzip2Dlg(CWnd* pParent = NULL);	// 


	enum { IDD = IDD_TESTZIP2_DIALOG };

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV 

	DWORD DoCreateProcessHandle_WaitMsg(CString sAppsPath, CString sAppsPar, int dlg_flags, int nTimes, CString& csMsg, CString csCommandKey);

private:
	int test1();
	int test2();//zhongguoren
	int test3();
	int test4();
	int test5();


protected:
	HICON m_hIcon;


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
