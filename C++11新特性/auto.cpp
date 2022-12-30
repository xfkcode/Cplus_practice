#include<iostream>
#include<vector>
using namespace std;

int main()
{
	//1.auto 基本用法
	auto n = 10;
	auto f = 12.8;
	auto p = &n;
	//可以连续定义多个变量
	//推导不能有二义性（同一个类型）
	auto a = 10, b = 20;
	//auto 注意：必须初始化
	// 错误示范 auto x;
	//auto 注意：函数参数不能使用auto
	// 错误示范 void func(auto x){}
	//auto 注意：不能定义数组
	// 错误示范 auto str[] = data;
	//2.auto 应用
	//stl定义迭代器
	vector<int>v = { 1,2,3,4,5 };
	for (auto it = v.begin();it != v.end();it++)
	{
		cout << *it << " ";
	}
	return 0;
}