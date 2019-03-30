#include <iostream>
#include "bag.h"
#include "student.h"
using namespace std;

int main()
{
    bag b;
    student *s1 = new student("Methodios Hatheway",15,9);
    student *s2 = new student("Delia Baines",16,10);
    student *s3 = new student("Mahesh Reuter",17,11);
    student *s4 = new student("Ilias Bosch",18,12);
    b.insert(1,s1);
    b.insert(2,s2);
    b.insert(2,s3);
    b.insert(3,s4);
    b.insert(4,s2);
    cout<<b<<endl;

    b.remove(1);
    cout<<b<<endl;

    cout<<*(b.getValue(3))<<endl;

    delete s1;
    delete s2;
    delete s3;
    delete s4;

    return 1;
}
