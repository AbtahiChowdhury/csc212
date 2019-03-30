#ifndef ABTAHI_NODEVALUE
#define ABTAHI_NODEVALUE
class nodekey;
#include "nodekey.h"

class nodevalue
{
    public:
        nodevalue(int valuein, nodekey* nextin=nullptr, nodekey* previn=nullptr);
        int getValue() const {return value;}
        const nodekey* getNext() const {return next;}
        const nodekey* getPrevious() const {return prev;}
        nodekey* getNext() {return next;}
        nodekey* getPrevious() {return prev;}
        void setValue(const int& valuein);
        void setNextNode(nodekey* nextin);
        void setPreviousNode(nodekey* previn);
    private:
        int value;
        nodekey* next;
        nodekey* prev;
};

#endif // !ABTAHI_NODEVALUE