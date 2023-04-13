#include <dotpatch/runtime.hh>
#include <dotpatch/debug.hh>
#include <dotpatch/hook.hh>

namespace dotpatch::runtime
{
	void Initialize()
	{
		debug::InitializeDebugConsole();
		hook::Initialize();

		runtime::LoadHostFXR();
		auto managed = runtime::LoadManagedRuntime();
	}

	void Exit()
	{
		MessageBoxA(nullptr, "Exit", "Exit", MB_OK);
		runtime::UnloadHostFXR();

		hook::Exit();
		debug::ExitDebugConsole();
	}


	HINSTANCE gNativeModuleInstance;
}