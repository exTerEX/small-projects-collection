#include <stdio.h>
#include <stdbool.h>
#include <assert.h>
#include <math.h>

bool is_prime(int);
void test_is_prime(void);

int main()
{
  // TODO: Implement script interaction.
}

bool is_prime(int x)
{
  if (x == 2)
  {
    return true;
  }
  if (x < 2 || x % 2 == 0)
  {
    return false;
  }

  double root = sqrt(x);

  for (int index = 3; index <= root; index += 2)
  {
    if (x % index == 0)
    {
      return false;
    }
  }
  return true;
}

void test_is_prime(void)
{
  int primers[] = {2, 3, 5, 7, 11, 13, 17, 19, 23, 29, 31, 37, 41, 43, 47, 53, 59, 61, 67, 71, 73, 79, 83, 89, 97};

  for (int index = 0; index < sizeof(primers) / sizeof(*primers); index++)
  {
    assert(is_prime(primers[index]) == true);
  }
  assert(is_prime(6) == false);
  assert(is_prime(0) == false);
}