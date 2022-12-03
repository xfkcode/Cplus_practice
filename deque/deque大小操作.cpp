#include<deque>
#include<iostream>
using namespace std;

void printDeque(const deque<int>& d)
{
	//Ö»¶Áµü´úÆ÷
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
	if (d1.empty() == 1)
	{
		cout << "d1¿Õ" << endl;
	}
	else 
	{
		cout << "d1·Ç¿Õ" << endl;
	}
	cout << d1.size() << endl;
	d1.resize(15);
	printDeque(d1);
	d1.resize(20, 100);
	printDeque(d1);
	d1.resize(5);
	printDeque(d1);
}
int main()
{
	test1();
	system("pause");
	return 0;
}