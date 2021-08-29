#ifndef QUADRATIC_TESTS_H_
#define QUADRATIC_TESTS_H_

/*!
    \brief This function runs tests of quadratic_equation_solution(double a, double b, double c, double* root1, double* root2) function\n
    It calls solution_test() function 
*/
int quadratic_tests();


/*!
    \brief This function tests solution of quadratic equation. \n
    It takes test number, coefficients a, b and c; refernce roots; number of roots.
*/
int solution_test(int test_n, double a, double b, double c, double real_root1, double real_root2, int n_roots);


#endif // QUADRATIC_TESTS_H_