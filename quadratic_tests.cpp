#include <assert.h>
#include <stdio.h>
#include "quadratic_equation.h"
#include "quadratic_tests.h"


void quadratic_tests() {
    double root1 = 0.0;
    double root2 = 0.0;
    assert(solution_test(1, -5, 4, &root1, &root2, 4, 1) == 2);
    assert(solution_test(1, -3, 2, &root1, &root2, 2, 1));
    assert(solution_test(1, -13, 12, &root1, &root2, 12, 1));
    assert(solution_test(1, -7, 12, &root1, &root2, 4, 3));
    assert(solution_test(0, 0, 0, &root1, &root2, 0, 0) == 3);
    assert(solution_test(1, -12, 35, &root1, &root2, 7, 5) == 2);
}

int solution_test(double a, double b, double c, double* root1, double* root2, double real_root1, double real_root2) {
    int num_of_solutions = 0;
    *root1 = 0.0;
    *root2 = 0.0;
    num_of_solutions = quadratic_equation_solution(a, b, c, root1, root2);
    assert(*root1 == real_root1);
    assert(*root2 == real_root2);
    return num_of_solutions;
}