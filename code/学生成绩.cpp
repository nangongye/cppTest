#include<iostream>
#include<string>
using namespace std;
/*创建一个学生类，该数据成员有：学号，姓名，总成绩；成员函数：构造函数，输出函数。
主函数定义一个五个学生的对象数组。
要求（1）求五个学生的总成绩最高和最低
   （2）按照总成绩的升序排列输出学生信息
   （3）求五个学生的总成绩的平均值*/
class Student {
public:
    string Name;
    string Id;
    int Score;

    Student(string name, string Id, int score);
    ~Student();   
    friend void statis_Students(Student[], int num);
    void PrintInfo();//输出函数
    friend void Sort(Student stus[], int num);
};

Student::~Student() {}

Student::Student(string name,string id,int score) {
    this->Name = name;
    this->Id = id;
    this->Score = score;
}
void Student::PrintInfo() {
    cout <<"学生id" << this->Id << "  "
        <<"学生名字" << this->Name << "  "
        <<"学生分数" << this->Score << endl;
}

void statis_Students(Student stus[], int num) {
    int max_score, min_score;
    max_score = stus[0].Score;
    min_score = stus[0].Score;
    int avg_score = 0;

    for (int i = 0; i < num; i++) {//先初始化一个最大值，比max大的赋值
        avg_score += stus[i].Score;
        if (stus[i].Score > max_score) {
            max_score = stus[i].Score;
        }
        if (stus[i].Score < min_score) {
            min_score = stus[i].Score;
        }
    }
    cout << "分数最大值" << endl;
    cout << max_score << endl;
    cout << "分数最小值" << endl;
    cout << min_score << endl;

    avg_score /= num;//平均分数
    cout << "五个学生的分数平均值为：" <<avg_score<< endl;

    cout << "超过平均分的学生编号" << endl;//输出高于平均分的学生学号
    for (int i = 0; i < num; i++) {
        if (avg_score < stus[i].Score) {
            stus[i].PrintInfo();
        }
    }
}

void Sort(Student stus[], int num) {   
    for (int i = 0; i < num; i++) {//选择排序
        for (int j = i + 1; j < num; j++) {
            if (stus[i].Score > stus[j].Score) {
                int temp = stus[i].Score;
                stus[i].Score = stus[j].Score;
                stus[j].Score = temp;
            }
        }
    }
    cout << "排序后：" << endl;
    for (int i = 0; i < num; i++) {
        stus[i].PrintInfo();
    }
    cout << endl;
 
}
int main() {
    Student stus[] = { Student("10", "马云", 100),
                    Student("11", "马化腾", 89),
                    Student("12", "赵四",70) ,
                    Student("13","张三",23),
                    Student("14","李四",34)};

    statis_Students(stus,5);
    Sort(stus,5);
    return 0;
}