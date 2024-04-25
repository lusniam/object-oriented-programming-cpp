#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QMessageBox>
#include <QFile>
#include <QFileDialog>
#include <QDir>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    this->setWindowIcon(QPixmap(":/images/icon.png"));
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_CPUBox_currentIndexChanged(int index)
{
    switch(index){
        case 0:{
            CPU.price=699;
            CPU.tdp=89;
            break;
        }
        case 1:{
            CPU.price=1219;
            CPU.tdp=154;
            break;
        }
        case 2:{
            CPU.price=1539;
            CPU.tdp=181;
            break;
        }
        case 3:{
            CPU.price=1999;
            CPU.tdp=219;
            break;
        }
        case 4:{
            CPU.price=2079;
            CPU.tdp=253;
            break;
        }
        case 5:{
            CPU.price=2849;
            CPU.tdp=253;
            break;
        }
        case 6:{
            CPU.price=1099;
            CPU.tdp=65;
            break;
        }
        case 7:{
            CPU.price=1499;
            CPU.tdp=65;
            break;
        }
        case 8:{
            CPU.price=2249;
            CPU.tdp=120;
            break;
        }
        case 9:{
            CPU.price=1999;
            CPU.tdp=88;
            break;
        }
        case 10:{
            CPU.price=3599;
            CPU.tdp=162;
            break;
        }
    }
    ui->CPUPriceLabel->setText("+"+QString::number(CPU.price)+" zł");
}


void MainWindow::on_GPUBox_currentIndexChanged(int index)
{
    switch(index){
        case 0:{
            GPU.price=0;
            GPU.tdp=0;
            break;
        }
        case 1:{
            GPU.price=1699;
            GPU.tdp=200;
            break;
        }
        case 2:{
            GPU.price=2799;
            GPU.tdp=290;
            break;
        }
        case 3:{
            GPU.price=1949;
            GPU.tdp=160;
            break;
        }
        case 4:{
            GPU.price=3979;
            GPU.tdp=285;
            break;
        }
        case 5:{
            GPU.price=6199;
            GPU.tdp=320;
            break;
        }
        case 6:{
            GPU.price=7899;
            GPU.tdp=450;
            break;
        }
    }
    ui->GPUPriceLabel->setText("+"+QString::number(GPU.price)+" zł");
}


void MainWindow::on_MBBox_currentIndexChanged(int index)
{
    switch(index){
        case 0:{
            MB.price=599;
            break;
        }
        case 1:{
            MB.price=999;
            break;
        }
        case 2:{
            MB.price=1449;
            break;
        }
    }
    ui->MBPriceLabel->setText("+"+QString::number(MB.price)+" zł");
}

void MainWindow::on_RAMSlider_sliderPressed()
{
    if(ui->RAMValueLabel->text().toStdString().compare("-")==0){
        this->on_RAMSlider_actionTriggered();
    }
}

void MainWindow::on_RAMSlider_actionTriggered()
{
    std::string val;
    switch(ui->RAMSlider->sliderPosition()){
        case 0:{
            val="2 GB";
            RAM.price=35;
            RAM.tdp=3;
            break;
        }
        case 1:{
            val="4 GB";
            RAM.price=71;
            RAM.tdp=3;
            break;
        }
        case 2:{
            val="8 GB";
            RAM.price=85;
            RAM.tdp=3;
            break;
        }
        case 3:{
            val="16 GB";
            RAM.price=167;
            RAM.tdp=6;
            break;
        }
        case 4:{
            val="32 GB";
            RAM.price=339;
            RAM.tdp=12;
            break;
        }
    }
    ui->RAMValueLabel->setText(QString::fromStdString(val));
    ui->RAMPriceLabel->setText("+"+QString::number(RAM.price)+" zł");
}

void MainWindow::on_SSDSlider_sliderPressed()
{
    if(ui->SSDValueLabel->text().toStdString().compare("-")==0){
        this->on_SSDSlider_actionTriggered();
    }
}

