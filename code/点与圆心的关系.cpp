#include<iostream>
#include<string>
using namespace std;

class Point {//����
public://����x
	void  setX(int x) {
		m_x = x;
	}

	//����y
	void setY(int y) {
		m_y = y;
	}

	//��ȡy
	int get_Y() {
		return m_y;
	}

	//��ȡx
	int  get_X() {
		return m_x;
	}
private:
	int m_x;
	int m_y;
};

class circle {
public:
	//���ð뾶
	void setR(int r) {
		m_R = r;
	}
	//��ȡ�뾶
	int get_R() {
		return m_R;
	}
	//����Բ��
	void setCenter(Point center) {
		m_Center = center;
	}
	//��ȡԲ��
	Point getCenter() {
		return m_Center;
	}
private:
	int m_R;//�뾶
	Point m_Center;//Բ��
};
void isInCircle(circle& c, Point& p) {
	//��������֮�����ƽ��
	int distance =
		(c.getCenter().get_X() - p.get_X()) * (c.getCenter().get_X() - p.get_X()) +
		(c.getCenter().get_Y() - p.get_Y()) * (c.getCenter().get_Y() - p.get_Y());

	int rDistance = c.get_R() * c.get_R();

	//�жϹ�ϵ
	if (distance == rDistance)
		cout << "����Բ��" << endl;
	else if (distance > rDistance)
		cout << "����Բ��" << endl;
	else
		cout << "����Բ��" << endl;
}
int main() {
	//����һ��Բ
	circle c;
	c.setR(10);
	Point center;
	center.setX(0);
	center.setY(0);
	c.setCenter(center);

	//������
	Point p;
	p.setX(10);
	p.setY(10);

	//�жϹ�ϵ
	isInCircle(c, p);

}