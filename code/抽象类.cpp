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
/*��д�Ƿ���ֵ��ͬ�����������Լ��β����͡�������ͬ�������岻ͬ������
���麯�����ǳ����࣬�����಻��ʵ������������̳к�����д��������Ϳ�ʵ����
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