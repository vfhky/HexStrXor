
// HexStrXorDlg.h : ͷ�ļ�
//

#pragma once


// CHexStrXorDlg �Ի���
class CHexStrXorDlg : public CDialogEx
{
// ����
public:
	CHexStrXorDlg(CWnd* pParent = NULL);	// ��׼���캯��

// �Ի�������
	enum { IDD = IDD_HEXSTRXOR_DIALOG };

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV ֧��


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
	// ��һ��ʮ�������ַ���1
	CString HexStr1;
	// �ڶ���ʮ�������ַ���
	CString HexStr2;
	// �����
	CString HexStr;
	//ASCII���н��ַ�ת���ɶ�Ӧ��ʮ������
	int char2int(char input);
	//ASCII���н�ʮ������ת���ɶ�Ӧ���ַ�
	int int2char(char input);
	//��ʮ�������ַ���HexStr1��HexStr2���õ�HexStr
	void hexstrxor(char * HexStr1, char * HexStr2, char * HexStr);
	//��������ʮ�������ַ����Ƿ�Ϸ�
	int CheckInputHex(CEdit* pEdit, CString HexInput);
	afx_msg void OnBnClickedButton1();
	afx_msg void OnEnKillfocusEdit1();
	afx_msg void OnEnKillfocusEdit2();
	virtual BOOL PreTranslateMessage(MSG* pMsg);
};
