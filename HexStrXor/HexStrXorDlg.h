
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
	afx_msg void OnBnClickedButton1();
	afx_msg void OnEnKillfocusEdit1();
	afx_msg void OnEnKillfocusEdit2();
};
