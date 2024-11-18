#include <stdio.h>
#include <math.h>
#define f(x) ((x) * (x) - 4 * (x) + 4)

void fibonacciSearch(double left, double right, double tol) {
    int steps = 1;
    double fib_prev2 = 1, fib_prev1 = 1, fib_current;
    while (fib_prev1 < (right - left) / tol) {
        fib_current = fib_prev1 + fib_prev2;
        fib_prev2 = fib_prev1;
        fib_prev1 = fib_current;
        steps++;
    }
    double x1 = left + (fib_prev2 / fib_current) * (right - left);
    double x2 = left + (fib_prev1 / fib_current) * (right - left);
    printf("Step\t\tx1\t\tf(x1)\tx2\t\tf(x2)\n");
    printf("----------------------------------------------------\n");
    for (int step = 1; step <= steps; step++) {
        if (f(x1) < f(x2)) {
            right = x2;
            x2 = x1;
            x1 = left + (fib_prev2 / fib_current) * (right - left);
        } else {
            left = x1;
            x1 = x2;
            x2 = left + (fib_prev1 / fib_current) * (right - left);
        }
        printf("%d\t\t%f\t%f\t%f\t%f\n", step, x1, f(x1), x2, f(x2));
    }
    double min_point = (left + right) / 2;
    printf("Minimum point: %f\n", min_point);
}

int main() {
    double left, right, tol;
    printf("Enter the interval [left, right]:\n");
    scanf("%lf %lf", &left, &right);
    printf("Enter the tolerance:\n");
    scanf("%lf", &tol);
    fibonacciSearch(left, right, tol);

    return 0;
}
