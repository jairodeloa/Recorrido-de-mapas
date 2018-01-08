#include "principal.h"
#include "ui_principal.h"
#include <QMessageBox>
#include <QRegExp>
#include <QValidator>
#include <fstream>
#include <QFileDialog>
#include <QDebug>
#include "mainwindow.h"
principal::principal(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::principal)
{
    ui->setupUi(this);
}

principal::~principal()
{
    delete ui;
}

void principal::cargar_valores(string nombre_archivo)
{
    int valor;
    char comma;
    ifstream archivo(nombre_archivo.c_str());

    if(!archivo.is_open()){
        QMessageBox msg;
        msg.setText("Error al abrir el archivo");
        msg.exec();
        ui->lineEdit->setText("");
    }
    else{
        int i=0,j=0;
        while(!archivo.eof()){
            if(archivo.eof())break;
            archivo >> valor;
            if(j!=14){
            archivo >> comma;
            }
            if(repetidos.size()==0){
                repetidos.push_back(valor);
            }
            else{
                int bandera=0;
                for(unsigned int g=0; g<repetidos.size(); g++){
                    if(valor==repetidos[g]){
                        bandera=1;
                    }
                }
                if(bandera==0){
                    repetidos.push_back(valor);
                }
            }
            valores[i][j]=valor;
            if(j==14){
                i++;
                j=-1;
            }
            j++;
        }
        checar_repetidos();
        generar_linedits_terrenos();
        ui->lineEdit->setDisabled(true);
        ui->pb_cargarValores->setDisabled(true);
        ui->pb_buscar->setDisabled(true);
    }
}

void principal::checar_repetidos()
{
    //burbuja;

    QMessageBox mse;
    mse.setText("Se detectaron: "+QString::number(repetidos.size()));
    mse.exec();

    for(unsigned int i=1;i<repetidos.size();i++)
    {
        for(unsigned int j=0;j<repetidos.size()-i;j++)
        {
            if(repetidos[j]>repetidos[j+1])
            {int k=repetidos[j+1]; repetidos[j+1]=repetidos[j]; repetidos[j]=k;}
        }
    }
}

void principal::generar_linedits_terrenos()
{
    switch(repetidos.size()){
    case 1:
        ui->lb_val->setText(QString::number(repetidos[0]));
        ui->le_terreno->setEnabled(true);
        ui->cb_terreo->setEnabled(true);
        break;
    case 2:
        ui->lb_val->setText(QString::number(repetidos[0]));
        ui->le_terreno->setEnabled(true);
        ui->cb_terreo->setEnabled(true);
        ui->lb_val_2->setText(QString::number(repetidos[1]));
        ui->le_terreno_2->setEnabled(true);
        ui->cb_terreo_2->setEnabled(true);
        break;
    case 3:
        ui->lb_val->setText(QString::number(repetidos[0]));
        ui->le_terreno->setEnabled(true);
        ui->cb_terreo->setEnabled(true);
        ui->lb_val_2->setText(QString::number(repetidos[1]));
        ui->le_terreno_2->setEnabled(true);
        ui->cb_terreo_2->setEnabled(true);
        ui->lb_val_3->setText(QString::number(repetidos[2]));
        ui->le_terreno_3->setEnabled(true);
        ui->cb_terreo_3->setEnabled(true);
        break;
    case 4:
        ui->lb_val->setText(QString::number(repetidos[0]));
        ui->le_terreno->setEnabled(true);
        ui->cb_terreo->setEnabled(true);
        ui->lb_val_2->setText(QString::number(repetidos[1]));
        ui->le_terreno_2->setEnabled(true);
        ui->cb_terreo_2->setEnabled(true);
        ui->lb_val_3->setText(QString::number(repetidos[2]));
        ui->le_terreno_3->setEnabled(true);
        ui->cb_terreo_3->setEnabled(true);
        ui->lb_val_4->setText(QString::number(repetidos[3]));
        ui->le_terreno_4->setEnabled(true);
        ui->cb_terreo_4->setEnabled(true);
        break;
    case 5:
        ui->lb_val->setText(QString::number(repetidos[0]));
        ui->le_terreno->setEnabled(true);
        ui->cb_terreo->setEnabled(true);
        ui->lb_val_2->setText(QString::number(repetidos[1]));
        ui->le_terreno_2->setEnabled(true);
        ui->cb_terreo_2->setEnabled(true);
        ui->lb_val_3->setText(QString::number(repetidos[2]));
        ui->le_terreno_3->setEnabled(true);
        ui->cb_terreo_3->setEnabled(true);
        ui->lb_val_4->setText(QString::number(repetidos[3]));
        ui->le_terreno_4->setEnabled(true);
        ui->cb_terreo_4->setEnabled(true);
        ui->lb_val_5->setText(QString::number(repetidos[4]));
        ui->le_terreno_5->setEnabled(true);
        ui->cb_terreo_5->setEnabled(true);
        break;
    case 6:
        ui->lb_val->setText(QString::number(repetidos[0]));
        ui->le_terreno->setEnabled(true);
        ui->cb_terreo->setEnabled(true);
        ui->lb_val_2->setText(QString::number(repetidos[1]));
        ui->le_terreno_2->setEnabled(true);
        ui->cb_terreo_2->setEnabled(true);
        ui->lb_val_3->setText(QString::number(repetidos[2]));
        ui->le_terreno_3->setEnabled(true);
        ui->cb_terreo_3->setEnabled(true);
        ui->lb_val_4->setText(QString::number(repetidos[3]));
        ui->le_terreno_4->setEnabled(true);
        ui->cb_terreo_4->setEnabled(true);
        ui->lb_val_5->setText(QString::number(repetidos[4]));
        ui->le_terreno_5->setEnabled(true);
        ui->cb_terreo_5->setEnabled(true);
        ui->lb_val_6->setText(QString::number(repetidos[5]));
        ui->le_terreno_6->setEnabled(true);
        ui->cb_terreo_6->setEnabled(true);
        break;
    case 7:
        ui->lb_val->setText(QString::number(repetidos[0]));
        ui->le_terreno->setEnabled(true);
        ui->cb_terreo->setEnabled(true);
        ui->lb_val_2->setText(QString::number(repetidos[1]));
        ui->le_terreno_2->setEnabled(true);
        ui->cb_terreo_2->setEnabled(true);
        ui->lb_val_3->setText(QString::number(repetidos[2]));
        ui->le_terreno_3->setEnabled(true);
        ui->cb_terreo_3->setEnabled(true);
        ui->lb_val_4->setText(QString::number(repetidos[3]));
        ui->le_terreno_4->setEnabled(true);
        ui->cb_terreo_4->setEnabled(true);
        ui->lb_val_5->setText(QString::number(repetidos[4]));
        ui->le_terreno_5->setEnabled(true);
        ui->cb_terreo_5->setEnabled(true);
        ui->lb_val_6->setText(QString::number(repetidos[5]));
        ui->le_terreno_6->setEnabled(true);
        ui->cb_terreo_6->setEnabled(true);
        ui->lb_val_7->setText(QString::number(repetidos[6]));
        ui->le_terreno_7->setEnabled(true);
        ui->cb_terreo_7->setEnabled(true);
        break;
    case 8:
        ui->lb_val->setText(QString::number(repetidos[0]));
        ui->le_terreno->setEnabled(true);
        ui->cb_terreo->setEnabled(true);
        ui->lb_val_2->setText(QString::number(repetidos[1]));
        ui->le_terreno_2->setEnabled(true);
        ui->cb_terreo_2->setEnabled(true);
        ui->lb_val_3->setText(QString::number(repetidos[2]));
        ui->le_terreno_3->setEnabled(true);
        ui->cb_terreo_3->setEnabled(true);
        ui->lb_val_4->setText(QString::number(repetidos[3]));
        ui->le_terreno_4->setEnabled(true);
        ui->cb_terreo_4->setEnabled(true);
        ui->lb_val_5->setText(QString::number(repetidos[4]));
        ui->le_terreno_5->setEnabled(true);
        ui->cb_terreo_5->setEnabled(true);
        ui->lb_val_6->setText(QString::number(repetidos[5]));
        ui->le_terreno_6->setEnabled(true);
        ui->cb_terreo_6->setEnabled(true);
        ui->lb_val_7->setText(QString::number(repetidos[6]));
        ui->le_terreno_7->setEnabled(true);
        ui->cb_terreo_7->setEnabled(true);
        ui->lb_val_8->setText(QString::number(repetidos[7]));
        ui->le_terreno_8->setEnabled(true);
        ui->cb_terreo_8->setEnabled(true);
        break;
    case 9:
        ui->lb_val->setText(QString::number(repetidos[0]));
        ui->le_terreno->setEnabled(true);
        ui->cb_terreo->setEnabled(true);
        ui->lb_val_2->setText(QString::number(repetidos[1]));
        ui->le_terreno_2->setEnabled(true);
        ui->cb_terreo_2->setEnabled(true);
        ui->lb_val_3->setText(QString::number(repetidos[2]));
        ui->le_terreno_3->setEnabled(true);
        ui->cb_terreo_3->setEnabled(true);
        ui->lb_val_4->setText(QString::number(repetidos[3]));
        ui->le_terreno_4->setEnabled(true);
        ui->cb_terreo_4->setEnabled(true);
        ui->lb_val_5->setText(QString::number(repetidos[4]));
        ui->le_terreno_5->setEnabled(true);
        ui->cb_terreo_5->setEnabled(true);
        ui->lb_val_6->setText(QString::number(repetidos[5]));
        ui->le_terreno_6->setEnabled(true);
        ui->cb_terreo_6->setEnabled(true);
        ui->lb_val_7->setText(QString::number(repetidos[6]));
        ui->le_terreno_7->setEnabled(true);
        ui->cb_terreo_7->setEnabled(true);
        ui->lb_val_8->setText(QString::number(repetidos[7]));
        ui->le_terreno_8->setEnabled(true);
        ui->cb_terreo_8->setEnabled(true);
        ui->lb_val_9->setText(QString::number(repetidos[8]));
        ui->le_terreno_9->setEnabled(true);
        ui->cb_terreo_9->setEnabled(true);
        break;
    case 10:
        ui->lb_val->setText(QString::number(repetidos[0]));
        ui->le_terreno->setEnabled(true);
        ui->cb_terreo->setEnabled(true);
        ui->lb_val_2->setText(QString::number(repetidos[1]));
        ui->le_terreno_2->setEnabled(true);
        ui->cb_terreo_2->setEnabled(true);
        ui->lb_val_3->setText(QString::number(repetidos[2]));
        ui->le_terreno_3->setEnabled(true);
        ui->cb_terreo_3->setEnabled(true);
        ui->lb_val_4->setText(QString::number(repetidos[3]));
        ui->le_terreno_4->setEnabled(true);
        ui->cb_terreo_4->setEnabled(true);
        ui->lb_val_5->setText(QString::number(repetidos[4]));
        ui->le_terreno_5->setEnabled(true);
        ui->cb_terreo_5->setEnabled(true);
        ui->lb_val_6->setText(QString::number(repetidos[5]));
        ui->le_terreno_6->setEnabled(true);
        ui->cb_terreo_6->setEnabled(true);
        ui->lb_val_7->setText(QString::number(repetidos[6]));
        ui->le_terreno_7->setEnabled(true);
        ui->cb_terreo_7->setEnabled(true);
        ui->lb_val_8->setText(QString::number(repetidos[7]));
        ui->le_terreno_8->setEnabled(true);
        ui->cb_terreo_8->setEnabled(true);
        ui->lb_val_9->setText(QString::number(repetidos[8]));
        ui->le_terreno_9->setEnabled(true);
        ui->cb_terreo_9->setEnabled(true);
        ui->lb_val_10->setText(QString::number(repetidos[9]));
        ui->le_terreno_10->setEnabled(true);
        ui->cb_terreo_10->setEnabled(true);
        break;

    }
}

