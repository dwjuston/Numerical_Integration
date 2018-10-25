#ifndef TRAPOZOIDAL_H
#define TRAPOZOIDAL_H

#include <functional>

double Trapezoidal(double a, double b, size_t n, std::function<double(double)> f_int)
{
	double I_trap = 0;
	double h = (b - a) / n;

	for (int i = 0; i < n; ++i)
		I_trap += f_int(a + i*h);

	I_trap *= h;
	return I_trap;
}

#endif
