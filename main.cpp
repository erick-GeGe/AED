#include "unorderedLinkedList.h"
#include "ordereLinkedList.h"

int main()
{
    OrderedLinkedList<int> listaOrdenada ;
    listaOrdenada.insertFirst(10);
    listaOrdenada.insertLast(5);
    listaOrdenada.insertFirst( 8);
    listaOrdenada.print();
}
