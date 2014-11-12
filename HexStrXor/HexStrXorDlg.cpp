
// HexStrXorDlg.cpp : ʵ���ļ�
//

#include "stdafx.h"
#include "HexStrXor.h"
#include "HexStrXorDlg.h"
#include "afxdialogex.h"

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


// CHexStrXorDlg �Ի���



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


// CHexStrXorDlg ��Ϣ�������

BOOL CHexStrXorDlg::OnInitDialog()
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

	// ���ô˶Ի����ͼ�ꡣ  ��Ӧ�ó��������ڲ��ǶԻ���ʱ����ܽ��Զ�
	//  ִ�д˲���
	SetIcon(m_hIcon, TRUE);			// ���ô�ͼ��
	SetIcon(m_hIcon, FALSE);		// ����Сͼ��

	// TODO:  �ڴ���Ӷ���ĳ�ʼ������

	return TRUE;  // ���ǽ��������õ��ؼ������򷵻� TRUE
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

// �����Ի��������С����ť������Ҫ����Ĵ���
//  �����Ƹ�ͼ�ꡣ  ����ʹ���ĵ�/��ͼģ�͵� MFC Ӧ�ó���
//  �⽫�ɿ���Զ���ɡ�

void CHexStrXorDlg::OnPaint()
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
HCURSOR CHexStrXorDlg::OnQueryDragIcon()
{
	return static_cast<HCURSOR>(m_hIcon);
}


//ASCII���н��ַ�ת���ɶ�Ӧ��ʮ������
int char2int(char input)
{
	return input>64 ? (input - 55) : (input - 48);
}

//ASCII���н�ʮ������ת���ɶ�Ӧ���ַ�
int int2char(char input)
{
	return input>9 ? (input + 55) : (input + 48);
}

//��ʮ�������ַ���HexStr1��HexStr2���õ�HexStr
void hexstrxor(char * HexStr1, char * HexStr2, char * HexStr)
{
	int i, iHexStr1Len, iHexStr2Len, iHexStrLenLow, iHexStrLenGap;

	//�󳤶�
	iHexStr1Len = strlen(HexStr1);
	iHexStr2Len = strlen(HexStr2);

	//��ȡ��С�ĳ���
	iHexStrLenLow = iHexStr1Len<iHexStr2Len ? iHexStr1Len : iHexStr2Len;

	//��ȡ���Ȳ�ֵ
	iHexStrLenGap = abs(iHexStr1Len - iHexStr2Len);

	//����ʮ�����Ƶ��ַ����������
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
	// TODO:  �ڴ���ӿؼ�֪ͨ����������
	UpdateData(TRUE);

	//���峤��
	int iHexStr1Len, iHexStr2Len, iHexStrLenHigh;

	//��дת�����󳤶�
	HexStr1.MakeUpper();
	HexStr2.MakeUpper();
	iHexStr1Len = HexStr1.GetLength();
	iHexStr2Len = HexStr2.GetLength();

	//��ȡ��󳤶�
	iHexStrLenHigh = iHexStr1Len > iHexStr2Len ? iHexStr1Len : iHexStr2Len;

	//Ϊ����������ڴ�
	char * HexStrXorResult = (char *)malloc(sizeof(char)*iHexStrLenHigh+1);

	//������򷽷�
	hexstrxor((LPSTR)(LPCTSTR)HexStr1, (LPSTR)(LPCTSTR)HexStr2, HexStrXorResult);

	//��ʾ
	HexStr = HexStrXorResult;

	//���¾�̬�ؼ�1�ĳ���
	CString UpdateHexStrLen;
	UpdateHexStrLen.Format("%s%d%s", "�ֽ�=[", HexStr1.GetLength(), "]");
	//SetDlgItemText(IDC_STATIC_STR1, UpdateHexStr1Len );
	GetDlgItem(IDC_STATIC_STR1)->SetWindowTextA(UpdateHexStrLen);

	//���¾�̬�ؼ�2�ĳ���
	UpdateHexStrLen.Format("%s%d%s", "�ֽ�=[", HexStr2.GetLength(), "]");
	//SetDlgItemText(IDC_STATIC_STR2, UpdateHexStr2Len );
	GetDlgItem(IDC_STATIC_STR2)->SetWindowTextA(UpdateHexStrLen);

	//���¾�̬�ؼ�3�ĳ���
	UpdateHexStrLen.Format("%s%d%s", "�ֽ�=[", iHexStrLenHigh, "]");
	//SetDlgItemText(IDC_STATIC_STR, UpdateHexStrLen );
	GetDlgItem(IDC_STATIC_STR3)->SetWindowTextA(UpdateHexStrLen);

	//�������пؼ�����
	UpdateData(FALSE);

	//�ͷ��ڴ�
	free(HexStrXorResult);
	HexStrXorResult = NULL;
}


