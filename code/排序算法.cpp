#include<iostream>
#include<numeric>//体积很小，只包括几个序列上面进行简单数学运算的模板函数
#include<algorithm>//所以stl头文件中最大的一个，范围涉及到比较、交换、查找、遍历操作、复制、修改
#include<functional>//定义了一些模板类，用以声明函数对象
using namespace std;
#include<vector>
#include<string>

void Myprint(int val) {
	cout <<val<<"\t";
}
void test01() {
	vector<int>v;
	for (int i = 0; i < 5; i++)
		v.push_back(i * 10);
	v.push_back(2);
	v.push_back(89);
	v.push_back(45);

	sort(v.begin(), v.end());
	for_each(v.begin(), v.end(), Myprint);
	cout << endl;

	//改变为降序
	sort(v.begin(), v.end(), greater<int>());
	for_each(v.begin(), v.end(), Myprint);

	random_shuffle(v.begin(), v.end());//随机打乱顺序函数
	for_each(v.begin(), v.end(), Myprint);

}

void test02() {//容器合并
	vector<int>v;
	vector<int>v1;
	for (int i = 0; i < 5; i++) {
		v.push_back(i * 10);
		v1.push_back(i * 2);
	}
		
	vector<int>vTarget;//合成前需开辟空间
	vTarget.resize(v.size() + v1.size());
	merge(v.begin(), v.end(), v1.begin(), v1.end(),vTarget.begin());/*两容器合成必须是顺序一致*/
	for_each(vTarget.begin(), vTarget.end(), Myprint);
}

void test03() {//反转算法reverse
	vector<int>v;
	for (int i = 0; i < 5; i++)
		v.push_back(i * 10);
	cout << "反转前：" << endl;
	for_each(v.begin(), v.end(), Myprint);
	cout << endl;

	cout << "反转后" << endl;
	reverse(v.begin(), v.end());
	for_each(v.begin(), v.end(), Myprint);
	cout << endl;

}
int main() {
	//test01();
	//test02();
	test03();
	return 0;
}