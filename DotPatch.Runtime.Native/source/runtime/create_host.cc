#pragma once

#include <dotpatch/runtime.hh>
#include <dotpatch/debug.hh>

#include <string>
#include <filesystem>

#include <Windows.h>

namespace dotpatch::runtime
{
	std::filesystem::path  GetBinDirPath()
	{
		wchar_t buffer[MAX_PATH];
		GetModuleFileNameW(runtime::gNativeModuleInstance, buffer, MAX_PATH);
		return std::filesystem::path(buffer).parent_path();
	}

	const auto ManagedRuntimeName = L"DotPatch.Runtime.Managed";
	const auto ManagedRuntimeNativeInterfaceClass = L"DotPatch.Runtime.Managed.NativeInterface, DotPatch.Runtime.Managed";
	const auto ManagedRuntimeEntrypointDelegate = L"DotPatch.Runtime.Managed.NativeInterface+EntrypointDelegate, DotPatch.Runtime.Managed";
	ManagedHost LoadManagedRuntime()
	{
		auto runtimeConfigPath = (GetBinDirPath() / (std::wstring(ManagedRuntimeName) + L".runtimeconfig.json")).wstring();
		auto assemblyPath = (GetBinDirPath() / (std::wstring(ManagedRuntimeName) + L".dll")).wstring();

		void* loadFunc = nullptr;
		hostfxr_handle ctx = nullptr;

		if (global::InitializeForRuntimeConfig(runtimeConfigPath.c_str(), nullptr, &ctx) != 0 || ctx == nullptr)
		{
			debug::Panic("Failed to find runtime config: %S", runtimeConfigPath.c_str());
		}

		if (global::GetRuntimeDelegate(ctx, hdt_load_assembly_and_get_function_pointer, &loadFunc) != 0 || loadFunc == nullptr)
		{
			debug::Panic("Failed to get runtime delegate");
		}

		auto LoadAssemblyAndGetFunctionPointer = (load_assembly_and_get_function_pointer_fn)loadFunc;

		void (*entrypoint)() = nullptr;
		auto result = LoadAssemblyAndGetFunctionPointer(assemblyPath.c_str(), ManagedRuntimeNativeInterfaceClass, L"Entrypoint", ManagedRuntimeEntrypointDelegate, nullptr, (void**) & entrypoint);
		if (result != 0)
		{
			debug::Panic("Failed to load assembly: %S", assemblyPath.c_str());
		}

		entrypoint();
		return { ctx };
	}

	ManagedHost::ManagedHost(hostfxr_handle handle) : Context(handle) {}
	
	ManagedHost::~ManagedHost()
	{
		global::Close(Context);
	}
}