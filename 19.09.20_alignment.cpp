#include <iostream>
#include <iomanip>

int main()
{
	const int n = 5, m = 6;
	int N[n][m];
	for (int i = 0; i < n; ++i)
		for (int j = 0; j < m; ++j)
			N[i][j] = rand() % 1000;

	for (int i = 0; i < n; ++i){
		for (int j = 0; j < m; ++j){
			std::cout << std::setw(8) << N[i][j];
		}
		std::cout << "\n";
	}
	std::cout << "\n" << "\n";
	for (int i = 0; i < n; ++i){
		for (int j = 0; j < m; j++){
			std::cout << "\t" << N[i][j];
		}
		std::cout << "\n";
	}
}
