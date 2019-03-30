#ifndef ABTAHI_LLNODE
#define ABTAHI_LLNODE

template <class item>
class llnode
{
    public:
        llnode(const int& keyin, const item& datain=item(), llnode* nextin=nullptr, llnode* previn=nullptr);
        int getKey() const {return key;}
        item getData() const {return data;}
        const llnode* getNext() const {return next;}
        const llnode* getPrevious() const {return prev;}
        llnode* getNext() {return next;}
        llnode* getPrevious() {return prev;}
        void setKey(const int& keyin);
        void setData(const item& datain);
        void setNextNode(llnode* nextin);
        void setPreviousNode(llnode* previn);
    private:
        int key;
        item data;
        llnode* next;
        llnode* prev;
};

#include "llnode.template"
#endif // !ABTAHI_LLNODE
