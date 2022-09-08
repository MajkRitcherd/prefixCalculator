#pragma once

#include <vector>
#include <map>
#include <string>
#include <regex>

namespace prefixCalculator
{
	// Checks whether string matches regex pattern inside this class
	class RegexCheck
	{
	public:
		RegexCheck();
		~RegexCheck();

		std::vector<std::string> getKeys() const;
		std::vector<std::regex> getValues() const;
		std::map<std::string, std::regex>::iterator checkPattern(std::string& str);
		bool isEnd(std::map<std::string, std::regex>::iterator it) const;
	private:
		std::map<std::string, std::regex> m_patterns;
		std::map<int8_t, std::string> m_allowedStrings;
	};
}