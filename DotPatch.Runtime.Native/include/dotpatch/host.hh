#pragma once

#include <hostfxr.h>
#include <nethost.h>
#include <coreclr_delegates.h>

#include <Windows.h>

namespace dotpatch::host
{
	namespace global
	{
		extern HMODULE HostfxrModule;

		extern hostfxr_initialize_for_runtime_config_fn InitializeForRuntimeConfig;
		extern hostfxr_get_runtime_delegate_fn GetRuntimeDelegate;
		extern hostfxr_close_fn Close;
	}

	void LoadHostFXR();
	void UnloadHostFXR();

	class ManagedHost
	{
	public:
		ManagedHost(hostfxr_handle ctx);
		~ManagedHost();

	private:
		hostfxr_handle Context;
	};

	ManagedHost LoadManagedRuntime();
}