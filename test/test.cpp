// test.cpp : コンソール アプリケーションのエントリ ポイントを定義します。
//

#include "stdafx.h"

#include <Windows.h>

typedef int (*up)(const WCHAR *, WCHAR *);
typedef double (*vr)();

int _tmain(int argc, _TCHAR* argv[])
{
	if(argc < 2){
		printf("Error: argv\n");
		return 1;
	}
	
	HMODULE h = LoadLibrary(L"upue.dll");
	if(h == NULL){
		printf("Error: LoadLibrary\n");
		return -1;
	}

	up a = (up)GetProcAddress(h, "unpacking");
	vr b = (vr)GetProcAddress(h, "version");

	printf("FUNC unpacking: %08x\n", (DWORD)a);
	printf("FUNC version:   %08x\n", (DWORD)b);

	char buff[1024];

	printf("version = %f\n", b());
	a(argv[1], argv[2]);
	return 0;
}

