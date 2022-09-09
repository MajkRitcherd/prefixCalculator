#pragma once
#pragma warning(suppress : 26800)

#include "../../vendor/nlohmann/json.hpp"
#include "FileUtil.h"

namespace prefixCalculator
{
	namespace utilities
	{
		using json = nlohmann::json;

		// Downloads currency exchange from internet and writes it into a file
		bool UpdateJson();

		// Returns currency rate between fromC to toC
		double_t getRate(std::string& from, std::string& to, std::string& rate);
	}
}