#include<iostream>
using namespace std;

class A {
public:
	A() { cout << "A"; }
};
class B {
public:
	B() { cout << "B"; }
};

class C : public A, private B {//多个基类在类派生表中出现的顺序
public:
	C() { cout << "C"; }
private:
	
	A a;//类成员对象构造函数的顺序是，被声明的顺序
	B b;
};

struct J {
	char a;
	char b;
	double c;
};

//内存对齐
struct E {
	char a;
	double c;
	char b;
	
};
void test() {
	//C c;
	cout << sizeof(J) << endl;
	cout << sizeof(E) << endl;
}
int main() {
	test();
	return 0;
}