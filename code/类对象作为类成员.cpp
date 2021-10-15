#include<iostream>
using namespace std;
#include<string>

class Phone {
public:
	Phone(string name) { //有参构造
		m_PhoneName = name;
		cout << "phone构造" << endl;
	}
	~Phone() {//析构
		cout << "Phone析构" << endl;
	}

	string m_PhoneName;
};

class Person {
public :
	//初始化列表可以告诉编译器调用哪一个构造函数
	Person(string name, string pName) :m_Name(name), m_Phone(pName) {
		cout << "person构造" << endl;
	}

	~Person() {
		cout << "Person析构" << endl;
	}

	void playGame() {
		cout << m_Name << "使用" << m_Phone.m_PhoneName << "牌手机" << endl;
	}

	string m_Name;
	Phone m_Phone;
};

void test01() {
	//当类中成员是其他类对象时，我们称该成员为对象成员
	//构造的顺序时：先调用对象成员的构造，再调用本类构造
	//析构顺序与构造相反

	Person p("张三", "苹果MAX");
	p.playGame();
}
int main() {
	test01();
	return 0;
}