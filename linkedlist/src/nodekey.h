#ifndef ABTAHI_NODEKEY
#define ABTAHI_NODEKEY
class nodevalue;
#include "nodevalue.h"

class nodekey
{
    public:
        nodekey(int keyin, nodevalue* nextin=nullptr, nodevalue* previn=nullptr);
        int getKey() const {return key;}
        const nodevalue* getNext() const {return next;}
        const nodevalue* getPrevious() const {return prev;}
        nodevalue* getNext() {return next;}
        nodevalue* getPrevious() {return prev;}
        void setKey(int keyin);
        void setNextNode(nodevalue* nextin);
        void setPreviousNode(nodevalue* previn);
    private:
        int key;
        nodevalue* next;
        nodevalue* prev;
};

#endif // !ABTAHI_NODEKEY
