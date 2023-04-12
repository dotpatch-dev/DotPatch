#include <dotpatch/runtime/init.hh>

#include <iostream>

int main(int argc, const char** argv)
{
	if (argc > 10)
	{
		dotpatch::runtime::Initialize();
	}

	std::cin.get();
	return 0;
}