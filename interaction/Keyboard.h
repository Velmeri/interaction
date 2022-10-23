#pragma once
#include <iostream>
#include <istream>

using namespace std;

class Keyboard {
public:
	string inpute() {
		string value;
		cin >> value;
		return value;
	}
};

