#pragma once
#include <string>
#include <fstream>
#include "Keyboard.h"
#include "Printer.h"

using namespace std;

class Laptop {
	class CPU {
		string value;
	public:
		void get(string value) {
			this->value = value;
		}
		string send() {
			return value;
		}
	};

	class RAM {
		string memory;
	public:
		void save(string value) {
			memory = value;
		}
		string read() {
			return memory;
		}
	};

	class HHD {
		fstream memory;

	public:
		void save(string value) {
			memory.open("disk.txt", fstream::in);
			memory << value;
			memory.close();
		}
		string read() {
			memory.open("disk.txt",fstream::out);
			string value;
			memory >> value;
			memory.close();
			return value;
		}
	};

	class VideoCard {
		string name;
		int size;
		int ClockFrequency;
		int cores;
	public:
		VideoCard(string n, int s, int CF, int c) {
			name = n;
			size = s;
			CF = ClockFrequency;
			cores = c;
		}
	};

public:
	Printer printer;
	Keyboard keyboard;
	CPU cpu;
	RAM ram;
	HHD hhd;

	void write_down_and_print() {
		ram.save(keyboard.inpute());
		cpu.get(ram.read());
		hhd.save(cpu.send());
		ram.save(hhd.read());
		cpu.get(ram.read());
		printer.print(cpu.send());
	}
};