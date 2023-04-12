#include <dotpatch/runtime.hh>

#include <Windows.h>

DWORD StartThread(LPVOID unused)
{
	dotpatch::runtime::Initialize();

	dotpatch::runtime::Exit();
	FreeLibraryAndExitThread(dotpatch::runtime::gNativeModuleInstance, 0);
}

BOOL WINAPI DllMain(HINSTANCE dllHandle, DWORD reason, LPVOID reserved)
{
	dotpatch::runtime::gNativeModuleInstance = dllHandle;

	switch (reason)
	{
	case DLL_PROCESS_ATTACH:
		CreateThread(nullptr, 0, (LPTHREAD_START_ROUTINE)StartThread, nullptr, 0, nullptr);
		break;

	default:
		break;
	}
	return TRUE;
}