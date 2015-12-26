
// calculatorDlg.h : 头文件
//

#pragma once


// CcalculatorDlg 对话框
class CcalculatorDlg : public CDialogEx
{
// 构造
public:
	CcalculatorDlg(CWnd* pParent = NULL);	// 标准构造函数

// 对话框数据
	enum { IDD = IDD_CALCULATOR_DIALOG };

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV 支持


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
	int flag;
	double temp;
	CString m_str;
	afx_msg void OnBnClicked0();
	afx_msg void OnBnClicked1();
	afx_msg void OnBnClicked2();
	afx_msg void OnBnClicked3();
	afx_msg void OnBnClicked4();
	afx_msg void OnBnClicked5();
	afx_msg void OnBnClicked6();
	afx_msg void OnBnClicked7();
	afx_msg void OnBnClicked8();
	afx_msg void OnBnClicked9();
	afx_msg void OnBnClickedDot();
	afx_msg void OnBnClickedAdd();
	afx_msg void OnBnClickedCut();
	afx_msg void OnBnClickedMultiply();
	afx_msg void OnBnClickedRemove();
	afx_msg void OnBnClickedResult();
	afx_msg void OnBnClickedClear();
	afx_msg void OnBnClickedTg();
	afx_msg void OnBnClickedBfh();
	afx_msg void OnBnClickedDs();
	afx_msg void OnBnClickedZf();
	afx_msg void OnBnClickedGh();
	afx_msg void OnBnClickedPf();
	protected:
	        void mydelete(CString &ca);
	        void check(CString &ca);
};
