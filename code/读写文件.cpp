#include<iostream>
#include<fstream>
using namespace std;

void test01() {
	ofstream ofs;//创建流对象，//写入操作
	ifstream ifs;//读文件操作

	//打开方式
	ofs.open("test.txt", ios::out);//为写文件而打开文件
	//ofs.open("text.txt", ios::in);//为读文件而打开文件
	//ofs.open("text.txt", ios::ate);//初始位置:文件尾
	//ofs.open("text.txt", ios::app);//追加方式写文件
	//ofs.open("text.txt", ios::trunc);//文件存在先删除，再创建
	//ofs.open("text.txt", ios::binary);//二进制方式
	ofs << "姓名：张三" << endl;
	ofs << "年龄：18" << endl;
	ofs.close();

	/*ofs.close();*///关闭文件
	ifs.open("test.txt",ios::in );
	if (!ifs.is_open()) {
		cout << "文件打开失败" << endl;
		return;
	}
	//读数据,第一种方法
	/*char buf[1024] = { 0 };
	while(ifs>>buf) {
		cout << buf << endl;
	}*/

	//第二种
	/*char buf[1024] = { 0 };
	while (ifs.getline(buf, sizeof(buf))) {
		cout << buf << endl;
	}*/
	
	//第四种
	char c;
	while ((c = ifs.get()) != EOF) {
		cout << buf << endl;
	
	}//eof文件尾
	ifs.close();
}
int main() {
	test01();
	return 0;
}