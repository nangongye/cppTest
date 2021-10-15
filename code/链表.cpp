#include<iostream>
#include<list>
using namespace std;
#include<algorithm>
void PrintList(const list<int>&L) {//为了防止遍历的时候修改容器里面的内容，加const
	for (list<int>::const_iterator it = L.begin(); it != L.end(); it++) {
		cout << *it << "  ";
	}
	cout << endl;
}
//void test01() {
//	list<int>L1;
//
//	for (int i = 0; i < 5; i++) {
//		L1.push_back(i);//给链表赋值
//	}
//	
//	//遍历链表
//	PrintList(L1);
//
//	//区间方式构造
//	list<int>L2(L1.begin(), L1.end());
//	PrintList(L2);
//
//	//拷贝构造
//	list<int>L3(L2);
//	PrintList(L3);
//
//	//n个elem
//	list<int>L4(10, 1000);
//
//	PrintList(L4);
//
//}



void test02() {
	list<int>L1;

	for (int i = 0; i < 5; i++) {
		L1.push_back(i);//给链表赋值
	}

	list<int>L2;

	L2.assign(10, 10);

	////交换前
	//cout << "交换前： " << endl;
	//PrintList2(L1);
	//PrintList2(L2);

	//L1.swap(L2);
	//cout << "交换后： " << endl;
	//PrintList2(L1);
	//PrintList2(L2);

	//L2 = L1; //operator赋值
	//PrintList(L2);

	//list<int>L3;
	//L3.assign(L2.begin(), L2.end());//assign赋值

	//list<int>L4;
	//L4.assign(10, 100);

	//list<int>::iterator it = L1.begin();
	//
	//L1.insert(++it, 1000);//往后移动一位再插入，如果超过链表长度，则会额外创建一个空间
	//PrintList(L1);

	////删除
	//it = L1.begin();
	//L1.erase(it);
	//PrintList(L1);

	//L1.remove(4);//删除与4匹配的元素，有多少个删多少个
	//PrintList(L1);

	//L1.clear();//清空
	//PrintList(L1);


}
//
//void test03() {
//	list<int>L1;
//
//	for (int i = 0; i < 5; i++) {
//		L1.push_back(i);//给链表赋值
//	}
//	//L1[0]不可以用[]访问list容器中的元素,因为容器中没有重载改符号
//	//L1.at(0) 不可以用ata方式访问List容器中的元素
//	//原因是list本质链表，不是用连续线性空间存储数据，迭代器也是不支持随机访问的
//
//	cout << "第一个元素：" << L1.front() << endl;
//	cout << "最后一个元素为：" << L1.back() << endl;
//
//	//验证迭代器是不支持随机访问的
//	list<int>::iterator it = L1.begin();
//	it++; //it = it+1报错，不支持，虽然意思一样，如果可以，+2，+3也可以，那么就是随机访问了
//	//支持双向，it--;
//	 
//}
//
//void test04() {
//	list<int>L1;
//
//	for (int i = 0; i < 5; i++) {
//		L1.push_back(i);//给链表赋值
//	}
//
//	cout << "反转后" <<endl;
//	PrintList(L1);
//	L1.reverse();//反转函数
//
//	PrintList(L1);
//
//	//所有不支持随机访问迭代器的容器，不可以用标准算法
//	/*sort(L1.begin(), L1.end());
//	cout << "排序后： " << endl;
//	PrintList(L1);所有不支持随机访问迭代器的容器，不可以用标准算法*/
//
//	L1.sort(myCompare);
//	PrintList(L1);
//
//}

//bool myCompare(int v1,int v2) {
//	return v1 > v2;
//}
class Person {
public:
	Person(string name,int age,int height) {
		this->m_Name = name;
		this->m_Age = age;
		this->m_Height = height;
	}

	string m_Name;
	int m_Age;
	int m_Height;
};
void test05() {
	list<Person>L;

	Person p1("刘备", 34, 234);
	Person p2("关羽", 23, 343);
	Person p3("赵云", 23, 234);
	Person p4("张飞", 23, 524);

	L.push_back(p1);
	L.push_back(p2);
	L.push_back(p3);
	L.push_back(p4);


}
int main() {
	//test04();
	//test02();
	test05();
	return 0;

}