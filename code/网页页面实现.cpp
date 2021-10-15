#include<iostream>
#include<string>
using namespace std;

//普通实现页面

//java页面
//class Jave {
//public:
//	void header() {
//		cout << "首页、公开课、登录、注册(公共头部)" << endl;
//	}
//
//	void footer() {
//		cout << "帮助中心、交流合作、站内地图（公共底部）" << endl;
//	}
//
//	void left() {
//		cout << "Java、python、C++（公共分类列表）" << endl;
//	}
//
//	void content() {
//		cout << "Java学科视频" << endl;
//	}
//};
//
////python页面
//class Python {
//public:
//	void header() {
//		cout << "首页、公开课、登录、注册(公共头部)" << endl;
//	}
//
//	void footer() {
//		cout << "帮助中心、交流合作、站内地图（公共底部）" << endl;
//	}
//
//	void left() {
//		cout << "Java、python、C++（公共分类列表）" << endl;
//	}
//
//	void content() {
//		cout << "python学科视频" << endl;
//	}
//};
//
//class C_PulsPlus{
//	void header() {
//		cout << "首页、公开课、登录、注册(公共头部)" << endl;
//	}
//
//	void footer() {
//		cout << "帮助中心、交流合作、站内地图（公共底部）" << endl;
//	}
//
//	void left() {
//		cout << "Java、python、C++（公共分类列表）" << endl;
//	}
//
//	void content() {
//		cout << "C++学科视频" << endl;
//	}
//};
//void test01() {
//	cout << "Java下载页面如下" << endl;
//	Jave ja;
//	ja.header();
//	ja.footer();
//	ja.left();
//	ja.content();
//
//	Python Py;
//	Py.header();
//	Py.footer();
//	Py.left();
//	Py.content();
//
//}

//继承实现页面
class BasePage {
public:
	 
		void header() {
			cout << "首页、公开课、登录、注册(公共头部)" << endl;
		}
		
		void footer() {
			cout << "帮助中心、交流合作、站内地图（公共底部）" << endl;
		}
		
		void left() {
			cout << "Java、python、C++（公共分类列表）" << endl;
		}
		
		void content() {
			cout << "Java学科视频" << endl;
		}		
};

class Java :public BasePage {
public:
	void content() {
		cout << "Java学科视频" << endl;
	}
};
class Python :public BasePage {
public:
	void content() {
		cout << "Python学科视频" << endl;
	}
};

class Cpp :public BasePage {//只需要将自己特点的东西写下即可省掉很多重复的代码
public:
	void content() {
		cout << "Cpp学科视频" << endl;
	}
};

void test02() {
			cout << "Java下载页面如下" << endl;
			Java ja;
			ja.header();
			ja.footer();
			ja.left();
			ja.content();
		
			Python Py;
			Py.header();
			Py.footer();
			Py.left();
			Py.content();
}
int main() {
	//test01();
	test02();
	return 0;

}