#include<iostream>
#include<fstream>
#include<sstream>
#include<vector>
#include<string>
#include<deque>
#include<list>
#include<forward_list>
#include<algorithm>
#include<numeric>
#include"chapter6.h"
#include"Sales_data.h"
#include"Screen.h"
#include"Person.h"
#include"PersonInfo.h"
#include"Primer 9.51.h"
#include<functional>
#include<iterator>
using namespace std;
using namespace std::placeholders;
bool compareIsbn(Sales_data s1, Sales_data s2)

{
	return s1.isbn().size() < s2.isbn().size();
}

int main(int argc,char* argv[])
{
	/*for (int i = 0; i < 10; ++i)
		cout << count_calls() << endl;
	int a = 5;
	int b = 7;
	int *p = &a;
	int *q = &b;
	changezhen(p, q);
	cout << *p << *q << endl;
	string s1 = "abcccgcc";
	char s2 = 'c';
	size_t val = 0;
	int number = find_char(s1, s2, val);
	cout << "c第一次出现的位置为" << number << endl;
	cout << "c出现了" << val << endl;
	int c = 6;
	cout << jiecheng(c) << endl;
	typedef int(*s)(int a, int b);
	vector<s> d = { ssum,jian,cheng,chu };
	for (auto z : d)
		cout << z(2, 2) << endl;*/




	//Sales_data类
	/*ifstream input(argv[1]);
	ofstream output(argv[2],ofstream::app);
	Sales_data total;
	
	if (read(input, total))
	{
		Sales_data trans;
			while (read(input, trans))
			{
				if (trans.isbn() == total.isbn())
					total.combine(trans);
				else
				{
					print(output, total);
						total = trans;
				}
			}
		print(output, total);

	}
	else
	{
		cerr << "no data enter" << endl;
	}*/


	//PersonInfo类
	/*string line, word;
	vector<PersonInfo> people;
	while (getline(cin, line))
	{
		PersonInfo info;
		istringstream record(line);
		record >> info.name;
		while (record >> word)
			info.phones.push_back(word);
		people.push_back(info);
	}

	list<deque<int>>;
	*/


	//8.10
	/*
	vector<string> sa;
	string s3;
	ifstream file("x.txt");
	string s1;
	while(getline(file,s1))
	{
		sa.push_back(s1);
	}
	for (const auto &a : sa) 
	{
		istringstream s2(a);
		
		s2 >> s3;
		
cout << s3 << endl;


	}
	*/












	//Screen类
	/*Screen myScreen(5, 5, 'x');
	myScreen.move(4, 0).set('#').display(cout);
	cout << "\n";
	myScreen.display(cout);*/







	//8.4
	/*
	string s = "x.txt";//读取的路径
	ifstream ifs(s);
	vector<string> sv;
	
	if (ifs)
	{
		string a;
		while (ifs>>a) //getline是以行输入  直接ifs是单个元素输入
		{
			sv.push_back(a);
		}
	}
	else 
	{
		cerr << "不能打开" <<  endl;
	}

	for (const auto &i : sv)
		cout << i << endl;

		*/




/*list<char*> l1;
vector<string> v1;//容器的简单赋值操作
v1.assign(l1.begin(), l1.end());*/

//9.26
/*
int ia[] = { 0,1,1,2,3,5,8,13,21,55,89 };
vector<int> v(ia,ia+9);
list<int> l(ia, ia + 9);
auto vb = v.begin();
auto lb = l.begin();
while (vb != v.end())
{
	if (!(*vb% 2))
	{
		vb = v.erase(vb);
	}
	else
		++vb;
}
while (lb != l.end())
{
	if (*lb % 2)
	{
		lb = l.erase(lb);
	}
	else
		++lb;
}
for (auto const &a : v)
cout << a << endl;
for (auto const &s : l)
cout << s << endl;
*/



//9.27  单向链表的删除操作 
/*
forward_list<int> fl = { 0,1,1,2,3,5,8,13,21,55,89 };
auto sq = fl.before_begin();
auto s = fl.begin();
while (s != fl.end())
{
	if (*s % 2)
	{
		s = fl.erase_after(sq);
	}
	else 
	{
		sq = s;
		++s;
	}
}
for (auto const &d : fl)
cout << d << endl;


*/
//9.33
/*
vector<int> v = { 0,1,2,3,4,5,6 };
auto begin = v.begin();
while (begin != v.end())
{
	++begin;
	begin=v.insert(begin, 42);
	++begin;
}
for (auto const &s : v)
cout << s << endl;

auto d = v.capacity();
cout << d << endl;

*/





//9.41   利用迭代器拷贝
/*
vector<char> v = { 'a','s' };
string s(v.begin(),v.end());

*/

//9.43
/*
string s = "abcdefg";
string oldval = "bc";
string newval = "asas";
stx(s, oldval, newval);
cout << s << endl;
*/




//9.47
/*
string s1 = "ab2c3d7R4E6";
string num = "0123456789";

string::size_type pos = 0;
while((pos=s1.find_first_of(num,pos))!=string::npos)
{
	cout << "在第" << pos << "个位置发现" << endl;
	++pos;
}
pos = 0;
while ((pos = s1.find_first_not_of(num, pos)) != string::npos)
{
	cout << "在第" << pos << "个位置发现" << endl;
	++pos;
}
*/
// 9.49
/*
string s = "acenmorsuvwxz";
ifstream file("1.txt");
string str;
file >> str;
string::size_type pos1 = 0, pos3 = 0;
string::size_type pos2 = 0;
string::size_type length = 0;
while ((pos1 = str.find_first_of(s, pos1)) != string::npos)
{
	pos2 = pos1;
	if ((pos2 = str.find_first_not_of(s, pos2)) != string::npos)
	{
		if (pos2 - pos1 >= length)
		{
			length = pos2 - pos1;
			pos3 = pos1;
		}
	}
	++pos1;
}
string fin = str.substr(pos3, length);
cout << fin << endl;
*/





//9.50
/*
vector<string> v(20, "7");
int sum1=0;
double sum2 = 0.0;

for (int i = 0; i < v.size(); i++)
{
	sum1 += stoi(v[i]);
	sum2 += stod(v[i]);
}
cout << sum1 << endl;
cout << sum2 << endl;


*/

//10.1
//int a[10]={ 0,1,2,3,4,5,6,7,8,9 };
//vector<int> v(a, a + 10);
//int val = 1;
//cout << val << "出现的次数" << count(v.begin(), v.end(), val) << endl;

//10.3

//vector<int> v(10, 5);
//int sum = accumulate(v.cbegin(), v.cend(), 0);
//cout << "v中元素的和为" << sum << endl;


//10.9  消除重复单词

//
//vector<string> words = { "the","quick","red","fox","jumps","over","the","slow","red","turtle" };
//
//elimDups(words);
//for (auto &it1 : words)
//cout << it1 << endl;
//cout << "\n\n\n\n" << endl;
//
////10.11
//stable_sort(words.begin(),words.end(),isShorter);
//for (auto &it2 : words)
//cout << it2 << endl;
//



//10.12


//Sales_data a("because");//初始化对象
//Sales_data b("I");
//Sales_data c("Like");
//Sales_data d("your");
//Sales_data e("beautiful");
//Sales_data f("eyes");
//
//
//vector<Sales_data> v = { a,b,c,d,e,f };
//cout << v[1].isbn() << endl;
//stable_sort(v.begin(),v.end(),compareIsbn);
//
//
//for (int i = 0; i < v.size(); ++i)
//{
//	cout << v[i].isbn() << " ";
//}
//



//10.13
//vector<string> words = { "the","quick","red","fox","jumps","over","the","slow","red","turtle" };
//partition(words.begin(), words.end(), boom);
//
//for (auto &it : words)
//cout << it << endl;






//lambda表达式
//vector<string> words = { "the","quick","red","fox","jumps","over","the","slow","red","turtle" };
//biggies(words,5);



//
////10.17
//
//
//Sales_data a("because");//初始化对象
//Sales_data b("I");
//Sales_data c("Like");
//Sales_data d("your");
//Sales_data e("beautiful");
//Sales_data f("eyes");
//
//
//vector<Sales_data> v = { a,b,c,d,e,f };
//stable_sort(v.begin(), v.end(), [](Sales_data a, Sales_data b) {return a.isbn().size() < b.isbn().size(); });
//
//
//for (int i = 0; i < v.size(); ++i)
//{
//	cout << v[i].isbn() << " ";
//}



//10.18
//vector<string> words = { "the","quick","red","fox","jumps","over","the","slow","red","turtle" };
//biggiest(words,5);


//10.20
//vector<string> words = { "the","quick","red","fox","jumps","over","the","slow","red","turtddle" };
//auto i = count_if(words.begin(), words.end(), [](string &s) {return s.size() > 6; });
//
//cout << i << endl;

//10.21
//[&s]() 
//{
//	for (s; s == 0; s--)
//	{
//		s;
//	}
//	return true;

//}

//10.24
//string s5 = "love";
//vector<int> vi= {45, 5, 8, 1, 2, 3, 5, 4, 6, 9, 4};
//string::size_type _length = s5.size();
//
// auto first=find_if(vi.begin(), vi.end(), bind(check_size, _1,_length));
//cout << *first << endl;
//
//
////10.27
//vector<string> words = { "the","quick","red","fox","jumps","over","the","slow","red","turtddle" };
//list<string> list1;
//elimDups(words);
//unique_copy(words.begin(), words.end(), back_inserter(list1));
//for (auto &s : list1)
//cout << s << endl;














//10.28
//vector<int> v = { 1,2,3,4,5,6,7,8,9 };
//vector<int> v1;
//vector<int> v2;
//list<int> v3;
//
//copy(v.begin(), v.end(), inserter(v1, v1.begin()));
//copy(v.begin(), v.end(), back_inserter(v2));
//copy(v.begin(), v.end(), front_inserter(v3));
//
//
//for (auto &s : v1)
//cout << s << endl;
//
//
//for (auto &d : v2)
//cout << d << endl;
//
//
//
//for (auto &f : v3)
//cout << f << endl;

//istream_iterator使用
//istream_iterator<int> in_iter(cin);
//istream_iterator<int> eof;
//vector<int> v1;
//while (in_iter != eof)
//{
//	v1.push_back(*in_iter);
//	in_iter++;
//}
//for (auto &s : v1)
//cout << s << endl;



//ostream_iterator使用
//ostream_iterator<int> os(cout, " ");
//vector<int> v1 = {1,2,3,4,5,6,7};
//for (auto &s : v1)
//	*os++ = s;  //直接os=s;是一样的，因为对os的这些运算符虽然存在但是没有任何作用，只是方便阅读
//cout << endl;



//10.29
//ifstream is("1.txt");
//istream_iterator<int> it(is), end;
//vector<int> v1;
//while (it != end)
//{
//	v1.push_back(*it++);
//}
//for (auto &s : v1)
//cout << s << endl;





//10.30
istream_iterator<string> is(cin),end;
vector<string> s1;
copy(is,end, back_inserter(s1));
sort(s1.begin(), s1.end());
for (auto &s : s1)
cout << s << endl;




















	system("pause");
	return 0;
}
































/*int main(int argc, char** argv)//实参列表
{
	string str;
	
	for (int i = 1; i != argc; ++i) {
		str += argv[i];
		str += " ";
	}

	cout << str << endl;
	system("pause");
	return 0;

}*/