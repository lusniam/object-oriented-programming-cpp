#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QString>
#include <QDebug>
#include <QTextStream>
#include <QFile>
#include <QMessageBox>


MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    this->on_actionUkryj_triggered();
    ui->a->setValidator(new QRegularExpressionValidator(QRegularExpression("[0-9]*")));
    ui->b->setValidator(new QRegularExpressionValidator(QRegularExpression("[0-9]*")));
}

MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::on_oblicz_clicked()
{
    float wyn=0;
    switch(ui->operacja->currentIndex()){
        case 0:{
            wyn=ui->a->text().toFloat()+ui->b->text().toFloat();
            break;
        }
        case 1:{
            wyn=ui->a->text().toFloat()-ui->b->text().toFloat();
            break;
        }
        case 2:{
            wyn=ui->a->text().toFloat()*ui->b->text().toFloat();
            break;
        }
        case 3:{
            if(ui->b->text().toFloat()==0){
                ui->wynik->setText("Błąd dzielenia przez 0!");
                return;
            }
            wyn=ui->a->text().toFloat()/ui->b->text().toFloat();
            break;
        }
        case 4:{
            wyn=pow(ui->a->text().toFloat(),ui->b->text().toFloat());
            break;
        }
    }
    ui->wynik->setText(QString::number(wyn));
}

void MainWindow::on_AutorCheckBox_clicked()
{
    if(ui->AutorCheckBox->checkState()==Qt::Checked)
        ui->Autor->setText("Maciej Luśnia");
    else
        ui->Autor->setText("???");
}


void MainWindow::on_Data_clicked(const QDate &date)
{
    ui->DataLabel->setText(date.toString());
}


void MainWindow::on_NrTelBar_actionTriggered()
{
    ui->NrTelLabel->setText(QString::number(ui->NrTelBar->value()));
}


void MainWindow::on_NotesButton_clicked()
{
    ui->Notes->append(ui->NotesLine->text());
}


void MainWindow::on_Sum1Button_clicked()
{
    ui->Sum1List->addItem(ui->Sum1Line->text());
    ui->Sum1Count->setText(QString::number(ui->Sum1List->count()));
    ui->Sum1Sum->setText(QString::number(ui->Sum1Sum->text().toFloat()+ui->Sum1Line->text().toFloat()));
    ui->Sum1Line->clear();
}


void MainWindow::on_Sum1Button2_clicked()
{
    ui->Sum1List->clear();
    ui->Sum1Count->setText(QString::number(0));
    ui->Sum1Sum->setText(QString::number(0));
}


void MainWindow::on_Sum2Button_clicked()
{
    ui->Sum1List->addItem(QString::number(ui->Sum2Box->value()));
    ui->Sum1Count->setText(QString::number(ui->Sum1List->count()));
    ui->Sum1Sum->setText(QString::number(ui->Sum1Sum->text().toFloat()+ui->Sum2Box->value()));
    ui->Sum1Line->clear();
}


void MainWindow::on_NotesButtonWrite_clicked()
{
    QString filename = "notes.txt";
    QFile file(filename);
    if(!file.open(QFile::WriteOnly | QFile::Text)){
        qDebug() << " Could not open file for writing";
        return;
    }
    QTextStream out(&file);
    out<<ui->Notes->toPlainText();
    file.flush();
    file.close();
}


void MainWindow::on_NotesButtonRead_clicked()
{
    QString filename = "notes.txt";
    QFile file(filename);
    if(!file.open(QFile::ReadOnly | QFile::Text)){
        qDebug() << " Could not open the file for reading";
        return;
    }
    QTextStream in(&file);
    while(!in.atEnd()){
        QString line = in.readLine();
        ui->Notes->append(line);}
    file.close();
}


void MainWindow::on_NotesButtonClear_clicked()
{
    ui->Notes->clear();
}


void MainWindow::on_WindowColorButtonRed_clicked()
{
    MainWindow::setStyleSheet("background-color: red");
}


void MainWindow::on_WindowColorButtonGreen_clicked()
{
    MainWindow::setStyleSheet("background-color: green");
}


void MainWindow::on_WindowColorButtonGray_clicked()
{
    MainWindow::setStyleSheet("background-color: gray");
}


void MainWindow::on_actionPokaz_triggered()
{
    ui->KalkLabel->setVisible(true);
    ui->a->setVisible(true);
    ui->operacja->setVisible(true);
    ui->b->setVisible(true);
    ui->oblicz->setVisible(true);
    ui->wynik->setVisible(true);
}


void MainWindow::on_actionUkryj_triggered()
{
    ui->KalkLabel->setVisible(false);
    ui->a->setVisible(false);
    ui->operacja->setVisible(false);
    ui->b->setVisible(false);
    ui->oblicz->setVisible(false);
    ui->wynik->setVisible(false);
}


void MainWindow::on_actionKopiuj_triggered()
{
    ui->Notes->selectAll();
    ui->Notes->copy();
}


void MainWindow::on_actionWytnij_triggered()
{
    ui->Notes->selectAll();
    ui->Notes->cut();
}


void MainWindow::on_actionWklej_triggered()
{
    ui->Notes->paste();
}


void MainWindow::on_actionk1_triggered()
{
    QMessageBox::information(this,"Komunikat 1","informacja");
}


void MainWindow::on_actionk2_triggered()
{
    QMessageBox::warning(this,"Komunikat 1","ostrzezenie",
        QMessageBox::Yes | QMessageBox::No | QMessageBox::Cancel,
        QMessageBox::Yes);
}


void MainWindow::on_actionAutor_triggered()
{
    QMessageBox::information(this,"Autor","Zadanie na lab 10 wykonał Maciej Luśnia");
}


void MainWindow::on_actionWy_czanie_triggered()
{
    if(QMessageBox::question(this,"Wyłączanie","Zamknąć program?",
        QMessageBox::Yes | QMessageBox::No,
        QMessageBox::No)==QMessageBox::Yes)
        QApplication::quit();
}


void MainWindow::on_actionTestK_triggered()
{
    QMessageBox::critical(this,"BŁĄD!","Ten komunikat nie został jeszcze zaprogramowany!",
    QMessageBox::Ok);
}

