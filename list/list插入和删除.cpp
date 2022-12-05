#include<list>
#include<iostream>
using namespace std;

void printList(const list<int>& L)
{
	for (list<int>::const_iterator it = L.begin();it != L.end();it++)
	{
		cout << *it << " ";
	}
	cout << endl;
}
void test1()
{
	list<int>L1;
	L1.push_back(10);
	L1.push_back(20);
	L1.push_back(30);
	L1.push_back(40);
	printList(L1);
	L1.push_front(100);
	L1.push_front(200);
	L1.push_front(300);
	printList(L1);

	L1.pop_back();
	L1.pop_front();
	printList(L1);

	list<int>::iterator it = L1.begin();
	L1.insert(++it, 1000);
	printList(L1);

	it = L1.begin();
	L1.erase(++it);
	printList(L1);

	L1.remove(100);
	printList(L1);

	L1.clear();
	printList(L1);
}

int main()
{
	test1();
	system("pause");
	return 0;
}