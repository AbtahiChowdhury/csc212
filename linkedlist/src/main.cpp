#include "linkedlist.h"
using namespace std;

int main()
{
	linkedlist l;
	cout<<"Inserting key 10 and value 2 at index 0"<<endl;
	l.insert(0,10,2);
	cout<<l<<endl<<endl;
	cout<<"Inserting key 5 and value 3 at index 1"<<endl;
	l.insert(1,5,3);
	cout<<l<<endl<<endl;
	cout<<"Inserting key 3 and value 4 at index 2"<<endl;
	l.insert(2,3,4);
	cout<<l<<endl<<endl;
	cout<<"Inserting key 3 and value 9 at index 5"<<endl;
	l.insert(5,3,9);
	cout<<l<<endl<<endl;
	cout<<"Inserting key 2 and value 7 at index 2"<<endl;
	l.insert(2,2,7);
	cout<<l<<endl<<endl;
	cout<<"Inserting key 8 and value 4 at index 10"<<endl;
	l.insert(10,8,4);
	cout<<l<<endl<<endl;
	cout<<"Sorting list"<<endl;
	l.sort();
	cout<<l<<endl<<endl;
	cout<<"Key 10 has value "<<l.getValue(10)<<endl<<endl;
	cout<<"Removing from index 3"<<endl;
	l.removeIndex(3);
	cout<<l<<endl<<endl;
	cout<<"Removing from index 1"<<endl;
	l.removeIndex(1);
	cout<<l<<endl<<endl;
	cout<<"Removing key 5"<<endl;
	l.removeKey(5);
	cout<<l<<endl<<endl;
	cout<<"Clearing list"<<endl;
	l.clearList();
	cout<<l<<endl;
}