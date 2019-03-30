#ifndef ABTAHI_HEAP
#define ABTAHI_HEAP
#include <iostream>

class heap
{
    friend std::ostream& operator<<(std::ostream& outs, const heap& h);
    public:
        heap();
        ~heap();
        void push(int datain);
        int pop();
    private:
        void heapifiyUpward();
        void heapifiyDownward();
        int getParent(int indexin);
        int getLeftChild(int indexin);
        int getRightChild(int indexin);
        size_t capacity;
        size_t size;
        int *data;
};

#endif //!ABTAHI_HEAP