/*array_list.cpp*/
#include "array_list.hpp"

void List::list_resize()
{
    list_capacity *= 2;                 // New capacity of list
    int *temp = new int[list_capacity]; // Create new temp array

    // Write data array into temp array
    for (int index = 0; index < list_size; index++)
    {
        temp[index] = data[index];
    }

    delete[] data;
    data = temp;

    delete[] temp;
}

void List::shrink_to_fit()
{
    int new_capacity;

    for (int index = 0; index < 64; index++) // TODO: Review agein.
    {
        new_capacity = 2 ^ index;
        if (new_capacity > list_size)
        {
            break;
        }
    }

    list_capacity = new_capacity;
}

List::List()
{
    list_size = 0;
    list_capacity = 1;
    data = new int[list_capacity];
}

List::~List()
{
    delete[] data;
}

List::List(std::vector<int> list)
{
}

int &List::operator[](int index)
{
}
