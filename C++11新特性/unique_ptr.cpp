#include<iostream>
#include<memory>			//智能指针
using namespace std;

class A
{
public:
	~A()
	{
		cout << "析构函数" << endl;
	}
};
int main()
{
	unique_ptr<int> up1(new int(11));	//创建智能指针对象，up1是唯一使用者
	cout << "*up1 =" << *up1 << endl;

	
	{
		unique_ptr<A> up2(new A);		//无需释放
		//人为指定释放堆区空间
		up2 = nullptr;					//1
		up2 = NULL;						//2
		up2.reset();					//3
		cout << "++++++++++++++++++++++++" << endl;
	}
	cout << "------------------------" << endl;

	//unique_ptr<int> up2 = up1;				//禁用拷贝构造
	unique_ptr<int> up2 = std::move(up1);		//up1转义up2，up1不能在使用
	cout << "*up2 = " << *up2 << endl;
	//cout << "*up1 = " << *up1 << endl;		//err

	unique_ptr<int> up3(new int(11));			
	up3.reset(new int(22));						//先释放原来堆区内容，重新给up1绑定一个新的堆区内容
	cout << "*up3 = " << *up3 << endl;

	unique_ptr<int> up4(new int(11));
	//释放控制权，不释放堆区内存
	int* p = up4.release();
	cout << *p << endl;
	//cout << "*up4 = " << *up4 << endl;		//err
	delete p;
	
	system("pause");
	return 0;

}
