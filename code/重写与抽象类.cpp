#include<iostream>
using namespace std;

class base {
public:
	virtual void print() = 0;
};

class derive: public base{
public:
	virtual void print();
};
/*重写是返回值相同，函数名称以及形参类型、个数相同。（定义不同），有
纯虚函数的是抽象类，抽象类不可实例化，派生类继承后再重写，派生类就可实例化
Override is when the return value is the same, the function name and parameter type and number are the same. (different definitions), yes
A pure virtual function is an abstract class. An abstract class cannot be instantiated. 
A derived class can be instantiated if it is inherited and overridden*/
void derive::print() {
	int y=0;
	cout << y << endl;
}
int main() {
	//base b;
	derive d;
	d.print();
	return 0;
}