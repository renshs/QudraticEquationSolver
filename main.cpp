#include <stdio.h>
#include "quadratic_equation.h"

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