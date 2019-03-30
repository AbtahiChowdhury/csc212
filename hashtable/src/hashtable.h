#ifndef ABTAHI_HASHTABLE
#define ABTAHI_HASHTABLE
#include "hashbucket.h"

template <class item>
class hashtable;
template <class item>
std::ostream& operator<<(std::ostream& outs, const hashtable<item>& h);

template <class item>
class hashtable
{
    friend std::ostream& operator<< <>(std::ostream& outs, const hashtable<item>& h);
    public:
        hashtable(const int& capacityin=10);
        ~hashtable();
        void insert(const int& keyin, const item& datain);
        void remove(const int& keyrm);
        item retrieve(const int& keyin);
        void clearTable();
    private:
        int hashFunction(const int& keyin);
        void updateLoadFactor();
        void rehash();
        double loadfactor;
        int capacity;
        int initialcapacity;
        int totalsizeoftable;
        int multiplier;
        hashbucket<item>** data;
};

#include "hashtable.template"
#endif //!ABTAHI_HASHTABLE
