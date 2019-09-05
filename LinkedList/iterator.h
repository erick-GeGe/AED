#include "node.h"

#ifndef ITERATOR_H
#define ITERATOR_H


template <class Type>
class LinkedListIterator
{
    public:
        LinkedListIterator();
        Type operator*();
        LinkedListIterator(NodeType<Type>* ptr);
        LinkedListIterator<Type> operator ++();
        bool operator==(const LinkedListIterator<Type>& right) const;
        bool operator!=(const LinkedListIterator<Type>& right) const;

    private:
        NodeType<Type>* current;
};

#pragma region Implementacion

template <class Type>
LinkedListIterator<Type>::LinkedListIterator() : current(nullptr) { }

template <class Type>
LinkedListIterator<Type>::LinkedListIterator(NodeType<Type> *ptr): current(ptr) { }

template <class Type>
Type LinkedListIterator<Type>::operator*(){ return current->info; }

template <class Type>
LinkedListIterator<Type> LinkedListIterator<Type>::operator++()
{
    current = current->link;
    return *this;
}

template <class Type>
bool LinkedListIterator<Type>::operator==(const LinkedListIterator<Type>& right) const
{
    return (current == right.current);
}

template <class Type>
bool LinkedListIterator<Type>::operator!=(const LinkedListIterator<Type>& right) const
{
    return (current != right.current);
}

#pragma endregion

#endif