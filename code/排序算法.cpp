#include<iostream>
#include<numeric>//�����С��ֻ������������������м���ѧ�����ģ�庯��
#include<algorithm>//����stlͷ�ļ�������һ������Χ�漰���Ƚϡ����������ҡ��������������ơ��޸�
#include<functional>//������һЩģ���࣬����������������
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

	//�ı�Ϊ����
	sort(v.begin(), v.end(), greater<int>());
	for_each(v.begin(), v.end(), Myprint);

	random_shuffle(v.begin(), v.end());//�������˳����
	for_each(v.begin(), v.end(), Myprint);

}

void test02() {//�����ϲ�
	vector<int>v;
	vector<int>v1;
	for (int i = 0; i < 5; i++) {
		v.push_back(i * 10);
		v1.push_back(i * 2);
	}
		
	vector<int>vTarget;//�ϳ�ǰ�迪�ٿռ�
	vTarget.resize(v.size() + v1.size());
	merge(v.begin(), v.end(), v1.begin(), v1.end(),vTarget.begin());/*�������ϳɱ�����˳��һ��*/
	for_each(vTarget.begin(), vTarget.end(), Myprint);
}

void test03() {//��ת�㷨reverse
	vector<int>v;
	for (int i = 0; i < 5; i++)
		v.push_back(i * 10);
	cout << "��תǰ��" << endl;
	for_each(v.begin(), v.end(), Myprint);
	cout << endl;

	cout << "��ת��" << endl;
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