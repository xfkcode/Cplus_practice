#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

void myprint(int val)
{
	cout << val << " ";
}
void test1()
{
	vector<int>v1;
	vector<int>v2;
	v1.push_back(15);
	v1.push_back(15);
	v1.push_back(20);
	v1.push_back(23);
	v1.push_back(25);


	for_each(v1.begin(), v1.end(), myprint);
	cout << endl;

	v2.resize(v1.size());
	copy(v1.begin(), v1.end(), v2.begin());
	for_each(v2.begin(), v2.end(), myprint);
	cout << endl;
}
int main()
{
	test1();
	system("pause");
	return 0;
}