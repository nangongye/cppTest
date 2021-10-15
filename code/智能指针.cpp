#include<iostream>
#include<memory>
using namespace std;
void auto_ptrTest() {
	//1.auto_ptr篇
	auto_ptr<int>p;//记住auto_ptr
	/*auto_ptr<int>p1;
	p1 = p; 使用auto_ptr拷贝资源，p的所有权被剥夺.
	 所以输出p会报错，使用auto_ptr有潜在的内存崩溃问题
	cout << *p.get() << endl;*/

	//reset 重新指定指针指向地址的值，如果不指定则为nullptr
	p.reset(new int);
	*p = 10;
	cout << *p.get() << endl;//获取指针所指向地址的值
	p.reset(new int);
	*p = 20;
	cout << *p.get() << endl;

	int* managePtr;
	managePtr = p.release();//将p变为nullptr，p之前存储的值赋给managePtr
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