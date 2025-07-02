#include <QApplication>

#include "Core/scenecontroller.h"
#include "UI/mainwindow.h"

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    SceneController *sceneController = new SceneController();

    MainWindow w(sceneController);
    w.show();
    return a.exec();
}
