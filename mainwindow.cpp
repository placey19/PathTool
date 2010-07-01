#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "windowsregistry.h"
#include <QMessageBox>
#include <QClipboard>

MainWindow::MainWindow(QWidget *parent)
	: QMainWindow(parent), ui(new Ui::MainWindow)
{
	ui->setupUi(this);

	//setup the Exit slot
	connect(ui->actionExit, SIGNAL(triggered()), this, SLOT(close()));

	//refresh the list
	on_actionRefresh_triggered();
}

MainWindow::~MainWindow()
{
	delete ui;
}

void MainWindow::on_actionRefresh_triggered()
{
	const char* path = WindowsRegistry::GetPathEnvironmentVariable();

	if (path)
	{
		//copy the path to a local QString and cleanup the data
		iPath = path;
		delete [] path;

		//add all paths to the list
		ui->textEdit->setText(iPath.replace(";", "\n"));
	}
	else
	{
		//display error message
		(void)QMessageBox::critical(NULL, windowTitle(), "Failed to retrieve path environment variable from registry");
	}
}

void MainWindow::on_actionSave_triggered()
{
	//update path from text
	iPath = ui->textEdit->toPlainText().replace("\n", ";");

	//set the path environment variable in the registry, show error if it failed
	if (!WindowsRegistry::SetPathEnvironmentVariable(iPath.toStdString().c_str()))
	{
		(void)QMessageBox::critical(NULL, windowTitle(), "Failed to set registry key value");
	}
}

void MainWindow::on_actionSort_triggered()
{
	//put path from text into list
	QStringList list(ui->textEdit->toPlainText().split('\n', QString::SkipEmptyParts));

	//sort the list and set the text to the newly ordered list
	list.sort();
	ui->textEdit->setText(list.join("\n"));
}

void MainWindow::on_actionCopyPath_triggered()
{
	//update path from text
	iPath = ui->textEdit->toPlainText().replace("\n", ";");

	QApplication::clipboard()->setText(iPath);
}
