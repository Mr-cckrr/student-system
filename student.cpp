#include<iostream>
#include"student.h"
int ct;
Student::Student()
{
}
Student::~Student()
{

}
Student::Student(const string& a, int b, int f)
{
	name = a;
	id = b;
	achievement = f;
}
void Student::Show()const
{
	op xu;
	ifstream fin;
	fin.open(pl, ios_base::in | ios_base::binary);
	if (fin.is_open())
	{
		ct = 0;
		cout << "����ѧ����\n";
		while (fin.read((char*)&xu, sizeof xu))
		{
			ou();
			cout << "  \n" << ct++ << "\n" << "ѧ��: " << xu.id;
			cout << "  " << setw(6) << "����: " << xu.naem << endl;
			cout << "�Ա�: " << xu.gender;
			cout << "  " << setw(6) << "�ɼ�: " << xu.achievement << endl;
		}
	}
	fin.close();
	
}
istream& operator>>(istream& is,const Student& s)
{
	ifstream fin;
	ofstream outfile;
	op xu;
	fin.open(s.pl, ios_base::in | ios_base::binary);
	if (fin.is_open())
	{
		ct = 0;
		cout << "����ѧ����\n";
		while (fin.read((char*)&xu, sizeof xu))
		{
			ou();
			cout << "  \n" << ct++ << "\n" << "ѧ��: " << xu.id;
			cout << "  " << setw(6) << "����: " << xu.naem << endl;
			cout << "�Ա�: " << xu.gender;
			cout << "  " << setw(6) << "�ɼ�: " << xu.achievement << endl;
		}
	}
	fin.close();

	outfile.open(s.pl, ios_base::out | ios_base::app | ios_base::binary);
	if (!outfile.is_open())
	{
		cerr << "д���ļ�ʧ��";
		exit(EXIT_FAILURE);
	}
	else
	{

		cout << "����ѧ�ţ�";
		cin >> xu.id;

		cout << "����������";
		cin >> xu.naem;

		cout << "�����Ա�";
		cin >> xu.gender;

		cout << "����ɼ�: ";
		cin >> xu.achievement;
		eatline();
		outfile.write((char*)&xu, sizeof xu);
	}
	outfile.close();
	fin.open(s.pl, ios_base::in | ios_base::binary);
	if (fin.is_open())
	{
		ct = 0;
		cout << "����ѧ����\n";
		while (fin.read((char*)&xu, sizeof xu))
		{
			ou();
			cout << "\n  " << ct++ << "\n" << "ѧ��: " << xu.id;
			cout << "  " << setw(6) << "����: " << xu.naem << endl;
			cout << "�Ա�: " << xu.gender;
			cout << "  " << setw(6) << "�ɼ�: " << xu.achievement << endl;
		}
	}
	fin.close();
	return is;
}
void Student::revise()
{
	fstream foin;
	op xu;
	foin.open(pl, ios_base::in |ios_base::out| ios_base::binary);
	if (foin.is_open())
	{
		ct = 0;
		foin.seekg(0);
		while (foin.read((char*)&xu, sizeof xu))
		{
			ou();
			cout << "\n  " << ct++ << "\n" << "ѧ��: " << xu.id;
			cout << "  " << setw(6) << "����: " << xu.naem << endl;
			cout << "�Ա�: " << xu.gender;
			cout << "  " << setw(6) << "�ɼ�: " << xu.achievement << endl;
		}
		if (foin.eof())
			foin.clear();
		else
		{
			cerr << "�ж�ĩβ����";
			exit(EXIT_FAILURE);
		}
	}
	else
	{
		cerr << "��ȡ�ļ�ʧ��";
		exit(EXIT_FAILURE);

	}
	long  kk;
	cout << "ѡ��Ҫ���ĵ�ѧ����";
	cin >> kk;
	eatline();
	if (kk < 0 || kk >= ct)
	{
		cerr << "�����ں���";
		exit(EXIT_FAILURE);
	}

	streampos pa = kk * sizeof xu;
	foin.seekg(pa);
	if (foin.fail())
	{
		cerr << "�򿪸����ļ�ʧ��";
		exit(EXIT_FAILURE);
	}
	
	foin.read((char*)&xu, sizeof xu);

	cout << "\n  " << kk << "\n" << "ѧ��: " << xu.id;
	cout << "  " << setw(6) << "����: " << xu.naem << endl;
	cout << "�Ա�: " << xu.gender;
	cout << "  " << setw(6) << "�ɼ�: " << xu.achievement << endl;
	if (foin.eof())
		foin.clear();

	cout << "����ѧ�ţ�";
	cin >> xu.id;

	cout << "����������";
	cin >> xu.naem;

	cout << "�����Ա�";
	cin >> xu.gender;
	
	cout << "����ɼ�: ";
	cin >> xu.achievement;
	eatline();
	foin.seekp(pa);
	foin.write((char*)&xu, sizeof xu)<<flush;
	
	if (foin.fail())
	{
		cerr << "��ȡ�����ļ�����";
		exit(EXIT_FAILURE);
	}
	
		ct = 0;
		foin.seekg(0);
		
		cout << "����ѧ����\n";
		while (foin.read((char*)&xu, sizeof xu))
		{	
			ou();
			cout << "\n  " << ct++ << "\n" << "ѧ��: " << xu.id;
			cout << "  " << setw(6) << "����: " << xu.naem << endl;
			cout << "�Ա�: " << xu.gender;
			cout << "  " << setw(6) << "�ɼ�: " << xu.achievement << endl;
		}
	foin.close();
	
}