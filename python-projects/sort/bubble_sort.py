"""This is a pure Python implementation of the bubble sort algorithm."""

# TODO: Implement advanced options.
# TODO: Make work for strings.


def bubble_sort(data: any) -> list:
    """"""
    if not isinstance(data, list):
        try:
            data = list(data)
        except Exception as error:
            raise error("Data provided not compatible with list.")

    # Algorithm
    for i in range(len(data) - 1):
        swap = False
        for j in range(len(data) - (i + 1)):
            if data[j] > data[j + 1]:
                swap = True
                data[j], data[j + 1] = data[j + 1], data[j]
        if not swap:
            break

    return list(data)


def test_bubble_sort():
    assert(bubble_sort([3, 9, 2, 6, 3]) == [2, 3, 3, 6, 9])


test_bubble_sort()
