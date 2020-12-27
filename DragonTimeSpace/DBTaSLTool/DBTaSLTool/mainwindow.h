#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <Tables/TableContainer.h>
QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

    void LoadTbxTableView(int index);
    Q_ENUMS(TABLES)
    enum TABLES
    {
        ADVENTURE_COPYMAP,
        ALLACTION,
        ATTRIBUTE_CONFIG,
        AVATAR_CONFIG,
        BATTLE_CONFIG,
        BUILDING_DATA,
        CARDDATA_CONFIG,
        CARDEFFECT_CONFIG,
        CAREERLV,
        CHARSTATE,
        CHATCHANNEL,
        CONVENIENT,
        COORDINATES_ARENA_CONFIG,
        COPYMAPEVENT,
        COPYMAPINFO,
        COPYMAPMASTER,
        CUTSCENE,
        DEVICESETTING,
        DIALOGUECONFIG,
        DNACHIP_CONFIG,
        DNASLOT_CONFIG,
        DYNAMICTEXT,
        ENTANGLEMENT_CONFIG,
        EQUIPS,
        EQUIP_SUFFIX,
        ESC_CONFIG,
        EVENT_CONFIG,
        EVOLUTION_CONFIG,
        FACECONFIG,
        GENE_REMAKE,
        GROWTARGET_CONFIG,
        GUIDE,
        HEROPANEL_MAXIMUM,
        HEROS,
        ILLEGALWORD,
        KEY,
        LEVELCONFIG,
        LOADINGTIPS,
        LOOKSCONFIG,
        MANUFACTURE,
        NAMEPOOL,
        NEWUSER,
        NPC_DATA,
        OBJECTS,
        PATHWAY,
        PLAYER_LEVEL_CONFIG,
        QUESTCONFIG,
        QUIZDATACONFIG,
        RANKPK_LEVEL,
        RELATION_TBX,
        REWARD_LEVEL,
        RUNECONFIG,
        SCREENSETTING,
        SEVENTARGET_CONFIG,
        SKILLSHOW,
        SKILL_DATA,
        SKILL_GUILD,
        SKILL_STAGE,
        SUMMONPET,
        SUMMONPETLEVELUP,
        SURVEY_CONFIG,
        TELEPORT,
        TEXTCONFIG,
        UIMAPINFO,
        UNLOCK_CONFIG,
        VIPCARD_CONFIG,
        FETTERS_CONFIG,
        TABLE_COUNT
    };

private slots:
    void on_actionLoad_TBX_triggered();

    void on_cbTBXNames_currentIndexChanged(int index);

private:
    Ui::MainWindow *ui;
};
#endif // MAINWINDOW_H
