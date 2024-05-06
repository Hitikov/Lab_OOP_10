#pragma once
#include <iostream>
#include <fstream>
#include <string>
#include "Pair.h"

using namespace std;

int make_file(const char* f_name)
{
	fstream stream(f_name, ios::out | ios::trunc);
	if (!stream) return -1;
	int n;
	Pair p;
	cout << "Number of pairs: ";
	cin >> n;
	for (int i = 0; i < n; i++)
	{
		cin >> p;
		stream << p << '\n';
	}
	stream.close();
	return n;
}

int print_file(const char* f_name)
{
	fstream stream(f_name, ios::in);
	if (!stream) return -1;
	Pair p;
	int i = 0;
	while (stream >> p)
	{
		cout << p << endl;
		i++;
	}
	stream.close();
	return i;
}

int del_file(const char* f_name, double k)
{
	fstream temp("temp", ios::out);
	fstream stream(f_name, ios::in);
	if (!stream) return -1;
	Pair p;
	int i = 0;

	while (stream >> p)
	{
		if (!stream.eof()) {
			i++;
			if (p.GetFirst() + p.GetSecond() >= k) {
				temp << p;
			}
		}
	}

	stream.close();
	temp.close();
	remove(f_name);
	rename("temp", f_name);
	
	return i;
}

int add_file(const char* f_name, int k, Pair adp)
{
	fstream temp("temp", ios::out);
	fstream stream(f_name, ios::in);
	if (!stream) return -1;
	Pair p;
	int i = 0, j = 0;
	if (k == 0)
	{
		temp << adp;
		j++;
	}
	while (stream >> p) 
	{
		if (!stream.eof()) {
			i++;
			temp << p;
			if (i == k)
			{
				temp << adp;
				j++;
			}
		}
	}

	stream.close();
	temp.close();
	remove(f_name);
	rename("temp", f_name);

	return j;
}

int add_end(const char* f_name, Pair adp)
{
	fstream stream(f_name, ios::app);
	if (!stream) return -1;
	stream << adp;
	return 1;
}

template <typename TT>
int change_file(const char* f_name, double k, TT l)
{
	fstream temp("temp", ios::out);
	fstream stream(f_name, ios::in);
	if (!stream) return -1;
	Pair p;
	int i = 0;

	while (stream >> p)
	{
		if (!stream.eof()) {
			if (p.GetFirst() + p.GetSecond() == k) {
				p = p + l;
				i++;
			}
			temp << p;
		}
	}

	stream.close();
	temp.close();
	remove(f_name);
	rename("temp", f_name);

	return i;
}