#include<iostream>
using namespace std;
#include<string>
//pari����Ĵ���
void test01() {
	pair<string, int>p("tom", 234);
	cout << "������" << p.first << "���䣺  " << p.second << endl;
	//first��second��Ӧ��һ�ڶ�������

	//�ڶ��ַ�ʽ
	pair<string, int>p2 = make_pair("jerrt", 23);
	cout << "������" << p2.first << "���䣺  " << p2.second << endl;
}
int main() {
	test01();
	return 0;
}