#include<iostream>
#include<memory>			//智能指针
using namespace std;

int main()
{
	shared_ptr<int> sp1(new int(11));				//创建智能指针对象
	cout << "*up1 =" << *sp1 << endl;
	shared_ptr<int> sp2 = sp1;						//拷贝构造，有两个对象与堆区空间绑定

	//计数器
	cout << "num = " << sp2.use_count() << endl;
	sp1 = nullptr;									//计数器减一
	cout << "num = " << sp2.use_count() << endl;

	sp2.reset();									//计数器减1，为0释放内存
	cout << "num = " << sp2.use_count() << endl;
	//cout << "*up2 =" << *sp2 << endl;


	system("pause");
	return 0;

}
