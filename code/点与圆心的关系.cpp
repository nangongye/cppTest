#include<iostream>
#include<string>
using namespace std;

class Point {//点类
public://设置x
	void  setX(int x) {
		m_x = x;
	}

	//设置y
	void setY(int y) {
		m_y = y;
	}

	//获取y
	int get_Y() {
		return m_y;
	}

	//获取x
	int  get_X() {
		return m_x;
	}
private:
	int m_x;
	int m_y;
};

class circle {
public:
	//设置半径
	void setR(int r) {
		m_R = r;
	}
	//获取半径
	int get_R() {
		return m_R;
	}
	//设置圆心
	void setCenter(Point center) {
		m_Center = center;
	}
	//获取圆心
	Point getCenter() {
		return m_Center;
	}
private:
	int m_R;//半径
	Point m_Center;//圆心
};
void isInCircle(circle& c, Point& p) {
	//计算两点之间距离平方
	int distance =
		(c.getCenter().get_X() - p.get_X()) * (c.getCenter().get_X() - p.get_X()) +
		(c.getCenter().get_Y() - p.get_Y()) * (c.getCenter().get_Y() - p.get_Y());

	int rDistance = c.get_R() * c.get_R();

	//判断关系
	if (distance == rDistance)
		cout << "点在圆上" << endl;
	else if (distance > rDistance)
		cout << "点在圆外" << endl;
	else
		cout << "点在圆内" << endl;
}
int main() {
	//创建一个圆
	circle c;
	c.setR(10);
	Point center;
	center.setX(0);
	center.setY(0);
	c.setCenter(center);

	//创建点
	Point p;
	p.setX(10);
	p.setY(10);

	//判断关系
	isInCircle(c, p);

}