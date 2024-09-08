#include <stdio.h>
#include <math.h>

// Fungsi f(x) = x^2 - 6x + 8
double f(double x)
{
    return x * x - 6 * x + 8;
}

int main()
{
    double a = 3.0, b = 6.0, c, toleransi = 0.01;
    int iterasi = 0;

    // Pastikan bahwa f(a) * f(b) < 0
    if (f(a) * f(b) >= 0)
    {
        printf("Tidak ada akar dalam interval ini.\n");
        return 1;
    }

    printf("Iterasi\t\ta\t\tb\t\tc\t\tf(c)\n");
    do
    {
        // Hitung nilai c dengan metode Regula Falsi
        c = b - (f(b) * (b - a)) / (f(b) - f(a));
        double fc = f(c);

        // Tampilkan hasil iterasi
        printf("%d\t\t%.6f\t%.6f\t%.6f\t%.6f\n", iterasi + 1, a, b, c, fc);

        if (fabs(fc) <= toleransi)
        {
            break; // Akar ditemukan
        }

        // Tentukan interval baru
        if (f(a) * fc < 0)
        {
            b = c;
        }
        else
        {
            a = c;
        }

        iterasi++;

    } while (fabs(f(c)) > toleransi); // Ulangi sampai toleransi tercapai

    // Tampilkan hasil akhir
    printf("\nAkar persamaan ditemukan pada x = %.6f setelah %d iterasi.\n", c, iterasi);
    printf("Nilai f(c) adalah %.6f\n", f(c));

    return 0;
}
