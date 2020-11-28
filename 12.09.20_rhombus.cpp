#include <iostream>

int main()
{
    int n;
    std::cout << "Enter the number of rhombuses (n > 0):  ";
    std::cin >> n;
    if (n > 0) {
        for (int i = 1; i <= n; ++i) {
            for (int s = 1; s <= n; ++s) {
                for (int j = 1; j <= n - i; ++j) {
                    std::cout << " ";
                }
                for (int j = 1; j <= 2 * i - 1; ++j) {
                    std::cout << "*";
                }
                for (int j = 1; j <= n - i; ++j) {
                    std::cout << " ";
                }
            }
            std::cout << std::endl;
        }

        for (int i = n - 1; i >= 1; --i) {
            for (int s = 1; s <= n; ++s) {
                for (int j = 1; j <= n - i; ++j) {
                    std::cout << " ";
                }
                for (int j = 1; j <= 2 * i - 1; ++j) {
                    std::cout << "*";
                }
                for (int j = 1; j <= n - i; ++j) {
                    std::cout << " ";
                }

            }
            std::cout << std::endl;
        }
    }
    else return 0;
 }
