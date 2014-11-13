// upue.cpp : DLL アプリケーション用にエクスポートされる関数を定義します。
//

#include "stdafx.h"
#include "upue.h"

#include "..\upu\exp.h"

UPUE_API int unpacking(const WCHAR *iname, WCHAR *oname)
{
	char iname_ascii[1024 * 2] = {0};
	char oname_ascii[1024 * 2] = {0};
	WideCharToMultiByte(CP_ACP, 0, iname, -1, 
		iname_ascii, sizeof(iname_ascii), NULL, NULL);
	WideCharToMultiByte(CP_ACP, 0, oname, -1, 
		oname_ascii, sizeof(oname_ascii), NULL, NULL);
	do_one_file_exp(iname_ascii, oname_ascii);
	return 0;
}

UPUE_API double version(void)
{
	return 0.2;
}

