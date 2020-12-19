#include <iostream>
#include <fstream>

unsigned char Base64Char(unsigned char b) {
    if (b >= 'A' && b <= 'Z') {
        return b - 'A';
    }
    if (b >= 'a' && b <= 'z') {
        return b - 'a' + 26;
    }
    if (b >= '0' && b <= '9') {
        return b - '0' + 52;
    }
    if (b == '+') {
        return 62;
    }
    if (b == '/') {
        return 63;
    }
    return 64;
}
char C(unsigned char b) {
    int c = (int)b;
    return c;
}

int Base64Decode(char* inStr, int Len, char* outStr) {
    unsigned char a1, a2, a3;
    unsigned char b1, b2, b3, b4;  
    int x = 0, y = 0;

    for (int i = 0; i < Len; i += 4) {
        b1 = Base64Char(inStr[i]);
        b2 = Base64Char(inStr[i + 1]);
        b3 = Base64Char(inStr[i + 2]);
        b4 = Base64Char(inStr[i + 3]);

        if (b3 == 64) {
            b3 = 0; b4 = 0; y = 2;
        }
        if (b4 == 64) {
            b4 = 0; y = 1;
        }
        a1 = (b1 << 2) | (b2 >> 4);
        a2 = (b2 << 4) | (b3 >> 2);
        a3 = (b3 << 6) |  b4;

        outStr[x++] = a1;
        outStr[x++] = a2;
        outStr[x++] = a3;
    }
    return x - y;
}

int main()
{
    char iFname[256];
    char oFname[256];
    std::cout << "Input source file name: ";
    std::cin.getline(iFname, 256);

    std::ifstream inFile(iFname);
    if (!inFile) {
        std::cout << "Can not open file " << iFname << std::endl;
        return 1;
    }
    std::cout << "Input destination file name: ";
    std::cin.getline(oFname, 256);

    std::ofstream outFile(oFname, std::ios_base::binary);
    if (!outFile) {
        inFile.close();
        std::cout << "Can not write to file " << oFname << std::endl;
        return 2;
    }
    const int block_size = 19;
    char inStr[4 * block_size], outStr[3 * block_size];
    int s;
    while (inFile.peek() != EOF) {
        s = 0;
        for (int i = 0; i < 4 * block_size && inFile.peek() != EOF; ++i) {
            char j;
            j = inFile.get();
            if (j >= 'A' && j <= 'Z' || j >= 'a' && j <= 'z' || j >= '0' && j <= '9' || j == '+' || j == '/' || j == '=') {
                inStr[i] = j;
                ++s;
            }
        }
        s = Base64Decode(inStr, s, outStr);
        outFile.write(outStr, s);
    }
    inFile.close();
    outFile.close();
    std::cout << "Decoder completed operation" << std::endl;
}
