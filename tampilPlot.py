# Program tampilPlot
    # menampilkan pengukuran waktu eksekusi algoritma perkalian matriks standard
    # dan algoritma strassen yang terdapat pada file .csv
    # file .csv diperoleh dari output program C
# KAMUS
    # Variabel
        # fp : pointer to file { pointer ke objek file yang ingin dibaca datanya }
        #
# ALGORITMA UTAMA
import pandas as pd
from matplotlib import pyplot as plt

fp = open("contoh_plot.csv",'r')

    # menyimpan run-time algoritma 1 ke array algo1
algo1 = fp.readline().split(',')
for k in range(len(algo1)):
    algo1[k] = int(algo1[k])

    # menyimpan run-time algoritma 2 ke array algo2
algo2 = fp.readline().split(',')
for k in range(len(algo2)):
    algo2[k] = int(algo2[k])

n_axis = ['10','100','200','500'] # dibuat dalam character, supaya ketika di-gambar plot tidak ada nilai antara (200,300, dst.) 

plt.scatter(n_axis,algo1)
plt.scatter(n_axis,algo2)
plt.xlabel('$n$')
plt.ylabel('$t$ (ms)')
plt.legend(['algoritma 1','algoritma 2'])
plt.savefig("contoh_grafik.png")
plt.show()

fp.close()

# REFERENSI
    # https://www.tutorialspoint.com/how-to-plot-csv-data-using-matplotlib-and-pandas-in-python