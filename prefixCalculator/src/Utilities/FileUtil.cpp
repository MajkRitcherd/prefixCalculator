#include "FileUtil.h"

#include <comdef.h>

namespace prefixCalculator
{
	namespace utilities
	{
		bool GetFile(const wchar_t* url, const wchar_t* saveDest)
		{
			if (S_OK == URLDownloadToFileW(NULL, url, saveDest, 0, NULL))
				return true;
			else
				return false;
		}

		std::fstream OpenFile(const wchar_t* wDest, std::ios_base::openmode mode)
		{
			_bstr_t b(wDest);
			const char* dest = b;

			std::fstream fileHandle(dest, mode);
			if (!fileHandle.is_open())
				throw "Couldn't open the file!";
			return fileHandle;
		}

		void CloseFile(std::fstream& file)
		{
			file.close();
		}

		bool DelFile(const wchar_t* wDest)
		{
			_bstr_t b(wDest);
			const char* dest = b;

			if (remove(dest) != 0)
				throw "Couldn't delete the file!";
			else
				return true;
		}
	}
}