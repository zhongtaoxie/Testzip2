
// Testzip2.h : PROJECT_NAME 应用程序的主头文件
//

#pragma once

#ifndef __AFXWIN_H__
	#error "在包含此文件之前包含“stdafx.h”以生成 PCH 文件"
#endif

#include "resource.h"		// 主符号


// CTestzip2App:
// 有关此类的实现，请参阅 Testzip2.cpp
//

class CTestzip2App : public CWinAppEx
{
public:
	CTestzip2App();

// 重写
	public:
	virtual BOOL InitInstance();
	int sfsf();
	int sfsf()2;
	int test();
	int test3();


// 实现

	DECLARE_MESSAGE_MAP()
};

extern CTestzip2App theApp;