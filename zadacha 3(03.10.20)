#include <iostream>
#include <fstream>
#include <stdlib.h>
#include <conio.h>
const int name = 20;
const int str = 1000;
int main(){
std::ifstream fin;
std::ofstream fout;
char fname[name];
char line[str];
std::cout << "\n Enter the name of the input file: ";
std::cin >> fname;
fin.open(fname);
if(!fin){
    std::cerr << "File doesn't open!" << fname;
    exit(1);
}
std::cout << "\nEnter the name of the output file: ";
std::cin >> fname;
fin.open(fname);
if(!fin){
    std::cerr << "File doesn't open!" << fname;
    exit(1);
}
int i = 0;
std::cin.get();
while(!fin.eof()){
    fin.getline(line, str);
    i++;
    fout << line;
}
fin.close();
fout.close();
    }
