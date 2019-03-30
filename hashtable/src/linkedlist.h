#ifndef ABTAHI_LINKEDLIST
#define ABTAHI_LINKEDLIST
#include <iostream>
#include "llnode.h"
template <class item>
class binarytree;
#include "binarytree.h"

template <class item>
class linkedlist;
template <class item>
std::ostream& operator<<(std::ostream& outs, const linkedlist<item>& l);

template <class item>
class linkedlist
{
    friend std::ostream& operator<< <>(std::ostream& outs, const linkedlist<item>& l);
    public:
        linkedlist();
        ~linkedlist();
        size_t getSize() const {return size;}
        void insert(const int& keyin, const item& datain);
        void copyTo(binarytree<item>& treein);
        void remove(const int& keyrm);
        item retrieve(const int& keyin);
        bool search(const int& keyin);
        int getLast();
        void clearList();
    private:
        void removeHead();
        void removeTail();
        void removeAll(llnode<item>* headptr);
        size_t size;
        llnode<item>* headptr;
        llnode<item>* tailptr;
};

#include "linkedlist.template"
#endif // !ABTAHI_LINKEDLIST
