//#include<stdio.h>
//
//const int max_len = 128;  // ������������ ����� �����
//const int max_words = 128;  // ������������ ����� �������
//
//int length(char* word)
//{
//// ����������� ����� �����
//    int len = 0;
//    while (word[len] != 0) len++;
//    return len;
//}
//
//void AddWord(int i, char** slovar, char* word)
//{
//    int len = length(word);
//    // ���������� ����� � �������
//    slovar[i] = new char[len + 1];
//    for (int j = 0; j <= len; j++) 
//        slovar[i][j] = word[j];
//}
//
//void copy(char buf[], char* word)
//{
//    // ����������� ������ � ������
//    int i = 0;
//    while (word[i] != 0) 
//    { 
//        buf[i] = word[i]; 
//        i++; 
//    }
//    buf[i] = 0;        // ���������� � ����� ������ ������� 0
//}
//
//void concat(char buf[], char* word)
//{
//    // ��������� ���� �����
//    int len = length(buf);
//    copy(buf + len, word);
//}
//
//bool equal(char* s1, char* s2)
//{
//    // ��������� ���� �����
//    int i = 0;
//    while (s1[i] != 0)
//    {
//        if (s1[i] != s2[i]) return false;        // ������ �������
//        i++;
//    }
//    if (s2[i] != 0)
//    return false;                // ������ ����������� ������ ������
//    else return true;                // ������ ���������
//
//}
//
//bool test_equal(char* si, char* sj, char* sk)
//{
//    // �������� ����������� ����������� ����� ������ �� ���� ������
//    if (length(si) == length(sj) + length(sk)) // �������� ����� �����
//    {
//        char buf[max_len * 2];        // ����� ��� ������� ���� �����
//        copy(buf, sj);
//        concat(buf, sk);                // �������� ������ � ��������� ������
//        if (equal(si, buf))                // �������� ����������
//        {
//            // ������ ����������
//            printf("%s = %s + %s\n", si, sj, sk);
//            return true;
//        }
//        return false; // �� ������� �� ������
//    }
//    else
//        return false; // �� ������� �� �����
//}
//
//bool test_words(char** slovar, int n_words)
//    {
//    // �������� ���� ���������� ���� �� �������
//    bool found = false;
//    for (int i = 0; i < n_words; i++)        // ���� �� ������� �����
//    {
//        for (int j = 0; j < n_words; j++) // ���� �� ������� �����
//        {
//            if (j == i) continue; // �� ���������� ���� � �����
//            for (int k = j + 1; k < n_words; k++) // ���� �� �������� �����
//            {
//                // �� ���������� ���� � �����
//                if (k == i) continue;
//                // ����������: ������ = ������ + ������
//                found |= test_equal(slovar[i], slovar[j], slovar[k]);
//                // ����������: ������ = ������ + ������
//                found |= test_equal(slovar[i], slovar[k], slovar[j]);
//            }
//        }
//    }
//    return found; // ���������� ��������� ���������
//}
//
//void free_mem(char** slovar, int n_words)
//{
//// �������� ������� �� ������
//    for (int i = 0; i < n_words; i++)
//    delete[] slovar[i];
//    delete slovar;
//}
//
//int main()
//{
//    int n_words;                // ���������� ���� � �������
//    char word[max_len];  // ����� ��� ����� �����
//    char** slovar = new char* [max_words];        // �������
//    printf("n_words=");                // ���� ���������� ����
//    scanf("%d", &n_words);
//    // �������� �������
//    for (int i = 0; i < n_words; i++)
//    {
//        scanf("%s", word);                // ���� �����
//        AddWord(i, slovar, word);        // ���������� � �������
//    }
//    // ���� ��������
//    bool ok = test_words(slovar, n_words);        // ���� ���� ����� - ��������
//    if (!ok)
//        printf("No Words Found!\n");        // ����� ���� �� ����
//    // ������������ ������
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