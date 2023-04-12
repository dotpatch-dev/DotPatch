#include <dotpatch/runtime.hh>
#include <dotpatch/debug.hh>

namespace dotpatch::runtime
{
	void Initialize()
	{
		debug::InitializeDebugConsole();

		runtime::LoadHostFXR();
		auto managed = runtime::LoadManagedRuntime();
	}

	void Exit()
	{
		MessageBoxA(nullptr, "Exit", "Exit", MB_OK);
		runtime::UnloadHostFXR();

		debug::ExitDebugConsole();
	}


	HINSTANCE gNativeModuleInstance;
}