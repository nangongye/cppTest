#include<iostream>
using namespace std;
#include<string>
#include<ctime>
/*ѧУ������������Ŀ��ÿ����ʦ����5��ѧ�����ܹ���3����ʦ����������
���ѧ������ʦ�Ľṹ�壬��������ʦ�Ľṹ���У�����ʦ������һ�����5��
ѧ����������Ϊ��Ա��ѧ���ĳ�Ա�����������Է���������������
3����ʦ��ͨ��������ÿ����ʦ��������ѧ����ֵ�����մ�ӡ����ʦ����
�Լ���ʦ������ѧ������*/
struct Student//����ѧ���Ľṹ��
{
	string	Sname;//ѧ������
	int score;//ѧ���ɼ�
};
struct Teachar
{
	string Tname;//��ʦ����
	struct Student sArray[5];/*����ѧ������	�������鱨���������������ͣ�
							 ����ΪStudentû�ж���*/
};
//����ʦ��ֵ�ĺ���
void allocateSpace(struct Teachar tArray[],int len) {
	string nameSeed = "ABCDE";//��ʦ�����»���׷��,nameseedΪ׷���ַ�����

	for (int i = 0; i < len; i++){
		tArray[i].Tname = "Teachar_";//����ʦ����֮����ʦ���Ƹ�ֵ				
		tArray[i].Tname += nameSeed[i];//ÿi+1,��ʦ�����»��߽�׷��һ���ַ�

		//ͨ��ѭ������ʦ������ѧ����ֵ
		for (int j = 0; j < 5; j++) {
			tArray[i].sArray[j].Sname = "Student_";
			tArray[i].sArray[j].Sname += nameSeed[j];

			int random = rand() % 60 + 40;//ȡ�෶ΧΪ40~99
			tArray[i].sArray[j].score = random;
		}
	}

}
//�����ʦ�������ѧ���ɼ���������������˫ѭ����ѭ�������ʦ����ѭ��ѧ��
void printInfo(struct Teachar tArray[], int len) {
	for (int i = 0; i < len; i++)
	{
		cout << "��ʦ������" << tArray[i].Tname << endl;//ѭ�������ʦ����

		for (int j = 0; j < 5; j++) {//ѭ�����ѧ���ɼ�����
			cout << "ѧ�������� " << tArray[i].sArray[j].Sname << endl; 
			cout << "ѧ�������� " << tArray[i].sArray[j].score << endl;
		}
	}
}

int main() {
	srand((unsigned int)time(NULL));
	struct Teachar tArray[3];//�����ʦ���ݵ�����
	
	int len = sizeof(tArray) / sizeof(tArray[0]);
	/*Ϊ�˳���ķ����ԣ�����len�ĳ��ȣ���tArray�ܵĳ��ȳ���ÿ��Ԫ��ռ�ó��ȼ��ɵõ�len*/
	allocateSpace(tArray, len);
	printInfo(tArray,len);
	system("pause");//��ͣ���򣬰�������ر�
	return 0;

}