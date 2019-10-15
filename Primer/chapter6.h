#pragma once
#ifndef CHAPTER_H
#define CHAPTER_H
#include<iostream>
#include<vector>
#include<string>

using namespace std;
int fact(int val);
int jueduizhi(int a);
size_t count_calls();
int change(int *p, int *q);
int exchange(int &a, int &b);
string::size_type find_char(const string &s, char c, string::size_type &occurs);
bool daxie(const string &s);
string daxiao(string &s);
int changezhen(int* &p, int* &q); 
int sum(initializer_list<int> a);
void get_val(vector<int>a, int x);
int jiecheng(int n);
//Êý×éÉùÃ÷
int((*function(int i))[5]);
auto fuunction(int i)->int(*)[10];
int hanshu(int a, int b);
int ssum(int a, int b);
int jian(int a, int b);
int cheng(int a, int b);
int chu(int a, int b);
istream& isa(istream &is);
void st(string &s, string &oldVal, string &newVal);
void stx(string &s, string &oldVal, string &newVal);
void elimDups(vector<string> &words);
bool isShorter(const string &s1, const string &s2);
bool boom(string &s1);
void biggies(vector<string> &words, vector<string>::size_type sz);
void biggiest(vector<string> &words, vector<string>::size_type sz);
bool check_size(int &s, string::size_type sz);

#endif