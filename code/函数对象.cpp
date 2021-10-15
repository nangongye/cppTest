#include<iostream>
using namespace std;
#include<string>
class MyAdd {//仿函数
public:
	int operator()(int v1, int v2) {
		return v1 + v2;
	}
};

class MyPrint {
public:
	MyPrint() {//构造函数
		this->count = 0;
	}
	void operator()(string test) {
		cout << test << endl;
		this->count++;
	}

	int count;//内部状态，用于记录调用多少次MyPrint
};

//函数对象在使用时，可以像普通函数那样调用，可以有参数，可以有返回值
void test01() {
	MyAdd myadd;//函数对象
	myadd(10, 10);
	cout << myadd(10,10) << endl;
}

//函数对象超出普通函数的概念，函数对象可以有自己的状态
void test02() {
	MyPrint myprint;
	myprint("asdasd");
	cout << myprint.count << endl;
}

//函数对象可以作为参数传递
void doPrint(MyPrint& mp, string test) {//传入对象引用
	mp(test);//对象mp的所属类里有重载（）运算符，传入test即可输出
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