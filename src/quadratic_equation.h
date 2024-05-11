#ifndef SRC_QUADRATIC_EQUATION_H_
#define SRC_QUADRATIC_EQUATION_H_

// Перечень статусов корней
#define NO_ROOTS 0
#define ONE_ROOT 1
#define TWO_ROOTS 2
#define INFINITE_ROOTS 8

// Определение структуры для хранения решения
typedef struct {
  double x1;
  double x2;
  int status;
} quadratic_solution;

quadratic_solution solve_equation(double a, double b, double c);

#endif  // SRC_QUADRATIC_EQUATION_H_