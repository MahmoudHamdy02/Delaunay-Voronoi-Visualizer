#include <QApplication>

#include "Core/system.h"
#include "UI/mainwindow.h"

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    System *system = new System();

    MainWindow w(system);
    w.show();
    return a.exec();
}