void principal::desactivar_lineedit_terrenos()
{
    terreno t;
    switch(repetidos.size()){
    case 1:
        if(ui->le_terreno->text()!=""&&ui->cb_terreo->currentIndex()!=0){
            ui->le_terreno->setDisabled(true);

            ui->cb_terreo->setDisabled(true);
            t.icono = ui->cb_terreo->currentText().toStdString();
            t.nombre = ui->le_terreno->text().toStdString();
            t.valor = ui->lb_val->text().toInt();
            campo.push_back(t);


            ui->pb_crearTerrenos->setDisabled(true);
            ui->spinBox->setEnabled(true);
        }
        else{
            QMessageBox mse;
            mse.setText("Hay algun campo activo vacio");
            mse.exec();
        }
        break;
    case 2:
        if(ui->le_terreno->text()!=""&&ui->le_terreno_2->text()!=""&&ui->cb_terreo->currentIndex()!=0&&ui->cb_terreo_2->currentIndex()!=0){
            ui->le_terreno->setDisabled(true);
            ui->le_terreno_2->setDisabled(true);

            ui->cb_terreo->setDisabled(true);
            ui->cb_terreo_2->setDisabled(true);


            ui->pb_crearTerrenos->setDisabled(true);
            ui->spinBox->setVisible(true);
            
            t.icono = ui->cb_terreo->currentText().toStdString();
            t.nombre = ui->le_terreno->text().toStdString();
            t.valor = ui->lb_val->text().toInt();
            campo.push_back(t);
            
            t.icono = ui->cb_terreo_2->currentText().toStdString();
            t.nombre = ui->le_terreno_2->text().toStdString();
            t.valor = ui->lb_val_2->text().toInt();
            campo.push_back(t);
            ui->pb_crearTerrenos->setDisabled(true);

            ui->spinBox->setEnabled(true);
        }
        else{
            QMessageBox mse;
            mse.setText("Hay algun campo activo vacio");
            mse.exec();
        }
        break;
    case 3:
        if(ui->le_terreno->text()!=""&&ui->le_terreno_2->text()!=""&&ui->le_terreno_3->text()!=""&&
                ui->cb_terreo->currentIndex()!=0&&ui->cb_terreo_2->currentIndex()!=0&&
                ui->cb_terreo_3->currentIndex()!=0){
            ui->le_terreno->setDisabled(true);
            ui->le_terreno_2->setDisabled(true);
            ui->le_terreno_3->setDisabled(true);

            ui->cb_terreo->setDisabled(true);
            ui->cb_terreo_2->setDisabled(true);
            ui->cb_terreo_3->setDisabled(true);


            ui->pb_crearTerrenos->setDisabled(true);
            ui->spinBox->setEnabled(true);
            t.icono = ui->cb_terreo->currentText().toStdString();
            t.nombre = ui->le_terreno->text().toStdString();
            t.valor = ui->lb_val->text().toInt();
            campo.push_back(t);
            t.icono = ui->cb_terreo_2->currentText().toStdString();
            t.nombre = ui->le_terreno_2->text().toStdString();
            t.valor = ui->lb_val_2->text().toInt();
            campo.push_back(t);
            t.icono = ui->cb_terreo_3->currentText().toStdString();
            t.nombre = ui->le_terreno_3->text().toStdString();
            t.valor = ui->lb_val_3->text().toInt();
            campo.push_back(t);
        }
        else{
            QMessageBox mse;
            mse.setText("Hay algun campo activo vacio");
            mse.exec();
        }
        break;
    case 4:
        if(ui->le_terreno->text()!=""&&ui->le_terreno_2->text()!=""&&ui->le_terreno_3->text()!=""&&ui->le_terreno_4->text()!=""&&
                ui->cb_terreo->currentIndex()!=0&&ui->cb_terreo_2->currentIndex()!=0&&
                ui->cb_terreo_3->currentIndex()!=0&&ui->cb_terreo_4->currentIndex()!=0){
            ui->le_terreno->setDisabled(true);
            ui->le_terreno_2->setDisabled(true);
            ui->le_terreno_3->setDisabled(true);
            ui->le_terreno_4->setDisabled(true);

            ui->cb_terreo->setDisabled(true);
            ui->cb_terreo_2->setDisabled(true);
            ui->cb_terreo_3->setDisabled(true);
            ui->cb_terreo_4->setDisabled(true);


            ui->pb_crearTerrenos->setDisabled(true);
            ui->spinBox->setEnabled(true);
            ui->pb_crearTerrenos->setDisabled(true);
            ui->spinBox->setVisible(true);
            ui->pb_crearTerrenos->setDisabled(true);
            ui->spinBox->setVisible(true);
            t.icono = ui->cb_terreo->currentText().toStdString();
            t.nombre = ui->le_terreno->text().toStdString();
            t.valor = ui->lb_val->text().toInt();
            campo.push_back(t);
            t.icono = ui->cb_terreo_2->currentText().toStdString();
            t.nombre = ui->le_terreno_2->text().toStdString();
            t.valor = ui->lb_val_2->text().toInt();
            campo.push_back(t);
            t.icono = ui->cb_terreo_3->currentText().toStdString();
            t.nombre = ui->le_terreno_3->text().toStdString();
            t.valor = ui->lb_val_3->text().toInt();
            campo.push_back(t);
            t.icono = ui->cb_terreo_4->currentText().toStdString();
            t.nombre = ui->le_terreno_4->text().toStdString();
            t.valor = ui->lb_val_4->text().toInt();
            campo.push_back(t);
        }
        else{
            QMessageBox mse;
            mse.setText("Hay algun campo activo vacio");
            mse.exec();
        }
        break;
    case 5:
        if(ui->le_terreno->text()!=""&&ui->le_terreno_2->text()!=""&&ui->le_terreno_3->text()!=""&&ui->le_terreno_4->text()!=""&&
                ui->le_terreno_5->text()!=""&&
                ui->cb_terreo->currentIndex()!=0&&ui->cb_terreo_2->currentIndex()!=0&&
                ui->cb_terreo_3->currentIndex()!=0&&ui->cb_terreo_4->currentIndex()!=0&&ui->cb_terreo_5->currentIndex()!=0){
            ui->le_terreno->setDisabled(true);
            ui->le_terreno_2->setDisabled(true);
            ui->le_terreno_3->setDisabled(true);
            ui->le_terreno_4->setDisabled(true);
            ui->le_terreno_5->setDisabled(true);

            ui->cb_terreo->setDisabled(true);
            ui->cb_terreo_2->setDisabled(true);
            ui->cb_terreo_3->setDisabled(true);
            ui->cb_terreo_4->setDisabled(true);
            ui->cb_terreo_5->setDisabled(true);

            ui->pb_crearTerrenos->setDisabled(true);
            ui->spinBox->setEnabled(true);
            ui->pb_crearTerrenos->setDisabled(true);
            ui->spinBox->setVisible(true);
            t.icono = ui->cb_terreo->currentText().toStdString();
            t.nombre = ui->le_terreno->text().toStdString();
            t.valor = ui->lb_val->text().toInt();
            campo.push_back(t);
            t.icono = ui->cb_terreo_2->currentText().toStdString();
            t.nombre = ui->le_terreno_2->text().toStdString();
            t.valor = ui->lb_val_2->text().toInt();
            campo.push_back(t);
            t.icono = ui->cb_terreo_3->currentText().toStdString();
            t.nombre = ui->le_terreno_3->text().toStdString();
            t.valor = ui->lb_val_3->text().toInt();
            campo.push_back(t);
            t.icono = ui->cb_terreo_4->currentText().toStdString();
            t.nombre = ui->le_terreno_4->text().toStdString();
            t.valor = ui->lb_val_4->text().toInt();
            campo.push_back(t);
            t.icono = ui->cb_terreo_5->currentText().toStdString();
            t.nombre = ui->le_terreno_5->text().toStdString();
            t.valor = ui->lb_val_5->text().toInt();
            campo.push_back(t);
        }
        else{
            QMessageBox mse;
            mse.setText("Hay algun campo activo vacio");
            mse.exec();
        }
        break;
    case 6:
        if(ui->le_terreno->text()!=""&&ui->le_terreno_2->text()!=""&&ui->le_terreno_3->text()!=""&&ui->le_terreno_4->text()!=""&&
                ui->le_terreno_5->text()!=""&&ui->le_terreno_6->text()!=""&&
                ui->cb_terreo->currentIndex()!=0&&ui->cb_terreo_2->currentIndex()!=0&&
                ui->cb_terreo_3->currentIndex()!=0&&ui->cb_terreo_4->currentIndex()!=0&&ui->cb_terreo_5->currentIndex()!=0&&ui->cb_terreo_6->currentIndex()!=0){
            ui->le_terreno->setDisabled(true);
            ui->le_terreno_2->setDisabled(true);
            ui->le_terreno_3->setDisabled(true);
            ui->le_terreno_4->setDisabled(true);
            ui->le_terreno_5->setDisabled(true);
            ui->le_terreno_6->setDisabled(true);

            ui->cb_terreo->setDisabled(true);
            ui->cb_terreo_2->setDisabled(true);
            ui->cb_terreo_3->setDisabled(true);
            ui->cb_terreo_4->setDisabled(true);
            ui->cb_terreo_5->setDisabled(true);
            ui->cb_terreo_6->setDisabled(true);


            ui->pb_crearTerrenos->setDisabled(true);
            ui->spinBox->setEnabled(true);
            
            ui->pb_crearTerrenos->setDisabled(true);

            t.icono = ui->cb_terreo->currentText().toStdString();
            t.nombre = ui->le_terreno->text().toStdString();
            t.valor = ui->lb_val->text().toInt();
            campo.push_back(t);
            t.icono = ui->cb_terreo_2->currentText().toStdString();
            t.nombre = ui->le_terreno_2->text().toStdString();
            t.valor = ui->lb_val_2->text().toInt();
            campo.push_back(t);
            t.icono = ui->cb_terreo_3->currentText().toStdString();
            t.nombre = ui->le_terreno_3->text().toStdString();
            t.valor = ui->lb_val_3->text().toInt();
            campo.push_back(t);
            t.icono = ui->cb_terreo_4->currentText().toStdString();
            t.nombre = ui->le_terreno_4->text().toStdString();
            t.valor = ui->lb_val_4->text().toInt();
            campo.push_back(t);
            t.icono = ui->cb_terreo_5->currentText().toStdString();
            t.nombre = ui->le_terreno_5->text().toStdString();
            t.valor = ui->lb_val_5->text().toInt();
            campo.push_back(t);
            t.icono = ui->cb_terreo_6->currentText().toStdString();
            t.nombre = ui->le_terreno_6->text().toStdString();
            t.valor = ui->lb_val_6->text().toInt();
            campo.push_back(t);
        }
        else{
            QMessageBox mse;
            mse.setText("Hay algun campo activo vacio");
            mse.exec();
        }
        break;
    case 7:
        if(ui->le_terreno->text()!=""&&ui->le_terreno_2->text()!=""&&ui->le_terreno_3->text()!=""&&ui->le_terreno_4->text()!=""&&
                ui->le_terreno_5->text()!=""&&ui->le_terreno_6->text()!=""&&ui->le_terreno_7->text()!=""&&
                ui->cb_terreo->currentIndex()!=0&&ui->cb_terreo_2->currentIndex()!=0&&
                ui->cb_terreo_3->currentIndex()!=0&&ui->cb_terreo_4->currentIndex()!=0&&ui->cb_terreo_5->currentIndex()!=0&&ui->cb_terreo_6->currentIndex()!=0&&
                ui->cb_terreo_7->currentIndex()!=0){
            ui->le_terreno->setDisabled(true);
            ui->le_terreno_2->setDisabled(true);
            ui->le_terreno_3->setDisabled(true);
            ui->le_terreno_4->setDisabled(true);
            ui->le_terreno_5->setDisabled(true);
            ui->le_terreno_6->setDisabled(true);
            ui->le_terreno_7->setDisabled(true);

            ui->cb_terreo->setDisabled(true);
            ui->cb_terreo_2->setDisabled(true);
            ui->cb_terreo_3->setDisabled(true);
            ui->cb_terreo_4->setDisabled(true);
            ui->cb_terreo_5->setDisabled(true);
            ui->cb_terreo_6->setDisabled(true);
            ui->cb_terreo_7->setDisabled(true);


            ui->pb_crearTerrenos->setDisabled(true);
            ui->spinBox->setEnabled(true);
            
            ui->pb_crearTerrenos->setDisabled(true);

            t.icono = ui->cb_terreo->currentText().toStdString();
            t.nombre = ui->le_terreno->text().toStdString();
            t.valor = ui->lb_val->text().toInt();
            campo.push_back(t);
            t.icono = ui->cb_terreo_2->currentText().toStdString();
            t.nombre = ui->le_terreno_2->text().toStdString();
            t.valor = ui->lb_val_2->text().toInt();
            campo.push_back(t);
            t.icono = ui->cb_terreo_3->currentText().toStdString();
            t.nombre = ui->le_terreno_3->text().toStdString();
            t.valor = ui->lb_val_3->text().toInt();
            campo.push_back(t);
            t.icono = ui->cb_terreo_4->currentText().toStdString();
            t.nombre = ui->le_terreno_4->text().toStdString();
            t.valor = ui->lb_val_4->text().toInt();
            campo.push_back(t);
            t.icono = ui->cb_terreo_5->currentText().toStdString();
            t.nombre = ui->le_terreno_5->text().toStdString();
            t.valor = ui->lb_val_5->text().toInt();
            campo.push_back(t);
            t.icono = ui->cb_terreo_6->currentText().toStdString();
            t.nombre = ui->le_terreno_6->text().toStdString();
            t.valor = ui->lb_val_6->text().toInt();
            campo.push_back(t);
            t.icono = ui->cb_terreo_7->currentText().toStdString();
            t.nombre = ui->le_terreno_7->text().toStdString();
            t.valor = ui->lb_val_7->text().toInt();
            campo.push_back(t);
        }
        else{
            QMessageBox mse;
            mse.setText("Hay algun campo activo vacio");
            mse.exec();
        }
        break;
    case 8:
        if(ui->le_terreno->text()!=""&&ui->le_terreno_2->text()!=""&&ui->le_terreno_3->text()!=""&&ui->le_terreno_4->text()!=""&&
                ui->le_terreno_5->text()!=""&&ui->le_terreno_6->text()!=""&&ui->le_terreno_7->text()!=""&&ui->le_terreno_8->text()!=""&&
                ui->cb_terreo->currentIndex()!=0&&ui->cb_terreo_2->currentIndex()!=0&&
                ui->cb_terreo_3->currentIndex()!=0&&ui->cb_terreo_4->currentIndex()!=0&&ui->cb_terreo_5->currentIndex()!=0&&ui->cb_terreo_6->currentIndex()!=0&&
                ui->cb_terreo_7->currentIndex()!=0&&ui->cb_terreo_8->currentIndex()!=0){
            ui->le_terreno->setDisabled(true);
            ui->le_terreno_2->setDisabled(true);
            ui->le_terreno_3->setDisabled(true);
            ui->le_terreno_4->setDisabled(true);
            ui->le_terreno_5->setDisabled(true);
            ui->le_terreno_6->setDisabled(true);
            ui->le_terreno_7->setDisabled(true);
            ui->le_terreno_8->setDisabled(true);

            ui->cb_terreo->setDisabled(true);
            ui->cb_terreo_2->setDisabled(true);
            ui->cb_terreo_3->setDisabled(true);
            ui->cb_terreo_4->setDisabled(true);
            ui->cb_terreo_5->setDisabled(true);
            ui->cb_terreo_6->setDisabled(true);
            ui->cb_terreo_7->setDisabled(true);
            ui->cb_terreo_8->setDisabled(true);


            ui->pb_crearTerrenos->setDisabled(true);
            ui->spinBox->setEnabled(true);
            t.icono = ui->cb_terreo->currentText().toStdString();
            t.nombre = ui->le_terreno->text().toStdString();
            t.valor = ui->lb_val->text().toInt();
            campo.push_back(t);
            t.icono = ui->cb_terreo_2->currentText().toStdString();
            t.nombre = ui->le_terreno_2->text().toStdString();
            t.valor = ui->lb_val_2->text().toInt();
            campo.push_back(t);
            t.icono = ui->cb_terreo_3->currentText().toStdString();
            t.nombre = ui->le_terreno_3->text().toStdString();
            t.valor = ui->lb_val_3->text().toInt();
            campo.push_back(t);
            t.icono = ui->cb_terreo_4->currentText().toStdString();
            t.nombre = ui->le_terreno_4->text().toStdString();
            t.valor = ui->lb_val_4->text().toInt();
            campo.push_back(t);
            t.icono = ui->cb_terreo_5->currentText().toStdString();
            t.nombre = ui->le_terreno_5->text().toStdString();
            t.valor = ui->lb_val_5->text().toInt();
            campo.push_back(t);
            t.icono = ui->cb_terreo_6->currentText().toStdString();
            t.nombre = ui->le_terreno_6->text().toStdString();
            t.valor = ui->lb_val_6->text().toInt();
            campo.push_back(t);
            t.icono = ui->cb_terreo_7->currentText().toStdString();
            t.nombre = ui->le_terreno_7->text().toStdString();
            t.valor = ui->lb_val_7->text().toInt();
            campo.push_back(t);
            t.icono = ui->cb_terreo_8->currentText().toStdString();
            t.nombre = ui->le_terreno_8->text().toStdString();
            t.valor = ui->lb_val_8->text().toInt();
            campo.push_back(t);
        }
        else{
            QMessageBox mse;
            mse.setText("Hay algun campo activo vacio");
            mse.exec();
        }
        break;
    case 9:
        if(ui->le_terreno->text()!=""&&ui->le_terreno_2->text()!=""&&ui->le_terreno_3->text()!=""&&ui->le_terreno_4->text()!=""&&
                ui->le_terreno_5->text()!=""&&ui->le_terreno_6->text()!=""&&ui->le_terreno_7->text()!=""&&ui->le_terreno_8->text()!=""&&
                ui->le_terreno_9->text()!=""&&ui->cb_terreo->currentIndex()!=0&&ui->cb_terreo_2->currentIndex()!=0&&
                ui->cb_terreo_3->currentIndex()!=0&&ui->cb_terreo_4->currentIndex()!=0&&ui->cb_terreo_5->currentIndex()!=0&&ui->cb_terreo_6->currentIndex()!=0&&
                ui->cb_terreo_7->currentIndex()!=0&&ui->cb_terreo_8->currentIndex()!=0&&ui->cb_terreo_9->currentIndex()!=0){
            ui->le_terreno->setDisabled(true);
            ui->le_terreno_2->setDisabled(true);
            ui->le_terreno_3->setDisabled(true);
            ui->le_terreno_4->setDisabled(true);
            ui->le_terreno_5->setDisabled(true);
            ui->le_terreno_6->setDisabled(true);
            ui->le_terreno_7->setDisabled(true);
            ui->le_terreno_8->setDisabled(true);
            ui->le_terreno_9->setDisabled(true);

            ui->cb_terreo->setDisabled(true);
            ui->cb_terreo_2->setDisabled(true);
            ui->cb_terreo_3->setDisabled(true);
            ui->cb_terreo_4->setDisabled(true);
            ui->cb_terreo_5->setDisabled(true);
            ui->cb_terreo_6->setDisabled(true);
            ui->cb_terreo_7->setDisabled(true);
            ui->cb_terreo_8->setDisabled(true);
            ui->cb_terreo_9->setDisabled(true);


            ui->pb_crearTerrenos->setDisabled(true);
            ui->spinBox->setEnabled(true);
            
            t.icono = ui->cb_terreo->currentText().toStdString();
            t.nombre = ui->le_terreno->text().toStdString();
            t.valor = ui->lb_val->text().toInt();
            campo.push_back(t);
            t.icono = ui->cb_terreo_2->currentText().toStdString();
            t.nombre = ui->le_terreno_2->text().toStdString();
            t.valor = ui->lb_val_2->text().toInt();
            campo.push_back(t);
            t.icono = ui->cb_terreo_3->currentText().toStdString();
            t.nombre = ui->le_terreno_3->text().toStdString();
            t.valor = ui->lb_val_3->text().toInt();
            campo.push_back(t);
            t.icono = ui->cb_terreo_4->currentText().toStdString();
            t.nombre = ui->le_terreno_4->text().toStdString();
            t.valor = ui->lb_val_4->text().toInt();
            campo.push_back(t);
            t.icono = ui->cb_terreo_5->currentText().toStdString();
            t.nombre = ui->le_terreno_5->text().toStdString();
            t.valor = ui->lb_val_5->text().toInt();
            campo.push_back(t);
            t.icono = ui->cb_terreo_6->currentText().toStdString();
            t.nombre = ui->le_terreno_6->text().toStdString();
            t.valor = ui->lb_val_6->text().toInt();
            campo.push_back(t);
            t.icono = ui->cb_terreo_7->currentText().toStdString();
            t.nombre = ui->le_terreno_7->text().toStdString();
            t.valor = ui->lb_val_7->text().toInt();
            campo.push_back(t);
            t.icono = ui->cb_terreo_8->currentText().toStdString();
            t.nombre = ui->le_terreno_8->text().toStdString();
            t.valor = ui->lb_val_8->text().toInt();
            campo.push_back(t);
            t.icono = ui->cb_terreo_9->currentText().toStdString();
            t.nombre = ui->le_terreno_9->text().toStdString();
            t.valor = ui->lb_val_9->text().toInt();
            campo.push_back(t);
        }
        else{
            QMessageBox mse;
            mse.setText("Hay algun campo activo vacio");
            mse.exec();
        }
        break;
    case 10:
        if(ui->le_terreno->text()!=""&&ui->le_terreno_2->text()!=""&&ui->le_terreno_3->text()!=""&&ui->le_terreno_4->text()!=""&&
                ui->le_terreno_5->text()!=""&&ui->le_terreno_6->text()!=""&&ui->le_terreno_7->text()!=""&&ui->le_terreno_8->text()!=""&&
                ui->le_terreno_9->text()!=""&&ui->le_terreno_10->text()!=""&&ui->cb_terreo->currentIndex()!=0&&ui->cb_terreo_2->currentIndex()!=0&&
                ui->cb_terreo_3->currentIndex()!=0&&ui->cb_terreo_4->currentIndex()!=0&&ui->cb_terreo_5->currentIndex()!=0&&ui->cb_terreo_6->currentIndex()!=0&&
                ui->cb_terreo_7->currentIndex()!=0&&ui->cb_terreo_8->currentIndex()!=0&&ui->cb_terreo_9->currentIndex()!=0&&ui->cb_terreo_10->currentIndex()!=0){
            ui->le_terreno->setDisabled(true);
            ui->le_terreno_2->setDisabled(true);
            ui->le_terreno_3->setDisabled(true);
            ui->le_terreno_4->setDisabled(true);
            ui->le_terreno_5->setDisabled(true);
            ui->le_terreno_6->setDisabled(true);
            ui->le_terreno_7->setDisabled(true);
            ui->le_terreno_8->setDisabled(true);
            ui->le_terreno_9->setDisabled(true);
            ui->le_terreno_10->setDisabled(true);
            ui->cb_terreo->setDisabled(true);
            ui->cb_terreo_2->setDisabled(true);
            ui->cb_terreo_3->setDisabled(true);
            ui->cb_terreo_4->setDisabled(true);
            ui->cb_terreo_5->setDisabled(true);
            ui->cb_terreo_6->setDisabled(true);
            ui->cb_terreo_7->setDisabled(true);
            ui->cb_terreo_8->setDisabled(true);
            ui->cb_terreo_9->setDisabled(true);
            ui->cb_terreo_10->setDisabled(true);

            ui->pb_crearTerrenos->setDisabled(true);
            ui->spinBox->setEnabled(true);
            
            t.icono = ui->cb_terreo->currentText().toStdString();
            t.nombre = ui->le_terreno->text().toStdString();
            t.valor = ui->lb_val->text().toInt();
            campo.push_back(t);
            t.icono = ui->cb_terreo_2->currentText().toStdString();
            t.nombre = ui->le_terreno_2->text().toStdString();
            t.valor = ui->lb_val_2->text().toInt();
            campo.push_back(t);
            t.icono = ui->cb_terreo_3->currentText().toStdString();
            t.nombre = ui->le_terreno_3->text().toStdString();
            t.valor = ui->lb_val_3->text().toInt();
            campo.push_back(t);
            t.icono = ui->cb_terreo_4->currentText().toStdString();
            t.nombre = ui->le_terreno_4->text().toStdString();
            t.valor = ui->lb_val_4->text().toInt();
            campo.push_back(t);
            t.icono = ui->cb_terreo_5->currentText().toStdString();
            t.nombre = ui->le_terreno_5->text().toStdString();
            t.valor = ui->lb_val_5->text().toInt();
            campo.push_back(t);
            t.icono = ui->cb_terreo_6->currentText().toStdString();
            t.nombre = ui->le_terreno_6->text().toStdString();
            t.valor = ui->lb_val_6->text().toInt();
            campo.push_back(t);
            t.icono = ui->cb_terreo_7->currentText().toStdString();
            t.nombre = ui->le_terreno_7->text().toStdString();
            t.valor = ui->lb_val_7->text().toInt();
            campo.push_back(t);
            t.icono = ui->cb_terreo_8->currentText().toStdString();
            t.nombre = ui->le_terreno_8->text().toStdString();
            t.valor = ui->lb_val_8->text().toInt();
            campo.push_back(t);
            t.icono = ui->cb_terreo_9->currentText().toStdString();
            t.nombre = ui->le_terreno_9->text().toStdString();
            t.valor = ui->lb_val_9->text().toInt();
            campo.push_back(t);
            t.icono = ui->cb_terreo_10->currentText().toStdString();
            t.nombre = ui->le_terreno_10->text().toStdString();
            t.valor = ui->lb_val_10->text().toInt();
            campo.push_back(t);
            
        }
        else{
            QMessageBox mse;
            mse.setText("Hay algun campo activo vacio");
            mse.exec();
        }
        break;

    }
}

