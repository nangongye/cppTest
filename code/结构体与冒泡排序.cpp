#include<iostream>
#include<string>
using namespace std;

struct hero {
	string name;
	int ago;
	string sex;
};

void bubbleSort( struct hero Array[], int len) {//用冒泡排序算法排序
	
	for (int i = 0; i < len - 1; i++) {
		for (int j = 0; j < len - i - 1; j++) {
			if (Array[j].ago > Array[j + 1].ago) {//如果j下标大于j+1下标，则进行交换
				struct hero temp = Array[j];
				Array[j] = Array[j + 1];
				Array[j + 1] = temp;
			}
		}
	}
}
	void printInfo(struct hero Array[], int len) //输出改变之后的排序
	{
		for (int i = 0; i < len; i++)
		{
			cout << "姓名： " << Array[i].name << "年龄： " << Array[i].ago
				<< "性别：" << Array[i].sex << endl;
		}		
	}

	int main() {
	struct hero Array[5] = {
		{"关羽",23,"男"},
		{"关羽",22,"男"},
		{"张飞",20,"男"},
		{"赵云",23,"男"},
		{"貂蝉",19,"女"},
	};

	int len = sizeof(Array) / sizeof(Array[0]);

	for(int i = 0;i<len; i++)
	{
		cout << "姓名： " << Array[i].name << "年龄： " << Array[i].ago
			<< "性别：" << Array[i].sex << endl;
	}
	bubbleSort(Array, len);
	cout << "输出改变之后的排序" << endl;
	printInfo(Array, len);

	system("pause");
	return 0;
}