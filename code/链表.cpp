#include<iostream>
#include<list>
using namespace std;
#include<algorithm>
void PrintList(const list<int>&L) {//Ϊ�˷�ֹ������ʱ���޸�������������ݣ���const
	for (list<int>::const_iterator it = L.begin(); it != L.end(); it++) {
		cout << *it << "  ";
	}
	cout << endl;
}
//void test01() {
//	list<int>L1;
//
//	for (int i = 0; i < 5; i++) {
//		L1.push_back(i);//������ֵ
//	}
//	
//	//��������
//	PrintList(L1);
//
//	//���䷽ʽ����
//	list<int>L2(L1.begin(), L1.end());
//	PrintList(L2);
//
//	//��������
//	list<int>L3(L2);
//	PrintList(L3);
//
//	//n��elem
//	list<int>L4(10, 1000);
//
//	PrintList(L4);
//
//}



void test02() {
	list<int>L1;

	for (int i = 0; i < 5; i++) {
		L1.push_back(i);//������ֵ
	}

	list<int>L2;

	L2.assign(10, 10);

	////����ǰ
	//cout << "����ǰ�� " << endl;
	//PrintList2(L1);
	//PrintList2(L2);

	//L1.swap(L2);
	//cout << "������ " << endl;
	//PrintList2(L1);
	//PrintList2(L2);

	//L2 = L1; //operator��ֵ
	//PrintList(L2);

	//list<int>L3;
	//L3.assign(L2.begin(), L2.end());//assign��ֵ

	//list<int>L4;
	//L4.assign(10, 100);

	//list<int>::iterator it = L1.begin();
	//
	//L1.insert(++it, 1000);//�����ƶ�һλ�ٲ��룬������������ȣ������ⴴ��һ���ռ�
	//PrintList(L1);

	////ɾ��
	//it = L1.begin();
	//L1.erase(it);
	//PrintList(L1);

	//L1.remove(4);//ɾ����4ƥ���Ԫ�أ��ж��ٸ�ɾ���ٸ�
	//PrintList(L1);

	//L1.clear();//���
	//PrintList(L1);


}
//
//void test03() {
//	list<int>L1;
//
//	for (int i = 0; i < 5; i++) {
//		L1.push_back(i);//������ֵ
//	}
//	//L1[0]��������[]����list�����е�Ԫ��,��Ϊ������û�����ظķ���
//	//L1.at(0) ��������ata��ʽ����List�����е�Ԫ��
//	//ԭ����list���������������������Կռ�洢���ݣ�������Ҳ�ǲ�֧��������ʵ�
//
//	cout << "��һ��Ԫ�أ�" << L1.front() << endl;
//	cout << "���һ��Ԫ��Ϊ��" << L1.back() << endl;
//
//	//��֤�������ǲ�֧��������ʵ�
//	list<int>::iterator it = L1.begin();
//	it++; //it = it+1������֧�֣���Ȼ��˼һ����������ԣ�+2��+3Ҳ���ԣ���ô�������������
//	//֧��˫��it--;
//	 
//}
//
//void test04() {
//	list<int>L1;
//
//	for (int i = 0; i < 5; i++) {
//		L1.push_back(i);//������ֵ
//	}
//
//	cout << "��ת��" <<endl;
//	PrintList(L1);
//	L1.reverse();//��ת����
//
//	PrintList(L1);
//
//	//���в�֧��������ʵ��������������������ñ�׼�㷨
//	/*sort(L1.begin(), L1.end());
//	cout << "����� " << endl;
//	PrintList(L1);���в�֧��������ʵ��������������������ñ�׼�㷨*/
//
//	L1.sort(myCompare);
//	PrintList(L1);
//
//}

//bool myCompare(int v1,int v2) {
//	return v1 > v2;
//}
class Person {
public:
	Person(string name,int age,int height) {
		this->m_Name = name;
		this->m_Age = age;
		this->m_Height = height;
	}

	string m_Name;
	int m_Age;
	int m_Height;
};
void test05() {
	list<Person>L;

	Person p1("����", 34, 234);
	Person p2("����", 23, 343);
	Person p3("����", 23, 234);
	Person p4("�ŷ�", 23, 524);

	L.push_back(p1);
	L.push_back(p2);
	L.push_back(p3);
	L.push_back(p4);


}
int main() {
	//test04();
	//test02();
	test05();
	return 0;

}