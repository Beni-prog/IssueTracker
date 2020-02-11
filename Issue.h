#pragma once
#include <string>
using namespace std;
class Issue
{
private:
	string description;
	string status;
	string reporter;
	string solver;
public:
	Issue(string description, string status, string reporter, string solver):description(description), status(status), reporter(reporter), solver(solver){}
	~Issue();
	string toString() { return description + "|" + status + "|" + reporter + "|" + solver; }
	string getDescription() { return description; }
	string getStatus() { return status; }
	string getReporter() { return reporter; }
	string getSolver() { return solver; }
	void changeSolver(string solver) { this->solver = solver; }
	void changeStatus() { this->status = "closed"; }

};

