#include<iostream>
#include<string>
using namespace std;
#define MAX 1000

struct Person  //联系人结构体
{
	string m_Name;//姓名
	string m_Sex;//性别
	int m_Age;//年龄
	string  m_Phone;//电话，若用int,可能会存在超出其范围的数据
	string m_Addr;//地址
};

struct Addressbooks  //通讯录结构体
{
	struct Person personArray[MAX];//通讯录中的联系人数组，最大为1000
	int m_Size;//通讯录中人员个数
};

void AddPerson(Addressbooks *abs) {	//添加联系人函数
	//首先要判断人数是否已满，如果满，则不在添加
	if (abs->m_Size == MAX)
	{
		cout << "通讯录已满，无法添加！" << endl;
		return ;
	}
	else //没满就开始添加
	{
		string name; 
		cout << "请输入该联系人姓名: " << endl;
		cin >> name;
		abs->personArray[abs->m_Size].m_Name = name;

		cout << "请输入该联系人性别 ： " << endl; 
		string m_Sex = "a";
		cin >> m_Sex;
		abs->personArray[abs->m_Size].m_Sex = m_Sex;
		 
		cout << "请输入该联系人年龄" << endl; 
		int Age = 0;
		cin >> Age;
		abs->personArray[abs->m_Size].m_Age = Age;

		cout << "请输入该联系人手机号码" << endl; 
		string Phone = "a";
		cin >> Phone;
		abs->personArray[abs->m_Size].m_Phone = Phone;

		cout << "请输入该联系人地址" << endl;
		string Addr = "aa";
		cin >> Addr;
		abs->personArray[abs->m_Size].m_Addr = Addr;

		abs->m_Size++;  /*联系人结构体里变量全部赋值完成后自增,
						为什么不直接在[abs->m.Size]里加，因为
						只是单个变量赋值就自增，而m_size差不多代表一个一维数组*/
	}

	cout << "添加成功，谢谢您的使用" << endl;
	system("pause");
	system("cls");
}
void showMenu() {//显示菜单函数
	cout << "****************************" << endl;
	cout << "******  1.添加联系人******  " << endl;
	cout << "******  2.显示联系人******  " << endl;
	cout << "******  3.删除联系人******  " << endl;
	cout << "******  4.查找联系人******  " << endl;
	cout << "******  5.修改联系人******  " << endl;
	cout << "******  6.清空联系人******  " << endl;
	cout << "******  0.退出通讯录******  " << endl;
}

void showPerson(Addressbooks * abs) {
	//判断通讯录人数是否为0，如果为0就显示空，不为0就输出
	if (abs->m_Size == 0)
		cout << "当前无记录" << endl;
	else
		for (int i = 0; i < abs->m_Size; i++) //循环输出联系人数组的数据
		{
			cout << "姓名：" << abs->personArray->m_Name << endl
				<< "年龄： " << abs->personArray->m_Age << endl
				<< "性别：" << abs->personArray->m_Sex << endl
				<< "电话： " << abs->personArray->m_Phone <<endl
				<< "地址：" << abs->personArray->m_Addr << endl;
		}

}
//检测联系人是否存在，如果存在，返回联系人所在的数组中的具体位置，不存在返回1
int isExist(Addressbooks *abs,string name) { 
	for (int i = 0; i < abs->m_Size; i++) {
		if (abs->personArray[i].m_Name == name) {
			return i;//找到就返回下标编号
		}
	}
	return -1;//如果遍历结束都没找到，返回-1
}

void deletePerson(Addressbooks* abs)//删除指定联系人
{
	cout << "请输入您要删除的联系人" << endl;
	string name;
	cin >> name;
	int ret = isExist(abs, name);//ret == -1未查到，==1则查到

	if (ret != -1) {
		for (int i = ret; i < abs->m_Size; i++)/*为什么是i=ret，因为只需要定位ret，
											   删除之后再迁移，而不是从头开始，能节省时间*/
			abs->personArray[i] = abs->personArray[i + 1];
			abs->m_Size++;
			cout << "删除成功" << endl;
	}
	else
		cout << "查无此人" << endl;
	system("pause");
	system("cls");
}

void findPerson(Addressbooks* abs) {
	cout << "请输入您要查找的联系人" << endl;
	string name;
	cin >> name;

	int ret = isExist(abs,name);

	if (ret != -1) {//找到改人
		cout << "姓名：" << abs->personArray[ret].m_Name << endl
			<< "年龄：" << abs->personArray[ret].m_Age << endl
			<< "性别：" << abs->personArray[ret].m_Sex << endl
			<< "电话： " << abs->personArray[ret].m_Phone << endl
			<< "地址：" << abs->personArray[ret].m_Addr << endl;
	}
	else
		cout << "查无此人" << endl;
	system("pause");
	system("cls");
}

void modifyPerson(Addressbooks* abs) {
	cout << "请输入您要修改的联系人" << endl;
	string name;
	cin >> name;

	int ret = isExist(abs, name);
	if (ret != -1) {
		string name;
		cout << "请输入姓名: " << endl;
		cin >> name;
		abs->personArray[ret].m_Name = name;

		string sex;
		cout << "请输入性别" << endl;
		cin >> sex;
		abs->personArray[ret].m_Sex = sex;

		int age;
		cout << "请输入年龄: " << endl;
		cin >> age;
		abs->personArray[ret].m_Age = age;

		string Phone;
		cout << "请输入电话号码" << endl;
		cin >> Phone;
		abs->personArray[ret].m_Phone = Phone;

		string Arr;
		cout << "请输入地址" << endl;
		cin >> Arr;
		abs->personArray[ret].m_Addr = Arr;

		cout << "修改成功" << endl;
	}
	else
		cout << "查无此人" << endl;
	system("pause");
	system("cls");
}

void cleanPerson(Addressbooks* abs) {//只需要逻辑上清空即可，即把通讯录人员个数变为0
	abs->m_Size = 0;
	cout << "通讯录已清空" << endl;
	system("pause");
	system("cls");
}
int main() {
	Addressbooks abs;//创建通讯录结构体变量
	abs.m_Size = 0; //初始化通讯录中人员个数
	int select = 0;//创建选择用户输入的变量
		
	while (1) {
		showMenu();//菜单函数
		cin >> select;
		switch (select){							
			case 1: //1.添加联系人
				AddPerson(&abs);//创建添加函数，因为要修改数据，所以要传入abs地址
				break;
			case 2://2.显示联系人
				showPerson(&abs);
				break;
			case 3://3.删除联系人
			
				/*cout << "请输入联系人姓名：" << endl;
				string name;
				cin >> name;
				if (isExist(&abs, name) == -1)
					cout << "查无此人" << endl;
				else
					cout << "找到此人" << endl;*/
				deletePerson(&abs);			
				break;
			case 4://4.查找联系人
				findPerson(&abs);
				break;
			case 5:// 5.修改联系人
				modifyPerson(&abs);
				break;
			case 6: // 6.清空联系人
				cleanPerson(&abs);
				break;
			case 0:// 0.退出通讯录
				cout << "欢迎下次使用" << endl;
				return 0;
				break;
			default:
				cout << "输入错误，请重新输入" << endl;
				break;
		}
	}
	
	system("pause");
	return 0;

}