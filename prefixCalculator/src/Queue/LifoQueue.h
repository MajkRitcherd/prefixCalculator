#pragma once

#include <limits>
#include <cstdint>

#ifndef MAX_HISTORY
	#define MAX_HISTORY 10
#endif // !MAX_HISTORY

namespace Queue
{
	/// <summary>
	/// Last in first out queue (own implementation)
	/// </summary>
	/// <typeparam name="T"></typeparam>
	template <class T>
	class LifoQueue
	{
	public:
		/// <summary>
		/// Creates new LifoQueue with maximum size of MAX_HISTORY
		/// </summary>
		LifoQueue() { m_queue = new T[MAX_HISTORY]; };

		/// <summary>
		/// Deletes LifoQueue
		/// </summary>
		~LifoQueue() { delete m_queue; };

		/// <summary>
		/// Gets queue.
		/// </summary>
		/// <returns>Pointer to the queue.</returns>
		T* getQueue() const { return m_queue; };

		/// <summary>
		/// Gets element at position of index.
		/// </summary>
		/// <param name="index:">Position of searched value.</param>
		/// <returns>Actual value on that posiiton.</returns>
		T& operator[](int index) { return m_queue[index]; };

		/// <summary>
		/// Clears the queue.
		/// </summary>
		void clear()
		{
			for (int i = 0; i < MAX_HISTORY; i++)
				m_queue[i] = std::numeric_limits<double_t>::max();
		};

		/// <summary>
		/// Pushes element to the back of the queue.
		/// </summary>
		/// <param name="number:">Element to be pushed.</param>
		void push(T& number)
		{
			for (int i = MAX_HISTORY - 1; i >= 0; i--)
				m_queue[i + 1] = m_queue[i];
			m_queue[0] = number;
		};

	private:
		T* m_queue = nullptr;
	};
}