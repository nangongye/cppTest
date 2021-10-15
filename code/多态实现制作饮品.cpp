#include<iostream>
#include<string>
using namespace std;

//������Ʒ
class AbstractDrinking {
public:
	//��ˮ
	virtual void Boil() = 0;
	//����
	virtual void Brew() = 0;
	//���뱭��
	virtual void PourInCup() = 0;
	//���븨��
	virtual void PutSomething() = 0;

	void makeDrink() {
		Boil();
		Brew();
		PourInCup();
		PutSomething();
	}
};

//��������
class Coffee : public AbstractDrinking{
	//��ˮ
	virtual void Boil() {
		cout << "��ũ��ɽȪ" << endl;
	}
	//����
	virtual void Brew() {
		cout << "���ݿ���" << endl;
	}
	//���뱭��
	virtual void PourInCup() {
		cout << "���뱭��" << endl;
	}
	//���븨��
	virtual void PutSomething() {
		cout << "���븨��" << endl;
	}

	void makeDrink() {
		Boil();
		Brew();
		PourInCup();
		PutSomething();
	}
};

//��������
void doWork(AbstractDrinking *abs) {
	abs->makeDrink();
	delete abs;//�ͷ��ڴ�,�ֶ������ֶ��ͷ�
}//��̬��һ���ӿڶ�����̬
void test01() {
	doWork(new Coffee);
}
int main() {
	test01();
	return 0;
}