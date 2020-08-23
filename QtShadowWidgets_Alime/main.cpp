#include "QtShadowWidgets_Alime.h"
#include <QtWidgets/QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    ShadowWidget w(2);
    w.show();
    return a.exec();
}
