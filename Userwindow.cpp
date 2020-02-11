#include "Userwindow.h"
#include "IssueException.h"
#include "qmessagebox.h"
vector<string> tokenize(string line, char delimiter);

Userwindow::Userwindow(IssueRepository& repo, string desc, string name, QWidget* parent):repo(repo),  desc(desc),name(name), QWidget(parent)
{
	ui.setupUi(this);
	this->setWindowTitle(QString::fromStdString(this->name + " " + this->desc));
	
	this->repo.addObs(this);
	if (this->desc == "tester")
		this->ui.solvePushButton->hide();
	if (this->desc == "programmer")
		this->ui.addPushButton->hide();
	this->connectSignalsAndSlots();
    this->update();
}

Userwindow::~Userwindow(){}


void Userwindow::populateList()
{
	ui.issueListWidget->clear();
	for (auto el : issuesList)
	{
		QListWidgetItem* item = new QListWidgetItem;
		item->setText(QString::fromStdString(el.toString()));
		ui.issueListWidget->addItem(item);
	}
}

void Userwindow::sortList()
{
	sort(this->issuesList.begin(), this->issuesList.end(), [](Issue i1, Issue i2) {
		if (i1.getStatus() > i2.getStatus()) return false;
		if (i1.getStatus() < i2.getStatus()) return true;
		if (i1.getDescription() > i2.getDescription())return false;
		if (i1.getDescription() < i2.getDescription())return true;
		return false;
	});
}

void Userwindow::addIssueGUI()
{
	string descr = ui.lineEdit->text().toStdString();
	string reporter = this->name;
	string status = "open";
	try
	{
		this->repo.addIssue(Issue(descr, status, reporter, "programmer"));
		this->update();
	}
	catch (IssueException e)
	{
		QMessageBox box;
		box.critical(0, "Error", QString::fromStdString(e.what()));
	}
}

void Userwindow::removeIssueGUI()
{
	vector<string> token = tokenize(ui.issueListWidget->currentItem()->text().toStdString(),'|');
	try {
		this->repo.removeIssue(token[0]);
		this->update();
	}
	catch (IssueException e)
	{
		QMessageBox box;
		box.critical(0, "Error", QString::fromStdString(e.what()));
	}
}

void Userwindow::updateIssueGUI()
{
	vector<string> token = tokenize(ui.issueListWidget->currentItem()->text().toStdString(), '|');
	this->repo.updateIssue(token[0], this->name);
	this->update();
}

void Userwindow::connectSignalsAndSlots()
{
	connect(ui.addPushButton, &QPushButton::clicked, this, &Userwindow::addIssueGUI);
	connect(ui.removePushButton, &QPushButton::clicked, this, &Userwindow::removeIssueGUI);
	connect(ui.solvePushButton, &QPushButton::clicked, this, &Userwindow::updateIssueGUI);
}

void Userwindow::update()
{
	this->issuesList = this->repo.getIssues();
	this->sortList();
	this->populateList();

}


