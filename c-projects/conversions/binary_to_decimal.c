/* binary_to_decimal.c */
#include <stdbool.h>
#include <assert.h>

bool is_binary(int);
int bin2dec(int);
void test_bin2dec();

int main(int argc, char *argv[])
{
  // TODO: Implement script interaction.
  test_bin2dec();
}

// TODO: Make function standalon for reusability
bool is_binary(int binary_number)
{
  int reminder = 0, temp;
  while (binary_number > 0)
  {
    reminder = binary_number % 10;

    if ((reminder != 0) && (reminder != 1))
    {
      return false;
    }

    binary_number /= 10;
  }
  return true;
}

int bin2dec(int binary_number)
{
  if (!is_binary(binary_number))
  {
    return 0;
  }

  int remainder, decimal_number = 0, temp = 1;

  while (binary_number > 0)
  {
    remainder = binary_number % 10;
    binary_number /= 10;
    decimal_number += remainder * temp;
    temp *= 2;
  }
  return decimal_number;
}

void test_bin2dec()
{
  int n1 = 1010, n2 = 1, n3 = 1234, n4 = 0, n5 = 11111, n6 = 111;

  assert(is_binary(n1) == true);
  assert(bin2dec(n1) == 10);
  assert(is_binary(n2) == true);
  assert(bin2dec(n2) == 1);
  assert(is_binary(n3) == false);
  assert(bin2dec(n3) == 0);
  assert(is_binary(n4) == true);
  assert(bin2dec(n4) == 0);
  assert(bin2dec(n5) == 31);
  assert(bin2dec(n6) == 7);
}