void principal::activar_valores()
{
    activar_botones();
    ui->pb_asignarValores->setEnabled(true);

}

void principal::activar_botones()
{

    for(unsigned int i=0; i<campo.size(); i++){
        if(campo[i].icono=="Ciudad"){
            ui->pb_personaje->setEnabled(true);
            ui->le_valor->setEnabled(true);
        }
        if(campo[i].icono=="Mar"){
            ui->pb_personaje_2->setEnabled(true);
            ui->le_valor_2->setEnabled(true);
        }
        if(campo[i].icono=="Playa"){
            ui->pb_personaje_3->setEnabled(true);
            ui->le_valor_3->setEnabled(true);
        }
        if(campo[i].icono=="Desierto"){
            ui->pb_personaje_4->setEnabled(true);
            ui->le_valor_4->setEnabled(true);
        }
        if(campo[i].icono=="Bosque"){
            ui->pb_personaje_5->setEnabled(true);
            ui->le_valor_5->setEnabled(true);
        }
        if(campo[i].icono=="Montana"){
            ui->pb_personaje_6->setEnabled(true);
            ui->le_valor_6->setEnabled(true);
        }
        if(campo[i].icono=="Pueblo"){
            ui->pb_personaje_7->setEnabled(true);
            ui->le_valor_7->setEnabled(true);
        }
        if(campo[i].icono=="Lomas"){
            ui->pb_personaje_8->setEnabled(true);
            ui->le_valor_8->setEnabled(true);
        }
        if(campo[i].icono=="Nieve"){
            ui->pb_personaje_9->setEnabled(true);
            ui->le_valor_9->setEnabled(true);
        }
        if(campo[i].icono=="Pared"){
            ui->pb_personaje_10->setEnabled(true);
            ui->le_valor_10->setEnabled(true);
        }
    }
}

