#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;

class Printf2 {
public:
	void operator()(int val) {
		cout << val << "   ";
	}
};

class Greater30 {
public:
	bool operator()(int val) {
		return val >= 30;
	}
};
void test01() {//拷贝
	vector<int>v;
	for (int i = 0; i < 6; i++) {
		v.push_back(i*2);
	}
	vector<int>v1;
	v1.resize(v.size());
	copy(v.begin(), v.end(), v1.begin());//需要复制方的起始和结束迭代器，目标方的起始迭代器
	for_each(v1.begin(), v1.end(), Printf2());
	cout << endl;
}

void test02() {//替换算法replace测试
	vector<int>v;
	for (int i = 0; i < 6; i++) {
		v.push_back(i * 2);
	}

	//cout << "替换前" << endl;
	//for_each(v.begin(), v.end(),Printf2());
	//cout << endl;

	//vector<int>::iterator it = find(v.begin(), v.end(), 20);//判断替换前容器是否有目标值
	//if (it == v.end())
	//	cout << "没有目标值,替换失败" << endl;
	//else {
	//	replace(v.begin(), v.end(), 20, 200);//替换算法，将所有20换成200
	//	cout << "替换后" << endl;
	//	for_each(v.begin(), v.end(), Printf2());
	//}
	
	vector<int>::iterator it = find(v.begin(), v.end(), 30);//判断替换前容器是否有目标值
	if (it == v.end())
		cout << "没有目标值,替换失败" << endl;
	else {
		replace_if(v.begin(), v.end(), Greater30(), 3000);//将所有大于30的值换成3000
		cout << "替换后" << endl;
		for_each(v.begin(), v.end(), Printf2());
	}
}

void test03(){
	vector<int>v;
	vector<int>v1;
	for (int i = 0; i < 6; i++) {
		v.push_back(i * 2);
		v1.push_back(i * 5);
	}
	cout << "替换前" << endl;
	for_each(v.begin(), v.end(), Printf2());
	cout << endl;
	for_each(v1.begin(), v1.end(), Printf2());
	cout << endl;
	
	cout << "————————————" << endl;
	cout << "替换后" << endl;

	swap(v, v1);
	for_each(v.begin(), v.end(), Printf2());
	cout << endl;
	for_each(v1.begin(), v1.end(), Printf2());
}


int main() {
	//test02();
	test03();
	return 0;
}