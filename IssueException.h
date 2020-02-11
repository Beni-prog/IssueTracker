#pragma once
#include "Issue.h"

using namespace std;
class IssueException
{
private:
	string error;
public:
	IssueException(string error):error(error){}
	string what() { return error; }
};