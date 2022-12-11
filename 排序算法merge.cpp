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
	//ÓÐÐòºÏ²¢
	vector<int>v1;
	vector<int>v2;
	
	v1.push_back(15);
	v1.push_back(15);
	v1.push_back(20);
	v1.push_back(23);
	v1.push_back(25);

	v2 = v1;

	vector<int>vt;
	vt.resize(v1.size() + v2.size());
	merge(v1.begin(), v1.end(), v2.begin(), v2.end(), vt.begin());
	
	for_each(vt.begin(), vt.end(), myprint);
	cout << endl;
}
int main()
{
	test1();
	system("pause");
	return 0;
}