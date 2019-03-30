#include "heap.h"
using namespace std;

int main()
{
	heap h;
	h.push(11);
	h.push(5);
	h.push(23);
	h.push(19);
	h.push(2);
	cout<<h<<endl;
	cout<<h.pop()<<endl;
	cout<<h.pop()<<endl;
	cout<<h.pop()<<endl;
	cout<<h.pop()<<endl;
	cout<<h.pop()<<endl;
	cout<<h<<endl;
}