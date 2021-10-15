#include<iostream>
using namespace std;
class StaticTest {
private:
	static int x;
};
class Test {
public:
	int r;
	//static依然被private限制，如果设为private的话。
	Test() :r(StaticTest::x) { cout << r << endl; }
};
int StaticTest::x = 2;

void test() {
	static int x =3; //该函数内static的作用域被限制在此
	x += 2;
}
int main() {
	Test t;
	return 0;
}