#include<iostream>
#include<vector>
#include<numeric>
using namespace std;

void test1()
{
	vector<int>v1;
	v1.resize(10);

	fill(v1.begin(), v1.end(), 100);
	for (int i = 0;i < v1.size();i++)
	{
		cout << v1[i] << " ";
	}
	cout << endl;
}
int main()
{
	test1();
	system("pause");
	return 0;
}