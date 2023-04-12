#pragma once

#include <hostfxr.h>

namespace dotpatch::runtime
{
	class ManagedHost
	{
	public:
		ManagedHost(hostfxr_handle ctx);
		~ManagedHost();

	private:
		hostfxr_handle Context;
	};
}