#include "mainwindow.h"
#include <qnamespace.h>

#include "./ui_mainwindow.h"
#include "Widgets/toolbar.h"

MainWindow::MainWindow(QWidget *parent) : QMainWindow(parent), ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    // Setup toolbar
    toolbar = new Toolbar();
    addToolBar(Qt::LeftToolBarArea, toolbar);
}

MainWindow::~MainWindow()
{
    delete ui;
}
