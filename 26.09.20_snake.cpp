#include <iostream>
#include <iomanip>

void snake(int **N, int n) {
  int k = 1, i = 0, j = 0, d=1;
	while (k <= n*(n+1)/2) {
		N[i][j] = k++;
		i += d;
		j -= d;
		if (j < 0) {
			j = 0;
			d = -d;
		}if(i < 0) {
			i = 0;
			d = -d;
		}
	}
	i += d;
	j -= d;
	while (k <= n * n) {
		N[i][j] = k++;
		i += d;
		j -= d;
		if (i >= n) {
			d = -d;
			i = n - 1;
			j += 2;
		}if(j >= n) {
			d = -d;
			j = n - 1;
			i += 2;
		}
	}
}

int main()
{
	int n = 10;
	int** N = new int* [n];
	for (int i = 0; i < n; ++i) {
		N[i] = new int[n];
	}
	snake(N, n);
	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < n; ++j)
			std::cout << std::setw(4) << N[i][j];
			std::cout << "\n";
	}
	for (int i = 0; i < n; ++i)
		delete[] N[i];
	delete[] N;
	return 0;
}
