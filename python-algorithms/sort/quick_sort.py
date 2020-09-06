"""This is a pure Python implementation of the quick sort algorithm."""

# TODO: Implement advanced options.
# TODO: Make work for strings.


def quick_sort(data: any) -> list:
    """"""
    if not isinstance(data, list):
        try:
            data = list(data)
        except Exception as error:
            raise error("Data provided not compatible with list.")

    # Algorithm
    if len(data) <= 1:
        return list(data)
    else:
        pivot = data.pop()
        greater, lesser = [], []
        for element in data:
            if element > pivot:
                greater.append(element)
            else:
                lesser.append(element)
        return list(quick_sort(lesser) + [pivot] + quick_sort(greater))


def test_quick_sort():
    """"""
    assert(quick_sort([3, 1, 7, 6, 8]) == [1, 3, 6, 7, 8])
    assert(quick_sort([1, 9, 2, 6, 8]) != [1, 3, 6, 7, 8])
    assert(quick_sort([1]) == [1])


test_quick_sort()
