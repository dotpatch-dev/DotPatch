#include <dotpatch/debug.hh>

#include <Windows.h>

namespace dotpatch::debug
{
	void InitializeDebugConsole()
	{
		AllocConsole();
		SetConsoleTitleW(L"💣 DotPatch Console 💣");
	}

	void ExitDebugConsole()
	{
		FreeConsole();
	}
}