void MainWindow::on_SSDSlider_actionTriggered()
{
    std::string val;
    SSD.tdp=10;
    switch(ui->SSDSlider->sliderPosition()){
        case 0:{
            val="Brak";
            SSD.price=0;
            SSD.tdp=0;
            break;
        }
        case 1:{
            val="120 GB";
            SSD.price=49;
            break;
        }
        case 2:{
            val="240 GB";
            SSD.price=62;
            break;
        }
        case 3:{
            val="480 GB";
            SSD.price=99;
            break;
        }
        case 4:{
            val="960 GB";
            SSD.price=189;
            break;
        }
        case 5:{
            val="2 TB";
            SSD.price=359;
            break;
        }
    }
    ui->SSDValueLabel->setText(QString::fromStdString(val));
    ui->SSDPriceLabel->setText("+"+QString::number(SSD.price)+" zł");
}

void MainWindow::on_HDDSlider_sliderPressed()
{
    if(ui->HDDValueLabel->text().toStdString().compare("-")==0){
        this->on_HDDSlider_actionTriggered();
    }
}

void MainWindow::on_HDDSlider_actionTriggered()
{
    std::string val;
    HDD.tdp=25;
    switch(ui->HDDSlider->sliderPosition()){
        case 0:{
            val="Brak";
            HDD.price=0;
            HDD.tdp=0;
            break;
        }
        case 1:{
            val="500 GB";
            HDD.price=72;
            break;
        }
        case 2:{
            val="1 TB";
            HDD.price=189;
            break;
        }
        case 3:{
            val="2 TB";
            HDD.price=245;
            break;
        }
        case 4:{
            val="4 TB";
            HDD.price=375;
            break;
        }
        case 5:{
            val="8 TB";
            HDD.price=639;
            break;
        }
    }
    ui->HDDValueLabel->setText(QString::fromStdString(val));
    ui->HDDPriceLabel->setText("+"+QString::number(HDD.price)+" zł");
}

void MainWindow::on_PSUSlider_sliderPressed()
{
    if(ui->PSUValueLabel->text().toStdString().compare("-")==0){
        this->on_PSUSlider_actionTriggered();
    }
}

void MainWindow::on_PSUSlider_actionTriggered()
{
    std::string val;
    switch(ui->PSUSlider->sliderPosition()){
        case 0:{
            val="450 W";
            PSU.price=159;
            break;
        }
        case 1:{
            val="550 W";
            PSU.price=199;
            break;
        }
        case 2:{
            val="650 W";
            PSU.price=269;
            break;
        }
        case 3:{
            val="750 W";
            PSU.price=339;
            break;
        }
        case 4:{
            val="850 W";
            PSU.price=479;
            break;
        }
        case 5:{
            val="1000 W";
            PSU.price=699;
            break;
        }
    }
    ui->PSUValueLabel->setText(QString::fromStdString(val));
    ui->PSUPriceLabel->setText("+"+QString::number(PSU.price)+" zł");
}


void MainWindow::on_CoolingBox_currentIndexChanged(int index)
{
    switch(index){
        case 0:{
            Cooling.price=0;
            break;
        }
        case 1:{
            Cooling.price=149;
            break;
        }
        case 2:{
            Cooling.price=599;
            break;
        }
    }
    ui->CoolingPriceLabel->setText("+"+QString::number(Cooling.price)+" zł");
}

void MainWindow::on_FanSlider_sliderPressed()
{
    if(ui->FanPriceLabel->text().toStdString().compare("-")==0){
        this->on_FanSlider_valueChanged(1);
    }
}

void MainWindow::on_FanSlider_valueChanged(int value)
{
    ui->FanNumberLabel->setText(QString::number(value));
    Fan.price=value*29;
    Fan.tdp=value*3;
    ui->FanPriceLabel->setText("+"+QString::number(Fan.price)+" zł");
}

void MainWindow::on_WifiCheck_stateChanged(int check)
{
    if(check){
        Wifi.price=149;
        Wifi.tdp=2;
    }
    else{
        Wifi.price=0;
        Wifi.tdp=0;
    }
    ui->WifiCheck->setText("+ "+QString::number(Wifi.price)+" zł");
}

