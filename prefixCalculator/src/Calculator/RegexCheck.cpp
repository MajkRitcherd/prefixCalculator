#include "RegexCheck.h"

namespace prefixCalculator
{
	RegexCheck::RegexCheck()
	{
		m_patterns.insert(std::pair<std::string, std::regex>
			("binaryNumber", std::regex("0b[0-1]+")));

		m_patterns.insert(std::pair<std::string, std::regex>
			("constants", std::regex("(pi|e|phi)")));

		m_patterns.insert(std::pair<std::string, std::regex>
			("floatNumber", std::regex("^[-|+]?\\d+\\.\\d+$")));

		m_patterns.insert(std::pair<std::string, std::regex>
			("fraction", std::regex("^[-|+]?\\d+/[-|+]?\\d+$")));

		m_patterns.insert(std::pair<std::string, std::regex>
			("hexadecimalNumber", std::regex("0x[\\dA-F]+")));

		m_patterns.insert(std::pair<std::string, std::regex>
			("operation", std::regex("^[\\+|\\-|\\*|/]|" \
			 "(#|abs|pow|sqrt|cbrt|fac|log|ln|mod|sin|cos|" \
			 "tan|cotan|sum|prod|cz-eu|cz-do|cz-po|eu-cz|eu-do" \
			 "|eu-po|do-cz|do-eu|do-po|po-cz|po-eu|po-do){1}$")));

		m_patterns.insert(std::pair<std::string, std::regex>
			("romNumFollowsRules", std::regex("^M{0,3}(CM|CD|D?C{0,3})(XC|XL|L?X{0,3})(IX|IV|V?I{0,3})$")));

		m_patterns.insert(std::pair<std::string, std::regex>
			("savedResults", std::regex("^[s|S]\\d+$")));

		m_patterns.insert(std::pair<std::string, std::regex>
			("wholeNumber", std::regex("^[-|+]?\\d+$")));
	}

	RegexCheck::~RegexCheck()
	{
	}

	std::vector<std::string> RegexCheck::getKeys() const
	{
		size_t count = m_patterns.size();
		std::vector<std::string> res;
		for (auto it = m_patterns.begin(); it != m_patterns.end(); it++)
			res.push_back(it->first);

		return res;
	}

	std::vector<std::regex> RegexCheck::getValues() const
	{
		size_t count = m_patterns.size();
		std::vector<std::regex> res;
		for (auto it = m_patterns.begin(); it != m_patterns.end(); it++)
			res.push_back(it->second);

		return res;
	}

	std::map<std::string, std::regex>::iterator RegexCheck::checkPattern(std::string& str)
	{
		std::map<std::string, std::regex>::iterator it;
		for (it = m_patterns.begin(); it != m_patterns.end(); it++)
			if (std::regex_match(str, it->second))
				return it;
		return it;
	}

	bool RegexCheck::isEnd(std::map<std::string, std::regex>::iterator it) const
	{
		return m_patterns.end() == it;
	}
}