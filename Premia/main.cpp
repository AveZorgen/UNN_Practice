#include <stdio.h>
#include <stdlib.h>

#define MAX_ST_ID 200
#define MAX_OBJ_ID 50
#define N_STUD 5

void add_obj(int a[], int el) {
	a[a[0] + 1] = el; a[0]++;
}


int main() {
	float Summ = 1000; int k = 0;
	int students[N_STUD][3] = { {1,2,5}, //ID студента, ID предмета, Оценка за предмет
								{2,3,4},
								{3,1,3},
								{2,2,5},
								{1,3,5} }; //перед добавлением учеников, увеличить n_stud
	float st_inf[MAX_ST_ID][5]{}; //Сумма баллов, Кол-во оценок, Средняя оценка, Коэф стипендии, Размер стипендии
	int objects[MAX_OBJ_ID][N_STUD + 1]{}; //id предметов от 0 до n_obj-1
	int st_id, obj_id, mark;

	for (int i = 0; i < N_STUD; i++) {
		st_id = students[i][0]; obj_id = students[i][1]; mark = students[i][2];

		add_obj(objects[obj_id], st_id);

		st_inf[st_id][0] += mark; st_inf[st_id][1]++; st_inf[st_id][2] = st_inf[st_id][0] / st_inf[st_id][1];

		if (st_inf[st_id][2] == 5) st_inf[st_id][3] = 2;
		else if (mark <= 3) st_inf[st_id][3] = -1;
		else if (st_inf[st_id][3] != -1) st_inf[st_id][3] = 1;
	}

	for (int i = 0; i < MAX_OBJ_ID; i++) { //Те, кто сдавал предметы
		if (objects[i][0] > 0) {
			printf("%d: ", i);
			for (int j = 0; j < objects[i][0]; j++)
				printf("%d ", objects[i][j + 1]);
			printf("\n");
		}
	}

	for (int i = 0; i < MAX_ST_ID; i++) { //Распределение стипендии
		if (st_inf[i][1] > 0) {
			if (st_inf[i][3] == -1) st_inf[i][3] = 0;
			k += st_inf[i][3];
		}
	}

	for (int i = 0; i < MAX_ST_ID; i++) { //Вывод информации по студентам
		if (st_inf[i][1] > 0) {
			st_inf[i][4] = (Summ / k) * st_inf[i][3];
			printf("\nID: %d, SummM: %5.2f, Kol-vo: %3.2f, Sred: %.2f, K: %.2f, Prem: %.2f", i, st_inf[i][0], st_inf[i][1], st_inf[i][2], st_inf[i][3], st_inf[i][4]);
		}
	}
}