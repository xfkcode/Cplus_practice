#include<stack>
#include<iostream>
using namespace std;

void test1()
{
	stack<int>s;
	s.push(10);
	s.push(20);
	s.push(30);
	s.push(40);

	while (!s.empty())
	{
		cout << "栈顶元素：" << s.top() << endl;
		s.pop();
	}
	cout << "栈的大小" << s.size() << endl;
}
int main()
{
	test1();
	system("pause");
	return 0;
}