#include <iostream>

int main()
{
	double x;
	int n;
	std::cout << "Enter value x: ";
	std::cin >> x;
	std::cout << "Enter a natural number: ";
	std::cin >> n;
	if (n > 1) {
		double S = 0, Ak = x;
		for (double k = 0; k <= n; ++k) {
			S += Ak;
			Ak *= (-1) * x * x / (2 * k + 2) / (2 * k + 3);
		}
		std::cout << "S1 = " << S << "\n";

		double eps = 1e-6;
		//S = 0;
		Ak = x;
		double k = 0;
		while (Ak > eps || Ak < -eps) {
			S += Ak;
			Ak *= (-1) * x * x / (2 * k + 2) / (2 * k + 3);
			++k;
		}
		std::cout << "S2= " << S << "\n";
		std::cout << "k = " << k << "\n";
	}
	else return 0;

}
