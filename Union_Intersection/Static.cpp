#include <stdio.h>
#include <stdlib.h>
#define MAX_SIZE 100

void out_arr(int a[], int n) {
    for (int i = 0; i < n; i++)
        printf("%d ", a[i]);
    printf("\n");
}

void add_el_to_arr(int a[], int& n, int el) {
    a[n] = el; n++;
}

void init_arr(int a[], int size) {
    for (int i = 0; i < size; i++)
        scanf("%d", a + i);
}

void calc_c(int c[], int down, int arr[], int size, int mod) {
    for (int i = 0; i < size; i++)
        c[arr[i] - down] += mod;
}


int main()
{
    int a[MAX_SIZE]; int b[MAX_SIZE];
    int inter[MAX_SIZE]; int unioN[MAX_SIZE];
    int c[MAX_SIZE]{};
    int a_size, b_size;
    int i_size = 0, u_size = 0;
    int down = -10, up = 10;
    int k = up - down + 1;

    scanf("%d %d", &a_size, &b_size);
    init_arr(a, a_size); init_arr(b, b_size);
    calc_c(c, down, a, a_size, 2);
    calc_c(c, down, b, b_size, -1);

    for (int i = 0; i < k; i++) {
        if (c[i] != 0) {
            add_el_to_arr(unioN, u_size, i + down);
            if (c[i] == 1)
                add_el_to_arr(inter, i_size, i + down);
        }
    }

    out_arr(unioN, u_size); out_arr(inter, i_size);
    return 0;
}