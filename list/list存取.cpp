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
	L1.push_front(100);
	L1.push_front(200);
	L1.push_front(300);
	printList(L1);

	cout << "首元素：" << L1.front() << endl;
	cout << "尾元素：" << L1.back() << endl;
	
	list<int>::iterator	it = L1.begin();
	it++;
	it--;
	//双向，不支持随机访问
}

int main()
{
	test1();
	system("pause");
	return 0;
}