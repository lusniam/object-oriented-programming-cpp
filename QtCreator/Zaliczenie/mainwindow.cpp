#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QFontDatabase>
#include <QStackedWidget>
#include <QPixmap>
#include <QIcon>
#include <QMovie>
#include <QSignalSpy>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    this->setFixedSize(1067,600);
    gracz.hp=60;
    gracz.maxhp=60;
    gracz.zloto=20;
    gracz.poziom=1;
    gracz.exp=0;
    gracz.lvlup=125;
    gracz.potki=0;
    gracz.minatak=0;
    gracz.maxatak=7;
    gracz.pmiecza=0;
    gracz.pzbroi=0;
    gracz.szansa=100;

    shop.SwordCost=10;
    shop.ArmorCost=10;

    ui->setupUi(this);
    LoadFiles();
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::LoadFiles(){
    QIcon icon(QString::fromStdString(":/resources/icon.ico"));
    this->setWindowTitle("Miecze i kalosze");
    this->setWindowIcon(icon);

    QFontDatabase::addApplicationFont(":/resources/PixeloidMono.ttf");
    ui->stackedWidget->setCurrentWidget(ui->Start);
    ButtonSound.setSource(QUrl::fromLocalFile(":/resources/mp3/przycisk.wav"));
    CrowdSound.setSource(QUrl::fromLocalFile(":/resources/mp3/tlum.wav"));
    CrowdSound.setVolume(0.75);
    PotionSound.setSource(QUrl::fromLocalFile(":/resources/mp3/mikstura.wav"));
    Attack1Sound.setSource(QUrl::fromLocalFile(":/resources/mp3/atak1.wav"));
    Attack2Sound.setSource(QUrl::fromLocalFile(":/resources/mp3/atak2.wav"));
    VictorySound.setSource(QUrl::fromLocalFile(":/resources/mp3/wygrana.wav"));
    DefeatSound.setSource(QUrl::fromLocalFile(":/resources/mp3/przegrana.wav"));

    PlayerIdleAnim=new QMovie(":resources/gif/player-idle.gif");
    PlayerAttackAnim=new QMovie(":resources/gif/player-atak.gif");
    PlayerHealAnim=new QMovie(":resources/gif/player-heal.gif");
    PlayerHealReturnAnim=new QMovie(":resources/gif/player-heal-return.gif");
    PlayerHitAnim=new QMovie(":resources/gif/atak.gif");
    EnemyIdleAnim=new QMovie(":resources/gif/enemy-idle.gif");
    EnemyAttackAnim=new QMovie(":resources/gif/enemy-atak.gif");
    EnemyHealAnim=new QMovie(":resources/gif/enemy-heal.gif");
    EnemyHealReturnAnim=new QMovie(":resources/gif/enemy-heal-return.gif");
    EnemyHitAnim=new QMovie(":resources/gif/atak.gif");

    ui->TownPlayer->setMovie(PlayerIdleAnim);
    ui->ArenaPlayerSprite->setMovie(PlayerIdleAnim);
    ui->ArenaEnemySprite->setMovie(EnemyIdleAnim);
    ui->ArenaEndPlayerSprite->setMovie(PlayerHealAnim);
    ui->ArenaEndEnemySprite->setMovie(EnemyHealAnim);
    ui->ArenaPlayerAttackSprite->setMovie(EnemyHitAnim);
    ui->ArenaEnemyAttackSprite->setMovie(PlayerHitAnim);

    PlayerHPEffect=new QGraphicsOpacityEffect();
    ui->ArenaPlayerHPChange->setGraphicsEffect(PlayerHPEffect);
    PlayerHPAnim=new QPropertyAnimation(PlayerHPEffect,"opacity");
    PlayerHPAnim->setDuration(2500);
    PlayerHPAnim->setStartValue(1.5);
    PlayerHPAnim->setEndValue(0.0);
    PlayerHPAnim->setEasingCurve(QEasingCurve::OutQuad);
    EnemyHPEffect=new QGraphicsOpacityEffect();
    ui->ArenaEnemyHPChange->setGraphicsEffect(EnemyHPEffect);
    EnemyHPAnim=new QPropertyAnimation(EnemyHPEffect,"opacity");
    EnemyHPAnim->setDuration(2500);
    EnemyHPAnim->setStartValue(1.5);
    EnemyHPAnim->setEndValue(0.0);
    EnemyHPAnim->setEasingCurve(QEasingCurve::OutQuad);

    ui->ArenaEndDefeat->setVisible(false);
    ui->ArenaEndDefeat->setEnabled(false);
    ui->ArenaEndEnemySprite->setVisible(false);
    ui->ArenaEndFinish->setVisible(false);
    ui->ArenaEndFinish->setEnabled(false);
    ui->ArenaEndVictory->setEnabled(false);
    ui->ArenaEndVictory->setVisible(false);
    ui->ArenaEndVictoryLvlup->setEnabled(false);
    ui->ArenaEndVictoryLvlup->setVisible(false);
    ui->ArenaEndPlayerSprite->setVisible(false);
}

