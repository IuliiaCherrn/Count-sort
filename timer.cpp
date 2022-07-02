#include "timer.hpp"
#include <chrono>

namespace yc
{

	void Timer::reset()
	{
		m_beg = clock_t::now();
	}
}