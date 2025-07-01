#include "mainwindow.h"

#include <qaction.h>
#include <qapplication.h>
#include <qgraphicsview.h>
#include <qmessagebox.h>
#include <qopenglwidget.h>

#include <iostream>

#include "./ui_mainwindow.h"
#include "Widgets/toolbar.h"

MainWindow::MainWindow(System* system, QWidget* parent) : QMainWindow(parent), ui(new Ui::MainWindow), system(system)
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
    connect(ui->actionNew_Canvas, &QAction::triggered, this, []() { std::cout << "New canvas" << std::endl; });

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
    view = new QGraphicsView(system->getScene());
    // view->setViewport(new QOpenGLWidget);

    QOpenGLWidget* gl = new QOpenGLWidget();
    QSurfaceFormat format;
    format.setSamples(8);
    gl->setFormat(format);
    view->setViewport(gl);

    view->setBackgroundBrush(Qt::white);
    view->setRenderHint(QPainter::Antialiasing, true);
    ui->horizontalLayout->addWidget(view);
}
