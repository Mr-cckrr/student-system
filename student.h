#pragma once
#ifndef SHCOOLCHANG_H_
#define SHCOOLCHANG_H_
#include<iostream>
#include<string>
#include<fstream>
#include<cstdlib>
#include<iomanip>
using namespace std;
inline void eatline() { while (std::cin.get() != '\n')continue; }
inline void ou() { for (int i = 0; i < 20; i++)cout << "="; }
static struct op//The next method is not used,just for pasing,so use struct
	{
		int id;
		char naem[50];
		int achievement;
		char gender[50];
	};
class Student
{
	
private:
	string name;
	int id;
	int achievement;
	const char* pl = "Student.dat";
public:
	Student(const string& a, int b, int f);
	Student();
	~Student();
	void Show()const;
	void revise();
	friend istream& operator>>(istream& is, const Student& s);

};


#endif