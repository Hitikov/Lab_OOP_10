#pragma once
#include <iostream> 
#include <fstream>
using namespace std;

class Pair
{
private:
	int first;
	double second;
public:
	Pair();
	Pair(int f, double s);
	Pair(const Pair& p);
	~Pair();
	void SetFirst(int x);
	void SetSecond(double y);
	int GetFirst();
	double GetSecond();
	void Print();

	//������������� �������� 
	Pair operator+(const int& x) const;
	Pair operator+(const double& y) const;
	Pair operator-(const Pair& p) const;
	friend Pair operator+(const int& x, const Pair& p);
	friend Pair operator+(const double& y, const Pair& p);
	friend ostream& operator<<(ostream& str, const Pair& p);
	friend istream& operator>> (istream& str, Pair& p);


	friend fstream& operator>> (fstream& fin, Pair& p);
	friend fstream& operator<< (fstream& fout, Pair& p);
};