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
//�ַ������Ƿ��д�д
bool daxie(const string &s)
{
	for (size_t i = 0; i < s.size(); i++)
	{
		if (s[i] >= 'A'&&s[i] <= 'Z')
			return true;
	}
	return false;
}
//��дȫ���Сд  ASCII��Ҳ����  Сд�ȴ�д��32
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
//����ָ��
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
//��׼io�� ��ϰ8.1
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
	cout << "û�ҵ�" << endl;
}

//9.28  ��Ϊend�޷����� ����������ǰָ��
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
//9.43   ���ܼ� ���Ǻ����ջ�
void st(string &s, string &oldVal, string &newVal)
{
	auto it1 = s.begin();
	auto it2 = newVal.begin();
	auto it3 = newVal.end();
	for (it1; it1 <= s.end() - oldVal.size() + 1; ++it1)//����it1�������ҵ���oldVal��size֮ǰ�������ȥsize��û�ҵ�˵��û��oldVal
	{
		if (s.substr(it1 - s.begin(), oldVal.size()) == oldVal)//substr ��һ�������ǵ��������ڶ�����oldVal��size�����ڵĻ�
		{
			it1=s.erase(it1, it1 + oldVal.size());
			s.insert(it1, it2,it3);

		}
	}
	

}
//�±�汾
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




//10.9  �����ظ�����
void elimDups(vector<string> &words)
{
	sort(words.begin(), words.end());
	auto end_unique=unique(words.begin(), words.end());
	words.erase(end_unique, words.end());

}




//10.11 ��дһ��isShorter
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




//lambda���ʽ
void biggies(vector<string> &words, vector<string>::size_type sz)
{
	elimDups(words);
	stable_sort(words.begin(), words.end(), isShorter);//Ҳ���԰�isShorter����lambda���ʽ  [](const string &a,const string &b){return a.size()<b.size();}
	auto wc = find_if(words.begin(), words.end(), [sz](const string &a) {return a.size() > sz; });
	auto count = words.end() - wc;//���ҵ��ĵ�һ������sz��Ԫ�ص����һ��Ԫ���ж��ٸ�
	for_each(wc, words.end(), [](const string &s) {cout << s << "" << endl; });
}


//10.18
void biggiest(vector<string> &words, vector<string>::size_type sz)
{
	elimDups(words);
	stable_sort(words.begin(), words.end(), isShorter);//Ҳ���԰�isShorter����lambda���ʽ  [](const string &a,const string &b){return a.size()<b.size();}
	auto wc = partition(words.begin(), words.end(), [sz](const string &a) {if (a.size() >= sz) return true; else return false; });
	//auto count = words.end() - wc;//���ҵ��ĵ�һ������sz��Ԫ�ص����һ��Ԫ���ж��ٸ�
	for_each(wc, words.end(), [](const string &s) {cout << s << "" << endl; });
}

//��ʮ�� Cheak_size
bool check_size(int &s, string::size_type sz)
{
	return s >= sz;
}