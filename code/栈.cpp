#include<iostream>
#include<stack>
using namespace std;

void test01() {
	stack<int>s;
	
	for (int i = 0; i < 10; i++) {
		s.push(i);//��ջ
	}

	while (!s.empty()) {//�Ƿ�Ϊ��
		//�鿴ջ��Ԫ��
		cout << "�鿴ջ��Ԫ��" << s.top() << endl;

		s.pop();//��ջ
	}

	cout << "ջ�Ĵ�С" << s.size() << endl;//�鿴��ջ֮��ջ�Ĵ�С
}

int main() {
	test01();
	return 0;
}