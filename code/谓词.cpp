/*����:
�񷵻�bool���͵ķº�����Ϊν��
�����operator()����һ �������� ��ô����-Ԫν��
�����operator()����������������ô������Ԫν��*/
#include<iostream>
using namespace std;
#include<vector>
#include<algorithm>

class GreaterFive {//һԪν��
public:
	bool operator()(int val) {
		return val > 5;
	}
};

class MyCompare {//��Ԫν��
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
		v.push_back(i * 10);//β��

	vector<int>::iterator it = find_if(v.begin(), v.end(), GreaterFive());//GreaterFive()������������
	if (it == v.end())
		cout << "δ�ҵ�" << endl;
	else
		cout << "�ҵ��˴���5������Ϊ�� " << *it << endl;//������*it�ҵ�����5������
}

void test02() {
	vector<int>v;
	for (int i = 0; i < 4; i++)
		v.push_back(i * 10);
	sort(v.begin(),v.end(),MyCompare());//sort�㷨����Ҫһ���º������ı���������˳�����������Ĭ������
	Printf(v);
}

int main() {
	//test01();
	test02();
	return 0;
}