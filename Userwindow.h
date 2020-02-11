#pragma once
#include "IssueRepository.h"
#include <QWidget>
#include "ui_Userwindow.h"
using namespace std;

class Userwindow : public QWidget, public Observer
{
	Q_OBJECT
private:
	IssueRepository& repo;
	string name;
	string desc; 
	vector<Issue> issuesList;

public:
	Userwindow(IssueRepository&repo, string desc,  string name, QWidget* parent = Q_NULLPTR);
	~Userwindow()override;
	void update() override;

private:
	Ui::Userwindow ui;

	void populateList();
	void sortList();
	void addIssueGUI();
	void removeIssueGUI();
	void updateIssueGUI();
	void connectSignalsAndSlots();

};
