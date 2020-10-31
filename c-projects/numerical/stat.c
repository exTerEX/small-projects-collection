///
/// \brief Definition for statistical algorithms.
///

#include <stdio.h>
#include <assert.h>
#include <math.h>

// --- Function definitions
double mean(double *, unsigned int);
double sd(double *, unsigned int);
double sum(double *, unsigned int);
double median(double *, int);

// --- Test functions
void test_mean();
void test_sd();
void test_sum();
void test_median();

int main(int argc, char *argv[])
{
  test_mean();
  test_sd();
  test_sum();
  test_median();
}

///
/// \fn mean(double *data, unsigned int n)
/// \brief Calculate mean of an array.
/// \param data The array.
/// \param n Size of array.
///
double mean(double *data, unsigned int n)
{
  int sum = 0;
  for (int index = 0; index < n; index++)
  {
    sum += data[index];
  }
  return sum / n;
}

///
/// \fn sd(double *data, unsigned int n)
/// \brief Calculate standard deviation of an array.
/// \param data The array.
/// \param n Size of array.
///
double sd(double *data, unsigned int n)
{
  int sum = 0;
  for (int index = 0; index < n; index++)
  {
    sum += (data[index] - mean(data, n));
  }
  // FIXME: Something in the SUM loop doesn't work.
  return sqrt(sum ^ 2 / (n - 1));
}

///
/// \fn sum(double *data, unsigned int n, double r)
/// \brief Calculate sum of an array.
/// \param data The array.
/// \param n Size of array.
///
double sum(double *data, unsigned int n)
{
  int sum = 0;
  for (int index = 0; index < n; index++)
  {
    sum += data[index];
  }
  return sum;
}

///
/// \fn median(double *data, unsigned int n)
/// \brief Calculate median of an array.
/// \param data The array.
/// \param n Size of array.
///
double median(double *data, int size)
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

int n = 3;
double arr[3] = {1, 2, 3};

void test_mean()
{
  assert(mean(arr, n) == (double)2);
  assert(mean(arr, n) != 4);
}

void test_sd()
{
  //assert(sd(arr, n) == (double)1);
}

void test_sum()
{
  assert(sum(arr, n) == (double)6);
}

void test_median()
{
  assert(median(arr, n) == (double)2);
}