#include <iostream>
#include <functional>
#include "bind.h"
#include "Midpoint Rule.h"
#include "Trapozoidal Rule.h"
#include "Simpson's Rule.h"
#include "ComputeNumericalIntegration.h"

using namespace std;

auto f = [](double x) {return sqrt(x); };

int main()
{
	auto func = bind_function(0, 10, f, Simpson);
	cout << ComputeNumericalIntegration(0.000001, func);

	getchar();
	getchar();
	return 0;
}