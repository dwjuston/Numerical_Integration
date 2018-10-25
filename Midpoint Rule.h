#ifndef MIDPOINT_H
#define MIDPOINT_H

#include <functional>

double Midpoint(double a, double b, size_t n, std::function<double(double)> f_int)
{
	double I_midpoint = 0;
	double h = (b - a) / n;

	for (int i = 0; i < n; ++i)
		I_midpoint += f_int(a + (i - 1 / 2) * h);

	I_midpoint *= h;
	return I_midpoint;
}

#endif
