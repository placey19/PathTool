#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QtGui/QMainWindow>

namespace Ui
{
	class MainWindow;
}

class MainWindow : public QMainWindow
{
	Q_OBJECT

public:
	MainWindow(QWidget *parent = 0);
	~MainWindow();

private slots:
	void on_actionCopyPath_triggered();
	void on_actionRefresh_triggered();
	void on_actionSave_triggered();
	void on_actionSort_triggered();

private:
	Ui::MainWindow* ui;
	QString iPath;
};

#endif	//MAINWINDOW_H