void principal::validar_valores()
{
    if(!ui->pb_personaje->isEnabled()){
        ui->le_valor->setText("NA");
    }
    if(!ui->pb_personaje_2->isEnabled()){
        ui->le_valor_2->setText("NA");
    }
    if(!ui->pb_personaje_3->isEnabled()){
        ui->le_valor_3->setText("NA");
    }
    if(!ui->pb_personaje_4->isEnabled()){
        ui->le_valor_4->setText("NA");
    }
    if(!ui->pb_personaje_5->isEnabled()){
        ui->le_valor_5->setText("NA");
    }
    if(!ui->pb_personaje_6->isEnabled()){
        ui->le_valor_6->setText("NA");
    }
    if(!ui->pb_personaje_7->isEnabled()){
        ui->le_valor_7->setText("NA");
    }
    if(!ui->pb_personaje_8->isEnabled()){
        ui->le_valor_8->setText("NA");
    }
    if(!ui->pb_personaje_9->isEnabled()){
        ui->le_valor_9->setText("NA");
    }
    if(!ui->pb_personaje_10->isEnabled()){
        ui->le_valor_10->setText("NA");
    }
}

void principal::guardar_personajes()
{
    ofstream archivo("personajes.jai");
    if(archivo.is_open()){
        for(unsigned int i=0; i<persona.size();i++){
            archivo<<persona[i].nombre<<" ,"<<persona[i].icono<<" ,"<<persona[i].ciudad<<" ,"<<persona[i].mar<<" ,"<<persona[i].playa<<" ,"
                     <<persona[i].desierto<<" ,"<<persona[i].bosque<<" ,"<<persona[i].montana<<" ,"<<persona[i].pueblo<<" ,"<<persona[i].loma<<" ,"
                       <<persona[i].nieve<<" ,";
            if(i==persona.size()-1){
                archivo<<persona[i].pared<<" ,";
            }
            else {
                archivo<<persona[i].pared<<" ,\n";
            }
        }
    }
    archivo.close();
}

