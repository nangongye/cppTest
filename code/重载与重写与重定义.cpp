#include<iostream>
using namespace std;

//1.重载,同一命名空间内，具有不同参数列表的同名函数，函数类型、个数、顺序的不同都可以重载
void overload(){}
void overload(int temp){}

//重写,派生类重新定义父类除了函数体以外完全相同的虚函数，static函数不能重写
class Base {
private:
	virtual void override1() { cout << "haha" << endl; }
	void PrintInfo(){}
};
class derive : private Base {
public:
	 virtual void override1(){}//即使virtual中是private，重写可以改为public
	 void PrintInfo(){}//重定义，派生类重新定义父类中相同名字的非virtual函数，参数列表，返回类型可以不同
};
int main() {
	return 0;
}