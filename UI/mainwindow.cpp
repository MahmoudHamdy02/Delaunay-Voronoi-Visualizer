#include "mainwindow.h"

#include <qaction.h>

#include <iostream>

#include "./ui_mainwindow.h"
#include "Widgets/toolbar.h"

MainWindow::MainWindow(QWidget* parent) : QMainWindow(parent), ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    // Setup toolbar
    toolbar = new Toolbar();
    addToolBar(Qt::LeftToolBarArea, toolbar);

    connect(toolbar->getActionGroup(), &QActionGroup::triggered, this, &MainWindow::onToolbarActionSelected);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::onToolbarActionSelected(QAction* action)
{
    std::cout << action->text().toStdString() << std::endl;
}
