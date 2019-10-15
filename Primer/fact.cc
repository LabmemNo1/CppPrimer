#include<iostream>
#include<vector>
#include<string>
#include<forward_list>
#include<algorithm>


using namespace std;

int fact(int val)
{
	int ret = 1;
	while (val > 1)
		ret *= val--;
	return ret;


}
int jueduizhi(int a)
{
	a = abs(a);
	return a;
}
size_t count_calls()
{
	static size_t ctr = 0;
	return ++ctr;
}
int change(int *p,int *q)
{
	int a = *p;
	*p = *q;
	*q = a;
	return 0;
}
int exchange(int &a, int &b)
{
	int q = a;
	a = b;
	b = q;
	return 0;
}
string::size_type find_char(const string &s, char c, string::size_type &occurs)
{
	auto ret = s.size();
	occurs = 0;
	for(decltype(ret)i = 0; i < s.size(); i++)
	{
		if (s[i] == c)
		{
			if (ret == s.size())
				ret = i;
			++occurs;

		}
	}
	return ret;
}
//字符串里是否有大写
bool daxie(const string &s)
{
	for (size_t i = 0; i < s.size(); i++)
	{
		if (s[i] >= 'A'&&s[i] <= 'Z')
			return true;
	}
	return false;
}
//大写全变成小写  ASCII码也可以  小写比大写大32
string daxiao(string &s)
{
	for (size_t i = 0; i < s.size(); i++)
	{
		if (s[i] >= 'A'&&s[i] <= 'Z')
			;
		else
			s[i] = toupper(s[i]);
	}
	return s;
}
//交换指针
int changezhen(int* &p, int* &q)
{
	int *s = NULL;
	s = p;
	p = q;
	q = s;
	return 0;
}
//primer6.27
int sum(initializer_list<int> a)
{
	int sum = 0;
	for (auto s=a.begin();s!=a.end();s++)
	{
		sum += *s;
		++s;

	}
	return sum;
}
//primer6.33
void get_val(vector<int>a, int x)
{
	if (x == 0) 
	{
		cout << a[x] << endl;
		--x;
		get_val(a, x);
		cout << a.size() << endl;
	}
}
int jiecheng(int n)
{
	if (n > 1)
		return jiecheng(n - 1)*n;
	return 1;
}
//6.55
int ssum(int a, int b)
{
	return a+b;
}
int jian(int a, int b)
{
	return a - b;
}
int cheng(int a,int b)
{
	return a * b;
}
int chu(int a,int b)
{
	return a / b;
}
//标准io库 练习8.1
istream& isa(istream &is)
{
	string s;
	while (is >> s)
		cout << s << endl;
	is.clear();
	return is;

}
//9.4
bool jiudiansi(vector<int>::iterator &b, vector<int>::iterator &e,const int &a)
{
	while (b != e)
	{
		if (*b = a)
			return true;
		else 
			++b;

	}
	return false;
}
//9.5
vector<int>::iterator jiudianyiwu(vector<int>::iterator &b, vector<int>::iterator &e, const int &a)
{
	while (b != e)
	{
		if (*b = a)
			return b;
		else
			++b;

	}
	cout << "没找到" << endl;
}

//9.28  因为end无法计算 所以利用首前指针
void forwards(forward_list<string> &a, string &s1, string &s2)
{
	bool flag = false;
	auto bit = a.before_begin();
	for (auto it = a.begin(); it != a.end(); bit=it++)
	{
		if (*it == s1)
		{
			a.insert_after(it, s2);
			flag = true;
		}
		
	}
	if (!flag)
		a.insert_after(bit, s1);
}
//9.43   理解很简单 但是很有收获
void st(string &s, string &oldVal, string &newVal)
{
	auto it1 = s.begin();
	auto it2 = newVal.begin();
	auto it3 = newVal.end();
	for (it1; it1 <= s.end() - oldVal.size() + 1; ++it1)//这里it1迭代器找的是oldVal的size之前，如果减去size还没找到说明没有oldVal
	{
		if (s.substr(it1 - s.begin(), oldVal.size()) == oldVal)//substr 第一个参数是迭代器，第二个是oldVal的size，等于的话
		{
			it1=s.erase(it1, it1 + oldVal.size());
			s.insert(it1, it2,it3);

		}
	}
	

}
//下标版本
void stx(string &s, string &oldVal, string &newVal)
{
	for (int i = 0; i < oldVal.size(); i++)
	{
		if (s.substr(i, oldVal.size()) == oldVal)
		{
			s.replace(i, oldVal.size(), newVal);
		}
	}
}
//9.45
string na(string &name, string &front, string &after)
{
	auto it1 = name.begin();
	name.insert(it1, front.begin(),front.end());
	name.append(after);
	return name;
}




//10.9  消除重复单词
void elimDups(vector<string> &words)
{
	sort(words.begin(), words.end());
	auto end_unique=unique(words.begin(), words.end());
	words.erase(end_unique, words.end());

}




//10.11 先写一个isShorter
bool isShorter(const string &s1, const string &s2)
{
	return s1.size() <s2.size();
 }

//10.13
bool boom(string &s1)
{
	if (s1.size() >= 5)
		return true;
	else
		return false;
}




//lambda表达式
void biggies(vector<string> &words, vector<string>::size_type sz)
{
	elimDups(words);
	stable_sort(words.begin(), words.end(), isShorter);//也可以把isShorter换成lambda表达式  [](const string &a,const string &b){return a.size()<b.size();}
	auto wc = find_if(words.begin(), words.end(), [sz](const string &a) {return a.size() > sz; });
	auto count = words.end() - wc;//从找到的第一个大于sz的元素到最后一个元素有多少个
	for_each(wc, words.end(), [](const string &s) {cout << s << "" << endl; });
}


//10.18
void biggiest(vector<string> &words, vector<string>::size_type sz)
{
	elimDups(words);
	stable_sort(words.begin(), words.end(), isShorter);//也可以把isShorter换成lambda表达式  [](const string &a,const string &b){return a.size()<b.size();}
	auto wc = partition(words.begin(), words.end(), [sz](const string &a) {if (a.size() >= sz) return true; else return false; });
	//auto count = words.end() - wc;//从找到的第一个大于sz的元素到最后一个元素有多少个
	for_each(wc, words.end(), [](const string &s) {cout << s << "" << endl; });
}

//第十节 Cheak_size
bool check_size(int &s, string::size_type sz)
{
	return s >= sz;
}