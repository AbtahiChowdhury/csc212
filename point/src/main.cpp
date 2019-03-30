//#include <iostream>
#include "point.h"
#include "circle.h"

using namespace std;
using namespace ABTAHI_CSC212;

int main()
{
    point p1(1.5,3.5);
    point p2(3.5,6.5);
    point p3 = p1 + p2;
    p3.shift(-2, 3.5);
    p3.dilate(1.5);
    cout<<p3<<endl;

    circle c1(5);
    cout<<c1<<endl;
    return 0;
}
