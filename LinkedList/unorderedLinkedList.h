#include "lista.h"

template <class Type>
class UnorderedLinkedList : public Lista<Type>
{
public:
    bool search(const Type &searchItem) const ;
    void insertFirst(const Type &newItem) ;
    void insertLast(const Type &newItem) ;
    void deleteNode(const Type &deleteItem) ;
};

template <class Type>
bool UnorderedLinkedList<Type>::search(const Type &searchItem) const
{
    NodeType<Type> *current = this->first;
    bool found = false;

    while (current != NULL && !found)
        if (current->info == searchItem)
            found = true;
        else
            current = current->link;

    return found;
}

template <class Type>
void UnorderedLinkedList<Type>::insertFirst(const Type &newItem)
{
    NodeType<Type> *newNode = new NodeType<Type>(newItem);
    newNode->link = this->first;
    this->first = newNode;

    if (this->last == NULL)
        this->last = newNode;

    this->count++;
}

template <class Type>
void UnorderedLinkedList<Type>::insertLast(const Type &newItem)
{
    NodeType<Type> *newNode = new NodeType<Type>(newItem);
    if (this->first == NULL)
    {
        this->first = newNode;
        this->last = newNode;
    }
    else
    {
        this->last->link = newNode;
        this->last = newNode;
    }
    this->count++;
}

template <class Type>
void UnorderedLinkedList<Type>::deleteNode(const Type &deleteItem)
{
    NodeType<Type> *current;

    if (this->first == NULL)
    {
        std::cout << "Cannot delete from an empty list." << std::endl;
        return;
    }

    if (this->first->info == deleteItem)
    {
        current = this->first;
        this->first = this->first->link;
        this->count--;
        if (this->first == NULL)
            this->last = NULL;
        delete current;
        return;
    }

    bool found = false;
    NodeType<Type> *trailCurrent = this->first;
    current = this->first->link;
    while (current != NULL && !found)
    {
        if (current->info != deleteItem)
        {
            trailCurrent = current;
            current = current->link;
        }
        else
            found = true;
    }          
    if (found) 
    {
        trailCurrent->link = current->link;
        if (this->last == current) 
            this->last = trailCurrent;
        delete current;          
        this->count--;
    }
    else
        std::cout << "The item to be deleted is not in the list." << std::endl;
}