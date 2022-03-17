// Program functionProcedure
    // agar program utama (matrixMultiplication.c) tidak terlalu ramai (agar program lebih modular)
    // maka implementasi fungsi akan dibuat di file .c terpisah dan deklarasi/prototipenya pada file .h terpisah
// KAMUS    
    // Konstanta
        // maxSize : integer := 1023 { ukuran maksimum baris/kolom matriks }
        // MAX_LEN : integer := 255 { ukuran maksimum string}
    // Fungsi/Prosedur
        // procedure cetakMatriks(input : int matriks (maxSize x maxSize) of integer arr,integer nbaris,integer nkolom)
            // mencetak matriks ke layar
            // I.S. matriks yang ingin dicetak telah terdefinisi
            // F.S. matriks telah dicetak ke layar
        // procedure inputMatriks(input/output: int arr[maxSize][maxSize], input nbaris : integer , input nkolom : integer, input namaFile : string)
            // melakukan input matriks dari file eksternal .csv
            // I.S. file .csv eksternal dan matriks yang mau diisi telah terdefinisi
            // F.S. elemen matriks telah terisi dari file eskternal
        // procedure kaliStandardMatriks(output arr_hasil : matrix [n x n] of integer, input arr1 arr2 : matrix [n x n] of integer)
            // melakukan perkalian matriks dengan algoritma standard terhadap dua matriks berukuran sama yaitu n x 
            // I.S. matriks yang ingin dikalikan telah terdefinisi
            // F.S. matriks hasil telah terhitung
// INCLUDE HEADER FILE
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "functionProcedure.h"


// REALISASI FUNGSI/PROSEDUR
void cetakMatriks(int arr[maxSize][maxSize],int nbaris,int nkolom)
{
    // ALGORITMA
    for (int j = 0;j<nbaris;j++)
    {
        for (int k = 0;k<nkolom;k++)
        {
            printf("%d",arr[j][k]);
            if (k != nkolom - 1)
            {
                printf(" "); // spasi sebelum elemen terakhir dalam satu baris
            }
        }

        // ganti baris sebelum baris terakahir
        if (j != nbaris - 1)
        {
            printf("\n");
        }
    }
}

void inputMatriks(int arr[maxSize][maxSize],int nbaris, int nkolom, char namaFile[MAX_LEN])
{
    // KAMUS LOKAL
        // Variabel
            // line : string { baris yang sedang dibaca dari file eksternal }
            // token : string { sub-string yang dibaca dengan strtok() terhadap line }
            // i, j : integer { indeks baris dan kolom matriks yang di-isi }
    // ALGORITMA
       // melakukan pengisian matriks arr dari file eksternal
    char line[MAX_LEN];
    char* token;

    FILE* fp = fopen(namaFile, "r");
    int i = 0;

    while(fgets(line, MAX_LEN, fp))
    {
            // membaca token pertama
        token = strtok(line, ",");
        
            // menyimpan (int) token pertama sebagai elemen pertama arr
        arr[i][0] = atoi(token);

            // terus membaca token berikutnya sebanyak nkolom-1 kali
        for(int j=1; j<nkolom ; j++)
        {
            token = strtok(NULL, ",");
            arr[i][j] = atoi(token);
        }
        token = strtok(NULL, "\n");
        arr[i][nkolom] = atoi(token);
        i++;
    }
    fclose(fp);
}

void kaliStandardMatriks(int arr_hasil[maxSize][maxSize], int arr1[maxSize][maxSize],int arr2[maxSize][maxSize],int n)
{
    // KAMUS LOKAL
        // Variabel
            // i,j,k : integer { indeks untuk perkalian standard matriks }
    // ALGORITMA
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<n;j++)
        {
            arr_hasil[i][j]=0;
            for(int k=0;k<n;k++)
            {
                arr_hasil[i][j]+=arr1[i][k]*arr2[k][j];
            }
        }
    }
}