#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <qaction.h>

#include <QMainWindow>

#include "../Core/scenecontroller.h"
#include "Widgets/toolbar.h"
#include "Widgets/view.h"

QT_BEGIN_NAMESPACE
namespace Ui {
class MainWindow;
}
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

    Ui::MainWindow *ui;
    SceneController *sceneController;

    Toolbar *toolbar;
    View *view;

    void setupMenubar();
    void setupToolbar();
    void setupOpenGLView();

public:
    MainWindow(SceneController *sceneController, QWidget *parent = nullptr);
    ~MainWindow();

public slots:
    void onToolbarActionSelected(QAction *action);
};
#endif  // MAINWINDOW_H
