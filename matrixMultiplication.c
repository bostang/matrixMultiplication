#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LEN 255

int main() {

    int n;
    printf("Masukkan ukuran matrix: ");
    scanf("%d", &n);
    
    int i,j,k,a[n][n],b[n][n];
    int row1,col1,row2,col2,c[n-1][n-1],counter;

    row1 = n; col1 = n;
    row2 = n; col2 = n;
    counter = 0;

    char line[MAX_LEN];
    char* token;

    char namaFile[MAX_LEN];
    printf("Masukkan nama file matrix pertama: ");
    scanf("%s", namaFile);

    FILE* stream1 = fopen(namaFile, "r");
    i = 0;
    j = 0;
    while(fgets(line, MAX_LEN, stream1)) {
        token = strtok(line, ",");
        a[j][0] = atol(token);
        for(i=1;i<n-1;i++) {
            token = strtok(NULL, ",");
            a[j][i] = atol(token);
        }
        token = strtok(NULL, "\n");
        a[j][i+1] = atol(token);
        j++;
    }
    fclose(stream1);

    printf("Masukkan nama file matrix pertama: ");
    scanf("%s", namaFile);

    FILE* stream2 = fopen(namaFile, "r");
    i = 0;
    j = 0;
    while(fgets(line, MAX_LEN, stream2)) {
        token = strtok(line, ",");
        b[j][0] = atol(token);
        for(i=1;i<n-1;i++) {
            token = strtok(NULL, ",");
            b[j][i] = atol(token);
        }
        token = strtok(NULL, "\n");
        b[j][i+1] = atol(token);
        j++;
    }
    fclose(stream2);

    //enable kalo mau cek
    //printMatrix
    // for(int i=0;i<n;i++){
    //     for(int j=0;j<n;j++){
    //         printf("%d ",*(*(a+i)+j));
    //     }
    //     printf("\n");
    // }
    // for(int i=0;i<n;i++){
    //     for(int j=0;j<n;j++){
    //         printf("%d ",*(*(b+i)+j));
    //     }
    //     printf("\n");
    // }

    printf("Multiplication:\n");
    for(i=0;i<row1;i++){
        for(j=0;j<col2;j++) {
            c[i][j]=0;
            for(k=0;k<row2;k++) {
                c[i][j]+=a[i][k]*b[k][j];
            }
        printf("%d ",c[i][j]);
        }
    printf("\n");
    }

}