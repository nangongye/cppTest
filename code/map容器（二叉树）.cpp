#include<iostream>
using namespace std;
#include<map>

void printMap(map<int,int>&m) {//输出函数
	for (map<int, int>::iterator it = m.begin(); it != m.end(); it++)
		cout << "key =  " << (*it).first  <<"  "<< "value = " << it->second<<endl;
	//cout << endl;
}

void test03() {//查找和统计
	map<int, int>m;
	m.insert(pair<int, int>(1, 10));

	map<int, int>::iterator pos = m.find(3);//查找Key为3的数据
	if (pos != m.end())
		cout << "查到了元素key = " << (*pos).first << "value = " << pos->second << endl;

	else
		cout << "未找到元素" << endl;

	int num = m.count(3);//统计key的value值有多少个，map容器不允许有重复数据，所以只能有一个
	cout << "有多少个" << endl;
	
}

void test02() {//交换测试案例
	map<int, int>m;
	map<int, int>m2;

	for (int i = 0; i < 5; i++)
		m.insert(pair<int,int>(i, i * 12)); //用pair对组初始化m容器
	for (int i = 0; i < 5; i++)
		m2.insert(pair<int, int>(2*i, i * 22));//用pair对组初始化m2容器

	cout << "交换前： " << endl;
	printMap(m);
	printMap(m2);

	cout << "交换后" << endl;
	m.swap(m2);
	printMap(m);
	printMap(m2);

	if (m.empty())//判断容器是否空
		cout << "为空" << endl;
	
	cout << "不为空" << endl;
	cout << "m的大小为：" << m.size() << endl;//查看Map容器大小


}

void test01() {//赋值
	map<int, int>m;//创建map容器

	for(int i = 0; i<5; i++)
		m.insert(pair<int, int>(i, i*10));//数据前者是key值，后者是value值，第一种方法
	
	//m.insert(make_pair(2, 20);//第二种赋值方法，表示在第二个元素赋值20
	//m.insert(map<int,int>::value_type(3, 30));//第三种方法，将key和value都写入
	//m[4] = 40;//不建议使用，为什么？因为如果寻找下一个键值key 5,会寻找不到就会
	//value值为0,即插错会value为0。[]可以通过key访问value

	//删除
	m.erase(m.begin());//删除第一个元素
	m.erase(3);//删除Key为3的数,只会按照key来删除，不会按照value删除
	m.erase(m.begin(),m. end());//按照区间方式删除从开始到结尾.只是举例
	m.clear();//清空
	printMap(m);

	map<int, int>m3;
	m3 = m;
	printMap(m3);
}

void test04() {//排序
	map<int, int>m;//创建map容器

	for (int i = 0; i < 5; i++)
		m.insert(pair<int, int>(i, i * 10));

	for (map<int, int>::iterator it = m.begin(); it != m.end(); it++) 
		cout << "key =  " << (*it).first << "  " << "value = " << it->second << endl;


}

int main() {
	//test01();
	//test02();
	//test03();
	return 0;
}