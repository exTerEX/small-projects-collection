#!/usr/bin/env python3

DNA = {"A": "T", "T": "A", "C": "G", "G": "C"}
RNA = {"A": "U", "U": "A", "C": "G", "G": "C"}


def complementary(sequence: str, rules: dict = DNA) -> str:
    cstr = ""

    for nucleotide in sequence:
        cstr += rules[nucleotide]

    return cstr[::-1]


if __name__ == "__main__":
    print(complementary("ATTGCCG"))
