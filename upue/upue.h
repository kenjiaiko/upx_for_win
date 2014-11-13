// 以下の ifdef ブロックは DLL からのエクスポートを容易にするマクロを作成するための 
// 一般的な方法です。この DLL 内のすべてのファイルは、コマンド ラインで定義された UPUE_EXPORTS
// シンボルを使用してコンパイルされます。このシンボルは、この DLL を使用するプロジェクトでは定義できません。
// ソースファイルがこのファイルを含んでいる他のプロジェクトは、 
// UPUE_API 関数を DLL からインポートされたと見なすのに対し、この DLL は、このマクロで定義された
// シンボルをエクスポートされたと見なします。
#ifdef UPUE_EXPORTS
#define UPUE_API __declspec(dllexport)
#else
#define UPUE_API __declspec(dllimport)
#endif

extern "C" {
	UPUE_API int unpacking(const WCHAR *iname, WCHAR *oname);
	UPUE_API double version(void);
};
