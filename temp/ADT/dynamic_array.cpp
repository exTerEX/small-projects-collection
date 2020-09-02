#include <iostream>
#include <vector>

class List
{
private:
    int *data;
    int size;
    int capacity;
    int growth_factor;

    void resize()
    {
        capacity *= growth_factor;
        int *tmp = new int[capacity];
        for (int i = 0; i < size; i++)
        {
            tmp[i] = data[i];
        }
        delete[] data;
        data = tmp;
    }

protected:
    ;

public:
    List(void)
    {
        size = 0;
        capacity = 1;
        growth_factor = 2;
        data = new int[growth_factor];
    }

    ~List(void)
    {
        delete[] data;
    }

    int &operator[](int index)
    {
        if (0 <= index && index < size)
        {
            return data[index];
        }
        else
        {
            throw std::range_error("IndexError: Index out of range.");
        }
    }

    void append(int value)
    {
        if (size < capacity)
        {
            data[size] = value;
            size += 1;
        }
        else
        {
            resize();
            append(value);
        }
    }

    int len(void)
    {
        return size;
    }

    void insert(int value, int index)
    {
        if (size + 1 < capacity)
        {
            for (int i = size; i >= index; i--)
            {
                data[i + 1] = data[i];
            }
            data[index] = value;
            size++;
        }
        else
        {
            resize();
            insert(value, index);
        }
    }

    void remove(int index)
    {
        for (int i = index; i <= size; i++)
        {
            data[i] = data[i + 1];
        }

        size--;

        if ((size / capacity) < 0.85)
        {
            shrink_to_fit();
        }
    }

    int pop(void)
    {
        pop(size);
    }

    int pop(int index)
    {
        int current = data[index];
        for (int i = index; i <= size; i++)
        {
            data[i] = data[i + 1];
        }

        size--;

        if ((size / capacity) < 0.85)
        {
            shrink_to_fit();
        }
    }

    void print(void)
    {
        std::cout << "[";
        for (int index = 0; index < size; index++)
        {
            if (index != size - 1)
            {
                std::cout << data[index] << ", ";
            }
            else
            {
                std::cout << data[index];
            }
        }
        std::cout << "]" << std::endl;
    }

    void shrink_to_fit(void)
    {
        int newCap;
        for (int i = 0; i < 64; i++)
        {
            newCap = 2 ^ i;
            if (newCap > size)
            {
                break;
            }
            capacity = newCap;
        }
    }
};

// Test case
bool is_prime(int n)
{
    if (n % 2 != 0 && n % 3 != 0 && n % 5 != 0)
    {
        return true;
    }
    else if (n == 2 || n == 3)
    {
        return true;
    }
    else
    {
        return false;
    }
}

int main(int argc, char **argv)
{
    List Primes;
    int count = 0;
    int iteration = 2;
    while (count < 15)
    {
        if (is_prime(iteration) == true)
        {
            Primes.append(iteration);
            count++;
        }
        ++iteration;
    }
    std::cout << "Primes: ";
    Primes.print();
}
