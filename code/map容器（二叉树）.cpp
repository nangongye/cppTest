#include<iostream>
using namespace std;
#include<map>

void printMap(map<int,int>&m) {//�������
	for (map<int, int>::iterator it = m.begin(); it != m.end(); it++)
		cout << "key =  " << (*it).first  <<"  "<< "value = " << it->second<<endl;
	//cout << endl;
}

void test03() {//���Һ�ͳ��
	map<int, int>m;
	m.insert(pair<int, int>(1, 10));

	map<int, int>::iterator pos = m.find(3);//����KeyΪ3������
	if (pos != m.end())
		cout << "�鵽��Ԫ��key = " << (*pos).first << "value = " << pos->second << endl;

	else
		cout << "δ�ҵ�Ԫ��" << endl;

	int num = m.count(3);//ͳ��key��valueֵ�ж��ٸ���map�������������ظ����ݣ�����ֻ����һ��
	cout << "�ж��ٸ�" << endl;
	
}

void test02() {//�������԰���
	map<int, int>m;
	map<int, int>m2;

	for (int i = 0; i < 5; i++)
		m.insert(pair<int,int>(i, i * 12)); //��pair�����ʼ��m����
	for (int i = 0; i < 5; i++)
		m2.insert(pair<int, int>(2*i, i * 22));//��pair�����ʼ��m2����

	cout << "����ǰ�� " << endl;
	printMap(m);
	printMap(m2);

	cout << "������" << endl;
	m.swap(m2);
	printMap(m);
	printMap(m2);

	if (m.empty())//�ж������Ƿ��
		cout << "Ϊ��" << endl;
	
	cout << "��Ϊ��" << endl;
	cout << "m�Ĵ�СΪ��" << m.size() << endl;//�鿴Map������С


}

void test01() {//��ֵ
	map<int, int>m;//����map����

	for(int i = 0; i<5; i++)
		m.insert(pair<int, int>(i, i*10));//����ǰ����keyֵ��������valueֵ����һ�ַ���
	
	//m.insert(make_pair(2, 20);//�ڶ��ָ�ֵ��������ʾ�ڵڶ���Ԫ�ظ�ֵ20
	//m.insert(map<int,int>::value_type(3, 30));//�����ַ�������key��value��д��
	//m[4] = 40;//������ʹ�ã�Ϊʲô����Ϊ���Ѱ����һ����ֵkey 5,��Ѱ�Ҳ����ͻ�
	//valueֵΪ0,������valueΪ0��[]����ͨ��key����value

	//ɾ��
	m.erase(m.begin());//ɾ����һ��Ԫ��
	m.erase(3);//ɾ��KeyΪ3����,ֻ�ᰴ��key��ɾ�������ᰴ��valueɾ��
	m.erase(m.begin(),m. end());//�������䷽ʽɾ���ӿ�ʼ����β.ֻ�Ǿ���
	m.clear();//���
	printMap(m);

	map<int, int>m3;
	m3 = m;
	printMap(m3);
}

void test04() {//����
	map<int, int>m;//����map����

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