#include "QDateEdit_QTimeEdit_Alime.h"
#include <QtWidgets/QApplication>
#include <QFile>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    QFile qssfile(":/Qss/DarkStyle.qss");
    qssfile.open(QFile::ReadOnly);
    QString qss;
    qss = qssfile.readAll();
    a.setStyleSheet(qss);

    QFont font;
    font.setFamily("Microsoft YaHei"); // Tahoma ËÎÌו
    a.setFont(font);

    QDateEdit_QTimeEdit_Alime w;
    w.show();
    return a.exec();
}
