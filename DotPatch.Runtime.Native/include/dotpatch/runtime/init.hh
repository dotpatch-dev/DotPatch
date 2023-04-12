#pragma once

#include <dotpatch/misc/common.hh>

#include <Windows.h>

namespace dotpatch::runtime
{
	extern HINSTANCE gNativeModuleInstance;

	dp_export void Initialize();
	dp_export void Exit();
}