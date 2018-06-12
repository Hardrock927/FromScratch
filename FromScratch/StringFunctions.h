#pragma once
#include<iostream>
#include<string>
#include<map>
#include <vector>

using namespace std;
string removeChar(string sentence, char value) {
	string newSentence;

	for (size_t i = 0; i < sentence.length(); i++)
	{
		if (sentence[i] != value) newSentence += sentence[i];
	}

	return newSentence;
}

bool checkForString(string sentence, string val) {
	int flag = 1;

	for (size_t i = 0; i < sentence.length(); i++)
	{
		flag = 1;
		if (sentence[i] == val[0]) {
			for (size_t k = 0; k < val.length(); k++)
			{
				if (sentence[i + k] != val[k]) {
					flag = 0;
					break;
				}
			}
			if (flag == 1) return true;
		}
	}

	return false;
}

string replace(string val,string sentence, string replace) {
	int flag = 1; size_t i, k;
	
	for (i = 0; i < sentence.length(); i++)
	{
		flag = 1;
		if (sentence[i] == val[0]) {
			for (k = 0; k < val.length(); k++)
			{
				if (sentence[i + k] != val[k]) {
					flag = 0;
					break;
				}
			}
			if (flag == 1) {
				sentence.replace(i, val.length(), replace);
				return sentence;
			}
		}
	}

		return "fail";
}

vector<string> splitWithAChar(string sentence, char val) {
	vector<string> List;
	int temp = 0;
	for (size_t i = 0; i < sentence.length(); i++)
	{
		if (sentence[i] == val) {
			string make(sentence.begin() + temp, sentence.begin() + i);
			List.push_back(make);
			temp = i+1;
		}
		else if (i == (sentence.length() - 1)) {
			string make(sentence.begin() + temp, sentence.begin() + i+1);
			List.push_back(make);
		}
	}
	return List;
}

bool checkForMapObject(map<char, int> operations, string look) {
	for (map<char, int>::iterator it = operations.begin(); it != operations.end(); it++)
	{
		for (size_t i = 0; i < look.length(); i++)
		{
			if (it->first == look[i]) return true;
		}
	}

	return true;
}