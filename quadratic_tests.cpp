#include <assert.h>
#include <stdio.h>
#include <math.h>
#include "quadratic_equation.h"
#include "quadratic_tests.h"


int quadratic_tests() {
    int fails = 0;
    double root1 = 0.0;
    double root2 = 0.0;
    //                №  a   b   c   r1  r2  n_roots
    if (solution_test(1, 1, -5,  4,  4,  1,  2) == 0) fails++;
    if (solution_test(2, 1, -3,  2,  2,  1,  2) == 0) fails++;
    if (solution_test(3, 1, -13, 12, 12, 1,  2 ) == 0) fails++;
    if (solution_test(4, 1, -7,  12, 4,  3,  2) == 0) fails++;
    if (solution_test(7, 1,  2,  1,  -1, 0,  1) == 0) fails++;
    if (solution_test(8, 0,  0,  5,  0,  0,  0) == 0) fails++;
    if (solution_test(9, 0,  3,  0,  0,  0,  1) == 0) fails++;
    if (solution_test(10,0,  0,  0,  0,  0,  3) == 0) fails++;
    return fails;
}

int solution_test(int test_n, double a, double b, double c, double real_root1, double real_root2, int n_roots) {
    double root1 = 0.0;
    double root2 = 0.0;
    assert(isnan(a) == 0);
    assert(isnan(b) == 0);
    assert(isnan(c) == 0);
    assert(isfinite(a));
    assert(isfinite(b));
    assert(isfinite(c));
    int num_of_solutions = 0;
    num_of_solutions = quadratic_equation_solution(a, b, c, &root1, &root2);
    if (n_roots != num_of_solutions || !are_equal(real_root1, root1) || !are_equal(real_root2, root2)) {
        printf("TEST №%d failed.\n", test_n);
        printf("          root1 = %lf, root2 = %lf, n_roots = %d\n", root1, root2, num_of_solutions);
        printf("Should be root1 = %lf, root2 = %lf, n_roots = %d\n", real_root1, real_root2, n_roots);
        return 0;
    }
    return 1;
}