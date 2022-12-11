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
	vector<int>v;
	v.push_back(15);
	v.push_back(15);
	v.push_back(20);
	v.push_back(15);
	v.push_back(5);
	sort(v.begin(), v.end());
	for_each(v.begin(), v.end(), myprint);
	cout << endl;

	sort(v.begin(), v.end(), greater<int>());
	for_each(v.begin(), v.end(), myprint);
	cout << endl;

}
int main()
{
	test1();
	system("pause");
	return 0;
}