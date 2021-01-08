#pragma once

#include <QtWidgets/QMainWindow>
#include "ui_HeritageTP2.h"

class HeritageTP2 : public QMainWindow
{
    Q_OBJECT

public:
    HeritageTP2(QWidget *parent = Q_NULLPTR);

private:
    Ui::HeritageTP2Class ui;
};
