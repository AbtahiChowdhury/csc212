#ifndef ABTAHI_BTNODE
#define ABTAHI_BTNODE

template <class item>
class btnode
{
    public:
        btnode(const int& keyin, const item& datain=item(), btnode* parentin=nullptr, btnode* leftchildin=nullptr, btnode* rightchildin=nullptr);
        int getKey() const {return key;}
        item getData() const {return data;}
        const btnode* getLeft() const {return leftchild;}
        const btnode* getRight() const {return rightchild;}
        const btnode* getParent() const {return parent;}
        btnode* getLeft() {return leftchild;}
        btnode* getRight() {return rightchild;}
        btnode* getParent() {return parent;}
        void setKey(const int& keyin);
        void setData(const item& datain);
        void setLeftNode(btnode* leftin);
        void setRightNode(btnode* rightin);
        void setParentNode(btnode* parentin);
    private:
        int key;
        item data;
        btnode* parent;
        btnode* leftchild;
        btnode* rightchild;
};

#include "btnode.template"
#endif //!ABTAHI_BTNODE
