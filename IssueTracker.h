#pragma once

#include <QtWidgets/QMainWindow>
#include "ui_IssueTracker.h"

class IssueTracker : public QMainWindow
{
	Q_OBJECT

public:
	IssueTracker(QWidget *parent = Q_NULLPTR);

private:
	Ui::IssueTrackerClass ui;
};
