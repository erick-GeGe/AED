#include "lista.h"

template <class Type>
class OrderedLinkedList : public Lista<Type>
{
public:
    bool search(const Type &searchItem) const;
    void insert(const Type &newItem);
    void insertFirst(const Type &newItem);
    void insertLast(const Type &newItem);
    void deleteNode(const Type &deleteItem);
};

template <class Type>
bool OrderedLinkedList<Type>::search(const Type &searchItem) const
{
    bool found = false;
    NodeType<Type> *current; 
    current = this->first;
    while (current != NULL && !found)
        if (current->info >= searchItem)
            found = true;
        else
            current = current->link;
    if (found)
        found = (current->info == searchItem); 
    return found;
} 

template <class Type>
void OrderedLinkedList<Type>::insert(const Type &newItem)
{
    NodeType<Type> *newNode = new NodeType<Type>(newItem);       
    if (this->first == NULL) 
    {
        this->first = newNode;
        this->last = newNode;
        this->count++;
        return;
    }

    NodeType<Type> *current = this->first;      
    NodeType<Type> *trailCurrent; 
    bool found = false;

    while (current != NULL && !found) 
        if (current->info >= newItem)
            found = true;
        else
        {
            trailCurrent = current;
            current = current->link;
        }
    if (current == this->first)
    {
        newNode->link = this->first;
        this->first = newNode;
        this->count++;
    }

    else
    {
        trailCurrent->link = newNode;
        newNode->link = current;
        if (current == NULL)
            this->last = newNode;
        this->count++;
    }

}


template <class Type>
void OrderedLinkedList<Type>::insertFirst(const Type &newItem)
{
    insert(newItem);
}

template <class Type>
void OrderedLinkedList<Type>::insertLast(const Type &newItem)
{
    insert(newItem);
}

template <class Type>
void OrderedLinkedList<Type>::deleteNode(const Type &deleteItem)
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