void MainWindow::on_BtCheck_stateChanged(int check)
{
    if(check){
        Bt.price=59;
        Bt.tdp=2;
    }
    else{
        Bt.price=0;
        Bt.tdp=0;
    }
    ui->BtCheck->setText("+ "+QString::number(Bt.price)+" zł");
}


void MainWindow::on_DriveCheck_stateChanged(int arg1)
{
    if(arg1){
        Drive.price=44;
        Drive.tdp=30;
    }
    else{
        Drive.price=0;
        Drive.tdp=0;
    }
    ui->DriveCheck->setText("+ "+QString::number(Drive.price)+" zł");
}


void MainWindow::on_OSBox_currentIndexChanged(int index)
{
    switch(index){
        case 0:{
            OS.price=0;
            break;
        }
        case 1:{
            OS.price=549;
            break;
        }
        case 2:{
            OS.price=749;
            break;
        }
        case 3:{
            OS.price=599;
            break;
        }
        case 4:{
            OS.price=999;
            break;
        }
    }
    ui->OSPriceLabel->setText("+"+QString::number(OS.price)+" zł");
}


void MainWindow::on_actionNowa_konfiguracja_triggered()
{
    QMessageBox box;
    box.setWindowTitle("Czyszczenie konfiguracji");
    box.setWindowIcon(QPixmap(":/images/icon.png"));
    box.setIcon(QMessageBox::Question);
    box.setText("Czy chcesz wyczyścić aktualną konfigurację?");
    QAbstractButton* tak=box.addButton("Tak", QMessageBox::YesRole);
    box.addButton("Nie", QMessageBox::NoRole);
    box.exec();
    if(box.clickedButton()==tak){
        ui->CPUBox->setCurrentIndex(-1);
        ui->CPUPriceLabel->setText("-");
        ui->GPUBox->setCurrentIndex(-1);
        ui->GPUPriceLabel->setText("-");
        ui->MBBox->setCurrentIndex(-1);
        ui->MBPriceLabel->setText("-");
        ui->RAMSlider->setSliderPosition(-1);
        ui->RAMValueLabel->setText("-");
        ui->RAMPriceLabel->setText("-");
        ui->SSDSlider->setSliderPosition(-1);
        ui->SSDValueLabel->setText("-");
        ui->SSDPriceLabel->setText("-");
        ui->HDDSlider->setSliderPosition(-1);
        ui->HDDValueLabel->setText("-");
        ui->HDDPriceLabel->setText("-");
        ui->PSUSlider->setSliderPosition(-1);
        ui->PSUValueLabel->setText("-");
        ui->PSUPriceLabel->setText("-");
        ui->CaseButtonBlack->setAutoExclusive(false);
        ui->CaseButtonWhite->setAutoExclusive(false);
        ui->CaseButtonPurple->setAutoExclusive(false);
        ui->CaseButtonBlack->setChecked(false);
        ui->CaseButtonWhite->setChecked(false);
        ui->CaseButtonPurple->setChecked(false);
        ui->CaseButtonBlack->setAutoExclusive(true);
        ui->CaseButtonWhite->setAutoExclusive(true);
        ui->CaseButtonPurple->setAutoExclusive(true);
        ui->CoolingBox->setCurrentIndex(-1);
        ui->CoolingPriceLabel->setText("-");
        ui->FanSlider->setSliderPosition(-1);
        ui->FanNumberLabel->setText("-");
        ui->FanPriceLabel->setText("-");
        ui->WifiCheck->setChecked(false);
        ui->BtCheck->setChecked(false);
        ui->DriveCheck->setChecked(false);
        ui->OSBox->setCurrentIndex(-1);
        ui->OSPriceLabel->setText("-");
    }
}

