#pragma once
#ifndef _TEACHER_H_
#define _TEACHER_H_
#include<iostream>
using namespace std;
class Teacher
{
private:
	string name;
	string id;
public:
	Teacher(string& a, string& b);
	Teacher();
	void Show()const;


};
#endif // !_LAOS_H_