void MainWindow::on_StartButton_clicked()
{
    ButtonSound.play();
    ui->stackedWidget->setCurrentWidget(ui->Town);
    PlayerIdleAnim->start();
    CrowdSound.play();
}

void MainWindow::on_TownStatsButton_clicked()
{
    ButtonSound.play();
    PlayerIdleAnim->stop();
    CrowdSound.stop();
    QString stats;
    stats+="Statystyki:\n";
    stats+="Zdrowie: "+QString::number(gracz.hp)+"/"+QString::number(gracz.maxhp)+"\n";
    stats+="Obrażenia: "+QString::number(gracz.minatak)+"-"+QString::number(gracz.maxatak)+"\n";
    stats+="Szansa na trafienie: "+QString::number(gracz.szansa)+"%\n";
    stats+="Masz "+QString::number(gracz.poziom)+" poziom doświadczenia\n";
    if(gracz.poziom==4){
        stats+="Masz maksymalny poziom!\n";
    }
    else{
        stats+=QString::number(gracz.exp)+"/"+QString::number(gracz.lvlup)+" punktów doświad-\n";
        stats+="czenia do poziomu "+QString::number(gracz.poziom+1);
    }
    stats+="\n\n\nEkwipunek:\n";
    stats+="Masz "+QString::number(gracz.zloto)+" sztuk złota\n";
    if(gracz.pmiecza==0){
        stats+="Nie posiadasz miecza!\n";
    }
    else{
        stats+="Posiadasz miecz poziomu "+QString::number(gracz.pmiecza)+"\n";
    }
    if(gracz.pzbroi==0){
        stats+="Nie posiadasz zbroi!\n";
    }
    else{
        stats+="Posiadasz zbroję poziomu "+QString::number(gracz.pzbroi)+"\n";
    }
    if(gracz.potki==0){
        stats+="Nie posiadasz mikstur!\n";
    }
    else if(gracz.potki==1){
        stats+="Posiadasz 1 miksturę\n";
    }
    else{
        stats+="Posiadasz "+QString::number(gracz.potki)+" mikstury";
    }
    ui->StatsText->setText(stats);
    ui->stackedWidget->setCurrentWidget(ui->Stats);
}

void MainWindow::on_TownShopButton_clicked()
{
    ButtonSound.play();
    PlayerIdleAnim->stop();
    CrowdSound.stop();
    ui->ShopCoinAmount->setText(QString::number(gracz.zloto));
    ui->stackedWidget->setCurrentWidget(ui->ShopEntrance);
}


void MainWindow::on_TownTavernButton_clicked()
{
    ButtonSound.play();
    PlayerIdleAnim->stop();
    CrowdSound.stop();
    ui->stackedWidget->setCurrentWidget(ui->Tavern);
}

void MainWindow::on_TavernYesButton_clicked()
{
    if(ui->TavernOutputText->text().compare("")){
        return;
    }
    if(gracz.hp==gracz.maxhp){
        ui->TavernOutputText->setText("Jesteś już w pełni uzdrowiony!");
    }
    else if(gracz.zloto<50){
        ui->TavernOutputText->setText("Nie masz wystarczająco dużo złota!");
    }
    else{
        gracz.hp=gracz.maxhp;
        gracz.zloto-=50;
        ui->TavernOutputText->setText("Zostałeś w pełni uzdrowiony!");
        PotionSound.play();
    }
    ui->TavernOutputText->update();
    qApp->processEvents();
    QSignalSpy spy(ui->TavernYesButton,SIGNAL(clicked()));
    spy.wait(1500);
    ui->TavernOutputText->setText("");
}

void MainWindow::on_TavernReturnButton_clicked()
{
    ButtonSound.play();
    ui->stackedWidget->setCurrentWidget(ui->Town);
    CrowdSound.play();
    PlayerIdleAnim->start();
}

void MainWindow::on_ShopSwordButton_clicked()
{
    ButtonSound.play();
    shop.item=1;
    ShopItemRender();
}

void MainWindow::on_ShopArmorButton_clicked()
{
    ButtonSound.play();
    shop.item=2;
    ShopItemRender();
}

void MainWindow::on_ShopPotionButton_clicked()
{
    ButtonSound.play();
    shop.item=3;
    ShopItemRender();
}

void MainWindow::on_ShopReturnButton_clicked()
{
    ButtonSound.play();
    ui->stackedWidget->setCurrentWidget(ui->Town);
    CrowdSound.play();
    PlayerIdleAnim->start();
}

