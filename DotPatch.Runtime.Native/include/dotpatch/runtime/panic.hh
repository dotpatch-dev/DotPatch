#pragma once

#include <dotpatch/common.hh>
#include <dotpatch/utility.hh>

#include <cstdarg>
#include <cstdio>
#include <source_location>

namespace dotpatch::runtime
{
	namespace detail
	{
		void RawPanic(const char* message, const char* fileName, const char* functionName, int line, int column);
	}

	inline void Panic(const char* fmt = nullptr, ...)
	{
		auto file = __builtin_FILE();
		auto func = __builtin_FUNCTION();
		auto line = __builtin_LINE();
		auto column = __builtin_COLUMN();

		if (fmt != nullptr)
		{
			va_list args;
			va_start(args, fmt);
			auto stringLength = std::vsnprintf(nullptr, 0, fmt, args);
			auto buffer = new char[stringLength + 1];
			std::vsprintf(buffer, fmt, args);
			va_end(args);

			detail::RawPanic(buffer, file, func, line, column);
			delete[] buffer;
		}
		else
		{
			detail::RawPanic("No further information provided", file, func, line, column);
		}

	}
}
