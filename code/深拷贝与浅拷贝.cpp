#include<iostream>
using namespace std;
/*��������Լ���һ����������һ���ڴ棬ǳ������ϵͳʵ�ֵĿ���
�������������ͷŸɾ��ڴ�*/
class Person {
public:
	Person() {
		cout << "Person��Ĭ�Ϲ��캯������" << endl;
	}
	Person(int age,int Height) {
		m_Age = age;
		m_Height = new int(Height);//��ָ��ȥ���շ�����ڴ�ռ䣬����һ�����*4��С�Ŀռ�
		cout << "Person���вι��캯������" << endl;
	}
	/*ǳ����������������Ƕ������ڴ��ظ��ͷš�Ϊʲô�ᷢ���쳣����
	����ִ�����֮�󣬾�Ҫִ�ж������ٳ���������������������
	����*Height��ָ����ڴ��ַ��0x0011�����裩,ִ��delete����,
	��ʱ���ͷŵ�0x0011���ڴ棬����������һ����p2Ҳ��ָ��Height���ڴ�ռ䣬
	��0x0011���ڴ汻�ͷ��ǣ�p2�Ҳ����ڴ�ͻᱨ��ǳ���������⣬Ҫ��������
	*/
	~Person() {
		/*if (m_Height != NULL) {
			delete m_Height;
			m_Height = NULL;
		}*/

		cout << "Person��������������" << endl;
	}
	//�Լ�ʵ�ֿ������캯�������ǳ��������������
	Person(const Person& p) {
		cout << "Person �������캯����" << endl;
		m_Age = p.m_Age;
		//m_Height = p.m_Height;������Ĭ��ִ�еľ������д��룬��������
		
		//�������
		m_Height = new int(*p.m_Height);
	}
	int* m_Height;//���
	int m_Age;
};

void test01() {
	Person p1(18,160);//��������
	cout << "p1������Ϊ�� " << p1.m_Age <<  "���Ϊ�� " << *p1.m_Height <<endl;
	Person p2(p1);
	cout << "p2����Ϊ�� " << p2.m_Age <<"���Ϊ �� "  << *p2.m_Height <<endl;//��ʹ���ṩ�������캯��������Ҳ��Ȼ���ṩ
}
int main() {

	test01();
	return 0;
}