void MainWindow::ShopItemRender(){
    ui->stackedWidget->setCurrentWidget(ui->ShopItem);
    QString desc;
    bool BuyButtonVisible;
    if(shop.item==1){
        if(gracz.pmiecza<4){
            desc+="Miecz poziomu "+QString::number(gracz.pmiecza+1)+"\n";
            desc+="Obrażenia: "+QString::number(gracz.minatak+2)+"-"+QString::number(gracz.maxatak+3)+"\n";
            desc+="Szansa na trafienie: "+QString::number(gracz.szansa-5)+"%\n";
            desc+="Czy chcesz go kupić za "+QString::number(shop.SwordCost)+" złota?";
            BuyButtonVisible=true;
        }
        else{
            desc+="Masz już maksymalny poziom miecza!";
            BuyButtonVisible=false;
        }
    }
    else if(shop.item==2){
        if(gracz.pzbroi<4){
            desc+="Zbroja poziomu "+QString::number(gracz.pzbroi+1)+"\n";
            desc+="Maksymalne zdrowie: "+QString::number(gracz.maxhp+10)+"\n";
            desc+="Czy chcesz ją kupić za "+QString::number(shop.ArmorCost)+" złota?";
            BuyButtonVisible=true;
        }
        else{
            desc+="Masz maksymalny poziom zbroi!";
            BuyButtonVisible=false;
        }
    }
    else{
        desc+="Mikstura lecząca odnawia około\n";
        desc+="50% twojego maksymalnego zdrowia.\n";
        desc+="Masz przy sobie "+QString::number(gracz.potki)+" mikstur.\n";
        if(gracz.potki<4){
            desc+="Czy chcesz ją kupić za 20 złota?";
            BuyButtonVisible=true;
        }
        else{
            desc+="Masz maksymalną ilość mikstur!";
            BuyButtonVisible=false;
        }
    }
    ui->ShopItemDescription->setText(desc);
    ui->ShopItemBuyButton->setEnabled(BuyButtonVisible);
    ui->ShopItemCoinAmount->setText(QString::number(gracz.zloto));
}

void MainWindow::on_ShopItemBuyButton_clicked()
{
    if(ui->ShopItemOutputText->text().compare("")){
        return;
    }
    QString desc;
    if(shop.item==1){
        if(gracz.zloto<shop.SwordCost){
            desc="Nie masz wystarczająco dużo złota!";
        }
        else{
            gracz.zloto-=shop.SwordCost;
            gracz.pmiecza+=1;
            gracz.minatak+=2;
            gracz.maxatak+=3;
            gracz.szansa-=5;
            shop.SwordCost=125*pow(2,gracz.pmiecza);
            desc="Kupiłeś miecz poziomu "+QString::number(gracz.pmiecza)+"!";
            PotionSound.play();
        }
    }
    else if(shop.item==2){
        if(gracz.zloto<shop.ArmorCost){
                desc="Nie masz wystarczająco dużo złota!";
        }
        else{
            gracz.zloto-=shop.ArmorCost;
            gracz.maxhp+=10;
            gracz.hp+=10;
            gracz.pzbroi+=1;
            shop.ArmorCost=125*pow(2,gracz.pzbroi);
            desc="Kupiłeś zbroję poziomu "+QString::number(gracz.pzbroi)+"!";
            PotionSound.play();
        }
    }
    else{
        if(gracz.zloto<20){
            desc="Nie masz wystarczająco dużo złota!";
        }
        else{
            gracz.potki++;
            gracz.zloto-=20;
            desc="Kupiłeś miksturę leczącą!";
            PotionSound.play();
        }
    }
    ui->ShopCoinAmount->setText(QString::number(gracz.zloto));
    ui->ShopItemOutputText->setText(desc);
    QSignalSpy spy(ui->ShopItemBuyButton,SIGNAL(clicked()));
    spy.wait(1500);
    ui->ShopItemOutputText->setText("");
    ShopItemRender();
}


void MainWindow::on_ShopItemReturnButton_clicked()
{
    if(ui->ShopItemOutputText->text().compare("")){
        ui->ShopItemBuyButton->click();
        return;
    }
    ui->ShopCoinAmount->setText(QString::number(gracz.zloto));
    ButtonSound.play();
    ui->stackedWidget->setCurrentWidget(ui->ShopEntrance);
}


void MainWindow::on_StatsReturnButton_clicked()
{
    ButtonSound.play();
    ui->stackedWidget->setCurrentWidget(ui->Town);
    CrowdSound.play();
    PlayerIdleAnim->start();
}

void MainWindow::on_TownArenaButton_clicked()
{
    ButtonSound.play();
    PlayerIdleAnim->stop();
    CrowdSound.stop();

    QString list="Dostępni przeciwnicy:\n";
        if(gracz.poziom<=2){
        list+="Przeciwnik normalny\n";
        list+="(Nagrody x1)\n";
        ui->ArenaEntranceNormalButton->setEnabled(true);
    }
    else{
        ui->ArenaEntranceNormalButton->setEnabled(false);
    }
    if(gracz.poziom>=2&&gracz.poziom<=3){
        list+="Przeciwnik trudny\n";
        list+="(Nagrody x3)\n";
        ui->ArenaEntranceHardButton->setEnabled(true);
    }
    else{
        ui->ArenaEntranceHardButton->setEnabled(false);
    }
    if(gracz.poziom>=3){
        list+="Boss\n";
        list+="(Ostateczny przeciwnik)\n";
        ui->ArenaEntranceBossButton->setEnabled(true);
    }
    else{
        ui->ArenaEntranceBossButton->setEnabled(false);
    }
    ui->ArenaEntranceEnemyList->setText(list);
    ui->stackedWidget->setCurrentWidget(ui->ArenaEntrance);
}

