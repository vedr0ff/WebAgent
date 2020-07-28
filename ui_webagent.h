/********************************************************************************
** Form generated from reading UI file 'webagent.ui'
**
** Created by: Qt User Interface Compiler version 5.14.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_WEBAGENT_H
#define UI_WEBAGENT_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>
#include "qwebengineview.h"

QT_BEGIN_NAMESPACE

class Ui_WebAgent
{
public:
    QWidget *centralwidget;
    QVBoxLayout *verticalLayout;
    QLineEdit *lineEdit;
    QWebEngineView *preview;
    QPushButton *pushButtonNetworkOn;
    QPushButton *pushButtonNetworkOff;
    QPushButton *POSTReguestButton;
    QMenuBar *menubar;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *WebAgent)
    {
        if (WebAgent->objectName().isEmpty())
            WebAgent->setObjectName(QString::fromUtf8("WebAgent"));
        WebAgent->resize(360, 640);
        WebAgent->setMinimumSize(QSize(360, 640));
        WebAgent->setMaximumSize(QSize(360, 640));
        WebAgent->setSizeIncrement(QSize(0, 2));
        centralwidget = new QWidget(WebAgent);
        centralwidget->setObjectName(QString::fromUtf8("centralwidget"));
        verticalLayout = new QVBoxLayout(centralwidget);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        lineEdit = new QLineEdit(centralwidget);
        lineEdit->setObjectName(QString::fromUtf8("lineEdit"));

        verticalLayout->addWidget(lineEdit);

        preview = new QWebEngineView(centralwidget);
        preview->setObjectName(QString::fromUtf8("preview"));

        verticalLayout->addWidget(preview);

        pushButtonNetworkOn = new QPushButton(centralwidget);
        pushButtonNetworkOn->setObjectName(QString::fromUtf8("pushButtonNetworkOn"));

        verticalLayout->addWidget(pushButtonNetworkOn);

        pushButtonNetworkOff = new QPushButton(centralwidget);
        pushButtonNetworkOff->setObjectName(QString::fromUtf8("pushButtonNetworkOff"));

        verticalLayout->addWidget(pushButtonNetworkOff);

        POSTReguestButton = new QPushButton(centralwidget);
        POSTReguestButton->setObjectName(QString::fromUtf8("POSTReguestButton"));

        verticalLayout->addWidget(POSTReguestButton);

        WebAgent->setCentralWidget(centralwidget);
        menubar = new QMenuBar(WebAgent);
        menubar->setObjectName(QString::fromUtf8("menubar"));
        menubar->setGeometry(QRect(0, 0, 360, 28));
        WebAgent->setMenuBar(menubar);
        statusbar = new QStatusBar(WebAgent);
        statusbar->setObjectName(QString::fromUtf8("statusbar"));
        WebAgent->setStatusBar(statusbar);

        retranslateUi(WebAgent);

        QMetaObject::connectSlotsByName(WebAgent);
    } // setupUi

    void retranslateUi(QMainWindow *WebAgent)
    {
        WebAgent->setWindowTitle(QCoreApplication::translate("WebAgent", "WebAgent", nullptr));
        pushButtonNetworkOn->setText(QCoreApplication::translate("WebAgent", "Network ON", nullptr));
        pushButtonNetworkOff->setText(QCoreApplication::translate("WebAgent", "Network OFF", nullptr));
        POSTReguestButton->setText(QCoreApplication::translate("WebAgent", "POST request", nullptr));
    } // retranslateUi

};

namespace Ui {
    class WebAgent: public Ui_WebAgent {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_WEBAGENT_H