void MainWindow::on_actionZapisz_konfiguracj_triggered()
{
    QString filename=QFileDialog::getSaveFileName(this,
        "Zapisz konfigurację",
        QDir::homePath()+QString::fromStdString("/Desktop/konf1.kpc"),
        "Plik konfiguracji PC (*.kpc)");
    if(filename.isEmpty())
        return;
    QFile file(filename);
    if(!file.open(QIODevice::WriteOnly | QIODevice::Text))
        return;
    QTextStream out(&file);
    std::string konf="";
    konf+=('a'+ui->CPUBox->currentIndex());
    konf+=('a'+ui->GPUBox->currentIndex());
    konf+=('a'+ui->MBBox->currentIndex());
    konf+=('a'+ui->RAMSlider->sliderPosition());
    konf+=('a'+ui->SSDSlider->sliderPosition());
    konf+=('a'+ui->HDDSlider->sliderPosition());
    konf+=('a'+ui->PSUSlider->sliderPosition());
    if(ui->CaseButtonBlack->isChecked())
        konf+='a';
    else if(ui->CaseButtonWhite->isChecked())
        konf+='b';
    else
        konf+='c';
    konf+=('a'+ui->CoolingBox->currentIndex());
    konf+=('a'+ui->FanSlider->sliderPosition());
    konf+=('a'+ui->WifiCheck->isChecked());
    konf+=('a'+ui->BtCheck->isChecked());
    konf+=('a'+ui->DriveCheck->isChecked());
    konf+=('a'+ui->OSBox->currentIndex());
    out<<QString::fromStdString(konf);
    file.close();
}


void MainWindow::on_actionWczytaj_konfiguracj_triggered()
{
    QString filename=QFileDialog::getOpenFileName(this,
        "Wczytaj konfigurację",
        QDir::homePath()+QString::fromStdString("/Desktop/konf1.kpc"),
        "Plik konfiguracji PC (*.kpc)");
    if(filename.isEmpty())
        return;
    QFile file(filename);
    if(!file.open(QIODevice::ReadOnly | QIODevice::Text))
        return;
    this->on_actionNowa_konfiguracja_triggered();
    QTextStream in(&file);
    std::string line = in.readLine().toStdString();
    file.close();
    ui->CPUBox->setCurrentIndex(line[0]-'a');
    ui->GPUBox->setCurrentIndex(line[1]-'a');
    ui->MBBox->setCurrentIndex(line[2]-'a');
    ui->RAMSlider->setSliderPosition(line[3]-'a');
    ui->SSDSlider->setSliderPosition(line[4]-'a');
    ui->HDDSlider->setSliderPosition(line[5]-'a');
    ui->PSUSlider->setSliderPosition(line[6]-'a');
    if(line[7]=='a')
        ui->CaseButtonBlack->setChecked(true);
    else if(line[7]=='b')
        ui->CaseButtonWhite->setChecked(true);
    else
        ui->CaseButtonPurple->setChecked(true);
    ui->CoolingBox->setCurrentIndex(line[8]-'a');
    ui->FanSlider->setSliderPosition(line[9]-'a');
    ui->WifiCheck->setChecked(line[10]-'a');
    ui->BtCheck->setChecked(line[11]-'a');
    ui->DriveCheck->setChecked(line[12]-'a');
    ui->OSBox->setCurrentIndex(line[13]-'a');
}

void MainWindow::on_actionAutor_triggered()
{
    QMessageBox::information(this,"Autor","Program wykonał Maciej Luśnia");
}


void MainWindow::on_actionWyj_cie_triggered()
{
    QMessageBox box;
    box.setWindowTitle("Wyłączanie");
    box.setWindowIcon(QPixmap(":/images/icon.png"));
    box.setIcon(QMessageBox::Question);
    box.setText("Zamknąć program?");
    QAbstractButton* tak=box.addButton("Tak", QMessageBox::YesRole);
    box.addButton("Nie", QMessageBox::NoRole);
    box.exec();
    if(box.clickedButton()==tak)
        QApplication::quit();
}

