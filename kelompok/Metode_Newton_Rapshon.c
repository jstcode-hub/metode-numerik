#include <stdio.h>
#include <math.h>

// Fungsi yang akan dicari akarnya
double fungsi(double x)
{
    return x * x - 6 * x + 8;
}

// Turunan dari fungsi
double fungsi_turunan(double x)
{
    return 2 * x - 6;
}

// Fungsi untuk melakukan metode Newton-Raphson
void newton_raphson(double tebakan_awal, double toleransi, int iterasi_maksimal)
{
    double x = tebakan_awal;
    int iterasi = 1;

    // Header tabel
    printf("| Iterasi |      x     |    f(x)    |    f'(x)   |    x_next   |    f(x_next) | \n");
    printf("------------------------------------------------------------------------------------\n");

    while (iterasi <= iterasi_maksimal)
    {
        double fx = fungsi(x);
        double fpx = fungsi_turunan(x);

        // Cek apakah turunan mendekati nol atau negatif
        if (fabs(fpx) < 1e-10)
        {
            printf("Turunan mendekati nol, tidak dapat melanjutkan.\n");
            return;
        }
        if (fpx < 0)
        {
            printf("Turunan negatif, tidak dapat melanjutkan.\n");
            return;
        }

        double x_next = x - fx / fpx;
        double f_x_next = fungsi(x_next);

        // Mencetak hasil per iterasi
        printf("|   %2d    |  %9.6f |  %9.6f |  %9.6f |  %9.6f |  %9.6f |\n",
                    iterasi,    x,      fx,     fpx,    x_next, f_x_next);

        // Cek apakah nilai f(x_next) sudah dalam toleransi
        if (fabs(f_x_next) <= toleransi)
        {
            printf("------------------------------------------------------------------------------------\n");
            printf("Akar yang ditemukan: %9.6f\n", x_next);
            return;
        }

        // Update nilai x untuk iterasi berikutnya
        x = x_next;
        iterasi++;
    }

    printf("------------------------------------------------------------------------------------\n");
    printf("Maksimal iterasi tercapai tanpa menemukan akar yang cukup akurat.\n");
}

int main()
{
    double tebakan_awal, toleransi;
    int iterasi_maksimal;

    printf("Masukkan nilai tebakan awal: ");
    scanf("%lf", &tebakan_awal);

    printf("Masukkan nilai toleransi: ");
    scanf("%lf", &toleransi);

    printf("Masukkan maksimal iterasi: ");
    scanf("%d", &iterasi_maksimal);

    printf("Metode Newton-Raphson untuk F(x) = X^2 - 6X + 8\n");

    newton_raphson(tebakan_awal, toleransi, iterasi_maksimal);

    return 0;
}