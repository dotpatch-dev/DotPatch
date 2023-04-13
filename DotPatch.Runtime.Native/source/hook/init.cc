#include <dotpatch/hook.hh>
#include <dotpatch/debug.hh>

#include <MinHook.h>

namespace dotpatch::hook
{
	void Initialize()
	{
		if (MH_Initialize() != MH_OK)
		{
			debug::Panic("Failed to initialize hooking subsystem");
		}
	}

	void Exit()
	{
		if (MH_Uninitialize() != MH_OK)
		{
			debug::Panic("Failed to uninitialize hooking subsystem");
		}
	}

	void CreateHook(void* target, void* hook, void** original)
	{
		if (MH_CreateHook(target, hook, original) != MH_OK)
		{
			debug::Panic("Failed to create hook");
		}

		if (MH_EnableHook(target) != MH_OK)
		{
			debug::Panic("Failed to enable hook");
		}
	}

	void RemoveHook(void* target)
	{
		if (MH_DisableHook(target) != MH_OK)
		{
			debug::Panic("Failed to disable hook");
		}
	}
}