// вынести тесты в отдельный файл (.h файл <- header <- объявления функций, .cpp <- файл с кодом)

#include <cstdio>
#include <stdlib.h>
#include <math.h>
#include <stdbool.h>
#include <assert.h>
#include "quadratic_tests.h"

const double PRECISION = 1e-7;

int quadratic_equation_solution(double a, double b, double c, double* root1, double* root2);
int linear_equation_solution(double b, double c, double* root1);


bool are_equal (double x, double y) {
    return abs(x - y) < PRECISION;
}

bool more (double x, double y) {
    return (x >= y) || (!are_equal(x, y));
}


enum RootsNumber : int {
    NO_ROOTS,
    ONE_ROOT,
    TWO_ROOTS,
    INFINITE_NUMBER_OF_ROOTS
};

int main() {
    double a = 0.0;
    double b = 0.0;
    double c = 0.0;
    double root1 = 0.0;
    double root2 = 0.0;
    int roots_number = NO_ROOTS;

    // quadratic_tests (); // Function that runs tests.
    
    printf("Hi! I'll help you with your equation.\n");
    printf("The equation should look like this: \"a * x^2 + b * x + c = 0\"\n");
    printf("Enter the coefficients of the quadratic eqution\n");
    printf("Input a:\n");
    fflush(stdout);
    while (scanf("%lf", &a) == 0) {
        printf("Incorrect input.\nTry again:\n");
        fflush(stdin);
    }
    printf("Input b:\n"); 
    fflush(stdout);
    while (scanf("%lf", &b) == 0) {
        printf("Incorrect input.\nTry again:\n");
        fflush(stdin);
    }
    printf("Input c:\n");
    fflush(stdout); 
    while (scanf("%lf", &c) == 0) {
        printf("Incorrect input.\nTry again:\n");
        fflush(stdin);
    }
    

    roots_number = quadratic_equation_solution(a, b, c, &root1, &root2);

    switch (roots_number) {
        case NO_ROOTS:
            printf("No roots");
            break;
        case ONE_ROOT:
            printf("Root is %.3lf\n", root1);
            break;
        case TWO_ROOTS:
            printf("First root is %.3lf\n", root1);
            printf("Second root is %.3lf\n", root2);
            break;
        case INFINITE_NUMBER_OF_ROOTS:
            printf("Infinite solutions\n");
            break;
        default:
            printf("ERROR: roots_number returns %d", roots_number);
            break;
    }

    return 0;
}


int quadratic_equation_solution(double a, double b, double c, double* root1, double* root2 ) { 
    assert(isnan(a) == 0);
    assert(isnan(b) == 0);
    assert(isnan(c) == 0);
    assert(isfinite(a));
    assert(isfinite(b));
    assert(isfinite(c));
    assert(root1 != NULL);
    assert(root2 != NULL);
    double discriminant = 0.0;
    double square_of_discriminant = 0.0;
    int number_of_roots = 0;
    bool are_real_roots = false;
    bool is_linear = are_equal(a, 0.0);

    if (is_linear) {
        number_of_roots = linear_equation_solution(b, c, root1);
        return number_of_roots;
    }
    else {
    discriminant = b * b - 4 * a * c;
    are_real_roots = more(discriminant, 0.0);
    if (!are_real_roots) {
        return NO_ROOTS;
    }
    square_of_discriminant = sqrt(discriminant);
    if (are_equal(discriminant, 0.0)) {
        *root1 = (-b + sqrt(discriminant)) / (2 * a);
        return ONE_ROOT;
    }
    *root1 = (-b + square_of_discriminant) / (2 * a);
    *root2 = (-b - square_of_discriminant) / (2 * a);
    return TWO_ROOTS;
    }
    
}


int linear_equation_solution(double b, double c, double* root1) {
    assert(isnan(b) == 0);
    assert(isnan(c) == 0);
    assert(root1 != NULL);
    assert(isfinite(b));
    assert(isfinite(c));

    if (are_equal(b, 0.0) and are_equal(c, 0.0)) {
        return INFINITE_NUMBER_OF_ROOTS;
    }
    if (are_equal(b, 0.0) and !are_equal(c, 0.0)) {
        return NO_ROOTS;
    }
    if (!are_equal(b, 0.0) and are_equal(c, 0.0)) {
        *root1 = 0;
        return ONE_ROOT;
    }
    *root1 = -c / b;
    return ONE_ROOT;
}