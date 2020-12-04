#include <iostream>
#include <stdarg.h>

int even_count(int N, int x, ...) {
	va_list args;
	va_start(args, x);
	int a = x, n = 0;
	while (N--) {
		if (a % 2 == 0) {
			++n;
		}
		a = va_arg(args, int);
	}
	va_end(args);
	return n;
}
int main()
{
	std::cout << even_count(10, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10) << std::endl;
}
