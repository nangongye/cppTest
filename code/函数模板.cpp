#include<iostream>
using namespace std;

//��������ģ��
template <class T>
void mySwap(T& a, T& b) {
	T temp = a;
	a = b;
	b = temp;
}
//�����㷨
template<class T>
void mysort(T arr[], int len) {
	for (int i = 0; i < len; i++) {
		int max = i;
		for (int j = i + 1; j < len; j++) {//����Ѱ�����ֵȻ�����
			if (arr[max] < arr[j]) 
				max = j;

		}
		if (max != i)
			mySwap(arr[max], arr[i]);
	}
}

template<class T>//��ӡģ��
void printArray(T arr[], int len) {
	for (int i = 0; i < len; i++)
		cout << arr[i] << "";
	cout << endl;
}

void test01() {
	char charArr[] = "bacfe";
	int num = sizeof(charArr) / sizeof(char);
	mysort(charArr, num);
	printArray(charArr, num);
}

int main() {

	test01();
	return 0;
}