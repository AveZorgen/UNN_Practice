#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define SIZE 100

void init_arr(int arr[],int n) {
	for (int i = 0; i < n; i++) 
		arr[i] = rand()%10;
}
void print_arr(int arr[], int n) {
	for (int i = 0; i < n; i++)
		printf("%d ", arr[i]);
	printf("\n");
}

void bub_sort(int arr[], int n) {
	int f = 1;
	while (f == 1) {
		f = 0;
		for (int i = 0; i < n - 1; i++) {
			if (arr[i] > arr[i + 1]) {
				int k = arr[i];
				arr[i] = arr[i + 1];
				arr[i + 1] = k;
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

void sravn_sort(int arr[], int n) {
	int min_ind; int temp;
	for (int i = 0; i < n; i++){
		min_ind = find_min(arr, n, i);
		temp = arr[i];
		arr[i] = arr[min_ind];
		arr[min_ind] = temp;
	}
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



int main() {
	int n;
	int s[SIZE];
	n = 10;
	srand(time(NULL));
	init_arr(s, n);
	print_arr(s, n);

	//sravn_sort(s, n);
	//bub_sort(s, n);
	//vstav_sort(s, n);
	podschet_sort(s, n);
	print_arr(s, n);


	return 0;
}