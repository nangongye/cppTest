#include<iostream>
using namespace std;
#include<string>

class Phone {
public:
	Phone(string name) { //�вι���
		m_PhoneName = name;
		cout << "phone����" << endl;
	}
	~Phone() {//����
		cout << "Phone����" << endl;
	}

	string m_PhoneName;
};

class Person {
public :
	//��ʼ���б���Ը��߱�����������һ�����캯��
	Person(string name, string pName) :m_Name(name), m_Phone(pName) {
		cout << "person����" << endl;
	}

	~Person() {
		cout << "Person����" << endl;
	}

	void playGame() {
		cout << m_Name << "ʹ��" << m_Phone.m_PhoneName << "���ֻ�" << endl;
	}

	string m_Name;
	Phone m_Phone;
};

void test01() {
	//�����г�Ա�����������ʱ�����ǳƸó�ԱΪ�����Ա
	//�����˳��ʱ���ȵ��ö����Ա�Ĺ��죬�ٵ��ñ��๹��
	//����˳���빹���෴

	Person p("����", "ƻ��MAX");
	p.playGame();
}
int main() {
	test01();
	return 0;
}