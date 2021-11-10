#include <stdio.h>
#include <cstdlib>
#include <ctime>
#define R 10

int in(int elem, int arr[], int size) {
	for (int i = 0; i < size; i++)
		if (arr[i] == elem)
			return 1;
	return 0;
}

int* add(int arr[], int* size, int num) {
	*size += 1;
	arr = (int*)realloc(arr, *size * sizeof(int));
	arr[*size - 1] = num;
	return arr;
}

int* to_set(int arr[], int* size) {
	int* c = nullptr;
	int c_size = 0;
	for (int i = 0; i < *size; i++)
		if (!in(arr[i], c, c_size))
			c = add(c, &c_size, arr[i]);
	*size = c_size;
	return c;
}

int* init_arr(int size) {
	int* arr = (int*)malloc(size * sizeof(int));
	for (int i = 0; i < size; i++) *(arr + i) = rand() % R;
	return arr;
}
void out(int arr[], int size) {
	printf("\n---\n");
	for (int i = 0; i < size; i++) printf("%d ", arr[i]);
}

int main() {
	srand(static_cast<unsigned int>(time(0)));
	int* unioN = nullptr;
	int* inter = nullptr;
	int u_size = 0, i_size = 0;

	int a_size, b_size;
	scanf("%d %d", &a_size, &b_size);

	int* a = init_arr(a_size);
	int* b = init_arr(b_size);

	for (int i = 0; i < a_size; i++) unioN = add(unioN, &u_size, a[i]);

	for (int i = 0; i < b_size; i++) {
		if (in(b[i], a, a_size)) inter = add(inter, &i_size, b[i]);
		unioN = add(unioN, &u_size, b[i]);
	}
	inter = to_set(inter, &i_size);
	unioN = to_set(unioN, &u_size);

	out(a, a_size); out(b, b_size);
	out(inter, i_size); out(unioN, u_size);

	return 0;
}