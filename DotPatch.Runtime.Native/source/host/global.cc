#include <dotpatch/host.hh>
#include <dotpatch/runtime.hh>

#include <Windows.h>

namespace dotpatch::host
{
	namespace detail
	{
		template <typename T>
		T GetExport(HMODULE mod, const char* func) { return reinterpret_cast<T>(GetProcAddress(mod, func)); }
	}

	namespace global
	{
		HMODULE HostfxrModule;

		hostfxr_initialize_for_runtime_config_fn InitializeForRuntimeConfig;
		hostfxr_get_runtime_delegate_fn GetRuntimeDelegate;
		hostfxr_close_fn Close;
	}

	void LoadHostFXR()
	{
		char_t hostFxrPath[MAX_PATH];
		size_t hostFxrPathSize = sizeof(hostFxrPath) / sizeof(char_t);
		if (get_hostfxr_path(hostFxrPath, &hostFxrPathSize, nullptr) != 0)
		{
			runtime::Panic("Failed to get hostfxr path");
		}

		global::HostfxrModule = LoadLibraryW(hostFxrPath);
		global::InitializeForRuntimeConfig = detail::GetExport<hostfxr_initialize_for_runtime_config_fn>(global::HostfxrModule, "hostfxr_initialize_for_runtime_config");
		global::GetRuntimeDelegate = detail::GetExport<hostfxr_get_runtime_delegate_fn>(global::HostfxrModule, "hostfxr_get_runtime_delegate");
		global::Close = detail::GetExport<hostfxr_close_fn>(global::HostfxrModule, "hostfxr_close");
	}

	void UnloadHostFXR()
	{
		if (global::HostfxrModule != nullptr)
		{
			FreeLibrary(global::HostfxrModule);
			global::InitializeForRuntimeConfig = nullptr;
			global::GetRuntimeDelegate = nullptr;
			global::Close = nullptr;
		}
	}
}