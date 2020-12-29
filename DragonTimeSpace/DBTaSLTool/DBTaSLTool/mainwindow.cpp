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
            case TABLES::DIALOGUECONFIG:
            {
                auto table = sTBL.get_table < pb::dialogueconfig>();
                IterateTbxFields<pb::dialogueconfig>(dataTable, table);
                ui->statusbar->showMessage("Table Loaded");
            }
            break;
            case TABLES::DNACHIP_CONFIG:
            {
                auto table = sTBL.get_table < pb::dnachip_config>();
                IterateTbxFields<pb::dnachip_config>(dataTable, table);
                ui->statusbar->showMessage("Table Loaded");
            }
            break;
            case TABLES::DNASLOT_CONFIG:
            {
                auto table = sTBL.get_table < pb::dnaslot_config>();
                IterateTbxFields<pb::dnaslot_config>(dataTable, table);
                ui->statusbar->showMessage("Table Loaded");
            }
            break;
            case TABLES::DYNAMICTEXT:
            {
                auto table = sTBL.get_table < pb::dynamictext>();
                IterateTbxFields<pb::dynamictext>(dataTable, table);
                ui->statusbar->showMessage("Table Loaded");
            }
            break;
            case TABLES::ENTANGLEMENT_CONFIG:
            {
                auto table = sTBL.get_table < pb::entanglement_config>();
                IterateTbxFields<pb::entanglement_config>(dataTable, table);
                ui->statusbar->showMessage("Table Loaded");
            }
            break;
            case TABLES::EQUIPS:
            {
                auto table = sTBL.get_table < pb::equips>();
                IterateTbxFields<pb::equips>(dataTable, table);
                ui->statusbar->showMessage("Table Loaded");
            }
            break;
            case TABLES::EQUIP_SUFFIX:
            {
                auto table = sTBL.get_table < pb::equip_suffix>();
                IterateTbxFields<pb::equip_suffix>(dataTable, table);
                ui->statusbar->showMessage("Table Loaded");
            }
            break;
            case TABLES::ESC_CONFIG:
            {
                auto table = sTBL.get_table < pb::esc_config>();
                IterateTbxFields<pb::esc_config>(dataTable, table);
                ui->statusbar->showMessage("Table Loaded");
            }
            break;
            case TABLES::EVENT_CONFIG:
            {
                auto table = sTBL.get_table < pb::event_config>();
                IterateTbxFields<pb::event_config>(dataTable, table);
                ui->statusbar->showMessage("Table Loaded");
            }
            break;
            case TABLES::EVOLUTION_CONFIG:
            {
                auto table = sTBL.get_table < pb::evolution_config>();
                IterateTbxFields<pb::evolution_config>(dataTable, table);
                ui->statusbar->showMessage("Table Loaded");
            }
            break;
            case TABLES::FACECONFIG:
            {
                auto table = sTBL.get_table < pb::faceconfig>();
                IterateTbxFields<pb::faceconfig>(dataTable, table);
                ui->statusbar->showMessage("Table Loaded");
            }
            break;
            case TABLES::FETTERS_CONFIG:
            {
                auto table = sTBL.get_table < pb::fetters_config>();
                IterateTbxFields<pb::fetters_config>(dataTable, table);
                ui->statusbar->showMessage("Table Loaded");
            }
            break;
            case TABLES::GENE_REMAKE:
            {
                auto table = sTBL.get_table < pb::gene_remake>();
                IterateTbxFields<pb::gene_remake>(dataTable, table);
                ui->statusbar->showMessage("Table Loaded");
            }
            break;
            case TABLES::GROWTARGET_CONFIG:
            {
                auto table = sTBL.get_table < pb::growtarget_config>();
                IterateTbxFields<pb::growtarget_config>(dataTable, table);
                ui->statusbar->showMessage("Table Loaded");
            }
            break;
            case TABLES::GUIDE:
            {
                auto table = sTBL.get_table < pb::guide>();
                IterateTbxFields<pb::guide>(dataTable, table);
                ui->statusbar->showMessage("Table Loaded");
            }
            break;
            case TABLES::HEROPANEL_MAXIMUM:
            {
                auto table = sTBL.get_table < pb::heropanel_maximum>();
                IterateTbxFields<pb::heropanel_maximum>(dataTable, table);
                ui->statusbar->showMessage("Table Loaded");
            }
            break;
            case TABLES::HEROS:
            {
                auto table = sTBL.get_table < pb::heros>();
                IterateTbxFields<pb::heros>(dataTable, table);
                ui->statusbar->showMessage("Table Loaded");
            }
            break;
            case TABLES::ILLEGALWORD:
            {
                auto table = sTBL.get_table < pb::illegalword>();
                IterateTbxFields<pb::illegalword>(dataTable, table);
                ui->statusbar->showMessage("Table Loaded");
            }
            break;
            case TABLES::KEY:
            {
                auto table = sTBL.get_table < pb::key>();
                IterateTbxFields<pb::key>(dataTable, table);
                ui->statusbar->showMessage("Table Loaded");
            }
            break;
            case TABLES::LEVELCONFIG:
            {
                auto table = sTBL.get_table < pb::levelconfig>();
                IterateTbxFields<pb::levelconfig>(dataTable, table);
                ui->statusbar->showMessage("Table Loaded");
            }
            break;
            case TABLES::LOADINGTIPS:
            {
                auto table = sTBL.get_table < pb::loadingtips>();
                IterateTbxFields<pb::loadingtips>(dataTable, table);
                ui->statusbar->showMessage("Table Loaded");
            }
            break;
            case TABLES::LOOKSCONFIG:
            {
                auto table = sTBL.get_table < pb::looksconfig>();
                IterateTbxFields < pb::looksconfig > (dataTable, table);
                ui->statusbar->showMessage("Table Loaded");
            }
            break;
            case TABLES::MANUFACTURE:
            {
                auto table = sTBL.get_table < pb::manufacture>();
                IterateTbxFields<pb::manufacture>(dataTable, table);
                ui->statusbar->showMessage("Table Loaded");
            }
            break;
            case TABLES::NAMEPOOL:
            {
                auto table = sTBL.get_table < pb::namepool>();
                IterateTbxFields<pb::namepool>(dataTable, table);
                ui->statusbar->showMessage("Table Loaded");
            }
            break;
            case TABLES::NEWUSER:
            {
                auto table = sTBL.get_table < pb::newUser>();
                IterateTbxFields<pb::newUser>(dataTable, table);
                ui->statusbar->showMessage("Table Loaded");
            }
            break;
            case TABLES::NPC_DATA:
            {
                auto table = sTBL.get_table < pb::npc_data>();
                IterateTbxFields<pb::npc_data>(dataTable, table);
                ui->statusbar->showMessage("Table Loaded");
            }
            break;
            case TABLES::OBJECTS:
            {
                auto table = sTBL.get_table < pb::objects>();
                IterateTbxFields<pb::objects>(dataTable, table);
                ui->statusbar->showMessage("Table Loaded");
            }
            break;
            case TABLES::PATHWAY:
            {
                auto table = sTBL.get_table < pb::pathway>();
                IterateTbxFields<pb::pathway>(dataTable, table);
                ui->statusbar->showMessage("Table Loaded");
            }
            break;
            case TABLES::PLAYER_LEVEL_CONFIG:
            {
                auto table = sTBL.get_table < pb::player_level_config>();
                IterateTbxFields<pb::player_level_config>(dataTable, table);
                ui->statusbar->showMessage("Table Loaded");
            }
            break;
            case TABLES::QUESTCONFIG:
            {
                auto table = sTBL.get_table < pb::questconfig>();
                IterateTbxFields<pb::questconfig>(dataTable, table);
                ui->statusbar->showMessage("Table Loaded");
            }
            break;
            case TABLES::QUIZDATACONFIG:
            {
                auto table = sTBL.get_table < pb::quizdataConfig>();
                IterateTbxFields<pb::quizdataConfig>(dataTable, table);
                ui->statusbar->showMessage("Table Loaded");
            }
            break;
            case TABLES::RANKPK_LEVEL:
            {
                auto table = sTBL.get_table < pb::rankpk_level>();
                IterateTbxFields<pb::rankpk_level>(dataTable, table);
                ui->statusbar->showMessage("Table Loaded");
            }
            break;
            case TABLES::RELATION_TBX:
            {
                auto table = sTBL.get_table < pb::relation_tbx>();
                IterateTbxFields<pb::relation_tbx>(dataTable, table);
                ui->statusbar->showMessage("Table Loaded");
            }
            break;
            case TABLES::REWARD_LEVEL:
            {
                auto table = sTBL.get_table < pb::reward_level>();
                IterateTbxFields<pb::reward_level>(dataTable, table);
                ui->statusbar->showMessage("Table Loaded");
            }
            break;
            case TABLES::RUNECONFIG:
            {
                auto table = sTBL.get_table < pb::runeConfig>();
                IterateTbxFields<pb::runeConfig>(dataTable, table);
                ui->statusbar->showMessage("Table Loaded");
            }
            break;
            case TABLES::SCREENSETTING:
            {
                auto table = sTBL.get_table < pb::screensetting>();
                IterateTbxFields<pb::screensetting>(dataTable, table);
                ui->statusbar->showMessage("Table Loaded");
            }
            break;
            case TABLES::SEVENTARGET_CONFIG:
            {
                auto table = sTBL.get_table < pb::seventarget_config>();
                IterateTbxFields<pb::seventarget_config>(dataTable, table);
                ui->statusbar->showMessage("Table Loaded");
            }
            break;
            case TABLES::SKILLSHOW:
            {
                auto table = sTBL.get_table < pb::skillshow>();
                IterateTbxFields<pb::skillshow>(dataTable, table);
                ui->statusbar->showMessage("Table Loaded");
            }
            break;
            case TABLES::SKILL_DATA:
            {
                auto table = sTBL.get_table < pb::skill_data>();
                IterateTbxFields<pb::skill_data>(dataTable, table);
                ui->statusbar->showMessage("Table Loaded");
            }
            break;
            case TABLES::SKILL_GUILD:
            {
                auto table = sTBL.get_table < pb::skill_guild>();
                IterateTbxFields<pb::skill_guild>(dataTable, table);
                ui->statusbar->showMessage("Table Loaded");
            }
            break;
            case TABLES::SKILL_STAGE:
            {
                auto table = sTBL.get_table < pb::skill_stage>();
                IterateTbxFields<pb::skill_stage>(dataTable, table);
                ui->statusbar->showMessage("Table Loaded");
            }
            break;
            case TABLES::SUMMONPET:
            {
                auto table = sTBL.get_table < pb::summonpet>();
                IterateTbxFields<pb::summonpet>(dataTable, table);
                ui->statusbar->showMessage("Table Loaded");
            }
            break;
            case TABLES::SUMMONPETLEVELUP:
            {
                auto table = sTBL.get_table < pb::summonpetLevelUp>();
                IterateTbxFields<pb::summonpetLevelUp>(dataTable, table);
                ui->statusbar->showMessage("Table Loaded");
            }
            break;
            case TABLES::SURVEY_CONFIG:
            {
                auto table = sTBL.get_table < pb::survey_config>();
                IterateTbxFields<pb::survey_config>(dataTable, table);
                ui->statusbar->showMessage("Table Loaded");
            }
            break;
            case TABLES::TELEPORT:
            {
                auto table = sTBL.get_table < pb::teleport>();
                IterateTbxFields<pb::teleport>(dataTable, table);
                ui->statusbar->showMessage("Table Loaded");
            }
            break;
            case TABLES::TEXTCONFIG:
            {
                auto table = sTBL.get_table < pb::textconfig>();
                IterateTbxFields<pb::textconfig>(dataTable, table);
                ui->statusbar->showMessage("Table Loaded");
            }
            break;
            case TABLES::UIMAPINFO:
            {
                auto table = sTBL.get_table < pb::uimapinfo>();
                IterateTbxFields<pb::uimapinfo>(dataTable, table);
                ui->statusbar->showMessage("Table Loaded");
            }
            break;
            case TABLES::UNLOCK_CONFIG:
            {
                auto table = sTBL.get_table < pb::unlock_config>();
                IterateTbxFields<pb::unlock_config>(dataTable, table);
                ui->statusbar->showMessage("Table Loaded");
            }
            break;
            case TABLES::VIPCARD_CONFIG:
            {
                auto table = sTBL.get_table < pb::vipcard_config>();
                IterateTbxFields<pb::vipcard_config>(dataTable, table);
                ui->statusbar->showMessage("Table Loaded");
            }
            break;

             default:
                 ui->statusbar->showMessage("Table Unhandled");
                 break;
        }


    }    
}

