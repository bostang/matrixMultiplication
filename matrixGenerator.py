# Program matrixGenerator
    # menggenerate matrix berukuran M kali N yang akan disimpan dalam sebuah file .csv
    # dengan separator koma -> kemudian akan dibaca dengan C
    # untuk disimpan ke array hingga akhirnya dipakai untuk perkalian matriks
# KAMUS
    # Variabel
        # m : integer { banyak baris matriks }
        # n : integer { banyak kolom matriks }
        # lines1 : array of integer { angka yang akan ditulis ke file matrix1.csv }
        # lines2 : array of integer { angka yang akan ditulis ke file matrix2.csv }
        # count : integer { indeks matriks saat penulisan ke file }
# ALGORITMA UTAMA

from random import randint

m = int(input("masukkan banyak baris matriks:\n>>> "))
n = int(input("masukkan banyak kolom matriks:\n>>> "))
lines1 = []
lines2 = []

for k in range(m):
    for j in range(n):
        lines1 += str(randint(0,10))
        lines2 += str(randint(0,10))

count = 0

f1 = open("matrix1.csv",'w')
f2 = open("matrix2.csv",'w')

for k in range(m):
    for j in range(n):
        f1.write(str(lines1[count]))
        f2.write(str(lines2[count]))
        count += 1
        if (j != n-1):
            f1.write(',')
            f2.write(',')
    if (k != m-1):
        f1.write('\n')
        f2.write('\n')

f1.close()
f2.close()

# REFERENSI
    # Cara menulis ke file dengan python
        # https://www.pythontutorial.net/python-basics/python-write-text-file/#:~:text=To%20write%20to%20a%20text%20file%20in%20Python%2C,close%20the%20file%20using%20the%20close%20%28%29%20method.
    # mengenerate angka acak
        # https://towardsdatascience.com/statistics-in-python-generating-random-numbers-in-python-numpy-and-sklearn-60e16b2210ae#:~:text=Generating%20Random%20Numbers%20in%20Python.%20To%20generate%20random,from%200%20to%201%20%28where%201%20is%20excluded%29.