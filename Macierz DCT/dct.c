#include "dct.h"

void initiateMatrix(float m[N][N], int size) {
	for (int i = 0; i < size; i++) {
		for (int j = 0; j < size; j++) {
			m[i][j] = 0;
		}
	}
}

void initiateCharMatrix(char repr[N][N], int size) {
	for (int k = 0; k < size; k++) {
		for (int n = 0; n < size; n++) {
			repr[k][n] = '0';
		}
	}
}

void displayMatrix(float m[N][N], int size) {
	for (int i = 0; i < size; i++) {
		printf("|");
		if (i == N / 2) {
			for (int k = 0; k < (size * 8 + 5); k++) {
				printf("-");
			}
			printf("|");
			printf("\n");
			printf("|");
		}
			//printf("\n");
		for (int j = 0; j < size; j++) {
			if (j == N / 2) {
				printf("  |");
			}
			printf("%8.4f", m[i][j]);
		}
		printf("  |\n");
	}
}

void displayCharMatrix(char repr[N][N], int size) {
	for (int i = 0; i < size; i++) {
		printf("|");
		if (i == N / 2) {
			for (int k = 0; k < (size * 3 + 1); k++) {
				printf("-");
			}
			printf("|");
			printf("\n");
			printf("|");
		}
		for (int j = 0; j < size; j++) {
			if (j == N / 2) {
				printf("|");
			}
			printf(" %c ", repr[i][j]);
		}
		printf("|\n");
	}
}
void calculateCoefficients(float m[N][N], int size) {
	for (int k = 0; k < size; k++) {
		for (int n = 0; n < size; n++) {
			if (k == 0) {
				m[k][n] = sqrt(1.0f / size) * (cos((2 * n + 1) * M_PI * k / (2 * size)));
			}
			else {
				m[k][n] = sqrt(2.0f / size) * (cos((2 * n + 1) * M_PI * k / (2 * size)));
			}
		}
	}
}

void changeRepresentation(char repr[N][N], float m[N][N], int size) {
	float temp[N];

	for (int k = 0; k < size; k++) {
		temp[k] = 0;
	}

	for (int k = 0; k < size; k++) {
		if (k == (size / 2))
			continue;
		temp[k] = m[k][0];
	}
	printf("Unikalne wartosci macierzy bazy: [");
	for (int k = 0; k < size; k++) {
		printf("%.4f ", temp[k]);
	}
	printf("]\n");

	for (int i = 0; i < size; i++) {
		for (int k = 0; k < size; k++) {
			for (int n = 0; n < size; n++) {
				if (temp[i] == m[k][n]) {
					repr[k][n] = 'a' + i;
				} else if (-temp[i] == m[k][n]) {
					repr[k][n] = 'A' + i;
				}
			}
		}
	}
}

void saveMatrixToFile(char filename[], char repr[N][N], int size) {
	FILE *fp;
	filename = strcat(filename, ".txt");
	if ((fp = fopen(filename, "w")) == NULL) {
		printf("Nie moge otworzyc pliku do zapisu!\n");
		exit(1);
	}
	fprintf(fp, "%s", "Macierz bazy przekszta³cona na wygodn¹ reprezentacjê: N = 16\n");
	fprintf(fp, "%s", "litera ma³a - wspó³czynnik dodatni, litera du¿a - wspó³czynnik ujemny\n\n");
	for (int i = 0; i < size; i++) {
		fprintf(fp, "%s", "|");
		if (i == N / 2) {
			for (int k = 0; k < (size * 3 + 1); k++) {
				fprintf(fp, "%s", "-");
			}
			fprintf(fp, "%s", "|");
			fprintf(fp, "%s", "\n");
			fprintf(fp, "%s", "|");
		}
		for (int j = 0; j < size; j++) {
			if (j == N / 2) {
				fprintf(fp, "%s", "|");
			}
			fprintf(fp, " %c ", repr[i][j]);
		}
		fprintf(fp, "%s", "|\n");
	}
	fclose(fp);
}

void spareMatrixRows(struct swap *p, char repr[N][N], int size, int row1, int row2) {
	char temp;
	for (int i = 0; i < size; i++) {
		temp = repr[row2][i];
		repr[row2][i] = repr[row1][i];
		repr[row1][i] = temp;
	}
	p[cnt].elem1 = row1;
	p[cnt].elem2 = row2;
	cnt++;

}

void spareMatrixColumns(char repr[N][N], int size, int col1, int col2) {
	char temp;
	for (int i = 0; i < size; i++) {
		temp = repr[i][col2];
		repr[i][col2] = repr[i][col1];
		repr[i][col1] = temp;
	}
}