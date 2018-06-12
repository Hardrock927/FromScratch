#include<iostream>
#include<string>
#include<map>
#include <vector>
#include "StringFunctions.h"
#include "svar.h"
#include "print.h"
#include "evalLines.h"
using namespace std;

int main() {
	try {
		string line;
		getline(cin, line);
		
		line = removeChar(line, ';');

		map<string, int> Variables = svarThings(line,1);

		for (auto &i : Variables)
		{
			i.second = 1;
		}
		getline(cin, line);
		printThings(line, Variables, 1);

		system("PAUSE");
	}
	catch (runtime_error & ex) {
		cout << ex.what() << endl;
		system("PAUSE");
	}
}