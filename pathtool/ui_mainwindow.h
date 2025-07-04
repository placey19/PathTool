/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 4.8.7
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QHBoxLayout>
#include <QtGui/QHeaderView>
#include <QtGui/QMainWindow>
#include <QtGui/QMenu>
#include <QtGui/QMenuBar>
#include <QtGui/QStatusBar>
#include <QtGui/QTextEdit>
#include <QtGui/QToolBar>
#include <QtGui/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QAction *actionSave;
    QAction *actionRefresh;
    QAction *actionExit;
    QAction *actionSort;
    QAction *actionCopyPath;
    QWidget *centralWidget;
    QHBoxLayout *horizontalLayout;
    QTextEdit *textEdit;
    QMenuBar *menuBar;
    QMenu *menu_File;
    QToolBar *mainToolBar;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QString::fromUtf8("MainWindow"));
        MainWindow->resize(600, 400);
        actionSave = new QAction(MainWindow);
        actionSave->setObjectName(QString::fromUtf8("actionSave"));
        QIcon icon;
        icon.addFile(QString::fromUtf8(":/icons/save-icon-32x32.png"), QSize(), QIcon::Normal, QIcon::Off);
        actionSave->setIcon(icon);
        actionRefresh = new QAction(MainWindow);
        actionRefresh->setObjectName(QString::fromUtf8("actionRefresh"));
        QIcon icon1;
        icon1.addFile(QString::fromUtf8(":/icons/refresh-icon-32x32.png"), QSize(), QIcon::Normal, QIcon::Off);
        actionRefresh->setIcon(icon1);
        actionExit = new QAction(MainWindow);
        actionExit->setObjectName(QString::fromUtf8("actionExit"));
        actionSort = new QAction(MainWindow);
        actionSort->setObjectName(QString::fromUtf8("actionSort"));
        QIcon icon2;
        icon2.addFile(QString::fromUtf8(":/icons/sort-az-icon-32x32.png"), QSize(), QIcon::Normal, QIcon::Off);
        actionSort->setIcon(icon2);
        actionCopyPath = new QAction(MainWindow);
        actionCopyPath->setObjectName(QString::fromUtf8("actionCopyPath"));
        QIcon icon3;
        icon3.addFile(QString::fromUtf8(":/icons/clipboard-icon-32x32.png"), QSize(), QIcon::Normal, QIcon::Off);
        actionCopyPath->setIcon(icon3);
        centralWidget = new QWidget(MainWindow);
        centralWidget->setObjectName(QString::fromUtf8("centralWidget"));
        horizontalLayout = new QHBoxLayout(centralWidget);
        horizontalLayout->setSpacing(6);
        horizontalLayout->setContentsMargins(11, 11, 11, 11);
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        textEdit = new QTextEdit(centralWidget);
        textEdit->setObjectName(QString::fromUtf8("textEdit"));

        horizontalLayout->addWidget(textEdit);

        MainWindow->setCentralWidget(centralWidget);
        menuBar = new QMenuBar(MainWindow);
        menuBar->setObjectName(QString::fromUtf8("menuBar"));
        menuBar->setGeometry(QRect(0, 0, 600, 21));
        menu_File = new QMenu(menuBar);
        menu_File->setObjectName(QString::fromUtf8("menu_File"));
        MainWindow->setMenuBar(menuBar);
        mainToolBar = new QToolBar(MainWindow);
        mainToolBar->setObjectName(QString::fromUtf8("mainToolBar"));
        mainToolBar->setFloatable(false);
        MainWindow->addToolBar(Qt::TopToolBarArea, mainToolBar);
        statusBar = new QStatusBar(MainWindow);
        statusBar->setObjectName(QString::fromUtf8("statusBar"));
        MainWindow->setStatusBar(statusBar);

        menuBar->addAction(menu_File->menuAction());
        menu_File->addAction(actionRefresh);
        menu_File->addAction(actionSave);
        menu_File->addAction(actionSort);
        menu_File->addAction(actionCopyPath);
        menu_File->addSeparator();
        menu_File->addAction(actionExit);
        mainToolBar->addAction(actionRefresh);
        mainToolBar->addAction(actionSave);
        mainToolBar->addAction(actionSort);
        mainToolBar->addAction(actionCopyPath);

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QApplication::translate("MainWindow", "Path Tool", 0, QApplication::UnicodeUTF8));
        actionSave->setText(QApplication::translate("MainWindow", "&Save", 0, QApplication::UnicodeUTF8));
        actionRefresh->setText(QApplication::translate("MainWindow", "&Refresh", 0, QApplication::UnicodeUTF8));
        actionExit->setText(QApplication::translate("MainWindow", "E&xit", 0, QApplication::UnicodeUTF8));
        actionSort->setText(QApplication::translate("MainWindow", "&Sort A-Z", 0, QApplication::UnicodeUTF8));
#ifndef QT_NO_TOOLTIP
        actionSort->setToolTip(QApplication::translate("MainWindow", "Sort A-Z", 0, QApplication::UnicodeUTF8));
#endif // QT_NO_TOOLTIP
        actionCopyPath->setText(QApplication::translate("MainWindow", "&Copy Path", 0, QApplication::UnicodeUTF8));
#ifndef QT_NO_TOOLTIP
        actionCopyPath->setToolTip(QApplication::translate("MainWindow", "Copy path to clipboard", 0, QApplication::UnicodeUTF8));
#endif // QT_NO_TOOLTIP
        menu_File->setTitle(QApplication::translate("MainWindow", "&File", 0, QApplication::UnicodeUTF8));
        mainToolBar->setWindowTitle(QApplication::translate("MainWindow", "Toolbar", 0, QApplication::UnicodeUTF8));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
