#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <random>
#include <time.h>
#include <locale.h>
#include <windows.h>
#include <string.h>

using namespace std;



void generate(int** mass, int n) { // заполнение массивов
	int i, r, c;
	for (i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			r = rand() % 2;
			c = rand() % 2;
			if (r == 1) {
				mass[i][j] = 1;
			}
			else
				mass[i][j] = 0;
			if (i == j) {
				mass[i][j] = 0;
			}
		}
	}
	for (i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			if (mass[i][j] != mass[j][i]) {
				mass[i][j] = mass[j][i];
			}
		}
	}
}

void rr(int** mass, int n)
{
	int i;
	printf("\nРучной ввод первой матрицы:\n");
	for (i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			printf(" Ребро между %d и %d - ", i + 1, j + 1);
			scanf_s("%d", &mass[i][j]);
		}
	}
}

void rr2(int** mass, int n)
{
	int i;
	printf("\nРучной ввод второй матрицы:\n");
	for (i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			printf(" Ребро между %d и %d - ", i + 1, j + 1);
			scanf_s("%d", &mass[i][j]);
		}
	}
}


void obe(int** mass_olegon, int** mass_olegon2, int** mass_olegon3, int** mass_p1, int** mass_p2, int n, int n1) { //объединение
	int i, j;

	if (n > n1) {
		for (i = 0; i < n1; i++) {
			for (j = 0; j < n1; j++) {
				if (mass_p1[i][j] != 1 && mass_p2[i][j] == 1) {
					mass_p1[i][j] = 1;
				}
			}
		}

		printf("\nРезультат объединения матриц:\n");
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < n; j++) {
				mass_olegon[i][j] = mass_p1[i][j];
				printf("%d ", mass_p1[i][j]);
			}
			printf("\n");
		}
	}


	if (n < n1) {
		for (i = 0; i < n; i++) {
			for (j = 0; j < n; j++) {
				if (mass_p1[i][j] == 1 && mass_p2[i][j] != 1) {
					mass_p2[i][j] = 1;
				}
			}
		}


		printf("\nРезультат объединения матриц:\n");
		for (int i = 0; i < n1; i++) {
			for (int j = 0; j < n1; j++) {
				mass_olegon2[i][j] = mass_p2[i][j];
				printf("%d ", mass_p2[i][j]);
			}
			printf("\n");
		}
	}


	if (n == n1) {
		for (i = 0; i < n1; i++) {
			for (j = 0; j < n1; j++) {
				if (mass_p1[i][j] != 1 && mass_p2[i][j] == 1) {
					mass_p1[i][j] = 1;
				}
			}
		}

		printf("\nРезультат объединения матриц:\n");
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < n; j++) {
				mass_olegon3[i][j] = mass_p1[i][j];
				printf("%d ", mass_p1[i][j]);
			}
			printf("\n");
		}
	}
}

void oleg(int** mass, int n)
{
	FILE* result;
	result = fopen("РЕЗУЛЬТАТ.txt", "w");

	fprintf(result, " Результат объединения матриц: \n\n ");
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			fprintf(result, "%4d ", mass[i][j]);
		}
		fprintf(result, "\n\n");
	}
	fclose(result);
}





int main() {
	setlocale(LC_ALL, "Rus");
	srand(time(NULL));
	int n, n1;



	printf("Введите размеры массивов через пробел:");
	scanf_s("%d %d", &n, &n1);
	int** mass = (int**)malloc(sizeof(int) * n);
	int** mass_p1 = (int**)malloc(sizeof(int) * n);
	int** mass_p2 = (int**)malloc(sizeof(int) * n1);
	int** mass_olegon = (int**)malloc(sizeof(int) * n);
	int** mass_olegon2 = (int**)malloc(sizeof(int) * n1);
	int** mass_olegon3 = (int**)malloc(sizeof(int) * n1);

	for (int i = 0; i < n; i++) {
		mass[i] = (int*)malloc(sizeof(int) * n);
		mass_p1[i] = (int*)malloc(sizeof(int) * n);
		mass_olegon[i] = (int*)malloc(sizeof(int) * n);
	}
	for (int i = 0; i < n1; i++) {
		mass_p2[i] = (int*)malloc(sizeof(int) * n1);
		mass_olegon2[i] = (int*)malloc(sizeof(int) * n1);
		mass_olegon3[i] = (int*)malloc(sizeof(int) * n1);
	}



	int i = 0;
	int j = 0;
	int gg;
	printf("\n1-Ручной ввод\n");
	printf("\n2-Автоматический ввод\n");
	printf("\nВыберите ввод: ");
	scanf_s("%d", &gg);
	while (gg > 2 || gg < 1)
	{
		printf("\nВы выбрали какое-то другое число...(\n");
		printf("\nВведите нужный пункт: ");
		scanf_s("%d", &gg);
	}

	if (gg == 1)
	{
		rr(mass, n);
		rr2(mass_p2, n1);
	}

	if (gg == 2)
	{
		generate(mass, n);
		generate(mass_p2, n1);
	}


	printf("\nМатрица 1\n");
	for (i = 0; i < n; i++) {
		for (j = 0; j < n; j++) {
			mass_p1[i][j] = mass[i][j];
		}
	}

	for (i = 0; i < n; i++) {
		for (j = 0; j < n; j++) {
			printf("%d ", mass[i][j]);
		}
		printf("\n");
	}

	printf("\nМатрица 2\n");
	for (i = 0; i < n1; i++) {
		for (j = 0; j < n1; j++) {
			printf("%d ", mass_p2[i][j]);
		}
		printf("\n");
	}
	printf("\n");


	obe(mass_olegon, mass_olegon2, mass_olegon3, mass_p1, mass_p2, n, n1);
	printf("\n");
	if (n > n1) {
		oleg(mass_olegon, n);
	}
	if (n < n1) {
		oleg(mass_olegon2, n1);
	}
	if (n == n1) {
		oleg(mass_olegon3, n1);
	}
	return 0;
}
