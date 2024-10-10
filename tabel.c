#include <stdio.h> // Pustaka untuk fungsi input/output standar (printf, scanf)
#include <math.h>  // Pustaka untuk fungsi matematika (fabs)

// Fungsi yang akan dicari akarnya
// Fungsi ini mendefinisikan persamaan f(x) = x^2 - 3x + 2, yang akar dari persamaannya akan dicari
double f(double x)
{
    return x * x - 3 * x + 2; // Mengembalikan nilai f(x) untuk x tertentu
}

// Fungsi untuk melakukan Metode Tabel
// Metode Tabel mencari akar dengan memeriksa perubahan tanda pada interval tertentu
void tabel_method(double a, double b, double h)
{
    double x = a;   // Inisialisasi titik awal interval
    double fx, fxh; // Variabel untuk menyimpan nilai f(x) dan f(x+h)

    // Header tabel untuk menampilkan hasil
    printf("|    x    |   f(x)   |\n");
    printf("----------------------\n");

    // Loop untuk iterasi dari titik awal a hingga titik akhir b dengan langkah h
    while (x <= b)
    {
        fx = f(x);      // Hitung f(x) untuk titik saat ini
        fxh = f(x + h); // Hitung f(x+h) untuk titik berikutnya

        // Tampilkan nilai f(x) di setiap iterasi
        printf("| %7.4f | %8.4f |\n", x, fx);

        // Periksa apakah f(x) dan f(x+h) berlawanan tanda
        // Jika ya, maka ada akar di antara x dan x+h
        if (fx * fxh < 0)
        {
            // Jika tanda berlawanan, maka akar ditemukan di antara interval tersebut
            printf("----------------------\n");
            printf("Akar ditemukan antara x = %.4f dan x = %.4f\n", x, x + h);

            // Tentukan titik mana yang lebih dekat dengan akar berdasarkan nilai mutlak f(x)
            if (fabs(fx) < fabs(fxh))
            {
                printf("Akar lebih dekat ke x = %.4f\n", x);
            }
            else
            {
                printf("Akar lebih dekat ke x = %.4f\n", x + h);
            }
            return; // Keluar dari fungsi karena akar sudah ditemukan
        }

        // Tingkatkan nilai x dengan langkah h
        x += h;
    }

    // Jika tidak ada akar yang ditemukan setelah seluruh interval diperiksa
    printf("----------------------\n");
    printf("Akar tidak ditemukan dalam interval yang diberikan.\n");
}

int main()
{
    double a, b, h; // Variabel untuk menyimpan nilai interval [a, b] dan langkah h

    // Input dari pengguna untuk nilai interval [a, b] dan langkah h
    printf("Masukkan nilai awal a: ");
    scanf("%lf", &a); // Baca nilai a

    printf("Masukkan nilai awal b: ");
    scanf("%lf", &b); // Baca nilai b

    printf("Masukkan nilai langkah h: ");
    scanf("%lf", &h); // Baca nilai langkah h

    // Menjalankan metode tabel dengan parameter [a, b] dan langkah h yang diinput oleh pengguna
    tabel_method(a, b, h);

    return 0; // Program selesai
}
