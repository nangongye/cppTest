#include<iostream>
#include<numeric>//体积很小，只包括几个序列上面进行简单数学运算的模板函数
#include<algorithm>//所以stl头文件中最大的一个，范围涉及到比较、交换、查找、遍历操作、复制、修改
#include<functional>//定义了一些模板类，用以声明函数对象
using namespace std;
#include<vector>
#include<string>


void Printf01(int val) {
	cout << val << "\t";
}
class Printf02 {
public:
	void operator()(int val) {
		cout << val<<"   " ;
	}

};

class Transform {//仿函数
public:
	int operator()(int v) {
		return v;
	}
};

class Person {
public:
	string Name;
	int Age;

	Person(string name,int age) {
		this->Name = name;
		this->Age = age;
	}
	bool operator==(const Person& p) {//加const防修改底层代码
		if (this->Name == p.Name && this->Age == p.Age)
			return true;
		else
			return false;
	}
};
class GreaterFive {
public:
	bool operator()(int val) {
		return val > 5;
	}
	bool operator()(const Person& p) {
		return p.Age > 20;
	}
};

//常用遍历算法
void test01() {
	vector<int>v;

	for (int i = 0; i < 4; i++)
		v.push_back(i * 10);
	for_each(v.begin(), v.end(), Printf01);
	cout << endl;

	for_each(v.begin(), v.end(), Printf02());
	cout << endl;
}

void test02() {//容器搬运
	vector<int>v;
	vector<int>vTarget;//目标容器

	for (int i = 0; i < 4; i++)
		v.push_back(i * 10);

	vTarget.resize(v.size());//重新指定一个容器v大小空间，目标容器为空，程序会崩溃，所以需要提前分配好空间
	
	transform(v.begin(),v.end(),vTarget.begin(),Transform());//搬运，需要一个仿函数

	for_each(vTarget.begin(), vTarget.end(),Printf02());//遍历vTarget容器
}

void test03() {//内置数据和自定义数据类型查找
	vector<int>v;
	vector<Person>v1;
	for (int i = 0; i < 4; i++)
		v.push_back(i * 10);

	vector<int>::iterator it = find_if(v.begin(), v.end(), GreaterFive());//按值查找元素
	if (it == v.end())
		cout << "没有找到" << endl;
	else
		cout << "找到大于5的数字：" << *it << endl;
	/*Person p1("asd", 23);
	Person p2("asd", 354);
	Person p3("asdasf", 43);

	v1.push_back(p1);
	v1.push_back(p2);
	v1.push_back(p3);
	Person pp("asd", 3542);*/

	//vector<int>::iterator it =find(v.begin(), v.end(), 10);//查找是否有10这个元素
	//if (it == v.end())
	//	cout << "没有找到" << endl;
	//cout << "找到" << *it<<endl;
	
	//vector<Person>::iterator it = find(v1.begin(),v1.end(), pp);//查找v中是否有跟pp一样的数据
	//if (it == v1.end())
	//	cout << "没有找到" << endl;
	//else
	//	cout << "找到元素:姓名  "<< it->Name<<"年龄： "<<it->Age<<endl;
}

void test04() {//adjacent_find查找相邻相同元素函数
	vector<int>v;
	for (int i = 0; i < 4; i++)
		v.push_back(i * 10);
	
	vector<int>::iterator it = adjacent_find(v.begin(), v.end());
	if (it == v.end())
		cout << "没有找到相邻重复元素" << endl;
	else
		cout << "找到相邻重复元素：" << *it << endl;
}

void test05() {//binary_search二分查找法,功能查找元素是否存在。在无序序列中不可用
	vector<int>v;
	for (int i = 0; i < 4; i++)
		v.push_back(i * 10);
	
	bool ret = binary_search(v.begin(), v.end(), 20);
	if (ret )
		cout << "找到元素："  << endl;
	else
		cout << "没有找到" << endl;
}

void test06() {//统计算法count
	vector<int>v;
	for (int i = 0; i < 4; i++)
		v.push_back(i * 10);
	
	int num = count(v.begin(), v.end(), 30);
	//cout << "元素个数为：" << num<<endl;

	//自定义数据类型统计
	vector<Person>v1;
	Person p1("asd", 23);
	Person p2("asd", 354);
	Person p3("asdasf", 43);

	v1.push_back(p1);
	v1.push_back(p2);
	v1.push_back(p3);
	Person pp("asd", 3542);

	num = count(v1.begin(), v1.end(), pp);
	//cout << "多少个：" << num << endl;

	num = count_if(v1.begin(), v1.end(), GreaterFive());//统计大于5的数有多少个
	cout << "大于5的人数有： " << num << endl;
}
int main() {
	//test01();
	//test02();
	//test03();	
	//test04();
	//test05();
	test06();
	return 0;
}