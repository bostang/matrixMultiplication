// Program matrixMultiplication
    // melakukan perkalian matriks dengan beberapa algoritma seperti algoritma perkalian matriks standar
    // dan algoritma strassen
// KAMUS
    // Variabel
        // n : integer { ukuran matriks yang akan dikalikan (nxn) }
        // a, b : matrix [n x n] of integer { matriks yang ingin dikalikan }
        // c : matrix [n x n] of integer { matriks hasil perkalian }
// ALGORITMA UTAMA
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "functionProcedure.h"

int main() {

    int n;
    printf("Masukkan ukuran matrix: ");
    scanf("%d", &n);
    
    int a[maxSize][maxSize], b[maxSize][maxSize], c[maxSize][maxSize];

        // melakukan pengisian matriks a dari file eksternal
    inputMatriks(a,n,n,"m1t.csv");
        // melakukan pengisian matriks b dari file eksternal
    inputMatriks(b,n,n,"m2t.csv");

        // mencetak matriks a
    printf("matriks a :\n");
    cetakMatriks(a,n,n);
    printf("\n");

        // mencetak matriks b
    printf("matriks b :\n");
    cetakMatriks(b,n,n);
    printf("\n");

        // menghitung c = a x b
    kaliStandardMatriks(c,a,b,n);

        // mencetak matriks c
    printf("matriks c = a x b :\n");
    cetakMatriks(c,n,n);
    printf("\n");
}