void MainWindow::on_SummaryButton_clicked()
{
    QString warn;
    if(ui->CPUPriceLabel->text()=="-"){
        QMessageBox::critical(this,"Błąd!","Nie wybrano procesora!");
        return;
    }
    if(ui->GPUPriceLabel->text()=="-"){
        QMessageBox::critical(this,"Błąd!","Nie wybrano karty graficznej!");
        return;
    }
    else if(ui->GPUBox->currentIndex()==0){
        warn+="Nie wybrano dedykowanej karty graficznej,\n";
    }
    if(ui->MBPriceLabel->text()=="-"){
        QMessageBox::critical(this,"Błąd!","Nie wybrano płyty głównej!");
        return;
    }
    if(ui->CPUBox->currentText().first(5)=="Intel"&&ui->MBBox->currentText().last(4)=="X670"){
        QMessageBox::critical(this,"Błąd!","Procesory Intela nie są kompatybilne z gniazdem AMD!");
        return;
    }
    if(ui->CPUBox->currentText().first(3)=="AMD"&&ui->MBBox->currentText().last(4)!="X670"){
        QMessageBox::critical(this,"Błąd!","Procesory AMD nie są kompatybilne z gniazdem Intela!");
        return;
    }
    if(ui->CPUBox->currentText().last(4)=="(OC)"&&ui->MBBox->currentText().last(4)!="(OC)"){
        warn+="Aby skorzystać z odblokowanego mnożnika procesora, należy dodać płytę główną, która umożliwia korzystanie z tej funkcjonalności (OC)\n";
    }
    if(ui->RAMPriceLabel->text()=="-"){
        QMessageBox::critical(this,"Błąd!","Nie wybrano pamięci RAM!");
        return;
    }
    if(ui->SSDSlider->sliderPosition()<=0){
        if(ui->HDDSlider->sliderPosition()<=0){
            if(ui->OSBox->currentIndex()<=0){
                warn+="Nie wybrano żadnego dysku,\n";
            }
            else{
                QMessageBox::critical(this,"Błąd!","Wybrano system operacyjny bez żadnego dysku!");
                return;
            }
        }
        else{
            if(ui->OSBox->currentIndex()<=0){
                warn+="Nie wybrano żadnego systemu operacyjnego\n";
            }
            else{
                warn+="Nie wybrano żadnego dysku SSD,\n";
                warn+="Zalecamy dobranie go aby przyśpieszyć działanie systemu,\n";
            }
        }
    }
    else if(ui->OSBox->currentIndex()<=0){
        warn+="Nie wybrano żadnego systemu operacyjnego,\n";
    }
    if(ui->PSUPriceLabel->text()=="-"){
        QMessageBox::critical(this,"Błąd!","Nie wybrano zasilacza!");
        return;
    }
    if(!(ui->CaseButtonBlack->isChecked()||ui->CaseButtonWhite->isChecked()||ui->CaseButtonPurple->isChecked())){
        QMessageBox::critical(this,"Błąd!","Nie wybrano koloru obudowy!");
        return;
    }
    if(ui->CoolingPriceLabel->text()=="-"){
        QMessageBox::critical(this,"Błąd!","Nie wybrano chłodzenia!");
        return;
    }
    if((ui->CPUBox->currentText().last(4)=="(OC)"||(
             ui->CPUBox->currentText().first(3)=="AMD"&&
             ui->CPUBox->currentText().last(3)=="X3D"
             ))&&ui->CoolingBox->currentIndex()<=0){
        QMessageBox::critical(this,"Błąd!","Wybrany procesor nie posiada chłodzenia producenta!");
        return;
    }
    if(ui->FanPriceLabel->text()=="-"){
        QMessageBox::critical(this,"Błąd!","Nie wybrano liczby wentylatorów w obudowie!");
        return;
    }
    if((ui->OSBox->currentIndex()==3||ui->OSBox->currentIndex()==4)&&ui->RAMSlider->sliderPosition()<1){
        QMessageBox::critical(this,"Błąd!","System Windows 11 wymaga minimum 4GB pamięci RAM!");
        return;
    }
    if(ui->CoolingBox->currentIndex()==2&&ui->FanSlider->sliderPosition()==1){
        QMessageBox::critical(this,"Błąd!","Chłodzenie wodne wymaga minimum 2 wentylatorów w obudowie!");
        return;
    }

    int tdp=CPU.tdp+GPU.tdp+RAM.tdp+SSD.tdp+HDD.tdp+Fan.tdp+Wifi.tdp+Bt.tdp+Drive.tdp;
    if(tdp>ui->PSUValueLabel->text().remove(" W").toInt()){
        QMessageBox::critical(this,"Błąd!","Wybrane podzespoły przewyższają możliwości zasilacza!\nProsimy wybrać mocniejszy zasilacz!");
        return;
    }
    else if(tdp+100>ui->PSUValueLabel->text().remove(" W").toInt()){
        warn+="Przy pełnym obciążeniu komputera zasilacz może nie być w stanie dostarczyć wystarczająco dużo mocy, zalecamy zmianę zasilacza";
    }

    if(warn!=""){
        QMessageBox::warning(this,"Uwagi",warn);
    }
    QString konf;
    konf+="Płyta główna: "+ui->MBBox->currentText()+"\n";
    konf+="Procesor: "+ui->CPUBox->currentText()+"\n";
    konf+="Pamięć RAM: "+ui->RAMValueLabel->text()+"\n";
    konf+="Karta graficzna: "+ui->GPUBox->currentText()+"\n";
    konf+="Dysk SSD: "+ui->SSDValueLabel->text()+"\n";
    konf+="Dysk HDD: "+ui->HDDValueLabel->text()+"\n";
    konf+="Zasilacz: "+ui->PSUValueLabel->text()+"\n";
    konf+="Łączność z Wi-fi: ";
    if(ui->WifiCheck->isChecked())
        konf+="tak\n";
    else
        konf+="nie\n";
    konf+="Łączność z  Bluetooth: ";
    if(ui->BtCheck->isChecked())
        konf+="tak\n";
    else
        konf+="nie\n";
    konf+="Napęd optyczny: ";
    if(ui->DriveCheck->isChecked())
        konf+="w zestawie\n";
    else
        konf+="brak\n";
    konf+="Chłodzenie: "+ui->CoolingBox->currentText().toLower()+"\n";
    konf+="Liczba wentylatorów w obudowie: "+QString::number(ui->FanSlider->sliderPosition())+"\n";
    konf+="System operacyjny: "+ui->OSBox->currentText()+"\n";
    konf+="\nCena za zestaw: "+QString::number(CPU.price+GPU.price+MB.price+RAM.price+SSD.price+HDD.price+PSU.price+Cooling.price+Fan.price+Wifi.price+Bt.price+Drive.price+OS.price)+" zł";

    QMessageBox summary;
    summary.setText(konf);
    summary.setWindowTitle("Podsumowanie");
    summary.setWindowIcon(QPixmap(":/images/icon.png"));
    summary.setStandardButtons(QMessageBox::Ok);
    if(ui->CaseButtonBlack->isChecked())
        summary.setIconPixmap(QPixmap(":/images/black.jpg"));
    else if(ui->CaseButtonPurple->isChecked())
        summary.setIconPixmap(QPixmap(":/images/purple.jpg"));
    else
        summary.setIconPixmap(QPixmap(":/images/white.jpg"));
    summary.show();
    summary.exec();
}

