/* palindrome.c */
#include <stdio.h>
#include <stdbool.h>
#include <assert.h>

bool is_palindrome(int);
void test_is_palindrome(void);

int main(int argc, char *argv[])
{
  // TODO: Implement script interaction.
  // TODO: Make work for strings as well.
  test_is_palindrome();
}

bool is_palindrome(int number)
{
  int reversed = 0;
  int original = number;
  while (number != 0)
  {
    int remainder = number % 10;
    reversed = reversed * 10 + remainder;
    number /= 10;
  }
  return original == reversed;
}

void test_is_palindrome(void)
{
  assert(is_palindrome(0) == true);
  assert(is_palindrome(123454321) == true);
  assert(is_palindrome(1234567) == false);
  assert(is_palindrome(1) == true);
}