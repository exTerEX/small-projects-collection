"""palindrome.py"""
import pytest


def is_palindrome(sequence: str, /, start: int = None, end: int = None) -> bool:
    """Check if the sequence is a palindrome or not.

    Args:
        sequence (str): A sequence to be checked.
        start (int, optional): Start index to where to check if sequence is a palindrome. Defaults to None.
        end (int, optional): End index to where to check if sequence is a palindrome. Defaults to None.

    Raises:
        ValueError: Raised if sequence isn't of type 'str'.
        ValueError: Raised if start is <= 0.
        ValueError: Raised if start is > len(sequence).
        ValueError: Raised if end is < 0.
        ValueError: Raised if end is >= len(sequence).
        ValueError: Raised if start > end.

    Returns:
        bool: Return true if (limited) sequence is palindrome or false if not a palindrome.
    """

    if not isinstance(sequence, str):
        raise ValueError(f"Sequence must be string")

    if start != None:
        if not start >= 0:
            raise ValueError(f"Start value must be 0 or higher.")

        if not start < len(sequence):
            raise ValueError(f"Start value must be {len(sequence)} or lower.")
    else:
        start = 0

    if end != None:
        if not end > 0:
            raise ValueError(f"End value must be 0 or higher.")

        if not end <= len(sequence):
            raise ValueError(f"End value must be {len(sequence)} or lower.")
    else:
        end = len(sequence)

    if not start < end:
        raise ValueError(f"Start value must be less then end value.")

    sequence = sequence[start:end]

    return sequence[start:end] == sequence[::-1]


def test_is_palindrome():
    assert(is_palindrome("ABBA", start=1) == False)
    assert(is_palindrome("ABBA", end=2) == False)
    assert(is_palindrome("ABBA") == True)
    assert(is_palindrome("ABBA", start=0, end=4) == True)
    with pytest.raises(Exception):
        assert is_palindrome("ABBA", start=3, end=2)


def find_palindrome(sequence: str) -> tuple:
    """Find palindromes longer then 3 characters in sequence.

    Args:
        sequence (str): A sequence to be searched.

    Raises:
        ValueError: Raised if sequence isn't of type 'str'.

    Returns:
        tuple: Return a list of all palindromes bigger then 3 characters.
    """
    if not isinstance(sequence, str):
        raise ValueError(f"Sequence must be string")

    palindrome = []
    for index in range(len(sequence)):
        for jndex in range(index + 1, len(sequence) + 1):
            temp = sequence[index:jndex]
            if temp == temp[::-1] and len(temp) >= 3:
                palindrome.append(temp)

    return tuple(palindrome)


def test_find_palindrome():
    assert(find_palindrome("forgeeksskeegfor") == (
        'geeksskeeg', 'eeksskee', 'eksske', 'kssk'))
