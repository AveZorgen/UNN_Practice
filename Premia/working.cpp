#include "working.h"


void add_subj(int a[], int el) {
	a[a[0] + 1] = el; a[0]++;
}

void fill_massives(int students[][3],int subjects[][N_STUD+1],float st_inf[][N_INFO]){
	int st_id, subj_id, mark;
	for (int i = 0; i < N_STUD; i++) {
		st_id = students[i][0]; subj_id = students[i][1]; mark = students[i][2];
		if (!(st_id + subj_id + mark)) break;

		add_subj(subjects[subj_id], st_id);

		st_inf[st_id][0] += mark; st_inf[st_id][1]++; st_inf[st_id][2] = st_inf[st_id][0] / st_inf[st_id][1];

		if (st_inf[st_id][2] == 5) st_inf[st_id][3] = 2;
		else if (mark <= 3) st_inf[st_id][3] = -1;
		else if (st_inf[st_id][3] != -1) st_inf[st_id][3] = 1;
	}
}

void general_coef(int* k, float arr[][N_INFO]) {
	for (int i = 0; i < MAX_ST_ID; i++) {
		if (arr[i][1] > 0) {
			if (arr[i][3] == -1) arr[i][3] = 0;
			*k += (int)arr[i][3];
		}
	}
}