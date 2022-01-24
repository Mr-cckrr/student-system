#include"teacher.h"
Teacher::Teacher(string& a, string& b)
{
	name = a;
	id = b;
}
Teacher::Teacher()
{

}
void Teacher::Show()const
{
	cout << "name: " << name << endl;
	cout << "ID: " << id << endl;
}
