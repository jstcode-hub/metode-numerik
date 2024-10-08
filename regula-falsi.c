#include <stdio.h>
#include <math.h>

// Definisikan fungsi f(x) = 5x * e^(-x) - 1
double f(double x)
{
    return x * x - 2 * x - 8;
}

int main()
{
    double a, b, c, fa, fb, fc;
    double tolerance = 0.01;  // Toleransi error
    int max_iterations = 100; // Batas maksimal iterasi
    int iteration = 0;

    // Masukkan nilai awal interval [a, b]
    printf("Masukkan nilai awal a: ");
    scanf("%lf", &a);
    printf("Masukkan nilai awal b: ");
    scanf("%lf", &b);

    fa = f(a);
    fb = f(b);

    // Pastikan f(a) dan f(b) berlawanan tanda
    if (fa * fb > 0)
    {
        printf("Kesalahan: f(a) dan f(b) harus memiliki tanda berlawanan.\n");
        return -1;
    }

    // Iterasi Regula Falsi
    while (iteration < max_iterations)
    {
        // Hitung c menggunakan formula Regula Falsi
        c = b - (fb * (b - a)) / (fb - fa);
        fc = f(c);

        printf("Iterasi %d: c = %lf, f(c) = %lf\n", iteration + 1, c, fc);

        // Periksa apakah solusi telah ditemukan dengan toleransi yang ditentukan
        if (fabs(fc) < tolerance)
        {
            printf("Akar ditemukan: %lf\n", c);
            return 0;
        }

        // Tentukan interval baru [a, c] atau [c, b]
        if (fa * fc < 0)
        {
            b = c;
            fb = fc;
        }
        else
        {
            a = c;
            fa = fc;
        }

        iteration++;
    }

    printf("Akar tidak ditemukan dalam %d iterasi.\n", max_iterations);
    return -1;
}
