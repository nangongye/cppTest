#include<iostream>
#include<fstream>
using namespace std;

void test01() {
	ofstream ofs;//����������//д�����
	ifstream ifs;//���ļ�����

	//�򿪷�ʽ
	ofs.open("test.txt", ios::out);//Ϊд�ļ������ļ�
	//ofs.open("text.txt", ios::in);//Ϊ���ļ������ļ�
	//ofs.open("text.txt", ios::ate);//��ʼλ��:�ļ�β
	//ofs.open("text.txt", ios::app);//׷�ӷ�ʽд�ļ�
	//ofs.open("text.txt", ios::trunc);//�ļ�������ɾ�����ٴ���
	//ofs.open("text.txt", ios::binary);//�����Ʒ�ʽ
	ofs << "����������" << endl;
	ofs << "���䣺18" << endl;
	ofs.close();

	/*ofs.close();*///�ر��ļ�
	ifs.open("test.txt",ios::in );
	if (!ifs.is_open()) {
		cout << "�ļ���ʧ��" << endl;
		return;
	}
	//������,��һ�ַ���
	/*char buf[1024] = { 0 };
	while(ifs>>buf) {
		cout << buf << endl;
	}*/

	//�ڶ���
	/*char buf[1024] = { 0 };
	while (ifs.getline(buf, sizeof(buf))) {
		cout << buf << endl;
	}*/
	
	//������
	char c;
	while ((c = ifs.get()) != EOF) {
		cout << buf << endl;
	
	}//eof�ļ�β
	ifs.close();
}
int main() {
	test01();
	return 0;
}