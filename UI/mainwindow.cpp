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

    // File -> Exit
    connect(ui->actionExit, &QAction::triggered, this, []() { qApp->exit(); });

    // Help -> How to use
    connect(ui->actionHow_to_use, &QAction::triggered, this,
            [this]() { QMessageBox::information(this, "Usage instructions", "Usage text here"); });

    // Help -> About
    connect(ui->actionAbout, &QAction::triggered, this, [this]() { QMessageBox::aboutQt(this, "About"); });
}

void MainWindow::setupToolbar()
{
    toolbar = new Toolbar(this);
    addToolBar(Qt::LeftToolBarArea, toolbar);

    connect(toolbar->getActionGroup(), &QActionGroup::triggered, this, &MainWindow::onToolbarActionSelected);
}

void MainWindow::setupOpenGLView()
{
    view = new View(sceneController->getScene(), this);

    connect(view, &View::emitAddPoint, sceneController, &SceneController::onAddPoint);

    ui->horizontalLayout->addWidget(view);
}
