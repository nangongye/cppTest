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

	int total = accumulate(v.begin(), v.end(), 0);//0Ϊ��ʼ�ۼ�ֵ,accumulateΪ�ۼӺ���
	cout << "total = " << total << endl;

	v.resize(10);//ָ��������СΪ10
	//����forѭ��ֻ��6��Ԫ�أ�����4��������Ҫ��fill������䣨Ҳ���Բ��
	fill(v.begin()+6, v.end(), 100);//����4��Ԫ�����100
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

	//vTarget.resize(min(v1.size(),v.size())) ����������Сֵ
	vTarget.resize(2);

	vector<int>::iterator itEnd = set_intersection(v1.begin(),v1.end(),v.begin(),v.end(),vTarget.begin());//�����������Ľ������˺�����������������������
	//for_each(vTarget.begin(), itEnd, Printf_2());

	/*Ϊʲô����target.end����itend��
	��Ϊ��target.end��������ڶ�����һ�飬����ֻ�м�����
	�����Ļ���ȱ�ٵ�Ԫ�ػ���0��*/
	//set_union;//�����������Ĳ�����Ҳ��������������������
	//set_difference;//�����������Ĳ

	vTarget.resize(v.size() + v1.size());//�󲢼��������������
	itEnd = set_union(v1.begin(), v1.end(), v.begin(), v.end(), vTarget.begin());
	//for_each(vTarget.begin(), itEnd, Printf_2());

	vTarget.resize(max(v1.size(), v.size()));
	itEnd = set_difference(v1.begin(), v1.end(), v.begin(), v.end(), vTarget.begin());//�
	for_each(vTarget.begin(), itEnd, Printf_2());

}
int main() {
	//test01();
	test02();
	return 0;
}