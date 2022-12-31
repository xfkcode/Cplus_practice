#include<iostream>
using namespace std;

int main()
{
	//强类型枚举，enum后面加上class或struct修饰
	enum class Status1 {OK,ERROR};
	enum struct Status2 {OK,ERROR};
	//枚举类型的作用域
	Status1 flag = Status1::OK;
	//可指定成员变量的类型
	enum struct Status3 :char {OK,ERROR};
	cout << sizeof(Status3::OK) << endl;

	system("pause");
	return 0;
}