void MainWindow::on_ArenaEntranceReturnButton_clicked()
{
    ButtonSound.play();
    ui->stackedWidget->setCurrentWidget(ui->Town);
    CrowdSound.play();
    PlayerIdleAnim->start();
}

void MainWindow::on_ArenaEntranceNormalButton_clicked()
{
    enemy.trudnosc=1;
    GenerateEnemy();
    ButtonSound.play();
    ui->stackedWidget->setCurrentWidget(ui->ArenaStart);
    CrowdSound.setVolume(1);
    CrowdSound.play();
}

void MainWindow::on_ArenaEntranceHardButton_clicked()
{
    enemy.trudnosc=2;
    GenerateEnemy();
    ButtonSound.play();
    ui->stackedWidget->setCurrentWidget(ui->ArenaStart);
    CrowdSound.setVolume(1);
    CrowdSound.play();
}

void MainWindow::on_ArenaEntranceBossButton_clicked()
{
    enemy.trudnosc=3;
    GenerateEnemy();
    ButtonSound.play();
    ui->stackedWidget->setCurrentWidget(ui->ArenaStart);
    CrowdSound.setVolume(1);
    CrowdSound.play();
}

void MainWindow::GenerateEnemy(){
    switch(enemy.trudnosc){
        case 1:{
            enemy.hp=30+rand()%11;
            enemy.minatak=1+rand()%2;
            enemy.maxatak=7+rand()%3;
            enemy.potki=rand()%2;
            enemy.szansa=80+rand()%11;
            break;
        }
        case 2:{
            enemy.hp=80+rand()%21;
            enemy.minatak=8+rand()%3;
            enemy.maxatak=16+rand()%3;
            enemy.potki=rand()%3;
            enemy.szansa=70+rand()%11;
            break;
        }
        case 3:{
            enemy.hp=125;
            enemy.minatak=18;
            enemy.maxatak=28;
            enemy.potki=4;
            enemy.szansa=75;
            break;
        }
    }
    enemy.maxhp=enemy.hp;
    enemy.tura=rand()%2;
    QString info="Statystyki przeciwnika:\n";
    info+="Zdrowie: "+QString::number(enemy.hp)+"\n";
    info+="Obrażenia: "+QString::number(enemy.minatak)+"-"+QString::number(enemy.maxatak)+"\n";
    info+="Szansa na trafienie: "+QString::number(enemy.szansa)+"%\n";
    info+="Posiadane mikstury: "+QString::number(enemy.potki)+"\n";
    if(enemy.tura){
        info+="Rozpoczyna przeciwnik\n";
    }
    else{
        info+="Rozpoczyna gracz\n";
    }
    info+="Walcz!";
    ui->ArenaStartInfo->setText(info);
    if(gracz.hp==gracz.maxhp){
        ui->ArenaPlayerHPBar->setStyleSheet("QProgressBar\n{\n	background-color: transparent;\n	color: black;\n    border-style: ridge;\n	border-width: 4px;\n}\nQProgressBar::chunk\n{\n    background-color: red;\n    border-style: ridge;\n	border-right-width: 0px;\n    border-color: black;\n}");
    }
    else{
        ui->ArenaPlayerHPBar->setStyleSheet("QProgressBar\n{\n	background-color: transparent;\n	color: black;\n    border-style: ridge;\n	border-width: 4px;\n}\nQProgressBar::chunk\n{\n    background-color: red;\n    border-style: ridge;\n	border-right-width: 3px;\n    border-color: black;\n}");
    }
    if(enemy.hp==enemy.maxhp){
        ui->ArenaEnemyHPBar->setStyleSheet("QProgressBar\n{\n	background-color: transparent;\n	color: black;\n    border-style: ridge;\n	border-width: 4px;\n}\nQProgressBar::chunk\n{\n    background-color: red;\n    border-style: ridge;\n	border-right-width: 0px;\n    border-color: black;\n}");
    }
    else{
        ui->ArenaEnemyHPBar->setStyleSheet("QProgressBar\n{\n	background-color: transparent;\n	color: black;\n    border-style: ridge;\n	border-width: 4px;\n}\nQProgressBar::chunk\n{\n    background-color: red;\n    border-style: ridge;\n	border-right-width: 3px;\n    border-color: black;\n}");
    }
}

