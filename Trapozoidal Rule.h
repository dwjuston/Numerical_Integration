#ifndef TRAPOZOIDAL_H
#define TRAPOZOIDAL_H

#include <functional>
/*

Input:
a = left endpoint of the integration interval
b = right endpoint of the integration interval
n = number of partition intervals
f_int(x) = routine evaluating f(x)

Output:
I_trap = Trapezoidal Rule approximation

h = (b-a)/n; 
I_trap = f_int(a)/2 + f_int(b)/2
for i = 1 : n
	I_trap += f_int( a + ih  )
end
I_trap = h * I_trap

*/

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