#include <stdio.h>
#include <math.h>

#define f(x) (x * x * x - x - 1)       // Define the function here
#define f_derivative(x) (3 * x * x - 1) // Define its derivative here

int main() {
    float x0, x1, f0, f_deriv, tolerance;
    int step = 1;

    printf("Enter the initial guess:\n");
    scanf("%f", &x0);
    printf("Enter the tolerance:\n");
    scanf("%f", &tolerance);

    printf("\nStep\t\tx0\t\tf(x0)\t\tf'(x0)\t\tx1\n");
    printf("-------------------------------------------------\n");

    do {
        f0 = f(x0);
        f_deriv = f_derivative(x0);

        if (f_deriv == 0) {
            printf("Division by zero error.\n");
            return -1;
        }

        x1 = x0 - f0 / f_deriv;

        printf("%d\t\t%f\t%f\t%f\t%f\n", step, x0, f0, f_deriv, x1);

        x0 = x1;
        step++;
    } while (fabs(f0) > tolerance);

    printf("-------------------------------------------------\n");
    printf("Root found at: %f\n", x1);

    return 0;
}
