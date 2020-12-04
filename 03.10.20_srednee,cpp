#include <iostream>
#include <stdarg.h>

double average(double x, ...) {
	va_list args;
	va_start(args, x);
	double a = x, sr = 0;
	int n = 0;
	while (a != -1.0) {
		sr += a;
		++n;
		a = va_arg(args, double);
	}
	va_end(args);
	sr /= n;
	return sr;
}
int main()
{
	std::cout << average(1.0, 2.0, 3.0, 4.0, 5.0, 6.0, 7.0, 8.0, 9.0, 10.0, -1.0) << std::endl;
}
