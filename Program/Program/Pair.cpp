#pragma once
#include "Pair.h"

Pair::Pair() {
	first = 0;
	second = 0;
}
Pair::Pair(int f = 0, double s = 0) {
	this->first = f;
	this->second = s;
}
Pair::Pair(const Pair& p) {
	this->first = p.first;
	this->second = p.second;
}
Pair::~Pair() {
}
int Pair::GetFirst() { return this->first; }
void Pair::SetFirst(int x) { this->first = x; }
double Pair::GetSecond() { return this->second; }
void Pair::SetSecond(double y) { this->second = y; }
void Pair::Print() {
	cout << this->first << ":" << this->second << endl;
}

Pair Pair::operator+(const int& x) const {
	return Pair(this->first + x, this->second);
}
Pair Pair::operator+(const double& y) const {
	return Pair(this->first, this->second + y);
}
Pair Pair::operator-(const Pair& p) const {
	return Pair(this->first - p.first, this->second - p.second);
}

Pair operator+(const int& x, const Pair& p) {
	return p + x;
}
Pair operator+(const double& y, const Pair& p) {
	return p + y;
}
ostream& operator<<(ostream& str, const Pair& p) {
	str << " " << p.first << " : " << p.second << endl;
	return str;
}
istream& operator>> (istream& str, Pair& p) {
	cout << endl << "Enter pair values" << endl;
	cout << "First value: ";
	str >> p.first;
	cout << "Second value: ";
	str >> p.second;
	return str;
}

fstream& operator>> (fstream& fin, Pair& p) {
	fin >> p.first;
	fin >> p.second;
	return fin;
}
fstream& operator<< (fstream& fout, Pair& p) {
	fout << p.first << "\n" << p.second << "\n";
	return fout;
}