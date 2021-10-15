#include<iostream>
using namespace std;

class Person {
public:
	//传统方法初始化
	/*Person(int a,int b,int c) {
		m_A = a;
		m_B = b;
		m_C = c;
	}*/

	//初始化列表
	Person(int a,int b,int c) :m_A(10), m_B(20), m_C(30) {

	}
	int m_A;
	int m_B;
	int m_C;
};

void test01() {
	//Person p(10, 20, 30);
	Person p;
	cout << p.m_A
		<< p.m_B
		<< p.m_C << endl;
}
int main() {
	test01();
	return 0;

}