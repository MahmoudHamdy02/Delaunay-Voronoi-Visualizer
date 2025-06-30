#pragma once

#include <QToolBar>
#include <QActionGroup>

class Toolbar : public QToolBar
{
    QActionGroup* actionGroup;

public:
    Toolbar();
};
