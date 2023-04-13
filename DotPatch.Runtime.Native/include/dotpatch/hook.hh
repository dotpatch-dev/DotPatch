#pragma once

#include <dotpatch/misc/common.hh>

namespace dotpatch::hook
{
	void Initialize();
	void Exit();

	dp_export void CreateHook(void* target, void* hook, void** original);
	dp_export void RemoveHook(void* target);
}