#include<iostream>
using namespace std;

/*1.static_cast可用于基本数据类型转换，向上转换，例如int 转long.
* 2.void 指针和具体类型指针之间的转换.
* 3.有转换构造函数或者类型转换函数的类与其它类型之间的转换，例如:double 转 Complex（调用转换构造函数）
* 不能用于无关类型之间的转换：
* 1.各指针类型之间的转换，例如：int* 转换成double*
* 2.int和指针之间的转换
*/
void static_castTest() {
	int testVirable = 23;
	long myVirable = static_cast<long long>(testVirable);//宽类型转换，不会丢失数据
	char myVirable2 = static_cast<char>(testVirable);//会丢失信息，最高127

	int* myPointer = new int(2);
	void* myPointer1 = static_cast<void*>(myPointer);
	//不能一次性从Int* 转换成double，要先转换成void* 再转换成double*
}

//去除或添加const
void const_castTest() {
	const int n = 100;
	int* p = const_cast<int*>(&n);
	*p = 23;
	cout << *p << endl;//能成功是因为去除了const，这是const_cast的功劳
}
/*
reinterpret_cast 这种转换仅仅是对二进制位的重新解释，
不会借助已有的转换规则对数据进行调整，非常简单粗暴，所以风险很高。
*/

/*dynamic_cast用于派生类之间的转换
dynamic_cast <newType> (expression)*/
int main() {
	const_castTest();
	return 0;
}