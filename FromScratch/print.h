#pragma once
#include<iostream>
#include<string>
#include<map>
#include <vector>
#include "StringFunctions.h"

using namespace std;
string replaceVariables(string line, map<string, int> Variables) {
	
	for ( auto i : Variables)
	{
		if (checkForString(line, i.first))
		{
			line = replace(i.first, line, to_string(i.second));
		}
	}

	return line;
}

void printThings(string line, map<string, int> Variables, int lineNumber) {
	if (checkForString(line, "print")) {

		line = replace("print", line, "");

		line = removeChar(line, ' ');

		line = replaceVariables(line, Variables);

		for (size_t i = 0; i < line.length(); i++)
		{
			if (isalpha(line[i])) throw runtime_error("An error occured: Undefined variable used in statement "+to_string(lineNumber));
		}

		cout << line << endl;
	}
}