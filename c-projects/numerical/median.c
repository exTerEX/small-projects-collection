/* median.c */

#include <stdlib.h>
#include <assert.h>

double median(int[], int);
void test_median();

int main()
{
  // TODO: Implement script interaction.
  // TODO: Make work for non integer.
  test_median();
}

double median(int data[], int size)
{
  double median;

  if (size % 2 == 0)
  {
    median = (data[size / 2] + data[(size / 2) - 1]) / 2;
  }
  else
  {
    median = data[size / 2];
  }

  return median;
}

void test_median()
{
  int arr_1[3] = {41, 67, 34};
  assert(median(arr_1, 3) == (double)67.0);

  int arr_2[4] = {41, 67, 87, 34};
  assert(median(arr_2, 4) == (double)77.0);
}