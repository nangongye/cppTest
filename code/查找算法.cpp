#include<iostream>
#include<numeric>//�����С��ֻ������������������м���ѧ�����ģ�庯��
#include<algorithm>//����stlͷ�ļ�������һ������Χ�漰���Ƚϡ����������ҡ��������������ơ��޸�
#include<functional>//������һЩģ���࣬����������������
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

class Transform {//�º���
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
	bool operator==(const Person& p) {//��const���޸ĵײ����
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

//���ñ����㷨
void test01() {
	vector<int>v;

	for (int i = 0; i < 4; i++)
		v.push_back(i * 10);
	for_each(v.begin(), v.end(), Printf01);
	cout << endl;

	for_each(v.begin(), v.end(), Printf02());
	cout << endl;
}

void test02() {//��������
	vector<int>v;
	vector<int>vTarget;//Ŀ������

	for (int i = 0; i < 4; i++)
		v.push_back(i * 10);

	vTarget.resize(v.size());//����ָ��һ������v��С�ռ䣬Ŀ������Ϊ�գ�����������������Ҫ��ǰ����ÿռ�
	
	transform(v.begin(),v.end(),vTarget.begin(),Transform());//���ˣ���Ҫһ���º���

	for_each(vTarget.begin(), vTarget.end(),Printf02());//����vTarget����
}

void test03() {//�������ݺ��Զ����������Ͳ���
	vector<int>v;
	vector<Person>v1;
	for (int i = 0; i < 4; i++)
		v.push_back(i * 10);

	vector<int>::iterator it = find_if(v.begin(), v.end(), GreaterFive());//��ֵ����Ԫ��
	if (it == v.end())
		cout << "û���ҵ�" << endl;
	else
		cout << "�ҵ�����5�����֣�" << *it << endl;
	/*Person p1("asd", 23);
	Person p2("asd", 354);
	Person p3("asdasf", 43);

	v1.push_back(p1);
	v1.push_back(p2);
	v1.push_back(p3);
	Person pp("asd", 3542);*/

	//vector<int>::iterator it =find(v.begin(), v.end(), 10);//�����Ƿ���10���Ԫ��
	//if (it == v.end())
	//	cout << "û���ҵ�" << endl;
	//cout << "�ҵ�" << *it<<endl;
	
	//vector<Person>::iterator it = find(v1.begin(),v1.end(), pp);//����v���Ƿ��и�ppһ��������
	//if (it == v1.end())
	//	cout << "û���ҵ�" << endl;
	//else
	//	cout << "�ҵ�Ԫ��:����  "<< it->Name<<"���䣺 "<<it->Age<<endl;
}

void test04() {//adjacent_find����������ͬԪ�غ���
	vector<int>v;
	for (int i = 0; i < 4; i++)
		v.push_back(i * 10);
	
	vector<int>::iterator it = adjacent_find(v.begin(), v.end());
	if (it == v.end())
		cout << "û���ҵ������ظ�Ԫ��" << endl;
	else
		cout << "�ҵ������ظ�Ԫ�أ�" << *it << endl;
}

void test05() {//binary_search���ֲ��ҷ�,���ܲ���Ԫ���Ƿ���ڡ������������в�����
	vector<int>v;
	for (int i = 0; i < 4; i++)
		v.push_back(i * 10);
	
	bool ret = binary_search(v.begin(), v.end(), 20);
	if (ret )
		cout << "�ҵ�Ԫ�أ�"  << endl;
	else
		cout << "û���ҵ�" << endl;
}

void test06() {//ͳ���㷨count
	vector<int>v;
	for (int i = 0; i < 4; i++)
		v.push_back(i * 10);
	
	int num = count(v.begin(), v.end(), 30);
	//cout << "Ԫ�ظ���Ϊ��" << num<<endl;

	//�Զ�����������ͳ��
	vector<Person>v1;
	Person p1("asd", 23);
	Person p2("asd", 354);
	Person p3("asdasf", 43);

	v1.push_back(p1);
	v1.push_back(p2);
	v1.push_back(p3);
	Person pp("asd", 3542);

	num = count(v1.begin(), v1.end(), pp);
	//cout << "���ٸ���" << num << endl;

	num = count_if(v1.begin(), v1.end(), GreaterFive());//ͳ�ƴ���5�����ж��ٸ�
	cout << "����5�������У� " << num << endl;
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