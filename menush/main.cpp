#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <string.h>
#include <locale.h>
#include <windows.h>

int linear_search(char** dst, char* source, int size) {
    int index = -1;
    int i = 0;

    while (index == -1 && i < size) {

        if (strcmp(dst[i], source) == 0) {
            index = i;
        }

        i++;
    }

    return index;
}

int spisok_bez_povtoreniy(char** name, int n, char*** list) {
    int k = 0;

    for (int i = 0; i < n; i++) {

        int l = -1;
        int j = 0;
        while (l == -1 && j < k)
        {
            if (strcmp(name[i], (*list)[j]) == 0)
            {
                l = j;
            }
            j++;
        }
        if (l == -1)
        {
            (*list)[k] = (char*)calloc(strlen(name[i]) + 2, sizeof(char));
            strcpy((*list)[k], name[i]);
            k++;
        }
    }
    return k;
}

int spisok_bez_povtoreniy_rate(char** name, int n, char*** list, int** rate) {
    int k = 0;

    for (int i = 0; i < n; i++) {

        int l = -1;
        int j = 0;
        while (l == -1 && j < k)
        {
            if (strcmp(name[i], (*list)[j]) == 0)
            {
                l = j;
            }
            j++;
        }
        if (l == -1)
        {
            (*list)[k] = (char*)calloc(strlen(name[i]) + 2, sizeof(char));
            strcpy((*list)[k], name[i]);
            (*rate)[k] = 1;
            k++;
        }
        else {
            (*rate)[l] += 1;
        }
    }
    return k;
}

int spisok_bez_povtoreniy_sum(char** name, int n, int* ch, char*** list, int** sum) {
    int k = 0;

    for (int i = 0; i < n; i++) {

        int l = -1;
        int j = 0;
        while (l == -1 && j < k)
        {
            if (strcmp(name[i], (*list)[j]) == 0)
            {
                l = j;
            }
            j++;
        }
        if (l == -1)
        {
            (*list)[k] = (char*)calloc(strlen(name[i]) + 2, sizeof(char));
            strcpy((*list)[k], name[i]);
            (*sum)[k] = ch[i];
            k++;
        }
        else {
            (*sum)[l] += ch[i];
        }
    }
    return k;
}

int string_split(char* str, const char* razd, char*** res) {

    strcat(str, " ");
    int k = 0;
    while (strlen(str) > 0) {
        int l = strcspn(str, razd);
        if (l > 0) {
            (*res)[k] = (char*)calloc(l + 2, sizeof(char));
            strncpy((*res)[k], str, l);
            k++;
        }
        int len = strlen(str);
        for (int i = 0; i < len - l + 1; i++) {
            str[i] = str[l + i + 1];
        }
    }
    return k;
}

void One() {
    int n, x;
    int i;
    int* A;
    int sum;
    sum = 0;
    setlocale(LC_ALL, "rus");
    printf("Введите количество чисел: ");
    scanf_s("%d", &n);
    A = (int*)calloc(n, sizeof(int));
    printf("Введите числа: ");
    for (i = 0; i < n; i++) {
        scanf_s("%d", &x);
        sum += x;
    }
    printf("Сумма чисел равна: %d", sum);
    _getch();
}

void Two() {
    int* A;
    int N;
    int l;
    int i;
    int min;
    setlocale(LC_ALL, "rus");
    printf("Введите кол-во чисел > ");
    scanf_s("%d", &N);
    A = (int*)calloc(4 * N, sizeof(int));
    printf("Введите число ");
    for (i = 0; i < N; i++) {
        scanf_s("%d", &A[i]);
    }
    min = A[0];
    l = 0;
    for (i = 0; i < N; i++) {
        if (A[i] < min) {
            min = A[i];
            l = i;

        }
    }
    printf("Минимальное число = %d \nЕго помер в массиве %d \n", min, l);
    _getch();
}

