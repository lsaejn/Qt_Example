#include "Qss_Alime.h"
#include <QtWidgets/QApplication>
#include <QFile>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    //Qss”Ô∑®
    //https://blog.csdn.net/hk2291976/article/details/51387813

    QFile qssfile(":/DarkOrange");
    qssfile.open(QFile::ReadOnly);
    QString qss;
    qss = qssfile.readAll();
    a.setStyleSheet(qss);

    Qss_Alime w;
    w.show();
    return a.exec();
}
