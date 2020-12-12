#include <iostream>
#include <cmath>

double fx(double x) {
	return x * x * x - 15 * x * x + 24 * x - 10 ; //нужная функция
    }
double derivative(double x) {
	return 3 * x * x - 30 * x + 24; // её производная
}
typedef double(*fun)(double x); 
double fsolve(fun fx, fun derivative, double x0) {
	double x1 = x0 - fx(x0) / derivative(x0); 
	while (fabs(x1 - x0) > 0.000001) { 
		x0 = x1;
		x1 = x0 - fx(x0) / derivative(x0); 
	}
	return x1;
}

int main() {
	std::cout << fsolve(fx, derivative, 10);
	return 0;
}
