// ==============================================================
// npp-fio-vari-fin-29-20.cpp
// Выбор варианта для зачёта.
// Комиссарова Яна                           2021-дек-11 Сб 13:11
// ==============================================================

#include <iostream>
#include <iomanip>
#include <fstream>
#include <vector>
#include <algorithm>

#include <string>
#include <random>

const size_t num_task{ 20 };
std::string spisok{ "spisok_.txt" };

// ==============================================================
int main()
{
    using namespace std;

    system("chcp 1251 > nul");

    ifstream fin(spisok);
    if (!fin) {
        cerr << "??? ОШИБКА - Где файл со списком группы... \n";
        return -1;
    }

    // заполнение fio из файла spisok и вычисление длины namespace

    vector<string> fio;
    string name;
    size_t name_size9{};


    while (getline(fin, name)) {
        fio.push_back(name);
        if (name.size() > name_size9)
            name_size9 = name.size();
    }
    fin.close();

    // Печать шапки

    string kepka{ " № |   фамилия имя    | вариант\n" },
        line{ string(kepka.size() - 1, '-') + '\n' };
    cout << line
        << kepka
        << line;

    // Вычисление номеров вариантов

    size_t fio_sz{ fio.size() };
    vector<int> vari(fio_sz);

    for (size_t i{}; i < fio_sz; ++i) {
        vari[i] = i % num_task + 1;
    }

    shuffle(vari.begin(),
        vari.end(), 
        default_random_engine(27182));

    // печать красивой таблицы

    size_t npp{};

    for (auto e : fio) {
        cout << setw(2) << npp << " | "
            << setw(name_size9) << left
            << setfill('-') << e << " | "
            << setw(3) << right
            << setfill(' ') << vari[npp] << endl;
        ++npp;
    }
    cout << line;

    return 0;
}