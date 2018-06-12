#pragma once
#include<iostream>
#include<string>
#include<map>
#include <vector>
#include "StringFunctions.h"

using namespace std;
bool IsVariable(string line) {
	for (size_t i = 0; i < line.length(); i++)
	{
		if (isalpha(line[i])) {
			for (size_t k = i + 1; k < line.length(); k++)
			{
				if (line[k] == ' ') return true;
			}
		}
	}
	return false;
}

map<string,int> svarThings(string line, int lineNumber) {
	map<string, int> Variables;
	if (checkForString(line, "svar")) {
		//svar ý kaldýr
		line = replace("svar", line, "");
		
		//Öncelikle deðiþken boþluklarýna bak
		vector<string> variableNames = splitWithAChar(line, ',');
		
		for (size_t i = 0; i < splitWithAChar(line, ',').size(); i++)
		{
			if (IsVariable(splitWithAChar(line, ',')[i])) throw runtime_error("An error occured: Invalid variable definition in statement " + to_string(lineNumber) + "! Please be sure to make variable names sticky.");
		}

		//deðiþken arasýndaki boþluklarý kaldýr
		line = removeChar(line, ' ');

		//deðiþkenleri al
		variableNames = splitWithAChar(line, ',');

		for (size_t i = 0; i < variableNames.size(); i++)
		{
			Variables[variableNames[i]] = NULL;
		}

		return Variables;
	}
	Variables["NULL"] = NULL;

	return Variables;
}