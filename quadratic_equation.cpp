#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <stdbool.h>
#include <assert.h>
#include "quadratic_tests.h"
#include "quadratic_equation.h"

const double PRECISION = 1e-6;


bool are_equal (double x, double y) {
    return abs(x - y) < PRECISION;
}


bool greater_or_equal (double x, double y) {
    return (x > (y - PRECISION));
}


int quadratic_equation_solution(double a, double b, double c, double* root1, double* root2) { 
    assert(isnan(a) == 0);
    assert(isnan(b) == 0);
    assert(isnan(c) == 0);
    assert(isfinite(a));
    assert(isfinite(b));
    assert(isfinite(c));
    assert(root1);
    assert(root2);
    assert(root1 != root2);

    int number_of_roots = 0;
    if (are_equal(c, 0.0)) {
        *root2 = 0;
        number_of_roots = linear_equation_solution(a, b, root1);

        if (number_of_roots == INFINITE_NUMBER_OF_ROOTS) {
            return INFINITE_NUMBER_OF_ROOTS;
        }
        if (are_equal(*root1, 0.0)) {
            return ONE_ROOT;
        }
        if (number_of_roots == ONE_ROOT) {
            return TWO_ROOTS;
        }
    }

    bool is_linear = are_equal(a, 0.0);
    if (is_linear) {
        number_of_roots = linear_equation_solution(b, c, root1);

        return number_of_roots;
    } else {
        double discriminant = b * b - 4 * a * c;

        bool are_real_roots = false;
        are_real_roots = greater_or_equal(discriminant, 0.0);
        if (!are_real_roots) {
            return NO_ROOTS;
        }

        double square_of_discriminant = sqrt(discriminant);

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
    assert(root1);
    assert(isfinite(b));
    assert(isfinite(c));

    if (are_equal(b, 0.0) && are_equal(c, 0.0)) {
        return INFINITE_NUMBER_OF_ROOTS;
    }

    if (are_equal(b, 0.0) && !are_equal(c, 0.0)) {
        return NO_ROOTS;
    }

    if (!are_equal(b, 0.0) && are_equal(c, 0.0)) {
        *root1 = 0;

        return ONE_ROOT;
    }

    *root1 = -c / b;

    return ONE_ROOT;
}


void welcome_words() {
    printf("Hi! I'll help you with your equation.\n");
    printf("The equation should look like this: \"a * x^2 + b * x + c = 0\"\n");
    printf("Enter the coefficients of the quadratic eqution\n");
}


void bad_input_message() {
    printf("Incorrect input.\n");
    printf("Try again:\n");
}


void result_message(int roots_n, double root1, double root2) {
    switch (roots_n) {
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
            printf("ERROR: roots_number returns %d", roots_n);
            break;
    }
}


void run_unit_tests(bool status) {
    if (status) {
        switch (quadratic_tests()) {
            case TESTS_PASSED:
                printf("All right, All right, All right!!!\nAll tests passed\n\n");
                break;
            case TESTS_TURNED_OFF:
                printf("Tests turned off.\n\n");
                break;
            default:
                printf("Sadly, tests failed(\n\n");
                break;
        }
    }
}


void input_data(double* a, double* b, double* c) {
    printf("Input a:\n");
    get_coefficient(a);

    printf("Input b:\n"); 
    get_coefficient(b);

    printf("Input c:\n");
    get_coefficient(c);
}


void get_coefficient(double* coefficient) {
    bool reading_coeff = YES;
    while (reading_coeff) {
        if (scanf("%lf", coefficient) != 1) {
            bad_input_message();
            while (getchar() != '\n') {;}
        } else {
            int number_of_symbols = 0;
            while (getchar() != '\n') {
                number_of_symbols++;
            }
            if (number_of_symbols == 0) {
                reading_coeff = NO;
            } else {
                bad_input_message();
            }
        }
    } 
}