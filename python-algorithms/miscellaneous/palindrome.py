#!/usr/bin/env python3

def is_palindrome(sequence: str) -> bool:
    """Return 'True' if :sequence: is a palindrome, otherwise 'False'.
    Param(s):
    - sequence (str) : String to analysed.
    Return:
    - (bool) Return 'True' or 'False'."""
    start, end = 0, len(sequence) - 1  # TODO: Make parameter argument

    return sequence[start:end] == sequence[start:end:-1]


def find_palindrome(sequence: str) -> tuple:
    """Search for palindrome in :sequence: and return palindrome sequence(s) and the position on form (seq, (start, stop))
    Param(s):
    - sequence (str) : Sequence to analyse
    Return:
    - (tuple) Return palindrome and position as (seq, (start, stop))"""
    pass  # TODO: Make algorithm 'find_palindrome'
