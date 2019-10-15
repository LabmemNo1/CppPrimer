#ifndef SCREEN_H
#define SCREEN_H
#include<iostream>
#include<string>
#include<vector>




class Screen;
class Window_mgr
{
public:
	using ScreenIndex = std::vector<Screen>::size_type;
	void clean(ScreenIndex &i);
















private:
	std::vector<Screen> screens;

};








class Screen
{
	friend void Window_mgr::clean(ScreenIndex &);
	
	
public:
	
	typedef std::string::size_type pos;
	//构造函数
	Screen() = default;
	Screen(pos ht,pos wd,char c):height(ht),width(wd),contents(ht*wd,c){}//屏幕的高宽和内容
	char get() const //读取光标处字符
	{
		return contents[cursor];//隐式内联
	}
	//声明  显式内联
	inline char get(pos ht, pos wd) const;
	Screen &move(pos r, pos c);
	Screen &set(char);//设置光标所在未知的字符内容
	Screen &set(pos, pos, char);//设置指定位置的字符内容
	//定义display的常量  非常量版本
	Screen &display(std::ostream &os) { do_display(os); return *this; }
	const Screen &display (std::ostream &os) const { do_display(os); return *this; }
private:
	
	pos cursor = 0;
	pos height = 0, width = 0;
	std::string contents;
	void do_display(std::ostream &os) const { os << contents; }
	pos size() const
	{

	}






};

//定义
//得到指定位置的内容
inline char Screen::get(pos r, pos c) const
{
	pos row = r * width;//计算行的位置
	return contents[row+c]; //返回给定列的字符
}
//光标移动
inline Screen &Screen::move(pos r, pos c)
{
	pos row = r * width;
	cursor = row + c;//在行内将光标移动到指定的列
	return *this;
}
//设定光标所在位置的内容
inline Screen &Screen::set(char c)
{
	contents[cursor] = c;
	return *this;
}
inline Screen &Screen::set(pos r, pos c, char ch)
{
	pos row = r * width;
	contents[row + c] = ch;
	return *this;
}

//Window的清空
void Window_mgr::clean(ScreenIndex &i)
{
	Screen &s = screens[i];
	s.contents = string(s.height*s.width, ' ');
}


























#endif // !SCREEN_H
