from typing import Callable


def bisection(func: Callable[[float], float], a, b) -> float:
    start, end = a, b
    if func(a) == 0:
        return a
    elif func(b) == 0:
        return b
    elif func(a) * func(b) > 0:
        raise ValueError()
    else:
        mid = start + (end - start) / 2

        while abs(start - mid) > 1e-7:
            if func(mid) == 0:
                return mid
            elif func(mid) * func(start) < 0:
                end = mid
            else:
                start = mid

            mid = start + (end - start) / 2

        return mid


def newton(func: Callable[[float], float],
           derivative: Callable[[float], float],
           strpt: int) -> float:
    prev = float(strpt)
    while True:
        try:
            next = prev - func(prev) / derivative(prev)
        except ZeroDivisionError:
            raise ZeroDivisionError()

        if abs(prev - next) < 1e-5:
            return next
        prev = next


# TODO: Write a test for method


if __name__ == "__main__":
    pass
