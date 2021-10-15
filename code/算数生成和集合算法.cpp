#include<iostream>
#include<algorithm>
#include<vector>
#include<numeric>
using namespace std;

class Printf_2 {
public:
	void operator()(int val) {
		cout << val << "   ";
	}
};
void test01() {
	vector<int>v;
	for (int i = 0; i < 6; i++)
		v.push_back(i * 4);

	int total = accumulate(v.begin(), v.end(), 0);//0为起始累加值,accumulate为累加函数
	cout << "total = " << total << endl;

	v.resize(10);//指定容器大小为10
	//上面for循环只有6个元素，后面4个我们需要用fill函数填充（也可以不填）
	fill(v.begin()+6, v.end(), 100);//后面4个元素填充100
	for_each(v.begin(), v.end(), Printf_2());
	cout << v.capacity() << endl;
}

void test02() {
	vector<int>v;
	vector<int>v1;
	for (int i = 0; i < 6; i++) {
		v.push_back(i * 4);
		v1.push_back(i * 5);
	}
	vector<int>vTarget;

	//vTarget.resize(min(v1.size(),v.size())) 即两容器最小值
	vTarget.resize(2);

	vector<int>::iterator itEnd = set_intersection(v1.begin(),v1.end(),v.begin(),v.end(),vTarget.begin());//求两个容器的交集，此函数两容器必须是有序序列
	//for_each(vTarget.begin(), itEnd, Printf_2());

	/*为什么不用target.end而改itend？
	因为用target.end会把容器内都遍历一遍，交集只有几个数
	遍历的话，缺少的元素会用0补*/
	//set_union;//求两个容器的并集，也必须两容器是有序序列
	//set_difference;//求两个容器的差集

	vTarget.resize(v.size() + v1.size());//求并集就是两容器相加
	itEnd = set_union(v1.begin(), v1.end(), v.begin(), v.end(), vTarget.begin());
	//for_each(vTarget.begin(), itEnd, Printf_2());

	vTarget.resize(max(v1.size(), v.size()));
	itEnd = set_difference(v1.begin(), v1.end(), v.begin(), v.end(), vTarget.begin());//差集
	for_each(vTarget.begin(), itEnd, Printf_2());

}
int main() {
	//test01();
	test02();
	return 0;
}