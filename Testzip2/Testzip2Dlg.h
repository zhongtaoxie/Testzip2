
// Testzip2Dlg.h : ͷ�ļ�
//

#pragma once


// CTestzip2Dlg �Ի���
class CTestzip2Dlg : public CDialog
{
// ����
public:
	CTestzip2Dlg(CWnd* pParent = NULL);	// ��׼���캯��

// �Ի�������
	enum { IDD = IDD_TESTZIP2_DIALOG };

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV ֧��

	DWORD DoCreateProcessHandle_WaitMsg(CString sAppsPath, CString sAppsPar, int dlg_flags, int nTimes, CString& csMsg, CString csCommandKey);

private:
	int test1();
	int test2();//zhongguoren

// ʵ��
protected:
	HICON m_hIcon;

	// ���ɵ���Ϣӳ�亯��
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
