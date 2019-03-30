#ifndef ABTAHI_LINKEDLIST
#define ABTAHI_LINKEDLIST
#include <iostream>
#include "nodekey.h"
#include "nodevalue.h"

class linkedlist
{
    friend std::ostream& operator<<(std::ostream& outs, const linkedlist& l);
    public:
        linkedlist();
        ~linkedlist();
        size_t getSize() const {return size;}
        void sort();
        void insert(size_t indexin, int keyin, int valuein);
        void removeKey(int keyrm);
        void removeIndex(size_t indexrm);
        void clearList();
        int getValue(int keyin);
    private:
        void insertAtHead(int keyin, int valuein);
        void insertAtTail(int keyin, int valuein);
        void removeAll(nodekey* headptrin);
        bool isSorted();
        size_t size;
        nodekey* headptr;
        nodevalue* tailptr;
};

#endif // !ABTAHI_LINKEDLIST
