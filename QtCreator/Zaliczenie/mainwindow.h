#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QtMultimedia/QSoundEffect>
#include <QGraphicsOpacityEffect>
#include <QPropertyAnimation>
#include <QResizeEvent>

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

struct Gracz{
    int hp;
    int maxhp;
    int zloto;
    int poziom;
    int exp;
    int lvlup;
    int potki;
    int minatak;
    int maxatak;
    int pmiecza;
    int pzbroi;
    int szansa;
};

struct Enemy{
    int hp;
    int maxhp;
    int minatak;
    int maxatak;
    int potki;
    int szansa;
    int tura;
    int trudnosc;
};

struct Shop{
    int SwordCost;
    int ArmorCost;
    int item;
};

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void on_StartButton_clicked();

    void on_TownStatsButton_clicked();

    void on_TownArenaButton_clicked();

    void on_TownShopButton_clicked();

    void on_TownTavernButton_clicked();

    void on_TavernYesButton_clicked();

    void on_TavernReturnButton_clicked();

    void on_ShopSwordButton_clicked();

    void on_ShopArmorButton_clicked();

    void on_ShopPotionButton_clicked();

    void on_ShopReturnButton_clicked();

    void on_ShopItemBuyButton_clicked();

    void on_ShopItemReturnButton_clicked();

    void on_StatsReturnButton_clicked();

    void on_ArenaEntranceReturnButton_clicked();

    void on_ArenaEntranceNormalButton_clicked();

    void on_ArenaEntranceHardButton_clicked();

    void on_ArenaEntranceBossButton_clicked();

    void on_ArenaStartButton_clicked();

    void on_ArenaFastAttackButton_clicked();

    void on_ArenaNormalAttackButton_clicked();

    void on_ArenaPowerAttackButton_clicked();

    void on_ArenaPotionButton_clicked();

    void on_ArenaEndDefeatResetButton_clicked();

    void on_ArenaEndDefeatExitButton_clicked();

    void on_ArenaEndFinishResetButton_clicked();

    void on_ArenaEndFinishExitButton_clicked();

    void on_ArenaEndVictoryButton_clicked();

    void on_ArenaEndVictoryLvlupButton_clicked();

private:
    Ui::MainWindow *ui;
    QSoundEffect ButtonSound;
    QSoundEffect CrowdSound;
    QSoundEffect PotionSound;
    QSoundEffect Attack1Sound;
    QSoundEffect Attack2Sound;
    QSoundEffect VictorySound;
    QSoundEffect DefeatSound;
    QMovie *PlayerIdleAnim;
    QMovie *PlayerAttackAnim;
    QMovie *PlayerHealAnim;
    QMovie *PlayerHealReturnAnim;
    QMovie *PlayerHitAnim;
    QMovie *EnemyIdleAnim;
    QMovie *EnemyAttackAnim;
    QMovie *EnemyHealAnim;
    QMovie *EnemyHealReturnAnim;
    QMovie *EnemyHitAnim;
    QGraphicsOpacityEffect *PlayerHPEffect;
    QGraphicsOpacityEffect *EnemyHPEffect;
    QPropertyAnimation *PlayerHPAnim;
    QPropertyAnimation *EnemyHPAnim;
    Gracz gracz;
    Shop shop;
    Enemy enemy;
    void LoadFiles();
    void ShopItemRender();
    void GenerateEnemy();
    void EnemyTurn();
    void HandleAttack(int damage);
    void HandleHealing(int healing);
    void FightEnd();
};
#endif // MAINWINDOW_H
