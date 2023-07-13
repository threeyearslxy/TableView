#pragma once

#include <QtWidgets/QWidget>
#include "ui_MyTableView.h"

class MyTableView : public QWidget
{
    Q_OBJECT

public:
    MyTableView(QWidget *parent = Q_NULLPTR);

private:
    Ui::MyTableViewClass ui;
};
