#include<map>
#include<iostream>
using namespace std;

class comp
{
public:
	bool operator()(int v1, int v2)const
	{
		return v1 > v2;
	}
};
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
	//Ä¬ÈÏkeyÉıĞò
	map<int, int>m;
	m.insert(pair<int, int>(1, 10));
	m.insert(pair<int, int>(2, 20));
	m.insert(pair<int, int>(3, 30));
	m.insert(pair<int, int>(4, 40));
	printMap(m);

	map<int, int, comp>M;
	M.insert(pair<int, int>(1, 10));
	M.insert(pair<int, int>(2, 20));
	M.insert(pair<int, int>(3, 30));
	M.insert(pair<int, int>(4, 40));
	for (map<int, int, comp>::iterator mit = M.begin();mit != M.end();mit++)
	{
		cout << "key=" << mit->first << "value=" << mit->second << endl;
	}
	cout << endl;
}
int main()
{
	test1();
	system("pause");
	return 0;
}