//��������ʮ�������ַ����Ƿ�Ϸ�
int CheckInputHex(CEdit* pEdit, CString HexInput)
{
	//��ȡ�ַ����ĳ���
	int i, HexInputLen;
	HexInputLen = HexInput.GetLength();

	//��鳤���Ƿ����
	if (HexInputLen > 500)
	{
		AfxMessageBox(_T("���Ȳ��ܴ���500!"));
		pEdit->SetFocus();
		pEdit->SetSel(0, HexInputLen);
		return -1;
	}

	//����Ƿ���ʮ�������ַ�
	for (i = 0; i < HexInputLen; i++)
	{
		if (HexInput[i]<0x30 || (HexInput[i]>0x39 && HexInput[i]<0x41) || (HexInput[i]>0x46 && HexInput[i]<0x61) || HexInput[i]> 0x66)
		{
			AfxMessageBox(_T("��������ȷ��ʮ�������ַ���!"));
			pEdit->SetFocus();
			pEdit->SetSel(0, HexInputLen);
			return -1;
		}
	}
	return 0;
}


void CHexStrXorDlg::OnEnKillfocusEdit1()
{
	// TODO:  �ڴ���ӿؼ�֪ͨ����������
	CEdit* pEdit;

	//��õ�һ���ַ����ؼ� 
	pEdit = (CEdit*)GetDlgItem(IDC_EDIT1);

	//��ȡEdit Control�ڵ����ݣ�����һ��ʮ�������ַ���  
	pEdit->GetWindowText(HexStr1);

	//���Ϸ���
	int iCheckData;
	iCheckData = CheckInputHex(pEdit, HexStr1);

	//������ֱ�ӷ���
	if (iCheckData)
		return;

	//���³���
	CString UpdateHexStr1Len;
	UpdateHexStr1Len.Format("%s%d%s", "�ֽ�=[", HexStr1.GetLength(), "]");
	//SetDlgItemText(IDC_STATIC_STR1, UpdateHexStr1Len );
	GetDlgItem(IDC_STATIC_STR1)->SetWindowTextA(UpdateHexStr1Len);
}


void CHexStrXorDlg::OnEnKillfocusEdit2()
{
	// TODO:  �ڴ���ӿؼ�֪ͨ����������
	CEdit* pEdit;

	//��õڶ����ַ����ؼ� 
	pEdit = (CEdit*)GetDlgItem(IDC_EDIT2);

	//��ȡEdit Control�ڵ����ݣ����ڶ���ʮ�������ַ���  
	pEdit->GetWindowText(HexStr2);

	//���Ϸ���
	int iCheckData;
	iCheckData = CheckInputHex(pEdit, HexStr2);

	//������ֱ�ӷ���
	if (iCheckData)
		return;

	//���³���
	CString UpdateHexStr2Len;
	UpdateHexStr2Len.Format("%s%d%s", "�ֽ�=[", HexStr2.GetLength(), "]");
	//SetDlgItemText(IDC_STATIC_STR2, UpdateHexStr2Len );
	GetDlgItem(IDC_STATIC_STR2)->SetWindowTextA(UpdateHexStr2Len);
}
