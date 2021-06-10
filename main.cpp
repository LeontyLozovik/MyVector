#include <iostream>
#include <Windows.h>
#include "MyVector.h"

using namespace::std;

int main()
{
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);
	MyVector <int> a;

	a.push(5);
	a.push(4);
	a.push(8);
	a.push(1);

	MyVector<int>::Iterator i;
	for (i = a.begin(); i != a.end(); i++)
	{
		cout << *i << " ";
	}

	cout << endl;

	a.push(7, 3);
	for (i=a.begin(); i != a.end(); i++)
	{
		cout << *i << " ";
	}

	cout << endl << endl;

	i--;
	*i = 1000;
	cout << *i << endl;

	cout << a.get_first() << " ";
	cout << a.get_last() << endl;

	cout << a.size() << endl;

	int q = a.empty();
	cout << q << endl;

	a.swap(0, 1);
	a.swap(2, 3);
	for (i = a.begin(); i != a.end(); i++)
	{
		cout << *i << " ";
	}

	a.clear();
	cout << endl << a.size();
	return 0;
}
