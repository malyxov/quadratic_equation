#include "quadratic_equation.h"

#include <math.h>

quadratic_solution solve_equation(double a, double b, double c) {
  quadratic_solution solution = {NAN, NAN, -1};
  if (a == 0) {
    if (b == 0) {
      solution.status = (c == 0) ? INFINITE_ROOTS : NO_ROOTS;
    } else {  // a==0, b!=0
      solution.x1 = -c / b;
      solution.status = ONE_ROOT;
    }
  } else {  // a!=0
    double discriminant = b * b - 4 * a * c;
    if (discriminant < 0) {
      solution.status = NO_ROOTS;
    } else if (discriminant == 0) {
      solution.x1 = -b / (2 * a);
      solution.status = ONE_ROOT;
    } else {
      solution.x1 = (-b - sqrt(discriminant)) / (2 * a);
      solution.x2 = (-b + sqrt(discriminant)) / (2 * a);
      solution.status = TWO_ROOTS;
    }
  }
  return solution;
}