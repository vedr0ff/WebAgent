#include "webagent.h"
#include "ui_webagent.h"
#include <sys/ioctl.h>
#include <net/if.h>
#include <netinet/in.h>
#include <stdio.h>
#include <arpa/inet.h>

WebAgent::WebAgent(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::WebAgent)
    , timer(new QTimer(this))
    , mgr(new QNetworkAccessManager(this))
    , popUp(new PopUpWidget(this))
{
    ui->setupUi(this);

    connect(this->ui->lineEdit, &QLineEdit::returnPressed, this, &WebAgent::UrlEnter);
    connect(this->mgr, &QNetworkAccessManager::finished, this, static_cast<void (WebAgent::*)(QNetworkReply*)> (&WebAgent::onResponse));
    connect(this->timer, &QTimer::timeout, this, static_cast<void (WebAgent::*)()> (&WebAgent::fadeOut));
}

WebAgent::~WebAgent()
{
    delete ui;
}

void WebAgent::fadeOut()
{
    this->popUp->hide();
    this->timer->stop();
    delete this->timer;
}


void WebAgent::onResponse(QNetworkReply* reply)
{
    const QPoint globalPos = ui->POSTReguestButton->mapFromGlobal(QPoint(0, 0));
    this->popUp->setPopupText(reply->readAll());
    const int posX = -globalPos.x();
    const int posY = -globalPos.y();

    popUp->setGeometry(posX + ui->POSTReguestButton->width(),
                       posY - ui->POSTReguestButton->height() / 2,
                       popUp->width(),
                       popUp->height());
    this->popUp->show();

    this->timer = new QTimer();
    connect(this->timer, &QTimer::timeout, this, static_cast<void (WebAgent::*)()> (&WebAgent::fadeOut));
    this->timer->start(5000);
}

void WebAgent::UrlEnter()
{
    QString tmp = ui->lineEdit->text();
    if (tmp.isEmpty())
       ui->preview->setUrl(QUrl("https://www.google.com/"));
    else
        ui->preview->setUrl(QUrl::fromUserInput(tmp));
    ui->preview->show();
}

void WebAgent::on_POSTReguestButton_clicked()
{
    QNetworkRequest request(QUrl("127.0.0.1:8000/api"));
    request.setRawHeader("Content-Type", "application/x-www-form-urlencoded");
    QByteArray params = "{'param1': 1, 'param2': 2}";
    this->mgr->post(request, params);
}


void WebAgent::on_pushButtonNetworkOn_clicked()
{
    QProcess process;
    process.setEnvironment(QProcess::systemEnvironment());
    process.start("pkexec", QStringList() << "--user" << "root" << "ifup" << "--all");
    process.waitForFinished();
    process.close();
}

void WebAgent::on_pushButtonNetworkOff_clicked()
{
    QProcess process;
    process.setEnvironment(QProcess::systemEnvironment());
    process.start("pkexec", QStringList() << "--user" << "root" << "ifdown" << "--all");
    process.waitForFinished();
    process.close();
}
