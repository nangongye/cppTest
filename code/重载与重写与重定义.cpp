#include<iostream>
using namespace std;

//1.����,ͬһ�����ռ��ڣ����в�ͬ�����б��ͬ���������������͡�������˳��Ĳ�ͬ����������
void overload(){}
void overload(int temp){}

//��д,���������¶��常����˺�����������ȫ��ͬ���麯����static����������д
class Base {
private:
	virtual void override1() { cout << "haha" << endl; }
	void PrintInfo(){}
};
class derive : private Base {
public:
	 virtual void override1(){}//��ʹvirtual����private����д���Ը�Ϊpublic
	 void PrintInfo(){}//�ض��壬���������¶��常������ͬ���ֵķ�virtual�����������б��������Ϳ��Բ�ͬ
};
int main() {
	return 0;
}