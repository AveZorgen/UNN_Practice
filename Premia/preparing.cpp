#include <stdlib.h>
#include <ctime>
#include "preparing.h"


bool in(int arr[][3], int comb[],int pos){
	for (int i = 0; i<pos;i++){
		if (arr[i][0] == comb[0] && arr[i][1] == comb[1] && arr[i][2] == comb[2]){
			return true;
		}
	}
	return false;
}

void set_info(int students[][3]){
    srand(static_cast<unsigned int>(time(0)));
	for (int i=0; i< N_STUD; i++){
		do
		{
			students[i][0] = rand() % MAX_ST_ID; 
			students[i][1] = rand() % MAX_SUBJ_ID; 
			students[i][2] = rand() % MARK_SYS + 1;
		} while (in(students, students[i],i));
	}
}