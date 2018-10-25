#ifndef SIMPSONS_RULE_H
#define SIMPSONS_RULE_H

#include <functional>
/*

Input:
a = left endpoint of the integration interval
b = right endpoint of the integration interval
n = number of partition intervals
f_int(x) = routine evaluating f(x)

Output:
I_simpson = Simpson's Rule approximation

h = (b-a)/n;
I_simpson = f_int(a)/6 + f_int(b)/6

for i = 1 : (n-1)
	I_simpson += f_int( a + ih  ) / 3
end
for i = 1 : n
	I_simpson += 2 * f_int(   a+ (i-1/2)h   )   /3
end
I_simpson = h * I_simpson

*/

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