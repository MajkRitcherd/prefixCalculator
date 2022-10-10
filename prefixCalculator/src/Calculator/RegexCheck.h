#pragma once

#include <vector>
#include <map>
#include <string>
#include <regex>

namespace prefixCalculator
{
//========================================================================
//																		  
//		Class for checking strings if they match regular expression					  
//																		  
//========================================================================

#pragma region RegexCheckClass

	class RegexCheck
	{
	#pragma region PublicMethods

		public:
			/// <summary>
			/// Creates RegexCheck class.
			/// </summary>
			RegexCheck();

			/// <summary>
			///	Destroys RegexCheck class.
			/// </summary>
			~RegexCheck();

			/// <summary>
			/// Finds regex pattern by given key.
			/// </summary>
			/// <param name="str:">Key represented by string.</param>
			/// <returns>Iterator to regex pattern or end.</returns>
			std::map<std::string, std::regex>::iterator checkPattern(std::string& str);

			/// <summary>
			/// Gets keys of all regex patterns.
			/// </summary>
			/// <returns>Vector of keys.</returns>
			std::vector<std::string> getKeys() const;

			/// <summary>
			/// Gets all stored regex patterns.
			/// </summary>
			/// <returns>Vector of regex patterns.</returns>
			std::vector<std::regex> getValues() const;

			/// <summary>
			/// Checks whether iterator is end iterator.
			/// </summary>
			/// <param name="it:">Iterator.</param>
			/// <returns>True if iterator is end iterator, otherwise false.</returns>
			bool isEnd(std::map<std::string, std::regex>::iterator it) const;

	#pragma endregion

	#pragma region PrivateMembers

		private:
			std::map<std::string, std::regex> m_patterns;
			std::map<int8_t, std::string> m_allowedStrings;

	#pragma endregion

	};

#pragma endregion

}