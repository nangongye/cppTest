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
void test01() {//����
	vector<int>v;
	for (int i = 0; i < 6; i++) {
		v.push_back(i*2);
	}
	vector<int>v1;
	v1.resize(v.size());
	copy(v.begin(), v.end(), v1.begin());//��Ҫ���Ʒ�����ʼ�ͽ�����������Ŀ�귽����ʼ������
	for_each(v1.begin(), v1.end(), Printf2());
	cout << endl;
}

void test02() {//�滻�㷨replace����
	vector<int>v;
	for (int i = 0; i < 6; i++) {
		v.push_back(i * 2);
	}

	//cout << "�滻ǰ" << endl;
	//for_each(v.begin(), v.end(),Printf2());
	//cout << endl;

	//vector<int>::iterator it = find(v.begin(), v.end(), 20);//�ж��滻ǰ�����Ƿ���Ŀ��ֵ
	//if (it == v.end())
	//	cout << "û��Ŀ��ֵ,�滻ʧ��" << endl;
	//else {
	//	replace(v.begin(), v.end(), 20, 200);//�滻�㷨��������20����200
	//	cout << "�滻��" << endl;
	//	for_each(v.begin(), v.end(), Printf2());
	//}
	
	vector<int>::iterator it = find(v.begin(), v.end(), 30);//�ж��滻ǰ�����Ƿ���Ŀ��ֵ
	if (it == v.end())
		cout << "û��Ŀ��ֵ,�滻ʧ��" << endl;
	else {
		replace_if(v.begin(), v.end(), Greater30(), 3000);//�����д���30��ֵ����3000
		cout << "�滻��" << endl;
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
	cout << "�滻ǰ" << endl;
	for_each(v.begin(), v.end(), Printf2());
	cout << endl;
	for_each(v1.begin(), v1.end(), Printf2());
	cout << endl;
	
	cout << "������������������������" << endl;
	cout << "�滻��" << endl;

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