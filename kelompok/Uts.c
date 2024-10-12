#include <stdio.h>
#include <math.h>

// Fungsi yang akan dicari akarnya
double f(double x)
{
    return x * x - 6 * x + 8;
}

// Fungsi turunan
double f_turunan(double x)
{
    return 2 * x - 6;
}

// Fungsi untuk melakukan Metode Tabel
void metode_tabel(double a, double b, int n)
{
    double h = (b - a) / n;
    double x, fx;
    int akarDitemukan = 0;

    printf("|    x    |   f(x)   |\n");
    printf("----------------------\n");

    for (int i = 0; i <= n; i++)
    {
        x = a + i * h;
        fx = f(x);
        printf("| %7.4f | %8.4f |\n", x, fx);

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

// Fungsi untuk melakukan metode biseksi
void bisection(double a, double b, double tol)
{
    if (f(a) * f(b) >= 0)
    {
        printf("Tidak ada akar di interval tersebut.\n");
        return;
    }

    double c;
    int iterasi = 1;

    printf("| Iterasi |      a     |    f(a)    |      b     |    f(b)    |      c     |    f(c)    |   b - a   |\n");
    printf("-----------------------------------------------------------------------------------------------------\n");

    while ((b - a) >= tol)
    {
        c = (a + b) / 2;
        printf("|   %2d    |  %9.6f |  %9.6f |  %9.6f |  %9.6f |  %9.6f |  %9.6f | %9.6f |\n",
                iterasi +1,    a,      f(a),     b,     f(b),     c,     f(c),    b - a);

        if (f(c) == 0.0)
            break;
        else if (f(c) * f(a) < 0)
            b = c;
        else
            a = c;
        iterasi++;
    }

    printf("-----------------------------------------------------------------------------------------------------\n");
    printf("Akar yang ditemukan: %9.6f\n", c);
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

    printf("| Iterasi |      a      |    f(a)    |      b      |    f(b)    |      c      |    f(c)    |   |f(c)|   |\n");
    printf("-----------------------------------------------------------------------------------------------------\n");

    do
    {
        c = (a * f(b) - b * f(a)) / (f(b) - f(a));
        printf("|   %2d    |  %9.6f |  %9.6f |  %9.6f |  %9.6f |  %9.6f |  %9.6f | %9.6f |\n",
                    iterasi,    a,      f(a),     b,     f(b),     c,     f(c),    fabs(f(c)));

        if (f(c) * f(a) < 0)
            b = c;
        else
            a = c;
        
        iterasi++;
    } while (fabs(f(c)) >= tol);

    printf("-----------------------------------------------------------------------------------------------------\n");
    printf("Akar yang ditemukan: %9.6f\n", c);
    printf("Nilai f(c): %9.6f\n", fabs(f(c)));
    printf("Jumlah iterasi: %d\n", iterasi - 1);
}

// Fungsi untuk melakukan metode Newton-Raphson
void newton_raphson(double tebakan_awal, double toleransi, int iterasi_maksimal)
{
    double x = tebakan_awal;
    int iterasi = 1;

    printf("| Iterasi |      x     |    f(x)    |    f'(x)   |    x_next   |    f(x_next) | \n");
    printf("------------------------------------------------------------------------------------\n");

    while (iterasi <= iterasi_maksimal)
    {
        double fx = f(x);
        double fpx = f_turunan(x);

        if (fabs(fpx) < 1e-10)
        {
            printf("Turunan mendekati nol, tidak dapat melanjutkan.\n");
            return;
        }

        double x_next = x - fx / fpx;
        double f_x_next = f(x_next);

        printf("|   %2d    |  %9.6f |  %9.6f |  %9.6f |  %9.6f |  %9.6f |\n",
                    iterasi,    x,      fx,     fpx,    x_next, f_x_next);

        if (fabs(f_x_next) <= toleransi)
        {
            printf("------------------------------------------------------------------------------------\n");
            printf("Akar yang ditemukan: %9.6f\n", x_next);
            return;
        }

        x = x_next;
        iterasi++;
    }

    printf("------------------------------------------------------------------------------------\n");
    printf("Maksimal iterasi tercapai tanpa menemukan akar yang cukup akurat.\n");
}

int main()
{
    int pilihan;
    double a, b, tol;
    int n, iterasi_maksimal;

    do {
        printf("\nPilih metode yang ingin digunakan:\n");
        printf("1. Metode Tabel\n");
        printf("2. Metode Biseksi\n");
        printf("3. Metode Regula-Falsi\n");
        printf("4. Metode Newton-Raphson\n");
        printf("0. Keluar\n");
        printf("Pilihan Anda: ");
        scanf("%d", &pilihan);

        switch(pilihan) {
            case 1:
                printf("\nMetode Tabel\n");
                printf("Masukkan batas bawah (a): ");
                scanf("%lf", &a);
                printf("Masukkan batas atas (b): ");
                scanf("%lf", &b);
                printf("Masukkan jumlah iterasi (n): ");
                scanf("%d", &n);
                metode_tabel(a, b, n);
                break;
            case 2:
                printf("\nMetode Biseksi\n");
                printf("Masukkan batas bawah (a): ");
                scanf("%lf", &a);
                printf("Masukkan batas atas (b): ");
                scanf("%lf", &b);
                printf("Masukkan toleransi: ");
                scanf("%lf", &tol);
                bisection(a, b, tol);
                break;
            case 3:
                printf("\nMetode Regula-Falsi\n");
                printf("Masukkan batas bawah (a): ");
                scanf("%lf", &a);
                printf("Masukkan batas atas (b): ");
                scanf("%lf", &b);
                printf("Masukkan toleransi: ");
                scanf("%lf", &tol);
                regulaFalsi(a, b, tol);
                break;
            case 4:
                printf("\nMetode Newton-Raphson\n");
                printf("Masukkan tebakan awal: ");
                scanf("%lf", &a);
                printf("Masukkan toleransi: ");
                scanf("%lf", &tol);
                printf("Masukkan maksimal iterasi: ");
                scanf("%d", &iterasi_maksimal);
                newton_raphson(a, tol, iterasi_maksimal);
                break;
            case 0:
                printf("Terima kasih telah menggunakan program ini.\n");
                break;
            default:
                printf("Pilihan tidak valid. Silakan coba lagi.\n");
        }
    } while (pilihan != 0);

    return 0;
}