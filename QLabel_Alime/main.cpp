#include "QLabel_Alime.h"
#include <QtWidgets/QApplication>
#include <QFile>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    QFile qssfile(":/Qss/DarkBlue.qss");
    qssfile.open(QFile::ReadOnly);
    QString qss;
    qss = qssfile.readAll();
    a.setStyleSheet(qss);

    QLabel_Alime w;
    w.show();
    return a.exec();
}
