#include<iostream>
using namespace std;

/*1.static_cast�����ڻ�����������ת��������ת��������int תlong.
* 2.void ָ��;�������ָ��֮���ת��.
* 3.��ת�����캯����������ת��������������������֮���ת��������:double ת Complex������ת�����캯����
* ���������޹�����֮���ת����
* 1.��ָ������֮���ת�������磺int* ת����double*
* 2.int��ָ��֮���ת��
*/
void static_castTest() {
	int testVirable = 23;
	long myVirable = static_cast<long long>(testVirable);//������ת�������ᶪʧ����
	char myVirable2 = static_cast<char>(testVirable);//�ᶪʧ��Ϣ�����127

	int* myPointer = new int(2);
	void* myPointer1 = static_cast<void*>(myPointer);
	//����һ���Դ�Int* ת����double��Ҫ��ת����void* ��ת����double*
}

//ȥ�������const
void const_castTest() {
	const int n = 100;
	int* p = const_cast<int*>(&n);
	*p = 23;
	cout << *p << endl;//�ܳɹ�����Ϊȥ����const������const_cast�Ĺ���
}
/*
reinterpret_cast ����ת�������ǶԶ�����λ�����½��ͣ�
����������е�ת����������ݽ��е������ǳ��򵥴ֱ������Է��պܸߡ�
*/

/*dynamic_cast����������֮���ת��
dynamic_cast <newType> (expression)*/
int main() {
	const_castTest();
	return 0;
}