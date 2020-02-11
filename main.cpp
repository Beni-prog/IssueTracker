#include "IssueTracker.h"
#include "IssueRepository.h"
#include "Userwindow.h"
#include <QtWidgets/QApplication>

int main(int argc, char *argv[])
{
	QApplication a(argc, argv);
	IssueRepository repo("issues.txt", "users.txt");
	repo.testAll();
	vector<User> users1= repo.getUsers();
	for (auto el : users1)
	{
		Userwindow* gui = new Userwindow(repo, el.getType(), el.getName());
		gui->show();
	}
	return a.exec();
}
