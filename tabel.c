#include <stdio.h>
#include <math.h>

// Definisi fungsi f(x)
double f(double x)
{
    return 5 * x * exp(-x) - 1;
}

int main()
{
    double a = 0.0, b = 0.5, step = 0.05;
    double x, fx, fx_next;

    printf("|   x    |   f(x)    |\n");
    printf("----------------------\n");

    for (x = a; x <= b; x += step)
    {
        fx = f(x);
        fx_next = f(x + step);

        // Mencetak nilai x dan f(x)
        printf("| %6.2f | %9.6f |\n", x, fx);

        // Jika tanda f(x) dan f(x + step) berbeda, maka ada akar di antara keduanya
        if (fx * fx_next < 0)
        {
            printf("Akar ditemukan di antara x = %.2f dan x = %.2f\n", x, x + step);
        }
    }

    return 0;
}
