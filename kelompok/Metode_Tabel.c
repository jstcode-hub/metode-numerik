#include <stdio.h>
#include <math.h>

// Fungsi yang akan dicari akarnya
double f(double x)
{
    return x * x - 6 * x + 8;
}

// Fungsi untuk melakukan Metode Tabel
void metode_tabel(double a, double b, int n)
{
    // a adalah batas bawah, b adalah batas atas, n adalah jumlah iterasi
    
    // Hitung nilai h
    double h = (b - a) / n;
    // Variabel untuk menyimpan nilai x dan f(x)
    double x, fx;
    // Variabel untuk menandai perubahan tanda
    int akarDitemukan = 0;

    // Header tabel
    printf("|    x    |   f(x)   |\n");
    printf("----------------------\n");

    for (int i = 0; i <= n; i++)
    {
        x = a + i * h;
        fx = f(x);

        // Tampilkan nilai x dan f(x) di setiap iterasi
        printf("| %7.4f | %8.4f |\n", x, fx);

        // Periksa perubahan tanda
        if (i > 0 && fx * f(a + (i-1) * h) < 0)
        {
            if (!akarDitemukan)
            {
                printf("----------------------\n");
                printf("Akar ditemukan antara x = %.4f dan x = %.4f\n", a + (i-1) * h, x);
                akarDitemukan = 1;
            }
        }
    }

    printf("----------------------\n");
    if (!akarDitemukan)
    {
        printf("Akar tidak ditemukan dalam interval yang diberikan.\n");
    }
}

int main()
{
    double a, b;
    int n;

    printf("Masukkan batas bawah (a): ");
    scanf("%lf", &a);

    printf("Masukkan batas atas (b): ");
    scanf("%lf", &b);

    printf("Masukkan jumlah iterasi (n): ");
    scanf("%d", &n);

    printf("Nilai h adalah %.4f\n", (b - a) / n);

    // Menjalankan metode tabel
    metode_tabel(a, b, n);

    return 0;
}