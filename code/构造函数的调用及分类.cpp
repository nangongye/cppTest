#include<iostream>
using namespace std;

//按照参数分类 无参（默认）构造和有参构造
class Person {
public://普通构造函数
	Person() {
		cout << "Person的无参构造" << endl;
	}

	Person(int a) {
		age = a;
		cout << "Person的有参构造" << endl;
	}
	~Person() {//程序在对象销毁前会自动调用析构
		cout << "Person的析构函数调用" << endl;
	}
	//拷贝构造函数，例把Percon中的全部数据传到另一个Person函数，这个时候就叫拷贝构造函数
	Person(const Person& p) {/*拷贝不能改变他原来的数据，所以需要const
							 另外，我们还需要引用*/
		age = p.age;
	}
	int age;
};
void test01() {
	////括号法
	//Person p;//默认构造函数调用
	//Person p2(10);//有参函数调用
	//Person p3(p2);//拷贝构造函数
	////Person p1;调用默认构造函数时，不要加（），编译器会认为你在声明函数，不是在创建对象
	//cout << "P2的年龄为： " << p2.age << endl;
	//cout << "p3的年龄为： " << p3.age << endl;

	//显示法
	Person p1;
	Person p2 = Person(10);
	Person p3 = Person(p2);
	//Person(10);//匿名对象 当前执行结束后，系统会立即回收匿名对象

	//Person(p3);//不要利用拷贝构造函数，初始化匿名对象，编译器会认为Person(p3) == Peroson p3，对象重复
	//cout << "测试用" << endl;
	
	//隐式转换法
	Person p4 = 10;//相当于写了Person p4 = Person(10)
}
int main() {
	test01();
	return 0;
}