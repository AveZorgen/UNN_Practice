//#include<stdio.h>
//
//const int max_len = 128;  // Максимальная длина слова
//const int max_words = 128;  // Максимальная длина словаря
//
//int length(char* word)
//{
//// Определение длины слова
//    int len = 0;
//    while (word[len] != 0) len++;
//    return len;
//}
//
//void AddWord(int i, char** slovar, char* word)
//{
//    int len = length(word);
//    // Добавление слова в словарь
//    slovar[i] = new char[len + 1];
//    for (int j = 0; j <= len; j++) 
//        slovar[i][j] = word[j];
//}
//
//void copy(char buf[], char* word)
//{
//    // Копирование строки в другую
//    int i = 0;
//    while (word[i] != 0) 
//    { 
//        buf[i] = word[i]; 
//        i++; 
//    }
//    buf[i] = 0;        // Добавление в конец строки символа 0
//}
//
//void concat(char buf[], char* word)
//{
//    // Сцепление двух строк
//    int len = length(buf);
//    copy(buf + len, word);
//}
//
//bool equal(char* s1, char* s2)
//{
//    // Сравнение двух строк
//    int i = 0;
//    while (s1[i] != 0)
//    {
//        if (s1[i] != s2[i]) return false;        // Разные символы
//        i++;
//    }
//    if (s2[i] != 0)
//    return false;                // Строка закончилась раньше другой
//    else return true;                // Строки совпадают
//
//}
//
//bool test_equal(char* si, char* sj, char* sk)
//{
//    // Проверка возможности составления одной строки из двух других
//    if (length(si) == length(sj) + length(sk)) // Проверка длины строк
//    {
//        char buf[max_len * 2];        // Буфер для слияния двух строк
//        copy(buf, sj);
//        concat(buf, sk);                // Копируем первую и добавляем вторую
//        if (equal(si, buf))                // Проверка совпадения
//        {
//            // Печеть результата
//            printf("%s = %s + %s\n", si, sj, sk);
//            return true;
//        }
//        return false; // Не совпали по буквам
//    }
//    else
//        return false; // Не совпали по длине
//}
//
//bool test_words(char** slovar, int n_words)
//    {
//    // Проверка всех комбинаций слов из словаря
//    bool found = false;
//    for (int i = 0; i < n_words; i++)        // Цикл по первому слову
//    {
//        for (int j = 0; j < n_words; j++) // Цикл по второму слову
//        {
//            if (j == i) continue; // Не сравнивать само с собой
//            for (int k = j + 1; k < n_words; k++) // Цикл по третьему слову
//            {
//                // Не сравнивать само с собой
//                if (k == i) continue;
//                // Сравниваем: первое = второе + третье
//                found |= test_equal(slovar[i], slovar[j], slovar[k]);
//                // Сравниваем: первое = третье + второе
//                found |= test_equal(slovar[i], slovar[k], slovar[j]);
//            }
//        }
//    }
//    return found; // Возвращаем результат сравнения
//}
//
//void free_mem(char** slovar, int n_words)
//{
//// Удаление словаря из памяти
//    for (int i = 0; i < n_words; i++)
//    delete[] slovar[i];
//    delete slovar;
//}
//
//int main()
//{
//    int n_words;                // Количество слов в словаре
//    char word[max_len];  // Буфер для ввода слова
//    char** slovar = new char* [max_words];        // Словарь
//    printf("n_words=");                // Ввод количества слов
//    scanf("%d", &n_words);
//    // Создание словаря
//    for (int i = 0; i < n_words; i++)
//    {
//        scanf("%s", word);                // Ввод слова
//        AddWord(i, slovar, word);        // Добавление в словарь
//    }
//    // Сама проверка
//    bool ok = test_words(slovar, n_words);        // Если есть слова - печатаем
//    if (!ok)
//        printf("No Words Found!\n");        // Таких слов не было
//    // Освобождение памяти
//    free_mem(slovar, n_words);
//    return 0;
//}

#include<stdio.h>

#define MAXWORD 10
#define MAXDICT 15

int length(char* word);
void addWord(int i, char** slovar, char* word);
int compare(char** slovar, int i, int j);
void printWord(char** slovar, int i, int len);

int main() {
    int n_words;
	char word[MAXWORD];
    char** slovar = new char* [MAXDICT];  
    int l1;
	scanf_s("%d", &n_words);

	for (int i = 0; i< n_words; i++) {
		scanf_s("%s", word, MAXWORD);
        addWord(i, slovar, word);
	}
    for (int i = 0; i < n_words; i++) {
        for (int j = i+1; j < n_words; j++) {
            l1 = compare(slovar, i, j);
            if (l1) printWord(slovar, i, l1); 
        }
    }
}

void printWord(char** slovar, int i, int len) {
    for (int j = 0; j < len; j++)
        printf("%c", slovar[i][j]);
    printf("\n");
}

int compare(char** slovar, int i, int j) {
    int l1 = length(slovar[i]);
    if (l1 != length(slovar[j])) return 0;
    for (int s = 0; s < l1; s++)
        if (slovar[i][s] != slovar[j][l1 - 1 - s])
            return 0;
    return l1;
}

int length(char* word)
{
    int len = 0;
    while (word[len] != 0) len++;
    return len;
}

void addWord(int i, char** slovar, char* word)
{
    int len = length(word);
    slovar[i] = new char[len + 1];
    for (int j = 0; j <= len; j++) 
        slovar[i][j] = word[j];
}