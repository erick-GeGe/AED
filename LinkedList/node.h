#ifndef NODE_H
#define NODE_H

template <class Type>
struct NodeType
{
    NodeType() : link(nullptr) {}
    NodeType(Type _info) : link(nullptr) { info = _info; }
    Type info;
    NodeType<Type> *link;
};

#endif