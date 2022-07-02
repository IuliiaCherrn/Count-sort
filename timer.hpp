#pragma once
#include<chrono>

using namespace std;

namespace yc
{
	class Timer
	{
	private:
		using clock_t = chrono::high_resolution_clock;
		using second_t = chrono::duration<double, ratio<1> >;

		chrono::time_point<clock_t> m_beg;
	public:
		Timer() : m_beg(clock_t::now()) {}

		void reset();

		double elapsed() const
		{
			return chrono::duration_cast<second_t>(clock_t::now() - m_beg).count();
		}
	};
}
