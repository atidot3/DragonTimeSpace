#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <qcombobox.h>
#include <qtablewidget.h>
#include <Utils/Logger/Logger.h>
#include <qmetaobject.h>
MainWindow::MainWindow(QWidget *parent)
  : QMainWindow(parent), ui(new Ui::MainWindow)
{    

    ui->setupUi(this);
}
// c = class name; e = enum name; v = enum value
#define ENUM_TO_STRING(e, v) \
    (MainWindow::staticMetaObject.enumerator(MainWindow::staticMetaObject.indexOfEnumerator(#e)).valueToKey(v))
// c = class name; e = enum name; s = string value
#define STRING_TO_ENUM(e, s) \
    (MainWindow::e)(MainWindow::staticMetaObject.enumerator(MainWindow::staticMetaObject.indexOfEnumerator(#e)).keyToValue(s))
// c = class name; f = flag name, v = flag value
#define FLAG_TO_STRING(f, v) \
    (MainWindow::staticMetaObject.enumerator(MainWindow::staticMetaObject.indexOfEnumerator(#f)).valueToKeys(v))
// c = class name; f = flag name; s = string value
#define STRING_TO_FLAG(f, s) \
    (MainWindow::f)(MainWindow::staticMetaObject.enumerator(MainWindow::staticMetaObject.indexOfEnumerator(#f)).keysToValue(s)
MainWindow::~MainWindow()
{
    delete ui;
}

QStringList GetChatCommandLabels()
{


    QStringList list;
    list << "cdrate"
        << "id"
        << "levellimit"

        << "name_short"

        << "contentstyle"

        << "name"
        << "cachedount"
        << "tbxid"
        << "namestyle"
        << "wordlimit"
        << "cost";
    return list;
}

void MainWindow::on_actionLoad_TBX_triggered()
{
    sTBL.load("../../Data/tbx/");
    ui->statusbar->showMessage("All Tables Loaded");
    QWidget* pWidget = ui->tabWidget->findChild<QWidget*>("cbTBXNames");
    QComboBox* combo = qobject_cast<QComboBox*>(pWidget);
    if (combo)
    {
        QStringList qList;
        for (int i = 0; i < TABLES::TABLE_COUNT; i++)
        {
            qList << ENUM_TO_STRING(TABLES, i);
        }
        combo->addItems(qList);
    }
}

void MainWindow::on_cbTBXNames_currentIndexChanged(int index)
{
    
    
    LoadTbxTableView(index);

        
}

void MainWindow::LoadTbxTableView(int index)
{
    QWidget* pWidget = ui->tabWidget->findChild<QWidget*>("dataTable");
    QTableWidget* dataTable = qobject_cast<QTableWidget*>(pWidget);
    if (dataTable)
    {
        switch ((TABLES)index)
        {
        case TABLES::CHATCHANNEL:
        {
            dataTable->clear();
            dataTable->setRowCount(0);
            dataTable->setColumnCount(GetChatCommandLabels().size());
            dataTable->setHorizontalHeaderLabels(GetChatCommandLabels());

            auto test = sTBL.get_table<pb::chatchannel>();
            for (auto it = test.datas().begin(); it != test.datas().end(); ++it)
            {
                int c = 0;
                dataTable->insertRow(dataTable->rowCount());
                dataTable->setItem(dataTable->rowCount() - 1, c, new QTableWidgetItem(QString::number(it->cdrate())));
                dataTable->setItem(dataTable->rowCount() - 1, ++c, new QTableWidgetItem(QString::number(it->id())));
                dataTable->setItem(dataTable->rowCount() - 1, ++c, new QTableWidgetItem(QString::number(it->levellimit())));
                dataTable->setItem(dataTable->rowCount() - 1, ++c, new QTableWidgetItem(QString::fromStdString(it->name_short())));
                dataTable->setItem(dataTable->rowCount() - 1, ++c, new QTableWidgetItem(QString::fromStdString(it->contentstyle())));
                dataTable->setItem(dataTable->rowCount() - 1, ++c, new QTableWidgetItem(QString::fromStdString(it->name())));
                dataTable->setItem(dataTable->rowCount() - 1, ++c, new QTableWidgetItem(QString::number(it->cachedount())));
                dataTable->setItem(dataTable->rowCount() - 1, ++c, new QTableWidgetItem(QString::number(it->tbxid())));
                dataTable->setItem(dataTable->rowCount() - 1, ++c, new QTableWidgetItem(QString::fromStdString(it->namestyle())));
                dataTable->setItem(dataTable->rowCount() - 1, ++c, new QTableWidgetItem(QString::number(it->wordlimit())));
                dataTable->setItem(dataTable->rowCount() - 1, ++c, new QTableWidgetItem(QString::fromStdString(it->cost())));

            }
            ui->statusbar->showMessage("Chat Command Loaded");
            this->setWindowTitle("DBTaSL Tool: Editing World zone");
        }break;
         default:
             ui->statusbar->showMessage("Table Unhandled");
             break;

        }


    }
}