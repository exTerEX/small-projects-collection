"""This is a pure Python implementation of the heap sort algorithm."""

# TODO: Implement advanced options.
# TODO: Make work for strings.


def process_heap(data: list, index: int, size: int):
    """"""
    largest, left_index, right_index = index, 2 * index + 1, 2 * index + 2

    if left_index < size and data[left_index] > data[largest]:
        largest = left_index

    if right_index < size and data[right_index] > data[largest]:
        largest = right_index

    if largest != index:
        data[largest], data[index] = data[index], data[largest]
        process_heap(data, largest, size)


def heap_sort(data: any) -> list:
    """"""
    if not isinstance(data, list):
        try:
            data = list(data)
        except Exception as error:
            raise error("Data provided not compatible with list.")

    # Algorithm
    for i in range(len(data) // 2 - 1, -1, -1):
        process_heap(data, i, len(data))

    for i in range(len(data) - 1, 0, -1):
        data[0], data[i] = data[i], data[0]
        process_heap(data, 0, i)

    return data


def test_heap_sort():
    assert(heap_sort([6, 2, 1, 4, 8, 0, 9]) == [0, 1, 2, 4, 6, 8, 9])


test_heap_sort()
