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
	v1.push_back(15);
	v1.push_back(15);
	v1.push_back(20);
	v1.push_back(23);
	v1.push_back(25);


	for_each(v1.begin(), v1.end(), myprint);
	cout << endl;

	reverse(v1.begin(), v1.end());
	for_each(v1.begin(), v1.end(), myprint);
	cout << endl;
}
int main()
{
	test1();
	system("pause");
	return 0;
}