void principal::guardar_terreno()
{
    ofstream archivo("terreno.jai");

    if(archivo.is_open()){
        for(int i=0; i<15; i++){
            for(int j=0; j<15; j++){
                archivo<<mapa[i][j].valor<<",";
                archivo<<mapa[i][j].nombre<<" ,";
                if(i==14&&j==14){
                    archivo<<mapa[i][j].icono<<" ,";
                }
                else{
                    archivo<<mapa[i][j].icono<<" ,\n";
                }
            }
        }
    }
    archivo.close();
}

void principal::bloquear_valores()
{
    ui->pb_personaje->setDisabled(true);
    ui->pb_personaje_2->setDisabled(true);
    ui->pb_personaje_3->setDisabled(true);
    ui->pb_personaje_4->setDisabled(true);
    ui->pb_personaje_5->setDisabled(true);
    ui->pb_personaje_6->setDisabled(true);
    ui->pb_personaje_7->setDisabled(true);
    ui->pb_personaje_8->setDisabled(true);
    ui->pb_personaje_9->setDisabled(true);
    ui->pb_personaje_10->setDisabled(true);
    ui->le_valor->setDisabled(true);
    ui->le_valor_2->setDisabled(true);
    ui->le_valor_3->setDisabled(true);
    ui->le_valor_4->setDisabled(true);
    ui->le_valor_5->setDisabled(true);
    ui->le_valor_6->setDisabled(true);
    ui->le_valor_7->setDisabled(true);
    ui->le_valor_8->setDisabled(true);
    ui->le_valor_9->setDisabled(true);
    ui->le_valor_10->setDisabled(true);
    ui->pb_asignarValores->setDisabled(true);
}

