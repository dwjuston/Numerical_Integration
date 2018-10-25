#ifndef COMPUTE_NUMERICAL_INTEGRATION_H
#define COMPUTE_NUMERICAL_INTEGRATION_H

#include <functional>

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
