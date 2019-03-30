#include "linkedlist.h"

linkedlist::linkedlist()
{
    headptr=nullptr;
    tailptr=nullptr;
    size=0;
}

linkedlist::~linkedlist()
{
    removeAll(headptr);
}

void linkedlist::insertAtHead(int keyin, int valuein)
{
    if(size==0)
    {
        nodekey* newnodekey = new nodekey(keyin);
        nodevalue* newnodevalue = new nodevalue(valuein,nullptr,newnodekey);
        newnodekey->setNextNode(newnodevalue);
        headptr=newnodekey;
        tailptr=newnodevalue;
        size++;
        return;
    }
    nodekey* newnodekey = new nodekey(keyin);
    nodevalue* newnodevalue = new nodevalue(valuein,headptr,newnodekey);
    newnodekey->setNextNode(newnodevalue);
    headptr->setPreviousNode(newnodevalue);
    headptr=newnodekey;
    size++;
    return;
}

void linkedlist::insertAtTail(int keyin, int valuein)
{
    if(size==0)
    {
        nodekey* newnodekey = new nodekey(keyin);
        nodevalue* newnodevalue = new nodevalue(valuein,nullptr,newnodekey);
        newnodekey->setNextNode(newnodevalue);
        headptr=newnodekey;
        tailptr=newnodevalue;
        size++;
        return;
    }
    nodekey* newnodekey = new nodekey(keyin,nullptr,tailptr);
    nodevalue* newnodevalue = new nodevalue(valuein,nullptr,newnodekey);
    newnodekey->setNextNode(newnodevalue);
    tailptr->setNextNode(newnodekey);
    tailptr=newnodevalue;
    size++;
    return;
}

void linkedlist::insert(size_t indexin, int keyin, int valuein)
{
    nodekey* currentkey=headptr;
    for(size_t i=0; i<size; i++)
    {
        if(currentkey->getKey()==keyin)
        {
            currentkey->getNext()->setValue(valuein);
            return;
        }
        currentkey=currentkey->getNext()->getNext();
    }

    if(indexin==0)
    {
        insertAtHead(keyin, valuein);
        return;
    }
    if(indexin>=size)
    {
        insertAtTail(keyin, valuein);
        return;
    }

    currentkey=headptr;
    for(size_t i=0; i<indexin; i++)
    {
        currentkey=currentkey->getNext()->getNext();
    }
    nodekey* newnodekey = new nodekey(keyin,nullptr,currentkey->getPrevious());
    nodevalue* newnodevalue = new nodevalue(valuein,currentkey,newnodekey);
    newnodekey->setNextNode(newnodevalue);
    currentkey->getPrevious()->setNextNode(newnodekey);
    currentkey->setPreviousNode(newnodevalue);
    size++;
    return;
}

void linkedlist::removeIndex(size_t indexrm)
{
    if(indexrm==0)
    {
        nodekey* currentkey=headptr->getNext()->getNext();
        currentkey->setPreviousNode(nullptr);
        delete headptr->getNext();
        delete headptr;
        headptr=currentkey;
        size--;
        return;
    }
    if(indexrm==size-1)
    {
        nodevalue* currentkey=tailptr->getPrevious()->getPrevious();
        currentkey->setNextNode(nullptr);
        delete tailptr->getPrevious();
        delete tailptr;
        tailptr=currentkey;
        size--;
        return;
    }
    if(indexrm<size)
    {
        nodekey* currentkey=headptr;
        for(size_t i=0; i<indexrm; i++)
        {
            currentkey=currentkey->getNext()->getNext();
        }
        currentkey->getNext()->getNext()->setPreviousNode(currentkey->getPrevious());
        currentkey->getPrevious()->setNextNode(currentkey->getNext()->getNext());
        delete currentkey->getNext();
        delete currentkey;
        size--;
        return;
    }
}

void linkedlist::removeKey(int keyrm)
{
    nodekey* currentkey=headptr;
    for(size_t i=0; i<size; i++)
    {
        if(currentkey->getKey()==keyrm)
        {
            removeIndex(i);
            return;
        }
        currentkey=currentkey->getNext()->getNext();
    }
}