void MainWindow::on_ArenaStartButton_clicked()
{
    ButtonSound.play();

    ui->ArenaPlayerHPBar->setMaximum(gracz.maxhp);
    ui->ArenaPlayerHPBar->setValue(gracz.hp);
    ui->ArenaPlayerPotionNumber->setText(QString::number(gracz.potki));
    ui->ArenaEnemyHPBar->setMaximum(enemy.maxhp);
    ui->ArenaEnemyHPBar->setValue(enemy.hp);
    ui->ArenaEnemyPotionNumber->setText(QString::number(enemy.potki));

    ui->ArenaFastAttackAtk->setText(QString::number(ceil(gracz.minatak*0.8))+"-"+QString::number(ceil(gracz.maxatak*0.8)));
    if(gracz.szansa+20>=100){
        ui->ArenaFastAttackAcc->setText("100%");
    }
    else{
        ui->ArenaFastAttackAcc->setText("~"+QString::number(gracz.szansa+20)+"%");
    }

    ui->ArenaNormalAttackAtk->setText(QString::number(gracz.minatak)+"-"+QString::number(gracz.maxatak));
    if(gracz.szansa>=100){
        ui->ArenaNormalAttackAcc->setText("100%");
    }
    else{
        ui->ArenaNormalAttackAcc->setText("~"+QString::number(gracz.szansa)+"%");
    }

    ui->ArenaPowerAttackAtk->setText(QString::number(ceil(gracz.minatak*1.2))+"-"+QString::number(ceil(gracz.maxatak*1.2)));
    if(gracz.szansa-20>100){
        ui->ArenaPowerAttackAcc->setText("100%");
    }
    else{
        ui->ArenaPowerAttackAcc->setText("~"+QString::number(gracz.szansa-20)+"%");
    }

    ui->ArenaPotionButton->setEnabled(gracz.potki>0);
    PlayerIdleAnim->setSpeed(100);
    PlayerIdleAnim->jumpToFrame(rand()%4);
    PlayerIdleAnim->start();
    EnemyIdleAnim->jumpToFrame(rand()%4);
    EnemyIdleAnim->start();
    ui->stackedWidget->setCurrentWidget(ui->Arena);
    if(enemy.tura){
        ui->ArenaButtonsBox->setVisible(false);
        ui->ArenaButtonsBox->setEnabled(false);
        EnemyTurn();
    }
    else{
        ui->ArenaButtonsBox->setVisible(true);
        ui->ArenaButtonsBox->setEnabled(true);
    }
}

void MainWindow::EnemyTurn(){
    if((float)enemy.hp/enemy.maxhp<0.5&&enemy.potki>0&&rand()%5<=1){
        int leczenie=std::ceil((enemy.maxhp*(40+rand()%21))/100);
        if(leczenie>enemy.maxhp-enemy.hp){
            leczenie=enemy.maxhp-enemy.hp;
        }
        enemy.potki--;
        HandleHealing(leczenie);
    }
    else{
        int akcja=rand()%3;
        int moc_ataku;
        int szansa_ataku;
        if(akcja==0){
            moc_ataku=(50+rand()%21);
            szansa_ataku=(10+rand()%11);
        }
        else if(akcja==1){
            moc_ataku=1;
            szansa_ataku=0;
        }
        else{
            moc_ataku=(130+rand()%21);
            szansa_ataku=-(15+rand()%11);
        }
        float atak=std::ceil((moc_ataku*(enemy.minatak+rand()%(1+enemy.maxatak-enemy.minatak)))/100);
        if(enemy.szansa+szansa_ataku<rand()%101){
            atak=-1;
        }
        HandleAttack(atak);
    }
}

void MainWindow::on_ArenaFastAttackButton_clicked()
{
    int moc_ataku=50+rand()%21;
    int atak=std::ceil((moc_ataku*(gracz.minatak+rand()%(1+gracz.maxatak-gracz.minatak)))/100);
    if(gracz.szansa+15+rand()%11<rand()%101){
        atak=-1;
    }
    HandleAttack(atak);
}


void MainWindow::on_ArenaNormalAttackButton_clicked()
{
    int atak=gracz.minatak+rand()%(1+gracz.maxatak-gracz.minatak);
    if(gracz.szansa<rand()%101){
        atak=-1;
    }
    HandleAttack(atak);
}

void MainWindow::on_ArenaPowerAttackButton_clicked()
{
    int moc_ataku=130+rand()%21;
    int atak=std::ceil((moc_ataku*(gracz.minatak+rand()%(1+gracz.maxatak-gracz.minatak)))/100);
    if(gracz.szansa-(15+rand()%11)<rand()%101){
        atak=-1;
    }
    HandleAttack(atak);
}

