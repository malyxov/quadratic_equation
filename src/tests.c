#include <check.h>

#include "quadratic_equation.h"

#define EPS 1e-6

// ck_assert_double_eq_tol

START_TEST(basic_quad1) {
  quadratic_solution solution = solve_equation(1, 3, 2);
  quadratic_solution answer = {-2, -1, TWO_ROOTS};
  ck_assert_double_eq_tol(solution.x1, answer.x1, EPS);
  ck_assert_double_eq_tol(solution.x2, answer.x2, EPS);
  ck_assert_int_eq(solution.status, answer.status);
}
END_TEST

START_TEST(basic_quad2) {
  quadratic_solution solution = solve_equation(1.5, 5, -3.5);
  quadratic_solution answer = {-3.9274433, 0.5941099, TWO_ROOTS};
  ck_assert_double_eq_tol(solution.x1, answer.x1, EPS);
  ck_assert_double_eq_tol(solution.x2, answer.x2, EPS);
  ck_assert_int_eq(solution.status, answer.status);
}
END_TEST

START_TEST(negative_discriminant) {
  quadratic_solution solution = solve_equation(1, 2, 3);
  quadratic_solution answer = {NAN, NAN, NO_ROOTS};
  ck_assert(isnan(solution.x1));
  ck_assert(isnan(solution.x2));
  ck_assert_int_eq(solution.status, answer.status);
}
END_TEST

START_TEST(zero_discriminant) {
  quadratic_solution solution = solve_equation(3, 6, 3);
  quadratic_solution answer = {-1, NAN, ONE_ROOT};
  ck_assert_double_eq_tol(solution.x1, answer.x1, EPS);
  ck_assert(isnan(solution.x2));
  ck_assert_int_eq(solution.status, answer.status);
}
END_TEST

START_TEST(zero_c) {
  quadratic_solution solution = solve_equation(2.7, 4, 0);
  quadratic_solution answer = {-1.4814814, 0, TWO_ROOTS};
  ck_assert_double_eq_tol(solution.x1, answer.x1, EPS);
  ck_assert_double_eq_tol(solution.x2, answer.x2, EPS);
  ck_assert_int_eq(solution.status, answer.status);
}
END_TEST

START_TEST(zero_b1) {
  quadratic_solution solution = solve_equation(1, 0, 3);
  quadratic_solution answer = {NAN, NAN, NO_ROOTS};
  ck_assert(isnan(solution.x1));
  ck_assert(isnan(solution.x2));
  ck_assert_int_eq(solution.status, answer.status);
}
END_TEST

START_TEST(zero_b2) {
  quadratic_solution solution = solve_equation(1, 0, -3);
  quadratic_solution answer = {-1.7320508, 1.7320508, TWO_ROOTS};
  ck_assert_double_eq_tol(solution.x1, answer.x1, EPS);
  ck_assert_double_eq_tol(solution.x2, answer.x2, EPS);
  ck_assert_int_eq(solution.status, answer.status);
}
END_TEST

START_TEST(zero_a) {
  quadratic_solution solution = solve_equation(0, 7, 3);
  quadratic_solution answer = {-0.4285714, NAN, ONE_ROOT};
  ck_assert_double_eq_tol(solution.x1, answer.x1, EPS);
  ck_assert(isnan(solution.x2));
  ck_assert_int_eq(solution.status, answer.status);
}
END_TEST

START_TEST(zero_b_c) {
  quadratic_solution solution = solve_equation(3, 0, 0);
  quadratic_solution answer = {0, NAN, ONE_ROOT};
  ck_assert_double_eq_tol(solution.x1, answer.x1, EPS);
  ck_assert(isnan(solution.x2));
  ck_assert_int_eq(solution.status, answer.status);
}
END_TEST

START_TEST(zero_a_c) {
  quadratic_solution solution = solve_equation(0, 3, 0);
  quadratic_solution answer = {0, NAN, ONE_ROOT};
  ck_assert_double_eq_tol(solution.x1, answer.x1, EPS);
  ck_assert(isnan(solution.x2));
  ck_assert_int_eq(solution.status, answer.status);
}
END_TEST

START_TEST(zero_a_b) {
  quadratic_solution solution = solve_equation(0, 0, 4.7);
  quadratic_solution answer = {NAN, NAN, NO_ROOTS};
  ck_assert(isnan(solution.x1));
  ck_assert(isnan(solution.x2));
  ck_assert_int_eq(solution.status, answer.status);
}
END_TEST

START_TEST(zero_a_b_c) {
  quadratic_solution solution = solve_equation(0, 0, 0);
  quadratic_solution answer = {NAN, NAN, INFINITE_ROOTS};
  ck_assert(isnan(solution.x1));
  ck_assert(isnan(solution.x2));
  ck_assert_int_eq(solution.status, answer.status);
}
END_TEST

int main(void) {
  Suite *s1 = suite_create("tests");
  SRunner *sr = srunner_create(s1);
  int nf;

  TCase *tc1_1 = tcase_create("tests");
  suite_add_tcase(s1, tc1_1);

  tcase_add_test(tc1_1, basic_quad1);
  tcase_add_test(tc1_1, basic_quad2);
  tcase_add_test(tc1_1, negative_discriminant);
  tcase_add_test(tc1_1, zero_discriminant);
  tcase_add_test(tc1_1, zero_c);
  tcase_add_test(tc1_1, zero_b1);
  tcase_add_test(tc1_1, zero_b2);
  tcase_add_test(tc1_1, zero_a);
  tcase_add_test(tc1_1, zero_b_c);
  tcase_add_test(tc1_1, zero_a_c);
  tcase_add_test(tc1_1, zero_a_b);
  tcase_add_test(tc1_1, zero_a_b_c);

  srunner_run_all(sr, CK_ENV);
  nf = srunner_ntests_failed(sr);
  srunner_free(sr);

  return nf == 0 ? 0 : 1;
}