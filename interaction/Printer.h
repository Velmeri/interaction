#pragma once
#include <string>
#include <ostream>

using namespace std;

class Printer {
	string name;
public:
	void print(string value) {
		cout << value;
	}
};