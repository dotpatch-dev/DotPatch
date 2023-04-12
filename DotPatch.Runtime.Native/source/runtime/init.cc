#include <dotpatch/runtime.hh>
#include <dotpatch/host.hh>

namespace dotpatch::runtime
{
	void Initialize()
	{
		host::LoadHostFXR();
		auto managed = host::LoadManagedRuntime();
	}

	void Exit()
	{
		host::UnloadHostFXR();
	}
}