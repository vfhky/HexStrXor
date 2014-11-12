
// HexStrXorDlg.cpp : 实现文件
//

#include "stdafx.h"
#include "HexStrXor.h"
#include "HexStrXorDlg.h"
#include "afxdialogex.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// 用于应用程序“关于”菜单项的 CAboutDlg 对话框

class CAboutDlg : public CDialogEx
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

CAboutDlg::CAboutDlg() : CDialogEx(CAboutDlg::IDD)
{
}

void CAboutDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}

BEGIN_MESSAGE_MAP(CAboutDlg, CDialogEx)
END_MESSAGE_MAP()


// CHexStrXorDlg 对话框



CHexStrXorDlg::CHexStrXorDlg(CWnd* pParent /*=NULL*/)
	: CDialogEx(CHexStrXorDlg::IDD, pParent)
	, HexStr1(_T(""))
	, HexStr2(_T(""))
	, HexStr(_T(""))
{
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void CHexStrXorDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Text(pDX, IDC_EDIT1, HexStr1);
	DDX_Text(pDX, IDC_EDIT2, HexStr2);
	DDX_Text(pDX, IDC_EDIT3, HexStr);
}

BEGIN_MESSAGE_MAP(CHexStrXorDlg, CDialogEx)
	ON_WM_SYSCOMMAND()
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_BN_CLICKED(IDC_BUTTON1, &CHexStrXorDlg::OnBnClickedButton1)
	ON_EN_KILLFOCUS(IDC_EDIT1, &CHexStrXorDlg::OnEnKillfocusEdit1)
	ON_EN_KILLFOCUS(IDC_EDIT2, &CHexStrXorDlg::OnEnKillfocusEdit2)
END_MESSAGE_MAP()


// CHexStrXorDlg 消息处理程序

BOOL CHexStrXorDlg::OnInitDialog()
{
	CDialogEx::OnInitDialog();

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

	// 设置此对话框的图标。  当应用程序主窗口不是对话框时，框架将自动
	//  执行此操作
	SetIcon(m_hIcon, TRUE);			// 设置大图标
	SetIcon(m_hIcon, FALSE);		// 设置小图标

	// TODO:  在此添加额外的初始化代码

	return TRUE;  // 除非将焦点设置到控件，否则返回 TRUE
}

void CHexStrXorDlg::OnSysCommand(UINT nID, LPARAM lParam)
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

// 如果向对话框添加最小化按钮，则需要下面的代码
//  来绘制该图标。  对于使用文档/视图模型的 MFC 应用程序，
//  这将由框架自动完成。

void CHexStrXorDlg::OnPaint()
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
		CDialogEx::OnPaint();
	}
}

//当用户拖动最小化窗口时系统调用此函数取得光标
//显示。
HCURSOR CHexStrXorDlg::OnQueryDragIcon()
{
	return static_cast<HCURSOR>(m_hIcon);
}


//ASCII码中将字符转换成对应的十进制数
int char2int(char input)
{
	return input>64 ? (input - 55) : (input - 48);
}

//ASCII码中将十进制数转换成对应的字符
int int2char(char input)
{
	return input>9 ? (input + 55) : (input + 48);
}

//将十六进制字符串HexStr1和HexStr2异或得到HexStr
void hexstrxor(char * HexStr1, char * HexStr2, char * HexStr)
{
	int i, iHexStr1Len, iHexStr2Len, iHexStrLenLow, iHexStrLenGap;

	//求长度
	iHexStr1Len = strlen(HexStr1);
	iHexStr2Len = strlen(HexStr2);

	//获取最小的长度
	iHexStrLenLow = iHexStr1Len<iHexStr2Len ? iHexStr1Len : iHexStr2Len;

	//获取长度差值
	iHexStrLenGap = abs(iHexStr1Len - iHexStr2Len);

	//两个十六进制的字符串进行异或
	for (i = 0; i<iHexStrLenLow; i++)
	{
		*(HexStr + i) = char2int(HexStr1[i]) ^ char2int(HexStr2[i]);
		*(HexStr + i) = int2char(*(HexStr + i));
	}
	if (iHexStr1Len>iHexStr2Len)
		memcpy(HexStr + i, HexStr1 + i, iHexStrLenGap);
	else if (iHexStr1Len<iHexStr2Len)
		memcpy(HexStr + i, HexStr2 + i, iHexStrLenGap);
	*(HexStr + iHexStrLenLow + iHexStrLenGap) = 0x00;
}


