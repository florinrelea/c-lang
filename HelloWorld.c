#include <stdio.h>
#include <math.h>

int main() {
  double a;
  double b;
  double c;

  printf("--> Find the triangle's C <--\n");

  printf("Enter side A: ");
  scanf("%lf", &a);

  printf("Enter side B: ");
  scanf("%lf", &b);

  c = sqrt(a * a + b * b);

  printf("The result is %lf", c);

  return 0;
}