void Three() {
    int N;
    int k;
    int i;
    int len;
    char** name;
    char** best;
    //char* tmp;
    char tmp[255];

    rsize_t l;

    setlocale(LC_ALL, "Rus");

    printf_s("Введите кол-во N: ");
    scanf_s("%d", &N);

    name = (char**)calloc(4 * N, sizeof(char*));
    best = (char**)calloc(4 * N, sizeof(char*));
    //tmp = (char*)calloc(255, sizeof(char));

    printf("Введи список\n");

    for (i = 0; i < N; i++) {
        //scanf_s("\n%s", tmp);
        scanf_s("\n");
        fgets(tmp, 255, stdin);
        len = strlen(tmp) + 2;
        l = sizeof(rsize_t);
        name[i] = (char*)calloc(l * len, sizeof(char));
        strcpy_s(name[i], l * len, tmp);
    }

    k = 0;

    for (i = 0; i < N; i++) {
        if (name[i][0] == 'A') {
            len = strlen(name[i]) + 2;
            l = sizeof(rsize_t);
            best[k] = (char*)calloc(l * len, sizeof(char));
            strcpy_s(best[k], l * len, name[i]);
            k += 1;
        }
    }

    printf_s("Список хороших:\n");

    for (i = 0; i < k; i++) {
        printf_s("%s", best[i]);
    }
    _getch();
}

void Four() {
    int N, i, len;
    char** name;
    char* ctrl;
    char tmp[255];

    char** sorted_name;

    rsize_t l;

    setlocale(LC_ALL, "Rus");

    printf_s("Введите кол-во N: ");
    scanf_s("%d", &N);

    name = (char**)calloc(4 * N, sizeof(char*));

    printf("Введи список\n");

    for (i = 0; i < N; i++) {

        scanf_s("\n");
        fgets(tmp, 255, stdin);
        len = strlen(tmp) + 2;
        l = sizeof(rsize_t);
        name[i] = (char*)calloc(l * len, sizeof(char));

        strcpy_s(name[i], l * len, tmp);
    }

    printf("Введите искомое слово\n");
    scanf_s("\n");
    fgets(tmp, 255, stdin);

    len = strlen(tmp) + 2;
    l = sizeof(rsize_t);
    ctrl = (char*)calloc(l * len, sizeof(char));

    strcpy_s(ctrl, l * len, tmp);

    printf("Линейный поиск: %d\n", linear_search(name, ctrl, N));
    _getch();
}

void Five() {
    int N, i, len, start, finish, index, o;
    char** name;
    char* ctrl;
    char tmp[255];
    char** dst;
    char* source;

    rsize_t l;

    setlocale(LC_ALL, "rus");
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);
    start = 0;
    index = -1;
    printf_s("Введите кол-во N: ");
    scanf_s("%d", &N);

    name = (char**)calloc(N, sizeof(char*));

    printf("Введи список\n");

    for (i = 0; i < N; i++) {

        scanf_s("\n");
        fgets(tmp, 255, stdin);
        len = strlen(tmp) + 2;
        l = sizeof(rsize_t);
        name[i] = (char*)calloc(len, sizeof(char));

        strcpy_s(name[i], l * len, tmp);
    }

    printf("Введите искомое слово\n");
    scanf_s("\n");
    fgets(tmp, 255, stdin);

    len = strlen(tmp) + 2;
    l = sizeof(rsize_t);
    ctrl = (char*)calloc(len, sizeof(char));

    strcpy_s(ctrl, len, tmp);
    finish = N - 1;
    o = 0;
    dst = name;
    source = ctrl;


    while (start <= finish)
    {
        int middle = (start + finish) / 2;

        int str_cmp_data = strcmp(source, dst[middle]);

        if (str_cmp_data == 0) {
            index = middle;
            break;
        }
        if (str_cmp_data < 0)
            finish = middle - 1;
        else
            start = middle + 1;
    }
    printf("Бинарный поиск %d\n", index);
    _getch();
}

