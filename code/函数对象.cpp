#include<iostream>
using namespace std;
#include<string>
class MyAdd {//�º���
public:
	int operator()(int v1, int v2) {
		return v1 + v2;
	}
};

class MyPrint {
public:
	MyPrint() {//���캯��
		this->count = 0;
	}
	void operator()(string test) {
		cout << test << endl;
		this->count++;
	}

	int count;//�ڲ�״̬�����ڼ�¼���ö��ٴ�MyPrint
};

//����������ʹ��ʱ����������ͨ�����������ã������в����������з���ֵ
void test01() {
	MyAdd myadd;//��������
	myadd(10, 10);
	cout << myadd(10,10) << endl;
}

//�������󳬳���ͨ�����ĸ����������������Լ���״̬
void test02() {
	MyPrint myprint;
	myprint("asdasd");
	cout << myprint.count << endl;
}

//�������������Ϊ��������
void doPrint(MyPrint& mp, string test) {//�����������
	mp(test);//����mp���������������أ��������������test�������
}
void test03() {
	MyPrint myprint;
	doPrint(myprint, "sadafsas");

}
int main() {
	//test01();
	//test02();
	test03();
	return 0;
}