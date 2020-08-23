#include "QMusicView.h"
#include <QtWidgets/QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    QMusicView w;
    w.show();
    return a.exec();
}
