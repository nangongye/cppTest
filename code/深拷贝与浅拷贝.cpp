#include<iostream>
using namespace std;
/*深拷贝就是自己从一个堆区创建一个内存，浅拷贝是系统实现的拷贝
析构代码用于释放干净内存*/
class Person {
public:
	Person() {
		cout << "Person的默认构造函数调用" << endl;
	}
	Person(int age,int Height) {
		m_Age = age;
		m_Height = new int(Height);//用指针去接收分配的内存空间，创建一个身高*4大小的空间
		cout << "Person的有参构造函数调用" << endl;
	}
	/*浅拷贝带来的问题就是堆区的内存重复释放。为什么会发生异常错误？
	程序执行完毕之后，就要执行对象销毁程序即析构函数，代码如下
	首先*Height所指向的内存地址是0x0011（假设）,执行delete程序,
	此时会释放掉0x0011的内存，而拷贝的另一对象p2也是指向Height的内存空间，
	当0x0011的内存被释放是，p2找不到内存就会报错，浅拷贝的问题，要用深拷贝解决
	*/
	~Person() {
		/*if (m_Height != NULL) {
			delete m_Height;
			m_Height = NULL;
		}*/

		cout << "Person的析构函数调用" << endl;
	}
	//自己实现拷贝构造函数，解决浅拷贝带来的问题
	Person(const Person& p) {
		cout << "Person 拷贝构造函数用" << endl;
		m_Age = p.m_Age;
		//m_Height = p.m_Height;编译器默认执行的就是这行代码，这是例子
		
		//深拷贝操作
		m_Height = new int(*p.m_Height);
	}
	int* m_Height;//身高
	int m_Age;
};

void test01() {
	Person p1(18,160);//创建对象
	cout << "p1的年龄为： " << p1.m_Age <<  "身高为： " << *p1.m_Height <<endl;
	Person p2(p1);
	cout << "p2年龄为： " << p2.m_Age <<"身高为 ： "  << *p2.m_Height <<endl;//即使不提供拷贝构造函数编译器也依然会提供
}
int main() {

	test01();
	return 0;
}