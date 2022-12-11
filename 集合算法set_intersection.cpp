#include<iostream>
#include<vector>
#include<numeric>
#include<algorithm>
using namespace std;

void mp(int val)
{
	cout << val << " ";
}
void test1()
{
	vector<int>v1;
	vector<int>v2;
	vector<int>vt;
	for (int i = 0;i < 10;i++)
	{
		v1.push_back(i);
		v2.push_back(i + 5);
	}
	vt.resize(min(v1.size(), v2.size()));
	vector<int>::iterator itend = set_intersection(v1.begin(), v1.end(), v2.begin(), v2.end(), vt.begin());
	
	for_each(vt.begin(), itend, mp);
	cout << endl;
}
int main()
{
	test1();
	system("pause");
	return 0;
}