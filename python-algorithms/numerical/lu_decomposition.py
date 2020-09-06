"""This is a Python implementation of the lu decomposition."""

import numpy


def lu_decompose(datatable: any) -> list:
    """"""
    row, col = numpy.shape(datatable)
    L, U = numpy.zeros((row, col)), numpy.zeros((row, col))

    if row != col:
        return []

    sum = 0
    for i in range(col):
        for j in range(i):
            for k in range(j):
                sum += L[i][k] * U[k][j]
            L[i][j] = (datatable[i][j] - sum) / U[j][j]

        L[i][i] = 1

        for j in range(i, col):
            for k in range(i):
                sum += L[i][k] * U[k][j]
            U[i][j] = datatable[i][j] - sum

    return list([L, U])


def test_lu_decompose():
    """"""
    pass  # TODO: Implement test of lu decompose


test_lu_decompose()
