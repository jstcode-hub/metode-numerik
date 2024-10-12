#include <stdio.h>
#include <math.h>

// Fungsi yang akan dicari akarnya
double f(double x)
{
    return x * x - 6 * x + 8;
}

// Fungsi untuk melakukan metode Regula Falsi
void regulaFalsi(double a, double b, double tol)
{
    if (f(a) * f(b) >= 0)
    {
        printf("Tidak ada akar di interval tersebut.\n");
        return;
    }

    double c;
    int iterasi = 1;

    // Header tabel
    printf("| Iterasi |      a      |    f(a)    |      b      |    f(b)    |      c      |    f(c)    |   |f(c)|   |\n");
    printf("-----------------------------------------------------------------------------------------------------\n");

    while (1)
    {
        // Menghitung c menggunakan metode Regula Falsi
        c = (a * f(b) - b * f(a)) / (f(b) - f(a));

        // Mencetak hasil per iterasi, termasuk nilai |f(c)|
        printf("|   %2d    |  %9.6f |  %9.6f |  %9.6f |  %9.6f |  %9.6f |  %9.6f | %9.6f |\n",
                    iterasi,    a,      f(a),     b,     f(b),     c,     f(c),    fabs(f(c)));

        // Tentukan subinterval yang baru
        if (f(c) * f(a) < 0)
        {
            b = c;
        }
        else
        {
            a = c;
        }

        // Jika |f(c)| sudah kurang dari toleransi, tampilkan iterasi ini
        if (fabs(f(c)) < tol)
        {
            break;
        }

        iterasi++;
    }

    printf("-----------------------------------------------------------------------------------------------------\n");
    printf("Akar yang ditemukan: %9.6f\n", c);
    printf("Nilai f(c): %9.6f\n", fabs(f(c)));
    printf("Jumlah iterasi: %d\n", iterasi);
}

int main()
{
    double a, b, tol;

    printf("Masukkan nilai awal a (batas bawah): ");
    scanf("%lf", &a);

    printf("Masukkan nilai awal b (batas atas): ");
    scanf("%lf", &b);

    printf("Masukkan batas toleransi error: ");
    scanf("%lf", &tol);

    printf("\n");

    regulaFalsi(a, b, tol);

    return 0;
}