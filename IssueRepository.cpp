#include "IssueRepository.h"
#include <fstream>
#include "Utils.h"
#include <algorithm>
#include "IssueException.h"

void IssueRepository::readFromFile()
{
	ifstream ifs1(this->usersFileName, ifstream::in);
	ifstream ifs2(this->issuesFileName, ifstream::in);
	string line;
	vector<string> tokens1;
	vector<string> tokens2;
	while (getline(ifs1, line))
	{
		tokens1= tokenize(line, '|');
		this->users.push_back(User(tokens1[0], tokens1[1]));
	}
	while (getline(ifs2, line))
	{
		tokens2= tokenize(line, '|');
		this->issues.push_back(Issue(tokens2[0],tokens2[1],tokens2[2],tokens2[3]));
	}
}

IssueRepository::IssueRepository(string issuesFileName, string _usersFileName): issuesFileName(issuesFileName), usersFileName(_usersFileName)
{
	this->readFromFile();
}

void IssueRepository::saveToFile(string fileName)
{
	ofstream ofs(fileName, ofstream::trunc);
	vector<Issue> open;
	vector<Issue> closed;
	copy_if(issues.begin(), issues.end(), back_inserter(open), [](Issue i) {
		return i.getStatus() == "open"; });
	copy_if(issues.begin(), issues.end(), back_inserter(closed), [](Issue i) {
		return i.getStatus() == "closed"; });
	sort(open.begin(), open.end(), [](Issue i1, Issue i2) {
		if (i1.getDescription() > i2.getDescription()) return false;
		if (i1.getDescription() < i2.getDescription()) return true;
	});
	for (auto el : open)
	{
		ofs << el.getDescription() << "|" << el.getStatus() << "|" << el.getReporter() << "|" << el.getSolver() << endl;
	}
	sort(closed.begin(), closed.end(), [](Issue i1, Issue i2) {
		if (i1.getDescription() > i2.getDescription()) return false;
		if (i1.getDescription() < i2.getDescription()) return true;
	});
	for (auto el : closed)
	{
		ofs << el.getDescription() << "|" << el.getStatus() << "|" << el.getReporter() << "|" << el.getSolver() << endl;
	}
}
IssueRepository::~IssueRepository() { this->saveToFile("issues.txt"); }
void IssueRepository::addIssue(Issue i)
{
	if (i.getDescription() == "")
		throw IssueException("The description can not be empty!");
	for (auto el : this->issues)
		if (el.getDescription() == i.getDescription())
			throw IssueException("This issue already exists!");
	issues.push_back(i);
	this->notify();
}

void IssueRepository::removeIssue(string description)
{
	issues.erase(remove_if(issues.begin(), issues.end(), [description](Issue i) {
		if (i.getStatus() == "open")throw IssueException("The status must be closed!");
		return (i.getDescription() == description &&i.getStatus()=="closed");
	}));
	this->notify();
}

void IssueRepository::updateIssue(string description, string solver)
{
	auto issue = find_if(issues.begin(), issues.end(), [description](Issue i) {
		return description == i.getDescription();
	});
	issue->changeSolver(solver);
	issue->changeStatus();
	this->notify();
}

void IssueRepository::testAll()
{
	/*IssueRepository repo("issues.txt", "users.txt");
	vector<Issue> repos = repo.getIssues();
	assert(repos[repos.size() - 1].getDescription() == "desc4");

	repo.addIssue(Issue("descr", "open", "any tester", "any programmer"));
	repos = repo.getIssues();
	assert(repos[repos.size() - 5].getDescription() == "desc");

	repo.removeIssue("desc4");
	repos = repo.getIssues();
	assert(repos[repos.size() - 1].getDescription() == "desc1");

	repo.updateIssue("desc4", "me");
	repos = repo.getIssues();
	assert(repos[repos.size() - 3].getStatus() == "closed");
	assert(repos[repos.size() - 3].getSolver() == "me");*/
}
