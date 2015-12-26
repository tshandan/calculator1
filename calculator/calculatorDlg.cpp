
// calculatorDlg.cpp : ʵ���ļ�
//

#include "stdafx.h"
#include "calculator.h"
#include "calculatorDlg.h"
#include "afxdialogex.h"
#include "math.h"
#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// ����Ӧ�ó��򡰹��ڡ��˵���� CAboutDlg �Ի���

class CAboutDlg : public CDialogEx
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

CAboutDlg::CAboutDlg() : CDialogEx(CAboutDlg::IDD)
{
}

void CAboutDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}

BEGIN_MESSAGE_MAP(CAboutDlg, CDialogEx)
END_MESSAGE_MAP()


// CcalculatorDlg �Ի���




CcalculatorDlg::CcalculatorDlg(CWnd* pParent /*=NULL*/)
	: CDialogEx(CcalculatorDlg::IDD, pParent)
	, m_str(_T(""))
{
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void CcalculatorDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Text(pDX, IDC_EDIT1, m_str);
}

BEGIN_MESSAGE_MAP(CcalculatorDlg, CDialogEx)
	ON_WM_SYSCOMMAND()
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_BN_CLICKED(IDC_0, &CcalculatorDlg::OnBnClicked0)
	ON_BN_CLICKED(IDC_1, &CcalculatorDlg::OnBnClicked1)
	ON_BN_CLICKED(IDC_2, &CcalculatorDlg::OnBnClicked2)
	ON_BN_CLICKED(IDC_3, &CcalculatorDlg::OnBnClicked3)
	ON_BN_CLICKED(IDC_4, &CcalculatorDlg::OnBnClicked4)
	ON_BN_CLICKED(IDC_5, &CcalculatorDlg::OnBnClicked5)
	ON_BN_CLICKED(IDC_6, &CcalculatorDlg::OnBnClicked6)
	ON_BN_CLICKED(IDC_7, &CcalculatorDlg::OnBnClicked7)
	ON_BN_CLICKED(IDC_8, &CcalculatorDlg::OnBnClicked8)
	ON_BN_CLICKED(IDC_9, &CcalculatorDlg::OnBnClicked9)
	ON_BN_CLICKED(IDC_DOT, &CcalculatorDlg::OnBnClickedDot)
	ON_BN_CLICKED(IDC_ADD, &CcalculatorDlg::OnBnClickedAdd)
	ON_BN_CLICKED(IDC_CUT, &CcalculatorDlg::OnBnClickedCut)
	ON_BN_CLICKED(IDC_MULTIPLY, &CcalculatorDlg::OnBnClickedMultiply)
	ON_BN_CLICKED(IDC_REMOVE, &CcalculatorDlg::OnBnClickedRemove)
	ON_BN_CLICKED(IDC_RESULT, &CcalculatorDlg::OnBnClickedResult)
	ON_BN_CLICKED(IDC_CLEAR, &CcalculatorDlg::OnBnClickedClear)
	ON_BN_CLICKED(IDC_TG, &CcalculatorDlg::OnBnClickedTg)
	ON_BN_CLICKED(IDC_BFH, &CcalculatorDlg::OnBnClickedBfh)
	ON_BN_CLICKED(IDC_DS, &CcalculatorDlg::OnBnClickedDs)
	ON_BN_CLICKED(IDC_ZF, &CcalculatorDlg::OnBnClickedZf)
	ON_BN_CLICKED(IDC_GH, &CcalculatorDlg::OnBnClickedGh)
	ON_BN_CLICKED(IDC_PF, &CcalculatorDlg::OnBnClickedPf)
END_MESSAGE_MAP()


// CcalculatorDlg ��Ϣ�������

BOOL CcalculatorDlg::OnInitDialog()
{
	CDialogEx::OnInitDialog();

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

void CcalculatorDlg::OnSysCommand(UINT nID, LPARAM lParam)
{
	if ((nID & 0xFFF0) == IDM_ABOUTBOX)
	{
		CAboutDlg dlgAbout;
		dlgAbout.DoModal();
	}
	else
	{
		CDialogEx::OnSysCommand(nID, lParam);
	}
}

// �����Ի��������С����ť������Ҫ����Ĵ���
//  �����Ƹ�ͼ�ꡣ����ʹ���ĵ�/��ͼģ�͵� MFC Ӧ�ó���
//  �⽫�ɿ���Զ���ɡ�

void CcalculatorDlg::OnPaint()
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
		CDialogEx::OnPaint();
	}
}

