#include<iostream>
using namespace std;

//���ղ������� �޲Σ�Ĭ�ϣ�������вι���
class Person {
public://��ͨ���캯��
	Person() {
		cout << "Person���޲ι���" << endl;
	}

	Person(int a) {
		age = a;
		cout << "Person���вι���" << endl;
	}
	~Person() {//�����ڶ�������ǰ���Զ���������
		cout << "Person��������������" << endl;
	}
	//�������캯��������Percon�е�ȫ�����ݴ�����һ��Person���������ʱ��ͽп������캯��
	Person(const Person& p) {/*�������ܸı���ԭ�������ݣ�������Ҫconst
							 ���⣬���ǻ���Ҫ����*/
		age = p.age;
	}
	int age;
};
void test01() {
	////���ŷ�
	//Person p;//Ĭ�Ϲ��캯������
	//Person p2(10);//�вκ�������
	//Person p3(p2);//�������캯��
	////Person p1;����Ĭ�Ϲ��캯��ʱ����Ҫ�ӣ���������������Ϊ�������������������ڴ�������
	//cout << "P2������Ϊ�� " << p2.age << endl;
	//cout << "p3������Ϊ�� " << p3.age << endl;

	//��ʾ��
	Person p1;
	Person p2 = Person(10);
	Person p3 = Person(p2);
	//Person(10);//�������� ��ǰִ�н�����ϵͳ������������������

	//Person(p3);//��Ҫ���ÿ������캯������ʼ���������󣬱���������ΪPerson(p3) == Peroson p3�������ظ�
	//cout << "������" << endl;
	
	//��ʽת����
	Person p4 = 10;//�൱��д��Person p4 = Person(10)
}
int main() {
	test01();
	return 0;
}