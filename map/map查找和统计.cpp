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
	m.insert(pair<int, int>(2, 20));
	m.insert(pair<int, int>(3, 30));
	m.insert(pair<int, int>(4, 40));

	map<int, int>::iterator pos = m.find(3);

	if (pos != m.end())
	{
		cout << "ÕÒµ½ÁË" << endl;
	}
	else
	{
		cout << "Î´ÕÒµ½" << endl;
	}

	int num = m.count(3);
	cout << "num=" << num << endl;
}
int main()
{
	test1();
	system("pause");
	return 0;
}