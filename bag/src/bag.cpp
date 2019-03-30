#include "bag.h"
#include <assert.h>

bag::bag()
{
    used=0;
}

void bag::insert(const int& keyin, student* const valuein)
{
    assert(used<CAPACITY);

    if(used==0)
    {
        keys[0]=keyin;
        values[0]=valuein;
        used++;
    }

    if(keyin>keys[used-1])
    {
        keys[used]=keyin;
        values[used]=valuein;
        used++;
        return;
    }

    for(size_t i=0; i<used; i++)
    {
        if(keyin==keys[i])
        {
            values[i]=valuein;
            return;
        }

        if(keyin<keys[i])
        {
            for (size_t j=used; j>i; j--)
            {
                keys[j]=keys[j-1];
                values[i]=values[i-1];
            }
            keys[i]=keyin;
            values[i]=valuein;
            used++;
            return;
        }
    }
}

void bag::remove(const int& keyrm)
{
    int index=search(keyrm);
    if(index!=-1)
    {
        for(size_t j=index; j<used; j++)
        {
            keys[j]=keys[j+1];
            values[j]=values[j+1];
        }
        used--;
    }
}

void bag::clear()
{
    used=0;
}

int bag::search(const int& keyin)
{
    return binarySearch(keys,0,used,keyin);
}

student* bag::getValue(const int& keyin)
{
    int index=search(keyin);
    return values[index];
}

std::ostream& operator<<(std::ostream& outs, const bag& b)
{
    outs<<"{";
    for (size_t i=0; i<b.used; i++)
    {
        outs<<" ("<<b.keys[i]<<":"<<*(b.values[i])<<")";
    }
    outs<<" }";
    return outs;
}

int bag::binarySearch(const int A[], const int& f, const int& l, const int& n)
{
    int index;
    if (f>l)
    {
        index=-1;
    }
    else
    {
        int m=(f+l)/2;
        if (n==A[m])
        {
            index=m;
        }
        else if(n<A[m])
        {
            index=binarySearch(A,f,m-1,n);
        }
        else
        {
            index=binarySearch(A,m+1,l,n);
        }
    }
    return index;
}
