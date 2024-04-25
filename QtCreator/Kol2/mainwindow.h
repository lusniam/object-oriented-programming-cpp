#ifndef PART_H
#define PART_H

class Part{
public:
    Part(){
        price=0;
        tdp=0;
    }
    int price;
    int tdp;
};

#endif

#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void on_CPUBox_currentIndexChanged(int index);

    void on_GPUBox_currentIndexChanged(int index);

    void on_MBBox_currentIndexChanged(int index);

    void on_RAMSlider_actionTriggered();

    void on_SSDSlider_actionTriggered();

    void on_HDDSlider_actionTriggered();

    void on_PSUSlider_actionTriggered();

    void on_CoolingBox_currentIndexChanged(int index);

    void on_RAMSlider_sliderPressed();

    void on_SSDSlider_sliderPressed();

    void on_HDDSlider_sliderPressed();

    void on_PSUSlider_sliderPressed();

    void on_actionAutor_triggered();

    void on_actionWyj_cie_triggered();

    void on_FanSlider_sliderPressed();

    void on_FanSlider_valueChanged(int value);

    void on_WifiCheck_stateChanged(int arg1);

    void on_BtCheck_stateChanged(int arg1);

    void on_DriveCheck_stateChanged(int arg1);

    void on_OSBox_currentIndexChanged(int index);

    void on_actionNowa_konfiguracja_triggered();

    void on_actionZapisz_konfiguracj_triggered();

    void on_actionWczytaj_konfiguracj_triggered();

    void on_SummaryButton_clicked();

    void on_TrojkatBox_currentIndexChanged(int index);

    void on_Oblicz_clicked();

private:
    Ui::MainWindow *ui;
    Part CPU;
    Part GPU;
    Part MB;
    Part RAM;
    Part SSD;
    Part HDD;
    Part PSU;
    Part Cooling;
    Part Fan;
    Part Wifi;
    Part Bt;
    Part Drive;
    Part OS;
};
#endif // MAINWINDOW_H
