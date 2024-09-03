#include <stdio.h>
#include <math.h>

// Mendefinisikan fungsi f(x)
double f(double x)
{
    // return pow(x, 3) - 7 * x + 1;
    return x * x - 6 * x + 8;
}

int main()
{
    double a, b, c, toleransi;
    int iterasi = 0;

    a = 3.0;
    b = 6.0;
    toleransi = 0.0005;

    // Metode bisection
    do
    {
        c = (a + b) / 2;

        if (f(c) == 0.0)
        {
            break; // Akar ditemukan
        }
        else if (f(a) * f(c) < 0.0)
        {
            b = c; // Akar berada di antara a dan c
        }
        else
        {
            a = c; // Akar berada di antara c dan b
        }

        iterasi++;

    } while (fabs(f(c)) > toleransi); // Cek nilai error terhadap toleransi

    // Tampilkan hasil
    printf("Akar persamaan ditemukan pada x = %.5f setelah %d iterasi.\n", c, iterasi);
    printf("Nilai f(c) adalah %.5f\n", f(c));

    return 0;
}
