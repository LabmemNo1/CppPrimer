#ifndef SALES_DATA_H
#define SALSE_DATA_H
#include<iostream>
#include<vector>
#include<string>
using namespace std;
class Sales_data
{	                                                        //��Ԫ
	friend Sales_data add(const Sales_data&, const Sales_data&);
	friend ostream &print(ostream &, const Sales_data&);
	friend istream &read(istream &, Sales_data&);
public:

	//���캯��
	//Sales_data()=default; 
	
	
	

	Sales_data(const std::string &s) : bookNo(s){}
	Sales_data(const std::string &s,const unsigned &n,const double &p):bookNo(s),units_sold(n),revenue(n*p){}
	Sales_data(std::istream & is);//read���캯��������
	Sales_data(std::ostream &os);//print ���캯������
	string isbn() const {return bookNo; }
	Sales_data& combine(const Sales_data&);

	//ί�й��캯��
	//Sales_data() :Sales_data(" ", 0, 0) {cout << "Sales_data() :Sales_data( ,0,0 )\n" ;}
	//Sales_data(const string &s) :Sales_data("s",0,0) { cout << "Sales_data():Sales_data(s,0,0)\n"; }
	//Sales_data(istream &is) :Sales_data() { read(is, *this); cout << "read" << endl; }


private:
	inline double avg_price()const;
	string bookNo;
	unsigned units_sold=0;
	double revenue=0.0;



};



//Sales_data�ǳ�Ա��ɲ��ֵ�����
Sales_data add(const Sales_data&, const Sales_data&);
ostream &print(ostream &, const Sales_data&);
istream &read(istream &, Sales_data&);


//����
//ƽ���۸�
double Sales_data::avg_price() const
{
	if (units_sold)
		return revenue / units_sold;
	else
		return 0;
}
//���Sales_data���������
Sales_data& Sales_data::combine(const Sales_data &rhs)
{
	units_sold += rhs.units_sold;
	revenue += rhs.revenue;
	return *this;
}
//������
istream &read(istream &is,  Sales_data &item)
{
	double price = 0;
	is >> item.bookNo >> item.units_sold>>price;
	item.revenue = price * item.units_sold;
	return is;
}
//�������
ostream &print(ostream &os, const Sales_data &item)
{
	os << "���Ϊ"<<item.bookNo <<"����"<<"����"<< item.units_sold<<"��" <<"һ��"<< item.revenue<<"Ǯ"<<"ƽ���۸�Ϊ" << item.avg_price() << endl;
	return os;
}
//���
Sales_data add(Sales_data const &lhs, Sales_data const &rhs)
{
	Sales_data sum = lhs;
	sum.combine(rhs);
	return sum;
}


//���캯�� read
/*Sales_data::Sales_data(istream &is)
{
	read(is, *this);
}*/
//���캯�� print
Sales_data::Sales_data(ostream &os)
{
	print(cout, *this);
}









#endif
