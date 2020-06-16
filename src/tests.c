#include <stdio.h>
#include "atom.h"
#include "tests.h"

bool test_atom_new()
{
    bool test;

    int id = 1;
    double position[3] = {1.0, 2.0, 3.0};
    Atom atom = atom_new(id, position);

    test = (atom.id == 1);
    test = test && (atom.position[0] == 1.0);
    test = test && (atom.position[1] == 2.0);
    test = test && (atom.position[2] == 3.0);

    return test;
}

#define N_ATOM_TESTS 1
struct test atom_tests[] = {
    {test_atom_new, "test_atom_new"},
};

/* Testing Setup.
   Tests are represented as a {function_pointer, function_name_string} struct.
   Each function_pointer is a test function that returns a boolean, indicating
   a pass or fail.
   The functions below iterate over an array of such test objects and reports
   the results of calling each test.
*/
void _display_result(bool test_success, char *test_name)
{
    if (test_success)
    {
        printf("*");
    }
    else
    {
        printf("\nTest %s failed.\n", test_name);
    }
}

void _display_final_result(bool all_success, int n_pass_tests, int n_fail_tests)
{
    printf("\n");
    if (all_success)
    {
        printf("All tests pass (%d passed, %d failed).\n",
               n_pass_tests, n_fail_tests);
    }
    else
    {
        printf("Test failure (%d passed, %d failed).\n",
               n_pass_tests, n_fail_tests);
    }
}

void run_tests(struct test tests[], int n_tests)
{
    bool test_success;
    bool all_success = true;
    int n_pass_tests = 0;
    int n_fail_tests = 0;
    for (int i = 0; i < n_tests; i++)
    {
        test_success = (tests[i].test_f)();
        n_pass_tests += test_success;
        n_fail_tests += 1 - test_success;
        _display_result(test_success, tests[i].name);
        all_success = all_success && test_success;
    }
    _display_final_result(all_success, n_pass_tests, n_fail_tests);
}

void run_all()
{
    run_tests(atom_tests, N_ATOM_TESTS);
}