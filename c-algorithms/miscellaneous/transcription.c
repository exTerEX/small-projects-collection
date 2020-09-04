#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <assert.h>
#include <stdio.h>

bool *is_dna(const char[]);
const char *to_rna(const char[]);
void test_to_rna();

int main(int argc, char *argv[])
{
  // TODO: Implement script interaction.
  test_to_rna();
  to_rna("GCTA"); // FIXME: Doesn't work as intended. Last 'char' wrong.
}

// TODO: implement in a standalone package for reusability
bool *is_dna(const char sequence[])
{
  for (int index = 0; index < strlen(sequence); index++)
  {
    switch (sequence[index])
    {
    case 'G':
      break;
    case 'C':
      break;
    case 'T':
      break;
    case 'A':
      break;
    default:
      return (bool *)false;
    }
  }
  return (bool *)true;
}

const char *to_rna(const char sequence[])
{
  if (!is_dna(sequence))
  {
    return false; // TODO: Better raise of error and/or feedback
  }

  char *memory_sequence_address = malloc(sizeof(char) * strlen(sequence));

  for (int index = 0; index < strlen(sequence); index++)
  {
    // TODO: Force uppercase
    switch (sequence[index])
    {
    case 'G':
      memory_sequence_address[index] = 'C';
      break;
    case 'C':
      memory_sequence_address[index] = 'G';
      break;
    case 'T':
      memory_sequence_address[index] = 'A';
      break;
    case 'A':
      memory_sequence_address[index] = 'U';
      break;
    }
  }
  return (char *)memory_sequence_address;
}

void test_to_rna()
{
  assert(is_dna("GCTA") == (bool *)true);
  assert(is_dna("HELLO") == (bool *)false);
  //assert(to_rna("GCTA") == (char *)"CGAU");
}