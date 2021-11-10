#include <stdio.h>
#include "resulting.h"


void about_exams(int arr[][N_STUD+1]){
	for (int i = 0; i < MAX_SUBJ_ID; i++) {
		if (arr[i][0] > 0) {
			printf("Subj %d: ", i);
			for (int j = 0; j < arr[i][0]; j++)
				printf("%d ", arr[i][j+1]);
			printf("\n");
		}
	}
}

void result(float arr[][N_INFO], float summ, int k){
	for (int i = 0; i < MAX_ST_ID; i++) {
		if (arr[i][1] > 0) {
			arr[i][4] = (summ / k) * arr[i][3];
			printf("ID: %3.d, MarkSUM: %5.2f, MarkN: %3.2f, Sredn: %.2f, K: %.2f, Prem: %7.2f\n", i,arr[i][0], arr[i][1], arr[i][2], arr[i][3], arr[i][4]);
		}
	}
}