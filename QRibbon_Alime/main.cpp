#include "QRibbon_Alime.h"
#include <QtWidgets/QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    QRibbon_Alime w;
    w.show();
    return a.exec();
}
