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
	cout << "\n请输入选项" << endl;
	cout << "   " << o++ << "---查看所有学生成绩" << endl;//使用fstream的读取流读取文件（完成）
	cout << "   " << o++ << "---添加学生" << endl;//重载>>运算符(完成）
	cout << "   " << o++ << "---更改学生信息" << endl;//使用seekg()和seekp()移动文件指针更改（完成）
	cout << "   " << o++ << "---列出学生平均成绩" << endl;//从单科，全部，年级里选择。
	cout << "   " << o++ << "---按学号索检学生（5位）" << endl;
	cout << "   " << o++ << "---按姓名索检学生" << endl;
	cout << "   " << o++ << "---按性别索检学生" << endl;
	cout << "   " << o++ << "---按学号索检学生" << endl;
	cout << " 输入选择：";
	int i;
	cin >> i;
	while (i>=9||i<=0)
	{
		cout << "输入错误，重新输入：";
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


