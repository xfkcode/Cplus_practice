#include<iostream>
#include<vector>
using namespace std;

int main()
{
	/*
	* for(declaration:expression){
	*		循环体
	* }
	* declaration：表示此处要定义一个变量，该变量的类型为要遍历序列中存储元素的类型
	* 可用auto
	* expression：需要遍历的序列，数组或容器还可以用{}初始化的序列
	*/
	vector<int> v = { 1,2,3,4,5 };
	for (auto item : v)
		cout << item << " ";
	cout << endl;
	//引用可修改
	for (auto &item : v)
		item++;
	return 0;
}