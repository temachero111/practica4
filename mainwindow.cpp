#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QPlainTextEdit> // Incluir la clase QPlainTextEdit para mostrar la información de las neuronas

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_Principio_clicked()
{
    // Obtener los datos de la neurona desde los campos de texto
    QString id = ui->data_ID->text();
    double voltaje = ui->data_VOLTAJE->text().toDouble();
    int posX = ui->POSICIONX->text().toInt();
    int posY = ui->POSICIONY->text().toInt();
    int red = ui->RED->text().toInt();
    int green = ui->GREEN->text().toInt();
    int blue = ui->BLUE->text().toInt();

    // Crear una nueva neurona con los datos proporcionados
    Neurona neurona(id, voltaje, posX, posY, red, green, blue);

    // Agregar la neurona al principio de la lista en la clase administradora
    administradora.agregarInicio(neurona);

    ui->RESULTADO->setPlainText("Se guardó la neurona al principio.");
}

void MainWindow::on_Final_clicked()
{
    // Obtener los datos de la neurona desde los campos de texto
    QString id = ui->data_ID->text();
    double voltaje = ui->data_VOLTAJE->text().toDouble();
    int posX = ui->POSICIONX->text().toInt();
    int posY = ui->POSICIONY->text().toInt();
    int red = ui->RED->text().toInt();
    int green = ui->GREEN->text().toInt();
    int blue = ui->BLUE->text().toInt();

    // Crear una nueva neurona con los datos proporcionados
    Neurona neurona(id, voltaje, posX, posY, red, green, blue);

    // Agregar la neurona al final de la lista en la clase administradora
    administradora.agregarFinal(neurona);

    ui->RESULTADO->setPlainText("Se guardó la neurona al final.");
}

void MainWindow::on_Muestra_clicked()
{
    // Obtener la información de todas las neuronas en la clase administradora
    std::vector<Neurona> neuronas = administradora.obtenerNeuronas();

    // Mostrar la información de todas las neuronas en el QPlainTextEdit
    QString texto;
    for(const auto& neurona : neuronas) {
        texto += "ID: " + neurona.getID() +"\n";
        texto += "Voltaje: " + QString::number(neurona.getVoltaje()) + "\n";
        texto += "Posicion en X: " + QString::number(neurona.getPosX()) + "\n";
        texto += "Posicion en Y: " + QString::number(neurona.getPosY()) + "\n";
        texto += "Red: " + QString::number(neurona.getRed()) + "\n";
        texto += "Green : " + QString::number(neurona.getGreen()) + "\n";
        texto += "Blue : " + QString::number(neurona.getBlue()) + "\n";
        texto += "\n";

        // Agregar más información según los campos de la neurona
    }
    ui->RESULTADO->setPlainText(texto);


}

void MainWindow::on_Guardar_clicked()
{
    // Obtener la información de todas las neuronas en la clase administradora
    std::vector<Neurona> neuronas = administradora.obtenerNeuronas();

    // Mostrar la información de todas las neuronas en el QPlainTextEdit
    QString texto;
    for(const auto& neurona : neuronas) {
        texto += "ID: " + neurona.getID() +"\n";
        texto += "Voltaje: " + QString::number(neurona.getVoltaje()) + "\n";
        texto += "Posicion en X: " + QString::number(neurona.getPosX()) + "\n";
        texto += "Posicion en Y: " + QString::number(neurona.getPosY()) + "\n";
        texto += "Red: " + QString::number(neurona.getRed()) + "\n";
        texto += "Green : " + QString::number(neurona.getGreen()) + "\n";
        texto += "Blue : " + QString::number(neurona.getBlue()) + "\n";
        texto += "\n";

        // Agregar más información según los campos de la neurona
    }

    QString rutaArchivo = QFileDialog::getSaveFileName(this, tr("Guardar archivo"), "C:/Users/josue/OneDrive/Documentos/pruebas", tr("Archivos de texto (*.txt);;Todos los archivos (*)"));
    if (!rutaArchivo.isEmpty()) {
        QFile archivo(rutaArchivo);
        if (archivo.open(QIODevice::WriteOnly | QIODevice::Text)) {
            QTextStream out(&archivo);
            out << texto;
            archivo.close();
        } else {
            ui->RESULTADO->setPlainText("");
            // Manejar errores al abrir el archivo
        }
    }
}


void MainWindow::on_Recuperar_clicked()
{
    QString rutaArchivo = QFileDialog::getOpenFileName(this, tr("Abrir archivo"), "C:/Users/josue/OneDrive/Documentos/pruebas", tr("Archivos de texto (*.txt);;Todos los archivos (*)"));
    if (!rutaArchivo.isEmpty()) {
        QFile archivo(rutaArchivo);
        if (archivo.open(QIODevice::ReadOnly | QIODevice::Text)) {
            QTextStream in(&archivo);
            QString contenido = in.readAll();
            ui->RESULTADO->setPlainText(contenido);
            archivo.close();
        } else {
            qDebug() << "Error al abrir el archivo para lectura:" << archivo.errorString();
            // Manejar errores al abrir el archivo
        }
    }
}