void MainWindow::HandleAttack(int damage){
    if(rand()%2){
        Attack1Sound.play();
    }
    else{
        Attack2Sound.play();
    }
    if(enemy.tura){
        ui->ArenaEnemySprite->setMovie(EnemyAttackAnim);
        EnemyAttackAnim->start();
        if(damage>=0){
            PlayerHitAnim->start();
        }
        QSignalSpy spy(EnemyAttackAnim,SIGNAL(finished()));
        spy.wait();
        ui->ArenaEnemySprite->setMovie(EnemyIdleAnim);
        EnemyIdleAnim->start();
        if(damage>=0){
            gracz.hp-=damage;
            if(gracz.hp<0){
                gracz.hp=0;
            }
            if(gracz.hp==gracz.maxhp){
                ui->ArenaPlayerHPBar->setStyleSheet("QProgressBar\n{\n	background-color: transparent;\n	color: black;\n    border-style: ridge;\n	border-width: 4px;\n}\nQProgressBar::chunk\n{\n    background-color: red;\n    border-style: ridge;\n	border-right-width: 0px;\n    border-color: black;\n}");
            }
            else{
                ui->ArenaPlayerHPBar->setStyleSheet("QProgressBar\n{\n	background-color: transparent;\n	color: black;\n    border-style: ridge;\n	border-width: 4px;\n}\nQProgressBar::chunk\n{\n    background-color: red;\n    border-style: ridge;\n	border-right-width: 3px;\n    border-color: black;\n}");
            }
            ui->ArenaPlayerHPBar->setValue(gracz.hp);
            ui->ArenaPlayerHPChange->setText("-"+QString::number(damage));
        }
        else{
            ui->ArenaPlayerHPChange->setText("Chybiono!");
        }
        PlayerHPAnim->stop();
        ui->ArenaPlayerHPChange->setStyleSheet("QLabel { color: red; }");
        PlayerHPAnim->start();
        spy.wait(1000);
        if(gracz.hp==0){
            FightEnd();
            return;
        }
        enemy.tura=0;
        ui->ArenaButtonsBox->setVisible(true);
        ui->ArenaButtonsBox->setEnabled(true);
    }
    else{
        ui->ArenaButtonsBox->setVisible(false);
        ui->ArenaButtonsBox->setEnabled(false);
        ui->ArenaPlayerSprite->setMovie(PlayerAttackAnim);
        PlayerAttackAnim->start();
        if(damage>=0){
            EnemyHitAnim->start();
        }
        QSignalSpy spy(PlayerAttackAnim,SIGNAL(finished()));
        spy.wait();
        ui->ArenaPlayerSprite->setMovie(PlayerIdleAnim);
        PlayerIdleAnim->start();
        if(damage>=0){
            enemy.hp-=damage;
            if(enemy.hp<0){
                enemy.hp=0;
            }
            if(enemy.hp==enemy.maxhp){
                ui->ArenaEnemyHPBar->setStyleSheet("QProgressBar\n{\n	background-color: transparent;\n	color: black;\n    border-style: ridge;\n	border-width: 4px;\n}\nQProgressBar::chunk\n{\n    background-color: red;\n    border-style: ridge;\n	border-right-width: 0px;\n    border-color: black;\n}");
            }
            else{
                ui->ArenaEnemyHPBar->setStyleSheet("QProgressBar\n{\n	background-color: transparent;\n	color: black;\n    border-style: ridge;\n	border-width: 4px;\n}\nQProgressBar::chunk\n{\n    background-color: red;\n    border-style: ridge;\n	border-right-width: 3px;\n    border-color: black;\n}");
            }
            ui->ArenaEnemyHPBar->setValue(enemy.hp);
            ui->ArenaEnemyHPChange->setText("-"+QString::number(damage));
        }
        else{
            ui->ArenaEnemyHPChange->setText("Chybiono!");
        }
        EnemyHPAnim->stop();
        ui->ArenaEnemyHPChange->setStyleSheet("QLabel { color: red; }");
        EnemyHPAnim->start();
        spy.wait(1000);
        if(enemy.hp==0){
            FightEnd();
            return;
        }
        enemy.tura=1;
        EnemyTurn();
    }
}

void MainWindow::on_ArenaPotionButton_clicked()
{
    int leczenie=std::ceil((gracz.maxhp*(40+rand()%21))/100);
    if(leczenie>gracz.maxhp-gracz.hp){
        leczenie=gracz.maxhp-gracz.hp;
    }
    gracz.potki--;
    HandleHealing(leczenie);
}

