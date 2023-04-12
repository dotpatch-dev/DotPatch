#include <dotpatch/runtime.hh>

int main(int argc, const char** argv)
{
	using namespace dotpatch;
	runtime::Initialize();

	runtime::Exit();
	return 0;
}