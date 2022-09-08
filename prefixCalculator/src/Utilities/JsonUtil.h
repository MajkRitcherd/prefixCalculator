#pragma once
#pragma warning(suppress : 26800)

#include "../../vendor/nlohmann/json.hpp"
#include "FileUtil.h"

namespace prefixCalculator
{
	namespace utilities
	{
		using json = nlohmann::json;

		bool UpdateJson();

		double_t getRate(std::string& from, std::string& to, std::string& rate);
	}
}