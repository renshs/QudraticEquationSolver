#include <assert.h>
#include <stdio.h>
#include <math.h>
#include "quadratic_equation.h"
#include "quadratic_tests.h"

/*!
    \brief This function runs tests of quadratic_equation_solution(double a, double b, double c, double* root1, double* root2) \n
    If all tests pass it returns 0. \n
    Otherwise it returns number of failed tests.
*/

int quadratic_tests() {

    int fails = 0;

    //                №  a   b   c
    if (solution_test(1, 1, -5,  4) == 0) fails++;
    if (solution_test(2, 1, -3,  2) == 0) fails++;
    if (solution_test(3, 1, -13, 12) == 0) fails++;
    if (solution_test(4, 1, -7,  12) == 0) fails++;
    if (solution_test(7, 1,  2,  1) == 0) fails++;
    if (solution_test(8, 0,  0,  5) == 0) fails++;
    if (solution_test(9, 0,  3,  0) == 0) fails++;
    if (solution_test(10,0,  0,  0) == 0) fails++;

    return fails;
}

/*!
    \brief This function checks the solution of a specific equatioin.\n
    It takes the test number and coefficients.\n
    If solution is wrong, it prints test number and solution that our function recieved.
*/

int solution_test(int test_n, double a, double b, double c) {
    assert(isnan(a) == 0);
    assert(isnan(b) == 0);
    assert(isnan(c) == 0);
    assert(isfinite(a));
    assert(isfinite(b));
    assert(isfinite(c));

    double root1 = 0.0;
    double root2 = 0.0;
    int num_of_solutions = 0;
    bool root1_check = false;
    bool root2_check = false;

    num_of_solutions = quadratic_equation_solution(a, b, c, &root1, &root2);

    root1_check = are_equal((root1 * root1 * a + root1 * b + c), 0.0);
    root2_check = are_equal((root2 * root2 * a + root2 * b + c), 0.0);
    switch (num_of_solutions)
    {
    case 0:
        if (!root1_check && !root2_check) {
            return 1;
        } else {
            return 0;
        }
    case 1:
        if (root1_check) {
            return 1;
        } else {
            return 0;
        }
    case 2:
        if (root1_check && root2_check) {
            return 1;
        } else {
            return 0;
        }
    case 3:
        if (root1_check && root2_check) {
            return 1;
        } else {
            return 0;
        }
    default:
        return 0;
        break;
    }
    return 0;
}