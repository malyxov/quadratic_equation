#include "quadratic_equation.h"

#include <math.h>

QuadraticSolution solve_equation(double a, double b, double c) {
  QuadraticSolution result = {-1, NAN, NAN};

  if (a == 0) {
    if (b == 0) {
      result.status = (c == 0) ? INFINITE_ROOTS : NO_ROOTS;
    } else {
      result.x1 = -c / b;
      result.status = ONE_ROOT;
    }
  } else {  // a!=0
    double discriminant = b * b - 4 * a * c;
    if (discriminant < 0) {
      result.status = NO_ROOTS;
    } else if (discriminant == 0) {
      result.x1 = -b / (2 * a);
      result.status = ONE_ROOT;
    } else {
      result.x1 = (-b - sqrt(discriminant)) / (2 * a);
      result.x2 = (-b + sqrt(discriminant)) / (2 * a);
      result.status = TWO_ROOTS;
    }
  }
  return result;
}
