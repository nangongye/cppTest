#include<iostream>
#include<string>
using namespace std;

//��ͨʵ��ҳ��

//javaҳ��
//class Jave {
//public:
//	void header() {
//		cout << "��ҳ�������Ρ���¼��ע��(����ͷ��)" << endl;
//	}
//
//	void footer() {
//		cout << "�������ġ�����������վ�ڵ�ͼ�������ײ���" << endl;
//	}
//
//	void left() {
//		cout << "Java��python��C++�����������б�" << endl;
//	}
//
//	void content() {
//		cout << "Javaѧ����Ƶ" << endl;
//	}
//};
//
////pythonҳ��
//class Python {
//public:
//	void header() {
//		cout << "��ҳ�������Ρ���¼��ע��(����ͷ��)" << endl;
//	}
//
//	void footer() {
//		cout << "�������ġ�����������վ�ڵ�ͼ�������ײ���" << endl;
//	}
//
//	void left() {
//		cout << "Java��python��C++�����������б�" << endl;
//	}
//
//	void content() {
//		cout << "pythonѧ����Ƶ" << endl;
//	}
//};
//
//class C_PulsPlus{
//	void header() {
//		cout << "��ҳ�������Ρ���¼��ע��(����ͷ��)" << endl;
//	}
//
//	void footer() {
//		cout << "�������ġ�����������վ�ڵ�ͼ�������ײ���" << endl;
//	}
//
//	void left() {
//		cout << "Java��python��C++�����������б�" << endl;
//	}
//
//	void content() {
//		cout << "C++ѧ����Ƶ" << endl;
//	}
//};
//void test01() {
//	cout << "Java����ҳ������" << endl;
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

//�̳�ʵ��ҳ��
class BasePage {
public:
	 
		void header() {
			cout << "��ҳ�������Ρ���¼��ע��(����ͷ��)" << endl;
		}
		
		void footer() {
			cout << "�������ġ�����������վ�ڵ�ͼ�������ײ���" << endl;
		}
		
		void left() {
			cout << "Java��python��C++�����������б�" << endl;
		}
		
		void content() {
			cout << "Javaѧ����Ƶ" << endl;
		}		
};

class Java :public BasePage {
public:
	void content() {
		cout << "Javaѧ����Ƶ" << endl;
	}
};
class Python :public BasePage {
public:
	void content() {
		cout << "Pythonѧ����Ƶ" << endl;
	}
};

class Cpp :public BasePage {//ֻ��Ҫ���Լ��ص�Ķ���д�¼���ʡ���ܶ��ظ��Ĵ���
public:
	void content() {
		cout << "Cppѧ����Ƶ" << endl;
	}
};

void test02() {
			cout << "Java����ҳ������" << endl;
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