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
	printVector(v1);

	v1.pop_back();
	printVector(v1);

	v1.insert(v1.begin(), 100);
	printVector(v1);

	v1.insert(v1.begin(), 2, 1000);
	printVector(v1);

	v1.erase(v1.begin());
	printVector(v1);

	v1.erase(v1.begin(),v1.end());
	printVector(v1);

	v1.clear();
	printVector(v1);
}
int main()
{
	test1();
	system("pause");
	return 0;
} 