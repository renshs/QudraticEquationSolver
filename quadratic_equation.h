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

/*!
    \brief This function solve quadratic equation.\n
    This function takes coefficients a, b, c and two pointers to variables that contains roots.
    \param[in] a First coefficient of quadratic equation
    \param[in] b Second coefficint of quadratic equation
    \param[in] c Third coefficint of quadratic equation
    \param[out] root1 It is pointer to variable which contains first root
    \param[out] root2 It is pointer to variable which contains second root
*/
int quadratic_equation_solution(double a, double b, double c, double* root1, double* root2);


/*!
    \brief This function solve linear equation.\n
    This function works as quadratic_equation_solution(double a, double b, double c, double* root1, double* root2)\n
    If you have coefficients of linear equation send them as arguments of this function.\n
    This function takes coefficients a, b and pointer to variable that contains root.
    \param[in] b It is variable coefficient
    \param[in] c It is intercept term
    \param[out] root1 Is pointer to variable which contains root
*/
int linear_equation_solution(double b, double c, double* root1);


/*!
    \brief This function returns a result of comparing two doubles.
    It takes two doubles.
    \param[in] x First double to compare
    \param[in] y Second double to compare
    \return This function returns number of roots of linear equation
*/
bool are_equal(double x, double y);


/*!
    \brief This function tells us is first double greater or equal than second double
    \param[in] x First double, which should be greater
    \param[in] y Second double, which should be less
*/
bool greater_or_equal (double x, double y);


/*!
    \brief This function prints greetings.
*/
void welcome_words();


/*!
    \brief This function prints an interface for data entry.\n
    It takes pointers to variabels and puts values to variables.
*/
void input_data(double* a, double* b, double* c);


/*!
    \brief This function gets the coefficient from the input.\n
    It takes a pointer to variable that stores the coefficient.
    \param[in] coefficient Coefficient to read
*/
void get_coefficient(double* coefficient);



/*!
    \brief This function prints message about error in input data.
*/

void bad_input_message();


/*!
    \brief This function prints the result of solving the equation.
    It takes roots number and roots.
*/
void result_message(int roots_n, double root1, double root2);


/*! 
    \brief This function runs unit tests.\n
    It takes an argument which takes YES or NO values.\n
    If "YES" is given it calls quadratic_tests() and handels the result.\n
    If "NO" is given it warns that tests are disabled.
*/
void run_unit_tests(bool status);


#endif // QUADRATIC_EQUATION_H_