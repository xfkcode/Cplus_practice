#include<iostream>
using namespace std;
/*
* constexpr函数限制
*	函数中只能有一个return语句（有极少特例）
*	函数必须返回值（不能是void函数）
*	在使用前必须已有定义
*	return返回语句表达式中不能使用非常量表达式的函数、全局数据，且必须是一个常量表达式
*/
/*
* constexpr构造函数限制
*	函数提必须为空
*	初始化列表只能由常量表达式来赋值
*/
int getNUM1()
{
	return 3;
}
const int getNUM2()
{
	return 3;
}
constexpr int getNUM3()
{
	return 3;
}
//constexpr后面的是常量表达式，int tmp赋值理应当只能是常量，而constexpr修饰更加灵活
constexpr int tmp = getNUM3();	
//tmp也是常量
enum { e1 = tmp };
int main()
{
	//常量表达式允许一些计算在编译阶段
	//枚举成员初始化，必须是整形常量
	//报错>>enum {e1=getNUM1(), e2 =1 };
	//报错>>enum {e1=getNUM2(), e2 =1 };
	enum {e1=getNUM3(), e2 =1 };

	system("pause");
	return 0;
}