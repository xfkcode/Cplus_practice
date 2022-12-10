#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

class Transform
{
public:
	int operator()(int v)
	{
		return v;
	}
};
class print1
{
public:
	void operator()(int v)
	{
		cout << v << " ";
	}
};
void test1()
{
	vector<int>v;
	for (int i = 0;i < 10;i++)
	{
		v.push_back(i);
	}
	vector<int>vt;
	vt.resize(v.size());
	transform(v.begin(), v.end(), vt.begin(), Transform());
	for_each(vt.begin(), vt.end(), print1());
}
int main()
{
	test1();
	system("pause");
	return 0;
}