#include <stdio.h>
#include <math.h>

#define f(x) (cos(x) - x * exp(x)) // Define the function here

int main() {
    float x0, x1, x2, f0, f1, f2;
    int maxIterations, step = 1;

    printf("Enter two initial guesses:\n");
    scanf("%f %f", &x0, &x1);
    printf("Enter the number of iterations:\n");
    scanf("%d", &maxIterations);

    printf("\nStep\t\tx0\t\tx1\t\tx2\t\tf(x2)\n");
    printf("-------------------------------------------------\n");

    do {
        f0 = f(x0);
        f1 = f(x1);
        if (f1 - f0 == 0) {
            printf("Division by zero error.\n");
            return -1;
        }
        x2 = x1 - (f1 * (x1 - x0)) / (f1 - f0);
        f2 = f(x2);

        printf("%d\t\t%f\t%f\t%f\t%f\n", step, x0, x1, x2, f2);

        x0 = x1;
        x1 = x2;

        step++;
    } while (step <= maxIterations);

    printf("-------------------------------------------------\n");
    printf("Approximation of the root after %d iterations: %f\n", maxIterations, x2);

    return 0;
}
