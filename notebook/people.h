#ifndef __MY_NOTEBOOK__
#define __MY_NOTEBOOK__
#include <iostream>

struct people {
    char surname[32];
    char name[16];
    char phone[16];
    char email[32];
    char birthday[10];
};

struct DataBase {
    int count;
    people* data;
};
std::ostream& operator << (std::ostream& out, const people& st);
std::istream& operator >> (std::istream& in, people& st);

bool operator < (const people& left, const people& right);
bool SB(const people& left, const people& right);
bool SS(const people& left, const people& right);
bool SDB(const people& left, const people& right);

int addNote(DataBase& DB);               //добавление записи
void deleteNote(DataBase& DB);           //удаление записи
void saveDB(const DataBase& DB);         //сохрарнение записной книжки
void exportDB(const DataBase& DB);       //экспорт
void sortSN(DataBase& DB);               //сортировка по фамилии
void sortB(DataBase& DB);                //сортировка по дате рождения
void sortDB(DataBase& DB);               //сортировка по дням до дня рождения
int searchSN(const DataBase& DB);        //поиск по фамилии
int searchPN(const DataBase& DB);        //поиск по номеру телефона


template <typename T>
void MySort(T* M, int n, bool (*comparator)(const T&, const T&)) {
    for (int j = 0; j < n - 1; ++j) {
        int k = j; 
        for (int i = k + 1; i < n; ++i) {
            if (comparator(M[i], M[k]))  
                k = i;
        }
        if (j < k) {
            std::swap(M[k], M[j]);
        }
    }
}
#endif