void MainWindow::HandleHealing(int healing){
    if(enemy.tura){
        ui->ArenaEnemySprite->setMovie(EnemyHealAnim);
        EnemyHealAnim->start();
        QSignalSpy spy(EnemyHealAnim,SIGNAL(finished()));
        spy.wait();
        enemy.hp+=healing;
        ui->ArenaEnemyHPBar->setValue(enemy.hp);
        if(enemy.hp==enemy.maxhp){
            ui->ArenaEnemyHPBar->setStyleSheet("QProgressBar\n{\n	background-color: transparent;\n	color: black;\n    border-style: ridge;\n	border-width: 4px;\n}\nQProgressBar::chunk\n{\n    background-color: red;\n    border-style: ridge;\n	border-right-width: 0px;\n    border-color: black;\n}");
        }
        else{
            ui->ArenaEnemyHPBar->setStyleSheet("QProgressBar\n{\n	background-color: transparent;\n	color: black;\n    border-style: ridge;\n	border-width: 4px;\n}\nQProgressBar::chunk\n{\n    background-color: red;\n    border-style: ridge;\n	border-right-width: 3px;\n    border-color: black;\n}");
        }
        PotionSound.play();
        EnemyHPAnim->stop();
        ui->ArenaEnemyPotionNumber->setText(QString::number(enemy.potki));
        ui->ArenaEnemyHPChange->setText("+"+QString::number(healing));
        ui->ArenaEnemyHPChange->setStyleSheet("QLabel { color: green; }");
        EnemyHPAnim->start();
        QSignalSpy spy2(EnemyHPAnim,SIGNAL(finished()));
        spy2.wait(1500);
        ui->ArenaEnemySprite->setMovie(EnemyHealReturnAnim);
        EnemyHealReturnAnim->start();
        QSignalSpy spy3(EnemyHealReturnAnim,SIGNAL(finished()));
        spy3.wait();
        EnemyIdleAnim->jumpToFrame(rand()%3);
        EnemyIdleAnim->start();
        ui->ArenaEnemySprite->setMovie(EnemyIdleAnim);
        enemy.tura=0;
        ui->ArenaButtonsBox->setVisible(true);
        ui->ArenaButtonsBox->setEnabled(true);
    }
    else{
        ui->ArenaButtonsBox->setVisible(false);
        ui->ArenaButtonsBox->setEnabled(false);
        ui->ArenaPlayerSprite->setMovie(PlayerHealAnim);
        PlayerHealAnim->start();
        QSignalSpy spy(PlayerHealAnim,SIGNAL(finished()));
        spy.wait();
        gracz.hp+=healing;
        ui->ArenaPlayerHPBar->setValue(gracz.hp);
        ui->ArenaPotionButton->setEnabled(gracz.potki>0);
        if(gracz.hp==gracz.maxhp){
            ui->ArenaPlayerHPBar->setStyleSheet("QProgressBar\n{\n	background-color: transparent;\n	color: black;\n    border-style: ridge;\n	border-width: 4px;\n}\nQProgressBar::chunk\n{\n    background-color: red;\n    border-style: ridge;\n	border-right-width: 0px;\n    border-color: black;\n}");
        }
        else{
            ui->ArenaPlayerHPBar->setStyleSheet("QProgressBar\n{\n	background-color: transparent;\n	color: black;\n    border-style: ridge;\n	border-width: 4px;\n}\nQProgressBar::chunk\n{\n    background-color: red;\n    border-style: ridge;\n	border-right-width: 3px;\n    border-color: black;\n}");
        }
        PotionSound.play();
        PlayerHPAnim->stop();
        ui->ArenaPlayerPotionNumber->setText(QString::number(gracz.potki));
        ui->ArenaPlayerHPChange->setText("+"+QString::number(healing));
        ui->ArenaPlayerHPChange->setStyleSheet("QLabel { color: green; }");
        PlayerHPAnim->start();
        QSignalSpy spy2(PlayerHPAnim,SIGNAL(finished()));
        spy2.wait(1500);
        ui->ArenaPlayerSprite->setMovie(PlayerHealReturnAnim);
        PlayerHealReturnAnim->start();
        QSignalSpy spy3(PlayerHealReturnAnim,SIGNAL(finished()));
        spy3.wait();
        PlayerIdleAnim->jumpToFrame(rand()%3);
        PlayerIdleAnim->start();
        ui->ArenaPlayerSprite->setMovie(PlayerIdleAnim);
        enemy.tura=1;
        EnemyTurn();
    }
}

