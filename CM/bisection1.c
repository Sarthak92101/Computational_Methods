#include <stdio.h>
#include <math.h>

#define f(x) (cos(x) - x * exp(x))

int main() {
    float x0, x1, x2, f0, f1, f2;
    int maxIterations, step = 1;

    printf("Enter two initial guesses:\n");
    scanf("%f %f", &x0, &x1);
    printf("Enter the number of iterations:\n");
    scanf("%d", &maxIterations);

    f0 = f(x0);
    f1 = f(x1);

    if (f0 * f1 > 0.0) {
        printf("Incorrect Initial Guesses. The function values must have opposite signs.\n");
        return -1;
    }

    printf("\nStep\t\tx0\t\tx1\t\tx2\t\tf(x2)\n");
    printf("-----------------------------------------------------------------------------------\n");

    while (step <= maxIterations) {
        x2 = (x0 + x1) / 2;
        f2 = f(x2);
        printf("%d\t\t%f\t%f\t%f\t%f\n", step, x0, x1, x2, f2);

        if (f0 * f2 < 0) {
            x1 = x2;
            f1 = f2;
        } else {
            x0 = x2;
            f0 = f2;
        }

        step++;
    }

    printf("------------------------------------------------------------------------\n");
    printf("Approximation of the root after %d iterations: %f\n", maxIterations, x2);

    return 0;
}
