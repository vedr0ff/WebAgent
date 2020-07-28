#ifndef WEBAGENT_H
#define WEBAGENT_H

#include <QLabel>
#include <QTimer>
#include <QProcess>
#include <QMainWindow>
#include <QWebEngineView>
#include <QPropertyAnimation>
#include <QNetworkAccessManager>
#include <QGraphicsOpacityEffect>
#include <QtNetwork/QNetworkReply>
#include <QtNetwork/QNetworkInterface>

#include "popupwidget.h"

QT_BEGIN_NAMESPACE
namespace Ui { class WebAgent; }
QT_END_NAMESPACE

class WebAgent : public QMainWindow
{
    Q_OBJECT

public:
    WebAgent(QWidget *parent = nullptr);
    ~WebAgent();

private slots:

    void UrlEnter();

    void on_POSTReguestButton_clicked();

    void on_pushButtonNetworkOn_clicked();

    void on_pushButtonNetworkOff_clicked();

private:
    Ui::WebAgent *ui;
    QTimer *timer;
    QNetworkAccessManager* mgr;
    PopUpWidget *popUp;

    void fadeOut();
    void onResponse(QNetworkReply* reply);
};
#endif // WEBAGENT_H
