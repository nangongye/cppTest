#include<iostream>
#include<memory>
using namespace std;
void auto_ptrTest() {
	//1.auto_ptrƪ
	auto_ptr<int>p;//��סauto_ptr
	/*auto_ptr<int>p1;
	p1 = p; ʹ��auto_ptr������Դ��p������Ȩ������.
	 �������p�ᱨ��ʹ��auto_ptr��Ǳ�ڵ��ڴ��������
	cout << *p.get() << endl;*/

	//reset ����ָ��ָ��ָ���ַ��ֵ�������ָ����Ϊnullptr
	p.reset(new int);
	*p = 10;
	cout << *p.get() << endl;//��ȡָ����ָ���ַ��ֵ
	p.reset(new int);
	*p = 20;
	cout << *p.get() << endl;

	int* managePtr;
	managePtr = p.release();//��p��Ϊnullptr��p֮ǰ�洢��ֵ����managePtr
	cout << "*managePtr:" << *managePtr << endl;
	//cout << *p.get() << endl;
}

void unique_ptrTest() {
	/*unique_ptr<int> foo;
	unique_ptr<int> bar;

	foo = unique_ptr<int>(new int(101));  // rvalue

	bar = move(foo);                       // using std::move

	cout << "foo: ";
	if (foo) cout << *foo << '\n'; else cout << "empty\n";

	cout << "bar: ";
	if (bar) cout << *bar << '\n'; else cout << "empty\n";*/
	unique_ptr<int> p1(new int);
	unique_ptr<int>p2;
	*p1.get() = 100;
	cout << *p1.get() << endl;
}
int main() {
	//auto_ptrTest();
	unique_ptrTest();
	return 0;
}