#pragma once
#include "Issue.h"
#include"User.h"
#include <vector>
#include<assert.h>
#include "Observer.h"
class IssueRepository :
	public Subject
{
private:
	vector<Issue> issues;
	vector<User> users;
	string issuesFileName;
	string usersFileName;
public:
	IssueRepository(string issuesFileName, string usersFileNmae);
	~IssueRepository();
	void readFromFile();
	void saveToFile(string fileName);
	vector<Issue> getIssues() { return this->issues; }
	vector<User> getUsers() { return this->users; }
	/*
	DESCR: adds a new issue
	IN:an issue i
	OUT:-
	THROWS:an exception if the issue already exists or its description is empty
	*/
	void addIssue(Issue i);

	/*
	DESCR:removes an issue
	IN: the description of an issue
	OUT:-
	THROWS: an error if the status of the issue is not closed
	*/
	void removeIssue(string description);

	/*
	DESCR: updates an issue's status and programmer
	IN:the description and the solver of the issue
	OUT:-
	THROWS:-
	*/
	void updateIssue(string description, string solver);

	void testAll();
};

