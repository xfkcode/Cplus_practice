#include<iostream>
using namespace std;
#if 0
//终止递归函数1
// 没有参数终止
void debug()
{
	cout << "empty" << endl;
}
#endif

//终止递归函数2
//还有一个参数终止
template<typename T>
void debug(T tmp)
{
	cout << tmp << endl;
}
//可变参数的模板函数
//参数包展开函数
template<typename T1,typename ... T2>
void debug(T1 first, T2 ... last)
{
	cout << first << endl;
	debug(last ...);
}

int main()
{
	debug(1,2,3,4);
	/*
	debug(1,2,3,4);
	debug(2,3,4);
	debug(3,4);
	debug(4); 终止2
	debug();  终止1
	*/
	system("pause");
	return 0;
}