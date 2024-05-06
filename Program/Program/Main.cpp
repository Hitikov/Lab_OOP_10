#include <iostream>
#include <fstream>
#include "Pair.h"
#include "file_work.h"


int main() {
	Pair p, p1;
	int k, c, pos;
	double l, value;
	char file_name[30];
	do
	{
		cout << endl << "1. Change work file name";
		cout << endl << "2. Make file";
		cout << endl << "3. Print file";
		cout << endl << "4. Delete record from file";
		cout << endl << "5. Add record to file";
		cout << endl << "6. Change records in file";
		cout << endl << "0. Exit" << endl;

		cin >> c;
		switch (c)
		{
		case 1:
			cout << "Enter file name: ";
			cin >> file_name;
			break;

		case 2:
			k = make_file(file_name);
			if (k < 0) cout << "Error in file creation" << endl;
			break;
		case 3:
			k = print_file(file_name);
			if (k == 0) cout << "File is empty" << endl;
			if (k < 0) cout << "Error in file reading" << endl;
			break;
		case 4:
			cout << "Enter target value: ";
			cin >> value;
			k = del_file(file_name, value);
			if (k < 0) cout << "Error in file reading" << endl;
			break;
		case 5:
			cout << "Enter adding position: ";
			cin >> pos;
			cout << "Enter adding pair: ";
			cin >> p1;
			k = add_file(file_name, pos, p1);
			if (k < 0) cout << "Error in file reading" << endl;
			break;
		case 6:
			cout << "Enter target value: ";
			cin >> value;
			cout << "Enter adding value: ";
			cin >> l;
			k = change_file(file_name, value, l);
			if (k == 0) cout << "No record changed" << endl;
			if (k < 0) cout << "Error in file reading" << endl;
			break;
		default:
			break;
		}
	} while (c != 0);

	return 0;
}