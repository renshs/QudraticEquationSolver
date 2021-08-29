//! @mainpage
//! - main.cpp
//! - quadratic_equation.h


#include <stdio.h>
#include "quadratic_equation.h"

// #ifdef TESTS
// #define UNIT_TESTS(smth) run_unit_tests(smth)
// #else UNIT_TEST(smth) ;
// #endif

int main() {
    // int test_status = TESTS_TURNED_OFF;

    // UNIT_TESTS(smth);
    run_unit_tests(YES);

    welcome_words();
    
    double a = 0.0;
    double b = 0.0;
    double c = 0.0;
    input_data(&a, &b, &c);

    double root1 = 0.0;
    double root2 = 0.0;

    int roots_number = NO_ROOTS;
    roots_number = quadratic_equation_solution(a, b, c, &root1, &root2);

    result_message(roots_number, root1, root2);

    return 0;
}