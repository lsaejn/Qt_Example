#include "QCommandLinkButton_Alime.h"
#include <QtWidgets/QApplication>

#include <QFile>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    //:/QCommandLinkButton_Alime/myqss
    QFile qssfile(":/QCommandLinkButton_Alime/myqss");
    qssfile.open(QFile::ReadOnly);
    QString qss;
    qss = qssfile.readAll();
    a.setStyleSheet(qss);

    QCommandLinkButton_Alime w;
    w.show();
    return a.exec();
}