//���û��϶���С������ʱϵͳ���ô˺���ȡ�ù��
//��ʾ��
HCURSOR CcalculatorDlg::OnQueryDragIcon()
{
	return static_cast<HCURSOR>(m_hIcon);
}



void CcalculatorDlg::OnBnClicked0()
{
	// TODO: �ڴ���ӿؼ�֪ͨ����������
	UpdateData(true);
    m_str=m_str+L"0";
	UpdateData(false);
}


void CcalculatorDlg::OnBnClicked1()
{
	// TODO: �ڴ���ӿؼ�֪ͨ����������
	UpdateData(true);
    m_str=m_str+L"1";
	UpdateData(false);
}


void CcalculatorDlg::OnBnClicked2()
{
	// TODO: �ڴ���ӿؼ�֪ͨ����������
	UpdateData(true);
    m_str=m_str+L"2";
	UpdateData(false);
}


void CcalculatorDlg::OnBnClicked3()
{
	// TODO: �ڴ���ӿؼ�֪ͨ����������
	UpdateData(true);
    m_str=m_str+L"3";
	UpdateData(false);
}


void CcalculatorDlg::OnBnClicked4()
{
	// TODO: �ڴ���ӿؼ�֪ͨ����������
	UpdateData(true);
    m_str=m_str+L"4";
	UpdateData(false);
}


void CcalculatorDlg::OnBnClicked5()
{
	// TODO: �ڴ���ӿؼ�֪ͨ����������
	UpdateData(true);
    m_str=m_str+L"5";
	UpdateData(false);
}


void CcalculatorDlg::OnBnClicked6()
{
	// TODO: �ڴ���ӿؼ�֪ͨ����������
	UpdateData(true);
    m_str=m_str+L"6";
	UpdateData(false);
}


void CcalculatorDlg::OnBnClicked7()
{
	// TODO: �ڴ���ӿؼ�֪ͨ����������
	UpdateData(true);
    m_str=m_str+L"7";
	UpdateData(false);
}


void CcalculatorDlg::OnBnClicked8()
{
	// TODO: �ڴ���ӿؼ�֪ͨ����������
	UpdateData(true);
    m_str=m_str+L"8";
	UpdateData(false);
}


void CcalculatorDlg::OnBnClicked9()
{
	// TODO: �ڴ���ӿؼ�֪ͨ����������
	UpdateData(true);
    m_str=m_str+L"9";
	UpdateData(false);
}


void CcalculatorDlg::OnBnClickedDot()
{
	// TODO: �ڴ���ӿؼ�֪ͨ����������
	UpdateData(true);
    m_str=m_str+L".";
	UpdateData(false);
}


void CcalculatorDlg::OnBnClickedAdd()
{
	// TODO: �ڴ���ӿؼ�֪ͨ����������
	UpdateData(true);
	flag=1;
	temp=_ttof(m_str);	
    m_str=" ";
	UpdateData(false);
}


void CcalculatorDlg::OnBnClickedCut()
{
	// TODO: �ڴ���ӿؼ�֪ͨ����������
	UpdateData(true);
	flag=2;
	temp=_ttof(m_str);	
    m_str=" ";
	UpdateData(false);
}


void CcalculatorDlg::OnBnClickedMultiply()
{
	// TODO: �ڴ���ӿؼ�֪ͨ����������
	UpdateData(true);
	flag=3;
	temp=_ttof(m_str);	
    m_str=" ";
	UpdateData(false);
}


void CcalculatorDlg::OnBnClickedRemove()
{
	// TODO: �ڴ���ӿؼ�֪ͨ����������
	UpdateData(true);
	flag=4;
	temp=_ttof(m_str);	
    m_str=" ";
	UpdateData(false);
}


