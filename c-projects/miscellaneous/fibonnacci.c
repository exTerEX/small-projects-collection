/* fibonnacci.c */
#include <assert.h>

int fibonnacci(int);
void test_fibonnacci();

int main(int argc, char *argv[])
{
  // TODO: Implement script interaction.
  test_fibonnacci();
}

int fibonnacci(int n)
{
  if (n < 0)
  {
    return 0;
  }

  if (n == 1 || n == 2)
  {
    return 1;
  }
  else
  {
    return fibonnacci(n - 1) + fibonnacci(n - 2);
  }
}

void test_fibonnacci()
{
  assert(fibonnacci(16) == 987);
  assert(fibonnacci(3) == 2);
  assert(fibonnacci(8) == 21);
}