#include "Operations.h"
#include <stdexcept>

namespace numRep
{
	namespace oper
	{
		opCode getCode(std::string& str)
		{
			int pos = findString(str);
			if (pos == -1)
				throw std::runtime_error("Operation does not exist!!");
			else
				return opCode(pos);
		}

		int findString(std::string& str)
		{
			for (int i = 0; i < TWOCOUNT; i++)
				if (str2Code[i] == str)
					return i;

			for (int i = 0; i < SINGLECOUNT; i++)
				if (str1Code[i] == str)
					return i + 6;

			for (int i = 0; i < ALLCOUNT; i++)
				if (strAllCode[i] == str)
					return i + 28;
			
			return -1;
		}

		bool isSingleOperator(std::string& str)
		{
			for (int i = 0; i < SINGLECOUNT; i++)
				if (str == str1Code[i])
					return true;
			return false;
		}

		bool isOperator(std::string& str)
		{
			for (int i = 0; i < TWOCOUNT; i++)
				if (str == str2Code[i])
					return true;
			return false;
		}
		
		bool isAllOperator(std::string& str)
		{
			for (int i = 0; i < ALLCOUNT; i++)
				if (str == strAllCode[i])
					return true;
			return false;
		}
	}
}