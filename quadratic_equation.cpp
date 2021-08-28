#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <stdbool.h>
#include <assert.h>
#include "quadratic_tests.h"

const double PRECISION = 1e-5;

enum RootsNumber : int {
    NO_ROOTS,
    ONE_ROOT,
    TWO_ROOTS,
    INFINITE_NUMBER_OF_ROOTS
};

enum Unit_TestStatus : int {
    TESTS_PASSED,
    TESTS_TURNED_OFF,
};

enum Unit_Tests_Launch : int {
    NO,
    YES,
};


int quadratic_equation_solution(double a, double b, double c, double* root1, double* root2);
int linear_equation_solution(double b, double c, double* root1);
void welcome_words();
void bad_input_message();
void result_message(int roots_n, double root1, double root2);
void run_unit_tests(bool status);
void input_data(double* a, double* b, double* c);
void get_coefficient(double* coefficient);

/*!
    \brief This function returns the result of comparing two doubles.
    It takes two doubles.
*/

bool are_equal (double x, double y) {
    return abs(x - y) < PRECISION;
}

/*!
    \brief This function returns whether first argument is greater than second.\n
    It takes two doubles.
*/

bool more (double x, double y) {
    return (x >= y) || (are_equal(x, y));
}


int main() {
    double a = 0.0;
    double b = 0.0;
    double c = 0.0;
    double root1 = 0.0;
    double root2 = 0.0;
    int roots_number = NO_ROOTS;
    int test_status = TESTS_TURNED_OFF;

    run_unit_tests(YES);

    welcome_words();
    
    input_data(&a, &b, &c);

    roots_number = quadratic_equation_solution(a, b, c, &root1, &root2);

    result_message(roots_number, root1, root2);

    return 0;
}
/*!
    \brief This function solve quadratic equation.\n
    If you have coefficients of quadratic equation send them as arguments of this function.\n
    Also you need to send pointers to variables that store the roots.
*/

int quadratic_equation_solution(double a, double b, double c, double* root1, double* root2) { 
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

    if (is_linear) {
        number_of_roots = linear_equation_solution(b, c, root1);
        return number_of_roots;
    } else {
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

/*!
    \brief This function solve linear equation.\n
    This function works as quadratic_equation_solution(double a, double b, double c, double* root1, double* root2)\n
    If you have coefficients of linear equation send them as arguments of this function.\n
    Also you need to send pointers to variables that store the roots.
*/

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

/*!
    \brief This function prints greetings.
*/

void welcome_words() {
    printf("Hi! I'll help you with your equation.\n");
    printf("The equation should look like this: \"a * x^2 + b * x + c = 0\"\n");
    printf("Enter the coefficients of the quadratic eqution\n");
}

/*!
    \brief This function prints message about error in input data.
*/

void bad_input_message() {
    printf("Incorrect input.\n");
    printf("Try again:\n");
}

/*!
    \brief This function prints the result of solving the equation.
*/

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

/*! 
    \brief This function runs unit tests.\n
    It takes an argument which takes yes or no values.\n
    If "YES" is given it calls quadratic_tests() and handels the result.\n
    If "NO" is given it warns that tests are disabled.
*/

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

/*!
    \brief This function prints an interface for data entry.\n
    It takes points to variabels and puts values to variables.
*/

void input_data(double* a, double* b, double* c) {
    printf("Input a:\n");
    get_coefficient(a);

    printf("Input b:\n"); 
    get_coefficient(b);

    printf("Input c:\n");
    get_coefficient(c);
}

/*!
    \brief This function gets coefficient.\n
    It takes point to variable that stores the coefficient.
*/

void get_coefficient(double* coefficient) {
    bool reading_coeff = YES;
    while (reading_coeff) {
        if (scanf("%lf", coefficient) != 1) {
            bad_input_message();
            while (getchar() != '\n') {;}
        } else {
            int count_of_symbols = 0;
            while (getchar() != '\n') {
                count_of_symbols++;
            }
            if (count_of_symbols == 0) {
                reading_coeff = NO;
            } else {
                bad_input_message();
            }
        }
    } 
}