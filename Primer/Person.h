#ifndef PERSON_H
#define PERSON_H
#include<iostream>
#include<vector>
#include<string>
using namespace std;



class Person {
	friend istream &read(istream &is, Person &it);
	friend ostream &print(ostream &os, const Person &it);
	//构造函数
public:
	Person()=default;
	Person(const string &n,const string &a):name(n),address(a){}
	Person(istream &is);
	//定义变量
	
	//类函数定义
	void show()
	{
		cout << name << "的地址为" << address << endl;
	}
	string& const show_name()
	{
		return name;
	}

	string& const show_address()
	{
		return address;
	}
private:
	string name;
	string address;

};
//Person::Person(string Client_name, string Client_address) :name(Client_name), address(Client_address) {};


//声明
istream &read(istream &is, Person &it);
ostream &print(ostream &os, const Person &it);







//读取
istream &read(istream &is, Person &it)
{
	is >> it.name >> it.address;
	return is;
}
// 打印
ostream &print(ostream &os, const Person &it)
{
	os << "名字为" << it.name << "地址为" << it.address;
	return os;
}


//read构造函数
Person::Person(istream &is)
{
	read(cin, *this);
}













#endif
