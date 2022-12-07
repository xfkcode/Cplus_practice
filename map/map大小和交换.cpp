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
	if (m.empty())
	{
		cout << "m¿Õ" << endl;
	}
	else
	{
		cout << "m·Ç¿Õ" << endl;
		cout << "m´óĞ¡" << m.size() << endl;
	}
	map<int, int>M;
	M.insert(pair<int, int>(5, 20));
	M.insert(pair<int, int>(4, 30));
	printMap(M);
	
	m.swap(M);
	printMap(m);
	printMap(M);
}
int main()
{
	test1();
	system("pause");
	return 0;
}