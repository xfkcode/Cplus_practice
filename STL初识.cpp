#include<iostream>
#include<vector>
#include<Algorithm>
using namespace std;

void myprint(int val)
{
	cout << val << endl;
}
void test1()
{
	vector<int> v;

	v.push_back(10);
	v.push_back(20);
	v.push_back(30);
	v.push_back(40);

	vector<int>::iterator itBegin = v.begin();//指向向量第一个数据
	vector<int>::iterator itEnd = v.end();//指向向量最后一个数据的下一个位置

	//遍历法1
	while (itBegin!=itEnd)
	{
		cout << *itBegin << endl;
		itBegin++;
	}

	//遍历法2
	for (vector<int>::iterator it = v.begin();it != v.end();it++)
	{
		cout << *it << endl;

	}

	//遍历法3
	for_each(v.begin(), v.end(), myprint);

}
int main()
{
	test1();
	system("pause");
	return 0;
}