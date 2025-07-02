#include "mainwindow.h"

#include <qaction.h>
#include <qapplication.h>
#include <qgraphicsview.h>
#include <qmessagebox.h>
#include <qopenglwidget.h>

#include <iostream>

#include "./ui_mainwindow.h"
#include "Widgets/toolbar.h"
#include "Widgets/view.h"

MainWindow::MainWindow(SceneController* sceneController, QWidget* parent)
    : QMainWindow(parent), ui(new Ui::MainWindow), sceneController(sceneController)
{
    ui->setupUi(this);

    setWindowTitle("Delaunay-Voronoi Visualiser");

    setupMenubar();
    setupToolbar();
    setupOpenGLView();
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::onToolbarActionSelected(QAction* action)
{
    std::cout << action->text().toStdString() << std::endl;
}

void MainWindow::setupMenubar()
{
    // File -> New Canvas
    connect(ui->actionNew_Canvas, &QAction::triggered, this, [this]() { sceneController->resetScene(); });

    // File -> About
    connect(ui->actionAbout, &QAction::triggered, this, [this]() { QMessageBox::aboutQt(this, "About"); });

    // File -> Exit
    connect(ui->actionExit, &QAction::triggered, this, []() { qApp->exit(); });
}

void MainWindow::setupToolbar()
{
    toolbar = new Toolbar(this);
    addToolBar(Qt::LeftToolBarArea, toolbar);

    connect(toolbar->getDelaunayAction(), &QAction::toggled, sceneController,
            &SceneController::setDrawDelaunayTriangles);
    connect(toolbar->getVoronoiAction(), &QAction::toggled, sceneController, &SceneController::setDrawVoronoiCells);
}

void MainWindow::setupOpenGLView()
{
    view = new View(sceneController->getScene(), this);

    connect(view, &View::emitAddPoint, sceneController, &SceneController::onAddPoint);

    ui->horizontalLayout->addWidget(view);
}
