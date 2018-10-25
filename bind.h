#ifndef BIND_H
#define BIND_H

#include <functional>

auto bind_function(double a, double b, std::function<double(double)> f_int, std::function<double(double,double,size_t, std::function<double(double)>)> particular_rule)
{
	using namespace std::placeholders;

	std::function<double(double)> ret = std::bind(particular_rule, a, b, _1, f_int);
	return ret;
}


#endif