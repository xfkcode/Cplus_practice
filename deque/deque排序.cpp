#include<deque>
#include<iostream>
#include<Algorithm>
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
	d1.push_back(50);
	d1.push_back(5);
	d1.push_back(56);
	d1.push_back(100);
	d1.push_back(2);
	printDeque(d1);
	
	//ÅÅĞòÄ¬ÈÏÉıĞò
	sort(d1.begin(), d1.end());
	printDeque(d1);
}
int main()
{
	test1();
	system("pause");
	return 0;
}