#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define ROWS1 2
#define COLS1 3
#define ROWS2 3
#define COLS2 2

void RastgeleDegerUret(int rows, int cols, int matris[rows][cols]);
void MatrisiYazdir(int rows, int cols, int matris[rows][cols]);
void MatrisiTopla(int rows, int cols, int matris1[rows][cols], int matris2[rows][cols], int sonuc[rows][cols]);
void MatrisCarpimi(int matris1[ROWS1][COLS1], int matris2[ROWS2][COLS2], int sonuc[ROWS1][COLS2]);


int main() {
    srand(time(NULL));

    int dizi1[ROWS1][COLS1];
    int dizi2[ROWS2][COLS2];
    int sum[ROWS1][COLS1];
    int product[ROWS1][COLS2];

    
    printf("****** 1. MATRIS ******\n");
    RastgeleDegerUret(ROWS1, COLS1, dizi1);
    MatrisiYazdir(ROWS1, COLS1, dizi1);

    
    printf("\n****** 2. MATRIS ******\n");
    RastgeleDegerUret(ROWS2, COLS2, dizi2);
    MatrisiYazdir(ROWS2, COLS2, dizi2);

    
    printf("\n****** MATRIS TOPLAMI ******\n");
    if (ROWS1 == ROWS2 && COLS1 == COLS2) {
        MatrisiTopla(ROWS1, COLS1, dizi1, dizi2, sum);
        MatrisiYazdir(ROWS1, COLS1, sum);
    } else {
        printf("Matris toplami mumkun olmaz .iki Matrisin satir sutun sayilari esit olmali.\n");
    }

    
    printf("\n****** MATRIS CARPIMI ******\n");
    if (COLS1 == ROWS2) {
        printf("Matris Carpimi mumkun.\n");
        MatrisCarpimi(dizi1, dizi2, product);
        MatrisiYazdir(ROWS1, COLS2, product);
    } else {
        printf("Matris carpimi mümkün degil. 1.Matrisin sutunu 2.Matrisin satiri esit olmali. \n");
    }

    return 0;
}



void RastgeleDegerUret(int rows, int cols, int matris[rows][cols]) {
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            matris[i][j] = rand() % 100 + 1; // Values between 1 and 100
        }
    }
}


void MatrisiYazdir(int rows, int cols, int matris[rows][cols]) {
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            printf("%3d ", matris[i][j]);
        }
        printf("\n");
    }
}


void MatrisiTopla(int rows, int cols, int matris1[rows][cols], int matris2[rows][cols], int sonuc[rows][cols]) {
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            sonuc[i][j] = matris1[i][j] + matris2[i][j];
        }
    }
}


void MatrisCarpimi(int matris1[ROWS1][COLS1], int matris2[ROWS2][COLS2], int sonuc[ROWS1][COLS2]) {
    for (int i = 0; i < ROWS1; i++) {
        for (int j = 0; j < COLS2; j++) {
            sonuc[i][j] = 0;
            for (int k = 0; k < COLS1; k++) {
                sonuc[i][j] += matris1[i][k] * matris2[k][j];
            }
  } }
} 