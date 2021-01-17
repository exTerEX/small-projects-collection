/*linked_list.hpp*/

#include <vector>

struct Node
{
    int data;
    Node *next;

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

class linked_list
{
private:
    Node *head;
    Node *tail;

    int size;

    Node *get_node(int index)
    {
        if (index < 0 || index >= size)
        {
            throw std::exception();
        }
        Node *current = head;
        for (int i = 0; i < index; i++)
        {
            current = current->next;
        }
        return current;
    }

public:
    linked_list();
    ~linked_list();
    linked_list(std::vector<int>);
    int &operator[](int);
    void append(int);
    void print();
    int length();
    void insert(int, int);
    void remove();
    int pop();
    int pop(int);
};