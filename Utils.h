#pragma once
#include<string>
#include<vector>
#include <sstream>
using namespace std;

vector<string> tokenize(string line, char delimiter)
{
	string token;
	vector<string> tokens;
	stringstream ss(line);
	while (getline(ss, token, delimiter))
	{
		if (token.back() == ' ')
			token.pop_back();
		if (token.front() == ' ')
			token = token.substr(1);
		tokens.push_back(token);
	}
	return tokens;
}