void MainWindow::on_TrojkatBox_currentIndexChanged(int index)
{
    if(index==0){
        ui->Bok1->setText("Pierwszy bok");
        ui->Bok2->setText("Drugi bok");
        ui->Bok3->setText("Trzeci bok");
        ui->Bok3Edit->setEnabled(true);
        ui->Bok3Edit->setVisible(true);
        ui->Bok3->setVisible(true);
    }
    else{
        ui->Bok1->setText("Podstawa");
        ui->Bok2->setText("Wysokosc");
        ui->Bok3->setText("");
        ui->Bok3Edit->setEnabled(false);
        ui->Bok3Edit->setVisible(false);
        ui->Bok3->setVisible(false);
    }
    ui->Bok1Edit->clear();
    ui->Bok2Edit->clear();
    ui->Bok3Edit->clear();
}


void MainWindow::on_Oblicz_clicked()
{
    double pole;
    if(ui->TrojkatBox->currentIndex()==0){
        double a=ui->Bok1Edit->text().toFloat();
        double b=ui->Bok2Edit->text().toFloat();
        double c=ui->Bok3Edit->text().toFloat();
        double p=(a+b+c)/2;
        pole=sqrt(p*(p-a)*(p-b)*(p-c));
    }
    else{
        pole=ui->Bok1Edit->text().toFloat()*ui->Bok2Edit->text().toFloat()/2;
    }
    ui->PoleEdit->setText(QString::number(pole));
}