void principal::generar_terreno()
{
    for(int i=0; i<15;i++){
        for(int j=0; j<15;j++){
            mapa[i][j].valor=valores[i][j];
        }
    }
    for(int i=0; i<15; i++){
        for(int j=0; j<15; j++){
            for(unsigned int h=0; h<campo.size(); h++){
                if(mapa[i][j].valor==campo[h].valor){
                    mapa[i][j].nombre=campo[h].nombre;
                    mapa[i][j].icono=campo[h].icono;
                }
            }
        }
    }
}

void principal::guardar_repetidos()
{
    ofstream archivo("repetidos.jai");
    if(archivo.is_open()){
        for(unsigned int i=0; i<campo.size(); i++){
            archivo<<campo[i].valor;
            archivo<<",";
            archivo<<campo[i].nombre;
            archivo<<" ,";
            archivo<<campo[i].icono;
            archivo<<" ,\n";
        }
    }
}

void principal::on_pb_cargarValores_clicked()
{
    QString nombre = ui->lineEdit->text();
    cargar_valores(nombre.toStdString());
    ui->pb_crearTerrenos->setEnabled(true);
}

void principal::on_pb_crearTerrenos_clicked()
{
    desactivar_lineedit_terrenos();
}

void principal::on_pb_iniciar_clicked()
{
    generar_terreno();
    guardar_personajes();
    guardar_terreno();
    guardar_repetidos();
    //lanzar ventana siguiente
    MainWindow *w=new MainWindow;
    this->close();
    w->show();
}

void principal::on_spinBox_valueChanged(int arg1)
{
    if(arg1!=0){
        ui->pb_crear_personaje->setEnabled(true);
    }
    else{
        ui->pb_crear_personaje->setDisabled(true);
    }
    if(arg1==1){
        ui->le_personaje->setEnabled(true);
        ui->cb_personaje->setEnabled(true);

        ui->le_personaje_2->setDisabled(true);
        ui->cb_personaje_2->setDisabled(true);

        ui->le_personaje_3->setDisabled(true);
        ui->cb_personaje_3->setDisabled(true);

        ui->le_personaje_2->clear();
        ui->cb_personaje_2->setCurrentIndex(0);
    }
    else if(arg1==2){
        ui->le_personaje->setEnabled(true);
        ui->cb_personaje->setEnabled(true);

        ui->le_personaje_2->setEnabled(true);
        ui->cb_personaje_2->setEnabled(true);

        ui->le_personaje_3->setDisabled(true);
        ui->cb_personaje_3->setDisabled(true);

        ui->le_personaje_3->clear();
        ui->cb_personaje_3->setCurrentIndex(0);
    }
    else if(arg1==3){
        ui->le_personaje->setEnabled(true);
        ui->cb_personaje->setEnabled(true);

        ui->le_personaje_2->setEnabled(true);
        ui->cb_personaje_2->setEnabled(true);

        ui->le_personaje_3->setEnabled(true);
        ui->cb_personaje_3->setEnabled(true);
    }
    else{
        ui->le_personaje->setDisabled(true);
        ui->cb_personaje->setDisabled(true);

        ui->le_personaje_2->setDisabled(true);
        ui->cb_personaje_2->setDisabled(true);

        ui->le_personaje_3->setDisabled(true);
        ui->cb_personaje_3->setDisabled(true);

        ui->pb_iniciar->setDisabled(true);
        ui->le_personaje->clear();
        ui->cb_personaje->setCurrentIndex(0);
    }
    cant_per=arg1;
    cp=arg1;
}