void CcalculatorDlg::OnBnClickedResult()
{
	// TODO: �ڴ���ӿؼ�֪ͨ����������
	TRACE(L"flag=%d\n",flag);
	UpdateData(true);

	if(flag==1)
	{
		temp=temp+_ttof(m_str);
		m_str.Format(L"%lf",temp);
		//check(m_str);
		check(m_str);
	}
	if(flag==2)
	{
		temp=temp-_ttof(m_str);
		m_str.Format(L"%lf",temp);
		check(m_str);
		//check(m_str);
	}
	if(flag==3)
	{
		temp=temp*_ttof(m_str);
		//m_str.Format(L"%lf",temp);
		m_str.Format(L"%lf",temp);
		check(m_str);
		//check(m_str);
	}
	if(flag==4)
	{
		if (_ttof(m_str)==0)
		{
		   m_str.Format(L"error");
		   //check(m_str);
		   //check(m_str);
		}
		else
		{
		    temp=temp/_ttof(m_str);
			m_str.Format(L"%lf",temp);
			check(m_str);
	        //check(m_str);
		}
	
	}
	//m_str.Format(L"%lf",temp);
	UpdateData(false);
}


void CcalculatorDlg::OnBnClickedClear()
{
	// TODO: �ڴ���ӿؼ�֪ͨ����������
	m_str=" ";
	UpdateData(false);
}


void CcalculatorDlg::OnBnClickedTg()
{
	// TODO: �ڴ���ӿؼ�֪ͨ����������
	UpdateData(true);
	mydelete(m_str);
	check(m_str);
	//ca.Delete(ca.GetLength()-1,1);
	UpdateData(false);
}

void CcalculatorDlg::mydelete(CString &ca)
{
	ca.Delete(ca.GetLength()-1,1);

}

void CcalculatorDlg::check(CString &ca)
{
	while(ca.Right(1)=="0")
	{
		ca.Delete(ca.GetLength()-1,1);
	}
	while(ca.Right(1)==".")
	{
		ca.Delete(ca.GetLength()-1,1);
	}
}
void CcalculatorDlg::OnBnClickedBfh()
{
	// TODO: �ڴ���ӿؼ�֪ͨ����������
	UpdateData(true);
	temp=_ttof(m_str);
	//temp=0.01*(temp��_ttof(m_str));
	if(temp+_ttof(m_str))
	{
		temp=0.01*(temp+_ttof(m_str));
	}
	if(temp-_ttof(m_str))
	{
		temp=0.01*(temp-_ttof(m_str));
	}
	m_str.Format(L"%lf",temp);
	check(m_str);
	UpdateData(false);
}


void CcalculatorDlg::OnBnClickedDs()
{
	// TODO: �ڴ���ӿؼ�֪ͨ����������
	UpdateData(true);
	temp=_ttof(m_str);
	if (_ttof(m_str)==0)
		{
		   m_str.Format(L"error");
		}
		else
		{
		    temp=1/temp;
			m_str.Format(L"%lf",temp);
			check(m_str);
		}
	UpdateData(false);

}


void CcalculatorDlg::OnBnClickedZf()
{
	// TODO: �ڴ���ӿؼ�֪ͨ����������
	UpdateData(true);
	temp=_ttof(m_str);
	if (m_str==" ")
		{
		   m_str.Format(L"0");
		}
		else
		{
		    temp=-temp;
			m_str.Format(L"%lf",temp);
			check(m_str);
		}
	//temp=-temp;
	//m_str.Format(L"%lf",temp);
	//check(m_str);
	UpdateData(false);
}


void CcalculatorDlg::OnBnClickedGh()
{
	// TODO: �ڴ���ӿؼ�֪ͨ����������
	UpdateData(true);
	temp=_ttof(m_str);
	temp=sqrt(temp);
	//temp=sqrt(-temp);
	m_str.Format(L"%lf",temp);
	check(m_str);
	UpdateData(false);
}


void CcalculatorDlg::OnBnClickedPf()
{
	// TODO: �ڴ���ӿؼ�֪ͨ����������
    UpdateData(true);
	temp=_ttof(m_str);
	temp=temp*temp;
	m_str.Format(L"%lf",temp);
	check(m_str);
	UpdateData(false);
}
