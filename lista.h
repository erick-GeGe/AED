#include "iterator.h"
#include <iostream>
#include <assert.h>

#ifndef LISTA_H
#define LISTA_H


template <class Type>
class Lista
{
public:
    const Lista<Type>& operator=(const Lista<Type>&);
    void initializeList();
    void destroyList();
    void print() const;
    bool isEmptyList() const;
    int length() const;

    Type front() const;
    Type back() const;

    virtual bool search(const Type &searchItem) const = 0;
    virtual void insertFirst(const Type &newItem) = 0;
    virtual void insertLast(const Type &newItem) = 0;
    virtual void deleteNode(const Type &deleteItem) = 0;

    LinkedListIterator<Type> begin();
    LinkedListIterator<Type> end();

    Lista();
    Lista(const Lista<Type>& otherList);
    ~Lista();
    
protected:

    int count;
    NodeType<Type> *first;
    NodeType<Type> *last;

private:

    void copyList(const Lista<Type> &otherList);
};


#pragma region Implementacion

template <class Type>
bool Lista<Type>::isEmptyList() const { return (first == nullptr); }

template <class Type>
int Lista<Type>::length() const { return count; }

template <class Type>
Lista<Type>::Lista() : first(nullptr), last(nullptr) { count = 0; }

template <class Type>
void Lista<Type>::initializeList() { destroyList(); }

template <class Type>
Lista<Type>::~Lista(){ destroyList(); }

template <class Type>
Lista<Type>::Lista(const Lista<Type>& otherList){ copyList(otherList); }

template <class Type>
void Lista<Type>::destroyList()
{
    NodeType<Type> *temp;
    while (first != nullptr)
    {
        temp = first;
        first = first->link;
        delete temp;
    }
    last = nullptr;
    count = 0;
}

template <class Type>
void Lista<Type>::print() const
{
    NodeType<Type> *current = first;
    while (current != nullptr)
    {
        std::cout << current->info << ' ';
        current = current->link;
    }
    std::cout << std::endl;
}

template <class Type>
Type Lista<Type>::front() const
{
    assert(first != NULL);

    return first->info;
}

template <class Type>
Type Lista<Type>::back() const
{
    assert(last != NULL);

    return last->info;
}

template <class Type>
void Lista<Type>::copyList(const Lista<Type> &otherList)
{
    NodeType<Type> *newNode;
    NodeType<Type> *current;
    if (first != nullptr)
        destroyList();
    if (otherList.first == nullptr)
    {
        first = nullptr;
        last = nullptr;
        count = 0;
    }
    else
    {
        current = otherList.first;
        count = otherList.count;
        first = new NodeType<Type>(current->info);
        last = first;
        current = current->link;
        while (current != NULL)
        {
            newNode = new NodeType<Type>(current->info);
            last->link = newNode;
            last = newNode;
            current = current->link;
        }
    }
}

template <class Type>
const Lista<Type>& Lista<Type>::operator= (const Lista<Type>& otherList)
{
    if(this != &otherList)
        copyList(otherList);
    return *this;
}

template <class Type>
LinkedListIterator<Type> Lista<Type>::begin()
{
    LinkedListIterator<Type> temp(first);
    return temp;
}
template <class Type>
LinkedListIterator<Type> Lista<Type>::end()
{
    LinkedListIterator<Type> temp(NULL);
    return temp;
}

#pragma endregion

#endif

