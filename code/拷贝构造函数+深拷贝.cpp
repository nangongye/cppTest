#include<iostream>
using namespace std;
class Base {
public:
	Base(int Age, int Hight);
	Base(const Base& copy);
	void printInfo();
	virtual ~Base() { cout << "��������" << endl; }
private:
	int* hight;
	int age;
};

Base::Base(int Age, int Hight)
	:age(Age){
	hight = new int(Hight);
}
Base::Base(const Base& copy) {//�������캯��
	age = copy.age;
	hight = new int(*copy.hight);
}
void Base::printInfo() {
	cout <<"����Ϊ�� " << this->age << endl;
	cout << "���Ϊ��" << *hight << endl;
}
void test(){
	Base p1(20,160),p2(p1);
	p2.printInfo();
}
int main() {
	test();
	return 0;
}