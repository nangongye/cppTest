#include<iostream>
#include<string>
using namespace std;
#define MAX 1000

struct Person  //��ϵ�˽ṹ��
{
	string m_Name;//����
	string m_Sex;//�Ա�
	int m_Age;//����
	string  m_Phone;//�绰������int,���ܻ���ڳ����䷶Χ������
	string m_Addr;//��ַ
};

struct Addressbooks  //ͨѶ¼�ṹ��
{
	struct Person personArray[MAX];//ͨѶ¼�е���ϵ�����飬���Ϊ1000
	int m_Size;//ͨѶ¼����Ա����
};

void AddPerson(Addressbooks *abs) {	//�����ϵ�˺���
	//����Ҫ�ж������Ƿ���������������������
	if (abs->m_Size == MAX)
	{
		cout << "ͨѶ¼�������޷���ӣ�" << endl;
		return ;
	}
	else //û���Ϳ�ʼ���
	{
		string name; 
		cout << "���������ϵ������: " << endl;
		cin >> name;
		abs->personArray[abs->m_Size].m_Name = name;

		cout << "���������ϵ���Ա� �� " << endl; 
		string m_Sex = "a";
		cin >> m_Sex;
		abs->personArray[abs->m_Size].m_Sex = m_Sex;
		 
		cout << "���������ϵ������" << endl; 
		int Age = 0;
		cin >> Age;
		abs->personArray[abs->m_Size].m_Age = Age;

		cout << "���������ϵ���ֻ�����" << endl; 
		string Phone = "a";
		cin >> Phone;
		abs->personArray[abs->m_Size].m_Phone = Phone;

		cout << "���������ϵ�˵�ַ" << endl;
		string Addr = "aa";
		cin >> Addr;
		abs->personArray[abs->m_Size].m_Addr = Addr;

		abs->m_Size++;  /*��ϵ�˽ṹ�������ȫ����ֵ��ɺ�����,
						Ϊʲô��ֱ����[abs->m.Size]��ӣ���Ϊ
						ֻ�ǵ���������ֵ����������m_size������һ��һά����*/
	}

	cout << "��ӳɹ���лл����ʹ��" << endl;
	system("pause");
	system("cls");
}
void showMenu() {//��ʾ�˵�����
	cout << "****************************" << endl;
	cout << "******  1.�����ϵ��******  " << endl;
	cout << "******  2.��ʾ��ϵ��******  " << endl;
	cout << "******  3.ɾ����ϵ��******  " << endl;
	cout << "******  4.������ϵ��******  " << endl;
	cout << "******  5.�޸���ϵ��******  " << endl;
	cout << "******  6.�����ϵ��******  " << endl;
	cout << "******  0.�˳�ͨѶ¼******  " << endl;
}

void showPerson(Addressbooks * abs) {
	//�ж�ͨѶ¼�����Ƿ�Ϊ0�����Ϊ0����ʾ�գ���Ϊ0�����
	if (abs->m_Size == 0)
		cout << "��ǰ�޼�¼" << endl;
	else
		for (int i = 0; i < abs->m_Size; i++) //ѭ�������ϵ�����������
		{
			cout << "������" << abs->personArray->m_Name << endl
				<< "���䣺 " << abs->personArray->m_Age << endl
				<< "�Ա�" << abs->personArray->m_Sex << endl
				<< "�绰�� " << abs->personArray->m_Phone <<endl
				<< "��ַ��" << abs->personArray->m_Addr << endl;
		}

}
//�����ϵ���Ƿ���ڣ�������ڣ�������ϵ�����ڵ������еľ���λ�ã������ڷ���1
int isExist(Addressbooks *abs,string name) { 
	for (int i = 0; i < abs->m_Size; i++) {
		if (abs->personArray[i].m_Name == name) {
			return i;//�ҵ��ͷ����±���
		}
	}
	return -1;//�������������û�ҵ�������-1
}

