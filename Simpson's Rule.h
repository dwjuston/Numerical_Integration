#ifndef SIMPSONS_RULE_H
#define SIMPSONS_RULE_H

#include <functional>

double Simpson(double a, double b, size_t n, std::function<double(double)> f_int)
{
	double I_simpson = 0;
	double h = (b - a) / n;

	for (int i = 0; i < n-1; ++i)
		I_simpson += f_int(a + i * h) / 3;

	for (int i = 0; i < n; ++i)
		I_simpson += 2 * f_int(a + (i - 1 / 2) * h) / 3;

	I_simpson *= h;

	return I_simpson;
}


#endif
