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

class C : public A, private B {//������������������г��ֵ�˳��
public:
	C() { cout << "C"; }
private:
	
	A a;//���Ա�����캯����˳���ǣ���������˳��
	B b;
};

struct J {
	char a;
	char b;
	double c;
};

//�ڴ����
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