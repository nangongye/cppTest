#include<iostream>
using namespace std;

const int x = 23;//用const代替define，详细可看effective C++

class Test {
public:
	void printInfo(int x)const;//使用const在后面，函数是可以重载的
	Test() :t(0) { cout << "构造自身" << endl; }
	const static int printInfo(){}//表示返回值是静态常量
	void asd(){}
private:
	int t;
};

//在成员函数后加const表示传入的this 指针是常量，不能修改该函数所属类的成员变量
void Test::printInfo(int x)const { 
	int Temp = 1;
	//this->t = Temp;报错
	cout << "666" << endl;
}


void test() {//const应用于变量
	int Temp = 23; int Temp1 = 22;
	int* const Test = &Temp;
//int* const x，const在星号右边表示指针x本身是常量，不能更改指向，例子中是报错
	//x = &Temp1;报错
	*Test = 22;//可以更改值，不能改指向

//在星号左边表示被指物是常量，也就意味着不能更改值，但是大不了我不指向你不就行了？
	const int* Test1 = &Temp;
	Test1 = &Temp1;//可以更改指向，不能改值
	//*Test1 = 234;报错
}

//void test01() const 报错，普通函数不能在函数体后加const
void test01() {
	const Test T;
	//T.printInfo()常量对象只能调用const成员函数
	Test t;
	//t.asd();t.printInfo()非常量对象可以调用非const成员函数和const函数
}

int main() {
	
	return 0;
}