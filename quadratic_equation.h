#ifndef QUADRATIC_EQUATION_H_
#define QUADRATIC_EQUATION_H_

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
bool are_equal(double x, double y);
void welcome_words();
void bad_input_message();
void result_message(int roots_n, double root1, double root2);
void run_unit_tests(bool status);
void input_data(double* a, double* b, double* c);
void get_coefficient(double* coefficient);

#endif