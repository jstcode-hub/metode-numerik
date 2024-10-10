#include <stdio.h> // Untuk fungsi input/output standar (printf, scanf)
#include <math.h>  // Untuk fungsi matematika, seperti fabs (menghitung nilai mutlak)

// Definisikan fungsi F(x) = x^3 - 7x + 1
// Fungsi ini mendefinisikan persamaan yang akar/solusinya kita cari
double f(double x)
{
    return x * x * x - 7 * x + 1; // Mengembalikan nilai dari persamaan x^3 - 7x + 1
}

// Definisikan turunan F'(x) = 3x^2 - 7
// Fungsi ini mendefinisikan turunan pertama dari F(x), yang digunakan dalam metode Newton-Raphson
double f_prime(double x)
{
    return 3 * x * x - 7; // Mengembalikan nilai dari turunan persamaan 3x^2 - 7
}

// Implementasi metode Newton-Raphson
// Metode ini mencari akar dari fungsi non-linear dengan menggunakan pendekatan iteratif
void newton_raphson(double initial_guess, double tolerance, int max_iter)
{
    double x = initial_guess; // Inisialisasi nilai tebakan awal untuk akar
    int iter = 0;             // Inisialisasi iterasi ke-0

    // Header tabel untuk menampilkan hasil iterasi dalam bentuk tabel
    printf("| %-3s | %-9s | %-10s | %-10s | %-9s | %-10s |\n", "i", "xi", "F(xi)", "F'(xi)", "xi+1", "F(xi+1)");
    printf("---------------------------------------------------------------\n");

    // Loop utama Newton-Raphson, berlanjut selama nilai f(x) lebih besar dari toleransi atau iterasi belum mencapai batas maksimal
    while (fabs(f(x)) > tolerance && iter < max_iter)
    {
        double fx = f(x);             // Hitung nilai fungsi F(x) pada titik xi
        double fpx = f_prime(x);      // Hitung nilai turunan F'(x) pada titik xi
        double x_next = x - fx / fpx; // Hitung nilai xi+1 (solusi baru yang lebih dekat ke akar)
        double f_x_next = f(x_next);  // Hitung nilai F(xi+1) untuk solusi baru

        // Cetak hasil tiap iterasi dalam bentuk tabel
        printf("| %-3d | %-9.6f | %-10.6f | %-10.6f | %-9.6f | %-10.6f |\n", iter, x, fx, fpx, x_next, f_x_next);

        // Perbarui nilai x dengan nilai x_next untuk iterasi berikutnya
        x = x_next;
        iter++; // Naikkan jumlah iterasi
    }

    // Cetak garis pemisah dan hasil akhir akar yang ditemukan
    printf("---------------------------------------------------------------\n");
    printf("Akar ditemukan: x = %.6f\n", x);
}

int main()
{
    double initial_guess, tolerance; // Variabel untuk tebakan awal dan toleransi
    int max_iter;                    // Variabel untuk jumlah maksimal iterasi

    // Minta input pengguna untuk tebakan awal
    printf("Masukkan nilai tebakan awal: ");
    scanf("%lf", &initial_guess); // Baca input tebakan awal dari pengguna

    // Minta input pengguna untuk nilai toleransi (keakuratan)
    printf("Masukkan nilai toleransi: ");
    scanf("%lf", &tolerance); // Baca input toleransi dari pengguna

    // Minta input pengguna untuk maksimal iterasi
    printf("Masukkan maksimal iterasi: ");
    scanf("%d", &max_iter); // Baca input jumlah maksimal iterasi

    // Cetak judul untuk menjelaskan metode yang digunakan
    printf("Metode Newton-Raphson untuk F(x) = X^3 - 7X + 1\n");

    // Panggil fungsi Newton-Raphson dengan parameter yang diinput oleh pengguna
    newton_raphson(initial_guess, tolerance, max_iter);

    return 0; // Kembalikan nilai 0, yang menunjukkan program berjalan dengan sukses
}
