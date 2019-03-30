#include "nodekey.h"

nodekey::nodekey(int keyin, nodevalue* nextin, nodevalue* previn)
{
    key=keyin;
    next=nextin;
    prev=previn;
}

void nodekey::setKey(int keyin)
{
    key=keyin;
}

void nodekey::setNextNode(nodevalue* nextin)
{
    next=nextin;
}

void nodekey::setPreviousNode(nodevalue* previn)
{
    prev=previn;
}
