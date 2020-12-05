#include <iostream>
#include <cstdio>
#include <iomanip>

long double C(int N, int K)
{
    return ((N < K) ? 0 : ((K == 0) ? 1 : ((N - K + 1) / long double(K) * C(N, K - 1))));
}
int main()
{
    int x;
    std::cout << "Enter the number of lines of Pascal's triangle (x > 0): ";
    std::cin >> x;
    for (int i = 0; i <= x; ++i) {
        for (int j = 0; j <= i; ++j)
            std::cout << C(i, j) << std::setw(5);
        std::cout << std::endl;
    }
    std::cin.get();
    std::cin.get();
    return 0;
}
