#include<vector>
#include<iostream>
using namespace std;

void printVector(vector<int>& v)
{
	for (vector<int>::iterator it = v.begin();it != v.end();it++)
	{
		cout << *it << " ";
	}
	cout << endl;
}
void test1()
{
	vector<int> v1;
	for (int i = 0;i < 10;i++)
	{
		v1.push_back(i);
	}
	if (v1.empty() == 1)
	{
		cout << "v1空" << endl;
	}
	else
	{
		cout << "v1非空" << endl;
		cout << "v1容量：" << v1.capacity() << endl;
		cout << "v1大小：" << v1.size() << endl;
	}
	v1.resize(15);
	printVector(v1);

	v1.resize(20, 100);
	printVector(v1);

	v1.resize(5);
	printVector(v1);
}
int main()
{
	test1();
	system("pause");
	return 0;
}