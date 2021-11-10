#include "options.h"
#include "preparing.h"
#include "working.h"
#include "resulting.h"

//Дано:
//	* сумма (её надо распределить)
//	* список: номер зачётки, номер предмета, оценка
//
//Задание
//	+ кто сдавал экзамен?
//	+ средний балл студентов
//	+ стипендия:
//		 все 5 - x2
//		 есть 3- x0
//		 иначе - x1


int main() {
	float Summ = 1000; int k = 0; 
	// int students[N_STUD][3] = {  {1,2,5}, 
	// 								{2,3,4},
	// 								{3,1,3},
	// 								{2,2,5},
	// 								{1,3,5} };
	int students[N_STUD][3]={}; //ID студента, ID предмета, Оценка за предмет
	float st_inf[MAX_ST_ID][N_INFO]{}; //Сумма баллов, Кол-во оценок, Средняя оценка, Коэф стипендии, Размер стипендии
	int subjects[MAX_SUBJ_ID][N_STUD + 1]{};

	set_info(students); // Формирование students

	fill_massives(students,subjects,st_inf); //Заполнение subjects и st_info из заданного students
	general_coef(&k, st_inf); //Распределение стипендии

	about_exams(subjects); //Кто сдавал предметы
	result(st_inf,Summ,k); //Вывод информации по студентам
}