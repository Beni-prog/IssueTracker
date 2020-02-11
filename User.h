#pragma once
#include <string>
using namespace std;
class User
{
private:
	string name;
	string type;
public:
	User(string name, string type) :name(name), type(type){}
	~User();
	string getName() { return name; }
	string getType() { return type; }

};

