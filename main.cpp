#include "unorderedLinkedList.h"
#include "ordereLinkedList.h"

int main()
{
    OrderedLinkedList<int> numerosError;
    numerosError.insertFirst(10);
    numerosError.insertLast(5);
    numerosError.insertFirst( 8);
    numerosError.print();
}