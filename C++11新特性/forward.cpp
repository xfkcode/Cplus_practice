#include<iostream>
using namespace std;

template<typename T>
void func(const T&)
{
	cout << "const T&" << endl;
}
template<typename T>
void func(T&)
{
	cout << "T&" << endl;
}
#if 0
template<typename T>
void forward_val(const T& tmp)
{
	func(tmp);
}
template<typename T>
void forward_val(T& tmp)
{
	func(tmp);
}
#endif
//只写一个版本，涉及引用折叠
template<typename T>
void forward_val(T&& tmp)
{
	func(std::forward<T>(tmp));
}
int main()
{
	//需要将一组参数原封不动的传递给另一个函数
	int a = 0;
	const int& b = 1;
	forward_val(a);
	forward_val(b);
	system("pause");
	return 0;
}