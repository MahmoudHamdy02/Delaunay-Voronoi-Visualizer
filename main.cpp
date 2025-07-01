#include <QApplication>

#include "Core/system.h"
#include "UI/mainwindow.h"

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    SceneController *system = new SceneController();

    MainWindow w(system);
    w.show();
    return a.exec();
}
