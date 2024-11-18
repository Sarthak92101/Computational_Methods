#include <stdio.h>
int main() {
    int n, i, j;
    float x[10], y[10], xp, yp = 0, p;

    // Input number of data points
    printf("Enter the number of data points: ");
    scanf("%d", &n);

    // Input data points (x[i], y[i])
    printf("Enter the data points (x and y):\n");
    for (i = 0; i < n; i++) {
        printf("x[%d] = ", i);
        scanf("%f", &x[i]);
        printf("y[%d] = ", i);
        scanf("%f", &y[i]);
    }

    // Input the value to interpolate
    printf("Enter the value of x to find y: ");
    scanf("%f", &xp);

    // Implement Lagrange Interpolation
    for (i = 0; i < n; i++) {
        p = 1; // Initialize the product term

        for (j = 0; j < n; j++) {
            if (j != i) {
                p *= (xp - x[j]) / (x[i] - x[j]);
            }
        }

        yp += p * y[i]; // Add the term to the interpolated value
    }

    // Output the result
    printf("The interpolated value at x = %f is y = %f\n", xp, yp);

    return 0;
}
