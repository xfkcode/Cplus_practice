#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

class print02
{
public:
	void operator()(int val)
	{
		cout << val << " ";
	}
};
void print01(int val)
{
	cout << val << " ";
}
void test1()
{
	vector<int>v;
	for (int i = 0;i < 10;i++)
	{
		v.push_back(i);
	}
	for_each(v.begin(), v.end(), print01);
	cout << endl;
	for_each(v.begin(), v.end(), print02());
	cout << endl;
}
int main()
{
	test1();
	system("pause");
	return 0;
}