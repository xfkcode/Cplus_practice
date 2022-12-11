#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

class Greater30
{
public:
	bool operator()(int val)
	{
		return val > 30;
	}
};
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
	v1.push_back(50);
	v1.push_back(25);

	replace_if(v1.begin(), v1.end(), Greater30(), 3000);
	for_each(v1.begin(), v1.end(), myprint);
	cout << endl;
}
int main()
{
	test1();
	system("pause");
	return 0;
}