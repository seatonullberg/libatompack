#include <math.h>
#include <stdio.h>
#include "atom.h"
#include "constants.h"
#include "linalg.h"
#include "tests.h"
#include "util.h"

/*
    `atom` module tests
*/

bool test_atom_new()
{
    bool test;

    int id = 1;
    double position[3] = {1.0, 2.0, 3.0};
    Atom *atom = atom_new(id, position);

    test = (atom_get_id(atom) == 1);
    test = test && (atom_get_position(atom)[0] == 1.0);
    test = test && (atom_get_position(atom)[1] == 2.0);
    test = test && (atom_get_position(atom)[2] == 3.0);

    atom_free(atom);
    return test;
}

bool test_atom_collection_new() {
    bool test;

    int id = 1;
    double position[3] = {1.0, 2.0, 3.0};
    Atom *atom = atom_new(id, position);
    Atom *atoms[] = {atom};
    double basis[3][3] = {
        {1.0, 0.0, 0.0},
        {0.0, 1.0, 0.0},
        {0.0, 0.0, 1.0},
    };
    size_t length = 1;
    size_t capacity = 1;
    AtomCollection *collection = atom_collection_new(basis, length, capacity, atoms);

    test = (collection->basis[0][0] == 1.0);
    test = test && (collection->basis[1][1] == 1.0);
    test = test && (collection->basis[2][2] == 1.0);
    test = test && (collection->atoms[0]->id == 1);
    test = test && (collection->atoms[0]->position[0] == 1.0);
    test = test && (collection->atoms[0]->position[1] == 2.0);
    test = test && (collection->atoms[0]->position[2] == 3.0);

    atom_collection_free(collection);
    return test;
}

#define N_ATOM_TESTS 2
struct test atom_tests[] = {
    {test_atom_new, "test_atom_new"},
    {test_atom_collection_new, "test_atom_collection_new"},
};

/*
    `linalg` module tests
*/

bool test_dist()
{
    bool test;

    double a[3] = {1.0, 2.0, 3.0};
    double b[3] = {3.0, 2.0, 1.0};

    test = (dist(a, b, 3) == sqrt(8.0));

    return test;
}

bool test_dot() {
    bool test;

    double a[3] = {1.0, 2.0, 3.0};
    double b[3] = {3.0, 2.0, 1.0};

    test = (dot(a, b, 3) == 10);

    return test;
}

bool test_norm() {
    bool test;

    double a[3] = {1.0, 2.0, 3.0};
    
    test = (norm(a, 3) == sqrt(14.0));

    return test;
}

#define N_LINALG_TESTS 3
struct test linalg_tests[] = {
    {test_dist, "test_dist"},
    {test_dot, "test_dot"},
    {test_norm, "test_norm"},
};

/*
    `util` module tests
*/

bool test_metric_tensor()
{
    bool test;

    double a, b, c, alpha, beta, gamma;
    a = 2.0;
    b = 2.0;
    c = 2.0;
    alpha = PI / 2.0;
    beta = PI / 2.0;
    gamma = PI / 2.0;
    double m[3][3];
    metric_tensor(a, b, c, alpha, beta, gamma, m);

    test = (m[0][0] == 4.0);
    test = test && (m[1][1] == 4.0);
    test = test && (m[2][2] == 4.0);

    return test;
}

#define N_UTIL_TESTS 1
struct test util_tests[] = {
    {test_metric_tensor, "test_metric_tensor"},
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
    run_tests(linalg_tests, N_LINALG_TESTS);
    run_tests(util_tests, N_UTIL_TESTS);
}