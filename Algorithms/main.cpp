#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <iostream>
//#include <chrono>

//using namespace std;
//using namespace chrono;
//typedef std::chrono::high_resolution_clock Clock;

#define SIZE 100
#define N 13

void init_arr(int arr[],int n) {
	for (int i = 0; i < n; i++) 
		arr[i] = rand()%20;
}

void print_arr(int arr[], int n) {
	for (int i = 0; i < n; i++)
		printf("%d ", arr[i]);
	printf("\n");
}

void swap_ij(int a[],int i, int j) {
	int t = a[i];
	a[i] = a[j];
	a[j] = t;
}

void bub_sort(int arr[], int n) {
	int f = 1;
	while (f == 1) {
		f = 0;
		for (int i = 0; i < n - 1; i++) {
			if (arr[i] > arr[i + 1]) {
				swap_ij(arr, i, i++);
				f = 1;
			}
		}
	}
}

int find_min(int arr[], int n, int pos) {
	int a = arr[pos];
	int ind = pos;
	for (int i = pos + 1; i < n; i++) {
		if (arr[i] < a) {
			a = arr[i];
			ind = i;
		}
	}
	return ind;
}

void vibork_sort(int arr[], int n) {
	for (int i = 0; i < n; i++)
		swap_ij(arr, i, find_min(arr, n, i));
}

void vstav_sort(int arr[], int n) {
	for (int i = 1; i < n; i++) {
		int copy = arr[i];
		int j = i-1;
		while ((copy<arr[j]) && (j >-1)){
			arr[j+1] = arr[j];
			j--;
		}
		arr[j+1] = copy;
	}
}

void podschet_sort(int arr[], int n) {
	int mi = arr[0], ma = arr[0];
	for (int i = 1; i < n; i++) {
		if (arr[i] < mi) mi = arr[i];
		if (arr[i] > ma) ma = arr[i];
	}
	int b[SIZE]{};
	for (int i = 0; i < n; i++) {
		b[arr[i] - mi]++;
	}
	int k = 0;
	for (int i = 0; i < ma - mi; i++) {
		for (int j = 0; j < b[i]; j++) {
			arr[k] = i + mi;
			k++;
		}
	}
}

void rec_print(int a[], int i, int n) {
	printf("%d ", a[i]);
	if (i != n - 1)
		rec_print(a, i + 1, n);
}

int part(int a[], int first, int last) {
	int i = first, j = last;
	int x = a[(first + last) / 2];
	while (i <= j)
	{
		while (a[i] < x) i++;
		while (a[j] > x) j--;
		if (i >= j) break;
		swap_ij(a, i++, j--);
	}
	return j;
}

void hoar_sort(int a[], int first, int last) {
	if (first < last) {
		int q = part(a, first, last);
		hoar_sort(a, first, q);
		hoar_sort(a, q + 1, last);
	}
}

void h_sort(int a[], int l, int r) {
	int to_sort[SIZE][2]; int q;
	int k = -1;
	k++; to_sort[k][0] = l; to_sort[k][1] = r;
	while (k > -1) {
		l = to_sort[k][0]; r = to_sort[k][1]; k--;
		q = part(a, l, r);
		if (q > l) {
			k++; to_sort[k][0] = l; to_sort[k][1] = q;
		}
		if (q + 1 < r) {
			k++; to_sort[k][0] = q + 1; to_sort[k][1] = r;
		}
	}
}

void merge(int a[], int n, int b[], int m, int f[]) {
	int i = 0, j = 0, k = 0;
	while (i < n && j < m)
	{
		if (a[i] < b[j]) {
			f[k] = a[i];
			i++; k++;
		}
		else if (a[i] > b[j]) {
			f[k] = b[j];
			j++; k++;
		}
		else {
			f[k] = f[k + 1] = a[i];
			i++; j++; k += 2;
		}
	}
	for (; i < n; i++) {
		f[k] = a[i];
		k++;
	}
	for (; j < m; j++) {
		f[k] = b[j];
		k++;
	}
}

void down(int a[], int n, int b[], int m, int t[], int f[]) {
	if (m == 0 || n == 0) merge(a, n, b, m, f);
	else {
		down(a, n / 2, a + n / 2, n - (n / 2), t + 2 * n, t);
		down(b, m / 2, b + m / 2, m - (m / 2), t + 3 * n, t + n);

		merge(t, n, t + n, m, f);
	}
}

void r_sort(int a[], int n, int base) {
	int* start = (int*)malloc(sizeof(int) * base);
	int* end = (int*)malloc(sizeof(int) * base);
	int* ind = (int*)malloc(sizeof(int) * n);
	int* buff = (int*)malloc(sizeof(int) * n);
	int raz = 0, m = 0, rd = 1, r, k, st, ed, max_el = a[0];
	unsigned char* uc_ptr = (unsigned char*)a;

	for (int i = 0; i < n; i++) {
		if (abs(a[i]) > max_el) max_el = abs(a[i]);
	}

	for (int raz = 0; rd < max_el; raz++) {
		memset(start, -1, sizeof(int) * base);
		memset(end, -1, sizeof(int) * base);
		//printf("\n"); for (int i = 0; i < n; i++) printf("%8.1d", a[i]); printf("\n");

		for (int i = 0; i < n; i++) {
			r = (a[i] < 0 ? a[i] + max_el : a[i]) / rd % base;
			//r = uc_ptr[i * 4 + raz];
			//printf("%8.1d", r);
			ind[i] = i;
			if (start[r] != -1) {
				ind[end[r]] = i;
				ind[i] = start[r];
			}
			else start[r] = i;
			end[r] = i;
		}

		k = 0;
		for (int i = 0; i < base; i++) {
			if (start[i] != -1) {
				st = start[i], ed = end[i];
				buff[k] = a[st]; k++;
				while (st != ed) {
					st = ind[st];
					buff[k] = a[st]; k++;
				}
			}
		}
		//printf("\n"); for (int i = 0; i < n; i++) printf("%8.1d", buff[i]); printf("\n");

		k = 0;
		for (int i = 0; i < n; i++) {
			if (buff[i] < 0) {
				a[k] = buff[i];
				k++;
			}
		}
		for (int i = 0; i < n; i++) {
			if (buff[i] >= 0) {
				a[k] = buff[i];
				k++;
			}
			if (k == n) break;
		}

		//for (int i = 0; i < n; i++) printf("%8.1d", a[i]); printf("\n");
		rd *= base;
	}

	free(start); free(end); free(ind); free(buff);
}

int main() {
	int n;
	int a[SIZE]; int t[SIZE];
	n = 10;
	srand(time(NULL));

	//int b[N]; init_arr(b, N);
	//int c[SIZE];
	//print_arr(b, N);

	init_arr(a, n); print_arr(a, n);

	//vibork_sort(a, n);
	//bub_sort(a, n);
	//vstav_sort(a, n);
	//podschet_sort(a, n);
	//rec_print(a, 0, n);
	print_arr(a, n);


	//down(b, N/2, b + N/2, N - N/2,t, c);
	//print_arr(c, N);

	//int s[SIZE] = { 1,2,3,0,3,5 };
	//print_arr(s, 6);
	return 0;
}