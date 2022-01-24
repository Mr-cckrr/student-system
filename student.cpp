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
		cout << "现有学生：\n";
		while (fin.read((char*)&xu, sizeof xu))
		{
			ou();
			cout << "  \n" << ct++ << "\n" << "学号: " << xu.id;
			cout << "  " << setw(6) << "姓名: " << xu.naem << endl;
			cout << "性别: " << xu.gender;
			cout << "  " << setw(6) << "成绩: " << xu.achievement << endl;
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
		cout << "现有学生：\n";
		while (fin.read((char*)&xu, sizeof xu))
		{
			ou();
			cout << "  \n" << ct++ << "\n" << "学号: " << xu.id;
			cout << "  " << setw(6) << "姓名: " << xu.naem << endl;
			cout << "性别: " << xu.gender;
			cout << "  " << setw(6) << "成绩: " << xu.achievement << endl;
		}
	}
	fin.close();

	outfile.open(s.pl, ios_base::out | ios_base::app | ios_base::binary);
	if (!outfile.is_open())
	{
		cerr << "写入文件失败";
		exit(EXIT_FAILURE);
	}
	else
	{

		cout << "输入学号：";
		cin >> xu.id;

		cout << "输入姓名：";
		cin >> xu.naem;

		cout << "输入性别：";
		cin >> xu.gender;

		cout << "输入成绩: ";
		cin >> xu.achievement;
		eatline();
		outfile.write((char*)&xu, sizeof xu);
	}
	outfile.close();
	fin.open(s.pl, ios_base::in | ios_base::binary);
	if (fin.is_open())
	{
		ct = 0;
		cout << "现有学生：\n";
		while (fin.read((char*)&xu, sizeof xu))
		{
			ou();
			cout << "\n  " << ct++ << "\n" << "学号: " << xu.id;
			cout << "  " << setw(6) << "姓名: " << xu.naem << endl;
			cout << "性别: " << xu.gender;
			cout << "  " << setw(6) << "成绩: " << xu.achievement << endl;
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
			cout << "\n  " << ct++ << "\n" << "学号: " << xu.id;
			cout << "  " << setw(6) << "姓名: " << xu.naem << endl;
			cout << "性别: " << xu.gender;
			cout << "  " << setw(6) << "成绩: " << xu.achievement << endl;
		}
		if (foin.eof())
			foin.clear();
		else
		{
			cerr << "判断末尾错误";
			exit(EXIT_FAILURE);
		}
	}
	else
	{
		cerr << "读取文件失败";
		exit(EXIT_FAILURE);

	}
	long  kk;
	cout << "选择要更改的学生：";
	cin >> kk;
	eatline();
	if (kk < 0 || kk >= ct)
	{
		cerr << "不存在号数";
		exit(EXIT_FAILURE);
	}

	streampos pa = kk * sizeof xu;
	foin.seekg(pa);
	if (foin.fail())
	{
		cerr << "打开更改文件失败";
		exit(EXIT_FAILURE);
	}
	
	foin.read((char*)&xu, sizeof xu);

	cout << "\n  " << kk << "\n" << "学号: " << xu.id;
	cout << "  " << setw(6) << "姓名: " << xu.naem << endl;
	cout << "性别: " << xu.gender;
	cout << "  " << setw(6) << "成绩: " << xu.achievement << endl;
	if (foin.eof())
		foin.clear();

	cout << "输入学号：";
	cin >> xu.id;

	cout << "输入姓名：";
	cin >> xu.naem;

	cout << "输入性别：";
	cin >> xu.gender;
	
	cout << "输入成绩: ";
	cin >> xu.achievement;
	eatline();
	foin.seekp(pa);
	foin.write((char*)&xu, sizeof xu)<<flush;
	
	if (foin.fail())
	{
		cerr << "读取更改文件错误";
		exit(EXIT_FAILURE);
	}
	
		ct = 0;
		foin.seekg(0);
		
		cout << "现有学生：\n";
		while (foin.read((char*)&xu, sizeof xu))
		{	
			ou();
			cout << "\n  " << ct++ << "\n" << "学号: " << xu.id;
			cout << "  " << setw(6) << "姓名: " << xu.naem << endl;
			cout << "性别: " << xu.gender;
			cout << "  " << setw(6) << "成绩: " << xu.achievement << endl;
		}
	foin.close();
	
}