#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QFileDialog>
#include <QMainWindow>
#include "administradora.h" // Incluir la clase administradora de neuronas

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
    void on_Principio_clicked();
    void on_Final_clicked();
    void on_Muestra_clicked();

    void on_Guardar_clicked();

    void on_Recuperar_clicked();

private:
    Ui::MainWindow *ui;
    Administradora administradora; // Instancia de la clase administradora de neuronas
};
#endif // MAINWINDOW_H
