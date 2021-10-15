/*概念:
●返回bool类型的仿函数称为谓词
●如果operator()接受一 个参数， 那么叫做-元谓词
●如果operator()接受两个参数，那么叫做二元谓词*/
#include<iostream>
using namespace std;
#include<vector>
#include<algorithm>

class GreaterFive {//一元谓词
public:
	bool operator()(int val) {
		return val > 5;
	}
};

class MyCompare {//二元谓词
public:
	bool operator()(int val_1,int val_2) {
		return val_1 > val_2;
	}
};

void Printf(vector<int>&a) {
	for (vector<int>::iterator it = a.begin(); it != a.end(); it++)
		cout << "\t" << *it;
	cout << endl;
}

void test01() {
	vector<int>v;
	for (int i = 0; i < 4; i++)
		v.push_back(i * 10);//尾插

	vector<int>::iterator it = find_if(v.begin(), v.end(), GreaterFive());//GreaterFive()匿名函数对象
	if (it == v.end())
		cout << "未找到" << endl;
	else
		cout << "找到了大于5的数字为： " << *it << endl;//解引用*it找到大于5的数字
}

void test02() {
	vector<int>v;
	for (int i = 0; i < 4; i++)
		v.push_back(i * 10);
	sort(v.begin(),v.end(),MyCompare());//sort算法中需要一个仿函数来改变他的排列顺序，如果不给则默认升序
	Printf(v);
}

int main() {
	//test01();
	test02();
	return 0;
}