void principal::on_pb_asignarValores_clicked()
{
    if(ui->le_valor->text()!=""&&ui->le_valor_2->text()!=""&&ui->le_valor_3->text()!=""&&ui->le_valor_4->text()!=""&&ui->le_valor_5->text()!=""&&
            ui->le_valor_6->text()!=""&&ui->le_valor_7->text()!=""&&ui->le_valor_8->text()!=""&&ui->le_valor_9->text()!=""&&ui->le_valor_10->text()!=""){

  if(cant_per>0){
        if(pers==0){
            persona[0].ciudad=ui->le_valor->text().toStdString();
            persona[0].mar=ui->le_valor_2->text().toStdString();;
            persona[0].playa=ui->le_valor_3->text().toStdString();;;
            persona[0].desierto=ui->le_valor_4->text().toStdString();;;
            persona[0].bosque=ui->le_valor_5->text().toStdString();;;
            persona[0].montana=ui->le_valor_6->text().toStdString();;
            persona[0].pueblo=ui->le_valor_7->text().toStdString();
            persona[0].loma=ui->le_valor_8->text().toStdString();
            persona[0].nieve=ui->le_valor_9->text().toStdString();
            persona[0].pared=ui->le_valor_10->text().toStdString();
            if(cp>1){
            QMessageBox mse;
            QString men="Capture los datos del personaje: "+QString::fromStdString(persona[1].nombre);
            mse.setText(men);
            mse.exec();
            }
            cant_per--;
            pers++;
            if(cant_per==0){
                ui->pb_crear_personaje->setDisabled(true);
                ui->pb_iniciar->setEnabled(true);
                ui->label_cant->clear();
                ui->label_cant->setText("0");
                bloquear_valores();
            }
        }
        else if(pers==1){
            validar_valores();
            persona[1].ciudad=ui->le_valor->text().toStdString();
            persona[1].mar=ui->le_valor_2->text().toStdString();
            persona[1].playa=ui->le_valor_3->text().toStdString();
            persona[1].desierto=ui->le_valor_4->text().toStdString();
            persona[1].bosque=ui->le_valor_5->text().toStdString();
            persona[1].montana=ui->le_valor_6->text().toStdString();
            persona[1].pueblo=ui->le_valor_7->text().toStdString();
            persona[1].loma=ui->le_valor_8->text().toStdString();
            persona[1].nieve=ui->le_valor_9->text().toStdString();
            persona[1].pared=ui->le_valor_10->text().toStdString();
            if(cp>2){
            QMessageBox mse;
            QString men="Capture los datos del personaje: "+QString::fromStdString(persona[2].nombre);
            mse.setText(men);
            mse.exec();
            }
            cant_per--;
            pers++;
            if(cant_per==0){
                ui->pb_crear_personaje->setDisabled(true);
                ui->pb_iniciar->setEnabled(true);
                ui->label_cant->clear();
                ui->label_cant->setText("0");
                bloquear_valores();
            }
            validar_valores();
        }
        else if(pers==2){
            validar_valores();
            persona[2].ciudad=ui->le_valor->text().toStdString();
            persona[2].mar=ui->le_valor_2->text().toStdString();
            persona[2].playa=ui->le_valor_3->text().toStdString();
            persona[2].desierto=ui->le_valor_4->text().toStdString();
            persona[2].bosque=ui->le_valor_5->text().toStdString();
            persona[2].montana=ui->le_valor_6->text().toStdString();
            persona[2].pueblo=ui->le_valor_7->text().toStdString();
            persona[2].loma=ui->le_valor_8->text().toStdString();
            persona[2].nieve=ui->le_valor_9->text().toStdString();
            persona[2].pared=ui->le_valor_10->text().toStdString();
            cant_per--;
            pers++;
            if(cant_per==0){
                ui->pb_crear_personaje->setDisabled(true);
                ui->pb_iniciar->setEnabled(true);
                ui->label_cant->clear();
                ui->label_cant->setText("0");
                bloquear_valores();
            }
        }
        ui->le_valor->clear();ui->le_valor_2->clear();ui->le_valor_3->clear();ui->le_valor_4->clear();ui->le_valor_5->clear();
        ui->le_valor_6->clear();ui->le_valor_7->clear();ui->le_valor_8->clear();ui->le_valor_9->clear();ui->le_valor_10->clear();
    }
    }
    else{
        QMessageBox mse;
        mse.setText("Hay algun campo activo vacio");
        mse.exec();
    }
    validar_valores();
}

void principal::on_lineEdit_cursorPositionChanged(int arg1, int arg2)
{
    QRegExp rx("([a-z]|[A-Z]|[0-9])*.txt");
    QValidator *validator=new QRegExpValidator(rx,this);
    ui->lineEdit->setValidator(validator);

    if(ui->lineEdit->text()!=""){
        ui->pb_cargarValores->setEnabled(true);

    }
    else{
        ui->pb_cargarValores->setDisabled(true);
    }
}

void principal::on_le_valor_cursorPositionChanged(int arg1, int arg2)
{
    QRegExp rx("(NA|([0-9]*.[0-9]*))");
    QValidator *validator=new QRegExpValidator(rx,this);
    ui->le_valor->setValidator(validator);
}

void principal::on_le_valor_2_cursorPositionChanged(int arg1, int arg2)
{
    QRegExp rx("NA|[0-9]*.[0-9]*");
    QValidator *validator=new QRegExpValidator(rx,this);
    ui->le_valor_2->setValidator(validator);
}

void principal::on_le_valor_3_cursorPositionChanged(int arg1, int arg2)
{
    QRegExp rx("NA|[0-9]*.[0-9]*");
    QValidator *validator=new QRegExpValidator(rx,this);
    ui->le_valor_3->setValidator(validator);
}

void principal::on_le_valor_4_cursorPositionChanged(int arg1, int arg2)
{
    QRegExp rx("NA|[0-9]*.[0-9]*");
    QValidator *validator=new QRegExpValidator(rx,this);
    ui->le_valor_4->setValidator(validator);
}

void principal::on_le_valor_5_cursorPositionChanged(int arg1, int arg2)
{
    QRegExp rx("NA|[0-9]*.[0-9]*");
    QValidator *validator=new QRegExpValidator(rx,this);
    ui->le_valor_5->setValidator(validator);
}

void principal::on_le_valor_6_cursorPositionChanged(int arg1, int arg2)
{
    QRegExp rx("NA|[0-9]*.[0-9]*");
    QValidator *validator=new QRegExpValidator(rx,this);
    ui->le_valor_6->setValidator(validator);
}

void principal::on_le_valor_7_cursorPositionChanged(int arg1, int arg2)
{
    QRegExp rx("NA|[0-9]*.[0-9]*");
    QValidator *validator=new QRegExpValidator(rx,this);
    ui->le_valor_7->setValidator(validator);
}

void principal::on_le_valor_8_cursorPositionChanged(int arg1, int arg2)
{
    QRegExp rx("NA|[0-9]*.[0-9]*");
    QValidator *validator=new QRegExpValidator(rx,this);
    ui->le_valor_8->setValidator(validator);
}

void principal::on_le_valor_9_cursorPositionChanged(int arg1, int arg2)
{
    QRegExp rx("NA|[0-9]*.[0-9]*");
    QValidator *validator=new QRegExpValidator(rx,this);
    ui->le_valor_9->setValidator(validator);
}

void principal::on_le_valor_10_cursorPositionChanged(int arg1, int arg2)
{
    QRegExp rx("NA|[0-9]*.[0-9]*");
    QValidator *validator=new QRegExpValidator(rx,this);
    ui->le_valor_10->setValidator(validator);
}

