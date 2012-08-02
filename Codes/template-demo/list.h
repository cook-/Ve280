#ifndef LIST_H
#define LIST_H

class listIsEmpty
{
};

template <class T>
class List
{
public:
    bool isEmpty();
    void insert(T v);
    T remove();

    List();
    List(const List &l);
    List &operator=(const List &l);
    ~List();

private:
    struct node
    {
        T value;
        node* next;
    };

    node *first;
    void removeAll();
    void copyList(node *v);
};

#endif
