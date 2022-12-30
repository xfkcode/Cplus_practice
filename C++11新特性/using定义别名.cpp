#include<iostream>
#include<map>
using namespace std;

int main()
{
	//typedef重定义一个类型
	typedef void(*function)(int, int);		//函数指针类型定义
	typedef double db;
	typedef std::map<std::string, int> map_str_int;
	//using 定义别名
	using function = void(*)(int, int);		//函数指针类型定义
	using db = double;
	using map_str_int = std::map<std::string, int>;
	return 0;
}