void deletePerson(Addressbooks* abs)//ɾ��ָ����ϵ��
{
	cout << "��������Ҫɾ������ϵ��" << endl;
	string name;
	cin >> name;
	int ret = isExist(abs, name);//ret == -1δ�鵽��==1��鵽

	if (ret != -1) {
		for (int i = ret; i < abs->m_Size; i++)/*Ϊʲô��i=ret����Ϊֻ��Ҫ��λret��
											   ɾ��֮����Ǩ�ƣ������Ǵ�ͷ��ʼ���ܽ�ʡʱ��*/
			abs->personArray[i] = abs->personArray[i + 1];
			abs->m_Size++;
			cout << "ɾ���ɹ�" << endl;
	}
	else
		cout << "���޴���" << endl;
	system("pause");
	system("cls");
}

void findPerson(Addressbooks* abs) {
	cout << "��������Ҫ���ҵ���ϵ��" << endl;
	string name;
	cin >> name;

	int ret = isExist(abs,name);

	if (ret != -1) {//�ҵ�����
		cout << "������" << abs->personArray[ret].m_Name << endl
			<< "���䣺" << abs->personArray[ret].m_Age << endl
			<< "�Ա�" << abs->personArray[ret].m_Sex << endl
			<< "�绰�� " << abs->personArray[ret].m_Phone << endl
			<< "��ַ��" << abs->personArray[ret].m_Addr << endl;
	}
	else
		cout << "���޴���" << endl;
	system("pause");
	system("cls");
}

void modifyPerson(Addressbooks* abs) {
	cout << "��������Ҫ�޸ĵ���ϵ��" << endl;
	string name;
	cin >> name;

	int ret = isExist(abs, name);
	if (ret != -1) {
		string name;
		cout << "����������: " << endl;
		cin >> name;
		abs->personArray[ret].m_Name = name;

		string sex;
		cout << "�������Ա�" << endl;
		cin >> sex;
		abs->personArray[ret].m_Sex = sex;

		int age;
		cout << "����������: " << endl;
		cin >> age;
		abs->personArray[ret].m_Age = age;

		string Phone;
		cout << "������绰����" << endl;
		cin >> Phone;
		abs->personArray[ret].m_Phone = Phone;

		string Arr;
		cout << "�������ַ" << endl;
		cin >> Arr;
		abs->personArray[ret].m_Addr = Arr;

		cout << "�޸ĳɹ�" << endl;
	}
	else
		cout << "���޴���" << endl;
	system("pause");
	system("cls");
}

void cleanPerson(Addressbooks* abs) {//ֻ��Ҫ�߼�����ռ��ɣ�����ͨѶ¼��Ա������Ϊ0
	abs->m_Size = 0;
	cout << "ͨѶ¼�����" << endl;
	system("pause");
	system("cls");
}
int main() {
	Addressbooks abs;//����ͨѶ¼�ṹ�����
	abs.m_Size = 0; //��ʼ��ͨѶ¼����Ա����
	int select = 0;//����ѡ���û�����ı���
		
	while (1) {
		showMenu();//�˵�����
		cin >> select;
		switch (select){							
			case 1: //1.�����ϵ��
				AddPerson(&abs);//������Ӻ�������ΪҪ�޸����ݣ�����Ҫ����abs��ַ
				break;
			case 2://2.��ʾ��ϵ��
				showPerson(&abs);
				break;
			case 3://3.ɾ����ϵ��
			
				/*cout << "��������ϵ��������" << endl;
				string name;
				cin >> name;
				if (isExist(&abs, name) == -1)
					cout << "���޴���" << endl;
				else
					cout << "�ҵ�����" << endl;*/
				deletePerson(&abs);			
				break;
			case 4://4.������ϵ��
				findPerson(&abs);
				break;
			case 5:// 5.�޸���ϵ��
				modifyPerson(&abs);
				break;
			case 6: // 6.�����ϵ��
				cleanPerson(&abs);
				break;
			case 0:// 0.�˳�ͨѶ¼
				cout << "��ӭ�´�ʹ��" << endl;
				return 0;
				break;
			default:
				cout << "�����������������" << endl;
				break;
		}
	}
	
	system("pause");
	return 0;

}