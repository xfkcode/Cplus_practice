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
	vector<int>vt1;
	vector<int>vt2;
	for (int i = 0;i < 10;i++)
	{
		v1.push_back(i);
		v2.push_back(i + 5);
	}
	vt1.resize(max(v1.size() , v2.size()));
	vt2.resize(max(v1.size() , v2.size()));
	vector<int>::iterator itend1 = set_difference(v1.begin(), v1.end(), v2.begin(), v2.end(), vt1.begin());
	vector<int>::iterator itend2 = set_difference(v2.begin(), v2.end(), v1.begin(), v1.end(), vt2.begin());

	for_each(vt1.begin(), itend1, mp);
	cout << endl;

	for_each(vt2.begin(), itend2, mp);
	cout << endl;

}
int main()
{
	test1();
	system("pause");
	return 0;
}