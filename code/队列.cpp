#include<iostream>
using namespace std;
#include<queue>
#include<string>
class Person {
public:
	Person(string name, int age) {
		this->Name = name;
		this->Age = age;
	}
	string Name;
	int Age;
};
void test02() {
	queue<Person>q;

	Person p1("��ɮ", 231);
	Person p2("�Ծ���", 3242);
	Person p3("����Ұ����", 2342);

	//���
	q.push(p1);
	q.push(p2);
	q.push(p3);

	while (!q.empty()) {
		//�鿴��ͷ
		cout << "��ͷԪ��������" << q.front().Name << "   "
			<< "���� " << q.front().Age << endl;

		cout << "��βԪ�������� " << q.back().Name << ""
			<< "���䣺" << q.back().Age << endl;

		q.pop();//����
	}

	cout << "���д�С" << q.size() << endl;//�鿴��С
}
int main() {
	test02();
	return 0;
}