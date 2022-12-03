#include<deque>
#include<iostream>
using namespace std;

void printDeque(const deque<int>& d)
{
	//只读迭代器
	for (deque<int>::const_iterator it = d.begin();it != d.end();it++)
	{
		cout << *it << " ";
	}
	cout << endl;
}
void test1()
{
	deque<int> d1;
	for (int i = 0;i < 10;i++)
	{
		d1.push_back(i);
	}
	printDeque(d1);
	
	for (int i = 0;i < d1.size();i++)
	{
		cout << d1[i] << " ";
	}
	cout << endl;
	for (int i = 0;i < d1.size();i++)
	{
		cout << d1.at(i) << " ";
	}
	cout << endl;
	cout << "第一个元素" << d1.front() << endl;
	cout << "最后一个元素" << d1.back() << endl;
}
int main()
{
	test1();
	system("pause");
	return 0;
}