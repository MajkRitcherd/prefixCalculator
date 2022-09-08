#pragma once

#ifndef MAX_HISTORY
#define MAX_HISTORY 10
#endif // !MAX_HISTORY


#include "../Pch.h"
#include "CalcBrain.h"
#include "Display.h"

namespace prefixCalculator
{
	class Calculator
	{
	public:
		Calculator();
		~Calculator();

		void run();

	private:
		CalcBrain* m_calcBrain = nullptr;
		Display* m_display = nullptr;
	};
}