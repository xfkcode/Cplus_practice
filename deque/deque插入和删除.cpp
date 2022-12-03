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
		//Î²²å
		d1.push_back(i);
	}
	printDeque(d1);
	//Í·²å
	d1.push_front(100);
	printDeque(d1);
	//Î²É¾
	d1.pop_back();
	printDeque(d1);
	//Í·É¾
	d1.pop_front();
	printDeque(d1);
}
void test2()
{
	deque<int> d1;
	d1.push_back(10);
	d1.push_back(20);
	d1.push_back(30);
	d1.push_back(40);
	printDeque(d1);

	d1.insert(d1.begin(), 10000);
	printDeque(d1);

	d1.insert(d1.begin(), 2, 10000);
	printDeque(d1);

	deque<int>d2;
	d2.push_back(1);
	d2.push_back(1);
	d2.push_back(1);

	d1.insert(d1.begin(), d2.begin(), d2.end());
	printDeque(d1);
}
void test3()
{
	deque<int> d1;
	d1.push_back(10);
	d1.push_back(20);
	d1.push_back(30);
	d1.push_back(40);

	deque<int>::iterator it = d1.begin();
	it++;
	d1.erase(it);
	printDeque(d1);

	d1.erase(d1.begin(), d1.end());
	printDeque(d1);

	d1.clear();
	printDeque(d1);
}
int main()
{
	test1();
	test2();
	test3();
	system("pause");
	return 0;
}