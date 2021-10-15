#include<iostream>
using namespace std;
#include<queue>
#include<string>
class Person {
public:
	Person(string name, int age) {
		this->Name = name;
		this->Age = age;
	}
	string Name;
	int Age;
};
void test02() {
	queue<Person>q;

	Person p1("唐僧", 231);
	Person p2("苍井空", 3242);
	Person p3("波多野结衣", 2342);

	//入队
	q.push(p1);
	q.push(p2);
	q.push(p3);

	while (!q.empty()) {
		//查看对头
		cout << "对头元素姓名：" << q.front().Name << "   "
			<< "年龄 " << q.front().Age << endl;

		cout << "队尾元素姓名： " << q.back().Name << ""
			<< "年龄：" << q.back().Age << endl;

		q.pop();//出队
	}

	cout << "队列大小" << q.size() << endl;//查看大小
}
int main() {
	test02();
	return 0;
}