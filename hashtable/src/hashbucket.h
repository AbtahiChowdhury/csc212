#ifndef ABTAHI_HASHBUCKET
#define ABTAHI_HASHBUCKET
#include "linkedlist.h"
#include "binarytree.h"

template <class item>
class hashbucket;
template <class item>
std::ostream& operator<<(std::ostream& outs, const hashbucket<item>& h);

template <class item>
class hashbucket
{
    friend std::ostream& operator<< <>(std::ostream& outs, const hashbucket<item>& h);
    public:
        hashbucket();
        ~hashbucket();
        size_t getSize() const;
        void insert(const int& keyin, const item& datain);
        void remove(const int& keyrm);
        item retrieve(const int& keyin);
        bool search(const int& keyin);
        int getLast();
        void emptyBucket();
    private:
        void switchDataStructure();
        bool listtype; //true is linkedlist, false is binary tree
        linkedlist<item>* list;
        binarytree<item>* tree;
};

#include "hashbucket.template"
#endif //!ABTAHI_HASHBUCKET