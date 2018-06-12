#pragma once
#include<iostream>
#include<string>
#include<map>
#include <vector>
#include "StringFunctions.h"

using namespace std;
int eval(string line) {
	map<char, int> operations;

	for (size_t i = 0; i < line.length(); i++)
	{
		if (line[i] == '+' || line[i] == '-' || line[i] == '*' || line[i] == '/' || line[i] == '%') {
			operations[line[i]] = i;
		}
	}

	while (checkForMapObject(operations,"*/%")) {
		map<char, int>::iterator it = operations.begin();
		switch (it->first)
		{
		case '*':
			map<char, int>::iterator left = --it, right;
			string first(line.begin() + (it-1)->second, line.end());
			break;
		}
	}
}