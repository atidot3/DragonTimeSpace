#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <qcombobox.h>
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
template<typename T>
void IterateTbxFields(QTableWidget* dataTable, T& tbl)
{
    try
    {
        const google::protobuf::Descriptor* desc = tbl.GetDescriptor();
        const google::protobuf::Reflection* refl = tbl.GetReflection();
        dataTable->clear();
        dataTable->setRowCount(0);
        int fieldCount = desc->nested_type(0)->field_count();
        QStringList HeaderNames;
        for (int i = 0; i < fieldCount; i++)
        {

            const google::protobuf::FieldDescriptor* field = desc->nested_type(0)->field(i);
            QString qstr = QString::fromStdString(field->name());

            HeaderNames << qstr;
        }
        dataTable->setColumnCount(HeaderNames.size());
        dataTable->setHorizontalHeaderLabels(HeaderNames);
     /*   for (auto it = tbl.datas().begin(); it != tbl.datas().end(); ++it)
        {*/

        const google::protobuf::FieldDescriptor* field = desc->field(0);
        // Use the reflection interface to examine the contents.
        int size = refl ->FieldSize(tbl, field);
        const google::protobuf::Reflection* pInnerReflection = NULL;
        const google::protobuf::FieldDescriptor* pTestFieldDesc = NULL;
        int nestedTypeCount = desc->nested_type(0)->field_count();
        for (int i = 0; i < size; i++) 
        {
            int c = 0;
            dataTable->insertRow(dataTable->rowCount());
            bool firstField = true;

            const google::protobuf::Message& msg = refl->GetRepeatedMessage(tbl, field, i);
            if (pInnerReflection == NULL) 
            {
                pInnerReflection = msg.GetReflection();
                for (int j = 0; j < nestedTypeCount; j++)
                {
                    pTestFieldDesc = msg.GetDescriptor()->field(j);
                    {
                        std::string g = "";
                        int32_t i32 = 0;
                        int64_t i64 = 0;
                        uint32_t u32 = 0;
                        uint64_t u64 = 0;


                        switch (pTestFieldDesc->type())
                        {
                        case google::protobuf::FieldDescriptor::TYPE_UINT32:
                            u32 = pInnerReflection->GetUInt32(msg, pTestFieldDesc);
                            if (firstField)
                            {
                                dataTable->setItem(dataTable->rowCount() - 1, c, new QTableWidgetItem(QString::number(u32)));
                                firstField = false;
                            }
                            else
                            {
                                dataTable->setItem(dataTable->rowCount() - 1, ++c, new QTableWidgetItem(QString::number(u32)));
                            }

                            break;
                        case google::protobuf::FieldDescriptor::TYPE_INT32:
                            i32 = pInnerReflection->GetInt32(msg, pTestFieldDesc);
                            if (firstField)
                            {
                                dataTable->setItem(dataTable->rowCount() - 1, c, new QTableWidgetItem(QString::number(i32)));
                                firstField = false;
                            }
                            else
                            {
                                dataTable->setItem(dataTable->rowCount() - 1, ++c, new QTableWidgetItem(QString::number(i32)));
                            }

                            break;
                        case google::protobuf::FieldDescriptor::TYPE_INT64:
                            i64 = pInnerReflection->GetInt64(msg, pTestFieldDesc);
                            if (firstField)
                            {
                                dataTable->setItem(dataTable->rowCount() - 1, c, new QTableWidgetItem(QString::number(i64)));
                                firstField = false;
                            }
                            else
                            {
                                dataTable->setItem(dataTable->rowCount() - 1, ++c, new QTableWidgetItem(QString::number(i64)));
                            }

                            break;
                        case google::protobuf::FieldDescriptor::TYPE_STRING:
                            g = pInnerReflection->GetString(msg, pTestFieldDesc);
                            if (firstField)
                            {
                                dataTable->setItem(dataTable->rowCount() - 1, c, new QTableWidgetItem(QString::fromStdString(g)));
                                firstField = false;
                            }
                            else
                            {
                                dataTable->setItem(dataTable->rowCount() - 1, ++c, new QTableWidgetItem(QString::fromStdString(g)));
                            }
                            break;
                        }
                    }
                }
                pInnerReflection = NULL;
            }
        }
        dataTable->resizeColumnsToContents();
    }
    catch (google::protobuf::FatalException& e)
    {
        std::cout << "Error: " << e.what();
    }
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
            case TABLES::ADVENTURE_COPYMAP:
            {
                auto table = sTBL.get_table<pb::adventure_copymap>();
                IterateTbxFields<pb::adventure_copymap>(dataTable, table);
                ui->statusbar->showMessage("Table Loaded");
            }
            break;
            case TABLES::ALLACTION:
            {
                auto table = sTBL.get_table < pb::allaction >();
                IterateTbxFields<pb::allaction>(dataTable, table);
                ui->statusbar->showMessage("Table Loaded");
            }
            break;
            case TABLES::ATTRIBUTE_CONFIG:
            {
                auto table = sTBL.get_table < pb::attribute_config>();
                IterateTbxFields<pb::attribute_config>(dataTable, table);
                ui->statusbar->showMessage("Table Loaded");
            }
            break;
            case TABLES::AVATAR_CONFIG:
            {
                auto table = sTBL.get_table < pb::avatar_config>();
                IterateTbxFields<pb::avatar_config>(dataTable, table);
                ui->statusbar->showMessage("Table Loaded");
            }
            break;
            case TABLES::BATTLE_CONFIG:
            {
                auto table = sTBL.get_table < pb::battle_config>();
                IterateTbxFields<pb::battle_config>(dataTable, table);
                ui->statusbar->showMessage("Table Loaded");
            }
            break;
            case TABLES::BUILDING_DATA:
            {
                auto table = sTBL.get_table < pb::building_data>();
                IterateTbxFields<pb::building_data>(dataTable, table);
                ui->statusbar->showMessage("Table Loaded");
            }
            break;
            case TABLES::CARDDATA_CONFIG:
            {
                auto table = sTBL.get_table < pb::carddata_config>();
                IterateTbxFields<pb::carddata_config>(dataTable, table);
                ui->statusbar->showMessage("Table Loaded");
            }
            break;
            case TABLES::CARDEFFECT_CONFIG:
            {
                auto table = sTBL.get_table < pb::cardeffect_config>();
                IterateTbxFields<pb::cardeffect_config>(dataTable, table);
                ui->statusbar->showMessage("Table Loaded");
            }
            break;
            case TABLES::CAREERLV:
            {
                auto table = sTBL.get_table < pb::careerLv>();
                IterateTbxFields<pb::careerLv>(dataTable, table);
                ui->statusbar->showMessage("Table Loaded");
            }
            break;
            case TABLES::CHARSTATE:
            {
                auto table = sTBL.get_table < pb::charstate>();
                IterateTbxFields<pb::charstate>(dataTable, table);
                ui->statusbar->showMessage("Table Loaded");
            }
            break;
            case TABLES::CHATCHANNEL:
            {
                auto table = sTBL.get_table < pb::chatchannel>();
                IterateTbxFields<pb::chatchannel>(dataTable, table);
                ui->statusbar->showMessage("Table Loaded");
            }
            break;
            case TABLES::CONVENIENT:
            {
                auto table = sTBL.get_table < pb::convenient>();
                IterateTbxFields<pb::convenient>(dataTable, table);
                ui->statusbar->showMessage("Table Loaded");
            }
            break;
            case TABLES::COORDINATES_ARENA_CONFIG:
            {
                auto table = sTBL.get_table < pb::coordinates_arena_config>();
                IterateTbxFields<pb::coordinates_arena_config>(dataTable, table);
                ui->statusbar->showMessage("Table Loaded");
            }
            break;
            case TABLES::COPYMAPEVENT:
            {
                auto table = sTBL.get_table < pb::copymapEvent>();
                IterateTbxFields<pb::copymapEvent>(dataTable, table);
                ui->statusbar->showMessage("Table Loaded");
            }
            break;
            case TABLES::COPYMAPINFO:
            {
                auto table = sTBL.get_table < pb::copymapinfo>();
                IterateTbxFields<pb::copymapinfo>(dataTable, table);
                ui->statusbar->showMessage("Table Loaded");
            }
            break;
            case TABLES::COPYMAPMASTER:
            {
                auto table = sTBL.get_table < pb::copymapmaster>();
                IterateTbxFields<pb::copymapmaster>(dataTable, table);
                ui->statusbar->showMessage("Table Loaded");
            }
            break;
            case TABLES::CUTSCENE:
            {
                auto table = sTBL.get_table < pb::cutscene>();
                IterateTbxFields<pb::cutscene>(dataTable, table);
                ui->statusbar->showMessage("Table Loaded");
            }
            break;
            case TABLES::DEVICESETTING:
            {
                auto table = sTBL.get_table < pb::devicesetting>();
                IterateTbxFields<pb::devicesetting>(dataTable, table);
                ui->statusbar->showMessage("Table Loaded");
            }
            break;

             default:
                 ui->statusbar->showMessage("Table Unhandled");
                 break;
        }


    }    
}

