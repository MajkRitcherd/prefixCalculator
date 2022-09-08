#pragma once

#include "../Pch.h"

namespace Queue
{
	template <class T>
	class LifoQueue
	{
	public:
		LifoQueue() { m_queue = new T[MAX_HISTORY]; };
		~LifoQueue() { delete m_queue; };

		T* getQueue() const { return m_queue; };
		T& operator[](int index) { return m_queue[index]; };

		void push(T& number)
		{
			for (int i = MAX_HISTORY - 1; i >= 0; i--)
				m_queue[i + 1] = m_queue[i];
			m_queue[0] = number;
		};

		void clear()
		{
			for (int i = 0; i < MAX_HISTORY; i++)
				m_queue[i] = std::numeric_limits<float_t>::max();
		};

	private:
		T* m_queue = nullptr;
	};
}