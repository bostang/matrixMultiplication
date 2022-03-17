#ifndef functionProcedure_H_   /* Include guard */
#define functionProcedure_H_

// DEKLARASI KONSTANTA
#define maxSize 127
#define MAX_LEN 255

// DEKLARASI FUNGSI
void cetakMatriks(int arr[maxSize][maxSize],int nbaris,int nkolom);

void inputMatriks(int arr[maxSize][maxSize],int nbaris, int nkolom, char namaFile[MAX_LEN]);

void kaliStandardMatriks(int arr_hasil[maxSize][maxSize], int arr1[maxSize][maxSize],int arr2[maxSize][maxSize],int n);

#endif // functionProcedure_H_

// catatan :
    // ketika maxSize dibuat 1023 -> program segmentation fault -> nampaknya menggunakan memori yang terlalu banyak
    // matriks ukuran 1000 x 1000 bukanlah lelucon

// referensi : https://stackoverflow.com/questions/7109964/creating-your-own-header-file-in-c