#ifndef PERSON_H
#define PERSON_H
#include<iostream>
#include<vector>
#include<string>
using namespace std;



class Person {
	friend istream &read(istream &is, Person &it);
	friend ostream &print(ostream &os, const Person &it);
	//���캯��
public:
	Person()=default;
	Person(const string &n,const string &a):name(n),address(a){}
	Person(istream &is);
	//�������
	
	//�ຯ������
	void show()
	{
		cout << name << "�ĵ�ַΪ" << address << endl;
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


//����
istream &read(istream &is, Person &it);
ostream &print(ostream &os, const Person &it);







//��ȡ
istream &read(istream &is, Person &it)
{
	is >> it.name >> it.address;
	return is;
}
// ��ӡ
ostream &print(ostream &os, const Person &it)
{
	os << "����Ϊ" << it.name << "��ַΪ" << it.address;
	return os;
}


//read���캯��
Person::Person(istream &is)
{
	read(cin, *this);
}













#endif
