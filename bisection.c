#include <stdio.h> // Pustaka untuk fungsi input/output standar (printf, scanf)
#include <math.h>  // Pustaka untuk fungsi matematika (fabs)

// Fungsi yang akan dicari akarnya
// Fungsi ini mendefinisikan persamaan f(x) = x^2 - 6x + 8, yang akar dari persamaannya akan dicari
double f(double x)
{
    return x * x - 6 * x + 8; // Mengembalikan nilai f(x) = x^2 - 6x + 8
}

// Fungsi untuk melakukan metode biseksi
// Metode ini mencari akar dalam interval [a, b] dengan pendekatan iteratif
void bisection(double a, double b, double tol)
{
    // Pastikan f(a) dan f(b) memiliki tanda yang berlawanan, syarat utama metode biseksi
    if (f(a) * f(b) >= 0)
    {
        // Jika f(a) dan f(b) memiliki tanda yang sama, metode tidak bisa dilanjutkan
        printf("Tidak ada akar di interval tersebut.\n");
        return; // Kembali ke program utama
    }

    double c;        // Variabel untuk menyimpan titik tengah dari interval [a, b]
    int iterasi = 1; // Variabel penghitung jumlah iterasi

    // Header tabel untuk menampilkan hasil per iterasi
    printf("| Iterasi |      a      |    f(a)    |      b      |    f(b)    |      c      |    f(c)    |   b - a   |\n");
    printf("-----------------------------------------------------------------------------------------------------\n");

    // Proses iterasi hingga selisih antara b dan a lebih kecil dari toleransi
    while (1)
    {
        // Mencari titik tengah dari interval [a, b]
        c = (a + b) / 2;

        // Mencetak hasil per iterasi, termasuk nilai b-a
        printf("|   %2d    |  %9.6f |  %9.6f |  %9.6f |  %9.6f |  %9.6f |  %9.6f | %9.6f |\n",
               iterasi, a, f(a), b, f(b), c, f(c), b - a);

        // Tentukan subinterval yang baru:
        // Jika f(c) dan f(a) berlawanan tanda, akar berada di interval [a, c]
        if (f(c) * f(a) < 0)
        {
            b = c; // Perbarui nilai b
        }
        else
        {
            a = c; // Jika tidak, akar berada di interval [c, b], perbarui nilai a
        }

        // Jika selisih b-a sudah kurang dari toleransi yang diinginkan, iterasi berakhir
        if (b - a < tol)
        {
            // Tampilkan iterasi terakhir di mana b-a sudah kurang dari toleransi
            c = (a + b) / 2;
            printf("|   %2d    |  %9.6f |  %9.6f |  %9.6f |  %9.6f |  %9.6f |  %9.6f | %9.6f |\n",
                   iterasi + 1, a, f(a), b, f(b), c, f(c), b - a);
            break; // Keluar dari loop
        }

        iterasi++; // Naikkan jumlah iterasi
    }

    // Cetak hasil akhir setelah iterasi selesai
    printf("-----------------------------------------------------------------------------------------------------\n");
    printf("Akar yang ditemukan: %9.6f\n", c);
}

int main()
{
    double a, b, tol; // Variabel untuk interval [a, b] dan toleransi

    // Meminta input dari pengguna untuk nilai interval [a, b] dan toleransi
    printf("Masukkan nilai awal a: ");
    scanf("%lf", &a); // Baca nilai a dari input pengguna

    printf("Masukkan nilai awal b: ");
    scanf("%lf", &b); // Baca nilai b dari input pengguna

    printf("Masukkan toleransi: ");
    scanf("%lf", &tol); // Baca nilai toleransi dari input pengguna

    // Menjalankan metode biseksi dengan parameter [a, b] dan toleransi yang diberikan
    bisection(a, b, tol);

    return 0; // Program selesai dengan sukses
}
