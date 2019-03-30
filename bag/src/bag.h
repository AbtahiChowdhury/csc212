#ifndef ABTAHI_BAG
#define ABTAHI_BAG

#include <iostream>
#include "student.h"

class bag
{
    friend std::ostream& operator<<(std::ostream& outs, const bag& b);
    public:
        static const size_t CAPACITY = 20;
        bag();
        void insert(const int& keyin, student* const valuein);
        void remove(const int& keyrm);
        void clear();
        size_t size() const {return used;}
        int search(const int& keyin);
        student* getValue(const int& keyin);
    private:
        int binarySearch(const int A[], const int& l, const int& r, const int& x);
        int keys[CAPACITY];
        student* values[CAPACITY];
        size_t used;
};

#endif // !ABTAHI_BAG 
