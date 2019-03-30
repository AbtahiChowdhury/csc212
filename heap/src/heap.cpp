#include "heap.h"

heap::heap()
{
    capacity=3;
    size=0;
    data=new int[capacity];
}

heap::~heap()
{
    delete[] data;
}

int heap::getParent(int indexin)
{
    return (indexin-1)/2;
}

int heap::getLeftChild(int indexin)
{
    return (indexin*2)+1;
}

int heap::getRightChild(int indexin)
{
    return (indexin*2)+2;
}

void heap::push(int datain)
{
    if(size==capacity)
    {
        int *newdata=new int[(capacity*2)+1];
        for(size_t i=0; i<size; i++)
        {
            newdata[i]=data[i];
        }
        delete[] data;
        data=newdata;
        capacity=(capacity*2)+1;
    }
    data[size]=datain;
    size++;
    heapifiyUpward();
}

int heap::pop()
{
    int pop=data[0];
    data[0]=data[size-1];
    size--;
    heapifiyDownward();
    return pop;
}

void heap::heapifiyUpward()
{
    if(size<2)
    {
        return;
    }
    int i=size-1;
    int tmp;
    while(i!=0 && data[getParent(i)]<data[i])
    {
        tmp=data[getParent(i)];
        data[getParent(i)]=data[i];
        data[i]=tmp;
        i=getParent(i);
    }
}

void heap::heapifiyDownward()
{
    if(size<2)
    {
        return;
    }
    int i=0;
    int tmp;
    while(i<size/2 && (data[i]<data[getLeftChild(i)] || data[i]<data[getRightChild(i)]))
    {
        if(data[getLeftChild(i)]>data[getRightChild(i)])
        {
            tmp=data[i];
            data[i]=data[getLeftChild(i)];
            data[getLeftChild(i)]=tmp;
            i=getLeftChild(i);
        }
        else
        {
            tmp=data[i];
            data[i]=data[getRightChild(i)];
            data[getRightChild(i)]=tmp;
            i=getRightChild(i);
        }
    }

}

std::ostream &operator<<(std::ostream &outs, const heap &h)
{
    outs<<"{";
    for(size_t i=0; i<h.size; i++)
    {
        outs<<h.data[i]<<", ";
    }
    outs<<"}";
    return outs;
}
