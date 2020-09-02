#include <iostream>
#include <vector>

struct Node
{
    int data;
    Node *next;
    Node *prev;

    Node(int n)
    {
        data = n;
        next = nullptr;
    }
    Node(int n, Node *p)
    {
        data = n;
        next = p;
    }
};

class LinkedList
{
private:
    Node *head, *tail;
    int size;

    Node *get_node(int index)
    {
        if (index < 0 || index >= size)
        {
            throw std::range_error("IndexError: Index out of range.");
        }
        Node *Current = head;
        for (int i = 0; i < index; i++)
        {
            Current = Current->next;
        }
        return Current;
    }

protected:
public:
    LinkedList(void)
    {
        head = nullptr;
        tail = nullptr;
        size = 0;
    }

    ~LinkedList(void)
    {
        Node *Current = head, *Next;

        while (Current != nullptr)
        {
            Next = Current->next;
            delete Current;
            Current = Next;
        }
        head = 0;
    }

    LinkedList(std::vector<int> value)
    {
        head = nullptr;
        tail = nullptr;
        size = 0;

        for (int element : value)
        {
            append(element);
        }
    }

    int &operator[](int index)
    {
        return get_node(index)->data;
    }

    void append(int value)
    {
        if (head == nullptr)
        {
            head = new Node(value);
            tail = head;
            size++;
            return;
        }
        tail->next = new Node(value);
        tail = tail->next;
        size++;
    }

    void print()
    {
        Node *Current = head;
        std::cout << "[";
        while (Current->next != nullptr)
        {
            std::cout << Current->data << ", ";
            Current = Current->next;
        }
        std::cout << Current->data << "]" << std::endl;
    }

    int len()
    {
        return size;
    }

    void insert(int value, int index)
    {
        Node *Prev = get_node(index - 1);
        Node *Next = Prev->next;
        Prev->next = new Node(value, Next);
        size++;
    }

    void remove(int index)
    {
        pop(index);
    }

    int pop()
    {
        return pop(size - 1);
    }

    int pop(int index)
    {
        Node *Current = head, *Next = nullptr;
        if (index == 0)
        {
            Node *Prev = head;
            head = Current->next;
            delete Current;
            size--;
            return Prev->data;
        }

        for (int i = 0; i < index - 1; i++)
        {
            Current = Current->next;
        }

        Next = Current->next;
        int Data = Next->data;
        Current->next = Next->next;
        delete Next;
        size--;
        return Data;
    }
};

int main(int argc, char **argv)
{
    LinkedList Link({2, 3, 5, 6, 7});
    Link.append(1);
    std::cout << "Length: " << Link.len() << std::endl;
    Link.print();
    Link.insert(3, 5);
    Link.print();
    std::cout << "Length: " << Link.len() << std::endl;
    Link.remove(2);
    Link.print();
    std::cout << "pop(2) = " << Link.pop(2) << std::endl;
    Link.print();
    std::cout << "pop() = " << Link.pop() << std::endl;
    Link.print();
    int n = 1;
    std::cout << "Element " << n << ": " << Link[n] << std::endl;
    std::cout << "Length: " << Link.len() << std::endl;
}
