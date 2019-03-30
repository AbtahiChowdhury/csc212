#include "nodevalue.h"

nodevalue::nodevalue(int valuein, nodekey* nextin, nodekey* previn)
{
    value=valuein;
    next=nextin;
    prev=previn;
}

void nodevalue::setValue(const int& valuein)
{
    value=valuein;
}

void nodevalue::setNextNode(nodekey* nextin)
{
    next=nextin;
}

void nodevalue::setPreviousNode(nodekey* previn)
{
    prev=previn;
}
