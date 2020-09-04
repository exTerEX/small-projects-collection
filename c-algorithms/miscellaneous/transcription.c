#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char *to_rna(const char[]);
void test_to_rna(void);

int main(int argc, char *argv[])
{
  // TODO: Implement script interaction.
}

char *to_rna(const char sequence[])
{
  int len = strlen(sequence);

  char *memseq = malloc(sizeof(char) * len);

  for (int index = 0; index < len; index++)
  {
    switch (toupper(sequence[index]))
    {
    case "G":
      memseq[i] = "G";
      break;
    case "C":
      memseq[i] = "G";
      break;
    case "T":
      memseq[i] = "A";
      break;
    case "A":
      memseq[i] = "U";
      break;
    default:
      break;
    }
  }
  return memseq;
}

void test_to_rna(void)
{
}