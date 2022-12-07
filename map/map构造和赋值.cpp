#include<map>
#include<iostream>
using namespace std;

void printMap(map<int, int>& m)
{
	for (map<int, int>::iterator it = m.begin();it != m.end();it++)
	{
		cout << "key=" << it->first << "value=" << it->second << endl;
	}
	cout << endl;
}
void test1()
{
	//keyÅÅĞò
	map<int, int>m;
	m.insert(pair<int, int>(1, 10));
	m.insert(pair<int, int>(5, 20));
	m.insert(pair<int, int>(4, 30));
	m.insert(pair<int, int>(3, 40));
	printMap(m);
	map<int, int>m1(m);
	printMap(m1);
	map<int, int>m2;
	m2 = m1;
	printMap(m2);
}
int main()
{
	test1();
	system("pause");
	return 0;
}