void Six() {
    char tmp[255];
    char** name;
    char** list;
    int N;

    setlocale(LC_ALL, "rus");
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);


    printf("Введите количество элементов: \n");
    scanf("%d", &N);

    name = (char**)calloc(N, sizeof(char*));
    list = (char**)calloc(N, sizeof(char*));
    printf("Введите список: \n");
    for (int i = 0; i < N; i++) {
        scanf("%s", &tmp);
        int len = strlen(tmp);
        name[i] = (char*)calloc(len + 2, sizeof(char));
        strcpy(name[i], tmp);
    }

    int k = spisok_bez_povtoreniy(name, N, &list);

    printf("Список без повторений: \n");
    for (int i = 0; i < k; i++) {
        printf("[%d] = %s\n", i, list[i]);
    }
    _getch();

}

void Seven() {
    char tmp[255];
    char** name;
    char** list;
    int* Rate;
    int N;

    setlocale(LC_ALL, "rus");
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);


    printf("Введите количество элементов: \n");
    scanf("%d", &N);

    name = (char**)calloc(N, sizeof(char*));
    list = (char**)calloc(N, sizeof(char*));
    Rate = (int*)calloc(N, sizeof(int));
    printf("Введите список: \n");
    for (int i = 0; i < N; i++) {
        scanf("%s", &tmp);
        int len = strlen(tmp);
        name[i] = (char*)calloc(len + 2, sizeof(char));
        strcpy(name[i], tmp);
    }

    int k = spisok_bez_povtoreniy_rate(name, N, &list, &Rate);

    printf("Список без повторений + подсчет рейтинга: \n");
    for (int i = 0; i < k; i++) {
        printf("[%d] = %s Его рейтинг -> %d\n", i, list[i], Rate[i]);
    }
    _getch();

}

void Eight() {
    char tmp[255];
    char** name;
    char** list;
    int* Sum;
    int* CH;
    int N;

    setlocale(LC_ALL, "rus");
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);

    printf("Введите количество элементов: \n");
    scanf("%d", &N);

    name = (char**)calloc(N, sizeof(char*));
    list = (char**)calloc(N, sizeof(char*));
    CH = (int*)calloc(N, sizeof(int));
    Sum = (int*)calloc(N, sizeof(int));

    printf("Введите название элемента и его характеристику: \n");
    for (int i = 0; i < N; i++) {
        scanf("%s %d", &tmp, &CH[i]);
        int len = strlen(tmp);
        name[i] = (char*)calloc(len + 2, sizeof(char));
        strcpy(name[i], tmp);
    }

    int k = spisok_bez_povtoreniy_sum(name, N, CH, &list, &Sum);

    printf("Список без повторений и подсчет рейтинга: \n");
    for (int i = 0; i < k; i++) {
        printf("[%d] = %s\n Характеристика %d\n", i, list[i], Sum[i]);
    }
    _getch();

}

void Nine() {
    setlocale(LC_ALL, "rus");
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);

    char data[100];
    char** result;

    printf("Введите строку: \n");
    fgets(data, 100, stdin);

    int len = strlen(data) + 2;

    result = (char**)calloc(len, sizeof(char*));

    int k = string_split(data, " ", &result);

    for (int i = 0; i < k; i++) {
        printf("[%d] %s\n", i, result[i]);
    }
    _getch();

}

