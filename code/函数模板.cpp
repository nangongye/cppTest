#include<iostream>
using namespace std;

//交换函数模板
template <class T>
void mySwap(T& a, T& b) {
	T temp = a;
	a = b;
	b = temp;
}
//排序算法
template<class T>
void mysort(T arr[], int len) {
	for (int i = 0; i < len; i++) {
		int max = i;
		for (int j = i + 1; j < len; j++) {//遍历寻找最大值然后更替
			if (arr[max] < arr[j]) 
				max = j;

		}
		if (max != i)
			mySwap(arr[max], arr[i]);
	}
}

template<class T>//打印模板
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