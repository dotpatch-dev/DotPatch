#pragma once

#include <string>
#include <codecvt>

namespace dotpatch::utility
{
	inline std::wstring to_wstring(const std::string& source)
	{
		std::wstring_convert<std::codecvt_utf8<wchar_t>> converter;
		return converter.from_bytes(source);
	}

	inline std::string to_string(const std::wstring& source)
	{
		std::wstring_convert<std::codecvt_utf8<wchar_t>> converter;
		return converter.to_bytes(source);
	}
}