void principal::on_pb_crear_personaje_clicked()
{
    int cant= ui->spinBox->value();
    personaje p;
        if(cant==1){
            if(ui->le_personaje->text()!=""&&ui->cb_personaje->currentIndex()!=0){

                ui->le_personaje->setDisabled(true);
                ui->cb_personaje->setDisabled(true);
                ui->pb_crear_personaje->setDisabled(true);
                cant_per=cant;
                p.nombre=ui->le_personaje->text().toStdString();
                p.icono=ui->cb_personaje->currentText().toStdString();
                persona.push_back(p);
                ui->label_cant->clear();
                ui->label_cant->setText(QString::number(cant));
                activar_valores();
                ui->spinBox->setDisabled(true);
                validar_valores();
                QMessageBox mse;
                QString men="Capture los datos del personaje: "+QString::fromStdString(p.nombre);
                mse.setText(men);
                mse.exec();
            }
            else{
                QMessageBox *mse= new QMessageBox;
                mse->setText("Hay campos vacios\nFavor de ingresar datos");
                mse->exec();
            }
        }
        else if(cant==2){
            if(ui->le_personaje->text()!=""&&ui->cb_personaje->currentIndex()!=0&&ui->le_personaje_2->text()!=""&&ui->cb_personaje_2->currentIndex()!=0){
                //guardar datos
                ui->le_personaje->setDisabled(true);
                ui->cb_personaje->setDisabled(true);
                ui->pb_crear_personaje->setDisabled(true);
                ui->le_personaje_2->setDisabled(true);
                ui->cb_personaje_2->setDisabled(true);
                cant_per=cant;
                p.nombre=ui->le_personaje->text().toStdString();
                p.icono=ui->cb_personaje->currentText().toStdString();
                persona.push_back(p);
                QMessageBox mse;
                QString men="Capture los datos del personaje: "+QString::fromStdString(p.nombre);
                mse.setText(men);
                mse.exec();
                p.nombre=ui->le_personaje_2->text().toStdString();
                p.icono=ui->cb_personaje_2->currentText().toStdString();
                persona.push_back(p);
                ui->label_cant->clear();
                ui->label_cant->setText(QString::number(cant));
                activar_valores();
                ui->spinBox->setDisabled(true);
                validar_valores();
            }
            else{
                QMessageBox *mse=new QMessageBox;
                mse->setText("Hay campos vacios\nFavor de ingresar datos");
                mse->exec();
            }
        }
        else if(cant==3){
            if(ui->le_personaje->text()!=""&&ui->cb_personaje->currentIndex()!=0&&ui->le_personaje_2->text()!=""&&ui->cb_personaje_2->currentIndex()!=0&&
                    ui->le_personaje_3->text()!=""&&ui->cb_personaje_3->currentIndex()!=0){
                // guardar datos
                ui->le_personaje->setDisabled(true);
                ui->cb_personaje->setDisabled(true);
                ui->pb_crear_personaje->setDisabled(true);
                ui->le_personaje_2->setDisabled(true);
                ui->cb_personaje_2->setDisabled(true);
                ui->le_personaje_3->setDisabled(true);
                ui->cb_personaje_3->setDisabled(true);
                cant_per=cant;
                p.nombre=ui->le_personaje->text().toStdString();
                p.icono=ui->cb_personaje->currentText().toStdString();
                persona.push_back(p);
                QMessageBox mse;
                QString men="Capture los datos del personaje: "+QString::fromStdString(p.nombre);
                mse.setText(men);
                mse.exec();
                p.nombre=ui->le_personaje_2->text().toStdString();
                p.icono=ui->cb_personaje_2->currentText().toStdString();
                persona.push_back(p);
                p.nombre=ui->le_personaje_3->text().toStdString();
                p.icono=ui->cb_personaje_3->currentText().toStdString();
                persona.push_back(p);
                ui->label_cant->clear();
                ui->label_cant->setText(QString::number(cant));
                activar_valores();
                ui->spinBox->setDisabled(true);
                validar_valores();
            }
            else{
                QMessageBox *mse=new QMessageBox;
                mse->setText("Hay campos vacios\nFavor de ingresar datos");
                mse->exec();
            }
        }
        else{
            QMessageBox *mse=new QMessageBox;
            mse->setText("Por lo menos debe de crear un personaje");
            mse->exec();
        }


}

void principal::on_pb_buscar_clicked()
{
    QString fileName1 = QFileDialog::getOpenFileName(this,tr("Open Text File"), "", tr("Text Files (*.txt)"));
    ui->lineEdit->setText(fileName1);
}

void principal::on_le_personaje_cursorPositionChanged(int arg1, int arg2)
{
    QRegExp rx("([A-Z]|[a-z]|[0-9])*");
    QValidator *validator=new QRegExpValidator(rx,this);
    ui->le_personaje->setValidator(validator);
}

void principal::on_le_personaje_2_cursorPositionChanged(int arg1, int arg2)
{
    QRegExp rx("([A-Z]|[a-z]|[0-9])*");
    QValidator *validator=new QRegExpValidator(rx,this);
    ui->le_personaje_2->setValidator(validator);
}

void principal::on_le_personaje_3_cursorPositionChanged(int arg1, int arg2)
{
    QRegExp rx("([A-Z]|[a-z]|[0-9])*");
    QValidator *validator=new QRegExpValidator(rx,this);
    ui->le_personaje_3->setValidator(validator);
}

void principal::on_le_terreno_cursorPositionChanged(int arg1, int arg2)
{
    QRegExp rx("([A-Z]|[a-z]|[0-9])*");
    QValidator *validator=new QRegExpValidator(rx,this);
    ui->le_terreno->setValidator(validator);
}

void principal::on_le_terreno_2_cursorPositionChanged(int arg1, int arg2)
{
    QRegExp rx("([a-z]|[A-Z]|[0-9])*");
    QValidator *validator=new QRegExpValidator(rx,this);
    ui->le_terreno_2->setValidator(validator);
}

void principal::on_le_terreno_3_cursorPositionChanged(int arg1, int arg2)
{
    QRegExp rx("([A-Z]|[a-z]|[0-9])*");
    QValidator *validator=new QRegExpValidator(rx,this);
    ui->le_terreno_3->setValidator(validator);
}

void principal::on_le_terreno_4_cursorPositionChanged(int arg1, int arg2)
{
    QRegExp rx("([A-Z]|[a-z]|[0-9])*");
    QValidator *validator=new QRegExpValidator(rx,this);
    ui->le_terreno_4->setValidator(validator);
}

void principal::on_le_terreno_5_cursorPositionChanged(int arg1, int arg2)
{
    QRegExp rx("([A-Z]|[a-z]|[0-9])*");
    QValidator *validator=new QRegExpValidator(rx,this);
    ui->le_terreno_5->setValidator(validator);
}

void principal::on_le_terreno_6_cursorPositionChanged(int arg1, int arg2)
{
    QRegExp rx("([A-Z]|[a-z]|[0-9])*");
    QValidator *validator=new QRegExpValidator(rx,this);
    ui->le_terreno_6->setValidator(validator);
}

void principal::on_le_terreno_7_cursorPositionChanged(int arg1, int arg2)
{
    QRegExp rx("([A-Z]|[a-z]|[0-9])*");
    QValidator *validator=new QRegExpValidator(rx,this);
    ui->le_terreno_7->setValidator(validator);
}

void principal::on_le_terreno_8_cursorPositionChanged(int arg1, int arg2)
{
    QRegExp rx("([A-Z]|[a-z]|[0-9])*");
    QValidator *validator=new QRegExpValidator(rx,this);
    ui->le_terreno_8->setValidator(validator);
}

void principal::on_le_terreno_9_cursorPositionChanged(int arg1, int arg2)
{
    QRegExp rx("([A-Z]|[a-z]|[0-9])*");
    QValidator *validator=new QRegExpValidator(rx,this);
    ui->le_terreno_9->setValidator(validator);
}

void principal::on_le_terreno_10_cursorPositionChanged(int arg1, int arg2)
{
    QRegExp rx("([A-Z]|[a-z]|[0-9])*");
    QValidator *validator=new QRegExpValidator(rx,this);
    ui->le_terreno_10->setValidator(validator);
}
