#include<iostream>
using namespace std;

const int x = 23;//��const����define����ϸ�ɿ�effective C++

class Test {
public:
	void printInfo(int x)const;//ʹ��const�ں��棬�����ǿ������ص�
	Test() :t(0) { cout << "��������" << endl; }
	const static int printInfo(){}//��ʾ����ֵ�Ǿ�̬����
	void asd(){}
private:
	int t;
};

//�ڳ�Ա�������const��ʾ�����this ָ���ǳ����������޸ĸú���������ĳ�Ա����
void Test::printInfo(int x)const { 
	int Temp = 1;
	//this->t = Temp;����
	cout << "666" << endl;
}


void test() {//constӦ���ڱ���
	int Temp = 23; int Temp1 = 22;
	int* const Test = &Temp;
//int* const x��const���Ǻ��ұ߱�ʾָ��x�����ǳ��������ܸ���ָ���������Ǳ���
	//x = &Temp1;����
	*Test = 22;//���Ը���ֵ�����ܸ�ָ��

//���Ǻ���߱�ʾ��ָ���ǳ�����Ҳ����ζ�Ų��ܸ���ֵ�����Ǵ����Ҳ�ָ���㲻�����ˣ�
	const int* Test1 = &Temp;
	Test1 = &Temp1;//���Ը���ָ�򣬲��ܸ�ֵ
	//*Test1 = 234;����
}

//void test01() const ������ͨ���������ں�������const
void test01() {
	const Test T;
	//T.printInfo()��������ֻ�ܵ���const��Ա����
	Test t;
	//t.asd();t.printInfo()�ǳ���������Ե��÷�const��Ա������const����
}

int main() {
	
	return 0;
}