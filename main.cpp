#include<iostream>
#include<string>
#include<cctype>
#include"student.h"
#include"teacher.h"
using namespace std;
int main()
{
	int o = 1;
	ou();
	Student s1;
	cout << "\n������ѡ��" << endl;
	cout << "   " << o++ << "---�鿴����ѧ���ɼ�" << endl;//ʹ��fstream�Ķ�ȡ����ȡ�ļ�����ɣ�
	cout << "   " << o++ << "---���ѧ��" << endl;//����>>�����(��ɣ�
	cout << "   " << o++ << "---����ѧ����Ϣ" << endl;//ʹ��seekg()��seekp()�ƶ��ļ�ָ����ģ���ɣ�
	cout << "   " << o++ << "---�г�ѧ��ƽ���ɼ�" << endl;//�ӵ��ƣ�ȫ�����꼶��ѡ��
	cout << "   " << o++ << "---��ѧ������ѧ����5λ��" << endl;
	cout << "   " << o++ << "---����������ѧ��" << endl;
	cout << "   " << o++ << "---���Ա�����ѧ��" << endl;
	cout << "   " << o++ << "---��ѧ������ѧ��" << endl;
	cout << " ����ѡ��";
	int i;
	cin >> i;
	while (i>=9||i<=0)
	{
		cout << "��������������룺";
		cin >> i;
	}
	switch (i)
	{
	case 1:
		s1.Show();
		break;
	case 2:
		cin >> s1;
		break;
	case 3:
		s1.revise();
		break;
	case 4:
		break;
	case 5:
		break;
	case 6:
		break;
	case 7:
		break;
	case 8:
		break;
	case 9:
		break;
	}

	return 0;
}


