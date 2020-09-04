#include <assert.h>

int factorial(int);
int test_factorial();

int main(int argc, char *argv[])
{
  // TODO: Implement script interaction.
  // TODO: Implement support for arbitrary high numbers.
  test_factorial();
}

int factorial(int n)
{
  // TODO: Implement some checks to end execution if invalid number given.
  int product = 1;

  while (n >= 2)
  {
    product *= n;
    n--;
  }

  return product;
}

int test_factorial()
{
  assert(factorial(5) == 120);
  assert(factorial(10) == 3628800);
  assert(factorial(3) == 6);
}