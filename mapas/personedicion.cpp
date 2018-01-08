#include "personedicion.h"
#include "ui_personedicion.h"
#include <QRegExp>
#include <QValidator>
#include <QRegExpValidator>
#include <fstream>
#include "mainwindow.h"

personedicion::personedicion(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::personedicion)
{
    ui->setupUi(this);
    cargar_personajes();
    generar_personaje();
    cargar_repetidos();
}

personedicion::~personedicion()
{
    delete ui;
}

void personedicion::cargar_personajes()
{
    personaje p;
    char comma;
    ifstream archivo("personajes.jai");
    if(archivo.is_open()){
        while(!archivo.eof()){
            if(archivo.eof())break;
            archivo>>p.nombre;
            if(archivo.eof())break;
            archivo>>comma;
            archivo>>p.icono;
            archivo>>comma;
            archivo>>p.ciudad;
            archivo>>comma;
            archivo>>p.mar;
            archivo>>comma;
            archivo>>p.playa;
            archivo>>comma;
            archivo>>p.desierto;
            archivo>>comma;
            archivo>>p.bosque;
            archivo>>comma;
            archivo>>p.montana;
            archivo>>comma;
            archivo>>p.pueblo;
            archivo>>comma;
            archivo>>p.loma;
            archivo>>comma;
            archivo>>p.nieve;
            archivo>>comma;
            archivo>>p.pared;
            archivo>>comma;
            p.estado=0;
            persona.push_back(p);
        }
    }
}

QIcon personedicion::generar_icono_personaje(string nombre)
{
    if(nombre=="Mono"){
        QPixmap pixmap("iconos/mono.png");
        QIcon Icon(pixmap);
        return Icon;
    }
    else if(nombre=="Ballena"){
        QPixmap pixmap("iconos/ballena.png");
        QIcon Icon(pixmap);
        return Icon;
    }
    else if(nombre=="Super"){
        QPixmap pixmap("iconos/super.png");
        QIcon Icon(pixmap);
        return Icon;
    }
    QIcon ico;
    return ico;
}

void personedicion::generar_personaje()
{
    if(persona.size()==1){
        ui->pushButton_11->setIcon(generar_icono_personaje(persona[0].icono));
        ui->pushButton_11->setIconSize(ui->pushButton_11->size());

        ui->pushButton_12->setGeometry(0,0,0,0);
        ui->pushButton_13->setGeometry(0,0,0,0);
    }
    else if(persona.size()==2){

        ui->pushButton_11->setIcon(generar_icono_personaje(persona[0].icono));
        ui->pushButton_11->setIconSize(ui->pushButton_11->size());
        ui->pushButton_12->setIcon(generar_icono_personaje(persona[1].icono));
        ui->pushButton_12->setIconSize(ui->pushButton_11->size());
        ui->pushButton_13->setGeometry(0,0,0,0);
    }
    else if(persona.size()==3){
        ui->pushButton_11->setIcon(generar_icono_personaje(persona[0].icono));
        ui->pushButton_11->setIconSize(ui->pushButton_11->size());
        ui->pushButton_12->setIcon(generar_icono_personaje(persona[1].icono));
        ui->pushButton_12->setIconSize(ui->pushButton_11->size());
        ui->pushButton_13->setIcon(generar_icono_personaje(persona[2].icono));
        ui->pushButton_13->setIconSize(ui->pushButton_11->size());

    }
    else{
        ui->pushButton_11->setGeometry(0,0,0,0);
        ui->pushButton_12->setGeometry(0,0,0,0);
        ui->pushButton_13->setGeometry(0,0,0,0);
    }
}

