/* mean.c */

#include <stdlib.h>
#include <assert.h>

int mean(int[], int);
void test_mean();

int main(int argc, char *argv[])
{
  // TODO: Implement script interaction.
  // TODO: Make work for non integer.
  test_mean();
}

int mean(int data[], int n)
{
  int sum = 0;

  for (int index = 0; index < n; index++)
  {
    sum += data[index];
  }

  return sum / n;
}

void test_mean()
{
  int arr[10] = {41, 67, 34, 0, 69, 24, 78, 58, 62, 64};
  int n = 10;

  assert(mean(arr, n) == 49);
  assert(mean(arr, n) != 47);
}