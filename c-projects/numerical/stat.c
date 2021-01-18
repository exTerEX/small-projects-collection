#include <stdio.h>
#include <assert.h>
#include <math.h>

// --- Function definitions
double mean(double *, unsigned int);
double variance(double *data, unsigned int n);
double sd(double *, unsigned int);
double sum(double *, unsigned int);
double median(double *, unsigned int);

int main(int argc, char *argv[])
{
  double arr[3] = {1, 2, 3};
  int n = sizeof(arr) / sizeof(*arr);

  printf("Length: %i\n", n);
  printf("Mean: %f\n", mean(arr, n));
  printf("Variance: %f\n", variance(arr, n));
  printf("Standard deviation: %f\n", sd(arr, n));
  printf("Sum: %f\n", sum(arr, n));
  printf("Median: %f\n", median(arr, n));
}

double mean(double *data, unsigned int n)
{
  int sum = 0;
  for (int index = 0; index < n; index++)
  {
    sum += data[index];
  }
  return sum / n;
}

double variance(double *data, unsigned int n)
{
  double sum = 0;
  for (int index = 0; index < n; index++)
  {
    sum += pow(data[index] - mean(data, n), 2);
  }
  return sum / n;
}

double sd(double *data, unsigned int n)
{
  return sqrt(variance(data, n));
}

double sum(double *data, unsigned int n)
{
  double sum = 0;
  for (int index = 0; index < n; index++)
  {
    sum += data[index];
  }
  return sum;
}

double median(double *data, unsigned int n)
{
  double median;

  if (n % 2 == 0)
  {
    median = (data[n / 2] + data[(n / 2) - 1]) / 2;
  }
  else
  {
    median = data[n / 2];
  }

  return median;
}