void personedicion::activar_valores()
{
    for(unsigned int i=0; i<campo.size(); i++){
        if(campo[i].icono=="Ciudad"){
            ui->pushButton->setEnabled(true);
            ui->lineEdit->setEnabled(true);
        }
        if(campo[i].icono=="Mar"){
            ui->pushButton_2->setEnabled(true);
            ui->lineEdit_2->setEnabled(true);
        }
        if(campo[i].icono=="Playa"){
            ui->pushButton_3->setEnabled(true);
            ui->lineEdit_3->setEnabled(true);
        }
        if(campo[i].icono=="Desierto"){
            ui->pushButton_4->setEnabled(true);
            ui->lineEdit_4->setEnabled(true);
        }
        if(campo[i].icono=="Bosque"){
            ui->pushButton_5->setEnabled(true);
            ui->lineEdit_5->setEnabled(true);
        }
        if(campo[i].icono=="Montana"){
            ui->pushButton_6->setEnabled(true);
            ui->lineEdit_6->setEnabled(true);
        }
        if(campo[i].icono=="Pueblo"){
            ui->pushButton_7->setEnabled(true);
            ui->lineEdit_7->setEnabled(true);
        }
        if(campo[i].icono=="Lomas"){
            ui->pushButton_8->setEnabled(true);
            ui->lineEdit_8->setEnabled(true);
        }
        if(campo[i].icono=="Nieve"){
            ui->pushButton_9->setEnabled(true);
            ui->lineEdit_9->setEnabled(true);
        }
        if(campo[i].icono=="Pared"){
            ui->pushButton_10->setEnabled(true);
            ui->lineEdit_10->setEnabled(true);
        }
    }
    ui->pushButton_14->setEnabled(true);
}

/*void personedicion::validar_valores()
{
    if(!ui->pushButton->isEnabled()){
        ui->lineEdit->setText("NA");
    }
    if(!ui->pushButton_2->isEnabled()){
        ui->lineEdit_2->setText("NA");
    }
    if(!ui->pushButton_3->isEnabled()){
        ui->lineEdit_3->setText("NA");
    }
    if(!ui->pushButton_4->isEnabled()){
        ui->lineEdit_4->setText("NA");
    }
    if(!ui->pushButton_5->isEnabled()){
        ui->lineEdit_5->setText("NA");
    }
    if(!ui->pushButton_6->isEnabled()){
        ui->lineEdit_6->setText("NA");
    }
    if(!ui->pushButton_7->isEnabled()){
        ui->lineEdit_7->setText("NA");
    }
    if(!ui->pushButton_8->isEnabled()){
        ui->lineEdit_8->setText("NA");
    }
    if(!ui->pushButton_9->isEnabled()){
        ui->lineEdit_9->setText("NA");
    }
    if(!ui->pushButton_10->isEnabled()){
        ui->lineEdit_10->setText("NA");
    }
}*/

void personedicion::cargar_repetidos()
{
    terreno t;
    char comma;
    ifstream archivo("repetidos.jai");
    if(archivo.is_open()){
        while(!archivo.eof()){
            if(archivo.eof())break;
            archivo>>t.valor;
            if(archivo.eof())break;
            archivo>>comma;
            archivo>>t.nombre;
            archivo>>comma;
            archivo>>t.icono;
            archivo>>comma;
            campo.push_back(t);
        }
    }
}

void personedicion::on_pushButton_11_clicked()//personaje  1
{
   if(campo.size()>0){
       activar_valores();
       colocar_valores(0);
       perso=0;
   }
}

void personedicion::on_pushButton_12_clicked()//personaje 2
{
    if(campo.size()>1){
        activar_valores();
        colocar_valores(1);
        perso=1;
    }
}

void personedicion::on_pushButton_13_clicked()//personaje 3
{
    if(campo.size()>2){
        activar_valores();
        colocar_valores(2);
        perso=2;
    }
}

void personedicion::on_pushButton_14_clicked()//editar
{
    if(ui->lineEdit->text()!=""&&ui->lineEdit_2->text()!=""&&ui->lineEdit_3->text()!=""&&ui->lineEdit_4->text()!=""&&ui->lineEdit_5->text()!=""&&ui->lineEdit_6->text()!=""&&
            ui->lineEdit_7->text()!=""&&ui->lineEdit_8->text()!=""&&ui->lineEdit_9->text()!=""&&ui->lineEdit_10->text()!=""){
        persona[perso].ciudad=ui->lineEdit->text().toStdString();
        persona[perso].mar=ui->lineEdit_2->text().toStdString();
        persona[perso].playa=ui->lineEdit_3->text().toStdString();
        persona[perso].desierto=ui->lineEdit_4->text().toStdString();
        persona[perso].bosque=ui->lineEdit_5->text().toStdString();
        persona[perso].montana=ui->lineEdit_6->text().toStdString();
        persona[perso].pueblo=ui->lineEdit_7->text().toStdString();
        persona[perso].loma=ui->lineEdit_8->text().toStdString();
        persona[perso].nieve=ui->lineEdit_9->text().toStdString();
        persona[perso].pared=ui->lineEdit_10->text().toStdString();
        guardar_valores();
    }
    ui->lineEdit->clear();ui->lineEdit_2->clear();ui->lineEdit_3->clear();ui->lineEdit_4->clear();ui->lineEdit_5->clear();
    ui->lineEdit_6->clear();ui->lineEdit_7->clear();ui->lineEdit_8->clear();ui->lineEdit_9->clear();ui->lineEdit_10->clear();
}

