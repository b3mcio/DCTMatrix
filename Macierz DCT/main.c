#include <stdio.h>
#include <stdlib.h>
#include "dct.h"

int main(void) {
	float m[N][N];
	char repr[N][N];
	int choice = 0;
	char filename[] = "resultMatrix";
	int row1, row2, col1, col2;
	struct swap listOfSpares[N * 2];
	initiateMatrix(m, N);
	initiateCharMatrix(repr, N);

	for (;;) {
		printf("Dostepne operacje:\n");
		printf("1. Oblicz wspolczynniki\n2. Wyswietl macierz\n3. Utworz wygodna reprezentacje\n"
			"4. Pokaz wygodna reprezentacje\n5. Zapisz macierz wynikowa do pliku\n6. Zamien wiersze miejscami\n"
			"7. Zamien kolumny miejscami\n");
		printf("Podaj numer operacji: ");
		scanf("%d", &choice);
		switch (choice)
		{
			case 1: 
				calculateCoefficients(m, N);
				system("cls");
				break;
			case 2:
				system("cls");
				displayMatrix(m, N);
				break;
			case 3:
				system("cls");
				changeRepresentation(repr, m, N);
				break;
			case 4:
				system("cls");
				displayCharMatrix(repr, N);
				break;
			case 5:
				system("cls");
				printf("Podaj nazwe pliku: ");
				scanf("%s", filename);
				saveMatrixToFile(filename, repr, N);
				break;
			case 6:
				system("cls");
				printf("Podaj wiersz nr 1 do zamiany: ");
				scanf("%d", &row1);
				printf("Podaj wiersz nr 2 do zamiany: ");
				scanf("%d", &row2);
				if ((row1 < 0 || row1 > N - 1) || (row2 < 0 || row2 > N - 1)) {
					printf("Wprowadziles zle numery wierszy!");
					break;
				}
				else {
					spareMatrixRows(&listOfSpares, repr, N, row1, row2);
					break;
				}
			case 7:
				system("cls");
				printf("Podaj kolumne nr 1 do zamiany: ");
				scanf("%d", &col1);
				printf("Podaj kolumne nr 2 do zamiany: ");
				scanf("%d", &col2);
				if ((col1 < 0 || col1 > N - 1) || (col2 < 0 || col2 > N - 1)) {
					printf("Wprowadziles zle numery kolumn!");
					break;
				}
				else {
					spareMatrixColumns(repr, N, col1, col2);
					break;
				}
			case 8:
				system("cls");
				for (int i = 0; i < N * 2; i++) {
					printf("%hu", listOfSpares[i].elem1);
					printf("%hu", listOfSpares[i].elem2);
				}
				break;
			default:
				return 0;
				break;
		}
	}
	return 0;
}