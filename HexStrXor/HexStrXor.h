
// HexStrXor.h : PROJECT_NAME Ӧ�ó������ͷ�ļ�
//

#pragma once

#ifndef __AFXWIN_H__
	#error "�ڰ������ļ�֮ǰ������stdafx.h�������� PCH �ļ�"
#endif

#include "resource.h"		// ������


// CHexStrXorApp: 
// �йش����ʵ�֣������ HexStrXor.cpp
//

class CHexStrXorApp : public CWinApp
{
public:
	CHexStrXorApp();

// ��д
public:
	virtual BOOL InitInstance();

// ʵ��

	DECLARE_MESSAGE_MAP()
};

extern CHexStrXorApp theApp;