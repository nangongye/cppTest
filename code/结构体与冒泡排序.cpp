#include<iostream>
#include<string>
using namespace std;

struct hero {
	string name;
	int ago;
	string sex;
};

void bubbleSort( struct hero Array[], int len) {//��ð�������㷨����
	
	for (int i = 0; i < len - 1; i++) {
		for (int j = 0; j < len - i - 1; j++) {
			if (Array[j].ago > Array[j + 1].ago) {//���j�±����j+1�±꣬����н���
				struct hero temp = Array[j];
				Array[j] = Array[j + 1];
				Array[j + 1] = temp;
			}
		}
	}
}
	void printInfo(struct hero Array[], int len) //����ı�֮�������
	{
		for (int i = 0; i < len; i++)
		{
			cout << "������ " << Array[i].name << "���䣺 " << Array[i].ago
				<< "�Ա�" << Array[i].sex << endl;
		}		
	}

	int main() {
	struct hero Array[5] = {
		{"����",23,"��"},
		{"����",22,"��"},
		{"�ŷ�",20,"��"},
		{"����",23,"��"},
		{"����",19,"Ů"},
	};

	int len = sizeof(Array) / sizeof(Array[0]);

	for(int i = 0;i<len; i++)
	{
		cout << "������ " << Array[i].name << "���䣺 " << Array[i].ago
			<< "�Ա�" << Array[i].sex << endl;
	}
	bubbleSort(Array, len);
	cout << "����ı�֮�������" << endl;
	printInfo(Array, len);

	system("pause");
	return 0;
}