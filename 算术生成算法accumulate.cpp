#include<iostream>
#include<vector>
#include<numeric>
using namespace std;

void test1()
{
	vector<int>v1;

	v1.push_back(15);
	v1.push_back(15);
	v1.push_back(20);
	v1.push_back(50);
	v1.push_back(25);

	int ret = accumulate(v1.begin(), v1.end(), 0);
	cout << "total=" << ret << endl;
}
int main()
{
	test1();
	system("pause");
	return 0;
}