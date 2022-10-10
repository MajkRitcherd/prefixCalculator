#pragma once
#pragma warning(suppress : 26800)

#include "../../vendor/nlohmann/json.hpp"
#include "FileUtil.h"

namespace prefixCalculator
{
	namespace utilities
	{
		using json = nlohmann::json;

		/// <summary>
		/// Returns currency rate between fromCurr to toCurr.
		/// </summary>
		/// <param name="fromCurr:">Currency to change from.</param>
		/// <param name="toCurr:">Currency to change to.</param>
		/// <param name="rate:">'rate' (fromCurr -> toCurr) or 'inverseRate' (toCurr -> fromCurr)</param>
		/// <returns>Curerncy rate.</returns>
		double_t getRate(std::string& fromCurr, std::string& toCurr, std::string& rate);

		/// <summary>
		/// Downloads currency exchange from internet and writes it to the file.
		/// </summary>
		/// <returns>True if successful, otherise false.</returns>
		bool UpdateJson();

	}
}