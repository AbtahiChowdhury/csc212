#ifndef ABTAHI_BINARYTREE
#define ABTAHI_BINARYTREE
#include <iostream>
#include "btnode.h"
template <class item>
class linkedlist;
#include "linkedlist.h"

template <class item>
class binarytree;
template <class item>
std::ostream& operator<<(std::ostream& outs, const binarytree<item>& b);

template <class item>
class binarytree
{
    friend std::ostream& operator<< <>(std::ostream& outs, const binarytree<item>& b);
    public:
        binarytree();
        ~binarytree();
        size_t getSize() const {return size;}
        void insert(const int& keyin, const item& datain);
        void copyTo(linkedlist<item>& listin);
        void remove(const int& keyrm);
        item retrieve(const int& keyin);
        bool search(const int& keyin);
        int getLast();
        void clearTree();
    private:
        void copyRecursion(btnode<item>* rootin, linkedlist<item>& listin);
        void insertRecursion(btnode<item>* rootin, const int& keyin, const item& datain);
        void searchRecursion(btnode<item>* rootin, const int& keyin, btnode<item>*& location);
        void getSuccessor(btnode<item>* rootin, btnode<item>*& location);
        void removeAll(btnode<item>* rootin);
        void print(std::ostream& outs) const;
        void inOrderPrint(btnode<item>* rootin, std::ostream& outs) const;
        size_t size;
        btnode<item>* root;
};

#include "binarytree.template"
#endif //!ABTAHI_BINARYTRE