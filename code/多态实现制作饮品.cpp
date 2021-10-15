#include<iostream>
#include<string>
using namespace std;

//制作饮品
class AbstractDrinking {
public:
	//煮水
	virtual void Boil() = 0;
	//冲泡
	virtual void Brew() = 0;
	//倒入杯中
	virtual void PourInCup() = 0;
	//加入辅料
	virtual void PutSomething() = 0;

	void makeDrink() {
		Boil();
		Brew();
		PourInCup();
		PutSomething();
	}
};

//制作咖啡
class Coffee : public AbstractDrinking{
	//煮水
	virtual void Boil() {
		cout << "煮农夫山泉" << endl;
	}
	//冲泡
	virtual void Brew() {
		cout << "冲泡咖啡" << endl;
	}
	//倒入杯中
	virtual void PourInCup() {
		cout << "倒入杯中" << endl;
	}
	//加入辅料
	virtual void PutSomething() {
		cout << "加入辅料" << endl;
	}

	void makeDrink() {
		Boil();
		Brew();
		PourInCup();
		PutSomething();
	}
};

//制作函数
void doWork(AbstractDrinking *abs) {
	abs->makeDrink();
	delete abs;//释放内存,手动开辟手动释放
}//多态：一个接口多种形态
void test01() {
	doWork(new Coffee);
}
int main() {
	test01();
	return 0;
}