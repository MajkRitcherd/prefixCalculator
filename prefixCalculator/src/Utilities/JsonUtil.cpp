#include "JsonUtil.h"

#include <iostream>

namespace prefixCalculator
{
	namespace utilities
	{
		bool UpdateJson()
		{
			using namespace prefixCalculator;
			using json = nlohmann::json;
			
			const wchar_t* currExch1 = L"data\\CurrencyExchange1.json";
			const wchar_t* currExch2 = L"data\\CurrencyExchange2.json";
			const wchar_t* currExch3 = L"data\\CurrencyExchange3.json";
			json obj = json::object();

			try
			{
				std::cout << "..";
				if (!utilities::GetFile(L"http://www.floatrates.com/daily/eur.json", currExch1))
					return false;
				if (!utilities::GetFile(L"http://www.floatrates.com/daily/czk.json", currExch2))
					return false;
				if (!utilities::GetFile(L"http://www.floatrates.com/daily/usd.json", currExch3))
					return false;

				std::cout << "..";
				auto curExHandle1 = utilities::OpenFile(currExch1, std::ios::in);
				json jsonFile1 = json::parse(curExHandle1);
				utilities::CloseFile(curExHandle1);
				utilities::DelFile(currExch1);

				auto curExHandle2 = utilities::OpenFile(currExch2, std::ios::in);
				json jsonFile2 = json::parse(curExHandle2);
				utilities::CloseFile(curExHandle2);
				utilities::DelFile(currExch2);

				auto curExHandle3 = utilities::OpenFile(currExch3, std::ios::in);
				json jsonFile3 = json::parse(curExHandle3);
				utilities::CloseFile(curExHandle3);
				utilities::DelFile(currExch3);
				
				std::cout << ".." << std::endl;
				obj.push_back({ "eur", {{ "czk", {{"rate", jsonFile1["czk"]["rate"]}, {"inverseRate", jsonFile1["czk"]["inverseRate"]}} },
										  { "usd", {{"rate", jsonFile1["usd"]["rate"]}, {"inverseRate", jsonFile1["usd"]["inverseRate"]}} },
										  { "gbp", {{"rate", jsonFile1["gbp"]["rate"]}, {"inverseRate", jsonFile1["gbp"]["inverseRate"]}} }} });
				obj.push_back({ "czk", {{"usd", {{"rate", jsonFile2["usd"]["rate"]}, {"inverseRate", jsonFile2["usd"]["inverseRate"]}}},
										  { "gbp", {{"rate", jsonFile2["gbp"]["rate"]}, {"inverseRate", jsonFile2["gbp"]["inverseRate"]}}}} });
				obj.push_back({ "usd", {"gbp", {{"rate", jsonFile3["gbp"]["rate"]}, {"inverseRate", jsonFile3["gbp"]["inverseRate"]}}} });

				std::fstream currency = utilities::OpenFile(L"data\\currency.json", std::ios::trunc | std::ios::out);
				currency << obj;
				utilities::CloseFile(currency);
			}
			catch (const char* e)
			{
				std::cout << "Exception was thrown: " << e << std::endl;
			}
			return true;
		}

		double_t getRate(std::string& fromC, std::string& toC, std::string& rate)
		{
			using json = nlohmann::json;

			auto file = utilities::OpenFile(L"data\\currency.json", std::ios::in);
			json js = json::parse(file);
			utilities::CloseFile(file);

			return (double_t)std::stod(js[fromC][toC][rate].dump());		}
	}
}