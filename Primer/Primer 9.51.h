#include<iostream>
#include<fstream>
#include<sstream>
#include<vector>
#include<string>
#include<deque>
#include<list>
#include<forward_list>
using namespace std;
class Primer    //���˵ͼ��Ĵ� switch�����case������ţ����캯������const������pos1δ��ʼ��
{
public:
	Primer(string s);
	void show()
	{
		cout << years << "��" << months << "��" << days << "��" << endl;
	}
unsigned years;
	unsigned months;
	unsigned days;







};
Primer::Primer(string s)
{
	string num = "0123456789/";
	string coma = ",";
	string num2 = "0123456789";
	string xie = "/";
	int flag = 0;
	
	string::size_type pos = 0;
	string::size_type pos0, pos1, pos2;
	string::size_type pos01, pos11, pos21,pos12;
	
	
	string ri;
	string yue;
	string nian;
	//���� ������ʽ ����תΪ ��������
	if ((pos = s.find_first_not_of(num)) == string::npos)
	{
		flag = 1;
	}
	if ((pos = s.find_first_of(coma)) != string::npos)
	{
		flag = 2;
	}
	switch (flag)
	{
	case 1://  1/1/1990��ʽ

		pos1 = 0;
		pos1 = s.find_first_of("/");
		
		yue = s.substr(0, pos1);
		months = stoul(yue);

		pos11=++pos1;
		pos1 = s.find_first_of("/",pos1);
		ri = s.substr(pos11, pos1);
		days = stoul(ri);


		pos12=++pos1;
		nian = s.substr(pos12);
		years = stoul(nian);
break;


		
		
		

		//pos1 = 0;
		//pos1 = s.find_first_of("/", pos1);
		//days = stoul(s.substr(0, pos1));//�Ƚ�ȡĿ���ַ������ٽ��ַ���ת��Ϊunsigned
		//pos11 = ++pos1;
		//pos1 = s.find_first_of("/", pos1);
		//months = stoul(s.substr(pos11, pos1));
		//pos12 = ++pos1;
		//years = stoul(s.substr(pos12));
		//break;
		//


	


	case 2: //January 1,1990

		pos2 = s.find_first_of(num);
		yue = s.substr(0, pos2 - 1);
		if (yue == "January")months = 1;
		if (yue == "February")months = 2;
		if (yue == "March")months = 3;
		if (yue == "April")months = 4;
		if (yue == "May ")months = 5;
		if (yue == "June")months = 6;
		if (yue == "July")months = 7;
		if (yue == "August")months = 8;
		if (yue == "September")months = 9;
		if (yue == "October")months = 10;
		if (yue == "November")months = 11;
		if (yue == "December")months = 12;




		pos21 = s.find_first_of(coma);
		ri = s.substr(pos2, pos21 - 1);
		days = stoi(ri);




		nian = s.substr(pos21 + 1);
		years = stoi(nian);





		break;




	case 0://Jan 1 1900

		pos0 = s.find_first_of(num);
		yue = s.substr(0, pos0 - 1);
		if (yue == "Jan")months = 1;
		if (yue == "Feb")months = 2;
		if (yue == "Mar")months = 3;
		if (yue == "Apr")months = 4;
		if (yue == "May ")months = 5;
		if (yue == "Jun")months = 6;
		if (yue == "Jul")months = 7;
		if (yue == "Aug")months = 8;
		if (yue == "Sep")months = 9;
		if (yue == "Oct")months = 10;
		if (yue == "Nov")months = 11;
		if (yue == "Dec")months = 12;


		pos01 = s.find_first_of(" ", pos0);
		ri = s.substr(pos0, pos01);
		days = stoi(ri);




		nian = s.substr(pos01 + 1);
		years = stoi(nian);

		break;


	}

}