/* decimal_to_binary.c */
#include <assert.h>

int dec2bin(int);
void test_dec2bin();

int main(int argc, char *argv[])
{
  // TODO: Implement script interaction.
  test_dec2bin();
}

int dec2bin(int decimal_number)
{
  int remainder, binary_number = 0, temp = 1;

  while (decimal_number > 0)
  {
    remainder = decimal_number % 2;
    decimal_number /= 2;
    binary_number += remainder * temp;
    temp *= 10;
  }

  return binary_number;
}

void test_dec2bin()
{
  int n1 = 21, n2 = 1, n3 = 14, n4 = 0, n5 = 1000, n6 = 123;

  assert(dec2bin(n1) == 10101);
  assert(dec2bin(n2) == 1);
  assert(dec2bin(n3) == 1110);
  assert(dec2bin(n4) == 0);
  assert(dec2bin(n5) == 1111101000);
  assert(dec2bin(n6) == 1111011);
}