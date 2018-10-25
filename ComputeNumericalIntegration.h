#ifndef COMPUTE_NUMERICAL_INTEGRATION_H
#define COMPUTE_NUMERICAL_INTEGRATION_H

#include <functional>
/*

Input:
tol = prescribed tolerance
I_numerical(n) = result of 3 rules

Output:
I_approx = approximation with tolerance tol

n = 4; I_old = I_numerical(n)
n = 2n; I_new = I_numerical(n)

while( abs(I_new - I_old) > tol )
	I_old = I_new
	n = 2n;
	I_new = I_numerical(n)
end
I_approx = I_new

*/

double ComputeNumericalIntegration(double tol, std::function<double(double)> I_numerical)
{
	size_t n = 4; double I_old = I_numerical(n);
	n *= 2; double I_new = I_numerical(n);

	while (abs(I_new - I_old) > tol)
	{
		I_old = I_new;
		n *= 2;
		I_new = I_numerical(n);
	}

	return I_new;
}

#endif