#include<iostream>
#include<string>
#include<vector>
#include<algorithm>
using namespace std;

class GreaterFive
{
public:
	//一元谓词
	bool operator()(int val)
	{
		return val > 5;
	}
};
class MyCompare
{
public:
	//二元谓词
	bool operator()(int v1, int v2)
	{
		return v1 > v2;
	}
};
void test1()
{
	vector<int>v;
	for (int i = 0;i < 10;i++)
	{
		v.push_back(i);
	}
	//查找容器中有没有大于5的元素
	vector<int>::iterator it = find_if(v.begin(), v.end(), GreaterFive());
	if (it == v.end())
	{
		cout << "未找到" << endl;
	}
	else
	{
		cout << "找到了" << *it << endl;
	}
}
void test2()
{
	vector<int>v;
	v.push_back(50);
	v.push_back(20);
	v.push_back(5);
	v.push_back(505);
	sort(v.begin(), v.end(), MyCompare());
	for (int i = 0;i < v.size(); i++)
	{
		cout << v[i] << " ";
	}
	cout << endl;
}
int main()
{
	test1();
	test2();
	system("pause");
	return 0;
}