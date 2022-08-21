#include "Calculator.h"

namespace prefixCalculator
{
	Calculator::Calculator()
	{
		m_calcBrain = new CalcBrain;
		m_display = new Display;
	}

	Calculator::~Calculator()
	{
	}

	void Calculator::run()
	{
		m_calcBrain->run(m_display);
	}
}