void CHexStrXorDlg::OnBnClickedButton1()
{
	// TODO:  在此添加控件通知处理程序代码
	UpdateData(TRUE);

	//定义长度
	int iHexStr1Len, iHexStr2Len, iHexStrLenHigh;

	//大写转换并求长度
	HexStr1.MakeUpper();
	HexStr2.MakeUpper();
	iHexStr1Len = HexStr1.GetLength();
	iHexStr2Len = HexStr2.GetLength();

	//获取最大长度
	iHexStrLenHigh = iHexStr1Len > iHexStr2Len ? iHexStr1Len : iHexStr2Len;

	//为异或结果开辟内存
	char * HexStrXorResult = (char *)malloc(sizeof(char)*iHexStrLenHigh+1);

	//调用异或方法
	hexstrxor((LPSTR)(LPCTSTR)HexStr1, (LPSTR)(LPCTSTR)HexStr2, HexStrXorResult);

	//显示
	HexStr = HexStrXorResult;

	//更新静态控件1的长度
	CString UpdateHexStrLen;
	UpdateHexStrLen.Format("%s%d%s", "字节=[", HexStr1.GetLength(), "]");
	//SetDlgItemText(IDC_STATIC_STR1, UpdateHexStr1Len );
	GetDlgItem(IDC_STATIC_STR1)->SetWindowTextA(UpdateHexStrLen);

	//更新静态控件2的长度
	UpdateHexStrLen.Format("%s%d%s", "字节=[", HexStr2.GetLength(), "]");
	//SetDlgItemText(IDC_STATIC_STR2, UpdateHexStr2Len );
	GetDlgItem(IDC_STATIC_STR2)->SetWindowTextA(UpdateHexStrLen);

	//更新静态控件3的长度
	UpdateHexStrLen.Format("%s%d%s", "字节=[", iHexStrLenHigh, "]");
	//SetDlgItemText(IDC_STATIC_STR, UpdateHexStrLen );
	GetDlgItem(IDC_STATIC_STR3)->SetWindowTextA(UpdateHexStrLen);

	//更新所有控件数据
	UpdateData(FALSE);

	//释放内存
	free(HexStrXorResult);
	HexStrXorResult = NULL;
}


//检查输入的十六进制字符串是否合法
int CheckInputHex(CEdit* pEdit, CString HexInput)
{
	//获取字符串的长度
	int i, HexInputLen;
	HexInputLen = HexInput.GetLength();

	//检查长度是否合适
	if (HexInputLen > 500)
	{
		AfxMessageBox(_T("长度不能大于500!"));
		pEdit->SetFocus();
		pEdit->SetSel(0, HexInputLen);
		return -1;
	}

	//检查是否是十六进制字符
	for (i = 0; i < HexInputLen; i++)
	{
		if (HexInput[i]<0x30 || (HexInput[i]>0x39 && HexInput[i]<0x41) || (HexInput[i]>0x46 && HexInput[i]<0x61) || HexInput[i]> 0x66)
		{
			AfxMessageBox(_T("请输入正确的十六进制字符串!"));
			pEdit->SetFocus();
			pEdit->SetSel(0, HexInputLen);
			return -1;
		}
	}
	return 0;
}


void CHexStrXorDlg::OnEnKillfocusEdit1()
{
	// TODO:  在此添加控件通知处理程序代码
	CEdit* pEdit;

	//获得第一个字符串控件 
	pEdit = (CEdit*)GetDlgItem(IDC_EDIT1);

	//获取Edit Control内的内容，即第一个十六进制字符串  
	pEdit->GetWindowText(HexStr1);

	//检查合法性
	int iCheckData;
	iCheckData = CheckInputHex(pEdit, HexStr1);

	//出错则直接返回
	if (iCheckData)
		return;

	//更新长度
	CString UpdateHexStr1Len;
	UpdateHexStr1Len.Format("%s%d%s", "字节=[", HexStr1.GetLength(), "]");
	//SetDlgItemText(IDC_STATIC_STR1, UpdateHexStr1Len );
	GetDlgItem(IDC_STATIC_STR1)->SetWindowTextA(UpdateHexStr1Len);
}


void CHexStrXorDlg::OnEnKillfocusEdit2()
{
	// TODO:  在此添加控件通知处理程序代码
	CEdit* pEdit;

	//获得第二个字符串控件 
	pEdit = (CEdit*)GetDlgItem(IDC_EDIT2);

	//获取Edit Control内的内容，即第二个十六进制字符串  
	pEdit->GetWindowText(HexStr2);

	//检查合法性
	int iCheckData;
	iCheckData = CheckInputHex(pEdit, HexStr2);

	//出错则直接返回
	if (iCheckData)
		return;

	//更新长度
	CString UpdateHexStr2Len;
	UpdateHexStr2Len.Format("%s%d%s", "字节=[", HexStr2.GetLength(), "]");
	//SetDlgItemText(IDC_STATIC_STR2, UpdateHexStr2Len );
	GetDlgItem(IDC_STATIC_STR2)->SetWindowTextA(UpdateHexStr2Len);
}
