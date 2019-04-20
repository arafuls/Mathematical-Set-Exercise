// AUTHOR - AUSTIN RAFULS
#include <iostream>
#include "MySet.h"
#include "MySet.cpp"	// Needed to include implementation for templated classes in MVS.
using namespace std;

int main()
{
	/* Sample Test Code */

	// Create first object
	MySet<int> obj1;
	obj1.add(10);
	obj1.add(20);
	obj1.add(20);		// Duplicate handling demo, uses exists() method
	obj1.add(60);
	obj1.add(40);
	obj1.add(30);
	cout << "Object 1" << endl;
	obj1.display();		// Display contents
	obj1.size();		// Return (but also displays) size
	cout << endl << endl;		// Make things pretty

	MySet<int> obj2;
	obj2.add(40);
	obj2.add(50);
	obj2.add(80);
	obj2.add(10);
	obj2.add(60);
	obj2.remove(80);	// Removal demo
	cout << "Object 2" << endl;
	obj2.display();		// Display contents
	obj2.size();		// Return (but also displays) size
	cout << endl << endl;		// Make things pretty

	// Result of intersection is returned and used to
	// instantiate a new object using a custom
	// constructor.
	MySet<int> obj3(obj1.intersect(obj2));
	cout << "Object 3" << endl;
	obj3.display();
	obj3.size();

	// Result of union is returned and used to
	// instantiate a new object using a custom
	// constructor.
	MySet<int> obj4(obj1._union(obj2));
	cout << "Object 4" << endl;
	obj4.display();
	obj4.size();

	return 0;
}
