#include "webagent.h"

#include <QApplication>
#include <QWebEngineView>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    WebAgent w;
    w.show();
    return a.exec();
}
