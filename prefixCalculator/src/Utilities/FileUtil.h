#pragma once

#include <fstream>

#pragma comment(lib, "Urlmon.lib")

namespace prefixCalculator
{
	namespace utilities
	{
		bool GetFile(const wchar_t* url, const wchar_t* saveDest); 

		std::fstream OpenFile(const wchar_t* dest, std::ios_base::openmode mode);

		void CloseFile(std::fstream& file);
		
		bool DelFile(const wchar_t* dest);
	}
}