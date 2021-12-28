#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>
#include <iostream>

#include <string>
#include <chrono>

using namespace std;
using namespace chrono;
typedef std::chrono::high_resolution_clock Clock;

void init_arr(int arr[],int n) {
	for (int i = 0; i < n; i++) {
		arr[i] = rand() % 10;
	}
}

void print_arr(int arr[], int n) {
	for (int i = 0; i < n; i++)
		printf("%d ", arr[i]);
	printf("\n");
}

void vstav_sort_2elem(int a[],int b[], int n) {
	for (int i = 1; i < n; i++) {
		int copy = a[i];
		int copyb = b[i];
		int j = i - 1;
		while (j > -1 && (copy < a[j] || copy == a[j] && copyb > b[j])) {
			a[j + 1] = a[j];
			b[j + 1] = b[j];
			j--;
		}
		a[j + 1] = copy;
		b[j + 1] = copyb;
	}
}

int str2int(char* s) {
	int ans = 0;
	for (int i = 0; s[i] != '\n'; i++) {
		ans *= 10;
		ans += s[i] - '0';
	}
	return ans;
}

void int2str(int n, char* s) {
	int i = 0;
	int t = n;
	while (t > 0) {
		t /= 10; i++;
	}
	for (int k = 0; k < i; k++) {
		s[i-k-1]= n % 10 + '0';
		n /= 10;
	}
	s[i] = '\0';
}

int counter(char* str, int n) {
	int c = 0;
	while (str[c] != 0) c++;
	return c-1;
}

bool isdigit(char* s) {
	for (int i = 0; s[i] != '\0'; i++) if (s[i]-'0' > 9) return false; return true;
}

int main() {
	srand(time(NULL));
	int n = 15;
	int* a = new int[n];
	//int* b = new int[100]{};
	
	//init_arr(a, n);
	//print_arr(a, n);
	//print_arr(a, n);
	//Clock timer;
	

	
	
	

	return 0;
}