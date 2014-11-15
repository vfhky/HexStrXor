
// HexStrXorDlg.h : 头文件
//

#pragma once


// CHexStrXorDlg 对话框
class CHexStrXorDlg : public CDialogEx
{
// 构造
public:
	CHexStrXorDlg(CWnd* pParent = NULL);	// 标准构造函数

// 对话框数据
	enum { IDD = IDD_HEXSTRXOR_DIALOG };

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
	// 第一个十六进制字符串1
	CString HexStr1;
	// 第二个十六进制字符串
	CString HexStr2;
	// 异或结果
	CString HexStr;
	//ASCII码中将字符转换成对应的十进制数
	int char2int(char input);
	//ASCII码中将十进制数转换成对应的字符
	int int2char(char input);
	//将十六进制字符串HexStr1和HexStr2异或得到HexStr
	void hexstrxor(char * HexStr1, char * HexStr2, char * HexStr);
	//检查输入的十六进制字符串是否合法
	int CheckInputHex(CEdit* pEdit, CString HexInput);
	afx_msg void OnBnClickedButton1();
	afx_msg void OnEnKillfocusEdit1();
	afx_msg void OnEnKillfocusEdit2();
	virtual BOOL PreTranslateMessage(MSG* pMsg);
};
