#include<iostream>
using namespace std;
class StaticTest {
private:
	static int x;
};
class Test {
public:
	int r;
	//static��Ȼ��private���ƣ������Ϊprivate�Ļ���
	Test() :r(StaticTest::x) { cout << r << endl; }
};
int StaticTest::x = 2;

void test() {
	static int x =3; //�ú�����static�������������ڴ�
	x += 2;
}
int main() {
	Test t;
	return 0;
}