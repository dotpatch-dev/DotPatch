#include <dotpatch/runtime.hh>

#include <sstream>

#include <Windows.h>

namespace dotpatch::runtime::detail
{
	void RawPanic(const char* message, const char* fileName, const char* functionName, int line, int column)
	{
		std::stringstream formattedMessage;

		formattedMessage << "[" << fileName << " line " << line << " column " << column << "]: " << message << std::endl;

		MessageBoxA(nullptr, formattedMessage.str().c_str(), "DotPatch Panic Handler", MB_ICONERROR | MB_OK);
	}
}