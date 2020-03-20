#!/usr/bin/env python3

DNA = set("ATGC")  # DNA alphabet
RNA = set("AUGC")  # RNA alphabet


def validate(sequence: str, alphabet: str = DNA) -> bool:
    return not set(sequence.upper()) - alphabet


if __name__ == "__main__":
    print(validate("AGGCTTGAA", DNA))
