#include<iostream>
#include<stack>
using namespace std;

void test01() {
	stack<int>s;
	
	for (int i = 0; i < 10; i++) {
		s.push(i);//入栈
	}

	while (!s.empty()) {//是否为空
		//查看栈顶元素
		cout << "查看栈顶元素" << s.top() << endl;

		s.pop();//出栈
	}

	cout << "栈的大小" << s.size() << endl;//查看出栈之后，栈的大小
}

int main() {
	test01();
	return 0;
}