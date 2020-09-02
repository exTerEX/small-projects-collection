#!/usr/bin/env python3


def palindrome(sequence: str) -> bool:
    return sequence[::-1] == sequence


if __name__ == "__main__":
    print(palindrome("AAGGAA"))
