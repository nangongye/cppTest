#include<iostream>
using namespace std;
#include<string>
#include<ctime>
/*学校正在做毕设项目，每名老师带领5个学生，总共有3名老师，需求如下
设计学生和老师的结构体，其中在老师的结构体中，有老师姓名和一个存放5名
学生的数组作为成员。学生的成员有姓名、考试分数，创建数组存放
3名老师，通过函数给每个老师及所带的学生赋值，最终打印出老师数据
以及老师所带的学生数据*/
struct Student//创建学生的结构体
{
	string	Sname;//学生名字
	int score;//学生成绩
};
struct Teachar
{
	string Tname;//老师名字
	struct Student sArray[5];/*创建学生数组	，若数组报错不完整的数据类型，
							 是因为Student没有定义*/
};
//给老师赋值的函数
void allocateSpace(struct Teachar tArray[],int len) {
	string nameSeed = "ABCDE";//老师名字下划线追加,nameseed为追加字符操作

	for (int i = 0; i < len; i++){
		tArray[i].Tname = "Teachar_";//对老师数组之中老师名称赋值				
		tArray[i].Tname += nameSeed[i];//每i+1,老师名字下划线将追加一个字符

		//通过循环给老师所带的学生赋值
		for (int j = 0; j < 5; j++) {
			tArray[i].sArray[j].Sname = "Student_";
			tArray[i].sArray[j].Sname += nameSeed[j];

			int random = rand() % 60 + 40;//取余范围为40~99
			tArray[i].sArray[j].score = random;
		}
	}

}
//输出老师所带领的学生成绩和姓名函数，用双循环先循环输出老师，在循环学生
void printInfo(struct Teachar tArray[], int len) {
	for (int i = 0; i < len; i++)
	{
		cout << "老师姓名：" << tArray[i].Tname << endl;//循环输出老师名字

		for (int j = 0; j < 5; j++) {//循环输出学生成绩姓名
			cout << "学生姓名： " << tArray[i].sArray[j].Sname << endl; 
			cout << "学生分数： " << tArray[i].sArray[j].score << endl;
		}
	}
}

int main() {
	srand((unsigned int)time(NULL));
	struct Teachar tArray[3];//存放老师数据的数组
	
	int len = sizeof(tArray) / sizeof(tArray[0]);
	/*为了程序的泛用性，计算len的长度，将tArray总的长度除以每个元素占用长度即可得到len*/
	allocateSpace(tArray, len);
	printInfo(tArray,len);
	system("pause");//暂停程序，按任意键关闭
	return 0;

}