void MainWindow::FightEnd(){
    CrowdSound.setVolume(0.75);
    CrowdSound.stop();
    ui->stackedWidget->setCurrentWidget(ui->ArenaEnd);
    if(enemy.tura){
        ui->ArenaEndEnemySprite->setVisible(true);
        EnemyHealAnim->start();
        QSignalSpy spy(EnemyHealAnim,SIGNAL(finished()));
        spy.wait();
        EnemyHealAnim->jumpToFrame(3);
        ui->ArenaEndEnemySprite->setPixmap(EnemyHealAnim->currentPixmap());
        EnemyHealAnim->jumpToFrame(0);
        DefeatSound.play();
        ui->ArenaEndDefeat->setVisible(true);
        ui->ArenaEndDefeat->setEnabled(true);
    }
    else{
        ui->ArenaEndPlayerSprite->setVisible(true);
        PlayerHealAnim->start();
        QSignalSpy spy(PlayerHealAnim,SIGNAL(finished()));
        spy.wait();
        PlayerHealAnim->jumpToFrame(3);
        ui->ArenaEndPlayerSprite->setPixmap(PlayerHealAnim->currentPixmap());
        PlayerHealAnim->jumpToFrame(0);
        VictorySound.play();
        if(enemy.trudnosc==3){
            ui->ArenaEndFinish->setVisible(true);
            ui->ArenaEndFinish->setEnabled(true);
        }
        else{
            int mnoznik;
            if(enemy.trudnosc==2){
                mnoznik=3;
            }
            else{
                mnoznik=1;
            }
            int ZdobytyExp=mnoznik*(100+rand()%101);
            int ZdobyteZloto=mnoznik*(150+rand()%101);
            gracz.exp+=ZdobytyExp;
            gracz.zloto+=ZdobyteZloto;
            if(gracz.exp<gracz.lvlup){
                QString text="Wygrywasz!\n";
                text+="Otrzymujesz "+QString::number(ZdobytyExp)+" expa\n";
                text+="oraz "+QString::number(ZdobyteZloto)+" złota!\n";
                text+="Masz "+QString::number(gracz.exp)+" punktów doświadczenia.\n";
                text+="Brakuje ci "+QString::number(gracz.lvlup-gracz.exp)+" do poziomu "+QString::number(gracz.poziom+1);
                ui->ArenaEndVictoryText->setText(text);
                ui->ArenaEndVictory->setVisible(true);
                ui->ArenaEndVictory->setEnabled(true);
            }
            else{
                if(gracz.poziom==1){
                    gracz.lvlup=625;
                }
                else if(gracz.poziom==2){
                    gracz.lvlup=2125;
                }
                gracz.poziom++;
                gracz.maxhp+=10;
                gracz.hp=gracz.maxhp;
                gracz.exp=0;
                gracz.minatak+=2;
                gracz.maxatak+=2;
                QString text="Wygrywasz!\n";
                text+="Otrzymujesz "+QString::number(ZdobytyExp)+" expa oraz "+QString::number(ZdobyteZloto)+" złota!\n\n";
                text+="Gratulacje!\n";
                text+="Osiągnąłeś "+QString::number(gracz.poziom)+" poziom doświadczenia!\n";
                text+="Twoje maksymalne zdrowie wzrasta o 10!\n";
                text+="Aktualnie masz go "+QString::number(gracz.maxhp)+"!\n";
                text+="Twoje ataki zadają 2 punkty obrażeń\nwięcej! ";
                text+="Aktualnie "+QString::number(gracz.minatak)+"-"+QString::number(gracz.maxatak)+"!\n";
                text+="Zyskujesz na celności!\n";
                text+="Masz "+QString::number(gracz.szansa)+"% szans na trafienie!";
                ui->ArenaEndVictoryLvlupText->setText(text);
                ui->ArenaEndVictoryLvlup->setEnabled(true);
                ui->ArenaEndVictoryLvlup->setVisible(true);
            }
        }
    }
}

void MainWindow::on_ArenaEndDefeatResetButton_clicked()
{
    ButtonSound.play();
    gracz.hp=60;
    gracz.maxhp=60;
    gracz.zloto=20;
    gracz.poziom=1;
    gracz.exp=0;
    gracz.lvlup=125;
    gracz.potki=0;
    gracz.minatak=0;
    gracz.maxatak=7;
    gracz.pmiecza=0;
    gracz.pzbroi=0;
    gracz.szansa=100;
    shop.SwordCost=10;
    shop.ArmorCost=10;
    ui->stackedWidget->setCurrentWidget(ui->Start);
    ui->ArenaEndDefeat->setVisible(false);
    ui->ArenaEndDefeat->setEnabled(false);
    ui->ArenaEndEnemySprite->setVisible(false);
}


void MainWindow::on_ArenaEndDefeatExitButton_clicked()
{
    ButtonSound.play();
    QApplication::quit();
}


void MainWindow::on_ArenaEndFinishResetButton_clicked()
{
    ButtonSound.play();
    gracz.hp=60;
    gracz.maxhp=60;
    gracz.zloto=20;
    gracz.poziom=1;
    gracz.exp=0;
    gracz.lvlup=125;
    gracz.potki=0;
    gracz.minatak=0;
    gracz.maxatak=7;
    gracz.pmiecza=0;
    gracz.pzbroi=0;
    gracz.szansa=100;
    shop.SwordCost=10;
    shop.ArmorCost=10;
    ui->stackedWidget->setCurrentWidget(ui->Start);
    ui->ArenaEndFinish->setVisible(false);
    ui->ArenaEndFinish->setEnabled(false);
    ui->ArenaEndPlayerSprite->setVisible(false);
}


void MainWindow::on_ArenaEndFinishExitButton_clicked()
{
    ButtonSound.play();
    QApplication::quit();
}


void MainWindow::on_ArenaEndVictoryButton_clicked()
{
    ButtonSound.play();
    ui->stackedWidget->setCurrentWidget(ui->Town);
    CrowdSound.play();
    ui->ArenaEndVictory->setEnabled(false);
    ui->ArenaEndVictory->setVisible(false);
    ui->ArenaEndPlayerSprite->setVisible(false);
}


void MainWindow::on_ArenaEndVictoryLvlupButton_clicked()
{
    ButtonSound.play();
    ui->stackedWidget->setCurrentWidget(ui->Town);
    CrowdSound.play();
    ui->ArenaEndVictoryLvlup->setEnabled(false);
    ui->ArenaEndVictoryLvlup->setVisible(false);
    ui->ArenaEndPlayerSprite->setVisible(false);
}
