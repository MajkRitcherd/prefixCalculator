#pragma once

#include <fstream>

#pragma comment(lib, "Urlmon.lib")

namespace prefixCalculator
{
	namespace utilities
	{
		/// <summary>
		/// Closes file.
		/// </summary>
		/// <param name="file:">Handle to the file.</param>
		void CloseFile(std::fstream& file);
		
		/// <summary>
		/// Deletes file.
		/// </summary>
		/// <param name="dest:">Path to the file.</param>
		/// <returns>True if successful, otherwise false.</returns>
		bool DelFile(const wchar_t* dest);

		/// <summary>
		/// Downloads file.
		/// </summary>
		/// <param name="url:">URL to the file.</param>
		/// <param name="saveDest:">Save destination.</param>
		/// <returns>True if successful, otherwise false.</returns>
		bool GetFile(const wchar_t* url, const wchar_t* saveDest); 

		/// <summary>
		/// Opens file.
		/// </summary>
		/// <param name="dest:">Path to the file.</param>
		/// <param name="mode:">Open mode.</param>
		/// <returns>Handle to the file.</returns>
		std::fstream OpenFile(const wchar_t* dest, std::ios_base::openmode mode);
	}
}