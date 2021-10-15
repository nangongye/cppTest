#include<iostream>
#include<string>
using namespace std;
/*����һ��ѧ���࣬�����ݳ�Ա�У�ѧ�ţ��������ܳɼ�����Ա���������캯�������������
����������һ�����ѧ���Ķ������顣
Ҫ��1�������ѧ�����ܳɼ���ߺ����
   ��2�������ܳɼ��������������ѧ����Ϣ
   ��3�������ѧ�����ܳɼ���ƽ��ֵ*/
class Student {
public:
    string Name;
    string Id;
    int Score;

    Student(string name, string Id, int score);
    ~Student();   
    friend void statis_Students(Student[], int num);
    void PrintInfo();//�������
    friend void Sort(Student stus[], int num);
};

Student::~Student() {}

Student::Student(string name,string id,int score) {
    this->Name = name;
    this->Id = id;
    this->Score = score;
}
void Student::PrintInfo() {
    cout <<"ѧ��id" << this->Id << "  "
        <<"ѧ������" << this->Name << "  "
        <<"ѧ������" << this->Score << endl;
}

void statis_Students(Student stus[], int num) {
    int max_score, min_score;
    max_score = stus[0].Score;
    min_score = stus[0].Score;
    int avg_score = 0;

    for (int i = 0; i < num; i++) {//�ȳ�ʼ��һ�����ֵ����max��ĸ�ֵ
        avg_score += stus[i].Score;
        if (stus[i].Score > max_score) {
            max_score = stus[i].Score;
        }
        if (stus[i].Score < min_score) {
            min_score = stus[i].Score;
        }
    }
    cout << "�������ֵ" << endl;
    cout << max_score << endl;
    cout << "������Сֵ" << endl;
    cout << min_score << endl;

    avg_score /= num;//ƽ������
    cout << "���ѧ���ķ���ƽ��ֵΪ��" <<avg_score<< endl;

    cout << "����ƽ���ֵ�ѧ�����" << endl;//�������ƽ���ֵ�ѧ��ѧ��
    for (int i = 0; i < num; i++) {
        if (avg_score < stus[i].Score) {
            stus[i].PrintInfo();
        }
    }
}

void Sort(Student stus[], int num) {   
    for (int i = 0; i < num; i++) {//ѡ������
        for (int j = i + 1; j < num; j++) {
            if (stus[i].Score > stus[j].Score) {
                int temp = stus[i].Score;
                stus[i].Score = stus[j].Score;
                stus[j].Score = temp;
            }
        }
    }
    cout << "�����" << endl;
    for (int i = 0; i < num; i++) {
        stus[i].PrintInfo();
    }
    cout << endl;
 
}
int main() {
    Student stus[] = { Student("10", "����", 100),
                    Student("11", "����", 89),
                    Student("12", "����",70) ,
                    Student("13","����",23),
                    Student("14","����",34)};

    statis_Students(stus,5);
    Sort(stus,5);
    return 0;
}