#include "QSpinBox_Alime.h"
#include <QtWidgets/QApplication>

#include <QFile>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    QFile qssfile(":/QSpinBox_Alime/DarkOrange");
    qssfile.open(QFile::ReadOnly);
    QString qss;
    qss = qssfile.readAll();
    a.setStyleSheet(qss);

    QSpinBox_Alime w;
    w.show();
    return a.exec();
}
