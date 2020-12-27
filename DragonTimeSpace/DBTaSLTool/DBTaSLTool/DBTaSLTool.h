#pragma once

#include <QtWidgets/QMainWindow>
#include "ui_DBTaSLTool.h"
#include <Tables/TableContainer.h>
class DBTaSLTool : public QMainWindow
{
    Q_OBJECT

public:
    DBTaSLTool(QWidget *parent = Q_NULLPTR);

private:
    Ui::DBTaSLToolClass ui;
};
