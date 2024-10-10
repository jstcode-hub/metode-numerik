#include <stdio.h> // Pustaka untuk fungsi input/output standar (printf, scanf)
#include <math.h>  // Pustaka untuk fungsi matematika (fabs)

// Definisikan fungsi f(x) = x^2 - 2x - 8
// Fungsi ini mendefinisikan persamaan yang akar/solusinya akan dicari
double f(double x)
{
    return x * x - 2 * x - 8; // Mengembalikan nilai dari fungsi f(x) = x^2 - 2x - 8
}

int main()
{
    double a, b, c;           // Variabel untuk interval [a, b] dan titik c
    double fa, fb, fc;        // Variabel untuk menyimpan nilai f(a), f(b), dan f(c)
    double tolerance = 0.01;  // Toleransi error untuk menentukan akurasi solusi
    int max_iterations = 100; // Batas maksimal iterasi
    int iteration = 0;        // Variabel penghitung jumlah iterasi

    // Masukkan nilai awal untuk interval [a, b] dari input pengguna
    printf("Masukkan nilai awal a: ");
    scanf("%lf", &a); // Membaca nilai a
    printf("Masukkan nilai awal b: ");
    scanf("%lf", &b); // Membaca nilai b

    // Hitung nilai f(a) dan f(b)
    fa = f(a);
    fb = f(b);

    // Pastikan f(a) dan f(b) memiliki tanda yang berlawanan, ini syarat metode Regula Falsi
    if (fa * fb > 0)
    {
        // Jika f(a) dan f(b) memiliki tanda yang sama, algoritma tidak dapat dilanjutkan
        printf("Kesalahan: f(a) dan f(b) harus memiliki tanda berlawanan.\n");
        return -1; // Menghentikan program dengan kode error -1
    }

    // Mulai iterasi metode Regula Falsi
    while (iteration < max_iterations)
    {
        // Hitung nilai c menggunakan formula Regula Falsi
        // c adalah titik potong garis lurus antara (a, f(a)) dan (b, f(b)) dengan sumbu x
        c = b - (fb * (b - a)) / (fb - fa);
        fc = f(c); // Hitung nilai f(c)

        // Cetak hasil iterasi saat ini
        printf("Iterasi %d: c = %lf, f(c) = %lf\n", iteration + 1, c, fc);

        // Periksa apakah solusi ditemukan berdasarkan toleransi yang telah ditentukan
        if (fabs(fc) < tolerance)
        {
            // Jika nilai f(c) sangat dekat dengan nol, c dianggap sebagai akar
            printf("Akar ditemukan: %lf\n", c);
            return 0; // Program selesai dengan sukses
        }

        // Tentukan interval baru [a, c] atau [c, b] berdasarkan tanda f(a) * f(c)
        if (fa * fc < 0)
        {
            // Jika f(a) dan f(c) memiliki tanda berlawanan, maka akar ada di [a, c]
            b = c;   // Perbarui b menjadi c
            fb = fc; // Perbarui nilai f(b) menjadi f(c)
        }
        else
        {
            // Jika f(a) dan f(c) memiliki tanda yang sama, maka akar ada di [c, b]
            a = c;   // Perbarui a menjadi c
            fa = fc; // Perbarui nilai f(a) menjadi f(c)
        }

        iteration++; // Naikkan jumlah iterasi
    }

    // Jika setelah mencapai batas iterasi maksimal akar belum ditemukan
    printf("Akar tidak ditemukan dalam %d iterasi.\n", max_iterations);
    return -1; // Program selesai dengan kode error karena akar tidak ditemukan
}
