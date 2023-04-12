#include <dotpatch/debug.hh>

#include <sstream>

#include <Windows.h>

namespace dotpatch::debug::detail
{
	void RawPanic(const char* message, const char* fileName, const char* functionName, int line, int column)
	{
		std::stringstream formattedMessage;

		formattedMessage << "[" << fileName << " line " << line << " column " << column << "]: " << message << std::endl;

		MessageBoxA(nullptr, formattedMessage.str().c_str(), "DotPatch Panic Handler", MB_ICONERROR | MB_OK);
		ExitProcess(1);
	}
}