int linkedlist::getValue(int keyin)
{
    nodekey* currentkey=headptr;
    for (size_t i=0; i<size; i++)
    {
        if(currentkey->getKey()==keyin)
        {
            return currentkey->getNext()->getValue();
        }
        currentkey=currentkey->getNext()->getNext();
    }
}

void linkedlist::clearList()
{
    removeAll(headptr);
    headptr=nullptr;
    tailptr=nullptr;
    size=0;
}

std::ostream& operator<<(std::ostream& outs, const linkedlist& l)
{
    outs<<"{";
    if(l.headptr!=nullptr)
    {
        nodekey* currentkey=l.headptr;
        nodevalue* currentvalue=l.headptr->getNext();
        for(size_t i=0; i<l.size; i++)
        {
            outs<<currentkey->getKey()<<":"<<currentvalue->getValue()<<" ";
            if(currentkey->getNext()->getNext()==nullptr)
            {
                break;
            }
            currentkey=currentkey->getNext()->getNext();
            currentvalue=currentvalue->getNext()->getNext();
        }
    }
    outs<<"}";
    return outs;
}

void linkedlist::removeAll(nodekey* headptrin)
{
    if(headptrin==nullptr)
    {
        return;
    }
    removeAll(headptrin->getNext()->getNext());
    delete headptrin->getNext();
    delete headptrin;
}

bool linkedlist::isSorted()
{
    bool check=true;
    nodekey* currentkey=headptr;
    while(currentkey->getNext()->getNext()!=nullptr)
    {
        if(currentkey->getKey()>currentkey->getNext()->getNext()->getKey())
        {
            check=false;
        }
        currentkey=currentkey->getNext()->getNext();
    }
    return check;
}

void linkedlist::sort() //Has a time complexity of O(n^2)
{
    if(isSorted())
    {
        return;
    }
    else
    {
        nodekey* currentkey=headptr;
        while(currentkey->getNext()->getNext()!=nullptr)
        {
            if(currentkey->getKey()>currentkey->getNext()->getNext()->getKey())
            {
                if(currentkey->getNext()->getNext()->getNext()->getNext()==nullptr)
                {
                    nodevalue* b=currentkey->getNext()->getNext()->getNext();
                    currentkey->getPrevious()->setNextNode(currentkey->getNext()->getNext());
                    currentkey->getNext()->getNext()->getNext()->setNextNode(currentkey);
                    currentkey->getNext()->getNext()->setPreviousNode(currentkey->getPrevious());
                    currentkey->getNext()->setNextNode(nullptr);
                    currentkey->setPreviousNode(b);
                    tailptr=currentkey->getNext();
                    break;
                }
                else if(currentkey->getPrevious()==nullptr)
                {
                    nodekey* a=currentkey->getNext()->getNext()->getNext()->getNext();
                    nodevalue* b=currentkey->getNext()->getNext()->getNext();
                    a->setPreviousNode(currentkey->getNext());
                    currentkey->getNext()->getNext()->getNext()->setNextNode(currentkey);
                    currentkey->getNext()->getNext()->setPreviousNode(nullptr);
                    headptr=currentkey->getNext()->getNext();
                    currentkey->getNext()->setNextNode(a);
                    currentkey->setPreviousNode(b);
                    break;
                }
                else
                {
                    nodekey* a=currentkey->getNext()->getNext()->getNext()->getNext();
                    nodevalue* b=currentkey->getNext()->getNext()->getNext();
                    currentkey->getPrevious()->setNextNode(currentkey->getNext()->getNext());
                    a->setPreviousNode(currentkey->getNext());
                    currentkey->getNext()->getNext()->getNext()->setNextNode(currentkey);
                    currentkey->getNext()->getNext()->setPreviousNode(currentkey->getPrevious());
                    currentkey->getNext()->setNextNode(a);
                    currentkey->setPreviousNode(b);
                    break;
                }
            }
            currentkey=currentkey->getNext()->getNext();
        }
        sort();
    }
}
