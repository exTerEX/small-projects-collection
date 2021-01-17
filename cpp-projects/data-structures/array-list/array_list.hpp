/*array_list.hpp*/

#include <vector>

class List
{
private:
    int *data;
    int list_size;
    int list_capacity;

    void list_resize();

protected:
    void shrink_to_fit();

public:
    List();
    ~List();
    List(std::vector<int>);

    int &operator[](int);

    void append(int);
    int size();
    void insert(int, int);
    void remove(int);
    int pop();
    int pop(int);

    void display();
};