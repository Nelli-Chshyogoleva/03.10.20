#include <iostream>
// R = rows = строки
// С = columns = столбцы
// T = top = верх
// B = bottom = низ
// RT = right = право
// LT = left = лево
// a = координата
// b = координата
int main()
{
    const int R = 6, C = 7;
    int N[R][C];
    int k = 1, a = 0, b = 0, LT = 0, RT = C - 1, T = 1, B = R - 1;
    do {
        do {
            N[b][a] = k;
            ++k;
            ++a;
        } while (a < RT);
        --RT;
        if (k <= R * C) {
            do {
                N[b][a] = k;
                ++k;
                ++b;
            } while (b < B);
            --B;
        }
        if (k <= R * C) {
            do {
                N[b][a] = k;
                ++k;
                --a;
            } while (a > LT);
            ++LT;
        }
        if (k <= R * C) {
            do {
                N[b][a] = k;
                ++k;
                --b;
            } while (b > T);
            ++T;
        }

    } while (k <= R * C);
    for (int i = 0; i < R; ++i) {
        for (int j = 0; j < C; ++j) {
            std::cout << N[i][j] << ' ';
        }
        std::cout << "\n";
    }
}
