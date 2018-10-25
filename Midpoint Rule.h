#ifndef MIDPOINT_H
#define MIDPOINT_H

#include <functional>

/*

Input:
a = left endpoint of the integration interval
b = right endpoint of the integration interval
n = number of partition intervals
f_int(x) = routine evaluating f(x)

Output:
I_midpoint = Midpoint Rule approximation

h = (b-a)/n; I_midpoint = 0;
for i = 1 : n
	I_midpoint += f_int( a + (i-1/2)h  )
end
I_midpoint = h * I_midpoint

*/

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