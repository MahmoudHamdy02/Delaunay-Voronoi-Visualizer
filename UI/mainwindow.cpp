#include "mainwindow.h"

#include <qaction.h>
#include <qmessagebox.h>

#include <QMessageBox>
#include <iostream>

#include "./ui_mainwindow.h"
#include "Widgets/toolbar.h"

MainWindow::MainWindow(QWidget* parent) : QMainWindow(parent), ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    setupMenubar();

    // Setup toolbar
    toolbar = new Toolbar(this);
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

void MainWindow::setupMenubar()
{
    // Help -> How to use
    connect(ui->actionHow_to_use, &QAction::triggered, this,
            [this]() { QMessageBox::information(this, "Usage instructions", "Usage text here"); });

    // Help -> About
    connect(ui->actionAbout, &QAction::triggered, this, [this]() { QMessageBox::aboutQt(this, "About"); });
}