void Ten() {
    char str[255];
    char* tmp;
    char* buff;
    char zn[] = " ,./?*-+&";
    char** W;
    char probel[2] = { ' ', '\0' };
    int k;
    int i;
    int l;
    int len;
    int tmp_len;
    setlocale(LC_ALL, "RUS");
    printf("Введи строку: \n");
    fgets(str, 255, stdin);
    len = strlen(str);
    W = (char**)calloc(len + 2, sizeof(char*));
    str[len - 1] = ' ';
    str[len] = '\0';
    k = 0;
    tmp = (char*)calloc(len + 2, sizeof(char));
    strcpy(tmp, "");
    for (i = 0; i < len; i++) {
        char symb[2] = { str[i], '\0' };
        l = strcspn(symb, zn);

        if (l > 0) {
            strcat(tmp, symb);
        }
        else {
            if (symb[0] == ' ')
            {
                tmp_len = strlen(tmp);
                if (tmp_len != 0)
                {
                    W[k] = (char*)calloc(tmp_len + 2, sizeof(char));
                    strcpy(W[k], tmp);
                    strcpy(tmp, "");
                    k++;
                }
            }
            else {
                tmp_len = strlen(tmp);
                if (tmp_len != 0) {
                    W[k] = (char*)calloc(tmp_len + 2, sizeof(char));
                    strcpy(W[k], tmp);
                    strcpy(tmp, "");
                    k++;
                }
                W[k] = (char*)calloc(2, sizeof(char));
                strcpy(W[k], symb);
                k++;
            }
        }
    }

    for (i = 0; i < k; i++)
    {
        printf("W[%d] = %s\n", i, W[i]);
    }
    _getch();
}

int menu(char** Name_punct, int Number) {
    int result = 0;
    int kod;
    system("cls");
    system("color 3F");
    HANDLE hStdOut = GetStdHandle(STD_OUTPUT_HANDLE);
    SetConsoleTextAttribute(hStdOut, FOREGROUND_INTENSITY);
    do {
        system("cls");
        for (int i = 0; i < Number; i++) {
            if (i == result) {
                system("color FF");
                //textcolor(4);
                //SetConsoleTextAttribute(4);

                SetConsoleTextAttribute(hStdOut, FOREGROUND_RED);

                // изменить цвет на инверсный
                printf("%s\n", Name_punct[i]);
                system("color FF");
                SetConsoleTextAttribute(hStdOut, FOREGROUND_INTENSITY);
            }
            else {
                printf("%s\n", Name_punct[i]);
            }
        }
        kod = _getch();
        if (kod == 0) {
            kod = _getch();
        }
        if (kod == 72) // нажата стрелка вверх
        {
            result--;
            if (result < 0) { result = Number - 1; }
        }
        if (kod == 80) // нажата стрелка вниз
        {
            result++;
            if (result == Number) { result = 0; }
        }
    } while (kod != 13);
    if (kod == 13) // enter
    {
        printf("\n........................\n");
        if (result == 0) {
            One();
        }
        if (result == 1) {
            Two();
        }
        if (result == 2) {
            Three();
        }
        if (result == 3) {
            Four();
        }
        if (result == 4) {
            Five();
        }
        if (result == 5) {
            Six();
        }
        if (result == 6) {
            Seven();
        }
        if (result == 7) {
            Eight();
        }
        if (result == 8) {
            Nine();
        }
        if (result == 9) {
            Ten();
        }
        if (result == 10) {
            exit(0);
        }
        printf("end alg\n");
    }


    //while (kod != 27) {
    //    kod = _getch();
    //}
    return result;

}

int main()
{
    setlocale(LC_ALL, "Rus");
    char** Np;
    int n = 11, m;


    Np = (char**)calloc(n, sizeof(char*));
    for (int i = 0; i < n; i++) {
        Np[i] = (char*)calloc(255, sizeof(char));
    }
    strcpy(Np[0], "1) Сумма n чисел");
    strcpy(Np[1], "2) Поиск минимального элемента массива с определением его места в массиве");
    strcpy(Np[2], "3) Отбор элемента массива  по заданному признаку с формированием нового массива");
    strcpy(Np[3], "4) Линейный поиск");
    strcpy(Np[4], "5) Бинарный поиск");
    strcpy(Np[5], "6) Список без повторений");
    strcpy(Np[6], "7) Список без повтоений с рейтингом ");
    strcpy(Np[7], "8) Список без повторений с характеристикой");
    strcpy(Np[8], "9) Деление строки на слова с помощью одного разделителя");
    strcpy(Np[9], "10) Деление строки на слова в случае разных разделителей");
    strcpy(Np[10], "[ВЫХОД]");
    do {
        m = menu(Np, n);
        printf("m = menu\n");
    } while (m != 1110);
}
