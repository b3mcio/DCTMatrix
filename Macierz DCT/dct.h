#ifndef DCT_H
#define DCT_H

#define _USE_MATH_DEFINES
#include <math.h>
#include <stdio.h>

struct swap {
	unsigned short int elem1;
	unsigned short int elem2;
};

static int cnt = 0;

#define N 16
void initiateMatrix(float m[N][N], int size);
void initiateCharMatrix(char repr[N][N], int size);
void displayMatrix(float m[N][N], int size);
void displayCharMatrix(char repr[N][N], int size);
void calculateCoefficients(float m[N][N], int size);
void changeRepresentation(char repr[N][N], float m[N][N], int size);
void saveMatrixToFile(float m[N][N], int size);
void spareMatrixRows(struct swap *p, char repr[N][N], int size, int row1, int row2);
void spareMatrixColumns(char repr[N][N], int size, int col1, int col2);

#endif