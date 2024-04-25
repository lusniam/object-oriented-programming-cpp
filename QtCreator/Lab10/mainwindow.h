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
    void on_oblicz_clicked();
    void on_AutorCheckBox_clicked();

    void on_Data_clicked(const QDate &date);

    void on_NrTelBar_actionTriggered();

    void on_NotesButton_clicked();

    void on_Sum1Button_clicked();

    void on_Sum1Button2_clicked();

    void on_Sum2Button_clicked();

    void on_NotesButtonClear_clicked();

    void on_NotesButtonWrite_clicked();

    void on_NotesButtonRead_clicked();

    void on_WindowColorButtonRed_clicked();

    void on_WindowColorButtonGreen_clicked();

    void on_WindowColorButtonGray_clicked();

    void on_actionPokaz_triggered();

    void on_actionUkryj_triggered();

    void on_actionKopiuj_triggered();

    void on_actionWytnij_triggered();

    void on_actionWklej_triggered();

    void on_actionk1_triggered();

    void on_actionk2_triggered();

    void on_actionAutor_triggered();

    void on_actionWy_czanie_triggered();

    void on_actionTestK_triggered();

private:
    Ui::MainWindow *ui;
};
#endif // MAINWINDOW_H
