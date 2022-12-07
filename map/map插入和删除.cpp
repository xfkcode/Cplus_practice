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
	//key排序
	map<int, int>m;
	m.insert(pair<int, int>(1, 10));
	
	m.insert(make_pair(2, 22));

	m.insert(map<int, int>::value_type(6, 60));

	m[7] = 70;
	printMap(m);

	//没有会创建出来对组值为零
	cout << m[5] << endl;
	printMap(m);

	m.erase(m.begin());
	printMap(m);

	m.erase(5);
	printMap(m);

	m.clear();
	printMap(m);
}
int main()
{
	test1();
	system("pause");
	return 0;
}