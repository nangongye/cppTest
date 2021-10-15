#include<iostream>
using namespace std;
#include<string>
//pari对组的创建
void test01() {
	pair<string, int>p("tom", 234);
	cout << "姓名：" << p.first << "年龄：  " << p.second << endl;
	//first、second对应第一第二个数据

	//第二种方式
	pair<string, int>p2 = make_pair("jerrt", 23);
	cout << "姓名：" << p2.first << "年龄：  " << p2.second << endl;
}
int main() {
	test01();
	return 0;
}