void personedicion::on_lineEdit_cursorPositionChanged(int arg1, int arg2)
{
    QRegExp rx("NA|[0-5]");
    QValidator *validator=new QRegExpValidator(rx,this);
    ui->lineEdit->setValidator(validator);
}

void personedicion::on_lineEdit_2_cursorPositionChanged(int arg1, int arg2)
{
    QRegExp rx("NA|[0-5]");
    QValidator *validator=new QRegExpValidator(rx,this);
    ui->lineEdit_2->setValidator(validator);
}

void personedicion::on_lineEdit_3_cursorPositionChanged(int arg1, int arg2)
{
    QRegExp rx("NA|[0-5]");
    QValidator *validator=new QRegExpValidator(rx,this);
    ui->lineEdit_3->setValidator(validator);
}

void personedicion::on_lineEdit_4_cursorPositionChanged(int arg1, int arg2)
{
    QRegExp rx("NA|[0-5]");
    QValidator *validator=new QRegExpValidator(rx,this);
    ui->lineEdit_4->setValidator(validator);
}

void personedicion::on_lineEdit_5_cursorPositionChanged(int arg1, int arg2)
{
    QRegExp rx("NA|[0-5]");
    QValidator *validator=new QRegExpValidator(rx,this);
    ui->lineEdit_5->setValidator(validator);
}

void personedicion::on_lineEdit_6_cursorPositionChanged(int arg1, int arg2)
{
    QRegExp rx("NA|[0-5]");
    QValidator *validator=new QRegExpValidator(rx,this);
    ui->lineEdit_6->setValidator(validator);
}

void personedicion::on_lineEdit_7_cursorPositionChanged(int arg1, int arg2)
{
    QRegExp rx("NA|[0-5]");
    QValidator *validator=new QRegExpValidator(rx,this);
    ui->lineEdit_7->setValidator(validator);
}

void personedicion::on_lineEdit_8_cursorPositionChanged(int arg1, int arg2)
{
    QRegExp rx("NA|[0-5]");
    QValidator *validator=new QRegExpValidator(rx,this);
    ui->lineEdit_8->setValidator(validator);
}

void personedicion::on_lineEdit_9_cursorPositionChanged(int arg1, int arg2)
{
    QRegExp rx("NA|[0-5]");
    QValidator *validator=new QRegExpValidator(rx,this);
    ui->lineEdit_9->setValidator(validator);
}

void personedicion::on_lineEdit_10_cursorPositionChanged(int arg1, int arg2)
{
    QRegExp rx("NA|[0-5]");
    QValidator *validator=new QRegExpValidator(rx,this);
    ui->lineEdit_10->setValidator(validator);
}

void personedicion::colocar_valores(int i)
{
    ui->lineEdit->setText(QString::fromStdString(persona[i].ciudad));
    ui->lineEdit_2->setText(QString::fromStdString(persona[i].mar));
    ui->lineEdit_3->setText(QString::fromStdString(persona[i].playa));
    ui->lineEdit_4->setText(QString::fromStdString(persona[i].desierto));
    ui->lineEdit_5->setText(QString::fromStdString(persona[i].bosque));
    ui->lineEdit_6->setText(QString::fromStdString(persona[i].montana));
    ui->lineEdit_7->setText(QString::fromStdString(persona[i].pueblo));
    ui->lineEdit_8->setText(QString::fromStdString(persona[i].loma));
    ui->lineEdit_9->setText(QString::fromStdString(persona[i].nieve));
    ui->lineEdit_10->setText(QString::fromStdString(persona[i].pared));
}

void personedicion::guardar_valores()
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

void personedicion::on_pushButton_15_clicked()
{
    MainWindow *w=new MainWindow;
    this->close();
    w->show();
}
