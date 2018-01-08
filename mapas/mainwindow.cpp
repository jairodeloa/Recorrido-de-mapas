#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QMessageBox>
#include <fstream>
#include <QWidget>
#include <QDebug>

#include "personedicion.h"
#include "nodo.h"

#include <QTime>
#include <math.h>




using namespace std;

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    cargar_personajes();
    cargar_terreno();
    generar_terreno();
    generar_personajes();
    cargar_repetidos();
    num_visita=1;
    ui->plainTextEdit->setReadOnly(true);
}

MainWindow::~MainWindow()
{
    delete ui;
}

bool MainWindow::validar_campo(terreno terren, personaje personaj)
{
    if(terren.icono=="Ciudad"){
        if(personaj.ciudad!="NA"){
            return true;
        }
    }
    if(terren.icono=="Pueblo"){
        if(personaj.pueblo!="NA"){
            return true;
        }
    }
    if(terren.icono=="Mar"){
        if(personaj.mar!="NA"){
            return true;
        }
    }
    if(terren.icono=="Playa"){
        if(personaj.playa!="NA"){
            return true;
        }
    }
    if(terren.icono=="Desierto"){
        if(personaj.desierto!="NA"){
            return true;
        }
    }
    if(terren.icono=="Bosque"){
        if(personaj.bosque!="NA"){
            return true;
        }
    }
    if(terren.icono=="Montana"){
        if(personaj.montana!="NA"){
            return true;
        }
    }
    if(terren.icono=="Lomas"){
        if(personaj.loma!="NA"){
            return true;
        }
    }
    if(terren.icono=="Nieve"){
        if(personaj.nieve!="NA"){
            return true;
        }
    }
    if(terren.icono=="Pared"){
        if(personaj.pared!="NA"){
            return true;
        }
    }
    return false;
}

void MainWindow::cargar_terreno()
{
    ifstream archivo("terreno.jai");
    if(archivo.is_open()){
        int i=0,j=0;
        char comma;
        while(!archivo.eof()){
            if(archivo.eof())break;
            archivo>>campo[i][j].valor;
            if(archivo.eof())break;
            archivo>>comma;
            archivo>>campo[i][j].nombre;
            archivo>>comma;
            archivo>>campo[i][j].icono;
            archivo>>comma;
            if(j==14){
                i++;
                j=-1;
            }
            j++;
        }
    }
}

void MainWindow::cargar_personajes()
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

void MainWindow::generar_terreno()
{
    //A
    ui->A1->setIcon(generar_icono(campo[0][0].icono));
    ui->A2->setIcon(generar_icono(campo[0][1].icono));
    ui->A3->setIcon(generar_icono(campo[0][2].icono));
    ui->A4->setIcon(generar_icono(campo[0][3].icono));
    ui->A5->setIcon(generar_icono(campo[0][4].icono));
    ui->A6->setIcon(generar_icono(campo[0][5].icono));
    ui->A7->setIcon(generar_icono(campo[0][6].icono));
    ui->A8->setIcon(generar_icono(campo[0][7].icono));
    ui->A9->setIcon(generar_icono(campo[0][8].icono));
    ui->A10->setIcon(generar_icono(campo[0][9].icono));
    ui->A11->setIcon(generar_icono(campo[0][10].icono));
    ui->A12->setIcon(generar_icono(campo[0][11].icono));
    ui->A13->setIcon(generar_icono(campo[0][12].icono));
    ui->A14->setIcon(generar_icono(campo[0][13].icono));
    ui->A15->setIcon(generar_icono(campo[0][14].icono));

    //B
    ui->B1->setIcon(generar_icono(campo[1][0].icono));
    ui->B1->setIconSize(QSize(41,41));
    ui->B2->setIcon(generar_icono(campo[1][1].icono));
    ui->B3->setIcon(generar_icono(campo[1][2].icono));
    ui->B4->setIcon(generar_icono(campo[1][3].icono));
    ui->B5->setIcon(generar_icono(campo[1][4].icono));
    ui->B6->setIcon(generar_icono(campo[1][5].icono));
    ui->B7->setIcon(generar_icono(campo[1][6].icono));
    ui->B8->setIcon(generar_icono(campo[1][7].icono));
    ui->B9->setIcon(generar_icono(campo[1][8].icono));
    ui->B10->setIcon(generar_icono(campo[1][9].icono));
    ui->B11->setIcon(generar_icono(campo[1][10].icono));
    ui->B12->setIcon(generar_icono(campo[1][11].icono));
    ui->B13->setIcon(generar_icono(campo[1][12].icono));
    ui->B14->setIcon(generar_icono(campo[1][13].icono));
    ui->B15->setIcon(generar_icono(campo[1][14].icono));

    //C
    ui->C1->setIcon(generar_icono(campo[2][0].icono));
    ui->C2->setIcon(generar_icono(campo[2][1].icono));
    ui->C3->setIcon(generar_icono(campo[2][2].icono));
    ui->C4->setIcon(generar_icono(campo[2][3].icono));
    ui->C5->setIcon(generar_icono(campo[2][4].icono));
    ui->C6->setIcon(generar_icono(campo[2][5].icono));
    ui->C7->setIcon(generar_icono(campo[2][6].icono));
    ui->C8->setIcon(generar_icono(campo[2][7].icono));
    ui->C9->setIcon(generar_icono(campo[2][8].icono));
    ui->C10->setIcon(generar_icono(campo[2][9].icono));
    ui->C11->setIcon(generar_icono(campo[2][10].icono));
    ui->C12->setIcon(generar_icono(campo[2][11].icono));
    ui->C13->setIcon(generar_icono(campo[2][12].icono));
    ui->C14->setIcon(generar_icono(campo[2][13].icono));
    ui->C15->setIcon(generar_icono(campo[2][14].icono));
    //D
    ui->D1->setIcon(generar_icono(campo[3][0].icono));
    ui->D2->setIcon(generar_icono(campo[3][1].icono));
    ui->D3->setIcon(generar_icono(campo[3][2].icono));
    ui->D4->setIcon(generar_icono(campo[3][3].icono));
    ui->D5->setIcon(generar_icono(campo[3][4].icono));
    ui->D6->setIcon(generar_icono(campo[3][5].icono));
    ui->D7->setIcon(generar_icono(campo[3][6].icono));
    ui->D8->setIcon(generar_icono(campo[3][7].icono));
    ui->D9->setIcon(generar_icono(campo[3][8].icono));
    ui->D10->setIcon(generar_icono(campo[3][9].icono));
    ui->D11->setIcon(generar_icono(campo[3][10].icono));
    ui->D12->setIcon(generar_icono(campo[3][11].icono));
    ui->D13->setIcon(generar_icono(campo[3][12].icono));
    ui->D14->setIcon(generar_icono(campo[3][13].icono));
    ui->D15->setIcon(generar_icono(campo[3][14].icono));
    //E
    ui->E1->setIcon(generar_icono(campo[4][0].icono));
    ui->E2->setIcon(generar_icono(campo[4][1].icono));
    ui->E3->setIcon(generar_icono(campo[4][2].icono));
    ui->E4->setIcon(generar_icono(campo[4][3].icono));
    ui->E5->setIcon(generar_icono(campo[4][4].icono));
    ui->E6->setIcon(generar_icono(campo[4][5].icono));
    ui->E7->setIcon(generar_icono(campo[4][6].icono));
    ui->E8->setIcon(generar_icono(campo[4][7].icono));
    ui->E9->setIcon(generar_icono(campo[4][8].icono));
    ui->E10->setIcon(generar_icono(campo[4][9].icono));
    ui->E11->setIcon(generar_icono(campo[4][10].icono));
    ui->E12->setIcon(generar_icono(campo[4][11].icono));
    ui->E13->setIcon(generar_icono(campo[4][12].icono));
    ui->E14->setIcon(generar_icono(campo[4][13].icono));
    ui->E15->setIcon(generar_icono(campo[4][14].icono));
    //F
    ui->F1->setIcon(generar_icono(campo[5][0].icono));
    ui->F2->setIcon(generar_icono(campo[5][1].icono));
    ui->F3->setIcon(generar_icono(campo[5][2].icono));
    ui->F4->setIcon(generar_icono(campo[5][3].icono));
    ui->F5->setIcon(generar_icono(campo[5][4].icono));
    ui->F6->setIcon(generar_icono(campo[5][5].icono));
    ui->F7->setIcon(generar_icono(campo[5][6].icono));
    ui->F8->setIcon(generar_icono(campo[5][7].icono));
    ui->F9->setIcon(generar_icono(campo[5][8].icono));
    ui->F10->setIcon(generar_icono(campo[5][9].icono));
    ui->F11->setIcon(generar_icono(campo[5][10].icono));
    ui->F12->setIcon(generar_icono(campo[5][11].icono));
    ui->F13->setIcon(generar_icono(campo[5][12].icono));
    ui->F14->setIcon(generar_icono(campo[5][13].icono));
    ui->F15->setIcon(generar_icono(campo[5][14].icono));
    //G
    ui->G1->setIcon(generar_icono(campo[6][0].icono));
    ui->G2->setIcon(generar_icono(campo[6][1].icono));
    ui->G3->setIcon(generar_icono(campo[6][2].icono));
    ui->G4->setIcon(generar_icono(campo[6][3].icono));
    ui->G5->setIcon(generar_icono(campo[6][4].icono));
    ui->G6->setIcon(generar_icono(campo[6][5].icono));
    ui->G7->setIcon(generar_icono(campo[6][6].icono));
    ui->G8->setIcon(generar_icono(campo[6][7].icono));
    ui->G9->setIcon(generar_icono(campo[6][8].icono));
    ui->G10->setIcon(generar_icono(campo[6][9].icono));
    ui->G11->setIcon(generar_icono(campo[6][10].icono));
    ui->G12->setIcon(generar_icono(campo[6][11].icono));
    ui->G13->setIcon(generar_icono(campo[6][12].icono));
    ui->G14->setIcon(generar_icono(campo[6][13].icono));
    ui->G15->setIcon(generar_icono(campo[6][14].icono));
    //H
    ui->H1->setIcon(generar_icono(campo[7][0].icono));
    ui->H2->setIcon(generar_icono(campo[7][1].icono));
    ui->H3->setIcon(generar_icono(campo[7][2].icono));
    ui->H4->setIcon(generar_icono(campo[7][3].icono));
    ui->H5->setIcon(generar_icono(campo[7][4].icono));
    ui->H6->setIcon(generar_icono(campo[7][5].icono));
    ui->H7->setIcon(generar_icono(campo[7][6].icono));
    ui->H8->setIcon(generar_icono(campo[7][7].icono));
    ui->H9->setIcon(generar_icono(campo[7][8].icono));
    ui->H10->setIcon(generar_icono(campo[7][9].icono));
    ui->H11->setIcon(generar_icono(campo[7][10].icono));
    ui->H12->setIcon(generar_icono(campo[7][11].icono));
    ui->H13->setIcon(generar_icono(campo[7][12].icono));
    ui->H14->setIcon(generar_icono(campo[7][13].icono));
    ui->H15->setIcon(generar_icono(campo[7][14].icono));
    //I
    ui->I1->setIcon(generar_icono(campo[8][0].icono));
    ui->I2->setIcon(generar_icono(campo[8][1].icono));
    ui->I3->setIcon(generar_icono(campo[8][2].icono));
    ui->I4->setIcon(generar_icono(campo[8][3].icono));
    ui->I5->setIcon(generar_icono(campo[8][4].icono));
    ui->I6->setIcon(generar_icono(campo[8][5].icono));
    ui->I7->setIcon(generar_icono(campo[8][6].icono));
    ui->I8->setIcon(generar_icono(campo[8][7].icono));
    ui->I9->setIcon(generar_icono(campo[8][8].icono));
    ui->I10->setIcon(generar_icono(campo[8][9].icono));
    ui->I11->setIcon(generar_icono(campo[8][10].icono));
    ui->I12->setIcon(generar_icono(campo[8][11].icono));
    ui->I13->setIcon(generar_icono(campo[8][12].icono));
    ui->I14->setIcon(generar_icono(campo[8][13].icono));
    ui->I15->setIcon(generar_icono(campo[8][14].icono));
    //J
    ui->J1->setIcon(generar_icono(campo[9][0].icono));
    ui->J2->setIcon(generar_icono(campo[9][1].icono));
    ui->J3->setIcon(generar_icono(campo[9][2].icono));
    ui->J4->setIcon(generar_icono(campo[9][3].icono));
    ui->J5->setIcon(generar_icono(campo[9][4].icono));
    ui->J6->setIcon(generar_icono(campo[9][5].icono));
    ui->J7->setIcon(generar_icono(campo[9][6].icono));
    ui->J8->setIcon(generar_icono(campo[9][7].icono));
    ui->J9->setIcon(generar_icono(campo[9][8].icono));
    ui->J10->setIcon(generar_icono(campo[9][9].icono));
    ui->J11->setIcon(generar_icono(campo[9][10].icono));
    ui->J12->setIcon(generar_icono(campo[9][11].icono));
    ui->J13->setIcon(generar_icono(campo[9][12].icono));
    ui->J14->setIcon(generar_icono(campo[9][13].icono));
    ui->J15->setIcon(generar_icono(campo[9][14].icono));
    //K
    ui->K1->setIcon(generar_icono(campo[10][0].icono));
    ui->K2->setIcon(generar_icono(campo[10][1].icono));
    ui->K3->setIcon(generar_icono(campo[10][2].icono));
    ui->K4->setIcon(generar_icono(campo[10][3].icono));
    ui->K5->setIcon(generar_icono(campo[10][4].icono));
    ui->K6->setIcon(generar_icono(campo[10][5].icono));
    ui->K7->setIcon(generar_icono(campo[10][6].icono));
    ui->K8->setIcon(generar_icono(campo[10][7].icono));
    ui->K9->setIcon(generar_icono(campo[10][8].icono));
    ui->K10->setIcon(generar_icono(campo[10][9].icono));
    ui->K11->setIcon(generar_icono(campo[10][10].icono));
    ui->K12->setIcon(generar_icono(campo[10][11].icono));
    ui->K13->setIcon(generar_icono(campo[10][12].icono));
    ui->K14->setIcon(generar_icono(campo[10][13].icono));
    ui->K15->setIcon(generar_icono(campo[10][14].icono));
    //L
    ui->L1->setIcon(generar_icono(campo[11][0].icono));
    ui->L2->setIcon(generar_icono(campo[11][1].icono));
    ui->L3->setIcon(generar_icono(campo[11][2].icono));
    ui->L4->setIcon(generar_icono(campo[11][3].icono));
    ui->L5->setIcon(generar_icono(campo[11][4].icono));
    ui->L6->setIcon(generar_icono(campo[11][5].icono));
    ui->L7->setIcon(generar_icono(campo[11][6].icono));
    ui->L8->setIcon(generar_icono(campo[11][7].icono));
    ui->L9->setIcon(generar_icono(campo[11][8].icono));
    ui->L10->setIcon(generar_icono(campo[11][9].icono));
    ui->L11->setIcon(generar_icono(campo[11][10].icono));
    ui->L12->setIcon(generar_icono(campo[11][11].icono));
    ui->L13->setIcon(generar_icono(campo[11][12].icono));
    ui->L14->setIcon(generar_icono(campo[11][13].icono));
    ui->L15->setIcon(generar_icono(campo[11][14].icono));
    //M
    ui->M1->setIcon(generar_icono(campo[12][0].icono));
    ui->M2->setIcon(generar_icono(campo[12][1].icono));
    ui->M3->setIcon(generar_icono(campo[12][2].icono));
    ui->M4->setIcon(generar_icono(campo[12][3].icono));
    ui->M5->setIcon(generar_icono(campo[12][4].icono));
    ui->M6->setIcon(generar_icono(campo[12][5].icono));
    ui->M7->setIcon(generar_icono(campo[12][6].icono));
    ui->M8->setIcon(generar_icono(campo[12][7].icono));
    ui->M9->setIcon(generar_icono(campo[12][8].icono));
    ui->M10->setIcon(generar_icono(campo[12][9].icono));
    ui->M11->setIcon(generar_icono(campo[12][10].icono));
    ui->M12->setIcon(generar_icono(campo[12][11].icono));
    ui->M13->setIcon(generar_icono(campo[12][12].icono));
    ui->M14->setIcon(generar_icono(campo[12][13].icono));
    ui->M15->setIcon(generar_icono(campo[12][14].icono));
    //N
    ui->N1->setIcon(generar_icono(campo[13][0].icono));
    ui->N2->setIcon(generar_icono(campo[13][1].icono));
    ui->N3->setIcon(generar_icono(campo[13][2].icono));
    ui->N4->setIcon(generar_icono(campo[13][3].icono));
    ui->N5->setIcon(generar_icono(campo[13][4].icono));
    ui->N6->setIcon(generar_icono(campo[13][5].icono));
    ui->N7->setIcon(generar_icono(campo[13][6].icono));
    ui->N8->setIcon(generar_icono(campo[13][7].icono));
    ui->N9->setIcon(generar_icono(campo[13][8].icono));
    ui->N10->setIcon(generar_icono(campo[13][9].icono));
    ui->N11->setIcon(generar_icono(campo[13][10].icono));
    ui->N12->setIcon(generar_icono(campo[13][11].icono));
    ui->N13->setIcon(generar_icono(campo[13][12].icono));
    ui->N14->setIcon(generar_icono(campo[13][13].icono));
    ui->N15->setIcon(generar_icono(campo[13][14].icono));
    //O
    ui->O1->setIcon(generar_icono(campo[14][0].icono));
    ui->O2->setIcon(generar_icono(campo[14][1].icono));
    ui->O3->setIcon(generar_icono(campo[14][2].icono));
    ui->O4->setIcon(generar_icono(campo[14][3].icono));
    ui->O5->setIcon(generar_icono(campo[14][4].icono));
    ui->O6->setIcon(generar_icono(campo[14][5].icono));
    ui->O7->setIcon(generar_icono(campo[14][6].icono));
    ui->O8->setIcon(generar_icono(campo[14][7].icono));
    ui->O9->setIcon(generar_icono(campo[14][8].icono));
    ui->O10->setIcon(generar_icono(campo[14][9].icono));
    ui->O11->setIcon(generar_icono(campo[14][10].icono));
    ui->O12->setIcon(generar_icono(campo[14][11].icono));
    ui->O13->setIcon(generar_icono(campo[14][12].icono));
    ui->O14->setIcon(generar_icono(campo[14][13].icono));
    ui->O15->setIcon(generar_icono(campo[14][14].icono));

    ui->A1->setIconSize(QSize(41,41));
    ui->A2->setIconSize(QSize(41,41));
    ui->A3->setIconSize(QSize(41,41));
    ui->A4->setIconSize(QSize(41,41));
    ui->A5->setIconSize(QSize(41,41));
    ui->A6->setIconSize(QSize(41,41));
    ui->A7->setIconSize(QSize(41,41));
    ui->A8->setIconSize(QSize(41,41));
    ui->A9->setIconSize(QSize(41,41));
    ui->A10->setIconSize(QSize(41,41));
    ui->A11->setIconSize(QSize(41,41));
    ui->A12->setIconSize(QSize(41,41));
    ui->A13->setIconSize(QSize(41,41));
    ui->A14->setIconSize(QSize(41,41));
    ui->A15->setIconSize(QSize(41,41));

    ui->B1->setIconSize(QSize(41,41));
    ui->B2->setIconSize(QSize(41,41));
    ui->B3->setIconSize(QSize(41,41));
    ui->B4->setIconSize(QSize(41,41));
    ui->B5->setIconSize(QSize(41,41));
    ui->B6->setIconSize(QSize(41,41));
    ui->B7->setIconSize(QSize(41,41));
    ui->B8->setIconSize(QSize(41,41));
    ui->B9->setIconSize(QSize(41,41));
    ui->B10->setIconSize(QSize(41,41));
    ui->B11->setIconSize(QSize(41,41));
    ui->B12->setIconSize(QSize(41,41));
    ui->B13->setIconSize(QSize(41,41));
    ui->B14->setIconSize(QSize(41,41));
    ui->B15->setIconSize(QSize(41,41));

    ui->C1->setIconSize(QSize(41,41));
    ui->C2->setIconSize(QSize(41,41));
    ui->C3->setIconSize(QSize(41,41));
    ui->C4->setIconSize(QSize(41,41));
    ui->C5->setIconSize(QSize(41,41));
    ui->C6->setIconSize(QSize(41,41));
    ui->C7->setIconSize(QSize(41,41));
    ui->C8->setIconSize(QSize(41,41));
    ui->C9->setIconSize(QSize(41,41));
    ui->C10->setIconSize(QSize(41,41));
    ui->C11->setIconSize(QSize(41,41));
    ui->C12->setIconSize(QSize(41,41));
    ui->C13->setIconSize(QSize(41,41));
    ui->C14->setIconSize(QSize(41,41));
    ui->C15->setIconSize(QSize(41,41));

    ui->D1->setIconSize(QSize(41,41));
    ui->D2->setIconSize(QSize(41,41));
    ui->D3->setIconSize(QSize(41,41));
    ui->D4->setIconSize(QSize(41,41));
    ui->D5->setIconSize(QSize(41,41));
    ui->D6->setIconSize(QSize(41,41));
    ui->D7->setIconSize(QSize(41,41));
    ui->D8->setIconSize(QSize(41,41));
    ui->D9->setIconSize(QSize(41,41));
    ui->D10->setIconSize(QSize(41,41));
    ui->D11->setIconSize(QSize(41,41));
    ui->D12->setIconSize(QSize(41,41));
    ui->D13->setIconSize(QSize(41,41));
    ui->D14->setIconSize(QSize(41,41));
    ui->D15->setIconSize(QSize(41,41));

    ui->F1->setIconSize(QSize(41,41));
    ui->F2->setIconSize(QSize(41,41));
    ui->F3->setIconSize(QSize(41,41));
    ui->F4->setIconSize(QSize(41,41));
    ui->F5->setIconSize(QSize(41,41));
    ui->F6->setIconSize(QSize(41,41));
    ui->F7->setIconSize(QSize(41,41));
    ui->F8->setIconSize(QSize(41,41));
    ui->F9->setIconSize(QSize(41,41));
    ui->F10->setIconSize(QSize(41,41));
    ui->F11->setIconSize(QSize(41,41));
    ui->F12->setIconSize(QSize(41,41));
    ui->F13->setIconSize(QSize(41,41));
    ui->F14->setIconSize(QSize(41,41));
    ui->F15->setIconSize(QSize(41,41));

    ui->E1->setIconSize(QSize(41,41));
    ui->E2->setIconSize(QSize(41,41));
    ui->E3->setIconSize(QSize(41,41));
    ui->E4->setIconSize(QSize(41,41));
    ui->E5->setIconSize(QSize(41,41));
    ui->E6->setIconSize(QSize(41,41));
    ui->E7->setIconSize(QSize(41,41));
    ui->E8->setIconSize(QSize(41,41));
    ui->E9->setIconSize(QSize(41,41));
    ui->E10->setIconSize(QSize(41,41));
    ui->E11->setIconSize(QSize(41,41));
    ui->E12->setIconSize(QSize(41,41));
    ui->E13->setIconSize(QSize(41,41));
    ui->E14->setIconSize(QSize(41,41));
    ui->E15->setIconSize(QSize(41,41));

    ui->G1->setIconSize(QSize(41,41));
    ui->G2->setIconSize(QSize(41,41));
    ui->G3->setIconSize(QSize(41,41));
    ui->G4->setIconSize(QSize(41,41));
    ui->G5->setIconSize(QSize(41,41));
    ui->G6->setIconSize(QSize(41,41));
    ui->G7->setIconSize(QSize(41,41));
    ui->G8->setIconSize(QSize(41,41));
    ui->G9->setIconSize(QSize(41,41));
    ui->G10->setIconSize(QSize(41,41));
    ui->G11->setIconSize(QSize(41,41));
    ui->G12->setIconSize(QSize(41,41));
    ui->G13->setIconSize(QSize(41,41));
    ui->G14->setIconSize(QSize(41,41));
    ui->G15->setIconSize(QSize(41,41));

    ui->H1->setIconSize(QSize(41,41));
    ui->H2->setIconSize(QSize(41,41));
    ui->H3->setIconSize(QSize(41,41));
    ui->H4->setIconSize(QSize(41,41));
    ui->H5->setIconSize(QSize(41,41));
    ui->H6->setIconSize(QSize(41,41));
    ui->H7->setIconSize(QSize(41,41));
    ui->H8->setIconSize(QSize(41,41));
    ui->H9->setIconSize(QSize(41,41));
    ui->H10->setIconSize(QSize(41,41));
    ui->H11->setIconSize(QSize(41,41));
    ui->H12->setIconSize(QSize(41,41));
    ui->H13->setIconSize(QSize(41,41));
    ui->H14->setIconSize(QSize(41,41));
    ui->H15->setIconSize(QSize(41,41));

    ui->I1->setIconSize(QSize(41,41));
    ui->I2->setIconSize(QSize(41,41));
    ui->I3->setIconSize(QSize(41,41));
    ui->I4->setIconSize(QSize(41,41));
    ui->I5->setIconSize(QSize(41,41));
    ui->I6->setIconSize(QSize(41,41));
    ui->I7->setIconSize(QSize(41,41));
    ui->I8->setIconSize(QSize(41,41));
    ui->I9->setIconSize(QSize(41,41));
    ui->I10->setIconSize(QSize(41,41));
    ui->I11->setIconSize(QSize(41,41));
    ui->I12->setIconSize(QSize(41,41));
    ui->I13->setIconSize(QSize(41,41));
    ui->I14->setIconSize(QSize(41,41));
    ui->I15->setIconSize(QSize(41,41));

    ui->J1->setIconSize(QSize(41,41));
    ui->J2->setIconSize(QSize(41,41));
    ui->J3->setIconSize(QSize(41,41));
    ui->J4->setIconSize(QSize(41,41));
    ui->J5->setIconSize(QSize(41,41));
    ui->J6->setIconSize(QSize(41,41));
    ui->J7->setIconSize(QSize(41,41));
    ui->J8->setIconSize(QSize(41,41));
    ui->J9->setIconSize(QSize(41,41));
    ui->J10->setIconSize(QSize(41,41));
    ui->J11->setIconSize(QSize(41,41));
    ui->J12->setIconSize(QSize(41,41));
    ui->J13->setIconSize(QSize(41,41));
    ui->J14->setIconSize(QSize(41,41));
    ui->J15->setIconSize(QSize(41,41));

    ui->K1->setIconSize(QSize(41,41));
    ui->K2->setIconSize(QSize(41,41));
    ui->K3->setIconSize(QSize(41,41));
    ui->K4->setIconSize(QSize(41,41));
    ui->K5->setIconSize(QSize(41,41));
    ui->K6->setIconSize(QSize(41,41));
    ui->K7->setIconSize(QSize(41,41));
    ui->K8->setIconSize(QSize(41,41));
    ui->K9->setIconSize(QSize(41,41));
    ui->K10->setIconSize(QSize(41,41));
    ui->K11->setIconSize(QSize(41,41));
    ui->K12->setIconSize(QSize(41,41));
    ui->K13->setIconSize(QSize(41,41));
    ui->K14->setIconSize(QSize(41,41));
    ui->K15->setIconSize(QSize(41,41));

    ui->L1->setIconSize(QSize(41,41));
    ui->L2->setIconSize(QSize(41,41));
    ui->L3->setIconSize(QSize(41,41));
    ui->L4->setIconSize(QSize(41,41));
    ui->L5->setIconSize(QSize(41,41));
    ui->L6->setIconSize(QSize(41,41));
    ui->L7->setIconSize(QSize(41,41));
    ui->L8->setIconSize(QSize(41,41));
    ui->L9->setIconSize(QSize(41,41));
    ui->L10->setIconSize(QSize(41,41));
    ui->L11->setIconSize(QSize(41,41));
    ui->L12->setIconSize(QSize(41,41));
    ui->L13->setIconSize(QSize(41,41));
    ui->L14->setIconSize(QSize(41,41));
    ui->L15->setIconSize(QSize(41,41));

    ui->M1->setIconSize(QSize(41,41));
    ui->M2->setIconSize(QSize(41,41));
    ui->M3->setIconSize(QSize(41,41));
    ui->M4->setIconSize(QSize(41,41));
    ui->M5->setIconSize(QSize(41,41));
    ui->M6->setIconSize(QSize(41,41));
    ui->M7->setIconSize(QSize(41,41));
    ui->M8->setIconSize(QSize(41,41));
    ui->M9->setIconSize(QSize(41,41));
    ui->M10->setIconSize(QSize(41,41));
    ui->M11->setIconSize(QSize(41,41));
    ui->M12->setIconSize(QSize(41,41));
    ui->M13->setIconSize(QSize(41,41));
    ui->M14->setIconSize(QSize(41,41));
    ui->M15->setIconSize(QSize(41,41));

    ui->N1->setIconSize(QSize(41,41));
    ui->N2->setIconSize(QSize(41,41));
    ui->N3->setIconSize(QSize(41,41));
    ui->N4->setIconSize(QSize(41,41));
    ui->N5->setIconSize(QSize(41,41));
    ui->N6->setIconSize(QSize(41,41));
    ui->N7->setIconSize(QSize(41,41));
    ui->N8->setIconSize(QSize(41,41));
    ui->N9->setIconSize(QSize(41,41));
    ui->N10->setIconSize(QSize(41,41));
    ui->N11->setIconSize(QSize(41,41));
    ui->N12->setIconSize(QSize(41,41));
    ui->N13->setIconSize(QSize(41,41));
    ui->N14->setIconSize(QSize(41,41));
    ui->N15->setIconSize(QSize(41,41));

    ui->O1->setIconSize(QSize(41,41));
    ui->O2->setIconSize(QSize(41,41));
    ui->O3->setIconSize(QSize(41,41));
    ui->O4->setIconSize(QSize(41,41));
    ui->O5->setIconSize(QSize(41,41));
    ui->O6->setIconSize(QSize(41,41));
    ui->O7->setIconSize(QSize(41,41));
    ui->O8->setIconSize(QSize(41,41));
    ui->O9->setIconSize(QSize(41,41));
    ui->O10->setIconSize(QSize(41,41));
    ui->O11->setIconSize(QSize(41,41));
    ui->O12->setIconSize(QSize(41,41));
    ui->O13->setIconSize(QSize(41,41));
    ui->O14->setIconSize(QSize(41,41));
    ui->O15->setIconSize(QSize(41,41));


}

QIcon MainWindow::generar_icono(string nombre)
{

    if(nombre=="Ciudad"){
        QPixmap pixmap("iconos/ciudad.png");
        QIcon Icon(pixmap);
        return Icon;
    }
    else if(nombre=="Mar"){
        QPixmap pixmap("iconos/agua.png");
        QIcon Icon(pixmap);
        return Icon;
    }
    else if(nombre=="Playa"){
        QPixmap pixmap("iconos/playa.png");
        QIcon Icon(pixmap);
        return Icon;
    }
    else if(nombre=="Desierto"){
        QPixmap pixmap("iconos/desierto.png");
        QIcon Icon(pixmap);
        return Icon;
    }
    else if(nombre=="Bosque"){
        QPixmap pixmap("iconos/bosque.png");
        QIcon Icon(pixmap);
        return Icon;
    }
    else if(nombre=="Montana"){
        QPixmap pixmap("iconos/montana.png");
        QIcon Icon(pixmap);
        return Icon;
    }
    else if(nombre=="Pueblo"){
        QPixmap pixmap("iconos/pueblo.png");
        QIcon Icon(pixmap);
        return Icon;
    }
    else if(nombre=="Loma"){
        QPixmap pixmap("iconos/lomas.png");
        QIcon Icon(pixmap);
        return Icon;
    }
    else if(nombre=="Nieve"){
        QPixmap pixmap("iconos/nieve.png");
        QIcon Icon(pixmap);
        return Icon;
    }
    else if(nombre=="Pared"){
        QPixmap pixmap("iconos/pared.png");
        QIcon Icon(pixmap);
        return Icon;
    }
    else if(nombre=="Ballena"){
        QPixmap pixmap("iconos/ballena.png");
        QIcon Icon(pixmap);
        return Icon;
    }
    else if(nombre=="Mono"){
        QPixmap pixmap("iconos/mono.png");
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

void MainWindow::generar_personajes()
{
    if(persona.size()==1){
        ui->pb_personaje->setIcon(generar_icono(persona[0].icono));
        ui->pb_personaje->setIconSize(QSize(51,51));
        ui->pb_personaje_2->setGeometry(0,0,0,0);
        ui->pb_personaje3->setGeometry(0,0,0,0);
        ui->radioButton_2->setGeometry(0,0,0,0);
        ui->radioButton_3->setGeometry(0,0,0,0);
    }
    else if(persona.size()==2){
        ui->pb_personaje->setIcon(generar_icono(persona[0].icono));
        ui->pb_personaje->setIconSize(QSize(51,51));
        ui->pb_personaje_2->setIcon(generar_icono(persona[1].icono));
        ui->pb_personaje_2->setIconSize(QSize(51,51));
        ui->pb_personaje3->setGeometry(0,0,0,0);
        ui->radioButton_3->setGeometry(0,0,0,0);

    }
    else if(persona.size()==3){
        ui->pb_personaje->setIcon(generar_icono(persona[0].icono));
        ui->pb_personaje->setIconSize(QSize(51,51));
        ui->pb_personaje_2->setIcon(generar_icono(persona[1].icono));
        ui->pb_personaje_2->setIconSize(QSize(51,51));
        ui->pb_personaje3->setIcon(generar_icono(persona[2].icono));
        ui->pb_personaje3->setIconSize(QSize(51,51));

    }
}

void MainWindow::on_A1_clicked()
{
    QMessageBox msg;
    QString mensaje ="Coordenada: A1\nTerreno: " +QString::fromStdString(campo[0][0].nombre);
    msg.setText(mensaje);
    msg.exec();
}
void MainWindow::on_A2_clicked()
{
    QMessageBox msg;
    QString mensaje ="Coordenada: A2\nTerreno: " +QString::fromStdString(campo[0][1].nombre);
    msg.setText(mensaje);
    msg.exec();
}
void MainWindow::on_A3_clicked()
{
    QMessageBox msg;
    QString mensaje ="Coordenada: A3\nTerreno: " +QString::fromStdString(campo[0][2].nombre);
    msg.setText(mensaje);
    msg.exec();
}
void MainWindow::on_A4_clicked()
{
    QMessageBox msg;
    QString mensaje ="Coordenada: A4\nTerreno: " +QString::fromStdString(campo[0][3].nombre);
    msg.setText(mensaje);
    msg.exec();
}
void MainWindow::on_A5_clicked()
{
    QMessageBox msg;
    QString mensaje ="Coordenada: A5\nTerreno: " +QString::fromStdString(campo[0][4].nombre);
    msg.setText(mensaje);
    msg.exec();
}
void MainWindow::on_A6_clicked()
{
    QMessageBox msg;
    QString mensaje ="Coordenada: A6\nTerreno: " +QString::fromStdString(campo[0][5].nombre);
    msg.setText(mensaje);
    msg.exec();
}
void MainWindow::on_A7_clicked()
{
    QMessageBox msg;
    QString mensaje ="Coordenada: A7\nTerreno: " +QString::fromStdString(campo[0][6].nombre);
    msg.setText(mensaje);
    msg.exec();
}
void MainWindow::on_A8_clicked()
{
    QMessageBox msg;
    QString mensaje ="Coordenada: A8\nTerreno: " +QString::fromStdString(campo[0][7].nombre);
    msg.setText(mensaje);
    msg.exec();
}
void MainWindow::on_A9_clicked()
{
    QMessageBox msg;
    QString mensaje ="Coordenada: A9\nTerreno: " +QString::fromStdString(campo[0][8].nombre);
    msg.setText(mensaje);
    msg.exec();
}
void MainWindow::on_A10_clicked()
{
    QMessageBox msg;
    QString mensaje ="Coordenada: A10\nTerreno: " +QString::fromStdString(campo[0][9].nombre);
    msg.setText(mensaje);
    msg.exec();
}
void MainWindow::on_A11_clicked()
{
    QMessageBox msg;
    QString mensaje ="Coordenada: A11\nTerreno: " +QString::fromStdString(campo[0][10].nombre);
    msg.setText(mensaje);
    msg.exec();
}
void MainWindow::on_A12_clicked()
{
    QMessageBox msg;
    QString mensaje ="Coordenada: A12\nTerreno: " +QString::fromStdString(campo[0][11].nombre);
    msg.setText(mensaje);
    msg.exec();
}
void MainWindow::on_A13_clicked()
{
    QMessageBox msg;
    QString mensaje ="Coordenada: A13\nTerreno: " +QString::fromStdString(campo[0][12].nombre);
    msg.setText(mensaje);
    msg.exec();
}
void MainWindow::on_A14_clicked()
{
    QMessageBox msg;
    QString mensaje ="Coordenada: A14\nTerreno: " +QString::fromStdString(campo[0][13].nombre);
    msg.setText(mensaje);
    msg.exec();
}
void MainWindow::on_A15_clicked()
{
    QMessageBox msg;
    QString mensaje ="Coordenada: A15\nTerreno: " +QString::fromStdString(campo[0][14].nombre);
    msg.setText(mensaje);
    msg.exec();
}
//B
void MainWindow::on_B1_clicked()
{
    QMessageBox msg;
    QString mensaje ="Coordenada: B1\nTerreno: " +QString::fromStdString(campo[1][0].nombre);
    msg.setText(mensaje);
    msg.exec();
}
void MainWindow::on_B2_clicked()
{
    QMessageBox msg;
    QString mensaje ="Coordenada: B2\nTerreno: " +QString::fromStdString(campo[1][1].nombre);
    msg.setText(mensaje);
    msg.exec();
}
void MainWindow::on_B3_clicked()
{
    QMessageBox msg;
    QString mensaje ="Coordenada B:3\nTerreno: " +QString::fromStdString(campo[1][2].nombre);
    msg.setText(mensaje);
    msg.exec();
}
void MainWindow::on_B4_clicked()
{
    QMessageBox msg;
    QString mensaje ="Coordenada: B4\nTerreno: " +QString::fromStdString(campo[1][3].nombre);
    msg.setText(mensaje);
    msg.exec();
}
void MainWindow::on_B5_clicked()
{
    QMessageBox msg;
    QString mensaje ="Coordenada: B5\nTerreno: " +QString::fromStdString(campo[1][4].nombre);
    msg.setText(mensaje);
    msg.exec();
}
void MainWindow::on_B6_clicked()
{
    QMessageBox msg;
    QString mensaje ="Coordenada: B6\nTerreno: " +QString::fromStdString(campo[1][5].nombre);
    msg.setText(mensaje);
    msg.exec();
}
void MainWindow::on_B7_clicked()
{
    QMessageBox msg;
    QString mensaje ="Coordenada: B7\nTerreno: " +QString::fromStdString(campo[1][6].nombre);
    msg.setText(mensaje);
    msg.exec();
}
void MainWindow::on_B8_clicked()
{
    QMessageBox msg;
    QString mensaje ="Coordenada: B8\nTerreno: " +QString::fromStdString(campo[1][7].nombre);
    msg.setText(mensaje);
    msg.exec();
}
void MainWindow::on_B9_clicked()
{
    QMessageBox msg;
    QString mensaje ="Coordenada: B9\nTerreno: " +QString::fromStdString(campo[1][8].nombre);
    msg.setText(mensaje);
    msg.exec();
}
void MainWindow::on_B10_clicked()
{
    QMessageBox msg;
    QString mensaje ="Coordenada: B10\nTerreno: " +QString::fromStdString(campo[1][9].nombre);
    msg.setText(mensaje);
    msg.exec();
}
void MainWindow::on_B11_clicked()
{
    QMessageBox msg;
    QString mensaje ="Coordenada: B11\nTerreno: " +QString::fromStdString(campo[1][10].nombre);
    msg.setText(mensaje);
    msg.exec();
}
void MainWindow::on_B12_clicked()
{
    QMessageBox msg;
    QString mensaje ="Coordenada: B12\nTerreno: " +QString::fromStdString(campo[1][11].nombre);
    msg.setText(mensaje);
    msg.exec();
}
void MainWindow::on_B13_clicked()
{
    QMessageBox msg;
    QString mensaje ="Coordenada: B13\nTerreno: " +QString::fromStdString(campo[1][12].nombre);
    msg.setText(mensaje);
    msg.exec();
}
void MainWindow::on_B14_clicked()
{
    QMessageBox msg;
    QString mensaje ="Coordenada: B14\nTerreno: " +QString::fromStdString(campo[1][13].nombre);
    msg.setText(mensaje);
    msg.exec();
}
void MainWindow::on_B15_clicked()
{
    QMessageBox msg;
    QString mensaje ="Coordenada: B15\nTerreno: " +QString::fromStdString(campo[1][14].nombre);
    msg.setText(mensaje);
    msg.exec();
}
//C
void MainWindow::on_C1_clicked()
{
    QMessageBox msg;
    QString mensaje ="Coordenada: C1\nTerreno: " +QString::fromStdString(campo[2][0].nombre);
    msg.setText(mensaje);
    msg.exec();
}
void MainWindow::on_C2_clicked()
{
    QMessageBox msg;
    QString mensaje ="Coordenada: C2\nTerreno: " +QString::fromStdString(campo[2][1].nombre);
    msg.setText(mensaje);
    msg.exec();
}
void MainWindow::on_C3_clicked()
{
    QMessageBox msg;
    QString mensaje ="Coordenada: C3\nTerreno: " +QString::fromStdString(campo[2][2].nombre);
    msg.setText(mensaje);
    msg.exec();
}
void MainWindow::on_C4_clicked()
{
    QMessageBox msg;
    QString mensaje ="Coordenada: C4\nTerreno: " +QString::fromStdString(campo[2][3].nombre);
    msg.setText(mensaje);
    msg.exec();
}
void MainWindow::on_C5_clicked()
{
    QMessageBox msg;
    QString mensaje ="Coordenada: C5\nTerreno: " +QString::fromStdString(campo[2][4].nombre);
    msg.setText(mensaje);
    msg.exec();
}
void MainWindow::on_C6_clicked()
{
    QMessageBox msg;
    QString mensaje ="Coordenada: C6\nTerreno: " +QString::fromStdString(campo[2][5].nombre);
    msg.setText(mensaje);
    msg.exec();
}
void MainWindow::on_C7_clicked()
{
    QMessageBox msg;
    QString mensaje ="Coordenada: C7\nTerreno: " +QString::fromStdString(campo[2][6].nombre);
    msg.setText(mensaje);
    msg.exec();
}
void MainWindow::on_C8_clicked()
{
    QMessageBox msg;
    QString mensaje ="Coordenada: C8\nTerreno: " +QString::fromStdString(campo[2][7].nombre);
    msg.setText(mensaje);
    msg.exec();
}
void MainWindow::on_C9_clicked()
{
    QMessageBox msg;
    QString mensaje ="Coordenada: C9\nTerreno: " +QString::fromStdString(campo[2][8].nombre);
    msg.setText(mensaje);
    msg.exec();
}
void MainWindow::on_C10_clicked()
{
    QMessageBox msg;
    QString mensaje ="Coordenada: C10\nTerreno: " +QString::fromStdString(campo[2][9].nombre);
    msg.setText(mensaje);
    msg.exec();
}
void MainWindow::on_C11_clicked()
{
    QMessageBox msg;
    QString mensaje ="Coordenada: C11\nTerreno: " +QString::fromStdString(campo[2][10].nombre);
    msg.setText(mensaje);
    msg.exec();
}
void MainWindow::on_C12_clicked()
{
    QMessageBox msg;
    QString mensaje ="Coordenada: C12\nTerreno: " +QString::fromStdString(campo[2][11].nombre);
    msg.setText(mensaje);
    msg.exec();
}
void MainWindow::on_C13_clicked()
{
    QMessageBox msg;
    QString mensaje ="Coordenada: C13\nTerreno: " +QString::fromStdString(campo[2][12].nombre);
    msg.setText(mensaje);
    msg.exec();
}
void MainWindow::on_C14_clicked()
{
    QMessageBox msg;
    QString mensaje ="Coordenada: C14\nTerreno: " +QString::fromStdString(campo[2][13].nombre);
    msg.setText(mensaje);
    msg.exec();
}
void MainWindow::on_C15_clicked()
{
    QMessageBox msg;
    QString mensaje ="Coordenada: C15\nTerreno: " +QString::fromStdString(campo[2][14].nombre);
    msg.setText(mensaje);
    msg.exec();
}
//D
void MainWindow::on_D1_clicked()
{
    QMessageBox msg;
    QString mensaje ="Coordenada: D1\nTerreno: " +QString::fromStdString(campo[3][0].nombre);
    msg.setText(mensaje);
    msg.exec();
}
void MainWindow::on_D2_clicked()
{
    QMessageBox msg;
    QString mensaje ="Coordenada: D2\nTerreno: " +QString::fromStdString(campo[3][1].nombre);
    msg.setText(mensaje);
    msg.exec();
}
void MainWindow::on_D3_clicked()
{
    QMessageBox msg;
    QString mensaje ="Coordenada: D3\nTerreno: " +QString::fromStdString(campo[3][2].nombre);
    msg.setText(mensaje);
    msg.exec();
}
void MainWindow::on_D4_clicked()
{
    QMessageBox msg;
    QString mensaje ="Coordenada: D4\nTerreno: " +QString::fromStdString(campo[3][3].nombre);
    msg.setText(mensaje);
    msg.exec();
}
void MainWindow::on_D5_clicked()
{
    QMessageBox msg;
    QString mensaje ="Coordenada: D5\nTerreno: " +QString::fromStdString(campo[3][4].nombre);
    msg.setText(mensaje);
    msg.exec();
}
void MainWindow::on_D6_clicked()
{
    QMessageBox msg;
    QString mensaje ="Coordenada: D6\nTerreno: " +QString::fromStdString(campo[3][5].nombre);
    msg.setText(mensaje);
    msg.exec();
}
void MainWindow::on_D7_clicked()
{
    QMessageBox msg;
    QString mensaje ="Coordenada: D7\nTerreno: " +QString::fromStdString(campo[3][6].nombre);
    msg.setText(mensaje);
    msg.exec();
}
void MainWindow::on_D8_clicked()
{
    QMessageBox msg;
    QString mensaje ="Coordenada: D8\nTerreno: " +QString::fromStdString(campo[3][7].nombre);
    msg.setText(mensaje);
    msg.exec();
}
void MainWindow::on_D9_clicked()
{
    QMessageBox msg;
    QString mensaje ="Coordenada: D9\nTerreno: " +QString::fromStdString(campo[3][8].nombre);
    msg.setText(mensaje);
    msg.exec();
}
void MainWindow::on_D10_clicked()
{
    QMessageBox msg;
    QString mensaje ="Coordenada: D10\nTerreno: " +QString::fromStdString(campo[3][9].nombre);
    msg.setText(mensaje);
    msg.exec();
}
void MainWindow::on_D11_clicked()
{
    QMessageBox msg;
    QString mensaje ="Coordenada: D11\nTerreno: " +QString::fromStdString(campo[3][10].nombre);
    msg.setText(mensaje);
    msg.exec();
}
void MainWindow::on_D12_clicked()
{
    QMessageBox msg;
    QString mensaje ="Coordenada: D12\nTerreno: " +QString::fromStdString(campo[3][11].nombre);
    msg.setText(mensaje);
    msg.exec();
}
void MainWindow::on_D13_clicked()
{
    QMessageBox msg;
    QString mensaje ="Coordenada: D13\nTerreno: " +QString::fromStdString(campo[3][12].nombre);
    msg.setText(mensaje);
    msg.exec();
}
void MainWindow::on_D14_clicked()
{
    QMessageBox msg;
    QString mensaje ="Coordenada: D14\nTerreno: " +QString::fromStdString(campo[3][13].nombre);
    msg.setText(mensaje);
    msg.exec();
}
void MainWindow::on_D15_clicked()
{
    QMessageBox msg;
    QString mensaje ="Coordenada: D15\nTerreno: " +QString::fromStdString(campo[3][14].nombre);
    msg.setText(mensaje);
    msg.exec();
}
//E
void MainWindow::on_E1_clicked()
{
    QMessageBox msg;
    QString mensaje ="Coordenada: E1\nTerreno: " +QString::fromStdString(campo[4][0].nombre);
    msg.setText(mensaje);
    msg.exec();
}
void MainWindow::on_E2_clicked()
{
    QMessageBox msg;
    QString mensaje ="Coordenada: E2\nTerreno: " +QString::fromStdString(campo[4][1].nombre);
    msg.setText(mensaje);
    msg.exec();
}
void MainWindow::on_E3_clicked()
{
    QMessageBox msg;
    QString mensaje ="Coordenada: E3\nTerreno: " +QString::fromStdString(campo[4][2].nombre);
    msg.setText(mensaje);
    msg.exec();
}
void MainWindow::on_E4_clicked()
{
    QMessageBox msg;
    QString mensaje ="Coordenada: E4\nTerreno: " +QString::fromStdString(campo[4][3].nombre);
    msg.setText(mensaje);
    msg.exec();
}
void MainWindow::on_E5_clicked()
{
    QMessageBox msg;
    QString mensaje ="Coordenada: E5\nTerreno: " +QString::fromStdString(campo[4][4].nombre);
    msg.setText(mensaje);
    msg.exec();
}
void MainWindow::on_E6_clicked()
{
    QMessageBox msg;
    QString mensaje ="Coordenada: E6\nTerreno: " +QString::fromStdString(campo[4][5].nombre);
    msg.setText(mensaje);
    msg.exec();
}
void MainWindow::on_E7_clicked()
{
    QMessageBox msg;
    QString mensaje ="Coordenada: E7\nTerreno: " +QString::fromStdString(campo[4][6].nombre);
    msg.setText(mensaje);
    msg.exec();
}
void MainWindow::on_E8_clicked()
{
    QMessageBox msg;
    QString mensaje ="Coordenada: E8\nTerreno: " +QString::fromStdString(campo[4][7].nombre);
    msg.setText(mensaje);
    msg.exec();
}
void MainWindow::on_E9_clicked()
{
    QMessageBox msg;
    QString mensaje ="Coordenada: E9\nTerreno: " +QString::fromStdString(campo[4][8].nombre);
    msg.setText(mensaje);
    msg.exec();
}
void MainWindow::on_E10_clicked()
{
    QMessageBox msg;
    QString mensaje ="Coordenada: E10\nTerreno: " +QString::fromStdString(campo[4][9].nombre);
    msg.setText(mensaje);
    msg.exec();
}
void MainWindow::on_E11_clicked()
{
    QMessageBox msg;
    QString mensaje ="Coordenada: E11\nTerreno: " +QString::fromStdString(campo[4][10].nombre);
    msg.setText(mensaje);
    msg.exec();
}
void MainWindow::on_E12_clicked()
{
    QMessageBox msg;
    QString mensaje ="Coordenada: E12\nTerreno: " +QString::fromStdString(campo[4][11].nombre);
    msg.setText(mensaje);
    msg.exec();
}
void MainWindow::on_E13_clicked()
{
    QMessageBox msg;
    QString mensaje ="Coordenada: E13\nTerreno: " +QString::fromStdString(campo[4][12].nombre);
    msg.setText(mensaje);
    msg.exec();
}
void MainWindow::on_E14_clicked()
{
    QMessageBox msg;
    QString mensaje ="Coordenada: E14\nTerreno: " +QString::fromStdString(campo[4][13].nombre);
    msg.setText(mensaje);
    msg.exec();
}
void MainWindow::on_E15_clicked()
{
    QMessageBox msg;
    QString mensaje ="Coordenada: E15\nTerreno: " +QString::fromStdString(campo[4][14].nombre);
    msg.setText(mensaje);
    msg.exec();
}
//F
void MainWindow::on_F1_clicked()
{
    QMessageBox msg;
    QString mensaje ="Coordenada: F1\nTerreno: " +QString::fromStdString(campo[5][0].nombre);
    msg.setText(mensaje);
    msg.exec();
}
void MainWindow::on_F2_clicked()
{
    QMessageBox msg;
    QString mensaje ="Coordenada: F2\nTerreno: " +QString::fromStdString(campo[5][1].nombre);
    msg.setText(mensaje);
    msg.exec();
}
void MainWindow::on_F3_clicked()
{
    QMessageBox msg;
    QString mensaje ="Coordenada: F3\nTerreno: " +QString::fromStdString(campo[5][2].nombre);
    msg.setText(mensaje);
    msg.exec();
}
void MainWindow::on_F4_clicked()
{
    QMessageBox msg;
    QString mensaje ="Coordenada: F4\nTerreno: " +QString::fromStdString(campo[5][3].nombre);
    msg.setText(mensaje);
    msg.exec();
}
void MainWindow::on_F5_clicked()
{
    QMessageBox msg;
    QString mensaje ="Coordenada: F5\nTerreno: " +QString::fromStdString(campo[5][4].nombre);
    msg.setText(mensaje);
    msg.exec();
}
void MainWindow::on_F6_clicked()
{
    QMessageBox msg;
    QString mensaje ="Coordenada: F6\nTerreno: " +QString::fromStdString(campo[5][5].nombre);
    msg.setText(mensaje);
    msg.exec();
}
void MainWindow::on_F7_clicked()
{
    QMessageBox msg;
    QString mensaje ="Coordenada: F7\nTerreno: " +QString::fromStdString(campo[5][6].nombre);
    msg.setText(mensaje);
    msg.exec();
}
void MainWindow::on_F8_clicked()
{
    QMessageBox msg;
    QString mensaje ="Coordenada: F8\nTerreno: " +QString::fromStdString(campo[5][7].nombre);
    msg.setText(mensaje);
    msg.exec();
}
void MainWindow::on_F9_clicked()
{
    QMessageBox msg;
    QString mensaje ="Coordenada: F9\nTerreno: " +QString::fromStdString(campo[5][8].nombre);
    msg.setText(mensaje);
    msg.exec();
}
void MainWindow::on_F10_clicked()
{
    QMessageBox msg;
    QString mensaje ="Coordenada: F10\nTerreno: " +QString::fromStdString(campo[5][9].nombre);
    msg.setText(mensaje);
    msg.exec();
}
void MainWindow::on_F11_clicked()
{
    QMessageBox msg;
    QString mensaje ="Coordenada: F11\nTerreno: " +QString::fromStdString(campo[5][10].nombre);
    msg.setText(mensaje);
    msg.exec();
}
void MainWindow::on_F12_clicked()
{
    QMessageBox msg;
    QString mensaje ="Coordenada: F12\nTerreno: " +QString::fromStdString(campo[5][11].nombre);
    msg.setText(mensaje);
    msg.exec();
}
void MainWindow::on_F13_clicked()
{
    QMessageBox msg;
    QString mensaje ="Coordenada: F13\nTerreno: " +QString::fromStdString(campo[5][12].nombre);
    msg.setText(mensaje);
    msg.exec();
}
void MainWindow::on_F14_clicked()
{
    QMessageBox msg;
    QString mensaje ="Coordenada: F14\nTerreno: " +QString::fromStdString(campo[5][13].nombre);
    msg.setText(mensaje);
    msg.exec();
}
void MainWindow::on_F15_clicked()
{
    QMessageBox msg;
    QString mensaje ="Coordenada: F15\nTerreno: " +QString::fromStdString(campo[5][14].nombre);
    msg.setText(mensaje);
    msg.exec();
}
//G
void MainWindow::on_G1_clicked()
{
    QMessageBox msg;
    QString mensaje ="Coordenada: G1\nTerreno: " +QString::fromStdString(campo[6][0].nombre);
    msg.setText(mensaje);
    msg.exec();
}
void MainWindow::on_G2_clicked()
{
    QMessageBox msg;
    QString mensaje ="Coordenada: G2\nTerreno: " +QString::fromStdString(campo[6][1].nombre);
    msg.setText(mensaje);
    msg.exec();
}
void MainWindow::on_G3_clicked()
{
    QMessageBox msg;
    QString mensaje ="Coordenada: G3\nTerreno: " +QString::fromStdString(campo[6][2].nombre);
    msg.setText(mensaje);
    msg.exec();
}
void MainWindow::on_G4_clicked()
{
    QMessageBox msg;
    QString mensaje ="Coordenada: G4\nTerreno: " +QString::fromStdString(campo[6][3].nombre);
    msg.setText(mensaje);
    msg.exec();
}
void MainWindow::on_G5_clicked()
{
    QMessageBox msg;
    QString mensaje ="Coordenada: G5\nTerreno: " +QString::fromStdString(campo[6][4].nombre);
    msg.setText(mensaje);
    msg.exec();
}
void MainWindow::on_G6_clicked()
{
    QMessageBox msg;
    QString mensaje ="Coordenada: G6\nTerreno: " +QString::fromStdString(campo[6][5].nombre);
    msg.setText(mensaje);
    msg.exec();
}
void MainWindow::on_G7_clicked()
{
    QMessageBox msg;
    QString mensaje ="Coordenada: G7\nTerreno: " +QString::fromStdString(campo[6][6].nombre);
    msg.setText(mensaje);
    msg.exec();
}
void MainWindow::on_G8_clicked()
{
    QMessageBox msg;
    QString mensaje ="Coordenada: G8\nTerreno: " +QString::fromStdString(campo[6][7].nombre);
    msg.setText(mensaje);
    msg.exec();
}
void MainWindow::on_G9_clicked()
{
    QMessageBox msg;
    QString mensaje ="Coordenada: G9\nTerreno: " +QString::fromStdString(campo[6][8].nombre);
    msg.setText(mensaje);
    msg.exec();
}
void MainWindow::on_G10_clicked()
{
    QMessageBox msg;
    QString mensaje ="Coordenada: G10\nTerreno: " +QString::fromStdString(campo[6][9].nombre);
    msg.setText(mensaje);
    msg.exec();
}
void MainWindow::on_G11_clicked()
{
    QMessageBox msg;
    QString mensaje ="Coordenada: G11\nTerreno: " +QString::fromStdString(campo[6][10].nombre);
    msg.setText(mensaje);
    msg.exec();
}
void MainWindow::on_G12_clicked()
{
    QMessageBox msg;
    QString mensaje ="Coordenada: G12\nTerreno: " +QString::fromStdString(campo[6][11].nombre);
    msg.setText(mensaje);
    msg.exec();
}
void MainWindow::on_G13_clicked()
{
    QMessageBox msg;
    QString mensaje ="Coordenada: G13\nTerreno: " +QString::fromStdString(campo[6][12].nombre);
    msg.setText(mensaje);
    msg.exec();
}
void MainWindow::on_G14_clicked()
{
    QMessageBox msg;
    QString mensaje ="Coordenada: G14\nTerreno: " +QString::fromStdString(campo[6][13].nombre);
    msg.setText(mensaje);
    msg.exec();
}
void MainWindow::on_G15_clicked()
{
    QMessageBox msg;
    QString mensaje ="Coordenada: G15\nTerreno: " +QString::fromStdString(campo[6][14].nombre);
    msg.setText(mensaje);
    msg.exec();
}
//H
void MainWindow::on_H1_clicked()
{
    QMessageBox msg;
    QString mensaje ="Coordenada: H1\nTerreno: " +QString::fromStdString(campo[7][0].nombre);
    msg.setText(mensaje);
    msg.exec();
}
void MainWindow::on_H2_clicked()
{
    QMessageBox msg;
    QString mensaje ="Coordenada: H2\nTerreno: " +QString::fromStdString(campo[7][1].nombre);
    msg.setText(mensaje);
    msg.exec();
}
void MainWindow::on_H3_clicked()
{
    QMessageBox msg;
    QString mensaje ="Coordenada: H3\nTerreno: " +QString::fromStdString(campo[7][2].nombre);
    msg.setText(mensaje);
    msg.exec();
}
void MainWindow::on_H4_clicked()
{
    QMessageBox msg;
    QString mensaje ="Coordenada: H4\nTerreno: " +QString::fromStdString(campo[7][3].nombre);
    msg.setText(mensaje);
    msg.exec();
}
void MainWindow::on_H5_clicked()
{
    QMessageBox msg;
    QString mensaje ="Coordenada: H5\nTerreno: " +QString::fromStdString(campo[7][4].nombre);
    msg.setText(mensaje);
    msg.exec();
}
void MainWindow::on_H6_clicked()
{
    QMessageBox msg;
    QString mensaje ="Coordenada: H6\nTerreno: " +QString::fromStdString(campo[7][5].nombre);
    msg.setText(mensaje);
    msg.exec();
}
void MainWindow::on_H7_clicked()
{
    QMessageBox msg;
    QString mensaje ="Coordenada: H7\nTerreno: " +QString::fromStdString(campo[7][6].nombre);
    msg.setText(mensaje);
    msg.exec();
}
void MainWindow::on_H8_clicked()
{
    QMessageBox msg;
    QString mensaje ="Coordenada: H8\nTerreno: " +QString::fromStdString(campo[7][7].nombre);
    msg.setText(mensaje);
    msg.exec();
}
void MainWindow::on_H9_clicked()
{
    QMessageBox msg;
    QString mensaje ="Coordenada: H9\nTerreno: " +QString::fromStdString(campo[7][8].nombre);
    msg.setText(mensaje);
    msg.exec();
}
void MainWindow::on_H10_clicked()
{
    QMessageBox msg;
    QString mensaje ="Coordenada: H10\nTerreno: " +QString::fromStdString(campo[7][9].nombre);
    msg.setText(mensaje);
    msg.exec();
}
void MainWindow::on_H11_clicked()
{
    QMessageBox msg;
    QString mensaje ="Coordenada: H11\nTerreno: " +QString::fromStdString(campo[7][10].nombre);
    msg.setText(mensaje);
    msg.exec();
}
void MainWindow::on_H12_clicked()
{
    QMessageBox msg;
    QString mensaje ="Coordenada: H12\nTerreno: " +QString::fromStdString(campo[7][11].nombre);
    msg.setText(mensaje);
    msg.exec();
}
void MainWindow::on_H13_clicked()
{
    QMessageBox msg;
    QString mensaje ="Coordenada: H13\nTerreno: " +QString::fromStdString(campo[7][12].nombre);
    msg.setText(mensaje);
    msg.exec();
}
void MainWindow::on_H14_clicked()
{
    QMessageBox msg;
    QString mensaje ="Coordenada: H14\nTerreno: " +QString::fromStdString(campo[7][13].nombre);
    msg.setText(mensaje);
    msg.exec();
}
void MainWindow::on_H15_clicked()
{
    QMessageBox msg;
    QString mensaje ="Coordenada: H15\nTerreno: " +QString::fromStdString(campo[7][14].nombre);
    msg.setText(mensaje);
    msg.exec();
}
//I
void MainWindow::on_I1_clicked()
{
    QMessageBox msg;
    QString mensaje ="Coordenada: I1\nTerreno: " +QString::fromStdString(campo[8][0].nombre);
    msg.setText(mensaje);
    msg.exec();
}
void MainWindow::on_I2_clicked()
{
    QMessageBox msg;
    QString mensaje ="Coordenada: I2\nTerreno: " +QString::fromStdString(campo[8][1].nombre);
    msg.setText(mensaje);
    msg.exec();
}
void MainWindow::on_I3_clicked()
{
    QMessageBox msg;
    QString mensaje ="Coordenada: I3\nTerreno: " +QString::fromStdString(campo[8][2].nombre);
    msg.setText(mensaje);
    msg.exec();
}
void MainWindow::on_I4_clicked()
{
    QMessageBox msg;
    QString mensaje ="Coordenada: I4\nTerreno: " +QString::fromStdString(campo[8][3].nombre);
    msg.setText(mensaje);
    msg.exec();
}
void MainWindow::on_I5_clicked()
{
    QMessageBox msg;
    QString mensaje ="Coordenada: I5\nTerreno: " +QString::fromStdString(campo[8][4].nombre);
    msg.setText(mensaje);
    msg.exec();
}
void MainWindow::on_I6_clicked()
{
    QMessageBox msg;
    QString mensaje ="Coordenada: I6\nTerreno: " +QString::fromStdString(campo[8][5].nombre);
    msg.setText(mensaje);
    msg.exec();
}
void MainWindow::on_I7_clicked()
{
    QMessageBox msg;
    QString mensaje ="Coordenada: I7\nTerreno: " +QString::fromStdString(campo[8][6].nombre);
    msg.setText(mensaje);
    msg.exec();
}
void MainWindow::on_I8_clicked()
{
    QMessageBox msg;
    QString mensaje ="Coordenada: I8\nTerreno: " +QString::fromStdString(campo[8][7].nombre);
    msg.setText(mensaje);
    msg.exec();
}
void MainWindow::on_I9_clicked()
{
    QMessageBox msg;
    QString mensaje ="Coordenada: I9\nTerreno: " +QString::fromStdString(campo[8][8].nombre);
    msg.setText(mensaje);
    msg.exec();
}
void MainWindow::on_I10_clicked()
{
    QMessageBox msg;
    QString mensaje ="Coordenada: I10\nTerreno: " +QString::fromStdString(campo[8][9].nombre);
    msg.setText(mensaje);
    msg.exec();
}
void MainWindow::on_I11_clicked()
{
    QMessageBox msg;
    QString mensaje ="Coordenada: I11\nTerreno: " +QString::fromStdString(campo[8][10].nombre);
    msg.setText(mensaje);
    msg.exec();
}
void MainWindow::on_I12_clicked()
{
    QMessageBox msg;
    QString mensaje ="Coordenada: I12\nTerreno: " +QString::fromStdString(campo[8][11].nombre);
    msg.setText(mensaje);
    msg.exec();
}
void MainWindow::on_I13_clicked()
{
    QMessageBox msg;
    QString mensaje ="Coordenada: I13\nTerreno: " +QString::fromStdString(campo[8][12].nombre);
    msg.setText(mensaje);
    msg.exec();
}
void MainWindow::on_I14_clicked()
{
    QMessageBox msg;
    QString mensaje ="Coordenada: I14\nTerreno: " +QString::fromStdString(campo[8][13].nombre);
    msg.setText(mensaje);
    msg.exec();
}
void MainWindow::on_I15_clicked()
{
    QMessageBox msg;
    QString mensaje ="Coordenada: I15\nTerreno: " +QString::fromStdString(campo[8][14].nombre);
    msg.setText(mensaje);
    msg.exec();
}
//J
void MainWindow::on_J1_clicked()
{
    QMessageBox msg;
    QString mensaje ="Coordenada: J1\nTerreno: " +QString::fromStdString(campo[9][0].nombre);
    msg.setText(mensaje);
    msg.exec();
}
void MainWindow::on_J2_clicked()
{
    QMessageBox msg;
    QString mensaje ="Coordenada: J2\nTerreno: " +QString::fromStdString(campo[9][1].nombre);
    msg.setText(mensaje);
    msg.exec();
}
void MainWindow::on_J3_clicked()
{
    QMessageBox msg;
    QString mensaje ="Coordenada: J3\nTerreno: " +QString::fromStdString(campo[9][2].nombre);
    msg.setText(mensaje);
    msg.exec();
}
void MainWindow::on_J4_clicked()
{
    QMessageBox msg;
    QString mensaje ="Coordenada: J4\nTerreno: " +QString::fromStdString(campo[9][3].nombre);
    msg.setText(mensaje);
    msg.exec();
}
void MainWindow::on_J5_clicked()
{
    QMessageBox msg;
    QString mensaje ="Coordenada: J5\nTerreno: " +QString::fromStdString(campo[9][4].nombre);
    msg.setText(mensaje);
    msg.exec();
}
void MainWindow::on_J6_clicked()
{
    QMessageBox msg;
    QString mensaje ="Coordenada: J6\nTerreno: " +QString::fromStdString(campo[9][5].nombre);
    msg.setText(mensaje);
    msg.exec();
}
void MainWindow::on_J7_clicked()
{
    QMessageBox msg;
    QString mensaje ="Coordenada: J7\nTerreno: " +QString::fromStdString(campo[9][6].nombre);
    msg.setText(mensaje);
    msg.exec();
}
void MainWindow::on_J8_clicked()
{
    QMessageBox msg;
    QString mensaje ="Coordenada: J8\nTerreno: " +QString::fromStdString(campo[9][7].nombre);
    msg.setText(mensaje);
    msg.exec();
}
void MainWindow::on_J9_clicked()
{
    QMessageBox msg;
    QString mensaje ="Coordenada: J9\nTerreno: " +QString::fromStdString(campo[9][8].nombre);
    msg.setText(mensaje);
    msg.exec();
}
void MainWindow::on_J10_clicked()
{
    QMessageBox msg;
    QString mensaje ="Coordenada: J10\nTerreno: " +QString::fromStdString(campo[9][9].nombre);
    msg.setText(mensaje);
    msg.exec();
}
void MainWindow::on_J11_clicked()
{
    QMessageBox msg;
    QString mensaje ="Coordenada: J11\nTerreno: " +QString::fromStdString(campo[9][10].nombre);
    msg.setText(mensaje);
    msg.exec();
}
void MainWindow::on_J12_clicked()
{
    QMessageBox msg;
    QString mensaje ="Coordenada: J12\nTerreno: " +QString::fromStdString(campo[9][11].nombre);
    msg.setText(mensaje);
    msg.exec();
}
void MainWindow::on_J13_clicked()
{
    QMessageBox msg;
    QString mensaje ="Coordenada: J113\nTerreno: " +QString::fromStdString(campo[9][12].nombre);
    msg.setText(mensaje);
    msg.exec();
}
void MainWindow::on_J14_clicked()
{
    QMessageBox msg;
    QString mensaje ="Coordenada: J14\nTerreno: " +QString::fromStdString(campo[9][13].nombre);
    msg.setText(mensaje);
    msg.exec();
}
void MainWindow::on_J15_clicked()
{
    QMessageBox msg;
    QString mensaje ="Coordenada: J15\nTerreno: " +QString::fromStdString(campo[9][14].nombre);
    msg.setText(mensaje);
    msg.exec();
}
//K
void MainWindow::on_K1_clicked()
{
    QMessageBox msg;
    QString mensaje ="Coordenada: K1\nTerreno: " +QString::fromStdString(campo[10][0].nombre);
    msg.setText(mensaje);
    msg.exec();
}
void MainWindow::on_K2_clicked()
{
    QMessageBox msg;
    QString mensaje ="Coordenada: K2\nTerreno: " +QString::fromStdString(campo[10][1].nombre);
    msg.setText(mensaje);
    msg.exec();
}
void MainWindow::on_K3_clicked()
{
    QMessageBox msg;
    QString mensaje ="Coordenada: K3\nTerreno: " +QString::fromStdString(campo[10][2].nombre);
    msg.setText(mensaje);
    msg.exec();
}
void MainWindow::on_K4_clicked()
{
    QMessageBox msg;
    QString mensaje ="Coordenada: K4\nTerreno: " +QString::fromStdString(campo[10][3].nombre);
    msg.setText(mensaje);
    msg.exec();
}
void MainWindow::on_K5_clicked()
{
    QMessageBox msg;
    QString mensaje ="Coordenada: K5\nTerreno: " +QString::fromStdString(campo[10][4].nombre);
    msg.setText(mensaje);
    msg.exec();
}
void MainWindow::on_K6_clicked()
{
    QMessageBox msg;
    QString mensaje ="Coordenada: K6\nTerreno: " +QString::fromStdString(campo[10][5].nombre);
    msg.setText(mensaje);
    msg.exec();
}
void MainWindow::on_K7_clicked()
{
    QMessageBox msg;
    QString mensaje ="Coordenada: K7\nTerreno: " +QString::fromStdString(campo[10][6].nombre);
    msg.setText(mensaje);
    msg.exec();
}
void MainWindow::on_K8_clicked()
{
    QMessageBox msg;
    QString mensaje ="Coordenada: K8\nTerreno: " +QString::fromStdString(campo[10][7].nombre);
    msg.setText(mensaje);
    msg.exec();
}
void MainWindow::on_K9_clicked()
{
    QMessageBox msg;
    QString mensaje ="Coordenada: K9\nTerreno: " +QString::fromStdString(campo[10][8].nombre);
    msg.setText(mensaje);
    msg.exec();
}
void MainWindow::on_K10_clicked()
{
    QMessageBox msg;
    QString mensaje ="Coordenada: K10\nTerreno: " +QString::fromStdString(campo[10][9].nombre);
    msg.setText(mensaje);
    msg.exec();
}
void MainWindow::on_K11_clicked()
{
    QMessageBox msg;
    QString mensaje ="Coordenada: K11\nTerreno: " +QString::fromStdString(campo[10][10].nombre);
    msg.setText(mensaje);
    msg.exec();
}
void MainWindow::on_K12_clicked()
{
    QMessageBox msg;
    QString mensaje ="Coordenada: K12\nTerreno: " +QString::fromStdString(campo[10][11].nombre);
    msg.setText(mensaje);
    msg.exec();
}
void MainWindow::on_K13_clicked()
{
    QMessageBox msg;
    QString mensaje ="Coordenada: K13\nTerreno: " +QString::fromStdString(campo[10][12].nombre);
    msg.setText(mensaje);
    msg.exec();
}
void MainWindow::on_K14_clicked()
{
    QMessageBox msg;
    QString mensaje ="Coordenada: K14\nTerreno: " +QString::fromStdString(campo[10][13].nombre);
    msg.setText(mensaje);
    msg.exec();
}
void MainWindow::on_K15_clicked()
{
    QMessageBox msg;
    QString mensaje ="Coordenada: K15\nTerreno: " +QString::fromStdString(campo[10][14].nombre);
    msg.setText(mensaje);
    msg.exec();
}
//L
void MainWindow::on_L1_clicked()
{
    QMessageBox msg;
    QString mensaje ="Coordenada: L1\nTerreno: " +QString::fromStdString(campo[11][0].nombre);
    msg.setText(mensaje);
    msg.exec();
}
void MainWindow::on_L2_clicked()
{
    QMessageBox msg;
    QString mensaje ="Coordenada: L2\nTerreno: " +QString::fromStdString(campo[11][1].nombre);
    msg.setText(mensaje);
    msg.exec();
}
void MainWindow::on_L3_clicked()
{
    QMessageBox msg;
    QString mensaje ="Coordenada: L3\nTerreno: " +QString::fromStdString(campo[11][2].nombre);
    msg.setText(mensaje);
    msg.exec();
}
void MainWindow::on_L4_clicked()
{
    QMessageBox msg;
    QString mensaje ="Coordenada: L4\nTerreno: " +QString::fromStdString(campo[11][3].nombre);
    msg.setText(mensaje);
    msg.exec();
}
void MainWindow::on_L5_clicked()
{
    QMessageBox msg;
    QString mensaje ="Coordenada: L5\nTerreno: " +QString::fromStdString(campo[11][4].nombre);
    msg.setText(mensaje);
    msg.exec();
}
void MainWindow::on_L6_clicked()
{
    QMessageBox msg;
    QString mensaje ="Coordenada: L6\nTerreno: " +QString::fromStdString(campo[11][5].nombre);
    msg.setText(mensaje);
    msg.exec();
}
void MainWindow::on_L7_clicked()
{
    QMessageBox msg;
    QString mensaje ="Coordenada: L7\nTerreno: " +QString::fromStdString(campo[11][6].nombre);
    msg.setText(mensaje);
    msg.exec();
}
void MainWindow::on_L8_clicked()
{
    QMessageBox msg;
    QString mensaje ="Coordenada: L8\nTerreno: " +QString::fromStdString(campo[11][7].nombre);
    msg.setText(mensaje);
    msg.exec();
}
void MainWindow::on_L9_clicked()
{
    QMessageBox msg;
    QString mensaje ="Coordenada: L9\nTerreno: " +QString::fromStdString(campo[11][8].nombre);
    msg.setText(mensaje);
    msg.exec();
}
void MainWindow::on_L10_clicked()
{
    QMessageBox msg;
    QString mensaje ="Coordenada: L10\nTerreno: " +QString::fromStdString(campo[11][9].nombre);
    msg.setText(mensaje);
    msg.exec();
}
void MainWindow::on_L11_clicked()
{
    QMessageBox msg;
    QString mensaje ="Coordenada: L11\nTerreno: " +QString::fromStdString(campo[11][10].nombre);
    msg.setText(mensaje);
    msg.exec();
}
void MainWindow::on_L12_clicked()
{
    QMessageBox msg;
    QString mensaje ="Coordenada: L12\nTerreno: " +QString::fromStdString(campo[11][11].nombre);
    msg.setText(mensaje);
    msg.exec();
}
void MainWindow::on_L13_clicked()
{
    QMessageBox msg;
    QString mensaje ="Coordenada: L13\nTerreno: " +QString::fromStdString(campo[11][12].nombre);
    msg.setText(mensaje);
    msg.exec();
}
void MainWindow::on_L14_clicked()
{
    QMessageBox msg;
    QString mensaje ="Coordenada: L14\nTerreno: " +QString::fromStdString(campo[11][13].nombre);
    msg.setText(mensaje);
    msg.exec();
}
void MainWindow::on_L15_clicked()
{
    QMessageBox msg;
    QString mensaje ="Coordenada: L15\nTerreno: " +QString::fromStdString(campo[11][14].nombre);
    msg.setText(mensaje);
    msg.exec();
}
//M
void MainWindow::on_M1_clicked()
{
    QMessageBox msg;
    QString mensaje ="Coordenada: M1\nTerreno: " +QString::fromStdString(campo[12][0].nombre);
    msg.setText(mensaje);
    msg.exec();
}
void MainWindow::on_M2_clicked()
{
    QMessageBox msg;
    QString mensaje ="Coordenada: M2\nTerreno: " +QString::fromStdString(campo[12][1].nombre);
    msg.setText(mensaje);
    msg.exec();
}
void MainWindow::on_M3_clicked()
{
    QMessageBox msg;
    QString mensaje ="Coordenada: M3\nTerreno: " +QString::fromStdString(campo[12][2].nombre);
    msg.setText(mensaje);
    msg.exec();
}
void MainWindow::on_M4_clicked()
{
    QMessageBox msg;
    QString mensaje ="Coordenada: M4\nTerreno: " +QString::fromStdString(campo[12][3].nombre);
    msg.setText(mensaje);
    msg.exec();
}
void MainWindow::on_M5_clicked()
{
    QMessageBox msg;
    QString mensaje ="Coordenada: M5\nTerreno: " +QString::fromStdString(campo[12][4].nombre);
    msg.setText(mensaje);
    msg.exec();
}
void MainWindow::on_M6_clicked()
{
    QMessageBox msg;
    QString mensaje ="Coordenada: M6\nTerreno: " +QString::fromStdString(campo[12][5].nombre);
    msg.setText(mensaje);
    msg.exec();
}
void MainWindow::on_M7_clicked()
{
    QMessageBox msg;
    QString mensaje ="Coordenada: M7\nTerreno: " +QString::fromStdString(campo[12][6].nombre);
    msg.setText(mensaje);
    msg.exec();
}
void MainWindow::on_M8_clicked()
{
    QMessageBox msg;
    QString mensaje ="Coordenada: M8\nTerreno: " +QString::fromStdString(campo[12][7].nombre);
    msg.setText(mensaje);
    msg.exec();
}
void MainWindow::on_M9_clicked()
{
    QMessageBox msg;
    QString mensaje ="Coordenada: M9\nTerreno: " +QString::fromStdString(campo[12][8].nombre);
    msg.setText(mensaje);
    msg.exec();
}
void MainWindow::on_M10_clicked()
{
    QMessageBox msg;
    QString mensaje ="Coordenada: M10\nTerreno: " +QString::fromStdString(campo[12][9].nombre);
    msg.setText(mensaje);
    msg.exec();
}
void MainWindow::on_M11_clicked()
{
    QMessageBox msg;
    QString mensaje ="Coordenada: M11\nTerreno: " +QString::fromStdString(campo[12][10].nombre);
    msg.setText(mensaje);
    msg.exec();
}
void MainWindow::on_M12_clicked()
{
    QMessageBox msg;
    QString mensaje ="Coordenada: M12\nTerreno: " +QString::fromStdString(campo[12][11].nombre);
    msg.setText(mensaje);
    msg.exec();
}
void MainWindow::on_M13_clicked()
{
    QMessageBox msg;
    QString mensaje ="Coordenada: M13\nTerreno: " +QString::fromStdString(campo[12][12].nombre);
    msg.setText(mensaje);
    msg.exec();

}
void MainWindow::on_M14_clicked()
{
    QMessageBox msg;
    QString mensaje ="Coordenada: M14\nTerreno: " +QString::fromStdString(campo[12][13].nombre);
    msg.setText(mensaje);
    msg.exec();
}
void MainWindow::on_M15_clicked()
{
    QMessageBox msg;
    QString mensaje ="Coordenada: M15\nTerreno: " +QString::fromStdString(campo[12][14].nombre);
    msg.setText(mensaje);
    msg.exec();
}
//N
void MainWindow::on_N1_clicked()
{
    QMessageBox msg;
    QString mensaje ="Coordenada: N1\nTerreno: " +QString::fromStdString(campo[13][0].nombre);
    msg.setText(mensaje);
    msg.exec();
}
void MainWindow::on_N2_clicked()
{
    QMessageBox msg;
    QString mensaje ="Coordenada: N2\nTerreno: " +QString::fromStdString(campo[13][1].nombre);
    msg.setText(mensaje);
    msg.exec();
}
void MainWindow::on_N3_clicked()
{
    QMessageBox msg;
    QString mensaje ="Coordenada: N3\nTerreno: " +QString::fromStdString(campo[13][2].nombre);
    msg.setText(mensaje);
    msg.exec();
}
void MainWindow::on_N4_clicked()
{
    QMessageBox msg;
    QString mensaje ="Coordenada: N4\nTerreno: " +QString::fromStdString(campo[13][3].nombre);
    msg.setText(mensaje);
    msg.exec();
}
void MainWindow::on_N5_clicked()
{
    QMessageBox msg;
    QString mensaje ="Coordenada: N5\nTerreno: " +QString::fromStdString(campo[13][4].nombre);
    msg.setText(mensaje);
    msg.exec();
}
void MainWindow::on_N6_clicked()
{
    QMessageBox msg;
    QString mensaje ="Coordenada: N6\nTerreno: " +QString::fromStdString(campo[13][5].nombre);
    msg.setText(mensaje);
    msg.exec();
}
void MainWindow::on_N7_clicked()
{
    QMessageBox msg;
    QString mensaje ="Coordenada: N7\nTerreno: " +QString::fromStdString(campo[13][6].nombre);
    msg.setText(mensaje);
    msg.exec();
}
void MainWindow::on_N8_clicked()
{
    QMessageBox msg;
    QString mensaje ="Coordenada: N8\nTerreno: " +QString::fromStdString(campo[13][7].nombre);
    msg.setText(mensaje);
    msg.exec();
}
void MainWindow::on_N9_clicked()
{
    QMessageBox msg;
    QString mensaje ="Coordenada: N9\nTerreno: " +QString::fromStdString(campo[13][8].nombre);
    msg.setText(mensaje);
    msg.exec();
}
void MainWindow::on_N10_clicked()
{
    QMessageBox msg;
    QString mensaje ="Coordenada: N10\nTerreno: " +QString::fromStdString(campo[13][9].nombre);
    msg.setText(mensaje);
    msg.exec();
}
void MainWindow::on_N11_clicked()
{
    QMessageBox msg;
    QString mensaje ="Coordenada: N11\nTerreno: " +QString::fromStdString(campo[13][10].nombre);
    msg.setText(mensaje);
    msg.exec();
}
void MainWindow::on_N12_clicked()
{
    QMessageBox msg;
    QString mensaje ="Coordenada: N12\nTerreno: " +QString::fromStdString(campo[13][11].nombre);
    msg.setText(mensaje);
    msg.exec();
}
void MainWindow::on_N13_clicked()
{
    QMessageBox msg;
    QString mensaje ="Coordenada: N13\nTerreno: " +QString::fromStdString(campo[13][12].nombre);
    msg.setText(mensaje);
    msg.exec();
}
void MainWindow::on_N14_clicked()
{
    QMessageBox msg;
    QString mensaje ="Coordenada: N14\nTerreno: " +QString::fromStdString(campo[13][13].nombre);
    msg.setText(mensaje);
    msg.exec();
}
void MainWindow::on_N15_clicked()
{
    QMessageBox msg;
    QString mensaje ="Coordenada: N15\nTerreno: " +QString::fromStdString(campo[13][14].nombre);
    msg.setText(mensaje);
    msg.exec();
}
//O
void MainWindow::on_O1_clicked()
{
    QMessageBox msg;
    QString mensaje ="Coordenada: O1\nTerreno: " +QString::fromStdString(campo[14][0].nombre);
    msg.setText(mensaje);
    msg.exec();
}
void MainWindow::on_O2_clicked()
{
    QMessageBox msg;
    QString mensaje ="Coordenada: O2\nTerreno: " +QString::fromStdString(campo[14][1].nombre);
    msg.setText(mensaje);
    msg.exec();
}
void MainWindow::on_O3_clicked()
{
    QMessageBox msg;
    QString mensaje ="Coordenada: O3\nTerreno: " +QString::fromStdString(campo[14][2].nombre);
    msg.setText(mensaje);
    msg.exec();
}
void MainWindow::on_O4_clicked()
{
    QMessageBox msg;
    QString mensaje ="Coordenada: O4\nTerreno: " +QString::fromStdString(campo[14][3].nombre);
    msg.setText(mensaje);
    msg.exec();
}
void MainWindow::on_O5_clicked()
{
    QMessageBox msg;
    QString mensaje ="Coordenada: O5\nTerreno: " +QString::fromStdString(campo[14][4].nombre);
    msg.setText(mensaje);
    msg.exec();
}
void MainWindow::on_O6_clicked()
{
    QMessageBox msg;
    QString mensaje ="Coordenada: O6\nTerreno: " +QString::fromStdString(campo[14][5].nombre);
    msg.setText(mensaje);
    msg.exec();
}
void MainWindow::on_O7_clicked()
{
    QMessageBox msg;
    QString mensaje ="Coordenada: O7\nTerreno: " +QString::fromStdString(campo[14][6].nombre);
    msg.setText(mensaje);
    msg.exec();
}
void MainWindow::on_O8_clicked()
{
    QMessageBox msg;
    QString mensaje ="Coordenada: O8\nTerreno: " +QString::fromStdString(campo[14][7].nombre);
    msg.setText(mensaje);
    msg.exec();
}
void MainWindow::on_O9_clicked()
{
    QMessageBox msg;
    QString mensaje ="Coordenada: O9\nTerreno: " +QString::fromStdString(campo[14][8].nombre);
    msg.setText(mensaje);
    msg.exec();
}
void MainWindow::on_O10_clicked()
{
    QMessageBox msg;
    QString mensaje ="Coordenada: O10\nTerreno: " +QString::fromStdString(campo[14][9].nombre);
    msg.setText(mensaje);
    msg.exec();
}
void MainWindow::on_O11_clicked()
{
    QMessageBox msg;
    QString mensaje ="Coordenada: O11\nTerreno: " +QString::fromStdString(campo[14][10].nombre);
    msg.setText(mensaje);
    msg.exec();
}
void MainWindow::on_O12_clicked()
{
    QMessageBox msg;
    QString mensaje ="Coordenada: O12\nTerreno: " +QString::fromStdString(campo[14][11].nombre);
    msg.setText(mensaje);
    msg.exec();
}
void MainWindow::on_O13_clicked()
{
    QMessageBox msg;
    QString mensaje ="Coordenada: O13\nTerreno: " +QString::fromStdString(campo[14][12].nombre);
    msg.setText(mensaje);
    msg.exec();
}
void MainWindow::on_O14_clicked()
{
    QMessageBox msg;
    QString mensaje ="Coordenada: O14\nTerreno: " +QString::fromStdString(campo[14][13].nombre);
    msg.setText(mensaje);
    msg.exec();
}
void MainWindow::on_O15_clicked()
{
    QMessageBox msg;
    QString mensaje ="Coordenada: O15\nTerreno: " +QString::fromStdString(campo[14][14].nombre);
    msg.setText(mensaje);
    msg.exec();
}

void MainWindow::on_pushButton_iniciar_clicked()
{
    string nombre;
    nodo padre;
    QMessageBox mse;

    if(persona.size()>0&&ui->ComboBox_fila->currentIndex()!=0&&ui->ComboBox_columna->currentIndex()!=0){
        if(ui->radioButton->isChecked()){
            if(validar_campo(campo[ui->ComboBox_fila->currentIndex()-1][ui->ComboBox_columna->currentIndex()-1],persona[0])){
                if(validar_campo(campo[ui->ComboBox_fila_fin->currentIndex()-1][ui->comboBox_columna_fin->currentIndex()-1],persona[0])){
                    if(ui->pb_abajo->isEnabled()||ui->pb_arriba->isEnabled()||ui->pb_izquierda->isEnabled()||ui->pb_derecha->isEnabled()){
                        QMessageBox mse;
                        mse.setText("Por favor termine de seleccionar la prioridad");
                        mse.exec();

                    }
                    else{
                        algoritmo=ui->comboBox_2->currentIndex();
                        if(algoritmo!=0){
                            nombre=persona[0].icono;
                            persona[0].estado=1;
                            bloquear_botones();
                            cordenada.nombre=nombre;
                            cordenada.x=ui->ComboBox_fila->currentIndex()-1;
                            cordenada.y=ui->ComboBox_columna->currentIndex()-1;
                            inicial=cordenada;
                            padre.cordenada=generar_coordenada(cordenada.x,cordenada.y);
                            padre.estado="abierto";
                            padre.color=color;
                            color++;
                            padre.costo=0;

                            padre.otro="I";
                            padre.padre="NA";
                            padre.tab="";

                            final.x=ui->ComboBox_fila_fin->currentIndex()-1;
                            final.y=ui->comboBox_columna_fin->currentIndex()-1;
                            padre.distancia=generar_distancia(inicial.x,inicial.y,final.x,final.y);
                            padre.tot=padre.total+padre.distancia;
                            desbloquear(cordenada.x, cordenada.y,final);
                            desbloquear_final(final);
                            insertar_en_pila(padre);
                            validar_cordenada(ui->ComboBox_fila->currentIndex(), ui->ComboBox_columna->currentIndex(), nombre);
                            ui->radioButton->setDisabled(true);
                            ui->radioButton_2->setDisabled(true);
                            ui->radioButton_3->setDisabled(true);
                            ui->ComboBox_fila->setDisabled(true);
                            ui->comboBox_columna_fin->setDisabled(true);
                            ui->ComboBox_columna->setDisabled(true);
                            ui->ComboBox_fila_fin->setDisabled(true);
                            ui->comboBox_2->setDisabled(true);
                            ui->pb_personaje->setDisabled(true);
                            ui->pb_personaje_2->setDisabled(true);
                            ui->pb_personaje3->setDisabled(true);
                            ui->pushButton_iniciar->setDisabled(true);
                            ui->ComboBox_fila_editar->setDisabled(true);
                            ui->ComboBox_columna_2->setDisabled(true);
                            ui->lineEdit->setDisabled(true);
                            ui->comboBox->setDisabled(true);
                            ui->pushButton->setDisabled(true);
                            ui->pushButton_2->setDisabled(true);
                            if(inicial.x==final.x && inicial.y==final.y){
                                activo=1;

                                QMessageBox mse;
                                mse.setText("Felicidades llego a su destino\nPara volver a recorrer el mapa presione el boton reiniciar");
                                mse.exec();
                                on_pushButton_3_clicked();


                            }
                            else{
                                switch(algoritmo){
                                case 1: anchura();
                                    break;
                                case 2: //profundidad
                                    profundidad();
                                    break;
                                case 3: backtracking();
                                    break;
                                case 4: //costes uniformes
                                    costes_uniformes();
                                    break;
                                case 5: //voraz primero el mejor
                                    primero_mejor();
                                    break;
                                case 6: //A*
                                    A();
                                    break;
                                }
                                ui->pushButton_4->setEnabled(true);
                            }
                        }
                        else{
                            QMessageBox mse;
                            mse.setText("Por favor seleccione un algoritmo");
                            mse.exec();
                        }


                    }
                }
                else{
                    QMessageBox mse;
                    mse.setText("Coordenada no valida para colocar\n el final del camino para el personaje seleccionado");
                    mse.exec();
                }


            }
            else{
                QMessageBox mse;
                mse.setText("Coordenada no valida para colocar al personajes");
                mse.exec();
            }

        }
        else if(ui->radioButton_2->isChecked()){
            if(validar_campo(campo[ui->ComboBox_fila->currentIndex()-1][ui->ComboBox_columna->currentIndex()-1],persona[1])){
                if(validar_campo(campo[ui->ComboBox_fila_fin->currentIndex()-1][ui->comboBox_columna_fin->currentIndex()-1],persona[1])){
                    if(ui->pb_abajo->isEnabled()||ui->pb_arriba->isEnabled()||ui->pb_izquierda->isEnabled()||ui->pb_derecha->isEnabled()){
                        QMessageBox mse;
                        mse.setText("Por favor termine de seleccionar la prioridad");
                        mse.exec();

                    }
                    else{
                        algoritmo=ui->comboBox_2->currentIndex();
                        if(algoritmo!=0){
                            nombre=persona[1].icono;
                            cordenada.nombre=nombre;
                            persona[1].estado=1;
                            bloquear_botones();
                            cordenada.x=ui->ComboBox_fila->currentIndex()-1;
                            cordenada.y=ui->ComboBox_columna->currentIndex()-1;
                            inicial=cordenada;
                            padre.cordenada=generar_coordenada(cordenada.x,cordenada.y);
                            padre.estado="abierto";
                            padre.color=color;
                            color++;
                            padre.costo=0;

                            padre.otro="I";
                            padre.padre="NA";
                            padre.tab="";

                            final.x=ui->ComboBox_fila_fin->currentIndex()-1;
                            final.y=ui->comboBox_columna_fin->currentIndex()-1;
                            padre.distancia=generar_distancia(inicial.x,inicial.y,final.x,final.y);
                            padre.tot=padre.total+padre.distancia;
                            desbloquear(cordenada.x, cordenada.y,final);
                            desbloquear_final(final);
                            insertar_en_pila(padre);
                            algoritmo=ui->comboBox_2->currentIndex();
                            validar_cordenada(ui->ComboBox_fila->currentIndex(), ui->ComboBox_columna->currentIndex(),nombre);
                            ui->radioButton->setDisabled(true);
                            ui->radioButton_2->setDisabled(true);
                            ui->radioButton_3->setDisabled(true);
                            ui->ComboBox_fila->setDisabled(true);
                            ui->comboBox_columna_fin->setDisabled(true);
                            ui->ComboBox_columna->setDisabled(true);
                            ui->ComboBox_fila_fin->setDisabled(true);
                            ui->pb_personaje->setDisabled(true);
                            ui->pb_personaje_2->setDisabled(true);
                            ui->pb_personaje3->setDisabled(true);
                            ui->comboBox_2->setDisabled(true);
                            ui->pushButton_iniciar->setDisabled(true);
                            ui->ComboBox_fila_editar->setDisabled(true);
                            ui->ComboBox_columna_2->setDisabled(true);
                            ui->lineEdit->setDisabled(true);
                            ui->comboBox->setDisabled(true);
                            ui->pushButton->setDisabled(true);
                            ui->pushButton_2->setDisabled(true);
                            if(inicial.x==final.x && inicial.y==final.y){
                                QMessageBox mse;
                                activo=1;

                                mse.setText("Felicidades llego a su destino\nPara volver a recorrer el mapa presione el boton reiniciar");
                                mse.exec();
                                on_pushButton_3_clicked();

                            }
                            else{

                                switch(algoritmo){
                                case 1: anchura();
                                    break;
                                case 2: //profundidad
                                    profundidad();
                                    break;
                                case 3: backtracking();
                                    break;
                                case 4: //costes uniformes
                                    costes_uniformes();
                                    break;
                                case 5: //voraz primero el mejor
                                    primero_mejor();
                                    break;
                                case 6: //A*

                                    A();
                                    break;
                                }
                                ui->pushButton_4->setEnabled(true);
                            }
                        }
                        else{
                            QMessageBox mse;
                            mse.setText("Por favor seleccione un algoritmo");
                            mse.exec();
                        }
                    }
                }
                else{
                    QMessageBox mse;
                    mse.setText("Coordenada no valida para colocar\n el final del camino para el personaje seleccionado");
                    mse.exec();
                }
            }
            else{
                QMessageBox mse;
                mse.setText("Coordenada no valida para colocar al personajes");
                mse.exec();
            }


        }
        else if(ui->radioButton_3->isChecked()){
            if(validar_campo(campo[ui->ComboBox_fila->currentIndex()-1][ui->ComboBox_columna->currentIndex()-1],persona[2])){
                if(validar_campo(campo[ui->ComboBox_fila_fin->currentIndex()-1][ui->comboBox_columna_fin->currentIndex()-1],persona[2])){
                    if(ui->pb_abajo->isEnabled()||ui->pb_arriba->isEnabled()||ui->pb_izquierda->isEnabled()||ui->pb_derecha->isEnabled()){
                        QMessageBox mse;
                        mse.setText("Por favor termine de seleccionar la prioridad");
                        mse.exec();

                    }
                    else{
                        algoritmo=ui->comboBox_2->currentIndex();
                        if(algoritmo!=0){
                            nombre=persona[2].icono;
                            cordenada.nombre=nombre;
                            persona[2].estado=1;
                            bloquear_botones();
                            cordenada.x=ui->ComboBox_fila->currentIndex()-1;
                            cordenada.y=ui->ComboBox_columna->currentIndex()-1;
                            inicial=cordenada;
                            padre.cordenada=generar_coordenada(cordenada.x,cordenada.y);
                            padre.estado="abierto";
                            padre.color=color;
                            color++;
                            padre.costo=0;

                            padre.otro="I";
                            padre.padre="NA";
                            padre.tab="";

                            final.x=ui->ComboBox_fila_fin->currentIndex()-1;
                            final.y=ui->comboBox_columna_fin->currentIndex()-1;
                            padre.distancia=generar_distancia(inicial.x,inicial.y,final.x,final.y);
                            padre.tot=padre.total+padre.distancia;
                            desbloquear(cordenada.x,cordenada.y,final);
                            desbloquear_final(final);
                            insertar_en_pila(padre);
                            algoritmo=ui->comboBox_2->currentIndex();
                            validar_cordenada(ui->ComboBox_fila->currentIndex(), ui->ComboBox_columna->currentIndex(),nombre);
                            ui->radioButton_2->setDisabled(true);
                            ui->radioButton_3->setDisabled(true);
                            ui->radioButton->setDisabled(true);
                            ui->ComboBox_fila->setDisabled(true);
                            ui->comboBox_columna_fin->setDisabled(true);
                            ui->ComboBox_columna->setDisabled(true);
                            ui->ComboBox_fila_fin->setDisabled(true);
                            ui->pb_personaje->setDisabled(true);
                            ui->pb_personaje_2->setDisabled(true);
                            ui->pb_personaje3->setDisabled(true);
                            ui->comboBox_2->setDisabled(true);
                            ui->pushButton_iniciar->setDisabled(true);
                            ui->ComboBox_fila_editar->setDisabled(true);
                            ui->ComboBox_columna_2->setDisabled(true);
                            ui->lineEdit->setDisabled(true);
                            ui->comboBox->setDisabled(true);
                            ui->pushButton->setDisabled(true);
                            ui->pushButton_2->setDisabled(true);
                            if(inicial.x==final.x && inicial.y==final.y){
                                activo=1;
                                QMessageBox mse;
                                mse.setText("Felicidades llego a su destino\nPara volver a recorrer el mapa presione el boton reiniciar");
                                mse.exec();
                                on_pushButton_3_clicked();

                            }
                            else{
                                switch(algoritmo){
                                case 1: anchura();
                                    break;
                                case 2: //profundidad
                                    profundidad();
                                    break;
                                case 3: backtracking();
                                    break;
                                case 4: //costes uniformes
                                    costes_uniformes();
                                    break;
                                case 5: //voraz primero el mejor
                                    primero_mejor();
                                    break;
                                case 6: //A*

                                    A();
                                    break;
                                }
                                ui->pushButton_4->setEnabled(true);
                            }
                        }
                        else{
                            QMessageBox mse;
                            mse.setText("Por favor seleccione un algoritmo");
                            mse.exec();
                        }
                    }

                }
                else{
                    QMessageBox mse;
                    mse.setText("Coordenada no valida para colocar\n el final del camino para el personaje seleccionado");
                    mse.exec();
                }
            }
            else{
                QMessageBox mse;
                mse.setText("Coordenada no valida para colocar al personajes");
                mse.exec();
            }

        }
        else{
            QMessageBox mse;
            mse.setText("No se ha seleccionado el personaje");
            mse.exec();
        }
    }
    else{
        QMessageBox mse;
        mse.setText("Favor de seleccionar la coordenada para iniciar");
        mse.exec();
    }

}


void MainWindow::validar_cordenada(int fila, int columna, string nombre){

    switch (fila) {
    case 1:
        switch (columna) {
        case 1:
            ui->A1->setIcon(generar_icono(nombre));
            ui->A1->setIconSize(ui->A1->size());
            break;
        case 2:
            ui->A2->setIcon(generar_icono(nombre));
            ui->A2->setIconSize(ui->A1->size());
            break;

        case 3:
            ui->A3->setIcon(generar_icono(nombre));
            ui->A4->setIconSize(ui->A1->size());
            break;
        case 4:
            ui->A4->setIcon(generar_icono(nombre));
            ui->A4->setIconSize(ui->A1->size());
            break;
        case 5:
            ui->A5->setIcon(generar_icono(nombre));
            ui->A5->setIconSize(ui->A1->size());
            break;
        case 6:
            ui->A6->setIcon(generar_icono(nombre));
            ui->A6->setIconSize(ui->A1->size());
            break;
        case 7:
            ui->A7->setIcon(generar_icono(nombre));
            ui->A7->setIconSize(ui->A1->size());
            break;
        case 8:
            ui->A8->setIcon(generar_icono(nombre));
            ui->A8->setIconSize(ui->A1->size());
            break;
        case 9:
            ui->A9->setIcon(generar_icono(nombre));
            ui->A9->setIconSize(ui->A1->size());
            break;
        case 10:
            ui->A10->setIcon(generar_icono(nombre));
            ui->A10->setIconSize(ui->A1->size());
            break;
        case 11:
            ui->A11->setIcon(generar_icono(nombre));
            ui->A11->setIconSize(ui->A1->size());
            break;
        case 12:
            ui->A12->setIcon(generar_icono(nombre));
            ui->A12->setIconSize(ui->A1->size());
            break;
        case 13:
            ui->A13->setIcon(generar_icono(nombre));
            ui->A13->setIconSize(ui->A1->size());
            break;
        case 14:
            ui->A14->setIcon(generar_icono(nombre));
            ui->A14->setIconSize(ui->A1->size());
            break;
        case 15:
            ui->A15->setIcon(generar_icono(nombre));
            ui->A15->setIconSize(ui->A1->size());
            break;
        }
        break;
    case 2:
        switch (columna) {
        case 1:
            ui->B1->setIcon(generar_icono(nombre));
            ui->B1->setIconSize(ui->B1->size());
            break;
        case 2:
            ui->B2->setIcon(generar_icono(nombre));
            ui->B2->setIconSize(ui->B1->size());
            break;

        case 3:
            ui->B3->setIcon(generar_icono(nombre));
            ui->B4->setIconSize(ui->B1->size());
            break;
        case 4:
            ui->B4->setIcon(generar_icono(nombre));
            ui->B4->setIconSize(ui->B1->size());
            break;
        case 5:
            ui->B5->setIcon(generar_icono(nombre));
            ui->B5->setIconSize(ui->B1->size());
            break;
        case 6:
            ui->B6->setIcon(generar_icono(nombre));
            ui->B6->setIconSize(ui->B1->size());
            break;
        case 7:
            ui->B7->setIcon(generar_icono(nombre));
            ui->B7->setIconSize(ui->B1->size());
            break;
        case 8:
            ui->B8->setIcon(generar_icono(nombre));
            ui->B8->setIconSize(ui->B1->size());
            break;
        case 9:
            ui->B9->setIcon(generar_icono(nombre));
            ui->B9->setIconSize(ui->B1->size());
            break;
        case 10:
            ui->B10->setIcon(generar_icono(nombre));
            ui->B10->setIconSize(ui->B1->size());
            break;
        case 11:
            ui->B11->setIcon(generar_icono(nombre));
            ui->B11->setIconSize(ui->B1->size());
            break;
        case 12:
            ui->B12->setIcon(generar_icono(nombre));
            ui->B12->setIconSize(ui->B1->size());
            break;
        case 13:
            ui->B13->setIcon(generar_icono(nombre));
            ui->B13->setIconSize(ui->B1->size());
            break;
        case 14:
            ui->B14->setIcon(generar_icono(nombre));
            ui->B14->setIconSize(ui->B1->size());
            break;
        case 15:
            ui->B15->setIcon(generar_icono(nombre));
            ui->B15->setIconSize(ui->B1->size());
            break;
        }
        break;
    case 3:
        switch (columna) {
        case 1:
            ui->C1->setIcon(generar_icono(nombre));
            ui->C1->setIconSize(ui->C1->size());
            break;
        case 2:
            ui->C2->setIcon(generar_icono(nombre));
            ui->C2->setIconSize(ui->C1->size());
            break;

        case 3:
            ui->C3->setIcon(generar_icono(nombre));
            ui->C4->setIconSize(ui->C1->size());
            break;
        case 4:
            ui->C4->setIcon(generar_icono(nombre));
            ui->C4->setIconSize(ui->C1->size());
            break;
        case 5:
            ui->C5->setIcon(generar_icono(nombre));
            ui->C5->setIconSize(ui->C1->size());
            break;
        case 6:
            ui->C6->setIcon(generar_icono(nombre));
            ui->C6->setIconSize(ui->C1->size());
            break;
        case 7:
            ui->C7->setIcon(generar_icono(nombre));
            ui->C7->setIconSize(ui->C1->size());
            break;
        case 8:
            ui->C8->setIcon(generar_icono(nombre));
            ui->C8->setIconSize(ui->C1->size());
            break;
        case 9:
            ui->C9->setIcon(generar_icono(nombre));
            ui->C9->setIconSize(ui->C1->size());
            break;
        case 10:
            ui->C10->setIcon(generar_icono(nombre));
            ui->C10->setIconSize(ui->C1->size());
            break;
        case 11:
            ui->C11->setIcon(generar_icono(nombre));
            ui->C11->setIconSize(ui->C1->size());
            break;
        case 12:
            ui->C12->setIcon(generar_icono(nombre));
            ui->C12->setIconSize(ui->C1->size());
            break;
        case 13:
            ui->C13->setIcon(generar_icono(nombre));
            ui->C13->setIconSize(ui->C1->size());
            break;
        case 14:
            ui->C14->setIcon(generar_icono(nombre));
            ui->C14->setIconSize(ui->C1->size());
            break;
        case 15:
            ui->C15->setIcon(generar_icono(nombre));
            ui->C15->setIconSize(ui->C1->size());
            break;
        }
        break;
    case 4:
        switch (columna) {
        case 1:
            ui->D1->setIcon(generar_icono(nombre));
            ui->D1->setIconSize(ui->D1->size());
            break;
        case 2:
            ui->D2->setIcon(generar_icono(nombre));
            ui->D2->setIconSize(ui->D1->size());
            break;

        case 3:
            ui->D3->setIcon(generar_icono(nombre));
            ui->D4->setIconSize(ui->D1->size());
            break;
        case 4:
            ui->D4->setIcon(generar_icono(nombre));
            ui->D4->setIconSize(ui->D1->size());
            break;
        case 5:
            ui->D5->setIcon(generar_icono(nombre));
            ui->D5->setIconSize(ui->D1->size());
            break;
        case 6:
            ui->D6->setIcon(generar_icono(nombre));
            ui->D6->setIconSize(ui->D1->size());
            break;
        case 7:
            ui->D7->setIcon(generar_icono(nombre));
            ui->D7->setIconSize(ui->D1->size());
            break;
        case 8:
            ui->D8->setIcon(generar_icono(nombre));
            ui->D8->setIconSize(ui->D1->size());
            break;
        case 9:
            ui->D9->setIcon(generar_icono(nombre));
            ui->D9->setIconSize(ui->D1->size());
            break;
        case 10:
            ui->D10->setIcon(generar_icono(nombre));
            ui->D10->setIconSize(ui->D1->size());
            break;
        case 11:
            ui->D11->setIcon(generar_icono(nombre));
            ui->D11->setIconSize(ui->D1->size());
            break;
        case 12:
            ui->D12->setIcon(generar_icono(nombre));
            ui->D12->setIconSize(ui->D1->size());
            break;
        case 13:
            ui->D13->setIcon(generar_icono(nombre));
            ui->D13->setIconSize(ui->D1->size());
            break;
        case 14:
            ui->D14->setIcon(generar_icono(nombre));
            ui->D14->setIconSize(ui->D1->size());
            break;
        case 15:
            ui->D15->setIcon(generar_icono(nombre));
            ui->D15->setIconSize(ui->D1->size());
            break;
        }
        break;
    case 5:
        switch (columna) {
        case 1:
            ui->E1->setIcon(generar_icono(nombre));
            ui->E1->setIconSize(ui->E1->size());
            break;
        case 2:
            ui->E2->setIcon(generar_icono(nombre));
            ui->E2->setIconSize(ui->E1->size());
            break;

        case 3:
            ui->E3->setIcon(generar_icono(nombre));
            ui->E4->setIconSize(ui->E1->size());
            break;
        case 4:
            ui->E4->setIcon(generar_icono(nombre));
            ui->E4->setIconSize(ui->E1->size());
            break;
        case 5:
            ui->E5->setIcon(generar_icono(nombre));
            ui->E5->setIconSize(ui->E1->size());
            break;
        case 6:
            ui->E6->setIcon(generar_icono(nombre));
            ui->E6->setIconSize(ui->E1->size());
            break;
        case 7:
            ui->E7->setIcon(generar_icono(nombre));
            ui->E7->setIconSize(ui->E1->size());
            break;
        case 8:
            ui->E8->setIcon(generar_icono(nombre));
            ui->E8->setIconSize(ui->E1->size());
            break;
        case 9:
            ui->E9->setIcon(generar_icono(nombre));
            ui->E9->setIconSize(ui->E1->size());
            break;
        case 10:
            ui->E10->setIcon(generar_icono(nombre));
            ui->E10->setIconSize(ui->E1->size());
            break;
        case 11:
            ui->E11->setIcon(generar_icono(nombre));
            ui->E11->setIconSize(ui->E1->size());
            break;
        case 12:
            ui->E12->setIcon(generar_icono(nombre));
            ui->E12->setIconSize(ui->E1->size());
            break;
        case 13:
            ui->E13->setIcon(generar_icono(nombre));
            ui->E13->setIconSize(ui->E1->size());
            break;
        case 14:
            ui->E14->setIcon(generar_icono(nombre));
            ui->E14->setIconSize(ui->E1->size());
            break;
        case 15:
            ui->E15->setIcon(generar_icono(nombre));
            ui->E15->setIconSize(ui->E1->size());
            break;
        }
        break;
    case 6:
        switch (columna) {
        case 1:
            ui->F1->setIcon(generar_icono(nombre));
            ui->F1->setIconSize(ui->F1->size());
            break;
        case 2:
            ui->F2->setIcon(generar_icono(nombre));
            ui->F2->setIconSize(ui->F1->size());
            break;

        case 3:
            ui->F3->setIcon(generar_icono(nombre));
            ui->F4->setIconSize(ui->F1->size());
            break;
        case 4:
            ui->F4->setIcon(generar_icono(nombre));
            ui->F4->setIconSize(ui->F1->size());
            break;
        case 5:
            ui->F5->setIcon(generar_icono(nombre));
            ui->F5->setIconSize(ui->F1->size());
            break;
        case 6:
            ui->F6->setIcon(generar_icono(nombre));
            ui->F6->setIconSize(ui->F1->size());
            break;
        case 7:
            ui->F7->setIcon(generar_icono(nombre));
            ui->F7->setIconSize(ui->F1->size());
            break;
        case 8:
            ui->F8->setIcon(generar_icono(nombre));
            ui->F8->setIconSize(ui->F1->size());
            break;
        case 9:
            ui->F9->setIcon(generar_icono(nombre));
            ui->F9->setIconSize(ui->F1->size());
            break;
        case 10:
            ui->F10->setIcon(generar_icono(nombre));
            ui->F10->setIconSize(ui->F1->size());
            break;
        case 11:
            ui->F11->setIcon(generar_icono(nombre));
            ui->F11->setIconSize(ui->F1->size());
            break;
        case 12:
            ui->F12->setIcon(generar_icono(nombre));
            ui->F12->setIconSize(ui->F1->size());
            break;
        case 13:
            ui->F13->setIcon(generar_icono(nombre));
            ui->F13->setIconSize(ui->F1->size());
            break;
        case 14:
            ui->F14->setIcon(generar_icono(nombre));
            ui->F14->setIconSize(ui->F1->size());
            break;
        case 15:
            ui->F15->setIcon(generar_icono(nombre));
            ui->F15->setIconSize(ui->F1->size());
            break;
        }
        break;
    case 7:
        switch (columna) {
        case 1:
            ui->G1->setIcon(generar_icono(nombre));
            ui->G1->setIconSize(ui->G1->size());
            break;
        case 2:
            ui->G2->setIcon(generar_icono(nombre));
            ui->G2->setIconSize(ui->G1->size());
            break;

        case 3:
            ui->G3->setIcon(generar_icono(nombre));
            ui->G4->setIconSize(ui->G1->size());
            break;
        case 4:
            ui->G4->setIcon(generar_icono(nombre));
            ui->G4->setIconSize(ui->G1->size());
            break;
        case 5:
            ui->G5->setIcon(generar_icono(nombre));
            ui->G5->setIconSize(ui->G1->size());
            break;
        case 6:
            ui->G6->setIcon(generar_icono(nombre));
            ui->G6->setIconSize(ui->G1->size());
            break;
        case 7:
            ui->G7->setIcon(generar_icono(nombre));
            ui->G7->setIconSize(ui->G1->size());
            break;
        case 8:
            ui->G8->setIcon(generar_icono(nombre));
            ui->G8->setIconSize(ui->G1->size());
            break;
        case 9:
            ui->G9->setIcon(generar_icono(nombre));
            ui->G9->setIconSize(ui->G1->size());
            break;
        case 10:
            ui->G10->setIcon(generar_icono(nombre));
            ui->G10->setIconSize(ui->G1->size());
            break;
        case 11:
            ui->G11->setIcon(generar_icono(nombre));
            ui->G11->setIconSize(ui->G1->size());
            break;
        case 12:
            ui->G12->setIcon(generar_icono(nombre));
            ui->G12->setIconSize(ui->G1->size());
            break;
        case 13:
            ui->G13->setIcon(generar_icono(nombre));
            ui->G13->setIconSize(ui->G1->size());
            break;
        case 14:
            ui->G14->setIcon(generar_icono(nombre));
            ui->G14->setIconSize(ui->G1->size());
            break;
        case 15:
            ui->G15->setIcon(generar_icono(nombre));
            ui->G15->setIconSize(ui->G1->size());
            break;
        }
        break;
    case 8:
        switch (columna) {
        case 1:
            ui->H1->setIcon(generar_icono(nombre));
            ui->H1->setIconSize(ui->H1->size());
            break;
        case 2:
            ui->H2->setIcon(generar_icono(nombre));
            ui->H2->setIconSize(ui->H1->size());
            break;

        case 3:
            ui->H3->setIcon(generar_icono(nombre));
            ui->H4->setIconSize(ui->H1->size());
            break;
        case 4:
            ui->H4->setIcon(generar_icono(nombre));
            ui->H4->setIconSize(ui->H1->size());
            break;
        case 5:
            ui->H5->setIcon(generar_icono(nombre));
            ui->H5->setIconSize(ui->H1->size());
            break;
        case 6:
            ui->H6->setIcon(generar_icono(nombre));
            ui->H6->setIconSize(ui->H1->size());
            break;
        case 7:
            ui->H7->setIcon(generar_icono(nombre));
            ui->H7->setIconSize(ui->H1->size());
            break;
        case 8:
            ui->H8->setIcon(generar_icono(nombre));
            ui->H8->setIconSize(ui->H1->size());
            break;
        case 9:
            ui->H9->setIcon(generar_icono(nombre));
            ui->H9->setIconSize(ui->H1->size());
            break;
        case 10:
            ui->H10->setIcon(generar_icono(nombre));
            ui->H10->setIconSize(ui->H1->size());
            break;
        case 11:
            ui->H11->setIcon(generar_icono(nombre));
            ui->H11->setIconSize(ui->H1->size());
            break;
        case 12:
            ui->H12->setIcon(generar_icono(nombre));
            ui->H12->setIconSize(ui->H1->size());
            break;
        case 13:
            ui->H13->setIcon(generar_icono(nombre));
            ui->H13->setIconSize(ui->H1->size());
            break;
        case 14:
            ui->H14->setIcon(generar_icono(nombre));
            ui->H14->setIconSize(ui->H1->size());
            break;
        case 15:
            ui->H15->setIcon(generar_icono(nombre));
            ui->H15->setIconSize(ui->H1->size());
            break;
        }
        break;
    case 9:
        switch (columna) {
        case 1:
            ui->I1->setIcon(generar_icono(nombre));
            ui->I1->setIconSize(ui->I1->size());
            break;
        case 2:
            ui->I2->setIcon(generar_icono(nombre));
            ui->I2->setIconSize(ui->I1->size());
            break;

        case 3:
            ui->I3->setIcon(generar_icono(nombre));
            ui->I4->setIconSize(ui->I1->size());
            break;
        case 4:
            ui->I4->setIcon(generar_icono(nombre));
            ui->I4->setIconSize(ui->I1->size());
            break;
        case 5:
            ui->I5->setIcon(generar_icono(nombre));
            ui->I5->setIconSize(ui->I1->size());
            break;
        case 6:
            ui->I6->setIcon(generar_icono(nombre));
            ui->I6->setIconSize(ui->I1->size());
            break;
        case 7:
            ui->I7->setIcon(generar_icono(nombre));
            ui->I7->setIconSize(ui->I1->size());
            break;
        case 8:
            ui->I8->setIcon(generar_icono(nombre));
            ui->I8->setIconSize(ui->I1->size());
            break;
        case 9:
            ui->I9->setIcon(generar_icono(nombre));
            ui->I9->setIconSize(ui->I1->size());
            break;
        case 10:
            ui->I10->setIcon(generar_icono(nombre));
            ui->I10->setIconSize(ui->I1->size());
            break;
        case 11:
            ui->I11->setIcon(generar_icono(nombre));
            ui->I11->setIconSize(ui->I1->size());
            break;
        case 12:
            ui->I12->setIcon(generar_icono(nombre));
            ui->I12->setIconSize(ui->I1->size());
            break;
        case 13:
            ui->I13->setIcon(generar_icono(nombre));
            ui->I13->setIconSize(ui->I1->size());
            break;
        case 14:
            ui->I14->setIcon(generar_icono(nombre));
            ui->I14->setIconSize(ui->I1->size());
            break;
        case 15:
            ui->I15->setIcon(generar_icono(nombre));
            ui->I15->setIconSize(ui->I1->size());
            break;
        }
        break;
    case 10:
        switch (columna) {
        case 1:
            ui->J1->setIcon(generar_icono(nombre));
            ui->J1->setIconSize(ui->J1->size());
            break;
        case 2:
            ui->J2->setIcon(generar_icono(nombre));
            ui->J2->setIconSize(ui->J1->size());
            break;

        case 3:
            ui->J3->setIcon(generar_icono(nombre));
            ui->J4->setIconSize(ui->J1->size());
            break;
        case 4:
            ui->J4->setIcon(generar_icono(nombre));
            ui->J4->setIconSize(ui->J1->size());
            break;
        case 5:
            ui->J5->setIcon(generar_icono(nombre));
            ui->J5->setIconSize(ui->J1->size());
            break;
        case 6:
            ui->J6->setIcon(generar_icono(nombre));
            ui->J6->setIconSize(ui->J1->size());
            break;
        case 7:
            ui->J7->setIcon(generar_icono(nombre));
            ui->J7->setIconSize(ui->J1->size());
            break;
        case 8:
            ui->J8->setIcon(generar_icono(nombre));
            ui->J8->setIconSize(ui->J1->size());
            break;
        case 9:
            ui->J9->setIcon(generar_icono(nombre));
            ui->J9->setIconSize(ui->J1->size());
            break;
        case 10:
            ui->J10->setIcon(generar_icono(nombre));
            ui->J10->setIconSize(ui->J1->size());
            break;
        case 11:
            ui->J11->setIcon(generar_icono(nombre));
            ui->J11->setIconSize(ui->J1->size());
            break;
        case 12:
            ui->J12->setIcon(generar_icono(nombre));
            ui->J12->setIconSize(ui->J1->size());
            break;
        case 13:
            ui->J13->setIcon(generar_icono(nombre));
            ui->J13->setIconSize(ui->J1->size());
            break;
        case 14:
            ui->J14->setIcon(generar_icono(nombre));
            ui->J14->setIconSize(ui->J1->size());
            break;
        case 15:
            ui->J15->setIcon(generar_icono(nombre));
            ui->J15->setIconSize(ui->J1->size());
            break;
        }
        break;
    case 11:
        switch (columna) {
        case 1:
            ui->K1->setIcon(generar_icono(nombre));
            ui->K1->setIconSize(ui->K1->size());
            break;
        case 2:
            ui->K2->setIcon(generar_icono(nombre));
            ui->K2->setIconSize(ui->K1->size());
            break;

        case 3:
            ui->K3->setIcon(generar_icono(nombre));
            ui->K4->setIconSize(ui->K1->size());
            break;
        case 4:
            ui->K4->setIcon(generar_icono(nombre));
            ui->K4->setIconSize(ui->K1->size());
            break;
        case 5:
            ui->K5->setIcon(generar_icono(nombre));
            ui->K5->setIconSize(ui->K1->size());
            break;
        case 6:
            ui->K6->setIcon(generar_icono(nombre));
            ui->K6->setIconSize(ui->K1->size());
            break;
        case 7:
            ui->K7->setIcon(generar_icono(nombre));
            ui->K7->setIconSize(ui->K1->size());
            break;
        case 8:
            ui->K8->setIcon(generar_icono(nombre));
            ui->K8->setIconSize(ui->K1->size());
            break;
        case 9:
            ui->K9->setIcon(generar_icono(nombre));
            ui->K9->setIconSize(ui->K1->size());
            break;
        case 10:
            ui->K10->setIcon(generar_icono(nombre));
            ui->K10->setIconSize(ui->K1->size());
            break;
        case 11:
            ui->K11->setIcon(generar_icono(nombre));
            ui->K11->setIconSize(ui->K1->size());
            break;
        case 12:
            ui->K12->setIcon(generar_icono(nombre));
            ui->K12->setIconSize(ui->K1->size());
            break;
        case 13:
            ui->K13->setIcon(generar_icono(nombre));
            ui->K13->setIconSize(ui->K1->size());
            break;
        case 14:
            ui->K14->setIcon(generar_icono(nombre));
            ui->K14->setIconSize(ui->K1->size());
            break;
        case 15:
            ui->K15->setIcon(generar_icono(nombre));
            ui->K15->setIconSize(ui->K1->size());
            break;
        }
        break;
    case 12:
        switch (columna) {
        case 1:
            ui->L1->setIcon(generar_icono(nombre));
            ui->L1->setIconSize(ui->L1->size());
            break;
        case 2:
            ui->L2->setIcon(generar_icono(nombre));
            ui->L2->setIconSize(ui->L1->size());
            break;

        case 3:
            ui->L3->setIcon(generar_icono(nombre));
            ui->L4->setIconSize(ui->L1->size());
            break;
        case 4:
            ui->L4->setIcon(generar_icono(nombre));
            ui->L4->setIconSize(ui->L1->size());
            break;
        case 5:
            ui->L5->setIcon(generar_icono(nombre));
            ui->L5->setIconSize(ui->L1->size());
            break;
        case 6:
            ui->L6->setIcon(generar_icono(nombre));
            ui->L6->setIconSize(ui->L1->size());
            break;
        case 7:
            ui->L7->setIcon(generar_icono(nombre));
            ui->L7->setIconSize(ui->L1->size());
            break;
        case 8:
            ui->L8->setIcon(generar_icono(nombre));
            ui->L8->setIconSize(ui->L1->size());
            break;
        case 9:
            ui->L9->setIcon(generar_icono(nombre));
            ui->L9->setIconSize(ui->L1->size());
            break;
        case 10:
            ui->L10->setIcon(generar_icono(nombre));
            ui->L10->setIconSize(ui->L1->size());
            break;
        case 11:
            ui->L11->setIcon(generar_icono(nombre));
            ui->L11->setIconSize(ui->L1->size());
            break;
        case 12:
            ui->L12->setIcon(generar_icono(nombre));
            ui->L12->setIconSize(ui->L1->size());
            break;
        case 13:
            ui->L13->setIcon(generar_icono(nombre));
            ui->L13->setIconSize(ui->L1->size());
            break;
        case 14:
            ui->L14->setIcon(generar_icono(nombre));
            ui->L14->setIconSize(ui->L1->size());
            break;
        case 15:
            ui->L15->setIcon(generar_icono(nombre));
            ui->L15->setIconSize(ui->L1->size());
            break;
        }
        break;
    case 13:
        switch (columna) {
        case 1:
            ui->M1->setIcon(generar_icono(nombre));
            ui->M1->setIconSize(ui->M1->size());
            break;
        case 2:
            ui->M2->setIcon(generar_icono(nombre));
            ui->M2->setIconSize(ui->M1->size());
            break;

        case 3:
            ui->M3->setIcon(generar_icono(nombre));
            ui->M4->setIconSize(ui->M1->size());
            break;
        case 4:
            ui->M4->setIcon(generar_icono(nombre));
            ui->M4->setIconSize(ui->M1->size());
            break;
        case 5:
            ui->M5->setIcon(generar_icono(nombre));
            ui->M5->setIconSize(ui->M1->size());
            break;
        case 6:
            ui->M6->setIcon(generar_icono(nombre));
            ui->M6->setIconSize(ui->M1->size());
            break;
        case 7:
            ui->M7->setIcon(generar_icono(nombre));
            ui->M7->setIconSize(ui->M1->size());
            break;
        case 8:
            ui->M8->setIcon(generar_icono(nombre));
            ui->M8->setIconSize(ui->M1->size());
            break;
        case 9:
            ui->M9->setIcon(generar_icono(nombre));
            ui->M9->setIconSize(ui->M1->size());
            break;
        case 10:
            ui->M10->setIcon(generar_icono(nombre));
            ui->M10->setIconSize(ui->M1->size());
            break;
        case 11:
            ui->M11->setIcon(generar_icono(nombre));
            ui->M11->setIconSize(ui->M1->size());
            break;
        case 12:
            ui->M12->setIcon(generar_icono(nombre));
            ui->M12->setIconSize(ui->M1->size());
            break;
        case 13:
            ui->M13->setIcon(generar_icono(nombre));
            ui->M13->setIconSize(ui->M1->size());
            break;
        case 14:
            ui->M14->setIcon(generar_icono(nombre));
            ui->M14->setIconSize(ui->M1->size());
            break;
        case 15:
            ui->M15->setIcon(generar_icono(nombre));
            ui->M15->setIconSize(ui->M1->size());
            break;
        }
        break;
    case 14:
        switch (columna) {
        case 1:
            ui->N1->setIcon(generar_icono(nombre));
            ui->N1->setIconSize(ui->N1->size());
            break;
        case 2:
            ui->N2->setIcon(generar_icono(nombre));
            ui->N2->setIconSize(ui->N1->size());
            break;

        case 3:
            ui->N3->setIcon(generar_icono(nombre));
            ui->N4->setIconSize(ui->N1->size());
            break;
        case 4:
            ui->N4->setIcon(generar_icono(nombre));
            ui->N4->setIconSize(ui->N1->size());
            break;
        case 5:
            ui->N5->setIcon(generar_icono(nombre));
            ui->N5->setIconSize(ui->N1->size());
            break;
        case 6:
            ui->N6->setIcon(generar_icono(nombre));
            ui->N6->setIconSize(ui->N1->size());
            break;
        case 7:
            ui->N7->setIcon(generar_icono(nombre));
            ui->N7->setIconSize(ui->N1->size());
            break;
        case 8:
            ui->N8->setIcon(generar_icono(nombre));
            ui->N8->setIconSize(ui->N1->size());
            break;
        case 9:
            ui->N9->setIcon(generar_icono(nombre));
            ui->N9->setIconSize(ui->N1->size());
            break;
        case 10:
            ui->N10->setIcon(generar_icono(nombre));
            ui->N10->setIconSize(ui->N1->size());
            break;
        case 11:
            ui->N11->setIcon(generar_icono(nombre));
            ui->N11->setIconSize(ui->N1->size());
            break;
        case 12:
            ui->N12->setIcon(generar_icono(nombre));
            ui->N12->setIconSize(ui->N1->size());
            break;
        case 13:
            ui->N13->setIcon(generar_icono(nombre));
            ui->N13->setIconSize(ui->N1->size());
            break;
        case 14:
            ui->N14->setIcon(generar_icono(nombre));
            ui->N14->setIconSize(ui->N1->size());
            break;
        case 15:
            ui->N15->setIcon(generar_icono(nombre));
            ui->N15->setIconSize(ui->N1->size());
            break;
        }
        break;
    case 15:
        switch (columna) {
        case 1:
            ui->O1->setIcon(generar_icono(nombre));
            ui->O1->setIconSize(ui->O1->size());
            break;
        case 2:
            ui->O2->setIcon(generar_icono(nombre));
            ui->O2->setIconSize(ui->O1->size());
            break;

        case 3:
            ui->O3->setIcon(generar_icono(nombre));
            ui->O4->setIconSize(ui->O1->size());
            break;
        case 4:
            ui->O4->setIcon(generar_icono(nombre));
            ui->O4->setIconSize(ui->O1->size());
            break;
        case 5:
            ui->O5->setIcon(generar_icono(nombre));
            ui->O5->setIconSize(ui->O1->size());
            break;
        case 6:
            ui->O6->setIcon(generar_icono(nombre));
            ui->O6->setIconSize(ui->O1->size());
            break;
        case 7:
            ui->O7->setIcon(generar_icono(nombre));
            ui->O7->setIconSize(ui->O1->size());
            break;
        case 8:
            ui->O8->setIcon(generar_icono(nombre));
            ui->O8->setIconSize(ui->O1->size());
            break;
        case 9:
            ui->O9->setIcon(generar_icono(nombre));
            ui->O9->setIconSize(ui->O1->size());
            break;
        case 10:
            ui->O10->setIcon(generar_icono(nombre));
            ui->O10->setIconSize(ui->O1->size());
            break;
        case 11:
            ui->O11->setIcon(generar_icono(nombre));
            ui->O11->setIconSize(ui->O1->size());
            break;
        case 12:
            ui->O12->setIcon(generar_icono(nombre));
            ui->O12->setIconSize(ui->O1->size());
            break;
        case 13:
            ui->O13->setIcon(generar_icono(nombre));
            ui->O13->setIconSize(ui->O1->size());
            break;
        case 14:
            ui->O14->setIcon(generar_icono(nombre));
            ui->O14->setIconSize(ui->O1->size());
            break;
        case 15:
            ui->O15->setIcon(generar_icono(nombre));
            ui->O15->setIconSize(ui->O1->size());
            break;
        }
        break;
    }
}

void MainWindow::desbloquear(int x, int y, coordenada final)
{
    if(x==0&&y==0){
        if(x==final.x && y==final.y){
            ui->A1->setEnabled(true);
        }else{
            ui->A1->setEnabled(true);
            ui->A2->setEnabled(true);
            ui->B1->setEnabled(true);
        }
    }
    if(x==0&&y==1){
        if(x==final.x && y==final.y){
            ui->A2->setEnabled(true);
        }else{
            ui->A1->setEnabled(true);
            ui->A2->setEnabled(true);
            ui->A3->setEnabled(true);
            ui->B2->setEnabled(true);
        }
    }
    if(x==0&&y==2){
        if(x==final.x && y==final.y){
            ui->A3->setEnabled(true);
        }else{
            ui->A2->setEnabled(true);
            ui->A3->setEnabled(true);
            ui->A4->setEnabled(true);
            ui->B3->setEnabled(true);
        }
    }
    if(x==0&&y==3){
        if(x==final.x && y==final.y){
            ui->A4->setEnabled(true);
        }else{
            ui->A3->setEnabled(true);
            ui->A4->setEnabled(true);
            ui->A5->setEnabled(true);
            ui->B4->setEnabled(true);
        }
    }
    if(x==0&&y==4){
        if(x==final.x && y==final.y){
            ui->A5->setEnabled(true);
        }else{
            ui->A4->setEnabled(true);
            ui->A5->setEnabled(true);
            ui->A6->setEnabled(true);
            ui->B5->setEnabled(true);
        }
    }
    if(x==0&&y==5){
        if(x==final.x && y==final.y){
            ui->A6->setEnabled(true);
        }else{
            ui->A5->setEnabled(true);
            ui->A6->setEnabled(true);
            ui->A7->setEnabled(true);
            ui->B6->setEnabled(true);
        }
    }
    if(x==0&&y==6){
        if(x==final.x && y==final.y){
            ui->A7->setEnabled(true);
        }else{
            ui->A6->setEnabled(true);
            ui->A7->setEnabled(true);
            ui->A8->setEnabled(true);
            ui->B7->setEnabled(true);
        }
    }
    if(x==0&&y==7){
        if(x==final.x && y==final.y){
            ui->A8->setEnabled(true);
        }else{
            ui->A7->setEnabled(true);
            ui->A8->setEnabled(true);
            ui->A9->setEnabled(true);
            ui->B8->setEnabled(true);
        }
    }
    if(x==0&&y==8){
        if(x==final.x && y==final.y){
            ui->A9->setEnabled(true);
        }else{
            ui->A8->setEnabled(true);
            ui->A9->setEnabled(true);
            ui->A10->setEnabled(true);
            ui->B9->setEnabled(true);
        }
    }
    if(x==0&&y==9){
        if(x==final.x && y==final.y){
            ui->A10->setEnabled(true);
        }else{
            ui->A9->setEnabled(true);
            ui->A10->setEnabled(true);
            ui->A11->setEnabled(true);
            ui->B10->setEnabled(true);
        }
    }
    if(x==0&&y==10){
        if(x==final.x && y==final.y){
            ui->A11->setEnabled(true);
        }else{
            ui->A10->setEnabled(true);
            ui->A11->setEnabled(true);
            ui->A12->setEnabled(true);
            ui->B11->setEnabled(true);
        }
    }
    if(x==0&&y==11){
        if(x==final.x && y==final.y){
            ui->A12->setEnabled(true);
        }else{
            ui->A11->setEnabled(true);
            ui->A12->setEnabled(true);
            ui->A13->setEnabled(true);
            ui->B12->setEnabled(true);
        }
    }
    if(x==0&&y==12){
        if(x==final.x && y==final.y){
            ui->A13->setEnabled(true);
        }else{
            ui->A12->setEnabled(true);
            ui->A13->setEnabled(true);
            ui->A14->setEnabled(true);
            ui->B13->setEnabled(true);
        }
    }
    if(x==0&&y==13){
        if(x==final.x && y==final.y){
            ui->A14->setEnabled(true);
        }else{
            ui->A13->setEnabled(true);
            ui->A14->setEnabled(true);
            ui->A15->setEnabled(true);
            ui->B14->setEnabled(true);}
    }
    if(x==0&&y==14){
        if(x==final.x && y==final.y){
            ui->A15->setEnabled(true);
        }else{
            ui->A14->setEnabled(true);
            ui->A15->setEnabled(true);
            ui->B15->setEnabled(true);
        }
    }
    //B

    if(x==1&&y==0){
        if(x==final.x && y==final.y){
            ui->B1->setEnabled(true);
        }else{
            ui->B1->setEnabled(true);
            ui->B2->setEnabled(true);
            ui->A1->setEnabled(true);
            ui->C1->setEnabled(true);}
    }
    if(x==1&&y==1){
        if(x==final.x && y==final.y){
            ui->B2->setEnabled(true);
        }else{
            ui->B1->setEnabled(true);
            ui->B2->setEnabled(true);
            ui->B3->setEnabled(true);
            ui->A2->setEnabled(true);
            ui->C2->setEnabled(true);}
    }
    if(x==1&&y==2){
        if(x==final.x && y==final.y){
            ui->B3->setEnabled(true);
        }else{
            ui->B2->setEnabled(true);
            ui->B3->setEnabled(true);
            ui->B4->setEnabled(true);
            ui->A3->setEnabled(true);
            ui->C3->setEnabled(true);}
    }
    if(x==1&&y==3){
        if(x==final.x && y==final.y){
            ui->B4->setEnabled(true);
        }else{
            ui->B3->setEnabled(true);
            ui->B4->setEnabled(true);
            ui->B5->setEnabled(true);
            ui->A4->setEnabled(true);
            ui->C4->setEnabled(true);}
    }
    if(x==1&&y==4){
        if(x==final.x && y==final.y){
            ui->B5->setEnabled(true);
        }else{
            ui->B4->setEnabled(true);
            ui->B5->setEnabled(true);
            ui->B6->setEnabled(true);
            ui->A5->setEnabled(true);
            ui->C5->setEnabled(true);}
    }
    if(x==1&&y==5){
        if(x==final.x && y==final.y){
            ui->B6->setEnabled(true);
        }else{
            ui->B5->setEnabled(true);
            ui->B6->setEnabled(true);
            ui->B7->setEnabled(true);
            ui->A6->setEnabled(true);
            ui->C6->setEnabled(true);}
    }
    if(x==1&&y==6){
        if(x==final.x && y==final.y){
            ui->B7->setEnabled(true);
        }else{
            ui->B6->setEnabled(true);
            ui->B7->setEnabled(true);
            ui->B8->setEnabled(true);
            ui->A7->setEnabled(true);
            ui->C7->setEnabled(true);}
    }
    if(x==1&&y==7){
        if(x==final.x && y==final.y){
            ui->B8->setEnabled(true);
        }else{
            ui->B7->setEnabled(true);
            ui->B8->setEnabled(true);
            ui->B9->setEnabled(true);
            ui->A8->setEnabled(true);
            ui->C8->setEnabled(true);}
    }
    if(x==1&&y==8){
        if(x==final.x && y==final.y){
            ui->B9->setEnabled(true);
        }else{
            ui->B8->setEnabled(true);
            ui->B9->setEnabled(true);
            ui->B10->setEnabled(true);
            ui->A9->setEnabled(true);
            ui->C9->setEnabled(true);}
    }
    if(x==1&&y==9){
        if(x==final.x && y==final.y){
            ui->B10->setEnabled(true);
        }else{
            ui->B9->setEnabled(true);
            ui->B10->setEnabled(true);
            ui->B11->setEnabled(true);
            ui->A10->setEnabled(true);
            ui->C10->setEnabled(true);}
    }
    if(x==1&&y==10){
        if(x==final.x && y==final.y){
            ui->B11->setEnabled(true);
        }else{
            ui->B10->setEnabled(true);
            ui->B11->setEnabled(true);
            ui->B12->setEnabled(true);
            ui->A11->setEnabled(true);
            ui->C11->setEnabled(true);}
    }
    if(x==1&&y==11){
        if(x==final.x && y==final.y){
            ui->B12->setEnabled(true);
        }else{
            ui->B11->setEnabled(true);
            ui->B12->setEnabled(true);
            ui->B13->setEnabled(true);
            ui->A12->setEnabled(true);
            ui->C12->setEnabled(true);}
    }
    if(x==1&&y==12){
        if(x==final.x && y==final.y){
            ui->B13->setEnabled(true);
        }else{
            ui->B12->setEnabled(true);
            ui->B13->setEnabled(true);
            ui->B14->setEnabled(true);
            ui->A13->setEnabled(true);
            ui->C13->setEnabled(true);}
    }
    if(x==1&&y==13){
        if(x==final.x && y==final.y){
            ui->B14->setEnabled(true);
        }else{
            ui->B13->setEnabled(true);
            ui->B14->setEnabled(true);
            ui->B15->setEnabled(true);
            ui->A14->setEnabled(true);
            ui->C14->setEnabled(true);}
    }
    if(x==1&&y==14){
        if(x==final.x && y==final.y){
            ui->B15->setEnabled(true);
        }else{
            ui->B14->setEnabled(true);
            ui->B15->setEnabled(true);
            ui->A15->setEnabled(true);
            ui->C15->setEnabled(true);}
    }
    //C
    if(x==2&&y==0){
        if(x==final.x && y==final.y){
            ui->C1->setEnabled(true);
        }else{
            ui->C1->setEnabled(true);
            ui->C2->setEnabled(true);
            ui->B1->setEnabled(true);
            ui->D1->setEnabled(true);}
    }
    if(x==2&&y==1){
        if(x==final.x && y==final.y){
            ui->C2->setEnabled(true);
        }else{
            ui->C1->setEnabled(true);
            ui->C2->setEnabled(true);
            ui->C3->setEnabled(true);
            ui->B2->setEnabled(true);
            ui->D2->setEnabled(true);}
    }
    if(x==2&&y==2){
        if(x==final.x && y==final.y){
            ui->C3->setEnabled(true);
        }else{
            ui->C2->setEnabled(true);
            ui->C3->setEnabled(true);
            ui->C4->setEnabled(true);
            ui->B3->setEnabled(true);
            ui->D3->setEnabled(true);}
    }
    if(x==2&&y==3){
        if(x==final.x && y==final.y){
            ui->C4->setEnabled(true);
        }else{
            ui->C3->setEnabled(true);
            ui->C4->setEnabled(true);
            ui->C5->setEnabled(true);
            ui->B4->setEnabled(true);
            ui->D4->setEnabled(true);}
    }
    if(x==2&&y==4){
        if(x==final.x && y==final.y){
            ui->C5->setEnabled(true);
        }else{
            ui->C4->setEnabled(true);
            ui->C5->setEnabled(true);
            ui->C6->setEnabled(true);
            ui->B5->setEnabled(true);
            ui->D5->setEnabled(true);}
    }
    if(x==2&&y==5){
        if(x==final.x && y==final.y){
            ui->C6->setEnabled(true);
        }else{
            ui->C5->setEnabled(true);
            ui->C6->setEnabled(true);
            ui->C7->setEnabled(true);
            ui->B6->setEnabled(true);
            ui->D6->setEnabled(true);}
    }
    if(x==2&&y==6){
        if(x==final.x && y==final.y){
            ui->C7->setEnabled(true);
        }else{
            ui->C6->setEnabled(true);
            ui->C7->setEnabled(true);
            ui->C8->setEnabled(true);
            ui->B7->setEnabled(true);
            ui->D7->setEnabled(true);}
    }
    if(x==2&&y==7){
        if(x==final.x && y==final.y){
            ui->C8->setEnabled(true);
        }else{
            ui->C7->setEnabled(true);
            ui->C8->setEnabled(true);
            ui->C9->setEnabled(true);
            ui->B8->setEnabled(true);
            ui->D8->setEnabled(true);}
    }
    if(x==2&&y==8){
        if(x==final.x && y==final.y){
            ui->C9->setEnabled(true);
        }else{
            ui->C8->setEnabled(true);
            ui->C9->setEnabled(true);
            ui->C10->setEnabled(true);
            ui->B9->setEnabled(true);
            ui->D9->setEnabled(true);}
    }
    if(x==2&&y==9){
        if(x==final.x && y==final.y){
            ui->C10->setEnabled(true);
        }else{
            ui->C9->setEnabled(true);
            ui->C10->setEnabled(true);
            ui->C11->setEnabled(true);
            ui->B10->setEnabled(true);
            ui->D10->setEnabled(true);}
    }
    if(x==2&&y==10){
        if(x==final.x && y==final.y){
            ui->C11->setEnabled(true);
        }else{
            ui->C10->setEnabled(true);
            ui->C11->setEnabled(true);
            ui->C12->setEnabled(true);
            ui->B11->setEnabled(true);
            ui->D11->setEnabled(true);}
    }
    if(x==2&&y==11){
        if(x==final.x && y==final.y){
            ui->C12->setEnabled(true);
        }else{
            ui->C11->setEnabled(true);
            ui->C12->setEnabled(true);
            ui->C13->setEnabled(true);
            ui->B12->setEnabled(true);
            ui->D12->setEnabled(true);}
    }
    if(x==2&&y==12){
        if(x==final.x && y==final.y){
            ui->C13->setEnabled(true);
        }else{
            ui->C12->setEnabled(true);
            ui->C13->setEnabled(true);
            ui->C14->setEnabled(true);
            ui->B13->setEnabled(true);
            ui->D13->setEnabled(true);}
    }
    if(x==2&&y==13){
        if(x==final.x && y==final.y){
            ui->C14->setEnabled(true);
        }else{
            ui->C13->setEnabled(true);
            ui->C14->setEnabled(true);
            ui->C15->setEnabled(true);
            ui->B14->setEnabled(true);
            ui->D14->setEnabled(true);}
    }
    if(x==2&&y==14){
        if(x==final.x && y==final.y){
            ui->C15->setEnabled(true);
        }else{
            ui->C14->setEnabled(true);
            ui->C15->setEnabled(true);
            ui->B15->setEnabled(true);
            ui->D15->setEnabled(true);}
    }
    //D
    if(x==3&&y==0){
        if(x==final.x && y==final.y){
            ui->D1->setEnabled(true);
        }else{
            ui->D1->setEnabled(true);
            ui->D2->setEnabled(true);
            ui->C1->setEnabled(true);
            ui->E1->setEnabled(true);}
    }
    if(x==3&&y==1){
        if(x==final.x && y==final.y){
            ui->D2->setEnabled(true);
        }else{
            ui->D1->setEnabled(true);
            ui->D2->setEnabled(true);
            ui->D3->setEnabled(true);
            ui->C2->setEnabled(true);
            ui->E2->setEnabled(true);}
    }
    if(x==3&&y==2){
        if(x==final.x && y==final.y){
            ui->D3->setEnabled(true);
        }else{
            ui->D2->setEnabled(true);
            ui->D3->setEnabled(true);
            ui->D4->setEnabled(true);
            ui->C3->setEnabled(true);
            ui->E3->setEnabled(true);}
    }
    if(x==3&&y==3){
        if(x==final.x && y==final.y){
            ui->D4->setEnabled(true);
        }else{
            ui->D3->setEnabled(true);
            ui->D4->setEnabled(true);
            ui->D5->setEnabled(true);
            ui->C4->setEnabled(true);
            ui->E4->setEnabled(true);}
    }
    if(x==3&&y==4){
        if(x==final.x && y==final.y){
            ui->D5->setEnabled(true);
        }else{
            ui->D4->setEnabled(true);
            ui->D5->setEnabled(true);
            ui->D6->setEnabled(true);
            ui->C5->setEnabled(true);
            ui->E5->setEnabled(true);}
    }
    if(x==3&&y==5){
        if(x==final.x && y==final.y){
            ui->D6->setEnabled(true);
        }else{
            ui->D5->setEnabled(true);
            ui->D6->setEnabled(true);
            ui->D7->setEnabled(true);
            ui->C6->setEnabled(true);
            ui->E6->setEnabled(true);}
    }
    if(x==3&&y==6){
        if(x==final.x && y==final.y){
            ui->D7->setEnabled(true);
        }else{
            ui->D6->setEnabled(true);
            ui->D7->setEnabled(true);
            ui->D8->setEnabled(true);
            ui->C7->setEnabled(true);
            ui->E7->setEnabled(true);}
    }
    if(x==3&&y==7){
        if(x==final.x && y==final.y){
            ui->D8->setEnabled(true);
        }else{
            ui->D7->setEnabled(true);
            ui->D8->setEnabled(true);
            ui->D9->setEnabled(true);
            ui->C8->setEnabled(true);
            ui->E8->setEnabled(true);}
    }
    if(x==3&&y==8){
        if(x==final.x && y==final.y){
            ui->D9->setEnabled(true);
        }else{
            ui->D8->setEnabled(true);
            ui->D9->setEnabled(true);
            ui->D10->setEnabled(true);
            ui->C9->setEnabled(true);
            ui->E9->setEnabled(true);}
    }
    if(x==3&&y==9){
        if(x==final.x && y==final.y){
            ui->D10->setEnabled(true);
        }else{
            ui->D9->setEnabled(true);
            ui->D10->setEnabled(true);
            ui->D11->setEnabled(true);
            ui->C10->setEnabled(true);
            ui->E10->setEnabled(true);}
    }
    if(x==3&&y==10){
        if(x==final.x && y==final.y){
            ui->D11->setEnabled(true);
        }else{
            ui->D10->setEnabled(true);
            ui->D11->setEnabled(true);
            ui->D12->setEnabled(true);
            ui->C11->setEnabled(true);
            ui->E11->setEnabled(true);}
    }
    if(x==3&&y==11){
        if(x==final.x && y==final.y){
            ui->D12->setEnabled(true);
        }else{
            ui->D11->setEnabled(true);
            ui->D12->setEnabled(true);
            ui->D13->setEnabled(true);
            ui->C12->setEnabled(true);
            ui->E12->setEnabled(true);}
    }
    if(x==3&&y==12){
        if(x==final.x && y==final.y){
            ui->D13->setEnabled(true);
        }else{
            ui->D12->setEnabled(true);
            ui->D13->setEnabled(true);
            ui->D14->setEnabled(true);
            ui->C13->setEnabled(true);
            ui->E13->setEnabled(true);}
    }
    if(x==3&&y==13){
        if(x==final.x && y==final.y){
            ui->D14->setEnabled(true);
        }else{
            ui->D13->setEnabled(true);
            ui->D14->setEnabled(true);
            ui->D15->setEnabled(true);
            ui->C14->setEnabled(true);
            ui->E14->setEnabled(true);}
    }
    if(x==3&&y==14){
        if(x==final.x && y==final.y){
            ui->D15->setEnabled(true);
        }else{
            ui->D14->setEnabled(true);
            ui->D15->setEnabled(true);
            ui->C15->setEnabled(true);
            ui->E15->setEnabled(true);
        }
    }
    //E
    if(x==4&&y==0){
        if(x==final.x && y==final.y){
            ui->E1->setEnabled(true);
        }else{
            ui->E1->setEnabled(true);
            ui->E2->setEnabled(true);
            ui->D1->setEnabled(true);
            ui->F1->setEnabled(true);
        }}
    if(x==4&&y==1){
        if(x==final.x && y==final.y){
            ui->E2->setEnabled(true);
        }else{
            ui->E1->setEnabled(true);
            ui->E2->setEnabled(true);
            ui->E3->setEnabled(true);
            ui->D2->setEnabled(true);
            ui->F2->setEnabled(true);
        }}
    if(x==4&&y==2){
        if(x==final.x && y==final.y){
            ui->E3->setEnabled(true);
        }else{
            ui->E2->setEnabled(true);
            ui->E3->setEnabled(true);
            ui->E4->setEnabled(true);
            ui->D3->setEnabled(true);
            ui->F3->setEnabled(true);
        }}
    if(x==4&&y==3){
        if(x==final.x && y==final.y){
            ui->E4->setEnabled(true);
        }else{
            ui->E3->setEnabled(true);
            ui->E4->setEnabled(true);
            ui->E5->setEnabled(true);
            ui->D4->setEnabled(true);
            ui->F4->setEnabled(true);
        }}
    if(x==4&&y==4){
        if(x==final.x && y==final.y){
            ui->E5->setEnabled(true);
        }else{
            ui->E4->setEnabled(true);
            ui->E5->setEnabled(true);
            ui->E6->setEnabled(true);
            ui->D5->setEnabled(true);
            ui->F5->setEnabled(true);
        }}
    if(x==4&&y==5){
        if(x==final.x && y==final.y){
            ui->E6->setEnabled(true);
        }else{
            ui->E5->setEnabled(true);
            ui->E6->setEnabled(true);
            ui->E7->setEnabled(true);
            ui->D6->setEnabled(true);
            ui->F6->setEnabled(true);
        }}
    if(x==4&&y==6){
        if(x==final.x && y==final.y){
            ui->E7->setEnabled(true);
        }else{
            ui->E6->setEnabled(true);
            ui->E7->setEnabled(true);
            ui->E8->setEnabled(true);
            ui->D7->setEnabled(true);
            ui->F7->setEnabled(true);
        }}
    if(x==4&&y==7){
        if(x==final.x && y==final.y){
            ui->E8->setEnabled(true);
        }else{
            ui->E7->setEnabled(true);
            ui->E8->setEnabled(true);
            ui->E9->setEnabled(true);
            ui->D8->setEnabled(true);
            ui->F8->setEnabled(true);
        }}
    if(x==4&&y==8){
        if(x==final.x && y==final.y){
            ui->E9->setEnabled(true);
        }else{
            ui->E8->setEnabled(true);
            ui->E9->setEnabled(true);
            ui->E10->setEnabled(true);
            ui->D9->setEnabled(true);
            ui->F9->setEnabled(true);
        }}
    if(x==4&&y==9){
        if(x==final.x && y==final.y){
            ui->E10->setEnabled(true);
        }else{
            ui->E9->setEnabled(true);
            ui->E10->setEnabled(true);
            ui->E11->setEnabled(true);
            ui->D10->setEnabled(true);
            ui->F10->setEnabled(true);
        }}
    if(x==4&&y==10){
        if(x==final.x && y==final.y){
            ui->E11->setEnabled(true);
        }else{
            ui->E10->setEnabled(true);
            ui->E11->setEnabled(true);
            ui->E12->setEnabled(true);
            ui->D11->setEnabled(true);
            ui->F11->setEnabled(true);
        }}
    if(x==4&&y==11){
        if(x==final.x && y==final.y){
            ui->E12->setEnabled(true);
        }else{
            ui->E11->setEnabled(true);
            ui->E12->setEnabled(true);
            ui->E13->setEnabled(true);
            ui->D12->setEnabled(true);
            ui->F12->setEnabled(true);
        }}
    if(x==4&&y==12){
        if(x==final.x && y==final.y){
            ui->E13->setEnabled(true);
        }else{
            ui->E12->setEnabled(true);
            ui->E13->setEnabled(true);
            ui->E14->setEnabled(true);
            ui->D13->setEnabled(true);
            ui->F13->setEnabled(true);
        }}
    if(x==4&&y==13){
        if(x==final.x && y==final.y){
            ui->E14->setEnabled(true);
        }else{
            ui->E13->setEnabled(true);
            ui->E14->setEnabled(true);
            ui->E15->setEnabled(true);
            ui->D14->setEnabled(true);
            ui->F14->setEnabled(true);
        }}
    if(x==4&&y==14){
        if(x==final.x && y==final.y){
            ui->E15->setEnabled(true);
        }else{
            ui->E14->setEnabled(true);
            ui->E15->setEnabled(true);
            ui->D15->setEnabled(true);
            ui->F15->setEnabled(true);
        }}

    //F
    if(x==5&&y==0){
        if(x==final.x && y==final.y){
            ui->F1->setEnabled(true);
        }else{
            ui->F1->setEnabled(true);
            ui->F2->setEnabled(true);
            ui->E1->setEnabled(true);
            ui->G1->setEnabled(true);
        }}
    if(x==5&&y==1){
        if(x==final.x && y==final.y){
            ui->F2->setEnabled(true);
        }else{
            ui->F1->setEnabled(true);
            ui->F2->setEnabled(true);
            ui->F3->setEnabled(true);
            ui->E2->setEnabled(true);
            ui->G2->setEnabled(true);
        }}
    if(x==5&&y==2){
        if(x==final.x && y==final.y){
            ui->F3->setEnabled(true);
        }else{
            ui->F2->setEnabled(true);
            ui->F3->setEnabled(true);
            ui->F4->setEnabled(true);
            ui->E3->setEnabled(true);
            ui->G3->setEnabled(true);
        }}
    if(x==5&&y==3){
        if(x==final.x && y==final.y){
            ui->F4->setEnabled(true);
        }else{
            ui->F3->setEnabled(true);
            ui->F4->setEnabled(true);
            ui->F5->setEnabled(true);
            ui->E4->setEnabled(true);
            ui->G4->setEnabled(true);
        }}
    if(x==5&&y==4){
        if(x==final.x && y==final.y){
            ui->F5->setEnabled(true);
        }else{
            ui->F4->setEnabled(true);
            ui->F5->setEnabled(true);
            ui->F6->setEnabled(true);
            ui->E5->setEnabled(true);
            ui->G5->setEnabled(true);
        }}
    if(x==5&&y==5){
        if(x==final.x && y==final.y){
            ui->F6->setEnabled(true);
        }else{
            ui->F5->setEnabled(true);
            ui->F6->setEnabled(true);
            ui->F7->setEnabled(true);
            ui->E6->setEnabled(true);
            ui->G6->setEnabled(true);
        }}
    if(x==5&&y==6){
        if(x==final.x && y==final.y){
            ui->F7->setEnabled(true);
        }else{
            ui->F6->setEnabled(true);
            ui->F7->setEnabled(true);
            ui->F8->setEnabled(true);
            ui->E7->setEnabled(true);
            ui->G7->setEnabled(true);
        }}
    if(x==5&&y==7){
        if(x==final.x && y==final.y){
            ui->F8->setEnabled(true);
        }else{
            ui->F7->setEnabled(true);
            ui->F8->setEnabled(true);
            ui->F9->setEnabled(true);
            ui->E8->setEnabled(true);
            ui->G8->setEnabled(true);
        }}
    if(x==5&&y==8){
        if(x==final.x && y==final.y){
            ui->F9->setEnabled(true);
        }else{
            ui->F8->setEnabled(true);
            ui->F9->setEnabled(true);
            ui->F10->setEnabled(true);
            ui->E9->setEnabled(true);
            ui->G9->setEnabled(true);
        }}
    if(x==5&&y==9){
        if(x==final.x && y==final.y){
            ui->F10->setEnabled(true);
        }else{
            ui->F9->setEnabled(true);
            ui->F10->setEnabled(true);
            ui->F11->setEnabled(true);
            ui->E10->setEnabled(true);
            ui->G10->setEnabled(true);
        }}
    if(x==5&&y==10){
        if(x==final.x && y==final.y){
            ui->F11->setEnabled(true);
        }else{
            ui->F10->setEnabled(true);
            ui->F11->setEnabled(true);
            ui->F12->setEnabled(true);
            ui->E11->setEnabled(true);
            ui->G11->setEnabled(true);
        }}
    if(x==5&&y==11){
        if(x==final.x && y==final.y){
            ui->F12->setEnabled(true);
        }else{
            ui->F11->setEnabled(true);
            ui->F12->setEnabled(true);
            ui->F13->setEnabled(true);
            ui->E12->setEnabled(true);
            ui->G12->setEnabled(true);
        }}
    if(x==5&&y==12){
        if(x==final.x && y==final.y){
            ui->F13->setEnabled(true);
        }else{
            ui->F12->setEnabled(true);
            ui->F13->setEnabled(true);
            ui->F14->setEnabled(true);
            ui->E13->setEnabled(true);
            ui->G13->setEnabled(true);
        }}
    if(x==5&&y==13){
        if(x==final.x && y==final.y){
            ui->F14->setEnabled(true);
        }else{
            ui->F13->setEnabled(true);
            ui->F14->setEnabled(true);
            ui->F15->setEnabled(true);
            ui->E14->setEnabled(true);
            ui->G14->setEnabled(true);
        }}
    if(x==5&&y==14){
        if(x==final.x && y==final.y){
            ui->F15->setEnabled(true);
        }else{
            ui->F14->setEnabled(true);
            ui->F15->setEnabled(true);
            ui->E15->setEnabled(true);
            ui->G15->setEnabled(true);
        }}

    //G
    if(x==6&&y==0){
        if(x==final.x && y==final.y){
            ui->G1->setEnabled(true);
        }else{
            ui->G1->setEnabled(true);
            ui->G2->setEnabled(true);
            ui->F1->setEnabled(true);
            ui->H1->setEnabled(true);
        }}
    if(x==6&&y==1){
        if(x==final.x && y==final.y){
            ui->G2->setEnabled(true);
        }else{
            ui->G1->setEnabled(true);
            ui->G2->setEnabled(true);
            ui->G3->setEnabled(true);
            ui->F2->setEnabled(true);
            ui->H2->setEnabled(true);
        }}
    if(x==6&&y==2){
        if(x==final.x && y==final.y){
            ui->G3->setEnabled(true);
        }else{
            ui->G2->setEnabled(true);
            ui->G3->setEnabled(true);
            ui->G4->setEnabled(true);
            ui->F3->setEnabled(true);
            ui->H3->setEnabled(true);
        }}
    if(x==6&&y==3){
        if(x==final.x && y==final.y){
            ui->G4->setEnabled(true);
        }else{
            ui->G3->setEnabled(true);
            ui->G4->setEnabled(true);
            ui->G5->setEnabled(true);
            ui->F4->setEnabled(true);
            ui->H4->setEnabled(true);
        }}
    if(x==6&&y==4){
        if(x==final.x && y==final.y){
            ui->G5->setEnabled(true);
        }else{
            ui->G4->setEnabled(true);
            ui->G5->setEnabled(true);
            ui->G6->setEnabled(true);
            ui->F5->setEnabled(true);
            ui->H5->setEnabled(true);
        }}
    if(x==6&&y==5){
        if(x==final.x && y==final.y){
            ui->G6->setEnabled(true);
        }else{
            ui->G5->setEnabled(true);
            ui->G6->setEnabled(true);
            ui->G7->setEnabled(true);
            ui->F6->setEnabled(true);
            ui->H6->setEnabled(true);
        }}
    if(x==6&&y==6){
        if(x==final.x && y==final.y){
            ui->G7->setEnabled(true);
        }else{
            ui->G6->setEnabled(true);
            ui->G7->setEnabled(true);
            ui->G8->setEnabled(true);
            ui->F7->setEnabled(true);
            ui->H7->setEnabled(true);
        }}
    if(x==6&&y==7){
        if(x==final.x && y==final.y){
            ui->G8->setEnabled(true);
        }else{
            ui->G7->setEnabled(true);
            ui->G8->setEnabled(true);
            ui->G9->setEnabled(true);
            ui->F8->setEnabled(true);
            ui->H8->setEnabled(true);
        }}
    if(x==6&&y==8){
        if(x==final.x && y==final.y){
            ui->G9->setEnabled(true);
        }else{
            ui->G8->setEnabled(true);
            ui->G9->setEnabled(true);
            ui->G10->setEnabled(true);
            ui->F9->setEnabled(true);
            ui->H9->setEnabled(true);
        }}
    if(x==6&&y==9){
        if(x==final.x && y==final.y){
            ui->G10->setEnabled(true);
        }else{
            ui->G9->setEnabled(true);
            ui->G10->setEnabled(true);
            ui->G11->setEnabled(true);
            ui->F10->setEnabled(true);
            ui->H10->setEnabled(true);
        }}
    if(x==6&&y==10){
        if(x==final.x && y==final.y){
            ui->G11->setEnabled(true);
        }else{
            ui->G10->setEnabled(true);
            ui->G11->setEnabled(true);
            ui->G12->setEnabled(true);
            ui->F11->setEnabled(true);
            ui->H11->setEnabled(true);
        }}
    if(x==6&&y==11){
        if(x==final.x && y==final.y){
            ui->G12->setEnabled(true);
        }else{
            ui->G11->setEnabled(true);
            ui->G12->setEnabled(true);
            ui->G13->setEnabled(true);
            ui->F12->setEnabled(true);
            ui->H12->setEnabled(true);
        }}
    if(x==6&&y==12){
        if(x==final.x && y==final.y){
            ui->G13->setEnabled(true);
        }else{
            ui->G12->setEnabled(true);
            ui->G13->setEnabled(true);
            ui->G14->setEnabled(true);
            ui->F13->setEnabled(true);
            ui->H13->setEnabled(true);
        }}
    if(x==6&&y==13){
        if(x==final.x && y==final.y){
            ui->G14->setEnabled(true);
        }else{
            ui->G13->setEnabled(true);
            ui->G14->setEnabled(true);
            ui->G15->setEnabled(true);
            ui->F14->setEnabled(true);
            ui->H14->setEnabled(true);
        }}
    if(x==6&&y==14){
        if(x==final.x && y==final.y){
            ui->G15->setEnabled(true);
        }else{
            ui->G14->setEnabled(true);
            ui->G15->setEnabled(true);
            ui->F15->setEnabled(true);
            ui->H15->setEnabled(true);
        }}
    //H
    if(x==7&&y==0){
        if(x==final.x && y==final.y){
            ui->H1->setEnabled(true);
        }else{
            ui->H1->setEnabled(true);
            ui->H2->setEnabled(true);
            ui->G1->setEnabled(true);
            ui->I1->setEnabled(true);
        }}
    if(x==7&&y==1){
        if(x==final.x && y==final.y){
            ui->H2->setEnabled(true);
        }else{
            ui->H1->setEnabled(true);
            ui->H2->setEnabled(true);
            ui->H3->setEnabled(true);
            ui->G2->setEnabled(true);
            ui->I2->setEnabled(true);
        }}
    if(x==7&&y==2){
        if(x==final.x && y==final.y){
            ui->H3->setEnabled(true);
        }else{
            ui->H2->setEnabled(true);
            ui->H3->setEnabled(true);
            ui->H4->setEnabled(true);
            ui->G3->setEnabled(true);
            ui->I3->setEnabled(true);
        }}
    if(x==7&&y==3){
        if(x==final.x && y==final.y){
            ui->H4->setEnabled(true);
        }else{
            ui->H3->setEnabled(true);
            ui->H4->setEnabled(true);
            ui->H5->setEnabled(true);
            ui->G4->setEnabled(true);
            ui->I4->setEnabled(true);
        }}
    if(x==7&&y==4){
        if(x==final.x && y==final.y){
            ui->H5->setEnabled(true);
        }else{
            ui->H4->setEnabled(true);
            ui->H5->setEnabled(true);
            ui->H6->setEnabled(true);
            ui->G5->setEnabled(true);
            ui->I5->setEnabled(true);
        }}
    if(x==7&&y==5){
        if(x==final.x && y==final.y){
            ui->H6->setEnabled(true);
        }else{
            ui->H5->setEnabled(true);
            ui->H6->setEnabled(true);
            ui->H7->setEnabled(true);
            ui->G6->setEnabled(true);
            ui->I6->setEnabled(true);
        }}
    if(x==7&&y==6){
        if(x==final.x && y==final.y){
            ui->H7->setEnabled(true);
        }else{
            ui->H6->setEnabled(true);
            ui->H7->setEnabled(true);
            ui->H8->setEnabled(true);
            ui->G7->setEnabled(true);
            ui->I7->setEnabled(true);
        }}
    if(x==7&&y==7){
        if(x==final.x && y==final.y){
            ui->H8->setEnabled(true);
        }else{
            ui->H7->setEnabled(true);
            ui->H8->setEnabled(true);
            ui->H9->setEnabled(true);
            ui->G8->setEnabled(true);
            ui->I8->setEnabled(true);
        }}
    if(x==7&&y==8){
        if(x==final.x && y==final.y){
            ui->H9->setEnabled(true);
        }else{
            ui->H8->setEnabled(true);
            ui->H9->setEnabled(true);
            ui->H10->setEnabled(true);
            ui->G9->setEnabled(true);
            ui->I9->setEnabled(true);
        }}
    if(x==7&&y==9){
        if(x==final.x && y==final.y){
            ui->H10->setEnabled(true);
        }else{
            ui->H9->setEnabled(true);
            ui->H10->setEnabled(true);
            ui->H11->setEnabled(true);
            ui->G10->setEnabled(true);
            ui->I10->setEnabled(true);
        }}
    if(x==7&&y==10){
        if(x==final.x && y==final.y){
            ui->H11->setEnabled(true);
        }else{
            ui->H10->setEnabled(true);
            ui->H11->setEnabled(true);
            ui->H12->setEnabled(true);
            ui->G11->setEnabled(true);
            ui->I11->setEnabled(true);
        }}
    if(x==7&&y==11){
        if(x==final.x && y==final.y){
            ui->H12->setEnabled(true);
        }else{
            ui->H11->setEnabled(true);
            ui->H12->setEnabled(true);
            ui->H13->setEnabled(true);
            ui->G12->setEnabled(true);
            ui->I12->setEnabled(true);
        }}
    if(x==7&&y==12){
        if(x==final.x && y==final.y){
            ui->H13->setEnabled(true);
        }else{
            ui->H12->setEnabled(true);
            ui->H13->setEnabled(true);
            ui->H14->setEnabled(true);
            ui->G13->setEnabled(true);
            ui->I13->setEnabled(true);
        }}
    if(x==7&&y==13){
        if(x==final.x && y==final.y){
            ui->H14->setEnabled(true);
        }else{
            ui->H13->setEnabled(true);
            ui->H14->setEnabled(true);
            ui->H15->setEnabled(true);
            ui->G14->setEnabled(true);
            ui->I14->setEnabled(true);
        }}
    if(x==7&&y==14){
        if(x==final.x && y==final.y){
            ui->H15->setEnabled(true);
        }else{
            ui->H14->setEnabled(true);
            ui->H15->setEnabled(true);
            ui->G15->setEnabled(true);
            ui->I15->setEnabled(true);
        }}
    //I
    if(x==8&&y==0){
        if(x==final.x && y==final.y){
            ui->I1->setEnabled(true);
        }else{
            ui->I1->setEnabled(true);
            ui->I2->setEnabled(true);
            ui->H1->setEnabled(true);
            ui->J1->setEnabled(true);
        }}
    if(x==8&&y==1){
        if(x==final.x && y==final.y){
            ui->I2->setEnabled(true);
        }else{
            ui->I1->setEnabled(true);
            ui->I2->setEnabled(true);
            ui->I3->setEnabled(true);
            ui->H2->setEnabled(true);
            ui->J2->setEnabled(true);
        }}
    if(x==8&&y==2){
        if(x==final.x && y==final.y){
            ui->I3->setEnabled(true);
        }else{
            ui->I2->setEnabled(true);
            ui->I3->setEnabled(true);
            ui->I4->setEnabled(true);
            ui->H3->setEnabled(true);
            ui->J3->setEnabled(true);
        }}
    if(x==8&&y==3){
        if(x==final.x && y==final.y){
            ui->I4->setEnabled(true);
        }else{
            ui->I3->setEnabled(true);
            ui->I4->setEnabled(true);
            ui->I5->setEnabled(true);
            ui->H4->setEnabled(true);
            ui->J4->setEnabled(true);
        }}
    if(x==8&&y==4){
        if(x==final.x && y==final.y){
            ui->I5->setEnabled(true);
        }else{
            ui->I4->setEnabled(true);
            ui->I5->setEnabled(true);
            ui->I6->setEnabled(true);
            ui->H5->setEnabled(true);
            ui->J5->setEnabled(true);
        }}
    if(x==8&&y==5){
        if(x==final.x && y==final.y){
            ui->I6->setEnabled(true);
        }else{
            ui->I5->setEnabled(true);
            ui->I6->setEnabled(true);
            ui->I7->setEnabled(true);
            ui->H6->setEnabled(true);
            ui->J6->setEnabled(true);
        }}
    if(x==8&&y==6){
        if(x==final.x && y==final.y){
            ui->I7->setEnabled(true);
        }else{
            ui->I6->setEnabled(true);
            ui->I7->setEnabled(true);
            ui->I8->setEnabled(true);
            ui->H7->setEnabled(true);
            ui->J7->setEnabled(true);
        }}
    if(x==8&&y==7){
        if(x==final.x && y==final.y){
            ui->I8->setEnabled(true);
        }else{
            ui->I7->setEnabled(true);
            ui->I8->setEnabled(true);
            ui->I9->setEnabled(true);
            ui->H8->setEnabled(true);
            ui->J8->setEnabled(true);
        }}
    if(x==8&&y==8){
        if(x==final.x && y==final.y){
            ui->I9->setEnabled(true);
        }else{
            ui->I8->setEnabled(true);
            ui->I9->setEnabled(true);
            ui->I10->setEnabled(true);
            ui->H9->setEnabled(true);
            ui->J9->setEnabled(true);
        }}
    if(x==8&&y==9){
        if(x==final.x && y==final.y){
            ui->I10->setEnabled(true);
        }else{
            ui->I9->setEnabled(true);
            ui->I10->setEnabled(true);
            ui->I11->setEnabled(true);
            ui->H10->setEnabled(true);
            ui->J10->setEnabled(true);
        }}
    if(x==8&&y==10){
        if(x==final.x && y==final.y){
            ui->I11->setEnabled(true);
        }else{
            ui->I10->setEnabled(true);
            ui->I11->setEnabled(true);
            ui->I12->setEnabled(true);
            ui->H11->setEnabled(true);
            ui->J11->setEnabled(true);
        }}
    if(x==8&&y==11){
        if(x==final.x && y==final.y){
            ui->I12->setEnabled(true);
        }else{
            ui->I11->setEnabled(true);
            ui->I12->setEnabled(true);
            ui->I13->setEnabled(true);
            ui->H12->setEnabled(true);
            ui->J12->setEnabled(true);
        }}
    if(x==8&&y==12){
        if(x==final.x && y==final.y){
            ui->I13->setEnabled(true);
        }else{
            ui->I12->setEnabled(true);
            ui->I13->setEnabled(true);
            ui->I14->setEnabled(true);
            ui->H13->setEnabled(true);
            ui->J13->setEnabled(true);
        }}
    if(x==8&&y==13){
        if(x==final.x && y==final.y){
            ui->I14->setEnabled(true);
        }else{
            ui->I13->setEnabled(true);
            ui->I14->setEnabled(true);
            ui->I15->setEnabled(true);
            ui->H14->setEnabled(true);
            ui->J14->setEnabled(true);
        }}
    if(x==8&&y==14){
        if(x==final.x && y==final.y){
            ui->I15->setEnabled(true);
        }else{
            ui->I14->setEnabled(true);
            ui->I15->setEnabled(true);
            ui->H15->setEnabled(true);
            ui->J15->setEnabled(true);
        }}

    //J
    if(x==9&&y==0){
        if(x==final.x && y==final.y){
            ui->J1->setEnabled(true);
        }else{
            ui->J1->setEnabled(true);
            ui->J2->setEnabled(true);
            ui->I1->setEnabled(true);
            ui->K1->setEnabled(true);
        }}
    if(x==9&&y==1){
        if(x==final.x && y==final.y){
            ui->J2->setEnabled(true);
        }else{
            ui->J1->setEnabled(true);
            ui->J2->setEnabled(true);
            ui->J3->setEnabled(true);
            ui->I2->setEnabled(true);
            ui->K2->setEnabled(true);
        }}
    if(x==9&&y==2){
        if(x==final.x && y==final.y){
            ui->J3->setEnabled(true);
        }else{
            ui->J2->setEnabled(true);
            ui->J3->setEnabled(true);
            ui->J4->setEnabled(true);
            ui->I3->setEnabled(true);
            ui->K3->setEnabled(true);
        }}
    if(x==9&&y==3){
        if(x==final.x && y==final.y){
            ui->J4->setEnabled(true);
        }else{
            ui->J3->setEnabled(true);
            ui->J4->setEnabled(true);
            ui->J5->setEnabled(true);
            ui->I4->setEnabled(true);
            ui->K4->setEnabled(true);
        }}
    if(x==9&&y==4){
        if(x==final.x && y==final.y){
            ui->J5->setEnabled(true);
        }else{
            ui->J4->setEnabled(true);
            ui->J5->setEnabled(true);
            ui->J6->setEnabled(true);
            ui->I5->setEnabled(true);
            ui->K5->setEnabled(true);
        }}
    if(x==9&&y==5){
        if(x==final.x && y==final.y){
            ui->J6->setEnabled(true);
        }else{
            ui->J5->setEnabled(true);
            ui->J6->setEnabled(true);
            ui->J7->setEnabled(true);
            ui->I6->setEnabled(true);
            ui->K6->setEnabled(true);
        }}
    if(x==9&&y==6){
        if(x==final.x && y==final.y){
            ui->J7->setEnabled(true);
        }else{
            ui->J6->setEnabled(true);
            ui->J7->setEnabled(true);
            ui->J8->setEnabled(true);
            ui->I7->setEnabled(true);
            ui->K7->setEnabled(true);
        }}
    if(x==9&&y==7){
        if(x==final.x && y==final.y){
            ui->J8->setEnabled(true);
        }else{
            ui->J7->setEnabled(true);
            ui->J8->setEnabled(true);
            ui->J9->setEnabled(true);
            ui->I8->setEnabled(true);
            ui->K8->setEnabled(true);
        }}
    if(x==9&&y==8){
        if(x==final.x && y==final.y){
            ui->J9->setEnabled(true);
        }else{
            ui->J8->setEnabled(true);
            ui->J9->setEnabled(true);
            ui->J10->setEnabled(true);
            ui->I9->setEnabled(true);
            ui->K9->setEnabled(true);
        }}
    if(x==9&&y==9){
        if(x==final.x && y==final.y){
            ui->J10->setEnabled(true);
        }else{
            ui->J9->setEnabled(true);
            ui->J10->setEnabled(true);
            ui->J11->setEnabled(true);
            ui->I10->setEnabled(true);
            ui->K10->setEnabled(true);
        }}
    if(x==9&&y==10){
        if(x==final.x && y==final.y){
            ui->J11->setEnabled(true);
        }else{
            ui->J10->setEnabled(true);
            ui->J11->setEnabled(true);
            ui->J12->setEnabled(true);
            ui->I11->setEnabled(true);
            ui->K11->setEnabled(true);
        }}
    if(x==9&&y==11){
        if(x==final.x && y==final.y){
            ui->J12->setEnabled(true);
        }else{
            ui->J11->setEnabled(true);
            ui->J12->setEnabled(true);
            ui->J13->setEnabled(true);
            ui->I12->setEnabled(true);
            ui->K12->setEnabled(true);
        }}
    if(x==9&&y==12){
        if(x==final.x && y==final.y){
            ui->J13->setEnabled(true);
        }else{
            ui->J12->setEnabled(true);
            ui->J13->setEnabled(true);
            ui->J14->setEnabled(true);
            ui->I13->setEnabled(true);
            ui->K13->setEnabled(true);
        }}
    if(x==9&&y==13){
        if(x==final.x && y==final.y){
            ui->J14->setEnabled(true);
        }else{
            ui->J13->setEnabled(true);
            ui->J14->setEnabled(true);
            ui->J15->setEnabled(true);
            ui->I14->setEnabled(true);
            ui->K14->setEnabled(true);
        }}
    if(x==9&&y==14){
        if(x==final.x && y==final.y){
            ui->J15->setEnabled(true);
        }else{
            ui->J14->setEnabled(true);
            ui->J15->setEnabled(true);
            ui->I15->setEnabled(true);
            ui->K15->setEnabled(true);
        }}

    //K
    if(x==10&&y==0){
        if(x==final.x && y==final.y){
            ui->K1->setEnabled(true);
        }else{
            ui->K1->setEnabled(true);
            ui->K2->setEnabled(true);
            ui->J1->setEnabled(true);
            ui->L1->setEnabled(true);
        }}
    if(x==10&&y==1){
        if(x==final.x && y==final.y){
            ui->K2->setEnabled(true);
        }else{
            ui->K1->setEnabled(true);
            ui->K2->setEnabled(true);
            ui->K3->setEnabled(true);
            ui->J2->setEnabled(true);
            ui->L2->setEnabled(true);
        }}
    if(x==10&&y==2){
        if(x==final.x && y==final.y){
            ui->K3->setEnabled(true);
        }else{
            ui->K2->setEnabled(true);
            ui->K3->setEnabled(true);
            ui->K4->setEnabled(true);
            ui->J3->setEnabled(true);
            ui->L3->setEnabled(true);
        }}
    if(x==10&&y==3){
        if(x==final.x && y==final.y){
            ui->K4->setEnabled(true);
        }else{
            ui->K3->setEnabled(true);
            ui->K4->setEnabled(true);
            ui->K5->setEnabled(true);
            ui->J4->setEnabled(true);
            ui->L4->setEnabled(true);
        }}
    if(x==10&&y==4){
        if(x==final.x && y==final.y){
            ui->K5->setEnabled(true);
        }else{
            ui->K4->setEnabled(true);
            ui->K5->setEnabled(true);
            ui->K6->setEnabled(true);
            ui->J5->setEnabled(true);
            ui->L5->setEnabled(true);
        }}
    if(x==10&&y==5){
        if(x==final.x && y==final.y){
            ui->K6->setEnabled(true);
        }else{
            ui->K5->setEnabled(true);
            ui->K6->setEnabled(true);
            ui->K7->setEnabled(true);
            ui->J6->setEnabled(true);
            ui->L6->setEnabled(true);
        }}
    if(x==10&&y==6){
        if(x==final.x && y==final.y){
            ui->K7->setEnabled(true);
        }else{
            ui->K6->setEnabled(true);
            ui->K7->setEnabled(true);
            ui->K8->setEnabled(true);
            ui->J7->setEnabled(true);
            ui->L7->setEnabled(true);
        }}
    if(x==10&&y==7){
        if(x==final.x && y==final.y){
            ui->K8->setEnabled(true);
        }else{
            ui->K7->setEnabled(true);
            ui->K8->setEnabled(true);
            ui->K9->setEnabled(true);
            ui->J8->setEnabled(true);
            ui->L8->setEnabled(true);
        }}
    if(x==10&&y==8){
        if(x==final.x && y==final.y){
            ui->K9->setEnabled(true);
        }else{
            ui->K8->setEnabled(true);
            ui->K9->setEnabled(true);
            ui->K10->setEnabled(true);
            ui->J9->setEnabled(true);
            ui->L9->setEnabled(true);
        }}
    if(x==10&&y==9){
        if(x==final.x && y==final.y){
            ui->K10->setEnabled(true);
        }else{
            ui->K9->setEnabled(true);
            ui->K10->setEnabled(true);
            ui->K11->setEnabled(true);
            ui->J10->setEnabled(true);
            ui->L10->setEnabled(true);
        }}
    if(x==10&&y==10){
        if(x==final.x && y==final.y){
            ui->K11->setEnabled(true);
        }else{
            ui->K10->setEnabled(true);
            ui->K11->setEnabled(true);
            ui->K12->setEnabled(true);
            ui->J11->setEnabled(true);
            ui->L11->setEnabled(true);
        }}
    if(x==10&&y==11){
        if(x==final.x && y==final.y){
            ui->K12->setEnabled(true);
        }else{
            ui->K11->setEnabled(true);
            ui->K12->setEnabled(true);
            ui->K13->setEnabled(true);
            ui->J12->setEnabled(true);
            ui->L12->setEnabled(true);
        }}
    if(x==10&&y==12){
        if(x==final.x && y==final.y){
            ui->K13->setEnabled(true);
        }else{
            ui->K12->setEnabled(true);
            ui->K13->setEnabled(true);
            ui->K14->setEnabled(true);
            ui->J13->setEnabled(true);
            ui->L13->setEnabled(true);
        }}
    if(x==10&&y==13){
        if(x==final.x && y==final.y){
            ui->K14->setEnabled(true);
        }else{
            ui->K13->setEnabled(true);
            ui->K14->setEnabled(true);
            ui->K15->setEnabled(true);
            ui->J14->setEnabled(true);
            ui->L14->setEnabled(true);
        }}
    if(x==10&&y==14){
        if(x==final.x && y==final.y){
            ui->K15->setEnabled(true);
        }else{
            ui->K14->setEnabled(true);
            ui->K15->setEnabled(true);
            ui->J15->setEnabled(true);
            ui->L15->setEnabled(true);
        }}
    //L
    if(x==11&&y==0){
        if(x==final.x && y==final.y){
            ui->L1->setEnabled(true);
        }else{
            ui->L1->setEnabled(true);
            ui->L2->setEnabled(true);
            ui->K1->setEnabled(true);
            ui->M1->setEnabled(true);
        }}
    if(x==11&&y==1){
        if(x==final.x && y==final.y){
            ui->L2->setEnabled(true);
        }else{
            ui->L1->setEnabled(true);
            ui->L2->setEnabled(true);
            ui->L3->setEnabled(true);
            ui->K2->setEnabled(true);
            ui->M2->setEnabled(true);
        }}
    if(x==11&&y==2){
        if(x==final.x && y==final.y){
            ui->L3->setEnabled(true);
        }else{
            ui->L2->setEnabled(true);
            ui->L3->setEnabled(true);
            ui->L4->setEnabled(true);
            ui->K3->setEnabled(true);
            ui->M3->setEnabled(true);
        }}
    if(x==11&&y==3){
        if(x==final.x && y==final.y){
            ui->L4->setEnabled(true);
        }else{
            ui->L3->setEnabled(true);
            ui->L4->setEnabled(true);
            ui->L5->setEnabled(true);
            ui->K4->setEnabled(true);
            ui->M4->setEnabled(true);
        }}
    if(x==11&&y==4){
        if(x==final.x && y==final.y){
            ui->L5->setEnabled(true);
        }else{
            ui->L4->setEnabled(true);
            ui->L5->setEnabled(true);
            ui->L6->setEnabled(true);
            ui->K5->setEnabled(true);
            ui->M5->setEnabled(true);
        }}
    if(x==11&&y==5){
        if(x==final.x && y==final.y){
            ui->L6->setEnabled(true);
        }else{
            ui->L5->setEnabled(true);
            ui->L6->setEnabled(true);
            ui->L7->setEnabled(true);
            ui->K6->setEnabled(true);
            ui->M6->setEnabled(true);
        }}
    if(x==11&&y==6){
        if(x==final.x && y==final.y){
            ui->L7->setEnabled(true);
        }else{
            ui->L6->setEnabled(true);
            ui->L7->setEnabled(true);
            ui->L8->setEnabled(true);
            ui->K7->setEnabled(true);
            ui->M7->setEnabled(true);
        }}
    if(x==11&&y==7){
        if(x==final.x && y==final.y){
            ui->L8->setEnabled(true);
        }else{
            ui->L7->setEnabled(true);
            ui->L8->setEnabled(true);
            ui->L9->setEnabled(true);
            ui->K8->setEnabled(true);
            ui->M8->setEnabled(true);
        }}
    if(x==11&&y==8){
        if(x==final.x && y==final.y){
            ui->L9->setEnabled(true);
        }else{
            ui->L8->setEnabled(true);
            ui->L9->setEnabled(true);
            ui->L10->setEnabled(true);
            ui->K9->setEnabled(true);
            ui->M9->setEnabled(true);
        }}
    if(x==11&&y==9){
        if(x==final.x && y==final.y){
            ui->L10->setEnabled(true);
        }else{
            ui->L9->setEnabled(true);
            ui->L10->setEnabled(true);
            ui->L11->setEnabled(true);
            ui->K10->setEnabled(true);
            ui->M10->setEnabled(true);
        }}
    if(x==11&&y==10){
        if(x==final.x && y==final.y){
            ui->L11->setEnabled(true);
        }else{
            ui->L10->setEnabled(true);
            ui->L11->setEnabled(true);
            ui->L12->setEnabled(true);
            ui->K11->setEnabled(true);
            ui->M11->setEnabled(true);
        }}
    if(x==11&&y==11){
        if(x==final.x && y==final.y){
            ui->L12->setEnabled(true);
        }else{
            ui->L11->setEnabled(true);
            ui->L12->setEnabled(true);
            ui->L13->setEnabled(true);
            ui->K12->setEnabled(true);
            ui->M12->setEnabled(true);
        }}
    if(x==11&&y==12){
        if(x==final.x && y==final.y){
            ui->L13->setEnabled(true);
        }else{
            ui->L12->setEnabled(true);
            ui->L13->setEnabled(true);
            ui->L14->setEnabled(true);
            ui->K13->setEnabled(true);
            ui->M13->setEnabled(true);
        }}
    if(x==11&&y==13){
        if(x==final.x && y==final.y){
            ui->L14->setEnabled(true);
        }else{
            ui->L13->setEnabled(true);
            ui->L14->setEnabled(true);
            ui->L15->setEnabled(true);
            ui->K14->setEnabled(true);
            ui->M14->setEnabled(true);
        }}
    if(x==11&&y==14){
        if(x==final.x && y==final.y){
            ui->L15->setEnabled(true);
        }else{
            ui->L14->setEnabled(true);
            ui->L15->setEnabled(true);
            ui->K15->setEnabled(true);
            ui->M15->setEnabled(true);
        }}

    //M
    if(x==12&&y==0){
        if(x==final.x && y==final.y){
            ui->M1->setEnabled(true);
        }else{
            ui->M1->setEnabled(true);
            ui->M2->setEnabled(true);
            ui->L1->setEnabled(true);
            ui->N1->setEnabled(true);
        }}
    if(x==12&&y==1){
        if(x==final.x && y==final.y){
            ui->M2->setEnabled(true);
        }else{
            ui->M1->setEnabled(true);
            ui->M2->setEnabled(true);
            ui->M3->setEnabled(true);
            ui->L2->setEnabled(true);
            ui->N2->setEnabled(true);
        }}
    if(x==12&&y==2){
        if(x==final.x && y==final.y){
            ui->M3->setEnabled(true);
        }else{
            ui->M2->setEnabled(true);
            ui->M3->setEnabled(true);
            ui->M4->setEnabled(true);
            ui->L3->setEnabled(true);
            ui->N3->setEnabled(true);
        }}
    if(x==12&&y==3){
        if(x==final.x && y==final.y){
            ui->M4->setEnabled(true);
        }else{
            ui->M3->setEnabled(true);
            ui->M4->setEnabled(true);
            ui->M5->setEnabled(true);
            ui->L4->setEnabled(true);
            ui->N4->setEnabled(true);
        }}
    if(x==12&&y==4){
        if(x==final.x && y==final.y){
            ui->M5->setEnabled(true);
        }else{
            ui->M4->setEnabled(true);
            ui->M5->setEnabled(true);
            ui->M6->setEnabled(true);
            ui->L5->setEnabled(true);
            ui->N5->setEnabled(true);
        }}
    if(x==12&&y==5){
        if(x==final.x && y==final.y){
            ui->M6->setEnabled(true);
        }else{
            ui->M5->setEnabled(true);
            ui->M6->setEnabled(true);
            ui->M7->setEnabled(true);
            ui->L6->setEnabled(true);
            ui->N6->setEnabled(true);
        }}
    if(x==12&&y==6){
        if(x==final.x && y==final.y){
            ui->M7->setEnabled(true);
        }else{
            ui->M6->setEnabled(true);
            ui->M7->setEnabled(true);
            ui->M8->setEnabled(true);
            ui->L7->setEnabled(true);
            ui->N7->setEnabled(true);
        }}
    if(x==12&&y==7){
        if(x==final.x && y==final.y){
            ui->M8->setEnabled(true);
        }else{
            ui->M7->setEnabled(true);
            ui->M8->setEnabled(true);
            ui->M9->setEnabled(true);
            ui->L8->setEnabled(true);
            ui->N8->setEnabled(true);
        }}
    if(x==12&&y==8){
        if(x==final.x && y==final.y){
            ui->M9->setEnabled(true);
        }else{
            ui->M8->setEnabled(true);
            ui->M9->setEnabled(true);
            ui->M10->setEnabled(true);
            ui->L9->setEnabled(true);
            ui->N9->setEnabled(true);
        }}
    if(x==12&&y==9){
        if(x==final.x && y==final.y){
            ui->M10->setEnabled(true);
        }else{
            ui->M9->setEnabled(true);
            ui->M10->setEnabled(true);
            ui->M11->setEnabled(true);
            ui->L10->setEnabled(true);
            ui->N10->setEnabled(true);
        }}
    if(x==12&&y==10){
        if(x==final.x && y==final.y){
            ui->M11->setEnabled(true);
        }else{
            ui->M10->setEnabled(true);
            ui->M11->setEnabled(true);
            ui->M12->setEnabled(true);
            ui->L11->setEnabled(true);
            ui->N11->setEnabled(true);
        }}
    if(x==12&&y==11){
        if(x==final.x && y==final.y){
            ui->M12->setEnabled(true);
        }else{
            ui->M11->setEnabled(true);
            ui->M12->setEnabled(true);
            ui->M13->setEnabled(true);
            ui->L12->setEnabled(true);
            ui->N12->setEnabled(true);
        }}
    if(x==12&&y==12){
        if(x==final.x && y==final.y){
            ui->M13->setEnabled(true);
        }else{
            ui->M12->setEnabled(true);
            ui->M13->setEnabled(true);
            ui->M14->setEnabled(true);
            ui->L13->setEnabled(true);
            ui->N13->setEnabled(true);
        }}
    if(x==12&&y==13){
        if(x==final.x && y==final.y){
            ui->M14->setEnabled(true);
        }else{
            ui->M13->setEnabled(true);
            ui->M14->setEnabled(true);
            ui->M15->setEnabled(true);
            ui->L14->setEnabled(true);
            ui->N14->setEnabled(true);
        }}
    if(x==12&&y==14){
        if(x==final.x && y==final.y){
            ui->M15->setEnabled(true);
        }else{
            ui->M14->setEnabled(true);
            ui->M15->setEnabled(true);
            ui->L15->setEnabled(true);
            ui->N15->setEnabled(true);
        }}
    //N
    if(x==13&&y==0){
        if(x==final.x && y==final.y){
            ui->N1->setEnabled(true);
        }else{
            ui->N1->setEnabled(true);
            ui->N2->setEnabled(true);
            ui->M1->setEnabled(true);
            ui->O1->setEnabled(true);
        }}
    if(x==13&&y==1){
        if(x==final.x && y==final.y){
            ui->N2->setEnabled(true);
        }else{
            ui->N1->setEnabled(true);
            ui->N2->setEnabled(true);
            ui->N3->setEnabled(true);
            ui->M2->setEnabled(true);
            ui->O2->setEnabled(true);
        }}
    if(x==13&&y==2){
        if(x==final.x && y==final.y){
            ui->N3->setEnabled(true);
        }else{
            ui->N2->setEnabled(true);
            ui->N3->setEnabled(true);
            ui->N4->setEnabled(true);
            ui->M3->setEnabled(true);
            ui->O3->setEnabled(true);
        }}
    if(x==13&&y==3){
        if(x==final.x && y==final.y){
            ui->N4->setEnabled(true);
        }else{
            ui->N3->setEnabled(true);
            ui->N4->setEnabled(true);
            ui->N5->setEnabled(true);
            ui->M4->setEnabled(true);
            ui->O4->setEnabled(true);
        }}
    if(x==13&&y==4){
        if(x==final.x && y==final.y){
            ui->N5->setEnabled(true);
        }else{
            ui->N4->setEnabled(true);
            ui->N5->setEnabled(true);
            ui->N6->setEnabled(true);
            ui->M5->setEnabled(true);
            ui->O5->setEnabled(true);
        }}
    if(x==13&&y==5){
        if(x==final.x && y==final.y){
            ui->N6->setEnabled(true);
        }else{
            ui->N5->setEnabled(true);
            ui->N6->setEnabled(true);
            ui->N7->setEnabled(true);
            ui->M6->setEnabled(true);
            ui->O6->setEnabled(true);
        }}
    if(x==13&&y==6){
        if(x==final.x && y==final.y){
            ui->N7->setEnabled(true);
        }else{
            ui->N6->setEnabled(true);
            ui->N7->setEnabled(true);
            ui->N8->setEnabled(true);
            ui->M7->setEnabled(true);
            ui->O7->setEnabled(true);
        }}
    if(x==13&&y==7){
        if(x==final.x && y==final.y){
            ui->N8->setEnabled(true);
        }else{
            ui->N7->setEnabled(true);
            ui->N8->setEnabled(true);
            ui->N9->setEnabled(true);
            ui->M8->setEnabled(true);
            ui->O8->setEnabled(true);
        }}
    if(x==13&&y==8){
        if(x==final.x && y==final.y){
            ui->N9->setEnabled(true);
        }else{
            ui->N8->setEnabled(true);
            ui->N9->setEnabled(true);
            ui->N10->setEnabled(true);
            ui->M9->setEnabled(true);
            ui->O9->setEnabled(true);
        }}
    if(x==13&&y==9){
        if(x==final.x && y==final.y){
            ui->N10->setEnabled(true);
        }else{
            ui->N9->setEnabled(true);
            ui->N10->setEnabled(true);
            ui->N11->setEnabled(true);
            ui->M10->setEnabled(true);
            ui->O10->setEnabled(true);
        }}
    if(x==13&&y==10){
        if(x==final.x && y==final.y){
            ui->N11->setEnabled(true);
        }else{
            ui->N10->setEnabled(true);
            ui->N11->setEnabled(true);
            ui->N12->setEnabled(true);
            ui->M11->setEnabled(true);
            ui->O11->setEnabled(true);
        }}
    if(x==13&&y==11){
        if(x==final.x && y==final.y){
            ui->N12->setEnabled(true);
        }else{
            ui->N11->setEnabled(true);
            ui->N12->setEnabled(true);
            ui->N13->setEnabled(true);
            ui->M12->setEnabled(true);
            ui->O12->setEnabled(true);
        }}
    if(x==13&&y==12){
        if(x==final.x && y==final.y){
            ui->N13->setEnabled(true);
        }else{
            ui->N12->setEnabled(true);
            ui->N13->setEnabled(true);
            ui->N14->setEnabled(true);
            ui->M13->setEnabled(true);
            ui->O13->setEnabled(true);
        }}
    if(x==13&&y==13){
        if(x==final.x && y==final.y){
            ui->N14->setEnabled(true);
        }else{
            ui->N13->setEnabled(true);
            ui->N14->setEnabled(true);
            ui->N15->setEnabled(true);
            ui->M14->setEnabled(true);
            ui->O14->setEnabled(true);
        }}
    if(x==13&&y==14){
        if(x==final.x && y==final.y){
            ui->N15->setEnabled(true);
        }else{
            ui->N14->setEnabled(true);
            ui->N15->setEnabled(true);
            ui->M15->setEnabled(true);
            ui->O15->setEnabled(true);
        }}

    if(x==14&&y==0){
        if(x==final.x && y==final.y){
            ui->O1->setEnabled(true);
        }else{
            ui->O1->setEnabled(true);
            ui->O2->setEnabled(true);
            ui->N1->setEnabled(true);
        }}
    if(x==14&&y==1){
        if(x==final.x && y==final.y){
            ui->O2->setEnabled(true);
        }else{
            ui->O1->setEnabled(true);
            ui->O2->setEnabled(true);
            ui->O3->setEnabled(true);
            ui->N2->setEnabled(true);
        }}
    if(x==14&&y==2){
        if(x==final.x && y==final.y){
            ui->O3->setEnabled(true);
        }else{
            ui->O2->setEnabled(true);
            ui->O3->setEnabled(true);
            ui->O4->setEnabled(true);
            ui->N3->setEnabled(true);
        }}
    if(x==14&&y==3){
        if(x==final.x && y==final.y){
            ui->O4->setEnabled(true);
        }else{
            ui->O3->setEnabled(true);
            ui->O4->setEnabled(true);
            ui->O5->setEnabled(true);
            ui->N4->setEnabled(true);
        }}
    if(x==14&&y==4){
        if(x==final.x && y==final.y){
            ui->O5->setEnabled(true);
        }else{
            ui->O4->setEnabled(true);
            ui->O5->setEnabled(true);
            ui->O6->setEnabled(true);
            ui->N5->setEnabled(true);
        }}
    if(x==14&&y==5){
        if(x==final.x && y==final.y){
            ui->O6->setEnabled(true);
        }else{
            ui->O5->setEnabled(true);
            ui->O6->setEnabled(true);
            ui->O7->setEnabled(true);
            ui->N6->setEnabled(true);
        }}
    if(x==14&&y==6){
        if(x==final.x && y==final.y){
            ui->O7->setEnabled(true);
        }else{
            ui->O6->setEnabled(true);
            ui->O7->setEnabled(true);
            ui->O8->setEnabled(true);
            ui->N7->setEnabled(true);
        }}
    if(x==14&&y==7){
        if(x==final.x && y==final.y){
            ui->O8->setEnabled(true);
        }else{
            ui->O7->setEnabled(true);
            ui->O8->setEnabled(true);
            ui->O9->setEnabled(true);
            ui->N8->setEnabled(true);
        }}
    if(x==14&&y==8){
        if(x==final.x && y==final.y){
            ui->O9->setEnabled(true);
        }else{
            ui->O8->setEnabled(true);
            ui->O9->setEnabled(true);
            ui->O10->setEnabled(true);
            ui->N9->setEnabled(true);
        }}
    if(x==14&&y==9){
        if(x==final.x && y==final.y){
            ui->O10->setEnabled(true);
        }else{
            ui->O9->setEnabled(true);
            ui->O10->setEnabled(true);
            ui->O11->setEnabled(true);
            ui->N10->setEnabled(true);
        }}
    if(x==14&&y==10){
        if(x==final.x && y==final.y){
            ui->O11->setEnabled(true);
        }else{
            ui->O10->setEnabled(true);
            ui->O11->setEnabled(true);
            ui->O12->setEnabled(true);
            ui->N11->setEnabled(true);
        }}
    if(x==14&&y==11){
        if(x==final.x && y==final.y){
            ui->O12->setEnabled(true);
        }else{
            ui->O11->setEnabled(true);
            ui->O12->setEnabled(true);
            ui->O13->setEnabled(true);
            ui->N12->setEnabled(true);
        }}
    if(x==14&&y==12){
        if(x==final.x && y==final.y){
            ui->O13->setEnabled(true);
        }else{
            ui->O12->setEnabled(true);
            ui->O13->setEnabled(true);
            ui->O14->setEnabled(true);
            ui->N13->setEnabled(true);
        }}
    if(x==14&&y==13){
        if(x==final.x && y==final.y){
            ui->O14->setEnabled(true);
        }else{
            ui->O13->setEnabled(true);
            ui->O14->setEnabled(true);
            ui->O15->setEnabled(true);
            ui->N14->setEnabled(true);
        }}
    if(x==14&&y==14){
        if(x==final.x && y==final.y){
            ui->O15->setEnabled(true);
        }else{

            ui->O14->setEnabled(true);
            ui->O15->setEnabled(true);
            ui->N15->setEnabled(true);
        }}

}

void MainWindow::desbloquear_final(coordenada final)
{
    desbloquear(final.x,final.y,final);
}

void MainWindow::bloquear_botones()
{
    ui->A1->setDisabled(true);ui->A2->setDisabled(true);ui->A3->setDisabled(true);ui->A4->setDisabled(true);ui->A5->setDisabled(true);ui->A6->setDisabled(true);ui->A7->setDisabled(true);ui->A8->setDisabled(true);ui->A9->setDisabled(true);ui->A10->setDisabled(true);ui->A11->setDisabled(true);ui->A12->setDisabled(true);ui->A13->setDisabled(true);ui->A14->setDisabled(true);ui->A15->setDisabled(true);
    ui->B1->setDisabled(true);ui->B2->setDisabled(true);ui->B3->setDisabled(true);ui->B4->setDisabled(true);ui->B5->setDisabled(true);ui->B6->setDisabled(true);ui->B7->setDisabled(true);ui->B8->setDisabled(true);ui->B9->setDisabled(true);ui->B10->setDisabled(true);ui->B11->setDisabled(true);ui->B12->setDisabled(true);ui->B13->setDisabled(true);ui->B14->setDisabled(true);ui->B15->setDisabled(true);
    ui->C1->setDisabled(true);ui->C2->setDisabled(true);ui->C3->setDisabled(true);ui->C4->setDisabled(true);ui->C5->setDisabled(true);ui->C6->setDisabled(true);ui->C7->setDisabled(true);ui->C8->setDisabled(true);ui->C9->setDisabled(true);ui->C10->setDisabled(true);ui->C11->setDisabled(true);ui->C12->setDisabled(true);ui->C13->setDisabled(true);ui->C14->setDisabled(true);ui->C15->setDisabled(true);
    ui->D1->setDisabled(true);ui->D2->setDisabled(true);ui->D3->setDisabled(true);ui->D4->setDisabled(true);ui->D5->setDisabled(true);ui->D6->setDisabled(true);ui->D7->setDisabled(true);ui->D8->setDisabled(true);ui->D9->setDisabled(true);ui->D10->setDisabled(true);ui->D11->setDisabled(true);ui->D12->setDisabled(true);ui->D13->setDisabled(true);ui->D14->setDisabled(true);ui->D15->setDisabled(true);
    ui->E1->setDisabled(true);ui->E2->setDisabled(true);ui->E3->setDisabled(true);ui->E4->setDisabled(true);ui->E5->setDisabled(true);ui->E6->setDisabled(true);ui->E7->setDisabled(true);ui->E8->setDisabled(true);ui->E9->setDisabled(true);ui->E10->setDisabled(true);ui->E11->setDisabled(true);ui->E12->setDisabled(true);ui->E13->setDisabled(true);ui->E14->setDisabled(true);ui->E15->setDisabled(true);
    ui->F1->setDisabled(true);ui->F2->setDisabled(true);ui->F3->setDisabled(true);ui->F4->setDisabled(true);ui->F5->setDisabled(true);ui->F6->setDisabled(true);ui->F7->setDisabled(true);ui->F8->setDisabled(true);ui->F9->setDisabled(true);ui->F10->setDisabled(true);ui->F11->setDisabled(true);ui->F12->setDisabled(true);ui->F13->setDisabled(true);ui->F14->setDisabled(true);ui->F15->setDisabled(true);
    ui->G1->setDisabled(true);ui->G2->setDisabled(true);ui->G3->setDisabled(true);ui->G4->setDisabled(true);ui->G5->setDisabled(true);ui->G6->setDisabled(true);ui->G7->setDisabled(true);ui->G8->setDisabled(true);ui->G9->setDisabled(true);ui->G10->setDisabled(true);ui->G11->setDisabled(true);ui->G12->setDisabled(true);ui->G13->setDisabled(true);ui->G14->setDisabled(true);ui->G15->setDisabled(true);
    ui->H1->setDisabled(true);ui->H2->setDisabled(true);ui->H3->setDisabled(true);ui->H4->setDisabled(true);ui->H5->setDisabled(true);ui->H6->setDisabled(true);ui->H7->setDisabled(true);ui->H8->setDisabled(true);ui->H9->setDisabled(true);ui->H10->setDisabled(true);ui->H11->setDisabled(true);ui->H12->setDisabled(true);ui->H13->setDisabled(true);ui->H14->setDisabled(true);ui->H15->setDisabled(true);
    ui->I1->setDisabled(true);ui->I2->setDisabled(true);ui->I3->setDisabled(true);ui->I4->setDisabled(true);ui->I5->setDisabled(true);ui->I6->setDisabled(true);ui->I7->setDisabled(true);ui->I8->setDisabled(true);ui->I9->setDisabled(true);ui->I10->setDisabled(true);ui->I11->setDisabled(true);ui->I12->setDisabled(true);ui->I13->setDisabled(true);ui->I14->setDisabled(true);ui->I15->setDisabled(true);
    ui->J1->setDisabled(true);ui->J2->setDisabled(true);ui->J3->setDisabled(true);ui->J4->setDisabled(true);ui->J5->setDisabled(true);ui->J6->setDisabled(true);ui->J7->setDisabled(true);ui->J8->setDisabled(true);ui->J9->setDisabled(true);ui->J10->setDisabled(true);ui->J11->setDisabled(true);ui->J12->setDisabled(true);ui->J13->setDisabled(true);ui->J14->setDisabled(true);ui->J15->setDisabled(true);
    ui->K1->setDisabled(true);ui->K2->setDisabled(true);ui->K3->setDisabled(true);ui->K4->setDisabled(true);ui->K5->setDisabled(true);ui->K6->setDisabled(true);ui->K7->setDisabled(true);ui->K8->setDisabled(true);ui->K9->setDisabled(true);ui->K10->setDisabled(true);ui->K11->setDisabled(true);ui->K12->setDisabled(true);ui->K13->setDisabled(true);ui->K14->setDisabled(true);ui->K15->setDisabled(true);
    ui->L1->setDisabled(true);ui->L2->setDisabled(true);ui->L3->setDisabled(true);ui->L4->setDisabled(true);ui->L5->setDisabled(true);ui->L6->setDisabled(true);ui->L7->setDisabled(true);ui->L8->setDisabled(true);ui->L9->setDisabled(true);ui->L10->setDisabled(true);ui->L11->setDisabled(true);ui->L12->setDisabled(true);ui->L13->setDisabled(true);ui->L14->setDisabled(true);ui->L15->setDisabled(true);
    ui->M1->setDisabled(true);ui->M2->setDisabled(true);ui->M3->setDisabled(true);ui->M4->setDisabled(true);ui->M5->setDisabled(true);ui->M6->setDisabled(true);ui->M7->setDisabled(true);ui->M8->setDisabled(true);ui->M9->setDisabled(true);ui->M10->setDisabled(true);ui->M11->setDisabled(true);ui->M12->setDisabled(true);ui->M13->setDisabled(true);ui->M14->setDisabled(true);ui->M15->setDisabled(true);
    ui->N1->setDisabled(true);ui->N2->setDisabled(true);ui->N3->setDisabled(true);ui->N4->setDisabled(true);ui->N5->setDisabled(true);ui->N6->setDisabled(true);ui->N7->setDisabled(true);ui->N8->setDisabled(true);ui->N9->setDisabled(true);ui->N10->setDisabled(true);ui->N11->setDisabled(true);ui->N12->setDisabled(true);ui->N13->setDisabled(true);ui->N14->setDisabled(true);ui->N15->setDisabled(true);
    ui->O1->setDisabled(true);ui->O2->setDisabled(true);ui->O3->setDisabled(true);ui->O4->setDisabled(true);ui->O5->setDisabled(true);ui->O6->setDisabled(true);ui->O7->setDisabled(true);ui->O8->setDisabled(true);ui->O9->setDisabled(true);ui->O10->setDisabled(true);ui->O11->setDisabled(true);ui->O12->setDisabled(true);ui->O13->setDisabled(true);ui->O14->setDisabled(true);ui->O15->setDisabled(true);
}

void MainWindow::cargar_repetidos()
{
    terreno t;
    char comma;
    ifstream archivo("repetidos.jai");
    if(archivo.is_open()){
        int i=1;
        ui->comboBox->insertItem(0,"Terreno");
        while(!archivo.eof()){
            if(archivo.eof())break;
            archivo>>t.valor;
            if(archivo.eof())break;
            archivo>>comma;
            archivo>>t.nombre;
            archivo>>comma;
            archivo>>t.icono;
            archivo>>comma;
            ui->comboBox->insertItem(i,generar_icono(t.icono),QString::fromStdString(t.icono));
            i++;
            terren.push_back(t);
        }
    }
}

bool MainWindow::mover(int x1, int y1, int x2, int y2, string nombre)
{
    switch (x1) {
    case 0:
        switch (y1) {
        case 0:
            ui->A1->setIcon(generar_icono(campo[0][0].icono));
            validar_cordenada(x2+1,y2+1,nombre);
            break;
        case 1:
            ui->A2->setIcon(generar_icono(campo[0][1].icono));
            validar_cordenada(x2+1,y2+1,nombre);
            break;
        case 2:
            ui->A3->setIcon(generar_icono(campo[0][2].icono));
            validar_cordenada(x2+1,y2+1,nombre);
            break;
        case 3:
            ui->A4->setIcon(generar_icono(campo[0][3].icono));
            validar_cordenada(x2+1,y2+1,nombre);
            break;
        case 4:
            ui->A5->setIcon(generar_icono(campo[0][4].icono));
            validar_cordenada(x2+1,y2+1,nombre);
            break;
        case 5:
            ui->A6->setIcon(generar_icono(campo[0][5].icono));
            validar_cordenada(x2+1,y2+1,nombre);
            break;
        case 6:
            ui->A7->setIcon(generar_icono(campo[0][6].icono));
            validar_cordenada(x2+1,y2+1,nombre);
            break;
        case 7:
            ui->A8->setIcon(generar_icono(campo[0][7].icono));
            validar_cordenada(x2+1,y2+1,nombre);
            break;
        case 8:
            ui->A9->setIcon(generar_icono(campo[0][8].icono));
            validar_cordenada(x2+1,y2+1,nombre);
            break;
        case 9:
            ui->A10->setIcon(generar_icono(campo[0][9].icono));
            validar_cordenada(x2+1,y2+1,nombre);
            break;
        case 10:
            ui->A11->setIcon(generar_icono(campo[0][10].icono));
            validar_cordenada(x2+1,y2+1,nombre);
            break;
        case 11:
            ui->A12->setIcon(generar_icono(campo[0][11].icono));
            validar_cordenada(x2+1,y2+1,nombre);
            break;
        case 12:
            ui->A13->setIcon(generar_icono(campo[0][12].icono));
            validar_cordenada(x2+1,y2+1,nombre);
            break;
        case 13:
            ui->A14->setIcon(generar_icono(campo[0][13].icono));
            validar_cordenada(x2+1,y2+1,nombre);
            break;
        case 14:
            ui->A15->setIcon(generar_icono(campo[0][14].icono));
            validar_cordenada(x2+1,y2+1,nombre);
            break;
        }

        break;
    case 1:
        switch (y1) {
        case 0:
            ui->B1->setIcon(generar_icono(campo[1][0].icono));
            validar_cordenada(x2+1,y2+1,nombre);
            break;
        case 1:
            ui->B2->setIcon(generar_icono(campo[1][1].icono));
            validar_cordenada(x2+1,y2+1,nombre);
            break;
        case 2:
            ui->B3->setIcon(generar_icono(campo[1][2].icono));
            validar_cordenada(x2+1,y2+1,nombre);
            break;
        case 3:
            ui->B4->setIcon(generar_icono(campo[1][3].icono));
            validar_cordenada(x2+1,y2+1,nombre);
            break;
        case 4:
            ui->B5->setIcon(generar_icono(campo[1][4].icono));
            validar_cordenada(x2+1,y2+1,nombre);
            break;
        case 5:
            ui->B6->setIcon(generar_icono(campo[1][5].icono));
            validar_cordenada(x2+1,y2+1,nombre);
            break;
        case 6:
            ui->B7->setIcon(generar_icono(campo[1][6].icono));
            validar_cordenada(x2+1,y2+1,nombre);
            break;
        case 7:
            ui->B8->setIcon(generar_icono(campo[1][7].icono));
            validar_cordenada(x2+1,y2+1,nombre);
            break;
        case 8:
            ui->B9->setIcon(generar_icono(campo[1][8].icono));
            validar_cordenada(x2+1,y2+1,nombre);
            break;
        case 9:
            ui->B10->setIcon(generar_icono(campo[1][9].icono));
            validar_cordenada(x2+1,y2+1,nombre);
            break;
        case 10:
            ui->B11->setIcon(generar_icono(campo[1][10].icono));
            validar_cordenada(x2+1,y2+1,nombre);
            break;
        case 11:
            ui->B12->setIcon(generar_icono(campo[1][11].icono));
            validar_cordenada(x2+1,y2+1,nombre);
            break;
        case 12:
            ui->B13->setIcon(generar_icono(campo[1][12].icono));
            validar_cordenada(x2+1,y2+1,nombre);
            break;
        case 13:
            ui->B14->setIcon(generar_icono(campo[1][13].icono));
            validar_cordenada(x2+1,y2+1,nombre);
            break;
        case 14:
            ui->B15->setIcon(generar_icono(campo[1][14].icono));
            validar_cordenada(x2+1,y2+1,nombre);
            break;
        }
        break;
    case 2:
        switch (y1) {
        case 0:
            ui->C1->setIcon(generar_icono(campo[2][0].icono));
            validar_cordenada(x2+1,y2+1,nombre);
            break;
        case 1:
            ui->C2->setIcon(generar_icono(campo[2][1].icono));
            validar_cordenada(x2+1,y2+1,nombre);
            break;
        case 2:
            ui->C3->setIcon(generar_icono(campo[2][2].icono));
            validar_cordenada(x2+1,y2+1,nombre);
            break;
        case 3:
            ui->C4->setIcon(generar_icono(campo[2][3].icono));
            validar_cordenada(x2+1,y2+1,nombre);
            break;
        case 4:
            ui->C5->setIcon(generar_icono(campo[2][4].icono));
            validar_cordenada(x2+1,y2+1,nombre);
            break;
        case 5:
            ui->C6->setIcon(generar_icono(campo[2][5].icono));
            validar_cordenada(x2+1,y2+1,nombre);
            break;
        case 6:
            ui->C7->setIcon(generar_icono(campo[2][6].icono));
            validar_cordenada(x2+1,y2+1,nombre);
            break;
        case 7:
            ui->C8->setIcon(generar_icono(campo[2][7].icono));
            validar_cordenada(x2+1,y2+1,nombre);
            break;
        case 8:
            ui->C9->setIcon(generar_icono(campo[2][8].icono));
            validar_cordenada(x2+1,y2+1,nombre);
            break;
        case 9:
            ui->C10->setIcon(generar_icono(campo[2][9].icono));
            validar_cordenada(x2+1,y2+1,nombre);
            break;
        case 10:
            ui->C11->setIcon(generar_icono(campo[2][10].icono));
            validar_cordenada(x2+1,y2+1,nombre);
            break;
        case 11:
            ui->C12->setIcon(generar_icono(campo[2][11].icono));
            validar_cordenada(x2+1,y2+1,nombre);
            break;
        case 12:
            ui->C13->setIcon(generar_icono(campo[2][12].icono));
            validar_cordenada(x2+1,y2+1,nombre);
            break;
        case 13:
            ui->C14->setIcon(generar_icono(campo[2][13].icono));
            validar_cordenada(x2+1,y2+1,nombre);
            break;
        case 14:
            ui->C15->setIcon(generar_icono(campo[2][14].icono));
            validar_cordenada(x2+1,y2+1,nombre);
            break;
        }
        break;
    case 3:
        switch (y1) {
        case 0:
            ui->D1->setIcon(generar_icono(campo[3][0].icono));
            validar_cordenada(x2+1,y2+1,nombre);
            break;
        case 1:
            ui->D2->setIcon(generar_icono(campo[3][1].icono));
            validar_cordenada(x2+1,y2+1,nombre);
            break;
        case 2:
            ui->D3->setIcon(generar_icono(campo[3][2].icono));
            validar_cordenada(x2+1,y2+1,nombre);
            break;
        case 3:
            ui->D4->setIcon(generar_icono(campo[3][3].icono));
            validar_cordenada(x2+1,y2+1,nombre);
            break;
        case 4:
            ui->D5->setIcon(generar_icono(campo[3][4].icono));
            validar_cordenada(x2+1,y2+1,nombre);
            break;
        case 5:
            ui->D6->setIcon(generar_icono(campo[3][5].icono));
            validar_cordenada(x2+1,y2+1,nombre);
            break;
        case 6:
            ui->D7->setIcon(generar_icono(campo[3][6].icono));
            validar_cordenada(x2+1,y2+1,nombre);
            break;
        case 7:
            ui->D8->setIcon(generar_icono(campo[3][7].icono));
            validar_cordenada(x2+1,y2+1,nombre);
            break;
        case 8:
            ui->D9->setIcon(generar_icono(campo[3][8].icono));
            validar_cordenada(x2+1,y2+1,nombre);
            break;
        case 9:
            ui->D10->setIcon(generar_icono(campo[3][9].icono));
            validar_cordenada(x2+1,y2+1,nombre);
            break;
        case 10:
            ui->D11->setIcon(generar_icono(campo[3][10].icono));
            validar_cordenada(x2+1,y2+1,nombre);
            break;
        case 11:
            ui->D12->setIcon(generar_icono(campo[3][11].icono));
            validar_cordenada(x2+1,y2+1,nombre);
            break;
        case 12:
            ui->D13->setIcon(generar_icono(campo[3][12].icono));
            validar_cordenada(x2+1,y2+1,nombre);
            break;
        case 13:
            ui->D14->setIcon(generar_icono(campo[3][13].icono));
            validar_cordenada(x2+1,y2+1,nombre);
            break;
        case 14:
            ui->D15->setIcon(generar_icono(campo[3][14].icono));
            validar_cordenada(x2+1,y2+1,nombre);
            break;
        }
        break;
    case 4:
        switch (y1) {
        case 0:
            ui->E1->setIcon(generar_icono(campo[4][0].icono));
            validar_cordenada(x2+1,y2+1,nombre);
            break;
        case 1:
            ui->E2->setIcon(generar_icono(campo[4][1].icono));
            validar_cordenada(x2+1,y2+1,nombre);
            break;
        case 2:
            ui->E3->setIcon(generar_icono(campo[4][2].icono));
            validar_cordenada(x2+1,y2+1,nombre);
            break;
        case 3:
            ui->E4->setIcon(generar_icono(campo[4][3].icono));
            validar_cordenada(x2+1,y2+1,nombre);
            break;
        case 4:
            ui->E5->setIcon(generar_icono(campo[4][4].icono));
            validar_cordenada(x2+1,y2+1,nombre);
            break;
        case 5:
            ui->E6->setIcon(generar_icono(campo[4][5].icono));
            validar_cordenada(x2+1,y2+1,nombre);
            break;
        case 6:
            ui->E7->setIcon(generar_icono(campo[4][6].icono));
            validar_cordenada(x2+1,y2+1,nombre);
            break;
        case 7:
            ui->E8->setIcon(generar_icono(campo[4][7].icono));
            validar_cordenada(x2+1,y2+1,nombre);
            break;
        case 8:
            ui->E9->setIcon(generar_icono(campo[4][8].icono));
            validar_cordenada(x2+1,y2+1,nombre);
            break;
        case 9:
            ui->E10->setIcon(generar_icono(campo[4][9].icono));
            validar_cordenada(x2+1,y2+1,nombre);
            break;
        case 10:
            ui->E11->setIcon(generar_icono(campo[4][10].icono));
            validar_cordenada(x2+1,y2+1,nombre);
            break;
        case 11:
            ui->E12->setIcon(generar_icono(campo[4][11].icono));
            validar_cordenada(x2+1,y2+1,nombre);
            break;
        case 12:
            ui->E13->setIcon(generar_icono(campo[4][12].icono));
            validar_cordenada(x2+1,y2+1,nombre);
            break;
        case 13:
            ui->E14->setIcon(generar_icono(campo[4][13].icono));
            validar_cordenada(x2+1,y2+1,nombre);
            break;
        case 14:
            ui->E15->setIcon(generar_icono(campo[4][14].icono));
            validar_cordenada(x2+1,y2+1,nombre);
            break;
        }
        break;
    case 5:
        switch (y1) {
        case 0:
            ui->F1->setIcon(generar_icono(campo[5][0].icono));
            validar_cordenada(x2+1,y2+1,nombre);
            break;
        case 1:
            ui->F2->setIcon(generar_icono(campo[5][1].icono));
            validar_cordenada(x2+1,y2+1,nombre);
            break;
        case 2:
            ui->F3->setIcon(generar_icono(campo[5][2].icono));
            validar_cordenada(x2+1,y2+1,nombre);
            break;
        case 3:
            ui->F4->setIcon(generar_icono(campo[5][3].icono));
            validar_cordenada(x2+1,y2+1,nombre);
            break;
        case 4:
            ui->F5->setIcon(generar_icono(campo[5][4].icono));
            validar_cordenada(x2+1,y2+1,nombre);
            break;
        case 5:
            ui->F6->setIcon(generar_icono(campo[5][5].icono));
            validar_cordenada(x2+1,y2+1,nombre);
            break;
        case 6:
            ui->F7->setIcon(generar_icono(campo[5][6].icono));
            validar_cordenada(x2+1,y2+1,nombre);
            break;
        case 7:
            ui->F8->setIcon(generar_icono(campo[5][7].icono));
            validar_cordenada(x2+1,y2+1,nombre);
            break;
        case 8:
            ui->F9->setIcon(generar_icono(campo[5][8].icono));
            validar_cordenada(x2+1,y2+1,nombre);
            break;
        case 9:
            ui->F10->setIcon(generar_icono(campo[5][9].icono));
            validar_cordenada(x2+1,y2+1,nombre);
            break;
        case 10:
            ui->F11->setIcon(generar_icono(campo[5][10].icono));
            validar_cordenada(x2+1,y2+1,nombre);
            break;
        case 11:
            ui->F12->setIcon(generar_icono(campo[5][11].icono));
            validar_cordenada(x2+1,y2+1,nombre);
            break;
        case 12:
            ui->F13->setIcon(generar_icono(campo[5][12].icono));
            validar_cordenada(x2+1,y2+1,nombre);
            break;
        case 13:
            ui->F14->setIcon(generar_icono(campo[5][13].icono));
            validar_cordenada(x2+1,y2+1,nombre);
            break;
        case 14:
            ui->F15->setIcon(generar_icono(campo[5][14].icono));
            validar_cordenada(x2+1,y2+1,nombre);
            break;
        }
        break;
    case 6:
        switch (y1) {
        case 0:
            ui->G1->setIcon(generar_icono(campo[6][0].icono));
            validar_cordenada(x2+1,y2+1,nombre);
            break;
        case 1:
            ui->G2->setIcon(generar_icono(campo[6][1].icono));
            validar_cordenada(x2+1,y2+1,nombre);
            break;
        case 2:
            ui->G3->setIcon(generar_icono(campo[6][2].icono));
            validar_cordenada(x2+1,y2+1,nombre);
            break;
        case 3:
            ui->G4->setIcon(generar_icono(campo[6][3].icono));
            validar_cordenada(x2+1,y2+1,nombre);
            break;
        case 4:
            ui->G5->setIcon(generar_icono(campo[6][4].icono));
            validar_cordenada(x2+1,y2+1,nombre);
            break;
        case 5:
            ui->G6->setIcon(generar_icono(campo[6][5].icono));
            validar_cordenada(x2+1,y2+1,nombre);
            break;
        case 6:
            ui->G7->setIcon(generar_icono(campo[6][6].icono));
            validar_cordenada(x2+1,y2+1,nombre);
            break;
        case 7:
            ui->G8->setIcon(generar_icono(campo[6][7].icono));
            validar_cordenada(x2+1,y2+1,nombre);
            break;
        case 8:
            ui->G9->setIcon(generar_icono(campo[6][8].icono));
            validar_cordenada(x2+1,y2+1,nombre);
            break;
        case 9:
            ui->G10->setIcon(generar_icono(campo[6][9].icono));
            validar_cordenada(x2+1,y2+1,nombre);
            break;
        case 10:
            ui->G11->setIcon(generar_icono(campo[6][10].icono));
            validar_cordenada(x2+1,y2+1,nombre);
            break;
        case 11:
            ui->G12->setIcon(generar_icono(campo[6][11].icono));
            validar_cordenada(x2+1,y2+1,nombre);
            break;
        case 12:
            ui->G13->setIcon(generar_icono(campo[6][12].icono));
            validar_cordenada(x2+1,y2+1,nombre);
            break;
        case 13:
            ui->G14->setIcon(generar_icono(campo[6][13].icono));
            validar_cordenada(x2+1,y2+1,nombre);
            break;
        case 14:
            ui->G15->setIcon(generar_icono(campo[6][14].icono));
            validar_cordenada(x2+1,y2+1,nombre);
            break;
        }
        break;
    case 7:
        switch (y1) {
        case 0:
            ui->H1->setIcon(generar_icono(campo[7][0].icono));
            validar_cordenada(x2+1,y2+1,nombre);
            break;
        case 1:
            ui->H2->setIcon(generar_icono(campo[7][1].icono));
            validar_cordenada(x2+1,y2+1,nombre);
            break;
        case 2:
            ui->H3->setIcon(generar_icono(campo[7][2].icono));
            validar_cordenada(x2+1,y2+1,nombre);
            break;
        case 3:
            ui->H4->setIcon(generar_icono(campo[7][3].icono));
            validar_cordenada(x2+1,y2+1,nombre);
            break;
        case 4:
            ui->H5->setIcon(generar_icono(campo[7][4].icono));
            validar_cordenada(x2+1,y2+1,nombre);
            break;
        case 5:
            ui->H6->setIcon(generar_icono(campo[7][5].icono));
            validar_cordenada(x2+1,y2+1,nombre);
            break;
        case 6:
            ui->H7->setIcon(generar_icono(campo[7][6].icono));
            validar_cordenada(x2+1,y2+1,nombre);
            break;
        case 7:
            ui->H8->setIcon(generar_icono(campo[7][7].icono));
            validar_cordenada(x2+1,y2+1,nombre);
            break;
        case 8:
            ui->H9->setIcon(generar_icono(campo[7][8].icono));
            validar_cordenada(x2+1,y2+1,nombre);
            break;
        case 9:
            ui->H10->setIcon(generar_icono(campo[7][9].icono));
            validar_cordenada(x2+1,y2+1,nombre);
            break;
        case 10:
            ui->H11->setIcon(generar_icono(campo[7][10].icono));
            validar_cordenada(x2+1,y2+1,nombre);
            break;
        case 11:
            ui->H12->setIcon(generar_icono(campo[7][11].icono));
            validar_cordenada(x2+1,y2+1,nombre);
            break;
        case 12:
            ui->H13->setIcon(generar_icono(campo[7][12].icono));
            validar_cordenada(x2+1,y2+1,nombre);
            break;
        case 13:
            ui->H14->setIcon(generar_icono(campo[7][13].icono));
            validar_cordenada(x2+1,y2+1,nombre);
            break;
        case 14:
            ui->H15->setIcon(generar_icono(campo[7][14].icono));
            validar_cordenada(x2+1,y2+1,nombre);
            break;
        }
        break;
    case 8:
        switch (y1) {
        case 0:
            ui->I1->setIcon(generar_icono(campo[8][0].icono));
            validar_cordenada(x2+1,y2+1,nombre);
            break;
        case 1:
            ui->I2->setIcon(generar_icono(campo[8][1].icono));
            validar_cordenada(x2+1,y2+1,nombre);
            break;
        case 2:
            ui->I3->setIcon(generar_icono(campo[8][2].icono));
            validar_cordenada(x2+1,y2+1,nombre);
            break;
        case 3:
            ui->I4->setIcon(generar_icono(campo[8][3].icono));
            validar_cordenada(x2+1,y2+1,nombre);
            break;
        case 4:
            ui->I5->setIcon(generar_icono(campo[8][4].icono));
            validar_cordenada(x2+1,y2+1,nombre);
            break;
        case 5:
            ui->I6->setIcon(generar_icono(campo[8][5].icono));
            validar_cordenada(x2+1,y2+1,nombre);
            break;
        case 6:
            ui->I7->setIcon(generar_icono(campo[8][6].icono));
            validar_cordenada(x2+1,y2+1,nombre);
            break;
        case 7:
            ui->I8->setIcon(generar_icono(campo[8][7].icono));
            validar_cordenada(x2+1,y2+1,nombre);
            break;
        case 8:
            ui->I9->setIcon(generar_icono(campo[8][8].icono));
            validar_cordenada(x2+1,y2+1,nombre);
            break;
        case 9:
            ui->I10->setIcon(generar_icono(campo[8][9].icono));
            validar_cordenada(x2+1,y2+1,nombre);
            break;
        case 10:
            ui->I11->setIcon(generar_icono(campo[8][10].icono));
            validar_cordenada(x2+1,y2+1,nombre);
            break;
        case 11:
            ui->I12->setIcon(generar_icono(campo[8][11].icono));
            validar_cordenada(x2+1,y2+1,nombre);
            break;
        case 12:
            ui->I13->setIcon(generar_icono(campo[8][12].icono));
            validar_cordenada(x2+1,y2+1,nombre);
            break;
        case 13:
            ui->I14->setIcon(generar_icono(campo[8][13].icono));
            validar_cordenada(x2+1,y2+1,nombre);
            break;
        case 14:
            ui->I15->setIcon(generar_icono(campo[8][14].icono));
            validar_cordenada(x2+1,y2+1,nombre);
            break;
        }
        break;
    case 9:
        switch (y1) {
        case 0:
            ui->J1->setIcon(generar_icono(campo[9][0].icono));
            validar_cordenada(x2+1,y2+1,nombre);
            break;
        case 1:
            ui->J2->setIcon(generar_icono(campo[9][1].icono));
            validar_cordenada(x2+1,y2+1,nombre);
            break;
        case 2:
            ui->J3->setIcon(generar_icono(campo[9][2].icono));
            validar_cordenada(x2+1,y2+1,nombre);
            break;
        case 3:
            ui->J4->setIcon(generar_icono(campo[9][3].icono));
            validar_cordenada(x2+1,y2+1,nombre);
            break;
        case 4:
            ui->J5->setIcon(generar_icono(campo[9][4].icono));
            validar_cordenada(x2+1,y2+1,nombre);
            break;
        case 5:
            ui->J6->setIcon(generar_icono(campo[9][5].icono));
            validar_cordenada(x2+1,y2+1,nombre);
            break;
        case 6:
            ui->J7->setIcon(generar_icono(campo[9][6].icono));
            validar_cordenada(x2+1,y2+1,nombre);
            break;
        case 7:
            ui->J8->setIcon(generar_icono(campo[9][7].icono));
            validar_cordenada(x2+1,y2+1,nombre);
            break;
        case 8:
            ui->J9->setIcon(generar_icono(campo[9][8].icono));
            validar_cordenada(x2+1,y2+1,nombre);
            break;
        case 9:
            ui->J10->setIcon(generar_icono(campo[9][9].icono));
            validar_cordenada(x2+1,y2+1,nombre);
            break;
        case 10:
            ui->J11->setIcon(generar_icono(campo[9][10].icono));
            validar_cordenada(x2+1,y2+1,nombre);
            break;
        case 11:
            ui->J12->setIcon(generar_icono(campo[9][11].icono));
            validar_cordenada(x2+1,y2+1,nombre);
            break;
        case 12:
            ui->J13->setIcon(generar_icono(campo[9][12].icono));
            validar_cordenada(x2+1,y2+1,nombre);
            break;
        case 13:
            ui->J14->setIcon(generar_icono(campo[9][13].icono));
            validar_cordenada(x2+1,y2+1,nombre);
            break;
        case 14:
            ui->J15->setIcon(generar_icono(campo[9][14].icono));
            validar_cordenada(x2+1,y2+1,nombre);
            break;
        }
        break;
    case 10:
        switch (y1) {
        case 0:
            ui->K1->setIcon(generar_icono(campo[10][0].icono));
            validar_cordenada(x2+1,y2+1,nombre);
            break;
        case 1:
            ui->K2->setIcon(generar_icono(campo[10][1].icono));
            validar_cordenada(x2+1,y2+1,nombre);
            break;
        case 2:
            ui->K3->setIcon(generar_icono(campo[10][2].icono));
            validar_cordenada(x2+1,y2+1,nombre);
            break;
        case 3:
            ui->K4->setIcon(generar_icono(campo[10][3].icono));
            validar_cordenada(x2+1,y2+1,nombre);
            break;
        case 4:
            ui->K5->setIcon(generar_icono(campo[10][4].icono));
            validar_cordenada(x2+1,y2+1,nombre);
            break;
        case 5:
            ui->K6->setIcon(generar_icono(campo[10][5].icono));
            validar_cordenada(x2+1,y2+1,nombre);
            break;
        case 6:
            ui->K7->setIcon(generar_icono(campo[10][6].icono));
            validar_cordenada(x2+1,y2+1,nombre);
            break;
        case 7:
            ui->K8->setIcon(generar_icono(campo[10][7].icono));
            validar_cordenada(x2+1,y2+1,nombre);
            break;
        case 8:
            ui->K9->setIcon(generar_icono(campo[10][8].icono));
            validar_cordenada(x2+1,y2+1,nombre);
            break;
        case 9:
            ui->K10->setIcon(generar_icono(campo[10][9].icono));
            validar_cordenada(x2+1,y2+1,nombre);
            break;
        case 10:
            ui->K11->setIcon(generar_icono(campo[10][10].icono));
            validar_cordenada(x2+1,y2+1,nombre);
            break;
        case 11:
            ui->K12->setIcon(generar_icono(campo[10][11].icono));
            validar_cordenada(x2+1,y2+1,nombre);
            break;
        case 12:
            ui->K13->setIcon(generar_icono(campo[10][12].icono));
            validar_cordenada(x2+1,y2+1,nombre);
            break;
        case 13:
            ui->K14->setIcon(generar_icono(campo[10][13].icono));
            validar_cordenada(x2+1,y2+1,nombre);
            break;
        case 14:
            ui->K15->setIcon(generar_icono(campo[10][14].icono));
            validar_cordenada(x2+1,y2+1,nombre);
            break;
        }
        break;
    case 11:
        switch (y1) {
        case 0:
            ui->L1->setIcon(generar_icono(campo[11][0].icono));
            validar_cordenada(x2+1,y2+1,nombre);
            break;
        case 1:
            ui->L2->setIcon(generar_icono(campo[11][1].icono));
            validar_cordenada(x2+1,y2+1,nombre);
            break;
        case 2:
            ui->L3->setIcon(generar_icono(campo[11][2].icono));
            validar_cordenada(x2+1,y2+1,nombre);
            break;
        case 3:
            ui->L4->setIcon(generar_icono(campo[11][3].icono));
            validar_cordenada(x2+1,y2+1,nombre);
            break;
        case 4:
            ui->L5->setIcon(generar_icono(campo[11][4].icono));
            validar_cordenada(x2+1,y2+1,nombre);
            break;
        case 5:
            ui->L6->setIcon(generar_icono(campo[11][5].icono));
            validar_cordenada(x2+1,y2+1,nombre);
            break;
        case 6:
            ui->L7->setIcon(generar_icono(campo[11][6].icono));
            validar_cordenada(x2+1,y2+1,nombre);
            break;
        case 7:
            ui->L8->setIcon(generar_icono(campo[11][7].icono));
            validar_cordenada(x2+1,y2+1,nombre);
            break;
        case 8:
            ui->L9->setIcon(generar_icono(campo[11][8].icono));
            validar_cordenada(x2+1,y2+1,nombre);
            break;
        case 9:
            ui->L10->setIcon(generar_icono(campo[11][9].icono));
            validar_cordenada(x2+1,y2+1,nombre);
            break;
        case 10:
            ui->L11->setIcon(generar_icono(campo[11][10].icono));
            validar_cordenada(x2+1,y2+1,nombre);
            break;
        case 11:
            ui->L12->setIcon(generar_icono(campo[11][11].icono));
            validar_cordenada(x2+1,y2+1,nombre);
            break;
        case 12:
            ui->L13->setIcon(generar_icono(campo[11][12].icono));
            validar_cordenada(x2+1,y2+1,nombre);
            break;
        case 13:
            ui->L14->setIcon(generar_icono(campo[11][13].icono));
            validar_cordenada(x2+1,y2+1,nombre);
            break;
        case 14:
            ui->L15->setIcon(generar_icono(campo[11][14].icono));
            validar_cordenada(x2+1,y2+1,nombre);
            break;
        }
        break;
    case 12:
        switch (y1) {
        case 0:
            ui->M1->setIcon(generar_icono(campo[12][0].icono));
            validar_cordenada(x2+1,y2+1,nombre);
            break;
        case 1:
            ui->M2->setIcon(generar_icono(campo[12][1].icono));
            validar_cordenada(x2+1,y2+1,nombre);
            break;
        case 2:
            ui->M3->setIcon(generar_icono(campo[12][2].icono));
            validar_cordenada(x2+1,y2+1,nombre);
            break;
        case 3:
            ui->M4->setIcon(generar_icono(campo[12][3].icono));
            validar_cordenada(x2+1,y2+1,nombre);
            break;
        case 4:
            ui->M5->setIcon(generar_icono(campo[12][4].icono));
            validar_cordenada(x2+1,y2+1,nombre);
            break;
        case 5:
            ui->M6->setIcon(generar_icono(campo[12][5].icono));
            validar_cordenada(x2+1,y2+1,nombre);
            break;
        case 6:
            ui->M7->setIcon(generar_icono(campo[12][6].icono));
            validar_cordenada(x2+1,y2+1,nombre);
            break;
        case 7:
            ui->M8->setIcon(generar_icono(campo[12][7].icono));
            validar_cordenada(x2+1,y2+1,nombre);
            break;
        case 8:
            ui->M9->setIcon(generar_icono(campo[12][8].icono));
            validar_cordenada(x2+1,y2+1,nombre);
            break;
        case 9:
            ui->M10->setIcon(generar_icono(campo[12][9].icono));
            validar_cordenada(x2+1,y2+1,nombre);
            break;
        case 10:
            ui->M11->setIcon(generar_icono(campo[12][10].icono));
            validar_cordenada(x2+1,y2+1,nombre);
            break;
        case 11:
            ui->M12->setIcon(generar_icono(campo[12][11].icono));
            validar_cordenada(x2+1,y2+1,nombre);
            break;
        case 12:
            ui->M13->setIcon(generar_icono(campo[12][12].icono));
            validar_cordenada(x2+1,y2+1,nombre);
            break;
        case 13:
            ui->M14->setIcon(generar_icono(campo[12][13].icono));
            validar_cordenada(x2+1,y2+1,nombre);
            break;
        case 14:
            ui->M15->setIcon(generar_icono(campo[12][14].icono));
            validar_cordenada(x2+1,y2+1,nombre);
            break;
        }
        break;
    case 13:
        switch (y1) {
        case 0:
            ui->N1->setIcon(generar_icono(campo[13][0].icono));
            validar_cordenada(x2+1,y2+1,nombre);
            break;
        case 1:
            ui->N2->setIcon(generar_icono(campo[13][1].icono));
            validar_cordenada(x2+1,y2+1,nombre);
            break;
        case 2:
            ui->N3->setIcon(generar_icono(campo[13][2].icono));
            validar_cordenada(x2+1,y2+1,nombre);
            break;
        case 3:
            ui->N4->setIcon(generar_icono(campo[13][3].icono));
            validar_cordenada(x2+1,y2+1,nombre);
            break;
        case 4:
            ui->N5->setIcon(generar_icono(campo[13][4].icono));
            validar_cordenada(x2+1,y2+1,nombre);
            break;
        case 5:
            ui->N6->setIcon(generar_icono(campo[13][5].icono));
            validar_cordenada(x2+1,y2+1,nombre);
            break;
        case 6:
            ui->N7->setIcon(generar_icono(campo[13][6].icono));
            validar_cordenada(x2+1,y2+1,nombre);
            break;
        case 7:
            ui->N8->setIcon(generar_icono(campo[13][7].icono));
            validar_cordenada(x2+1,y2+1,nombre);
            break;
        case 8:
            ui->N9->setIcon(generar_icono(campo[13][8].icono));
            validar_cordenada(x2+1,y2+1,nombre);
            break;
        case 9:
            ui->N10->setIcon(generar_icono(campo[13][9].icono));
            validar_cordenada(x2+1,y2+1,nombre);
            break;
        case 10:
            ui->N11->setIcon(generar_icono(campo[13][10].icono));
            validar_cordenada(x2+1,y2+1,nombre);
            break;
        case 11:
            ui->N12->setIcon(generar_icono(campo[13][11].icono));
            validar_cordenada(x2+1,y2+1,nombre);
            break;
        case 12:
            ui->N13->setIcon(generar_icono(campo[13][12].icono));
            validar_cordenada(x2+1,y2+1,nombre);
            break;
        case 13:
            ui->N14->setIcon(generar_icono(campo[13][13].icono));
            validar_cordenada(x2+1,y2+1,nombre);
            break;
        case 14:
            ui->N15->setIcon(generar_icono(campo[13][14].icono));
            validar_cordenada(x2+1,y2+1,nombre);
            break;
        }
        break;
    case 14:
        switch (y1) {
        case 0:
            ui->O1->setIcon(generar_icono(campo[14][0].icono));
            validar_cordenada(x2+1,y2+1,nombre);
            break;
        case 1:
            ui->O2->setIcon(generar_icono(campo[14][1].icono));
            validar_cordenada(x2+1,y2+1,nombre);
            break;
        case 2:
            ui->O3->setIcon(generar_icono(campo[14][2].icono));
            validar_cordenada(x2+1,y2+1,nombre);
            break;
        case 3:
            ui->O4->setIcon(generar_icono(campo[14][3].icono));
            validar_cordenada(x2+1,y2+1,nombre);
            break;
        case 4:
            ui->O5->setIcon(generar_icono(campo[14][4].icono));
            validar_cordenada(x2+1,y2+1,nombre);
            break;
        case 5:
            ui->O6->setIcon(generar_icono(campo[14][5].icono));
            validar_cordenada(x2+1,y2+1,nombre);
            break;
        case 6:
            ui->O7->setIcon(generar_icono(campo[14][6].icono));
            validar_cordenada(x2+1,y2+1,nombre);
            break;
        case 7:
            ui->O8->setIcon(generar_icono(campo[14][7].icono));
            validar_cordenada(x2+1,y2+1,nombre);
            break;
        case 8:
            ui->O9->setIcon(generar_icono(campo[14][8].icono));
            validar_cordenada(x2+1,y2+1,nombre);
            break;
        case 9:
            ui->O10->setIcon(generar_icono(campo[14][9].icono));
            validar_cordenada(x2+1,y2+1,nombre);
            break;
        case 10:
            ui->O11->setIcon(generar_icono(campo[14][10].icono));
            validar_cordenada(x2+1,y2+1,nombre);
            break;
        case 11:
            ui->O12->setIcon(generar_icono(campo[14][11].icono));
            validar_cordenada(x2+1,y2+1,nombre);
            break;
        case 12:
            ui->O13->setIcon(generar_icono(campo[14][12].icono));
            validar_cordenada(x2+1,y2+1,nombre);
            break;
        case 13:
            ui->O14->setIcon(generar_icono(campo[14][13].icono));
            validar_cordenada(x2+1,y2+1,nombre);
            break;
        case 14:
            ui->O15->setIcon(generar_icono(campo[14][14].icono));
            validar_cordenada(x2+1,y2+1,nombre);
            break;
        }
        break;
    }
}

void MainWindow::on_lineEdit_cursorPositionChanged(int arg1, int arg2)
{
    QRegExp rx("([A-Z]|[a-z]|[0-9])*");
    QValidator *validator=new QRegExpValidator(rx,this);
    ui->lineEdit->setValidator(validator);
}

void MainWindow::on_pushButton_clicked()
{
    if(ui->ComboBox_fila_editar->currentIndex()>0&&ui->ComboBox_columna_2->currentIndex()>0){
        if(ui->lineEdit->text()!=""&&ui->comboBox->currentIndex()>0){
            campo[ui->ComboBox_fila_editar->currentIndex()-1][ui->ComboBox_columna_2->currentIndex()-1].nombre=ui->lineEdit->text().toStdString();
            campo[ui->ComboBox_fila_editar->currentIndex()-1][ui->ComboBox_columna_2->currentIndex()-1].icono=ui->comboBox->currentText().toStdString();
            generar_terreno();
            ui->ComboBox_fila_editar->setCurrentIndex(0);
            ui->ComboBox_columna_2->setCurrentIndex(0);
            ui->lineEdit->clear();
            ui->comboBox->setCurrentIndex(0);
        }
        else{
            QMessageBox mse;
            mse.setText("Favor de ingresar datos validos para la edicion");
            mse.exec();
        }
    }
    else{
        QMessageBox mse;
        mse.setText("Coordenada invalida");
        mse.exec();
    }

}

void MainWindow::on_comboBox_2_currentIndexChanged(int index)
{  
        ui->pb_abajo->setEnabled(true);
        ui->pb_arriba->setEnabled(true);
        ui->pb_izquierda->setEnabled(true);
        ui->pb_derecha->setEnabled(true);
        tipo=1;
        orden=1;
        int tam = prioridad.size();
        for(int i=0; i<tam; i++){
            prioridad.pop_back();
        }
        ui->lb_orden_1->setText("");ui->lb_orden_2->setText("");ui->lb_orden_3->setText("");ui->lb_orden_4->setText("");

}
void MainWindow::on_pushButton_2_clicked()
{
    personedicion *w=new personedicion;
    this->close();
    w->show();
}

void MainWindow::on_comboBox_currentIndexChanged(int index)
{

    for(unsigned int i=0; i<terren.size(); i++){
        if(ui->comboBox->currentText().toStdString()==terren[i].icono){
            ui->lineEdit->setText(QString::fromStdString(terren[i].nombre));
            break;
        }
    }
}

void MainWindow::on_comboBox_currentTextChanged(const QString &arg1)
{
    for(unsigned int i=0; i<terren.size(); i++){
        if(ui->comboBox->currentText().toStdString()==terren[i].icono){
            ui->lineEdit->setText(QString::fromStdString(terren[i].nombre));
            break;
        }
    }
}

string MainWindow::generar_coordenada(int x, int y)
{
    if(x<15&&y<15){
        if(x==0&&y==0)
            return "A1";
        if(x==0&&y==1)
            return "A2";
        if(x==0&&y==2)
            return "A3";
        if(x==0&&y==3)
            return "A4";
        if(x==0&&y==4)
            return "A5";
        if(x==0&&y==5)
            return "A6";
        if(x==0&&y==6)
            return "A7";
        if(x==0&&y==7)
            return "A8";
        if(x==0&&y==8)
            return "A9";
        if(x==0&&y==9)
            return "A10";
        if(x==0&&y==10)
            return "A11";
        if(x==0&&y==11)
            return "A12";
        if(x==0&&y==12)
            return "A13";
        if(x==0&&y==13)
            return "A14";
        if(x==0&&y==14)
            return "A15";

        if(x==1&&y==0)
            return "B1";
        if(x==1&&y==1)
            return "B2";
        if(x==1&&y==2)
            return "B3";
        if(x==1&&y==3)
            return "B4";
        if(x==1&&y==4)
            return "B5";
        if(x==1&&y==5)
            return "B6";
        if(x==1&&y==6)
            return "B7";
        if(x==1&&y==7)
            return "B8";
        if(x==1&&y==8)
            return "B9";
        if(x==1&&y==9)
            return "B10";
        if(x==1&&y==10)
            return "B11";
        if(x==1&&y==11)
            return "B12";
        if(x==1&&y==12)
            return "B13";
        if(x==1&&y==13)
            return "B14";
        if(x==1&&y==14)
            return "B15";

        if(x==2&&y==0)
            return "C1";
        if(x==2&&y==1)
            return "C2";
        if(x==2&&y==2)
            return "C3";
        if(x==2&&y==3)
            return "C4";
        if(x==2&&y==4)
            return "C5";
        if(x==2&&y==5)
            return "C6";
        if(x==2&&y==6)
            return "C7";
        if(x==2&&y==7)
            return "C8";
        if(x==2&&y==8)
            return "C9";
        if(x==2&&y==9)
            return "C10";
        if(x==2&&y==10)
            return "C11";
        if(x==2&&y==11)
            return "C12";
        if(x==2&&y==12)
            return "C13";
        if(x==2&&y==13)
            return "C14";
        if(x==2&&y==14)
            return "C15";

        if(x==3&&y==0)
            return "D1";
        if(x==3&&y==1)
            return "D2";
        if(x==3&&y==2)
            return "D3";
        if(x==3&&y==3)
            return "D4";
        if(x==3&&y==4)
            return "D5";
        if(x==3&&y==5)
            return "D6";
        if(x==3&&y==6)
            return "D7";
        if(x==3&&y==7)
            return "D8";
        if(x==3&&y==8)
            return "D9";
        if(x==3&&y==9)
            return "D10";
        if(x==3&&y==10)
            return "D11";
        if(x==3&&y==11)
            return "D12";
        if(x==3&&y==12)
            return "D13";
        if(x==3&&y==13)
            return "D14";
        if(x==3&&y==14)
            return "D15";

        if(x==4&&y==0)
            return "E1";
        if(x==4&&y==1)
            return "E2";
        if(x==4&&y==2)
            return "E3";
        if(x==4&&y==3)
            return "E4";
        if(x==4&&y==4)
            return "E5";
        if(x==4&&y==5)
            return "E6";
        if(x==4&&y==6)
            return "E7";
        if(x==4&&y==7)
            return "E8";
        if(x==4&&y==8)
            return "E9";
        if(x==4&&y==9)
            return "E10";
        if(x==4&&y==10)
            return "E11";
        if(x==4&&y==11)
            return "E12";
        if(x==4&&y==12)
            return "E13";
        if(x==4&&y==13)
            return "E14";
        if(x==4&&y==14)
            return "E15";

        if(x==5&&y==0)
            return "F1";
        if(x==5&&y==1)
            return "F2";
        if(x==5&&y==2)
            return "F3";
        if(x==5&&y==3)
            return "F4";
        if(x==5&&y==4)
            return "F5";
        if(x==5&&y==5)
            return "F6";
        if(x==5&&y==6)
            return "F7";
        if(x==5&&y==7)
            return "F8";
        if(x==5&&y==8)
            return "F9";
        if(x==5&&y==9)
            return "F10";
        if(x==5&&y==10)
            return "F11";
        if(x==5&&y==11)
            return "F12";
        if(x==5&&y==12)
            return "F13";
        if(x==5&&y==13)
            return "F14";
        if(x==5&&y==14)
            return "F15";

        if(x==6&&y==0)
            return "G1";
        if(x==6&&y==1)
            return "G2";
        if(x==6&&y==2)
            return "G3";
        if(x==6&&y==3)
            return "G4";
        if(x==6&&y==4)
            return "G5";
        if(x==6&&y==5)
            return "G6";
        if(x==6&&y==6)
            return "G7";
        if(x==6&&y==7)
            return "G8";
        if(x==6&&y==8)
            return "G9";
        if(x==6&&y==9)
            return "G10";
        if(x==6&&y==10)
            return "G11";
        if(x==6&&y==11)
            return "G12";
        if(x==6&&y==12)
            return "G13";
        if(x==6&&y==13)
            return "G14";
        if(x==6&&y==14)
            return "G15";

        if(x==7&&y==0)
            return "H1";
        if(x==7&&y==1)
            return "H2";
        if(x==7&&y==2)
            return "H3";
        if(x==7&&y==3)
            return "H4";
        if(x==7&&y==4)
            return "H5";
        if(x==7&&y==5)
            return "H6";
        if(x==7&&y==6)
            return "H7";
        if(x==7&&y==7)
            return "H8";
        if(x==7&&y==8)
            return "H9";
        if(x==7&&y==9)
            return "H10";
        if(x==7&&y==10)
            return "H11";
        if(x==7&&y==11)
            return "H12";
        if(x==7&&y==12)
            return "H13";
        if(x==7&&y==13)
            return "H14";
        if(x==7&&y==14)
            return "H15";

        if(x==8&&y==0)
            return "I1";
        if(x==8&&y==1)
            return "I2";
        if(x==8&&y==2)
            return "I3";
        if(x==8&&y==3)
            return "I4";
        if(x==8&&y==4)
            return "I5";
        if(x==8&&y==5)
            return "I6";
        if(x==8&&y==6)
            return "I7";
        if(x==8&&y==7)
            return "I8";
        if(x==8&&y==8)
            return "I9";
        if(x==8&&y==9)
            return "I10";
        if(x==8&&y==10)
            return "I11";
        if(x==8&&y==11)
            return "I12";
        if(x==8&&y==12)
            return "I13";
        if(x==8&&y==13)
            return "I14";
        if(x==8&&y==14)
            return "I15";

        if(x==9&&y==0)
            return "J1";
        if(x==9&&y==1)
            return "J2";
        if(x==9&&y==2)
            return "J3";
        if(x==9&&y==3)
            return "J4";
        if(x==9&&y==4)
            return "J5";
        if(x==9&&y==5)
            return "J6";
        if(x==9&&y==6)
            return "J7";
        if(x==9&&y==7)
            return "J8";
        if(x==9&&y==8)
            return "J9";
        if(x==9&&y==9)
            return "J10";
        if(x==9&&y==10)
            return "J11";
        if(x==9&&y==11)
            return "J12";
        if(x==9&&y==12)
            return "J13";
        if(x==9&&y==13)
            return "J14";
        if(x==9&&y==14)
            return "J15";

        if(x==10&&y==0)
            return "K1";
        if(x==10&&y==1)
            return "K2";
        if(x==10&&y==2)
            return "K3";
        if(x==10&&y==3)
            return "K4";
        if(x==10&&y==4)
            return "K5";
        if(x==10&&y==5)
            return "K6";
        if(x==10&&y==6)
            return "K7";
        if(x==10&&y==7)
            return "K8";
        if(x==10&&y==8)
            return "K9";
        if(x==10&&y==9)
            return "K10";
        if(x==10&&y==10)
            return "K11";
        if(x==10&&y==11)
            return "K12";
        if(x==10&&y==12)
            return "K13";
        if(x==10&&y==13)
            return "K14";
        if(x==10&&y==14)
            return "K15";

        if(x==11&&y==0)
            return "L1";
        if(x==11&&y==1)
            return "L2";
        if(x==11&&y==2)
            return "L3";
        if(x==11&&y==3)
            return "L4";
        if(x==11&&y==4)
            return "L5";
        if(x==11&&y==5)
            return "L6";
        if(x==11&&y==6)
            return "L7";
        if(x==11&&y==7)
            return "L8";
        if(x==11&&y==8)
            return "L9";
        if(x==11&&y==9)
            return "L10";
        if(x==11&&y==10)
            return "L11";
        if(x==11&&y==11)
            return "L12";
        if(x==11&&y==12)
            return "L13";
        if(x==11&&y==13)
            return "L14";
        if(x==11&&y==14)
            return "L15";

        if(x==12&&y==0)
            return "M1";
        if(x==12&&y==1)
            return "M2";
        if(x==12&&y==2)
            return "M3";
        if(x==12&&y==3)
            return "M4";
        if(x==12&&y==4)
            return "M5";
        if(x==12&&y==5)
            return "M6";
        if(x==12&&y==6)
            return "M7";
        if(x==12&&y==7)
            return "M8";
        if(x==12&&y==8)
            return "M9";
        if(x==12&&y==9)
            return "M10";
        if(x==12&&y==10)
            return "M11";
        if(x==12&&y==11)
            return "M12";
        if(x==12&&y==12)
            return "M13";
        if(x==12&&y==13)
            return "M14";
        if(x==12&&y==14)
            return "M15";

        if(x==13&&y==0)
            return "N1";
        if(x==13&&y==1)
            return "N2";
        if(x==13&&y==2)
            return "N3";
        if(x==13&&y==3)
            return "N4";
        if(x==13&&y==4)
            return "N5";
        if(x==13&&y==5)
            return "N6";
        if(x==13&&y==6)
            return "N7";
        if(x==13&&y==7)
            return "N8";
        if(x==13&&y==8)
            return "N9";
        if(x==13&&y==9)
            return "N10";
        if(x==13&&y==10)
            return "N11";
        if(x==13&&y==11)
            return "N12";
        if(x==13&&y==12)
            return "N13";
        if(x==13&&y==13)
            return "N14";
        if(x==13&&y==14)
            return "N15";

        if(x==14&&y==0)
            return "O1";
        if(x==14&&y==1)
            return "O2";
        if(x==14&&y==2)
            return "O3";
        if(x==14&&y==3)
            return "O4";
        if(x==14&&y==4)
            return "O5";
        if(x==14&&y==5)
            return "O6";
        if(x==14&&y==6)
            return "O7";
        if(x==14&&y==7)
            return "O8";
        if(x==14&&y==8)
            return "O9";
        if(x==14&&y==9)
            return "O10";
        if(x==14&&y==10)
            return "O11";
        if(x==14&&y==11)
            return "O12";
        if(x==14&&y==12)
            return "O13";
        if(x==14&&y==13)
            return "O14";
        if(x==14&&y==14)
            return "O15";

    }
    return "z";
}

coordenada MainWindow::generar_xy(string cord)
{
    coordenada cor;
    if(cord=="A1"){
        cor.x=0;
        cor.y=0;
    }
    if(cord=="A2"){
        cor.x=0;
        cor.y=1;
    }
    if(cord=="A3"){
        cor.x=0;
        cor.y=2;
    }
    if(cord=="A4"){
        cor.x=0;
        cor.y=3;
    }
    if(cord=="A5"){
        cor.x=0;
        cor.y=4;
    }
    if(cord=="A6"){
        cor.x=0;
        cor.y=5;
    }
    if(cord=="A7"){
        cor.x=0;
        cor.y=6;
    }
    if(cord=="A8"){
        cor.x=0;
        cor.y=7;
    }
    if(cord=="A9"){
        cor.x=0;
        cor.y=8;
    }
    if(cord=="A10"){
        cor.x=0;
        cor.y=9;
    }
    if(cord=="A11"){
        cor.x=0;
        cor.y=10;
    }
    if(cord=="A12"){
        cor.x=0;
        cor.y=11;
    }
    if(cord=="A13"){
        cor.x=0;
        cor.y=12;
    }
    if(cord=="A14"){
        cor.x=0;
        cor.y=13;
    }
    if(cord=="A15"){
        cor.x=0;
        cor.y=14;
    }

    if(cord=="B1"){
        cor.x=1;
        cor.y=0;
    }
    if(cord=="B2"){
        cor.x=1;
        cor.y=1;
    }
    if(cord=="B3"){
        cor.x=1;
        cor.y=2;
    }
    if(cord=="B4"){
        cor.x=1;
        cor.y=3;
    }
    if(cord=="B5"){
        cor.x=1;
        cor.y=4;
    }
    if(cord=="B6"){
        cor.x=1;
        cor.y=5;
    }
    if(cord=="B7"){
        cor.x=1;
        cor.y=6;
    }
    if(cord=="B8"){
        cor.x=1;
        cor.y=7;
    }
    if(cord=="B9"){
        cor.x=1;
        cor.y=8;
    }
    if(cord=="B10"){
        cor.x=1;
        cor.y=9;
    }
    if(cord=="B11"){
        cor.x=1;
        cor.y=10;
    }
    if(cord=="B12"){
        cor.x=1;
        cor.y=11;
    }
    if(cord=="B13"){
        cor.x=1;
        cor.y=12;
    }
    if(cord=="B14"){
        cor.x=1;
        cor.y=13;
    }
    if(cord=="B15"){
        cor.x=1;
        cor.y=14;
    }

    if(cord=="C1"){
        cor.x=2;
        cor.y=0;
    }
    if(cord=="C2"){
        cor.x=2;
        cor.y=1;
    }
    if(cord=="C3"){
        cor.x=2;
        cor.y=2;
    }
    if(cord=="C4"){
        cor.x=2;
        cor.y=3;
    }
    if(cord=="C5"){
        cor.x=2;
        cor.y=4;
    }
    if(cord=="C6"){
        cor.x=2;
        cor.y=5;
    }
    if(cord=="C7"){
        cor.x=2;
        cor.y=6;
    }
    if(cord=="C8"){
        cor.x=2;
        cor.y=7;
    }
    if(cord=="C9"){
        cor.x=2;
        cor.y=8;
    }
    if(cord=="C10"){
        cor.x=2;
        cor.y=9;
    }
    if(cord=="C11"){
        cor.x=2;
        cor.y=10;
    }
    if(cord=="C12"){
        cor.x=2;
        cor.y=11;
    }
    if(cord=="C13"){
        cor.x=2;
        cor.y=12;
    }
    if(cord=="C14"){
        cor.x=2;
        cor.y=13;
    }
    if(cord=="C15"){
        cor.x=2;
        cor.y=14;
    }

    if(cord=="D1"){
        cor.x=3;
        cor.y=0;
    }
    if(cord=="D2"){
        cor.x=3;
        cor.y=1;
    }
    if(cord=="D3"){
        cor.x=3;
        cor.y=2;
    }
    if(cord=="D4"){
        cor.x=3;
        cor.y=3;
    }
    if(cord=="D5"){
        cor.x=3;
        cor.y=4;
    }
    if(cord=="D6"){
        cor.x=3;
        cor.y=5;
    }
    if(cord=="D7"){
        cor.x=3;
        cor.y=6;
    }
    if(cord=="D8"){
        cor.x=3;
        cor.y=7;
    }
    if(cord=="D9"){
        cor.x=3;
        cor.y=8;
    }
    if(cord=="D10"){
        cor.x=3;
        cor.y=9;
    }
    if(cord=="D11"){
        cor.x=3;
        cor.y=10;
    }
    if(cord=="D12"){
        cor.x=3;
        cor.y=11;
    }
    if(cord=="D13"){
        cor.x=3;
        cor.y=12;
    }
    if(cord=="D14"){
        cor.x=3;
        cor.y=13;
    }
    if(cord=="D15"){
        cor.x=3;
        cor.y=14;
    }

    if(cord=="E1"){
        cor.x=4;
        cor.y=0;
    }
    if(cord=="E2"){
        cor.x=4;
        cor.y=1;
    }
    if(cord=="E3"){
        cor.x=4;
        cor.y=2;
    }
    if(cord=="E4"){
        cor.x=4;
        cor.y=3;
    }
    if(cord=="E5"){
        cor.x=4;
        cor.y=4;
    }
    if(cord=="E6"){
        cor.x=4;
        cor.y=5;
    }
    if(cord=="E7"){
        cor.x=4;
        cor.y=6;
    }
    if(cord=="E8"){
        cor.x=4;
        cor.y=7;
    }
    if(cord=="E9"){
        cor.x=4;
        cor.y=8;
    }
    if(cord=="E10"){
        cor.x=4;
        cor.y=9;
    }
    if(cord=="E11"){
        cor.x=4;
        cor.y=10;
    }
    if(cord=="E12"){
        cor.x=4;
        cor.y=11;
    }
    if(cord=="E13"){
        cor.x=4;
        cor.y=12;
    }
    if(cord=="E14"){
        cor.x=4;
        cor.y=13;
    }
    if(cord=="E15"){
        cor.x=4;
        cor.y=14;
    }

    if(cord=="F1"){
        cor.x=5;
        cor.y=0;
    }
    if(cord=="F2"){
        cor.x=5;
        cor.y=1;
    }
    if(cord=="F3"){
        cor.x=5;
        cor.y=2;
    }
    if(cord=="F4"){
        cor.x=5;
        cor.y=3;
    }
    if(cord=="F5"){
        cor.x=5;
        cor.y=4;
    }
    if(cord=="F6"){
        cor.x=5;
        cor.y=5;
    }
    if(cord=="F7"){
        cor.x=5;
        cor.y=6;
    }
    if(cord=="F8"){
        cor.x=5;
        cor.y=7;
    }
    if(cord=="F9"){
        cor.x=5;
        cor.y=8;
    }
    if(cord=="F10"){
        cor.x=5;
        cor.y=9;
    }
    if(cord=="F11"){
        cor.x=5;
        cor.y=10;
    }
    if(cord=="F12"){
        cor.x=5;
        cor.y=11;
    }
    if(cord=="F13"){
        cor.x=5;
        cor.y=12;
    }
    if(cord=="F14"){
        cor.x=5;
        cor.y=13;
    }
    if(cord=="F15"){
        cor.x=5;
        cor.y=14;
    }

    if(cord=="G1"){
        cor.x=6;
        cor.y=0;
    }
    if(cord=="G2"){
        cor.x=6;
        cor.y=1;
    }
    if(cord=="G3"){
        cor.x=6;
        cor.y=2;
    }
    if(cord=="G4"){
        cor.x=6;
        cor.y=3;
    }
    if(cord=="G5"){
        cor.x=6;
        cor.y=4;
    }
    if(cord=="G6"){
        cor.x=6;
        cor.y=5;
    }
    if(cord=="G7"){
        cor.x=6;
        cor.y=6;
    }
    if(cord=="G8"){
        cor.x=6;
        cor.y=7;
    }
    if(cord=="G9"){
        cor.x=6;
        cor.y=8;
    }
    if(cord=="G10"){
        cor.x=6;
        cor.y=9;
    }
    if(cord=="G11"){
        cor.x=6;
        cor.y=10;
    }
    if(cord=="G12"){
        cor.x=6;
        cor.y=11;
    }
    if(cord=="G13"){
        cor.x=6;
        cor.y=12;
    }
    if(cord=="G14"){
        cor.x=6;
        cor.y=13;
    }
    if(cord=="G15"){
        cor.x=6;
        cor.y=14;
    }

    if(cord=="H1"){
        cor.x=7;
        cor.y=0;
    }
    if(cord=="H2"){
        cor.x=7;
        cor.y=1;
    }
    if(cord=="H3"){
        cor.x=7;
        cor.y=2;
    }
    if(cord=="H4"){
        cor.x=7;
        cor.y=3;
    }
    if(cord=="H5"){
        cor.x=7;
        cor.y=4;
    }
    if(cord=="H6"){
        cor.x=7;
        cor.y=5;
    }
    if(cord=="H7"){
        cor.x=7;
        cor.y=6;
    }
    if(cord=="H8"){
        cor.x=7;
        cor.y=7;
    }
    if(cord=="H9"){
        cor.x=7;
        cor.y=8;
    }
    if(cord=="H10"){
        cor.x=7;
        cor.y=9;
    }
    if(cord=="H11"){
        cor.x=7;
        cor.y=10;
    }
    if(cord=="H12"){
        cor.x=7;
        cor.y=11;
    }
    if(cord=="H13"){
        cor.x=7;
        cor.y=12;
    }
    if(cord=="H14"){
        cor.x=7;
        cor.y=13;
    }
    if(cord=="H15"){
        cor.x=7;
        cor.y=14;
    }

    if(cord=="I1"){
        cor.x=8;
        cor.y=0;
    }
    if(cord=="I2"){
        cor.x=8;
        cor.y=1;
    }
    if(cord=="I3"){
        cor.x=8;
        cor.y=2;
    }
    if(cord=="I4"){
        cor.x=8;
        cor.y=3;
    }
    if(cord=="I5"){
        cor.x=8;
        cor.y=4;
    }
    if(cord=="I6"){
        cor.x=8;
        cor.y=5;
    }
    if(cord=="I7"){
        cor.x=8;
        cor.y=6;
    }
    if(cord=="I8"){
        cor.x=8;
        cor.y=7;
    }
    if(cord=="I9"){
        cor.x=8;
        cor.y=8;
    }
    if(cord=="I10"){
        cor.x=8;
        cor.y=9;
    }
    if(cord=="I11"){
        cor.x=8;
        cor.y=10;
    }
    if(cord=="I12"){
        cor.x=8;
        cor.y=11;
    }
    if(cord=="I13"){
        cor.x=8;
        cor.y=12;
    }
    if(cord=="I14"){
        cor.x=8;
        cor.y=13;
    }
    if(cord=="I15"){
        cor.x=8;
        cor.y=14;
    }

    if(cord=="J1"){
        cor.x=9;
        cor.y=0;
    }
    if(cord=="J2"){
        cor.x=9;
        cor.y=1;
    }
    if(cord=="J3"){
        cor.x=9;
        cor.y=2;
    }
    if(cord=="J4"){
        cor.x=9;
        cor.y=3;
    }
    if(cord=="J5"){
        cor.x=9;
        cor.y=4;
    }
    if(cord=="J6"){
        cor.x=9;
        cor.y=5;
    }
    if(cord=="J7"){
        cor.x=9;
        cor.y=6;
    }
    if(cord=="J8"){
        cor.x=9;
        cor.y=7;
    }
    if(cord=="J9"){
        cor.x=9;
        cor.y=8;
    }
    if(cord=="J10"){
        cor.x=9;
        cor.y=9;
    }
    if(cord=="J11"){
        cor.x=9;
        cor.y=10;
    }
    if(cord=="J12"){
        cor.x=9;
        cor.y=11;
    }
    if(cord=="J13"){
        cor.x=9;
        cor.y=12;
    }
    if(cord=="J14"){
        cor.x=9;
        cor.y=13;
    }
    if(cord=="J15"){
        cor.x=9;
        cor.y=14;
    }

    if(cord=="K1"){
        cor.x=10;
        cor.y=0;
    }
    if(cord=="K2"){
        cor.x=10;
        cor.y=1;
    }
    if(cord=="K3"){
        cor.x=10;
        cor.y=2;
    }
    if(cord=="K4"){
        cor.x=10;
        cor.y=3;
    }
    if(cord=="K5"){
        cor.x=10;
        cor.y=4;
    }
    if(cord=="K6"){
        cor.x=10;
        cor.y=5;
    }
    if(cord=="K7"){
        cor.x=10;
        cor.y=6;
    }
    if(cord=="K8"){
        cor.x=10;
        cor.y=7;
    }
    if(cord=="K9"){
        cor.x=10;
        cor.y=8;
    }
    if(cord=="K10"){
        cor.x=10;
        cor.y=9;
    }
    if(cord=="K11"){
        cor.x=10;
        cor.y=10;
    }
    if(cord=="K12"){
        cor.x=10;
        cor.y=11;
    }
    if(cord=="K13"){
        cor.x=10;
        cor.y=12;
    }
    if(cord=="K14"){
        cor.x=10;
        cor.y=13;
    }
    if(cord=="K15"){
        cor.x=10;
        cor.y=14;
    }

    if(cord=="L1"){
        cor.x=11;
        cor.y=0;
    }
    if(cord=="L2"){
        cor.x=11;
        cor.y=1;
    }
    if(cord=="L3"){
        cor.x=11;
        cor.y=2;
    }
    if(cord=="L4"){
        cor.x=11;
        cor.y=3;
    }
    if(cord=="L5"){
        cor.x=11;
        cor.y=4;
    }
    if(cord=="L6"){
        cor.x=11;
        cor.y=5;
    }
    if(cord=="L7"){
        cor.x=11;
        cor.y=6;
    }
    if(cord=="L8"){
        cor.x=11;
        cor.y=7;
    }
    if(cord=="L9"){
        cor.x=11;
        cor.y=8;
    }
    if(cord=="L10"){
        cor.x=11;
        cor.y=9;
    }
    if(cord=="L11"){
        cor.x=11;
        cor.y=10;
    }
    if(cord=="L12"){
        cor.x=11;
        cor.y=11;
    }
    if(cord=="L13"){
        cor.x=11;
        cor.y=12;
    }
    if(cord=="L14"){
        cor.x=11;
        cor.y=13;
    }
    if(cord=="L15"){
        cor.x=11;
        cor.y=14;
    }

    if(cord=="M1"){
        cor.x=12;
        cor.y=0;
    }
    if(cord=="M2"){
        cor.x=12;
        cor.y=1;
    }
    if(cord=="M3"){
        cor.x=12;
        cor.y=2;
    }
    if(cord=="M4"){
        cor.x=12;
        cor.y=3;
    }
    if(cord=="M5"){
        cor.x=12;
        cor.y=4;
    }
    if(cord=="M6"){
        cor.x=12;
        cor.y=5;
    }
    if(cord=="M7"){
        cor.x=12;
        cor.y=6;
    }
    if(cord=="M8"){
        cor.x=12;
        cor.y=7;
    }
    if(cord=="M9"){
        cor.x=12;
        cor.y=8;
    }
    if(cord=="M10"){
        cor.x=12;
        cor.y=9;
    }
    if(cord=="M11"){
        cor.x=12;
        cor.y=10;
    }
    if(cord=="M12"){
        cor.x=12;
        cor.y=11;
    }
    if(cord=="M13"){
        cor.x=12;
        cor.y=12;
    }
    if(cord=="M14"){
        cor.x=12;
        cor.y=13;
    }
    if(cord=="M15"){
        cor.x=12;
        cor.y=14;
    }

    if(cord=="N1"){
        cor.x=13;
        cor.y=0;
    }
    if(cord=="N2"){
        cor.x=13;
        cor.y=1;
    }
    if(cord=="N3"){
        cor.x=13;
        cor.y=2;
    }
    if(cord=="N4"){
        cor.x=13;
        cor.y=3;
    }
    if(cord=="N5"){
        cor.x=13;
        cor.y=4;
    }
    if(cord=="N6"){
        cor.x=13;
        cor.y=5;
    }
    if(cord=="N7"){
        cor.x=13;
        cor.y=6;
    }
    if(cord=="N8"){
        cor.x=13;
        cor.y=7;
    }
    if(cord=="N9"){
        cor.x=13;
        cor.y=8;
    }
    if(cord=="N10"){
        cor.x=13;
        cor.y=9;
    }
    if(cord=="N11"){
        cor.x=13;
        cor.y=10;
    }
    if(cord=="N12"){
        cor.x=13;
        cor.y=11;
    }
    if(cord=="N13"){
        cor.x=13;
        cor.y=12;
    }
    if(cord=="N14"){
        cor.x=13;
        cor.y=13;
    }
    if(cord=="N15"){
        cor.x=13;
        cor.y=14;
    }

    if(cord=="O1"){
        cor.x=14;
        cor.y=0;
    }
    if(cord=="O2"){
        cor.x=14;
        cor.y=1;
    }
    if(cord=="O3"){
        cor.x=14;
        cor.y=2;
    }
    if(cord=="O4"){
        cor.x=14;
        cor.y=3;
    }
    if(cord=="O5"){
        cor.x=14;
        cor.y=4;
    }
    if(cord=="O6"){
        cor.x=14;
        cor.y=5;
    }
    if(cord=="O7"){
        cor.x=14;
        cor.y=6;
    }
    if(cord=="O8"){
        cor.x=14;
        cor.y=7;
    }
    if(cord=="O9"){
        cor.x=14;
        cor.y=8;
    }
    if(cord=="O10"){
        cor.x=14;
        cor.y=9;
    }
    if(cord=="O11"){
        cor.x=14;
        cor.y=10;
    }
    if(cord=="O12"){
        cor.x=14;
        cor.y=11;
    }
    if(cord=="O13"){
        cor.x=14;
        cor.y=12;
    }
    if(cord=="O14"){
        cor.x=14;
        cor.y=13;
    }
    if(cord=="O15"){
        cor.x=14;
        cor.y=14;
    }

    return cor;
}


void MainWindow::on_pb_arriba_clicked()
{
    ui->pb_arriba->setDisabled(true);
    prioridad.push_back("a");
    ui->lb_orden_1->setText(QString::number(orden));
    orden++;
}

void MainWindow::on_pb_abajo_clicked()
{
    ui->pb_abajo->setDisabled(true);
    prioridad.push_back("b");
    ui->lb_orden_2->setText(QString::number(orden));
    orden++;
}

void MainWindow::on_pb_izquierda_clicked()
{
    ui->pb_izquierda->setDisabled(true);
    prioridad.push_back("i");
    ui->lb_orden_3->setText(QString::number(orden));
    orden++;
}

void MainWindow::on_pb_derecha_clicked()
{
    ui->pb_derecha->setDisabled(true);
    prioridad.push_back("d");
    ui->lb_orden_4->setText(QString::number(orden));
    orden++;
}

void MainWindow::on_pb_reiniciar_clicked()
{
    MainWindow *w=new MainWindow;
    this->close();
    w->show();
}

void MainWindow::on_pb_cerrar_clicked()
{
    this->close();
}
void MainWindow::insertar_en_pila(nodo hijo){
    nodo aux;
    if(marbol.size()==0){
        marbol.push_back(hijo);
    }

    else{
        marbol.push_back(hijo);
        for(unsigned int i=marbol.size()-1; i>0;i--){
            if(marbol[i-1].cordenada==marbol[i].padre){
                break;
            }
            else{
                aux=marbol[i-1];
                marbol[i-1]=marbol[i];
                marbol[i]=aux;
            }
        }

    }
    pilaback.push_back(hijo);
}

void MainWindow::colorido(int color)
{
    if(color==0||color==10||color==20||color==30||color==40||color==50||color==60||color==70||color==80||color==90||color==100||
            color==110||color==120||color==130)ui->plainTextEdit->setTextColor(QColor("red"));

    if(color==1||color==11||color==21||color==31||color==41||color==51||color==61||color==71||color==81||color==91||color==101||
            color==111||color==121||color==131)ui->plainTextEdit->setTextColor(QColor("blue"));

    if(color==2||color==12||color==22||color==32||color==42||color==52||color==62||color==72||color==82||color==92||color==102||
            color==112||color==122||color==132)ui->plainTextEdit->setTextColor(QColor("green"));

    if(color==3||color==13||color==23||color==33||color==43||color==53||color==63||color==73||color==83||color==93||color==103||
            color==113||color==123||color==133)ui->plainTextEdit->setTextColor(QColor("yellow"));

    if(color==4||color==14||color==24||color==34||color==44||color==54||color==64||color==74||color==84||color==94||color==104||
            color==114||color==124||color==134)ui->plainTextEdit->setTextColor(QColor("brown"));

    if(color==5||color==15||color==25||color==35||color==45||color==55||color==65||color==75||color==85||color==95||color==105||
            color==115||color==125||color==135)ui->plainTextEdit->setTextColor(QColor("pink"));

    if(color==6||color==16||color==26||color==36||color==46||color==56||color==66||color==76||color==86||color==96||color==106||
            color==116||color==126||color==136)ui->plainTextEdit->setTextColor(QColor("purple"));

    if(color==7||color==17||color==27||color==37||color==47||color==57||color==67||color==77||color==87||color==97||color==107||
            color==117||color==127||color==137)ui->plainTextEdit->setTextColor(QColor("orange"));

    if(color==8||color==18||color==28||color==38||color==48||color==58||color==68||color==78||color==88||color==98||color==108||
            color==118||color==128||color==138)ui->plainTextEdit->setTextColor(QColor("white"));

    if(color==9||color==19||color==29||color==39||color==49||color==59||color==69||color==79||color==99||color==99||color==109||
            color==119||color==129||color==139)ui->plainTextEdit->setTextColor(QColor("cyan"));

}

void MainWindow::mostrar_arbol()
{
    ui->plainTextEdit->clear();
    for(unsigned int i=0; i<marbol.size();i++){
        colorido(marbol[i].color);

        QString men=QString::fromStdString(marbol[i].tab)+QString::fromStdString(marbol[i].cordenada)+"  ";
        ui->plainTextEdit->insertPlainText(men);
        men="";

        for(unsigned int j=0; j<marbol[i].orden_visita.size(); j++){
            if(j==marbol[i].orden_visita.size()-1){
                ui->plainTextEdit->setTextColor(QColor("black"));
                men+=QString::number(marbol[i].orden_visita[j]);
            }
            else{
                men+=QString::number(marbol[i].orden_visita[j])+", ";
            }

        }
        ui->plainTextEdit->insertPlainText(men);
        ui->plainTextEdit->insertPlainText("\n");
    }
    ui->plainTextEdit->setTextColor(QColor("black"));
}

void MainWindow::on_pushButton_3_clicked()
{
    switch(algoritmo){
    case 1: mostrar_arbol();
        break;
    case 2: mostrar_arbol();
        break;
    case 3: mostrar_arbol();
        break;
    case 4: mostrar_voraz();
        break;
    case 5: mostrar_distancia();
        break;
    case 6://mostrar A*
        mostrar_A();
        break;
    }


}

bool MainWindow::existe_hijo(string xy){
    if(xy==generar_coordenada(final.x,final.y))
        return true;
    for(unsigned int i=0; i<marbol.size(); i++){
        if(xy==marbol[i].cordenada){
            return false;
        }
    }

    return true;
}

nodo MainWindow::buscar_padre(string xy){
    nodo padre;
    padre.cordenada="z";
    if(xy!="NA"){
        for(unsigned int i = 0; i<pilaback.size(); i++){
            if(xy==pilaback[i].cordenada){
                return pilaback[i];
            }
        }
    }
    return padre;
}

bool MainWindow::expandir(int x, int y, string letra)
{
    nodo hijo;
    personaje per;
    for(unsigned int i=0; i<persona.size(); i++){
        if(persona[i].estado==1){
            per=persona[i];
            break;
        }
    }

    if(letra=="d"||letra=="D"){
        if(y<14){

            if(validar_campo(campo[x][y+1],per)){

                string cor=generar_coordenada(x,y+1);
                if(cor!="z"){
                    if(existe_hijo(cor)){
                        nodo padre=buscar_padre(generar_coordenada(x,y));
                        if(padre.cordenada!="z"){
                            hijo.cordenada=cor;
                            hijo.estado="abierto";
                            hijo.color=padre.color+1;
                            hijo.otro="";
                            hijo.padre=padre.cordenada;
                            hijo.tab=padre.tab+"    ";
                            insertar_en_pila(hijo);
                            return true;
                        }

                    }
                }
            }
        }
    }
    if(letra=="a"||letra=="A"){
        if(y>0){
            if(validar_campo(campo[x][y-1],per)){
                string cor=generar_coordenada(x,y-1);
                if(cor!="z"){
                    if(existe_hijo(cor)){
                        nodo padre=buscar_padre(generar_coordenada(x,y));
                        if(padre.cordenada!="z"){
                            hijo.cordenada=cor;
                            hijo.estado="abierto";
                            hijo.color=padre.color+1;
                            hijo.otro="";
                            hijo.padre=padre.cordenada;
                            hijo.tab=padre.tab+"    ";
                            insertar_en_pila(hijo);
                            return true;
                        }


                    }
                }
            }
        }
    }
    if(letra=="s"||letra=="S"){
        if(x<14){
            if(validar_campo(campo[x+1][y],per)){
                string cor=generar_coordenada(x+1,y);
                if(cor!="z"){
                    if(existe_hijo(cor)){
                        nodo padre=buscar_padre(generar_coordenada(x,y));
                        if(padre.cordenada!="z"){
                            hijo.cordenada=cor;
                            hijo.estado="abierto";
                            hijo.color=padre.color+1;
                            hijo.otro="";
                            hijo.padre=padre.cordenada;
                            hijo.tab=padre.tab+"    ";
                            insertar_en_pila(hijo);
                            return true;
                        }
                    }
                }
            }
        }
    }
    if(letra=="w"||letra=="W"){
        if(x>0){
            if(validar_campo(campo[x-1][y],per)){
                string cor=generar_coordenada(x-1,y);
                if(cor!="z"){
                    if(existe_hijo(cor)){
                        nodo padre=buscar_padre(generar_coordenada(x,y));
                        if(padre.cordenada!="z"){
                            hijo.cordenada=cor;
                            hijo.estado="abierto";
                            hijo.color=padre.color+1;
                            hijo.otro="";
                            hijo.padre=padre.cordenada;
                            hijo.tab=padre.tab+"    ";
                            insertar_en_pila(hijo);
                            return true;
                        }
                    }
                }
            }
        }
    }
    return false;

}

bool MainWindow::mover2(string letra)
{
    personaje per;
    coordenada f;
    f.x=20;
    f.y=20;
    for(unsigned int i=0; i<persona.size(); i++){
        if(persona[i].estado==1){
            per=persona[i];
            break;
        }
    }

    if(activo==0){

        if(letra=="w"||letra=="W"){
            if(cordenada.x>0){
                if(validar_campo(campo[cordenada.x-1][cordenada.y],per)){
                    mover(cordenada.x,cordenada.y,cordenada.x-1,cordenada.y,cordenada.nombre);
                    cordenada.x--;
                    desbloquear(cordenada.x, cordenada.y,f);

                    if(final.x==cordenada.x && final.y==cordenada.y){

                        activo=1;

                        on_pushButton_3_clicked();
                    }
                    return true;

                }
            }
        }
        else if(letra=="s"||letra=="S"){
            if(cordenada.x<14){
                if(validar_campo(campo[cordenada.x+1][cordenada.y],per)){
                    mover(cordenada.x,cordenada.y,cordenada.x+1,cordenada.y,cordenada.nombre);
                    cordenada.x++;
                    desbloquear(cordenada.x, cordenada.y,f);


                    if(final.x==cordenada.x && final.y==cordenada.y){

                        activo=1;

                        on_pushButton_3_clicked();
                    }
                    return true;
                }
            }
        }
        else if(letra=="a"||letra=="A"){
            if(cordenada.y>0){
                if(validar_campo(campo[cordenada.x][cordenada.y-1],per)){
                    mover(cordenada.x,cordenada.y,cordenada.x,cordenada.y-1,cordenada.nombre);
                    cordenada.y--;
                    desbloquear(cordenada.x, cordenada.y,f);


                    if(final.x==cordenada.x && final.y==cordenada.y){

                        activo=1;

                        on_pushButton_3_clicked();
                    }
                    return true;
                }
            }
        }
        else if(letra=="d"||letra=="D"){
            if(cordenada.y<14){
                if(validar_campo(campo[cordenada.x][cordenada.y+1],per)){
                    mover(cordenada.x,cordenada.y,cordenada.x,cordenada.y+1,cordenada.nombre);
                    cordenada.y++;

                    desbloquear(cordenada.x,cordenada.y,f);

                    if(final.x==cordenada.x && final.y==cordenada.y){

                        activo=1;

                        on_pushButton_3_clicked();
                    }
                    return true;
                }
            }
        }
    }
    return false;
}

void MainWindow::backtracking(){

    string orden=prioridad[0]+prioridad[1]+prioridad[2]+prioridad[3];

    while(true){
        if(pilaback.size()>0){
            visitas(pilaback[pilaback.size()-1],num_visita);
            num_visita++;
            on_pushButton_3_clicked();
            QTime dieTime= QTime::currentTime().addSecs(1);
            while (QTime::currentTime() < dieTime)
                QCoreApplication::processEvents(QEventLoop::AllEvents,1);
            bool bandera=false;
            if(orden=="abid"){
                if(bandera==false){
                    if(expandir(cordenada.x,cordenada.y,"W")==true){
                        if(mover2("W")){
                            bandera=true;
                        }
                    }
                }
                if(bandera==false){
                    if(expandir(cordenada.x,cordenada.y,"S")==true){
                        if(mover2("S")){
                            bandera=true;
                        }
                    }
                }
                if(bandera==false){
                    if(expandir(cordenada.x,cordenada.y,"A")==true){
                        if(mover2("A")){
                            bandera=true;
                        }
                    }
                }
                if(bandera==false){
                    if(expandir(cordenada.x,cordenada.y,"D")==true){
                        if(mover2("D")){
                            bandera=true;
                        }
                    }
                }
            }

            if(orden=="abdi"){
                if(bandera==false){
                    if(expandir(cordenada.x,cordenada.y,"W")==true){
                        if(mover2("W")){
                            bandera=true;
                        }
                    }
                }
                if(bandera==false){
                    if(expandir(cordenada.x,cordenada.y,"S")==true){
                        if(mover2("S")){
                            bandera=true;
                        }
                    }
                }
                if(bandera==false){
                    if(expandir(cordenada.x,cordenada.y,"D")==true){
                        if(mover2("D")){
                            bandera=true;
                        }
                    }
                }
                if(bandera==false){
                    if(expandir(cordenada.x,cordenada.y,"A")==true){
                        if(mover2("A")){
                            bandera=true;
                        }
                    }
                }
            }
            if(orden=="aidb"){
                if(bandera==false){
                    if(expandir(cordenada.x,cordenada.y,"W")==true){
                        if(mover2("W")){
                            bandera=true;
                        }
                    }
                }
                if(bandera==false){
                    if(expandir(cordenada.x,cordenada.y,"A")==true){
                        if(mover2("A")){
                            bandera=true;
                        }
                    }
                }
                if(bandera==false){
                    if(expandir(cordenada.x,cordenada.y,"D")==true){
                        if(mover2("D")){
                            bandera=true;
                        }
                    }
                }
                if(bandera==false){
                    if(expandir(cordenada.x,cordenada.y,"S")==true){
                        if(mover2("S")){
                            bandera=true;
                        }
                    }
                }
            }
            if(orden=="aibd"){
                if(bandera==false){
                    if(expandir(cordenada.x,cordenada.y,"W")==true){
                        if(mover2("W")){
                            bandera=true;
                        }
                    }
                }
                if(bandera==false){
                    if(expandir(cordenada.x,cordenada.y,"A")==true){
                        if(mover2("A")){
                            bandera=true;
                        }
                    }
                }
                if(bandera==false){
                    if(expandir(cordenada.x,cordenada.y,"S")==true){
                        if(mover2("S")){
                            bandera=true;
                        }
                    }
                }
                if(bandera==false){
                    if(expandir(cordenada.x,cordenada.y,"D")==true){
                        if(mover2("D")){
                            bandera=true;
                        }
                    }
                }
            }
            if(orden=="adbi"){
                if(bandera==false){
                    if(expandir(cordenada.x,cordenada.y,"W")==true){
                        if(mover2("W")){
                            bandera=true;
                        }
                    }
                }
                if(bandera==false){
                    if(expandir(cordenada.x,cordenada.y,"D")==true){
                        if(mover2("D")){
                            bandera=true;
                        }
                    }
                }
                if(bandera==false){
                    if(expandir(cordenada.x,cordenada.y,"S")==true){
                        if(mover2("S")){
                            bandera=true;
                        }
                    }
                }
                if(bandera==false){
                    if(expandir(cordenada.x,cordenada.y,"A")==true){
                        if(mover2("A")){
                            bandera=true;
                        }
                    }
                }
            }
            if(orden=="adib"){
                if(bandera==false){
                    if(expandir(cordenada.x,cordenada.y,"W")==true){
                        if(mover2("W")){
                            bandera=true;
                        }
                    }
                }
                if(bandera==false){
                    if(expandir(cordenada.x,cordenada.y,"D")==true){
                        if(mover2("D")){
                            bandera=true;
                        }
                    }
                }
                if(bandera==false){
                    if(expandir(cordenada.x,cordenada.y,"A")==true){
                        if(mover2("A")){
                            bandera=true;
                        }
                    }
                }
                if(bandera==false){
                    if(expandir(cordenada.x,cordenada.y,"S")==true){
                        if(mover2("S")){
                            bandera=true;
                        }
                    }
                }
            }

            if(orden=="baid"){
                if(bandera==false){
                    if(expandir(cordenada.x,cordenada.y,"S")==true){
                        if(mover2("S")){
                            bandera=true;
                        }
                    }
                }
                if(bandera==false){
                    if(expandir(cordenada.x,cordenada.y,"W")==true){
                        if(mover2("W")){
                            bandera=true;
                        }
                    }
                }
                if(bandera==false){
                    if(expandir(cordenada.x,cordenada.y,"A")==true){
                        if(mover2("A")){
                            bandera=true;
                        }
                    }
                }
                if(bandera==false){
                    if(expandir(cordenada.x,cordenada.y,"D")==true){
                        if(mover2("D")){
                            bandera=true;
                        }
                    }
                }
            }
            if(orden=="badi"){
                if(bandera==false){
                    if(expandir(cordenada.x,cordenada.y,"S")==true){
                        if(mover2("S")){
                            bandera=true;
                        }
                    }
                }
                if(bandera==false){
                    if(expandir(cordenada.x,cordenada.y,"W")==true){
                        if(mover2("W")){
                            bandera=true;
                        }
                    }
                }
                if(bandera==false){
                    if(expandir(cordenada.x,cordenada.y,"D")==true){
                        if(mover2("D")){
                            bandera=true;
                        }
                    }
                }
                if(bandera==false){
                    if(expandir(cordenada.x,cordenada.y,"A")==true){
                        if(mover2("A")){
                            bandera=true;
                        }
                    }
                }
            }
            if(orden=="biad"){
                if(bandera==false){
                    if(expandir(cordenada.x,cordenada.y,"S")==true){
                        if(mover2("S")){
                            bandera=true;
                        }
                    }
                }
                if(bandera==false){
                    if(expandir(cordenada.x,cordenada.y,"A")==true){
                        if(mover2("A")){
                            bandera=true;
                        }
                    }
                }
                if(bandera==false){
                    if(expandir(cordenada.x,cordenada.y,"W")==true){
                        if(mover2("W")){
                            bandera=true;
                        }
                    }
                }
                if(bandera==false){
                    if(expandir(cordenada.x,cordenada.y,"D")==true){
                        if(mover2("D")){
                            bandera=true;
                        }
                    }
                }
            }
            if(orden=="bida"){
                if(bandera==false){
                    if(expandir(cordenada.x,cordenada.y,"S")==true){
                        if(mover2("S")){
                            bandera=true;
                        }
                    }
                }
                if(bandera==false){
                    if(expandir(cordenada.x,cordenada.y,"A")==true){
                        if(mover2("A")){
                            bandera=true;
                        }
                    }
                }
                if(bandera==false){
                    if(expandir(cordenada.x,cordenada.y,"D")==true){
                        if(mover2("D")){
                            bandera=true;
                        }
                    }
                }
                if(bandera==false){
                    if(expandir(cordenada.x,cordenada.y,"W")==true){
                        if(mover2("W")){
                            bandera=true;
                        }
                    }
                }
            }
            if(orden=="bdai"){
                if(bandera==false){
                    if(expandir(cordenada.x,cordenada.y,"S")==true){
                        if(mover2("S")){
                            bandera=true;
                        }
                    }
                }
                if(bandera==false){
                    if(expandir(cordenada.x,cordenada.y,"D")==true){
                        if(mover2("D")){
                            bandera=true;
                        }
                    }
                }
                if(bandera==false){
                    if(expandir(cordenada.x,cordenada.y,"W")==true){
                        if(mover2("W")){
                            bandera=true;
                        }
                    }
                }
                if(bandera==false){
                    if(expandir(cordenada.x,cordenada.y,"A")==true){
                        if(mover2("A")){
                            bandera=true;
                        }
                    }
                }
            }
            if(orden=="bdia"){
                if(bandera==false){
                    if(expandir(cordenada.x,cordenada.y,"S")==true){
                        if(mover2("S")){
                            bandera=true;
                        }
                    }
                }
                if(bandera==false){
                    if(expandir(cordenada.x,cordenada.y,"D")==true){
                        if(mover2("D")){
                            bandera=true;
                        }
                    }
                }
                if(bandera==false){
                    if(expandir(cordenada.x,cordenada.y,"A")==true){
                        if(mover2("A")){
                            bandera=true;
                        }
                    }
                }
                if(bandera==false){
                    if(expandir(cordenada.x,cordenada.y,"W")==true){
                        if(mover2("W")){
                            bandera=true;
                        }
                    }
                }
            }
            //////////////////
            if(orden=="iadb"){
                if(bandera==false){
                    if(expandir(cordenada.x,cordenada.y,"A")==true){
                        if(mover2("A")){
                            bandera=true;
                        }
                    }
                }
                if(bandera==false){
                    if(expandir(cordenada.x,cordenada.y,"W")==true){
                        if(mover2("W")){
                            bandera=true;
                        }
                    }
                }
                if(bandera==false){
                    if(expandir(cordenada.x,cordenada.y,"D")==true){
                        if(mover2("D")){
                            bandera=true;
                        }
                    }
                }
                if(bandera==false){
                    if(expandir(cordenada.x,cordenada.y,"S")==true){
                        if(mover2("S")){
                            bandera=true;
                        }
                    }
                }
            }
            if(orden=="iabd"){
                if(bandera==false){
                    if(expandir(cordenada.x,cordenada.y,"A")==true){
                        if(mover2("A")){
                            bandera=true;
                        }
                    }
                }
                if(bandera==false){
                    if(expandir(cordenada.x,cordenada.y,"W")==true){
                        if(mover2("W")){
                            bandera=true;
                        }
                    }
                }
                if(bandera==false){
                    if(expandir(cordenada.x,cordenada.y,"S")==true){
                        if(mover2("S")){
                            bandera=true;
                        }
                    }
                }
                if(bandera==false){
                    if(expandir(cordenada.x,cordenada.y,"D")==true){
                        if(mover2("D")){
                            bandera=true;
                        }
                    }
                }
            }
            if(orden=="idab"){
                if(bandera==false){
                    if(expandir(cordenada.x,cordenada.y,"A")==true){
                        if(mover2("A")){
                            bandera=true;
                        }
                    }
                }
                if(bandera==false){
                    if(expandir(cordenada.x,cordenada.y,"D")==true){
                        if(mover2("D")){
                            bandera=true;
                        }
                    }
                }
                if(bandera==false){
                    if(expandir(cordenada.x,cordenada.y,"W")==true){
                        if(mover2("W")){
                            bandera=true;
                        }
                    }
                }
                if(bandera==false){
                    if(expandir(cordenada.x,cordenada.y,"S")==true){
                        if(mover2("S")){
                            bandera=true;
                        }
                    }
                }
            }
            if(orden=="idba"){
                if(bandera==false){
                    if(expandir(cordenada.x,cordenada.y,"A")==true){
                        if(mover2("A")){
                            bandera=true;
                        }
                    }
                }
                if(bandera==false){
                    if(expandir(cordenada.x,cordenada.y,"D")==true){
                        if(mover2("D")){
                            bandera=true;
                        }
                    }
                }
                if(bandera==false){
                    if(expandir(cordenada.x,cordenada.y,"S")==true){
                        if(mover2("S")){
                            bandera=true;
                        }
                    }
                }
                if(bandera==false){
                    if(expandir(cordenada.x,cordenada.y,"W")==true){
                        if(mover2("W")){
                            bandera=true;
                        }
                    }
                }
            }
            if(orden=="ibda"){
                if(bandera==false){
                    if(expandir(cordenada.x,cordenada.y,"A")==true){
                        if(mover2("A")){
                            bandera=true;
                        }
                    }
                }
                if(bandera==false){
                    if(expandir(cordenada.x,cordenada.y,"S")==true){
                        if(mover2("S")){
                            bandera=true;
                        }
                    }
                }
                if(bandera==false){
                    if(expandir(cordenada.x,cordenada.y,"D")==true){
                        if(mover2("D")){
                            bandera=true;
                        }
                    }
                }
                if(bandera==false){
                    if(expandir(cordenada.x,cordenada.y,"W")==true){
                        if(mover2("W")){
                            bandera=true;
                        }
                    }
                }
            }
            if(orden=="ibad"){
                if(bandera==false){
                    if(expandir(cordenada.x,cordenada.y,"A")==true){
                        if(mover2("A")){
                            bandera=true;
                        }
                    }
                }
                if(bandera==false){
                    if(expandir(cordenada.x,cordenada.y,"S")==true){
                        if(mover2("S")){
                            bandera=true;
                        }
                    }
                }
                if(bandera==false){
                    if(expandir(cordenada.x,cordenada.y,"W")==true){
                        if(mover2("W")){
                            bandera=true;
                        }
                    }
                }
                if(bandera==false){
                    if(expandir(cordenada.x,cordenada.y,"D")==true){
                        if(mover2("D")){
                            bandera=true;
                        }
                    }
                }
            }
            /////////////
            if(orden=="dabi"){
                if(bandera==false){
                    if(expandir(cordenada.x,cordenada.y,"D")==true){
                        if(mover2("D")){
                            bandera=true;
                        }
                    }
                }
                if(bandera==false){
                    if(expandir(cordenada.x,cordenada.y,"W")==true){
                        if(mover2("W")){
                            bandera=true;
                        }
                    }
                }
                if(bandera==false){
                    if(expandir(cordenada.x,cordenada.y,"S")==true){
                        if(mover2("S")){
                            bandera=true;
                        }
                    }
                }
                if(bandera==false){
                    if(expandir(cordenada.x,cordenada.y,"A")==true){
                        if(mover2("A")){
                            bandera=true;
                        }
                    }
                }
            }
            if(orden=="daib"){
                if(bandera==false){
                    if(expandir(cordenada.x,cordenada.y,"D")==true){
                        if(mover2("D")){
                            bandera=true;
                        }
                    }
                }
                if(bandera==false){
                    if(expandir(cordenada.x,cordenada.y,"W")==true){
                        if(mover2("W")){
                            bandera=true;
                        }
                    }
                }
                if(bandera==false){
                    if(expandir(cordenada.x,cordenada.y,"A")==true){
                        if(mover2("A")){
                            bandera=true;
                        }
                    }
                }
                if(bandera==false){
                    if(expandir(cordenada.x,cordenada.y,"S")==true){
                        if(mover2("S")){
                            bandera=true;
                        }
                    }
                }
            }
            if(orden=="dbai"){
                if(bandera==false){
                    if(expandir(cordenada.x,cordenada.y,"D")==true){
                        if(mover2("D")){
                            bandera=true;
                        }
                    }
                }
                if(bandera==false){
                    if(expandir(cordenada.x,cordenada.y,"S")==true){
                        if(mover2("S")){
                            bandera=true;
                        }
                    }
                }
                if(bandera==false){
                    if(expandir(cordenada.x,cordenada.y,"W")==true){
                        if(mover2("W")){
                            bandera=true;
                        }
                    }
                }
                if(bandera==false){
                    if(expandir(cordenada.x,cordenada.y,"A")==true){
                        if(mover2("A")){
                            bandera=true;
                        }
                    }
                }
            }
            if(orden=="dbia"){
                if(bandera==false){
                    if(expandir(cordenada.x,cordenada.y,"D")==true){
                        if(mover2("D")){
                            bandera=true;
                        }
                    }
                }
                if(bandera==false){
                    if(expandir(cordenada.x,cordenada.y,"S")==true){
                        if(mover2("S")){
                            bandera=true;
                        }
                    }
                }
                if(bandera==false){
                    if(expandir(cordenada.x,cordenada.y,"A")==true){
                        if(mover2("A")){
                            bandera=true;
                        }
                    }
                }
                if(bandera==false){
                    if(expandir(cordenada.x,cordenada.y,"W")==true){
                        if(mover2("W")){
                            bandera=true;
                        }
                    }
                }
            }
            if(orden=="diba"){
                if(bandera==false){
                    if(expandir(cordenada.x,cordenada.y,"D")==true){
                        if(mover2("D")){
                            bandera=true;
                        }
                    }
                }
                if(bandera==false){
                    if(expandir(cordenada.x,cordenada.y,"A")==true){
                        if(mover2("A")){
                            bandera=true;
                        }
                    }
                }
                if(bandera==false){
                    if(expandir(cordenada.x,cordenada.y,"S")==true){
                        if(mover2("S")){
                            bandera=true;
                        }
                    }
                }
                if(bandera==false){
                    if(expandir(cordenada.x,cordenada.y,"W")==true){
                        if(mover2("W")){
                            bandera=true;
                        }
                    }
                }
            }
            if(orden=="diab"){
                if(bandera==false){
                    if(expandir(cordenada.x,cordenada.y,"D")==true){
                        if(mover2("D")){
                            bandera=true;
                        }
                    }
                }
                if(bandera==false){
                    if(expandir(cordenada.x,cordenada.y,"A")==true){
                        if(mover2("A")){
                            bandera=true;
                        }
                    }
                }
                if(bandera==false){
                    if(expandir(cordenada.x,cordenada.y,"W")==true){
                        if(mover2("W")){
                            bandera=true;
                        }
                    }
                }
                if(bandera==false){
                    if(expandir(cordenada.x,cordenada.y,"S")==true){
                        if(mover2("S")){
                            bandera=true;
                        }
                    }
                }
            }

            if(bandera==false){
                coordenada auxpadre, auxhijo;
                auxpadre=generar_xy(pilaback[pilaback.size()-1].padre);
                auxhijo=generar_xy(pilaback[pilaback.size()-1].cordenada);
                mover(auxhijo.x,auxhijo.y,auxpadre.x,auxpadre.y,cordenada.nombre);
                pilaback.pop_back();

                if(pilaback.size()>0){
                    string name=cordenada.nombre;
                    cordenada=generar_xy(pilaback[pilaback.size()-1].cordenada);
                    cordenada.nombre=name;
                }
            }

        }
        else {
            QMessageBox msg;
            activo=1;
            msg.setText("El algoritmo no encontro una solucion");
            msg.exec();
            correcto=false;
            break;
        }

        if(final.x==cordenada.x && final.y==cordenada.y){
            //qDebug()<<QString::number(final.y);
            correcto=true;
            visitas(buscar_padre_anchura(generar_coordenada(final.x,final.y)),num_visita);
            num_visita++;
            on_pushButton_3_clicked();
            activo=1;
            QMessageBox msg;
            msg.setText("Felicidades llego a su destino\nPara volver a recorrer el mapa presiona el boton reiniciar");
            msg.exec();
            validar_cordenada(final.x+1,final.y+1,campo[final.x][final.y].icono);
            on_pushButton_4_clicked();
            break;
        }

    }

}

void MainWindow::marcar_solucion(coordenada cor)
{
    int x=cor.x, y=cor.y;
    if(x==0){
        if(y==0)ui->A1->setEnabled(true);
        if(y==1)ui->A2->setEnabled(true);
        if(y==2)ui->A3->setEnabled(true);
        if(y==3)ui->A4->setEnabled(true);
        if(y==4)ui->A5->setEnabled(true);
        if(y==5)ui->A6->setEnabled(true);
        if(y==6)ui->A7->setEnabled(true);
        if(y==7)ui->A8->setEnabled(true);
        if(y==8)ui->A9->setEnabled(true);
        if(y==9)ui->A10->setEnabled(true);
        if(y==10)ui->A11->setEnabled(true);
        if(y==11)ui->A12->setEnabled(true);
        if(y==12)ui->A13->setEnabled(true);
        if(y==13)ui->A14->setEnabled(true);
        if(y==14)ui->A15->setEnabled(true);

    }
    if(x==1){
        if(y==0)ui->B1->setEnabled(true);
        if(y==1)ui->B2->setEnabled(true);
        if(y==2)ui->B3->setEnabled(true);
        if(y==3)ui->B4->setEnabled(true);
        if(y==4)ui->B5->setEnabled(true);
        if(y==5)ui->B6->setEnabled(true);
        if(y==6)ui->B7->setEnabled(true);
        if(y==7)ui->B8->setEnabled(true);
        if(y==8)ui->B9->setEnabled(true);
        if(y==9)ui->B10->setEnabled(true);
        if(y==10)ui->B11->setEnabled(true);
        if(y==11)ui->B12->setEnabled(true);
        if(y==12)ui->B13->setEnabled(true);
        if(y==13)ui->B14->setEnabled(true);
        if(y==14)ui->B15->setEnabled(true);

    }
    if(x==2){
        if(y==0)ui->C1->setEnabled(true);
        if(y==1)ui->C2->setEnabled(true);
        if(y==2)ui->C3->setEnabled(true);
        if(y==3)ui->C4->setEnabled(true);
        if(y==4)ui->C5->setEnabled(true);
        if(y==5)ui->C6->setEnabled(true);
        if(y==6)ui->C7->setEnabled(true);
        if(y==7)ui->C8->setEnabled(true);
        if(y==8)ui->C9->setEnabled(true);
        if(y==9)ui->C10->setEnabled(true);
        if(y==10)ui->C11->setEnabled(true);
        if(y==11)ui->C12->setEnabled(true);
        if(y==12)ui->C13->setEnabled(true);
        if(y==13)ui->C14->setEnabled(true);
        if(y==14)ui->C15->setEnabled(true);

    }
    if(x==3){
        if(y==0)ui->D1->setEnabled(true);
        if(y==1)ui->D2->setEnabled(true);
        if(y==2)ui->D3->setEnabled(true);
        if(y==3)ui->D4->setEnabled(true);
        if(y==4)ui->D5->setEnabled(true);
        if(y==5)ui->D6->setEnabled(true);
        if(y==6)ui->D7->setEnabled(true);
        if(y==7)ui->D8->setEnabled(true);
        if(y==8)ui->D9->setEnabled(true);
        if(y==9)ui->D10->setEnabled(true);
        if(y==10)ui->D11->setEnabled(true);
        if(y==11)ui->D12->setEnabled(true);
        if(y==12)ui->D13->setEnabled(true);
        if(y==13)ui->D14->setEnabled(true);
        if(y==14)ui->D15->setEnabled(true);

    }
    if(x==4){
        if(y==0)ui->E1->setEnabled(true);
        if(y==1)ui->E2->setEnabled(true);
        if(y==2)ui->E3->setEnabled(true);
        if(y==3)ui->E4->setEnabled(true);
        if(y==4)ui->E5->setEnabled(true);
        if(y==5)ui->E6->setEnabled(true);
        if(y==6)ui->E7->setEnabled(true);
        if(y==7)ui->E8->setEnabled(true);
        if(y==8)ui->E9->setEnabled(true);
        if(y==9)ui->E10->setEnabled(true);
        if(y==10)ui->E11->setEnabled(true);
        if(y==11)ui->E12->setEnabled(true);
        if(y==12)ui->E13->setEnabled(true);
        if(y==13)ui->E14->setEnabled(true);
        if(y==14)ui->E15->setEnabled(true);

    }
    if(x==5){
        if(y==0)ui->F1->setEnabled(true);
        if(y==1)ui->F2->setEnabled(true);
        if(y==2)ui->F3->setEnabled(true);
        if(y==3)ui->F4->setEnabled(true);
        if(y==4)ui->F5->setEnabled(true);
        if(y==5)ui->F6->setEnabled(true);
        if(y==6)ui->F7->setEnabled(true);
        if(y==7)ui->F8->setEnabled(true);
        if(y==8)ui->F9->setEnabled(true);
        if(y==9)ui->F10->setEnabled(true);
        if(y==10)ui->F11->setEnabled(true);
        if(y==11)ui->F12->setEnabled(true);
        if(y==12)ui->F13->setEnabled(true);
        if(y==13)ui->F14->setEnabled(true);
        if(y==14)ui->F15->setEnabled(true);

    }
    if(x==6){
        if(y==0)ui->G1->setEnabled(true);
        if(y==1)ui->G2->setEnabled(true);
        if(y==2)ui->G3->setEnabled(true);
        if(y==3)ui->G4->setEnabled(true);
        if(y==4)ui->G5->setEnabled(true);
        if(y==5)ui->G6->setEnabled(true);
        if(y==6)ui->G7->setEnabled(true);
        if(y==7)ui->G8->setEnabled(true);
        if(y==8)ui->G9->setEnabled(true);
        if(y==9)ui->G10->setEnabled(true);
        if(y==10)ui->G11->setEnabled(true);
        if(y==11)ui->G12->setEnabled(true);
        if(y==12)ui->G13->setEnabled(true);
        if(y==13)ui->G14->setEnabled(true);
        if(y==14)ui->G15->setEnabled(true);

    }
    if(x==7){
        if(y==0)ui->H1->setEnabled(true);
        if(y==1)ui->H2->setEnabled(true);
        if(y==2)ui->H3->setEnabled(true);
        if(y==3)ui->H4->setEnabled(true);
        if(y==4)ui->H5->setEnabled(true);
        if(y==5)ui->H6->setEnabled(true);
        if(y==6)ui->H7->setEnabled(true);
        if(y==7)ui->H8->setEnabled(true);
        if(y==8)ui->H9->setEnabled(true);
        if(y==9)ui->H10->setEnabled(true);
        if(y==10)ui->H11->setEnabled(true);
        if(y==11)ui->H12->setEnabled(true);
        if(y==12)ui->H13->setEnabled(true);
        if(y==13)ui->H14->setEnabled(true);
        if(y==14)ui->H15->setEnabled(true);

    }
    if(x==8){
        if(y==0)ui->I1->setEnabled(true);
        if(y==1)ui->I2->setEnabled(true);
        if(y==2)ui->I3->setEnabled(true);
        if(y==3)ui->I4->setEnabled(true);
        if(y==4)ui->I5->setEnabled(true);
        if(y==5)ui->I6->setEnabled(true);
        if(y==6)ui->I7->setEnabled(true);
        if(y==7)ui->I8->setEnabled(true);
        if(y==8)ui->I9->setEnabled(true);
        if(y==9)ui->I10->setEnabled(true);
        if(y==10)ui->I11->setEnabled(true);
        if(y==11)ui->I12->setEnabled(true);
        if(y==12)ui->I13->setEnabled(true);
        if(y==13)ui->I14->setEnabled(true);
        if(y==14)ui->I15->setEnabled(true);

    }
    if(x==9){
        if(y==0)ui->J1->setEnabled(true);
        if(y==1)ui->J2->setEnabled(true);
        if(y==2)ui->J3->setEnabled(true);
        if(y==3)ui->J4->setEnabled(true);
        if(y==4)ui->J5->setEnabled(true);
        if(y==5)ui->J6->setEnabled(true);
        if(y==6)ui->J7->setEnabled(true);
        if(y==7)ui->J8->setEnabled(true);
        if(y==8)ui->J9->setEnabled(true);
        if(y==9)ui->J10->setEnabled(true);
        if(y==10)ui->J11->setEnabled(true);
        if(y==11)ui->J12->setEnabled(true);
        if(y==12)ui->J13->setEnabled(true);
        if(y==13)ui->J14->setEnabled(true);
        if(y==14)ui->J15->setEnabled(true);

    }
    if(x==10){
        if(y==0)ui->K1->setEnabled(true);
        if(y==1)ui->K2->setEnabled(true);
        if(y==2)ui->K3->setEnabled(true);
        if(y==3)ui->K4->setEnabled(true);
        if(y==4)ui->K5->setEnabled(true);
        if(y==5)ui->K6->setEnabled(true);
        if(y==6)ui->K7->setEnabled(true);
        if(y==7)ui->K8->setEnabled(true);
        if(y==8)ui->K9->setEnabled(true);
        if(y==9)ui->K10->setEnabled(true);
        if(y==10)ui->K11->setEnabled(true);
        if(y==11)ui->K12->setEnabled(true);
        if(y==12)ui->K13->setEnabled(true);
        if(y==13)ui->K14->setEnabled(true);
        if(y==14)ui->K15->setEnabled(true);

    }
    if(x==11){
        if(y==0)ui->L1->setEnabled(true);
        if(y==1)ui->L2->setEnabled(true);
        if(y==2)ui->L3->setEnabled(true);
        if(y==3)ui->L4->setEnabled(true);
        if(y==4)ui->L5->setEnabled(true);
        if(y==5)ui->L6->setEnabled(true);
        if(y==6)ui->L7->setEnabled(true);
        if(y==7)ui->L8->setEnabled(true);
        if(y==8)ui->L9->setEnabled(true);
        if(y==9)ui->L10->setEnabled(true);
        if(y==10)ui->L11->setEnabled(true);
        if(y==11)ui->L12->setEnabled(true);
        if(y==12)ui->L13->setEnabled(true);
        if(y==13)ui->L14->setEnabled(true);
        if(y==14)ui->L15->setEnabled(true);

    }
    if(x==12){
        if(y==0)ui->M1->setEnabled(true);
        if(y==1)ui->M2->setEnabled(true);
        if(y==2)ui->M3->setEnabled(true);
        if(y==3)ui->M4->setEnabled(true);
        if(y==4)ui->M5->setEnabled(true);
        if(y==5)ui->M6->setEnabled(true);
        if(y==6)ui->M7->setEnabled(true);
        if(y==7)ui->M8->setEnabled(true);
        if(y==8)ui->M9->setEnabled(true);
        if(y==9)ui->M10->setEnabled(true);
        if(y==10)ui->M11->setEnabled(true);
        if(y==11)ui->M12->setEnabled(true);
        if(y==12)ui->M13->setEnabled(true);
        if(y==13)ui->M14->setEnabled(true);
        if(y==14)ui->M15->setEnabled(true);

    }
    if(x==13){
        if(y==0)ui->N1->setEnabled(true);
        if(y==1)ui->N2->setEnabled(true);
        if(y==2)ui->N3->setEnabled(true);
        if(y==3)ui->N4->setEnabled(true);
        if(y==4)ui->N5->setEnabled(true);
        if(y==5)ui->N6->setEnabled(true);
        if(y==6)ui->N7->setEnabled(true);
        if(y==7)ui->N8->setEnabled(true);
        if(y==8)ui->N9->setEnabled(true);
        if(y==9)ui->N10->setEnabled(true);
        if(y==10)ui->N11->setEnabled(true);
        if(y==11)ui->N12->setEnabled(true);
        if(y==12)ui->N13->setEnabled(true);
        if(y==13)ui->N14->setEnabled(true);
        if(y==14)ui->N15->setEnabled(true);

    }
    if(x==14){
        if(y==0)ui->O1->setEnabled(true);
        if(y==1)ui->O2->setEnabled(true);
        if(y==2)ui->O3->setEnabled(true);
        if(y==3)ui->O4->setEnabled(true);
        if(y==4)ui->O5->setEnabled(true);
        if(y==5)ui->O6->setEnabled(true);
        if(y==6)ui->O7->setEnabled(true);
        if(y==7)ui->O8->setEnabled(true);
        if(y==8)ui->O9->setEnabled(true);
        if(y==9)ui->O10->setEnabled(true);
        if(y==10)ui->O11->setEnabled(true);
        if(y==11)ui->O12->setEnabled(true);
        if(y==12)ui->O13->setEnabled(true);
        if(y==13)ui->O14->setEnabled(true);
        if(y==14)ui->O15->setEnabled(true);

    }
}

void MainWindow::on_pushButton_4_clicked()
{
    //solucion_backtracking();
    //solucion();
    switch(algoritmo){
    case 1: solucion();
        break;
    case 2: //profundidad
        solucion();
        break;
    case 3:solucion();
        break;
    case 4://costes uniformes
        solucion_voraz();
        break;
    case 5://voraz primero el mejor
        solucion_distancia();
        break;
    case 6:
        solucion_distancia();
        break;
    }
}

void MainWindow::pop_front(){
    nodo aux;

    for(unsigned int i=0; i<pilaback.size()-1;i++){
        aux=pilaback[i];
        pilaback[i]=pilaback[i+1];
        pilaback[i+1]=aux;
    }
    pilaback.pop_back();
}

void MainWindow::anchura(){
    coordenada f;
    f.x=f.y=20;
    string orden=prioridad[0]+prioridad[1]+prioridad[2]+prioridad[3];

    while(true){

        if(pilaback.size()>0){
            visitas(pilaback[0],num_visita);
            num_visita++;
            on_pushButton_3_clicked();
            QTime dieTime= QTime::currentTime().addSecs(1);
            while (QTime::currentTime() < dieTime)
                QCoreApplication::processEvents(QEventLoop::AllEvents,1);
            if(orden=="abid"){
                expandir(cordenada.x,cordenada.y,"W");
                expandir(cordenada.x,cordenada.y,"S");
                expandir(cordenada.x,cordenada.y,"A");
                expandir(cordenada.x,cordenada.y,"D");
            }
            if(orden=="abdi"){
                expandir(cordenada.x,cordenada.y,"W");
                expandir(cordenada.x,cordenada.y,"S");
                expandir(cordenada.x,cordenada.y,"D");
                expandir(cordenada.x,cordenada.y,"A");
            }
            if(orden=="adbi"){
                expandir(cordenada.x,cordenada.y,"W");
                expandir(cordenada.x,cordenada.y,"D");
                expandir(cordenada.x,cordenada.y,"S");
                expandir(cordenada.x,cordenada.y,"A");
            }
            if(orden=="adib"){
                expandir(cordenada.x,cordenada.y,"W");
                expandir(cordenada.x,cordenada.y,"D");
                expandir(cordenada.x,cordenada.y,"A");
                expandir(cordenada.x,cordenada.y,"S");
            }
            if(orden=="aibd"){
                expandir(cordenada.x,cordenada.y,"W");
                expandir(cordenada.x,cordenada.y,"A");
                expandir(cordenada.x,cordenada.y,"S");
                expandir(cordenada.x,cordenada.y,"D");
            }
            if(orden=="aidb"){
                expandir(cordenada.x,cordenada.y,"W");
                expandir(cordenada.x,cordenada.y,"A");
                expandir(cordenada.x,cordenada.y,"D");
                expandir(cordenada.x,cordenada.y,"S");
            }

            if(orden=="baid"){
                expandir(cordenada.x,cordenada.y,"S");
                expandir(cordenada.x,cordenada.y,"W");
                expandir(cordenada.x,cordenada.y,"A");
                expandir(cordenada.x,cordenada.y,"D");
            }
            if(orden=="badi"){
                expandir(cordenada.x,cordenada.y,"S");
                expandir(cordenada.x,cordenada.y,"W");
                expandir(cordenada.x,cordenada.y,"D");
                expandir(cordenada.x,cordenada.y,"A");
            }
            if(orden=="biad"){
                expandir(cordenada.x,cordenada.y,"S");
                expandir(cordenada.x,cordenada.y,"A");
                expandir(cordenada.x,cordenada.y,"W");
                expandir(cordenada.x,cordenada.y,"D");
            }
            if(orden=="bida"){
                expandir(cordenada.x,cordenada.y,"S");
                expandir(cordenada.x,cordenada.y,"A");
                expandir(cordenada.x,cordenada.y,"D");
                expandir(cordenada.x,cordenada.y,"W");
            }
            if(orden=="bdai"){
                expandir(cordenada.x,cordenada.y,"S");
                expandir(cordenada.x,cordenada.y,"D");
                expandir(cordenada.x,cordenada.y,"W");
                expandir(cordenada.x,cordenada.y,"A");
            }
            if(orden=="bdia"){
                expandir(cordenada.x,cordenada.y,"S");
                expandir(cordenada.x,cordenada.y,"D");
                expandir(cordenada.x,cordenada.y,"A");
                expandir(cordenada.x,cordenada.y,"W");
            }

            if(orden=="iabd"){
                expandir(cordenada.x,cordenada.y,"A");
                expandir(cordenada.x,cordenada.y,"W");
                expandir(cordenada.x,cordenada.y,"S");
                expandir(cordenada.x,cordenada.y,"D");
            }
            if(orden=="iadb"){
                expandir(cordenada.x,cordenada.y,"A");
                expandir(cordenada.x,cordenada.y,"W");
                expandir(cordenada.x,cordenada.y,"D");
                expandir(cordenada.x,cordenada.y,"S");
            }
            if(orden=="ibad"){
                expandir(cordenada.x,cordenada.y,"A");
                expandir(cordenada.x,cordenada.y,"S");
                expandir(cordenada.x,cordenada.y,"W");
                expandir(cordenada.x,cordenada.y,"D");
            }
            if(orden=="ibda"){
                expandir(cordenada.x,cordenada.y,"A");
                expandir(cordenada.x,cordenada.y,"S");
                expandir(cordenada.x,cordenada.y,"D");
                expandir(cordenada.x,cordenada.y,"W");
            }
            if(orden=="idab"){
                expandir(cordenada.x,cordenada.y,"A");
                expandir(cordenada.x,cordenada.y,"D");
                expandir(cordenada.x,cordenada.y,"W");
                expandir(cordenada.x,cordenada.y,"S");
            }
            if(orden=="idba"){
                expandir(cordenada.x,cordenada.y,"A");
                expandir(cordenada.x,cordenada.y,"D");
                expandir(cordenada.x,cordenada.y,"S");
                expandir(cordenada.x,cordenada.y,"W");
            }

            if(orden=="dabi"){
                expandir(cordenada.x,cordenada.y,"D");
                expandir(cordenada.x,cordenada.y,"W");
                expandir(cordenada.x,cordenada.y,"S");
                expandir(cordenada.x,cordenada.y,"A");
            }
            if(orden=="daib"){
                expandir(cordenada.x,cordenada.y,"D");
                expandir(cordenada.x,cordenada.y,"W");
                expandir(cordenada.x,cordenada.y,"A");
                expandir(cordenada.x,cordenada.y,"S");
            }
            if(orden=="dbai"){
                expandir(cordenada.x,cordenada.y,"D");
                expandir(cordenada.x,cordenada.y,"S");
                expandir(cordenada.x,cordenada.y,"W");
                expandir(cordenada.x,cordenada.y,"A");
            }
            if(orden=="dbia"){
                expandir(cordenada.x,cordenada.y,"D");
                expandir(cordenada.x,cordenada.y,"S");
                expandir(cordenada.x,cordenada.y,"A");
                expandir(cordenada.x,cordenada.y,"W");
            }
            if(orden=="diab"){
                expandir(cordenada.x,cordenada.y,"D");
                expandir(cordenada.x,cordenada.y,"A");
                expandir(cordenada.x,cordenada.y,"W");
                expandir(cordenada.x,cordenada.y,"S");
            }
            if(orden=="diba"){
                expandir(cordenada.x,cordenada.y,"D");
                expandir(cordenada.x,cordenada.y,"A");
                expandir(cordenada.x,cordenada.y,"S");
                expandir(cordenada.x,cordenada.y,"W");
            }

            coordenada auxpadre, auxhijo;
            auxpadre=generar_xy(pilaback[1].cordenada);
            auxhijo=generar_xy(pilaback[0].cordenada);
            mover(auxhijo.x,auxhijo.y,auxpadre.x,auxpadre.y,cordenada.nombre);
            desbloquear(auxpadre.x, auxpadre.y,f);
            pop_front();
            string name=cordenada.nombre;
            cordenada=generar_xy(pilaback[0].cordenada);
            cordenada.nombre=name;
        }
        else {
            QMessageBox msg;
            activo=1;
            msg.setText("El algoritmo no encontro una solucion");
            msg.exec();
            correcto=false;
            break;
        }
        if(final.x==cordenada.x && final.y==cordenada.y){
            correcto=true;
            visitas(buscar_padre_anchura(generar_coordenada(final.x,final.y)),num_visita);
            num_visita++;
            on_pushButton_3_clicked();
            activo=1;
            QMessageBox msg;
            msg.setText("Felicidades llego a su destino\nPara volver a recorrer el mapa presiona el boton reiniciar");
            msg.exec();

            validar_cordenada(final.x+1,final.y+1,campo[final.x][final.y].icono);
            on_pushButton_4_clicked();
            break;
        }

    }


}

void MainWindow::solucion(){
    bloquear_botones();
    if(correcto==true){
        nodo hijo=buscar_padre_anchura(generar_coordenada(final.x,final.y));
        while(true){

            if(hijo.padre=="NA"){
                marcar_solucion(generar_xy(hijo.cordenada));
                break;
            }
            else{
                marcar_solucion(generar_xy(hijo.cordenada));
            }
            hijo=buscar_padre_anchura(hijo.padre);
        }

        ui->plainTextEdit->clear();
        QString texto="Nodo inicial: "+QString::fromStdString(generar_coordenada(inicial.x,inicial.y))+"\nNodo final: "
                +QString::fromStdString(generar_coordenada(final.x,final.y)+"\n\n");
        ui->plainTextEdit->insertPlainText(texto);
        ui->plainTextEdit->insertPlainText("La solucion final es:\n\n");
        QString cad="";
        hijo=buscar_padre_anchura(generar_coordenada(final.x,final.y));
        while(true){
            if(hijo.padre=="NA"){
                cad=QString::fromStdString(hijo.cordenada)+cad;
                break;
            }
            else{
                cad=" -> "+QString::fromStdString(hijo.cordenada)+cad;
            }
            hijo=buscar_padre_anchura(hijo.padre);
        }
        ui->plainTextEdit->insertPlainText(cad);
    }
    else{
        marcar_solucion(inicial);
        marcar_solucion(final);
        ui->plainTextEdit->clear();
        QString texto="Nodo inicial: "+QString::fromStdString(generar_coordenada(inicial.x,inicial.y))+"\nNodo final: "
                +QString::fromStdString(generar_coordenada(final.x,final.y)+"\n\n");
        ui->plainTextEdit->insertPlainText(texto);
        ui->plainTextEdit->insertPlainText("La solucion final es:\n\nNo se encontro solucion");
    }
}

nodo MainWindow::buscar_padre_anchura(string xy){
    nodo padre;
    for(unsigned int i=0; i<marbol.size(); i++){
        if(marbol[i].cordenada==xy){
            padre=marbol[i];
            break;
        }
    }
    return padre;
}

void MainWindow::profundidad(){
    coordenada f,auxhijo;
    f.x=f.y=20;
    string orden=prioridad[0]+prioridad[1]+prioridad[2]+prioridad[3];

    while(true){

        bool bandera=false,bandera1=false,bandera2=false,bandera3=false,bandera4=false;




        if(pilaback.size()>0){
            visitas( pilaback[pilaback.size()-1],num_visita);
            num_visita++;
            on_pushButton_3_clicked();
            QTime dieTime= QTime::currentTime().addSecs(1);
            while (QTime::currentTime() < dieTime)
                QCoreApplication::processEvents(QEventLoop::AllEvents,1);
            if(orden=="abid"){
                auxhijo=generar_xy(pilaback[pilaback.size()-1].cordenada);
                bandera1=expandir(cordenada.x,cordenada.y,"W");
                bandera2=expandir(cordenada.x,cordenada.y,"S");
                bandera3=expandir(cordenada.x,cordenada.y,"A");
                bandera4=expandir(cordenada.x,cordenada.y,"D");
                if(bandera1||bandera2||bandera3||bandera4)
                    bandera=true;

            }
            if(orden=="abdi"){
                auxhijo=generar_xy(pilaback[pilaback.size()-1].cordenada);
                bandera1=expandir(cordenada.x,cordenada.y,"W");
                bandera2=expandir(cordenada.x,cordenada.y,"S");
                bandera3=expandir(cordenada.x,cordenada.y,"D");
                bandera4=expandir(cordenada.x,cordenada.y,"A");
                if(bandera1||bandera2||bandera3||bandera4)
                    bandera=true;
            }
            if(orden=="adbi"){
                auxhijo=generar_xy(pilaback[pilaback.size()-1].cordenada);
                bandera1=expandir(cordenada.x,cordenada.y,"W");
                bandera2=expandir(cordenada.x,cordenada.y,"D");
                bandera3=expandir(cordenada.x,cordenada.y,"S");
                bandera4=expandir(cordenada.x,cordenada.y,"A");
                if(bandera1==true || bandera2==true || bandera3==true || bandera4==true)
                    bandera=true;
                /*else{
                        bandera=false
                    }*/
            }
            if(orden=="adib"){
                auxhijo=generar_xy(pilaback[pilaback.size()-1].cordenada);
                bandera1=expandir(cordenada.x,cordenada.y,"W");
                bandera2=expandir(cordenada.x,cordenada.y,"D");
                bandera3=expandir(cordenada.x,cordenada.y,"A");
                bandera4=expandir(cordenada.x,cordenada.y,"S");
                if(bandera1||bandera2||bandera3||bandera4)
                    bandera=true;
            }
            if(orden=="aibd"){
                auxhijo=generar_xy(pilaback[pilaback.size()-1].cordenada);
                bandera1=expandir(cordenada.x,cordenada.y,"W");
                bandera2=expandir(cordenada.x,cordenada.y,"A");
                bandera3=expandir(cordenada.x,cordenada.y,"S");
                bandera4=expandir(cordenada.x,cordenada.y,"D");
                if(bandera1||bandera2||bandera3||bandera4)
                    bandera=true;
            }
            if(orden=="aidb"){
                auxhijo=generar_xy(pilaback[pilaback.size()-1].cordenada);
                bandera1=expandir(cordenada.x,cordenada.y,"W");
                bandera2=expandir(cordenada.x,cordenada.y,"A");
                bandera3=expandir(cordenada.x,cordenada.y,"D");
                bandera4=expandir(cordenada.x,cordenada.y,"S");
                if(bandera1||bandera2||bandera3||bandera4)
                    bandera=true;
            }

            if(orden=="baid"){
                auxhijo=generar_xy(pilaback[pilaback.size()-1].cordenada);
                bandera1=expandir(cordenada.x,cordenada.y,"S");
                bandera2=expandir(cordenada.x,cordenada.y,"W");
                bandera3=expandir(cordenada.x,cordenada.y,"A");
                bandera4=expandir(cordenada.x,cordenada.y,"D");
                if(bandera1||bandera2||bandera3||bandera4)
                    bandera=true;
            }
            if(orden=="badi"){
                auxhijo=generar_xy(pilaback[pilaback.size()-1].cordenada);
                bandera1=expandir(cordenada.x,cordenada.y,"S");
                bandera2=expandir(cordenada.x,cordenada.y,"W");
                bandera3=expandir(cordenada.x,cordenada.y,"D");
                bandera4=expandir(cordenada.x,cordenada.y,"A");
                if(bandera1||bandera2||bandera3||bandera4)
                    bandera=true;
            }
            if(orden=="biad"){
                auxhijo=generar_xy(pilaback[pilaback.size()-1].cordenada);
                bandera1=expandir(cordenada.x,cordenada.y,"S");
                bandera2=expandir(cordenada.x,cordenada.y,"A");
                bandera3=expandir(cordenada.x,cordenada.y,"W");
                bandera4=expandir(cordenada.x,cordenada.y,"D");
                if(bandera1||bandera2||bandera3||bandera4)
                    bandera=true;
            }
            if(orden=="bida"){
                auxhijo=generar_xy(pilaback[pilaback.size()-1].cordenada);
                bandera1=expandir(cordenada.x,cordenada.y,"S");
                bandera2=expandir(cordenada.x,cordenada.y,"A");
                bandera3=expandir(cordenada.x,cordenada.y,"D");
                bandera4=expandir(cordenada.x,cordenada.y,"W");
                if(bandera1||bandera2||bandera3||bandera4)
                    bandera=true;
            }
            if(orden=="bdai"){
                auxhijo=generar_xy(pilaback[pilaback.size()-1].cordenada);
                bandera1=expandir(cordenada.x,cordenada.y,"S");
                bandera2=expandir(cordenada.x,cordenada.y,"D");
                bandera3=expandir(cordenada.x,cordenada.y,"W");
                bandera4=expandir(cordenada.x,cordenada.y,"A");
                if(bandera1||bandera2||bandera3||bandera4)
                    bandera=true;
            }
            if(orden=="bdia"){
                auxhijo=generar_xy(pilaback[pilaback.size()-1].cordenada);
                bandera1=expandir(cordenada.x,cordenada.y,"S");
                bandera2=expandir(cordenada.x,cordenada.y,"D");
                bandera3=expandir(cordenada.x,cordenada.y,"A");
                bandera4=expandir(cordenada.x,cordenada.y,"W");
                if(bandera1||bandera2||bandera3||bandera4)
                    bandera=true;
            }

            if(orden=="iabd"){
                auxhijo=generar_xy(pilaback[pilaback.size()-1].cordenada);
                bandera1=expandir(cordenada.x,cordenada.y,"A");
                bandera2=expandir(cordenada.x,cordenada.y,"W");
                bandera3=expandir(cordenada.x,cordenada.y,"S");
                bandera4=expandir(cordenada.x,cordenada.y,"D");
                if(bandera1||bandera2||bandera3||bandera4)
                    bandera=true;
            }
            if(orden=="iadb"){
                auxhijo=generar_xy(pilaback[pilaback.size()-1].cordenada);
                bandera1=expandir(cordenada.x,cordenada.y,"A");
                bandera2=expandir(cordenada.x,cordenada.y,"W");
                bandera3=expandir(cordenada.x,cordenada.y,"D");
                bandera4=expandir(cordenada.x,cordenada.y,"S");
                if(bandera1||bandera2||bandera3||bandera4)
                    bandera=true;
            }
            if(orden=="ibad"){
                auxhijo=generar_xy(pilaback[pilaback.size()-1].cordenada);
                bandera1=expandir(cordenada.x,cordenada.y,"A");
                bandera2=expandir(cordenada.x,cordenada.y,"S");
                bandera3=expandir(cordenada.x,cordenada.y,"W");
                bandera4=expandir(cordenada.x,cordenada.y,"D");
                if(bandera1||bandera2||bandera3||bandera4)
                    bandera=true;
            }
            if(orden=="ibda"){
                auxhijo=generar_xy(pilaback[pilaback.size()-1].cordenada);
                bandera1=expandir(cordenada.x,cordenada.y,"A");
                bandera2=expandir(cordenada.x,cordenada.y,"S");
                bandera3=expandir(cordenada.x,cordenada.y,"D");
                bandera4=expandir(cordenada.x,cordenada.y,"W");
                if(bandera1||bandera2||bandera3||bandera4)
                    bandera=true;
            }
            if(orden=="idab"){
                auxhijo=generar_xy(pilaback[pilaback.size()-1].cordenada);
                bandera1=expandir(cordenada.x,cordenada.y,"A");
                bandera2=expandir(cordenada.x,cordenada.y,"D");
                bandera3=expandir(cordenada.x,cordenada.y,"W");
                bandera4=expandir(cordenada.x,cordenada.y,"S");
                if(bandera1||bandera2||bandera3||bandera4)
                    bandera=true;
            }

            if(orden=="idba"){
                auxhijo=generar_xy(pilaback[pilaback.size()-1].cordenada);
                bandera1=expandir(cordenada.x,cordenada.y,"A");
                bandera2=expandir(cordenada.x,cordenada.y,"D");
                bandera3=expandir(cordenada.x,cordenada.y,"S");
                bandera4=expandir(cordenada.x,cordenada.y,"W");
                if(bandera1||bandera2||bandera3||bandera4)
                    bandera=true;
            }

            if(orden=="dabi"){
                auxhijo=generar_xy(pilaback[pilaback.size()-1].cordenada);
                bandera1=expandir(cordenada.x,cordenada.y,"D");
                bandera2=expandir(cordenada.x,cordenada.y,"W");
                bandera3=expandir(cordenada.x,cordenada.y,"S");
                bandera4=expandir(cordenada.x,cordenada.y,"A");
                if(bandera1||bandera2||bandera3||bandera4)
                    bandera=true;
            }
            if(orden=="daib"){
                auxhijo=generar_xy(pilaback[pilaback.size()-1].cordenada);
                bandera1=expandir(cordenada.x,cordenada.y,"D");
                bandera2=expandir(cordenada.x,cordenada.y,"W");
                bandera3=expandir(cordenada.x,cordenada.y,"A");
                bandera4=expandir(cordenada.x,cordenada.y,"S");
                if(bandera1||bandera2||bandera3||bandera4)
                    bandera=true;
            }
            if(orden=="dbai"){
                auxhijo=generar_xy(pilaback[pilaback.size()-1].cordenada);
                bandera1=expandir(cordenada.x,cordenada.y,"D");
                bandera2=expandir(cordenada.x,cordenada.y,"S");
                bandera3=expandir(cordenada.x,cordenada.y,"W");
                bandera4=expandir(cordenada.x,cordenada.y,"A");
                if(bandera1||bandera2||bandera3||bandera4)
                    bandera=true;
            }
            if(orden=="dbia"){
                auxhijo=generar_xy(pilaback[pilaback.size()-1].cordenada);
                bandera1=expandir(cordenada.x,cordenada.y,"D");
                bandera2=expandir(cordenada.x,cordenada.y,"S");
                bandera3=expandir(cordenada.x,cordenada.y,"A");
                bandera4=expandir(cordenada.x,cordenada.y,"W");
                if(bandera1||bandera2||bandera3||bandera4)
                    bandera=true;
            }
            if(orden=="diab"){
                auxhijo=generar_xy(pilaback[pilaback.size()-1].cordenada);
                bandera1=expandir(cordenada.x,cordenada.y,"D");
                bandera2=expandir(cordenada.x,cordenada.y,"A");
                bandera3=expandir(cordenada.x,cordenada.y,"W");
                bandera4=expandir(cordenada.x,cordenada.y,"S");
                if(bandera1||bandera2||bandera3||bandera4)
                    bandera=true;
            }
            if(orden=="diba"){
                auxhijo=generar_xy(pilaback[pilaback.size()-1].cordenada);
                bandera1=expandir(cordenada.x,cordenada.y,"D");
                bandera2=expandir(cordenada.x,cordenada.y,"A");
                bandera3=expandir(cordenada.x,cordenada.y,"S");
                bandera4=expandir(cordenada.x,cordenada.y,"W");
                if(bandera1||bandera2||bandera3||bandera4)
                    bandera=true;
            }

            if(bandera){
                coordenada auxpadre;
                auxpadre=generar_xy(pilaback[pilaback.size()-1].cordenada);
                mover(auxhijo.x,auxhijo.y,auxpadre.x,auxpadre.y,cordenada.nombre);
                desbloquear(auxpadre.x, auxpadre.y,f);
                pop_profundidad();
                string name=cordenada.nombre;
                cordenada=generar_xy(pilaback[pilaback.size()-1].cordenada);
                cordenada.nombre=name;
            }
            else{
                coordenada auxpadre;
                auxpadre=generar_xy(pilaback[pilaback.size()-2].cordenada);
                mover(auxhijo.x,auxhijo.y,auxpadre.x,auxpadre.y,cordenada.nombre);
                desbloquear(auxpadre.x, auxpadre.y,f);
                pop_profundidad();
                string name=cordenada.nombre;
                cordenada=generar_xy(pilaback[pilaback.size()-1].cordenada);
                cordenada.nombre=name;
            }
        }
        else {
            QMessageBox msg;
            activo=1;
            msg.setText("El algoritmo no encontro una solucion");
            msg.exec();
            correcto=false;
            break;
        }

        if(final.x==cordenada.x && final.y==cordenada.y){
            correcto=true;
            QMessageBox msg;
            visitas(buscar_padre_anchura(generar_coordenada(final.x,final.y)),num_visita);
            num_visita++;
            on_pushButton_3_clicked();
            activo=1;
            msg.setText("Felicidades llego a su destino\nPara volver a recorrer el mapa presiona el boton reiniciar");
            msg.exec();

            validar_cordenada(final.x+1,final.y+1,campo[final.x][final.y].icono);
            on_pushButton_4_clicked();
            break;
        }

    }
}

void MainWindow::pop_profundidad(){
    string cor=pilaback[pilaback.size()-1].padre;
    for(unsigned int i=0; i<pilaback.size();i++){
        if(cor==pilaback[i].cordenada){
            nodo aux;
            for(unsigned int j=i; j<pilaback.size()-1;j++){
                aux=pilaback[j];
                pilaback[j]=pilaback[j+1];
                pilaback[j+1]=aux;
            }
            break;
        }
    }
    pilaback.pop_back();
}

void MainWindow::visitas(nodo aux, int visita)
{
    for(unsigned int i=0; i<marbol.size();i++){
        if(aux.cordenada==marbol[i].cordenada&&aux.padre==marbol[i].padre&&aux.nivel==marbol[i].nivel){
            marbol[i].orden_visita.push_back(visita);
            break;
        }
    }
}

void MainWindow::on_pb_personaje_clicked()
{
    ui->radioButton->setChecked(true);
}

void MainWindow::on_pb_personaje_2_clicked()
{
    ui->radioButton_2->setChecked(true);
}

void MainWindow::on_pb_personaje3_clicked()
{
    ui->radioButton_3->setChecked(true);
}

//coste uniforme

float MainWindow::generar_costo(string nombre)
{
    personaje per;
    for(unsigned int i=0; i<persona.size(); i++){
        if(persona[i].estado==1){
            per=persona[i];
            break;
        }
    }
    if(nombre=="Ciudad"){
        if(per.ciudad!="NA")
        {
            QString num=QString::fromStdString(per.ciudad);
            float cant=num.toFloat();
            return cant;
        }
    }
    if(nombre=="Pueblo"){
        if(per.pueblo!="NA")
        {
            QString num=QString::fromStdString(per.pueblo);
            float cant=num.toFloat();
            return cant;
        }
    }
    if(nombre=="Mar"){
        if(per.mar!="NA")
        {
            QString num=QString::fromStdString(per.mar);
            float cant=num.toFloat();
            return cant;
        }
    }
    if(nombre=="Playa"){
        if(per.playa!="NA")
        {
            QString num=QString::fromStdString(per.playa);
            float cant=num.toFloat();
            return cant;
        }
    }
    if(nombre=="Desierto"){
        if(per.desierto!="NA")
        {
            QString num=QString::fromStdString(per.desierto);
            float cant=num.toFloat();
            return cant;
        }
    }
    if(nombre=="Bosque"){
        if(per.bosque!="NA")
        {
            QString num=QString::fromStdString(per.bosque);
            float cant=num.toFloat();
            return cant;
        }
    }
    if(nombre=="Montana"){
        if(per.montana!="NA")
        {
            QString num=QString::fromStdString(per.montana);
            float cant=num.toFloat();
            return cant;
        }
    }
    if(nombre=="Lomas"){
        if(per.loma!="NA")
        {
            QString num=QString::fromStdString(per.loma);
            float cant=num.toFloat();
            return cant;
        }
    }
    if(nombre=="Nieve"){
        if(per.nieve!="NA")
        {
            QString num=QString::fromStdString(per.nieve);
            float cant=num.toFloat();
            return cant;
        }
    }
    if(nombre=="Pared"){
        if(per.pared!="NA")
        {
            QString num=QString::fromStdString(per.pared);
            float cant=num.toFloat();
            return cant;
        }
    }
    return -1;

}

void MainWindow::insertar_en_costes(nodo hijo, int nivel)
{

    pilaback.push_back(hijo);
    if(marbol.size()==0){
        marbol.push_back(hijo);
    }
    else{
        marbol.push_back(hijo);
        nodo aux;
        for(unsigned int i=marbol.size()-1; i>0; i--){
            if(marbol[i-1].cordenada==marbol[i].padre&&marbol[i-1].nivel==nivel){
                break;
            }
            else{
                aux=marbol[i-1];
                marbol[i-1]=marbol[i];
                marbol[i]=aux;
            }
        }
    }
}

void MainWindow::ordenar()
{
    for(unsigned int i=1;i<pilaback.size();i++)
    {
        for(unsigned int j=0;j<pilaback.size()-1;j++)
        {
            if(pilaback[j].total>pilaback[j+1].total)
            {
                nodo k=pilaback[j];
                pilaback[j]=pilaback[j+1];
                pilaback[j+1]=k;
            }
        }
    }
}

bool MainWindow::expandir_voraz(int x, int y, string letra, int nivel,string xypadre)
{
    nodo hijo;
    personaje per;
    for(unsigned int i=0; i<persona.size(); i++){
        if(persona[i].estado==1){
            per=persona[i];
            break;
        }
    }

    if(letra=="d"||letra=="D"){
        if(y<14){

            if(validar_campo(campo[x][y+1],per)){

                string cor=generar_coordenada(x,y+1);
                if(cor!="z"){
                    nodo padre=buscar_padre_voraz(generar_coordenada(x,y),xypadre,nivel);
                    if(padre.cordenada!="z"){
                        if(generar_costo(campo[x][y].icono)!=-1){
                            if(existe_hijo_voraz(cor,xypadre, padre.nivel+1)){
                                if(existe_hijo(cor)){
                                    hijo.cordenada=cor;
                                    hijo.estado="abierto";
                                    hijo.color=padre.color+1;
                                    hijo.otro="";
                                    hijo.nivel=padre.nivel+1;
                                    hijo.costo=generar_costo(campo[x][y+1].icono);
                                    hijo.total=padre.total+hijo.costo;
                                    hijo.padre=padre.cordenada;
                                    hijo.tab=padre.tab+"    ";
                                    insertar_en_costes(hijo,padre.nivel);
                                    return true;
                                }
                            }
                        }
                    }

                }
            }
        }
    }
    if(letra=="a"||letra=="A"){
        if(y>0){
            if(validar_campo(campo[x][y-1],per)){
                string cor=generar_coordenada(x,y-1);
                if(cor!="z"){
                    nodo padre=buscar_padre_voraz(generar_coordenada(x,y),xypadre,nivel);
                    if(padre.cordenada!="z"){
                        if(generar_costo(campo[x][y].icono)!=-1){
                            if(existe_hijo_voraz(cor,xypadre,padre.nivel+1)){
                                if(existe_hijo(cor)){
                                    hijo.cordenada=cor;
                                    hijo.estado="abierto";
                                    hijo.color=padre.color+1;
                                    hijo.otro="";
                                    hijo.nivel=padre.nivel+1;
                                    hijo.costo=generar_costo(campo[x][y-1].icono);
                                    hijo.total=padre.total+hijo.costo;
                                    hijo.padre=padre.cordenada;
                                    hijo.tab=padre.tab+"    ";
                                    insertar_en_costes(hijo,padre.nivel);
                                    return true;
                                }
                            }
                        }
                    }
                }
            }
        }
    }
    if(letra=="s"||letra=="S"){
        if(x<14){
            if(validar_campo(campo[x+1][y],per)){
                string cor=generar_coordenada(x+1,y);
                if(cor!="z"){
                    nodo padre=buscar_padre_voraz(generar_coordenada(x,y),xypadre,nivel);
                    if(padre.cordenada!="z"){
                        if(generar_costo(campo[x][y].icono)!=-1){
                            if(existe_hijo_voraz(cor,xypadre,padre.nivel+1)){
                                if(existe_hijo(cor)){
                                    hijo.cordenada=cor;
                                    hijo.estado="abierto";
                                    hijo.color=padre.color+1;
                                    hijo.otro="";
                                    hijo.nivel=padre.nivel+1;
                                    hijo.costo=generar_costo(campo[x+1][y].icono);
                                    hijo.total=padre.total+hijo.costo;
                                    hijo.padre=padre.cordenada;
                                    hijo.tab=padre.tab+"    ";
                                    insertar_en_costes(hijo,padre.nivel);
                                    return true;
                                }
                            }
                        }
                    }
                }
            }
        }
    }
    if(letra=="w"||letra=="W"){
        if(x>0){
            if(validar_campo(campo[x-1][y],per)){
                string cor=generar_coordenada(x-1,y);
                if(cor!="z"){
                    nodo padre=buscar_padre_voraz(generar_coordenada(x,y),xypadre,nivel);
                    if(padre.cordenada!="z"){
                        if(generar_costo(campo[x][y].icono)!=-1){
                            if(existe_hijo_voraz(cor,xypadre,padre.nivel+1)){
                                if(existe_hijo(cor)){
                                    hijo.cordenada=cor;
                                    hijo.estado="abierto";
                                    hijo.color=padre.color+1;
                                    hijo.otro="";
                                    hijo.nivel=padre.nivel+1;
                                    hijo.costo=generar_costo(campo[x-1][y].icono);
                                    hijo.total=padre.total+hijo.costo;
                                    hijo.padre=padre.cordenada;
                                    hijo.tab=padre.tab+"    ";
                                    insertar_en_costes(hijo,padre.nivel);
                                    return true;
                                }
                            }
                        }
                    }
                }
            }
        }
    }
    return false;

}

void MainWindow::costes_uniformes()
{
    coordenada f;
    nodo auxi;
    coordenada auxpadre, auxhijo;
    f.x=f.y=20;
    string orden=prioridad[0]+prioridad[1]+prioridad[2]+prioridad[3];
    while(true){

        if(pilaback.size()>0){
            visitas(pilaback[0],num_visita);
            num_visita++;
            on_pushButton_3_clicked();
            QTime dieTime= QTime::currentTime().addSecs(1);
            while (QTime::currentTime() < dieTime)
                QCoreApplication::processEvents(QEventLoop::AllEvents,1);
            auxhijo=generar_xy(pilaback[0].cordenada);
            nodo pilabac=pilaback[0];
            if(pilaback.size()>1){
                auxi=pilaback[1];
                ant=auxi;
            }
            pop_front();


            if(orden=="abid"){
                expandir_voraz(cordenada.x,cordenada.y,"W",pilabac.nivel,pilabac.cordenada);
                expandir_voraz(cordenada.x,cordenada.y,"S",pilabac.nivel,pilabac.cordenada);
                expandir_voraz(cordenada.x,cordenada.y,"A",pilabac.nivel,pilabac.cordenada);
                expandir_voraz(cordenada.x,cordenada.y,"D",pilabac.nivel,pilabac.cordenada);
            }
            if(orden=="abdi"){
                expandir_voraz(cordenada.x,cordenada.y,"W",pilabac.nivel,pilabac.cordenada);
                expandir_voraz(cordenada.x,cordenada.y,"S",pilabac.nivel,pilabac.cordenada);
                expandir_voraz(cordenada.x,cordenada.y,"D",pilabac.nivel,pilabac.cordenada);
                expandir_voraz(cordenada.x,cordenada.y,"A",pilabac.nivel,pilabac.cordenada);
            }
            if(orden=="adbi"){
                expandir_voraz(cordenada.x,cordenada.y,"W",pilabac.nivel,pilabac.cordenada);
                expandir_voraz(cordenada.x,cordenada.y,"D",pilabac.nivel,pilabac.cordenada);
                expandir_voraz(cordenada.x,cordenada.y,"S",pilabac.nivel,pilabac.cordenada);
                expandir_voraz(cordenada.x,cordenada.y,"A",pilabac.nivel,pilabac.cordenada);
            }
            if(orden=="adib"){
                expandir_voraz(cordenada.x,cordenada.y,"W",pilabac.nivel,pilabac.cordenada);
                expandir_voraz(cordenada.x,cordenada.y,"D",pilabac.nivel,pilabac.cordenada);
                expandir_voraz(cordenada.x,cordenada.y,"A",pilabac.nivel,pilabac.cordenada);
                expandir_voraz(cordenada.x,cordenada.y,"S",pilabac.nivel,pilabac.cordenada);
            }
            if(orden=="aibd"){
                expandir_voraz(cordenada.x,cordenada.y,"W",pilabac.nivel,pilabac.cordenada);
                expandir_voraz(cordenada.x,cordenada.y,"A",pilabac.nivel,pilabac.cordenada);
                expandir_voraz(cordenada.x,cordenada.y,"S",pilabac.nivel,pilabac.cordenada);
                expandir_voraz(cordenada.x,cordenada.y,"D",pilabac.nivel,pilabac.cordenada);
            }
            if(orden=="aidb"){
                expandir_voraz(cordenada.x,cordenada.y,"W",pilabac.nivel,pilabac.cordenada);
                expandir_voraz(cordenada.x,cordenada.y,"A",pilabac.nivel,pilabac.cordenada);
                expandir_voraz(cordenada.x,cordenada.y,"D",pilabac.nivel,pilabac.cordenada);
                expandir_voraz(cordenada.x,cordenada.y,"S",pilabac.nivel,pilabac.cordenada);
            }

            if(orden=="baid"){
                expandir_voraz(cordenada.x,cordenada.y,"S",pilabac.nivel,pilabac.cordenada);
                expandir_voraz(cordenada.x,cordenada.y,"W",pilabac.nivel,pilabac.cordenada);
                expandir_voraz(cordenada.x,cordenada.y,"A",pilabac.nivel,pilabac.cordenada);
                expandir_voraz(cordenada.x,cordenada.y,"D",pilabac.nivel,pilabac.cordenada);
            }
            if(orden=="badi"){
                expandir_voraz(cordenada.x,cordenada.y,"S",pilabac.nivel,pilabac.cordenada);
                expandir_voraz(cordenada.x,cordenada.y,"W",pilabac.nivel,pilabac.cordenada);
                expandir_voraz(cordenada.x,cordenada.y,"D",pilabac.nivel,pilabac.cordenada);
                expandir_voraz(cordenada.x,cordenada.y,"A",pilabac.nivel,pilabac.cordenada);
            }
            if(orden=="biad"){
                expandir_voraz(cordenada.x,cordenada.y,"S",pilabac.nivel,pilabac.cordenada);
                expandir_voraz(cordenada.x,cordenada.y,"A",pilabac.nivel,pilabac.cordenada);
                expandir_voraz(cordenada.x,cordenada.y,"W",pilabac.nivel,pilabac.cordenada);
                expandir_voraz(cordenada.x,cordenada.y,"D",pilabac.nivel,pilabac.cordenada);
            }
            if(orden=="bida"){
                expandir_voraz(cordenada.x,cordenada.y,"S",pilabac.nivel,pilabac.cordenada);
                expandir_voraz(cordenada.x,cordenada.y,"A",pilabac.nivel,pilabac.cordenada);
                expandir_voraz(cordenada.x,cordenada.y,"D",pilabac.nivel,pilabac.cordenada);
                expandir_voraz(cordenada.x,cordenada.y,"W",pilabac.nivel,pilabac.cordenada);
            }
            if(orden=="bdai"){
                expandir_voraz(cordenada.x,cordenada.y,"S",pilabac.nivel,pilabac.cordenada);
                expandir_voraz(cordenada.x,cordenada.y,"D",pilabac.nivel,pilabac.cordenada);
                expandir_voraz(cordenada.x,cordenada.y,"W",pilabac.nivel,pilabac.cordenada);
                expandir_voraz(cordenada.x,cordenada.y,"A",pilabac.nivel,pilabac.cordenada);
            }
            if(orden=="bdia"){
                expandir_voraz(cordenada.x,cordenada.y,"S",pilabac.nivel,pilabac.cordenada);
                expandir_voraz(cordenada.x,cordenada.y,"D",pilabac.nivel,pilabac.cordenada);
                expandir_voraz(cordenada.x,cordenada.y,"A",pilabac.nivel,pilabac.cordenada);
                expandir_voraz(cordenada.x,cordenada.y,"W",pilabac.nivel,pilabac.cordenada);
            }

            if(orden=="iabd"){
                expandir_voraz(cordenada.x,cordenada.y,"A",pilabac.nivel,pilabac.cordenada);
                expandir_voraz(cordenada.x,cordenada.y,"W",pilabac.nivel,pilabac.cordenada);
                expandir_voraz(cordenada.x,cordenada.y,"S",pilabac.nivel,pilabac.cordenada);
                expandir_voraz(cordenada.x,cordenada.y,"D",pilabac.nivel,pilabac.cordenada);
            }
            if(orden=="iadb"){
                expandir_voraz(cordenada.x,cordenada.y,"A",pilabac.nivel,pilabac.cordenada);
                expandir_voraz(cordenada.x,cordenada.y,"W",pilabac.nivel,pilabac.cordenada);
                expandir_voraz(cordenada.x,cordenada.y,"D",pilabac.nivel,pilabac.cordenada);
                expandir_voraz(cordenada.x,cordenada.y,"S",pilabac.nivel,pilabac.cordenada);
            }
            if(orden=="ibad"){
                expandir_voraz(cordenada.x,cordenada.y,"A",pilabac.nivel,pilabac.cordenada);
                expandir_voraz(cordenada.x,cordenada.y,"S",pilabac.nivel,pilabac.cordenada);
                expandir_voraz(cordenada.x,cordenada.y,"W",pilabac.nivel,pilabac.cordenada);
                expandir_voraz(cordenada.x,cordenada.y,"D",pilabac.nivel,pilabac.cordenada);
            }
            if(orden=="ibda"){
                expandir_voraz(cordenada.x,cordenada.y,"A",pilabac.nivel,pilabac.cordenada);
                expandir_voraz(cordenada.x,cordenada.y,"S",pilabac.nivel,pilabac.cordenada);
                expandir_voraz(cordenada.x,cordenada.y,"D",pilabac.nivel,pilabac.cordenada);
                expandir_voraz(cordenada.x,cordenada.y,"W",pilabac.nivel,pilabac.cordenada);
            }
            if(orden=="idab"){
                expandir_voraz(cordenada.x,cordenada.y,"A",pilabac.nivel,pilabac.cordenada);
                expandir_voraz(cordenada.x,cordenada.y,"D",pilabac.nivel,pilabac.cordenada);
                expandir_voraz(cordenada.x,cordenada.y,"W",pilabac.nivel,pilabac.cordenada);
                expandir_voraz(cordenada.x,cordenada.y,"S",pilabac.nivel,pilabac.cordenada);
            }
            if(orden=="idba"){
                expandir_voraz(cordenada.x,cordenada.y,"A",pilabac.nivel,pilabac.cordenada);
                expandir_voraz(cordenada.x,cordenada.y,"D",pilabac.nivel,pilabac.cordenada);
                expandir_voraz(cordenada.x,cordenada.y,"S",pilabac.nivel,pilabac.cordenada);
                expandir_voraz(cordenada.x,cordenada.y,"W",pilabac.nivel,pilabac.cordenada);
            }

            if(orden=="dabi"){
                expandir_voraz(cordenada.x,cordenada.y,"D",pilabac.nivel,pilabac.cordenada);
                expandir_voraz(cordenada.x,cordenada.y,"W",pilabac.nivel,pilabac.cordenada);
                expandir_voraz(cordenada.x,cordenada.y,"S",pilabac.nivel,pilabac.cordenada);
                expandir_voraz(cordenada.x,cordenada.y,"A",pilabac.nivel,pilabac.cordenada);
            }
            if(orden=="daib"){
                expandir_voraz(cordenada.x,cordenada.y,"D",pilabac.nivel,pilabac.cordenada);
                expandir_voraz(cordenada.x,cordenada.y,"W",pilabac.nivel,pilabac.cordenada);
                expandir_voraz(cordenada.x,cordenada.y,"A",pilabac.nivel,pilabac.cordenada);
                expandir_voraz(cordenada.x,cordenada.y,"S",pilabac.nivel,pilabac.cordenada);
            }
            if(orden=="dbai"){
                expandir_voraz(cordenada.x,cordenada.y,"D",pilabac.nivel,pilabac.cordenada);
                expandir_voraz(cordenada.x,cordenada.y,"S",pilabac.nivel,pilabac.cordenada);
                expandir_voraz(cordenada.x,cordenada.y,"W",pilabac.nivel,pilabac.cordenada);
                expandir_voraz(cordenada.x,cordenada.y,"A",pilabac.nivel,pilabac.cordenada);
            }
            if(orden=="dbia"){
                expandir_voraz(cordenada.x,cordenada.y,"D",pilabac.nivel,pilabac.cordenada);
                expandir_voraz(cordenada.x,cordenada.y,"S",pilabac.nivel,pilabac.cordenada);
                expandir_voraz(cordenada.x,cordenada.y,"A",pilabac.nivel,pilabac.cordenada);
                expandir_voraz(cordenada.x,cordenada.y,"W",pilabac.nivel,pilabac.cordenada);
            }
            if(orden=="diab"){
                expandir_voraz(cordenada.x,cordenada.y,"D",pilabac.nivel,pilabac.cordenada);
                expandir_voraz(cordenada.x,cordenada.y,"A",pilabac.nivel,pilabac.cordenada);
                expandir_voraz(cordenada.x,cordenada.y,"W",pilabac.nivel,pilabac.cordenada);
                expandir_voraz(cordenada.x,cordenada.y,"S",pilabac.nivel,pilabac.cordenada);
            }
            if(orden=="diba"){
                expandir_voraz(cordenada.x,cordenada.y,"D",pilabac.nivel,pilabac.cordenada);
                expandir_voraz(cordenada.x,cordenada.y,"A",pilabac.nivel,pilabac.cordenada);
                expandir_voraz(cordenada.x,cordenada.y,"S",pilabac.nivel,pilabac.cordenada);
                expandir_voraz(cordenada.x,cordenada.y,"W",pilabac.nivel,pilabac.cordenada);
            }
            ordenar();


            auxpadre=generar_xy(pilaback[0].cordenada);
            mover(auxhijo.x,auxhijo.y,auxpadre.x,auxpadre.y,cordenada.nombre);
            desbloquear(auxpadre.x, auxpadre.y,f);
            string name=cordenada.nombre;
            cordenada=generar_xy(pilaback[0].cordenada);
            cordenada.nombre=name;
        }
        else {
            QMessageBox msg;
            activo=1;
            msg.setText("El algoritmo no encontro una solucion");
            msg.exec();
            correcto=false;
            break;
        }
        if(final.x==cordenada.x && final.y==cordenada.y){
            correcto=true;
            visitas(bpv(auxi.cordenada,auxi.padre),num_visita);
            num_visita++;
            on_pushButton_3_clicked();
            activo=1;
            QMessageBox msg;
            msg.setText("Felicidades llego a su destino\nPara volver a recorrer el mapa presiona el boton reiniciar");
            msg.exec();

            validar_cordenada(final.x+1,final.y+1,campo[final.x][final.y].icono);
            on_pushButton_4_clicked();
            break;
        }

    }

}

nodo MainWindow::buscar_padre_voraz(string xy, string xypadre,int nivel){
    nodo aux;
    for(unsigned int i=0; i<marbol.size(); i++){
        if(marbol[i].cordenada==xy&&marbol[i].nivel==nivel){
            return marbol[i];
        }
    }
    return aux;
}

bool MainWindow::existe_hijo_voraz(string xy,string xypadre, int nivel){

    if(xy==generar_coordenada(final.x,final.y)){
        return true;
    }
    for(unsigned int i=0; i<marbol.size(); i++){
        if(marbol[i].cordenada==xy&&marbol[i].nivel==nivel&&marbol[i].padre==xypadre){
            return false;
        }
    }
    return true;
}

void MainWindow::mostrar_voraz(){
    ui->plainTextEdit->clear();
    for(unsigned int i=0; i<marbol.size();i++){
        colorido(marbol[i].color);

        QString men=QString::fromStdString(marbol[i].tab)+QString::fromStdString(marbol[i].cordenada)+"  ";
        ui->plainTextEdit->insertPlainText(men);
        men="";

        for(unsigned int j=0; j<marbol[i].orden_visita.size(); j++){
            if(j==marbol[i].orden_visita.size()-1){
                ui->plainTextEdit->setTextColor(QColor("black"));
                men+=QString::number(marbol[i].orden_visita[j]);
            }
            else{
                men+=QString::number(marbol[i].orden_visita[j])+", ";
            }

        }
        ui->plainTextEdit->setTextColor(QColor("black"));
        ui->plainTextEdit->insertPlainText(men);
        men="         Costo: "+QString::number(marbol[i].total);
        ui->plainTextEdit->insertPlainText(men);
        ui->plainTextEdit->insertPlainText("\n");
    }
    ui->plainTextEdit->setTextColor(QColor("black"));
}

void MainWindow::solucion_voraz()
{
    bloquear_botones();
    int costoso=0;
    bool ban=false;
    if(correcto==true){
        ban=true;
        nodo hijo=bpv(ant.cordenada,ant.padre);
        while(true){
            costoso+=hijo.costo;
            if(hijo.padre=="NA"){
                marcar_solucion(generar_xy(hijo.cordenada));
                break;
            }
            else{
                marcar_solucion(generar_xy(hijo.cordenada));
            }
            hijo=buscar_padre_anchura(hijo.padre);
        }

        ui->plainTextEdit->clear();
        QString texto="Nodo inicial: "+QString::fromStdString(generar_coordenada(inicial.x,inicial.y))+"\nNodo final: "
                +QString::fromStdString(generar_coordenada(final.x,final.y)+"\n\n");
        ui->plainTextEdit->insertPlainText(texto);
        ui->plainTextEdit->insertPlainText("La solucion final es:\n\n");
        QString cad="";
        hijo=bpv(ant.cordenada,ant.padre);
        while(true){
            if(hijo.padre=="NA"){
                cad=QString::fromStdString(hijo.cordenada)+cad;
                break;
            }
            else{
                cad=" -> "+QString::fromStdString(hijo.cordenada)+cad;
            }
            hijo=buscar_padre_anchura(hijo.padre);
        }
        ui->plainTextEdit->insertPlainText(cad);
    }
    else{
        ban=false;
        marcar_solucion(inicial);
        marcar_solucion(final);
        ui->plainTextEdit->clear();
        QString texto="Nodo inicial: "+QString::fromStdString(generar_coordenada(inicial.x,inicial.y))+"\nNodo final: "
                +QString::fromStdString(generar_coordenada(final.x,final.y)+"\n\n");
        ui->plainTextEdit->insertPlainText(texto);
        ui->plainTextEdit->insertPlainText("La solucion final es:\n\nNo se encontro solucion");
    }
    if(ban==true){
        QString cad="";
        ui->plainTextEdit->insertPlainText("\n\n");
        nodo hijo=bpv(ant.cordenada,ant.padre);
        nodo aux=hijo;
        while(true){
            if(hijo.padre=="NA"){
                cad=QString::number(hijo.costo)+cad;
                break;
            }
            else{
                cad=" -> "+QString::number(hijo.costo)+cad;
            }
            hijo=buscar_padre_anchura(hijo.padre);
        }
        ui->plainTextEdit->insertPlainText(cad);
        QString ms="\n\nCosto Final: "+QString::number(aux.total);
        ui->plainTextEdit->insertPlainText(ms);
    }
}

float MainWindow::generar_distancia(int x1, int y1, int x2, int y2)
{
    float resultado = sqrt(pow(x2-x1,2)+pow(y2-y1,2));
    QString res=QString::number(resultado);
    int j=0;
    QString respu="";
    bool bandera = false;
    for(int i=0; i<res.size();i++){
        if(res[i]=='.'){
            bandera=true;
            respu.push_back(res[i]);
        }
        else{
            respu.push_back(res[i]);
        }
        if(j==2){
            break;
        }
        if(bandera==true){
            j++;
        }
    }
    resultado=respu.toFloat();
    return resultado;
}

void MainWindow::ordenar_distancia()
{
    for(unsigned int i=0;i<pilaback.size()-1;i++)
    {
        for(unsigned int j=0;j<pilaback.size()-i-1;j++)
        {
            if(pilaback[j].distancia>pilaback[j+1].distancia)
            {
                nodo k=pilaback[j];
                pilaback[j]=pilaback[j+1];
                pilaback[j+1]=k;
            }
        }
    }
}

void MainWindow::mostrar_distancia()
{
    ui->plainTextEdit->clear();
    for(unsigned int i=0; i<marbol.size();i++){
        colorido(marbol[i].color);

        QString men=QString::fromStdString(marbol[i].tab)+QString::fromStdString(marbol[i].cordenada)+"  ";
        ui->plainTextEdit->insertPlainText(men);
        men="";

        for(unsigned int j=0; j<marbol[i].orden_visita.size(); j++){
            if(j==marbol[i].orden_visita.size()-1){
                ui->plainTextEdit->setTextColor(QColor("black"));
                men+=QString::number(marbol[i].orden_visita[j]);
            }
            else{
                men+=QString::number(marbol[i].orden_visita[j])+", ";
            }

        }
        ui->plainTextEdit->setTextColor(QColor("black"));
        ui->plainTextEdit->insertPlainText(men);
        men="     Distancia: "+QString::number(marbol[i].distancia)+"     Costo: "+QString::number(marbol[i].total);
        ui->plainTextEdit->insertPlainText(men);
        ui->plainTextEdit->insertPlainText("\n");
    }
    ui->plainTextEdit->setTextColor(QColor("black"));
}

void MainWindow::solucion_distancia()
{
    bloquear_botones();
    int costoso=0;
    bool ban=false;
    if(correcto==true){
        ban=true;
        nodo hijo=bpv(ant.cordenada,ant.padre);
        while(true){
            costoso+=hijo.costo;
            if(hijo.padre=="NA"){
                marcar_solucion(generar_xy(hijo.cordenada));
                break;
            }
            else{
                marcar_solucion(generar_xy(hijo.cordenada));
            }
            hijo=buscar_padre_anchura(hijo.padre);
        }

        ui->plainTextEdit->clear();
        QString texto="Nodo inicial: "+QString::fromStdString(generar_coordenada(inicial.x,inicial.y))+"\nNodo final: "
                +QString::fromStdString(generar_coordenada(final.x,final.y)+"\n\n");
        ui->plainTextEdit->insertPlainText(texto);
        ui->plainTextEdit->insertPlainText("La solucion final es:\n\n");
        QString cad="";
        hijo=bpv(ant.cordenada,ant.padre);
        while(true){
            if(hijo.padre=="NA"){
                cad=QString::fromStdString(hijo.cordenada)+cad;
                break;
            }
            else{
                cad=" -> "+QString::fromStdString(hijo.cordenada)+cad;
            }
            hijo=buscar_padre_anchura(hijo.padre);
        }
        ui->plainTextEdit->insertPlainText(cad);
    }
    else{
        ban=false;
        marcar_solucion(inicial);
        marcar_solucion(final);
        ui->plainTextEdit->clear();
        QString texto="Nodo inicial: "+QString::fromStdString(generar_coordenada(inicial.x,inicial.y))+"\nNodo final: "
                +QString::fromStdString(generar_coordenada(final.x,final.y)+"\n\n");
        ui->plainTextEdit->insertPlainText(texto);
        ui->plainTextEdit->insertPlainText("La solucion final es:\n\nNo se encontro solucion");
    }
    if(ban==true){
        QString cad="";
        ui->plainTextEdit->insertPlainText("\n\n");
        nodo hijo=bpv(ant.cordenada,ant.padre);
        nodo aux=hijo;
        while(true){
            if(hijo.padre=="NA"){
                cad=QString::number(hijo.costo)+cad;
                break;
            }
            else{
                cad=" -> "+QString::number(hijo.costo)+cad;
            }
            hijo=buscar_padre_anchura(hijo.padre);
        }
        ui->plainTextEdit->insertPlainText(cad);
        QString ms="\n\nCosto Final: "+QString::number(aux.total);
        ui->plainTextEdit->insertPlainText(ms);
    }
}

bool MainWindow::expandir_distancia(int x, int y, string letra, int nivel, string xypadre)
{
    nodo hijo;
    personaje per;
    for(unsigned int i=0; i<persona.size(); i++){
        if(persona[i].estado==1){
            per=persona[i];
            break;
        }
    }

    if(letra=="d"||letra=="D"){
        if(y<14){

            if(validar_campo(campo[x][y+1],per)){

                string cor=generar_coordenada(x,y+1);
                if(cor!="z"){
                    nodo padre=buscar_padre_voraz(generar_coordenada(x,y),xypadre,nivel);
                    if(padre.cordenada!="z"){
                        if(generar_costo(campo[x][y].icono)!=-1){
                            if(existe_hijo_voraz(cor,xypadre, padre.nivel+1)){
                                if(existe_hijo(cor)){
                                    hijo.cordenada=cor;
                                    hijo.estado="abierto";
                                    hijo.color=padre.color+1;
                                    hijo.otro="";
                                    hijo.nivel=padre.nivel+1;
                                    hijo.costo=generar_costo(campo[x][y+1].icono);
                                    hijo.total=padre.total+hijo.costo;
                                    hijo.distancia=generar_distancia(cordenada.x,cordenada.y+1,final.x,final.y);
                                   // qDebug()<<QString::number(hijo.distancia);
                                    hijo.padre=padre.cordenada;
                                    hijo.tab=padre.tab+"    ";
                                    insertar_en_costes(hijo,padre.nivel);
                                    return true;
                                }
                            }
                        }
                    }

                }
            }
        }
    }
    if(letra=="a"||letra=="A"){
        if(y>0){
            if(validar_campo(campo[x][y-1],per)){
                string cor=generar_coordenada(x,y-1);
                if(cor!="z"){
                    nodo padre=buscar_padre_voraz(generar_coordenada(x,y),xypadre,nivel);
                    if(padre.cordenada!="z"){
                        if(generar_costo(campo[x][y].icono)!=-1){
                            if(existe_hijo_voraz(cor,xypadre,padre.nivel+1)){
                                if(existe_hijo(cor)){
                                    hijo.cordenada=cor;
                                    hijo.estado="abierto";
                                    hijo.color=padre.color+1;
                                    hijo.otro="";
                                    hijo.nivel=padre.nivel+1;
                                    hijo.costo=generar_costo(campo[x][y-1].icono);
                                    hijo.total=padre.total+hijo.costo;
                                    hijo.distancia=generar_distancia(cordenada.x,cordenada.y-1,final.x,final.y);
                                   //  qDebug()<<QString::number(hijo.distancia);
                                    hijo.padre=padre.cordenada;
                                    hijo.tab=padre.tab+"    ";
                                    insertar_en_costes(hijo,padre.nivel);
                                    return true;
                                }
                            }
                        }
                    }
                }
            }
        }
    }
    if(letra=="s"||letra=="S"){
        if(x<14){
            if(validar_campo(campo[x+1][y],per)){
                string cor=generar_coordenada(x+1,y);
                if(cor!="z"){
                    nodo padre=buscar_padre_voraz(generar_coordenada(x,y),xypadre,nivel);
                    if(padre.cordenada!="z"){
                        if(generar_costo(campo[x][y].icono)!=-1){
                            if(existe_hijo_voraz(cor,xypadre,padre.nivel+1)){
                                if(existe_hijo(cor)){
                                    hijo.cordenada=cor;
                                    hijo.estado="abierto";
                                    hijo.color=padre.color+1;
                                    hijo.otro="";
                                    hijo.nivel=padre.nivel+1;
                                    hijo.costo=generar_costo(campo[x+1][y].icono);
                                    hijo.total=padre.total+hijo.costo;
                                    hijo.distancia=generar_distancia(cordenada.x+1,cordenada.y,final.x,final.y);
                                    // qDebug()<<QString::number(hijo.distancia);
                                    hijo.padre=padre.cordenada;
                                    hijo.tab=padre.tab+"    ";
                                    insertar_en_costes(hijo,padre.nivel);
                                    return true;
                                }
                            }
                        }
                    }
                }
            }
        }
    }
    if(letra=="w"||letra=="W"){
        if(x>0){
            if(validar_campo(campo[x-1][y],per)){
                string cor=generar_coordenada(x-1,y);
                if(cor!="z"){
                    nodo padre=buscar_padre_voraz(generar_coordenada(x,y),xypadre,nivel);
                    if(padre.cordenada!="z"){
                        if(generar_costo(campo[x][y].icono)!=-1){
                            if(existe_hijo_voraz(cor,xypadre,padre.nivel+1)){
                                if(existe_hijo(cor)){
                                    hijo.cordenada=cor;
                                    hijo.estado="abierto";
                                    hijo.color=padre.color+1;
                                    hijo.otro="";
                                    hijo.nivel=padre.nivel+1;
                                    hijo.costo=generar_costo(campo[x-1][y].icono);
                                    hijo.total=padre.total+hijo.costo;
                                    hijo.distancia=generar_distancia(cordenada.x-1,cordenada.y,final.x,final.y);
                                    // qDebug()<<QString::number(hijo.distancia);
                                    hijo.padre=padre.cordenada;
                                    hijo.tab=padre.tab+"    ";
                                    insertar_en_costes(hijo,padre.nivel);
                                    return true;
                                }
                            }
                        }
                    }
                }
            }
        }
    }
    return false;
}

void MainWindow::primero_mejor()
{
    coordenada f;
    nodo auxi;
    coordenada auxpadre, auxhijo;
    f.x=f.y=20;
 string orden=prioridad[0]+prioridad[1]+prioridad[2]+prioridad[3];
    while(true){

        if(pilaback.size()>0){
            visitas(pilaback[0],num_visita);
            num_visita++;
            on_pushButton_3_clicked();
            QTime dieTime= QTime::currentTime().addSecs(1);
            while (QTime::currentTime() < dieTime)
                QCoreApplication::processEvents(QEventLoop::AllEvents,1);
            auxhijo=generar_xy(pilaback[0].cordenada);
            nodo pilabac=pilaback[0];

            if(pilaback.size()>1){
                auxi=pilaback[0];
                ant=auxi;
            }
            else{
                auxi=pilaback[0];
                ant=auxi;
            }
            pop_front();
            if(orden=="abid"){
                expandir_distancia(cordenada.x,cordenada.y,"W",pilabac.nivel,pilabac.cordenada);
                expandir_distancia(cordenada.x,cordenada.y,"S",pilabac.nivel,pilabac.cordenada);
                expandir_distancia(cordenada.x,cordenada.y,"A",pilabac.nivel,pilabac.cordenada);
                expandir_distancia(cordenada.x,cordenada.y,"D",pilabac.nivel,pilabac.cordenada);
            }
            if(orden=="abdi"){
                expandir_distancia(cordenada.x,cordenada.y,"W",pilabac.nivel,pilabac.cordenada);
                expandir_distancia(cordenada.x,cordenada.y,"S",pilabac.nivel,pilabac.cordenada);
                expandir_distancia(cordenada.x,cordenada.y,"D",pilabac.nivel,pilabac.cordenada);
                expandir_distancia(cordenada.x,cordenada.y,"A",pilabac.nivel,pilabac.cordenada);
            }
            if(orden=="adbi"){
                expandir_distancia(cordenada.x,cordenada.y,"W",pilabac.nivel,pilabac.cordenada);
                expandir_distancia(cordenada.x,cordenada.y,"D",pilabac.nivel,pilabac.cordenada);
                expandir_distancia(cordenada.x,cordenada.y,"S",pilabac.nivel,pilabac.cordenada);
                expandir_distancia(cordenada.x,cordenada.y,"A",pilabac.nivel,pilabac.cordenada);
            }
            if(orden=="adib"){
                expandir_distancia(cordenada.x,cordenada.y,"W",pilabac.nivel,pilabac.cordenada);
                expandir_distancia(cordenada.x,cordenada.y,"D",pilabac.nivel,pilabac.cordenada);
                expandir_distancia(cordenada.x,cordenada.y,"A",pilabac.nivel,pilabac.cordenada);
                expandir_distancia(cordenada.x,cordenada.y,"S",pilabac.nivel,pilabac.cordenada);
            }
            if(orden=="aibd"){
                expandir_distancia(cordenada.x,cordenada.y,"W",pilabac.nivel,pilabac.cordenada);
                expandir_distancia(cordenada.x,cordenada.y,"A",pilabac.nivel,pilabac.cordenada);
                expandir_distancia(cordenada.x,cordenada.y,"S",pilabac.nivel,pilabac.cordenada);
                expandir_distancia(cordenada.x,cordenada.y,"D",pilabac.nivel,pilabac.cordenada);
            }
            if(orden=="aidb"){
                expandir_distancia(cordenada.x,cordenada.y,"W",pilabac.nivel,pilabac.cordenada);
                expandir_distancia(cordenada.x,cordenada.y,"A",pilabac.nivel,pilabac.cordenada);
                expandir_distancia(cordenada.x,cordenada.y,"D",pilabac.nivel,pilabac.cordenada);
                expandir_distancia(cordenada.x,cordenada.y,"S",pilabac.nivel,pilabac.cordenada);
            }

            if(orden=="baid"){
                expandir_distancia(cordenada.x,cordenada.y,"S",pilabac.nivel,pilabac.cordenada);
                expandir_distancia(cordenada.x,cordenada.y,"W",pilabac.nivel,pilabac.cordenada);
                expandir_distancia(cordenada.x,cordenada.y,"A",pilabac.nivel,pilabac.cordenada);
                expandir_distancia(cordenada.x,cordenada.y,"D",pilabac.nivel,pilabac.cordenada);
            }
            if(orden=="badi"){
                expandir_distancia(cordenada.x,cordenada.y,"S",pilabac.nivel,pilabac.cordenada);
                expandir_distancia(cordenada.x,cordenada.y,"W",pilabac.nivel,pilabac.cordenada);
                expandir_distancia(cordenada.x,cordenada.y,"D",pilabac.nivel,pilabac.cordenada);
                expandir_distancia(cordenada.x,cordenada.y,"A",pilabac.nivel,pilabac.cordenada);
            }
            if(orden=="biad"){
                expandir_distancia(cordenada.x,cordenada.y,"S",pilabac.nivel,pilabac.cordenada);
                expandir_distancia(cordenada.x,cordenada.y,"A",pilabac.nivel,pilabac.cordenada);
                expandir_distancia(cordenada.x,cordenada.y,"W",pilabac.nivel,pilabac.cordenada);
                expandir_distancia(cordenada.x,cordenada.y,"D",pilabac.nivel,pilabac.cordenada);
            }
            if(orden=="bida"){
                expandir_distancia(cordenada.x,cordenada.y,"S",pilabac.nivel,pilabac.cordenada);
                expandir_distancia(cordenada.x,cordenada.y,"A",pilabac.nivel,pilabac.cordenada);
                expandir_distancia(cordenada.x,cordenada.y,"D",pilabac.nivel,pilabac.cordenada);
                expandir_distancia(cordenada.x,cordenada.y,"W",pilabac.nivel,pilabac.cordenada);
            }
            if(orden=="bdai"){
                expandir_distancia(cordenada.x,cordenada.y,"S",pilabac.nivel,pilabac.cordenada);
                expandir_distancia(cordenada.x,cordenada.y,"D",pilabac.nivel,pilabac.cordenada);
                expandir_distancia(cordenada.x,cordenada.y,"W",pilabac.nivel,pilabac.cordenada);
                expandir_distancia(cordenada.x,cordenada.y,"A",pilabac.nivel,pilabac.cordenada);
            }
            if(orden=="bdia"){
                expandir_distancia(cordenada.x,cordenada.y,"S",pilabac.nivel,pilabac.cordenada);
                expandir_distancia(cordenada.x,cordenada.y,"D",pilabac.nivel,pilabac.cordenada);
                expandir_distancia(cordenada.x,cordenada.y,"A",pilabac.nivel,pilabac.cordenada);
                expandir_distancia(cordenada.x,cordenada.y,"W",pilabac.nivel,pilabac.cordenada);
            }

            if(orden=="iabd"){
                expandir_distancia(cordenada.x,cordenada.y,"A",pilabac.nivel,pilabac.cordenada);
                expandir_distancia(cordenada.x,cordenada.y,"W",pilabac.nivel,pilabac.cordenada);
                expandir_distancia(cordenada.x,cordenada.y,"S",pilabac.nivel,pilabac.cordenada);
                expandir_distancia(cordenada.x,cordenada.y,"D",pilabac.nivel,pilabac.cordenada);
            }
            if(orden=="iadb"){
                expandir_distancia(cordenada.x,cordenada.y,"A",pilabac.nivel,pilabac.cordenada);
                expandir_distancia(cordenada.x,cordenada.y,"W",pilabac.nivel,pilabac.cordenada);
                expandir_distancia(cordenada.x,cordenada.y,"D",pilabac.nivel,pilabac.cordenada);
                expandir_distancia(cordenada.x,cordenada.y,"S",pilabac.nivel,pilabac.cordenada);
            }
            if(orden=="ibad"){
                expandir_distancia(cordenada.x,cordenada.y,"A",pilabac.nivel,pilabac.cordenada);
                expandir_distancia(cordenada.x,cordenada.y,"S",pilabac.nivel,pilabac.cordenada);
                expandir_distancia(cordenada.x,cordenada.y,"W",pilabac.nivel,pilabac.cordenada);
                expandir_distancia(cordenada.x,cordenada.y,"D",pilabac.nivel,pilabac.cordenada);
            }
            if(orden=="ibda"){
                expandir_distancia(cordenada.x,cordenada.y,"A",pilabac.nivel,pilabac.cordenada);
                expandir_distancia(cordenada.x,cordenada.y,"S",pilabac.nivel,pilabac.cordenada);
                expandir_distancia(cordenada.x,cordenada.y,"D",pilabac.nivel,pilabac.cordenada);
                expandir_distancia(cordenada.x,cordenada.y,"W",pilabac.nivel,pilabac.cordenada);
            }
            if(orden=="idab"){
                expandir_distancia(cordenada.x,cordenada.y,"A",pilabac.nivel,pilabac.cordenada);
                expandir_distancia(cordenada.x,cordenada.y,"D",pilabac.nivel,pilabac.cordenada);
                expandir_distancia(cordenada.x,cordenada.y,"W",pilabac.nivel,pilabac.cordenada);
                expandir_distancia(cordenada.x,cordenada.y,"S",pilabac.nivel,pilabac.cordenada);
            }
            if(orden=="idba"){
                expandir_distancia(cordenada.x,cordenada.y,"A",pilabac.nivel,pilabac.cordenada);
                expandir_distancia(cordenada.x,cordenada.y,"D",pilabac.nivel,pilabac.cordenada);
                expandir_distancia(cordenada.x,cordenada.y,"S",pilabac.nivel,pilabac.cordenada);
                expandir_distancia(cordenada.x,cordenada.y,"W",pilabac.nivel,pilabac.cordenada);
            }

            if(orden=="dabi"){
                expandir_distancia(cordenada.x,cordenada.y,"D",pilabac.nivel,pilabac.cordenada);
                expandir_distancia(cordenada.x,cordenada.y,"W",pilabac.nivel,pilabac.cordenada);
                expandir_distancia(cordenada.x,cordenada.y,"S",pilabac.nivel,pilabac.cordenada);
                expandir_distancia(cordenada.x,cordenada.y,"A",pilabac.nivel,pilabac.cordenada);
            }
            if(orden=="daib"){
                expandir_distancia(cordenada.x,cordenada.y,"D",pilabac.nivel,pilabac.cordenada);
                expandir_distancia(cordenada.x,cordenada.y,"W",pilabac.nivel,pilabac.cordenada);
                expandir_distancia(cordenada.x,cordenada.y,"A",pilabac.nivel,pilabac.cordenada);
                expandir_distancia(cordenada.x,cordenada.y,"S",pilabac.nivel,pilabac.cordenada);
            }
            if(orden=="dbai"){
                expandir_distancia(cordenada.x,cordenada.y,"D",pilabac.nivel,pilabac.cordenada);
                expandir_distancia(cordenada.x,cordenada.y,"S",pilabac.nivel,pilabac.cordenada);
                expandir_distancia(cordenada.x,cordenada.y,"W",pilabac.nivel,pilabac.cordenada);
                expandir_distancia(cordenada.x,cordenada.y,"A",pilabac.nivel,pilabac.cordenada);
            }
            if(orden=="dbia"){
                expandir_distancia(cordenada.x,cordenada.y,"D",pilabac.nivel,pilabac.cordenada);
                expandir_distancia(cordenada.x,cordenada.y,"S",pilabac.nivel,pilabac.cordenada);
                expandir_distancia(cordenada.x,cordenada.y,"A",pilabac.nivel,pilabac.cordenada);
                expandir_distancia(cordenada.x,cordenada.y,"W",pilabac.nivel,pilabac.cordenada);
            }
            if(orden=="diab"){
                expandir_distancia(cordenada.x,cordenada.y,"D",pilabac.nivel,pilabac.cordenada);
                expandir_distancia(cordenada.x,cordenada.y,"A",pilabac.nivel,pilabac.cordenada);
                expandir_distancia(cordenada.x,cordenada.y,"W",pilabac.nivel,pilabac.cordenada);
                expandir_distancia(cordenada.x,cordenada.y,"S",pilabac.nivel,pilabac.cordenada);
            }
            if(orden=="diba"){
                expandir_distancia(cordenada.x,cordenada.y,"D",pilabac.nivel,pilabac.cordenada);
                expandir_distancia(cordenada.x,cordenada.y,"A",pilabac.nivel,pilabac.cordenada);
                expandir_distancia(cordenada.x,cordenada.y,"S",pilabac.nivel,pilabac.cordenada);
                expandir_distancia(cordenada.x,cordenada.y,"W",pilabac.nivel,pilabac.cordenada);
            }

            ordenar_distancia();
            qDebug()<<QString::fromStdString(pilabac.cordenada);


            auxpadre=generar_xy(pilaback[0].cordenada);
            mover(auxhijo.x,auxhijo.y,auxpadre.x,auxpadre.y,cordenada.nombre);
            desbloquear(auxpadre.x, auxpadre.y,f);
            string name=cordenada.nombre;
            cordenada=generar_xy(pilaback[0].cordenada);
            cordenada.nombre=name;
        }
        else {
            QMessageBox msg;
            activo=1;
            msg.setText("El algoritmo no encontro una solucion");
            msg.exec();
            correcto=false;
            break;
        }
        if(final.x==cordenada.x && final.y==cordenada.y){
            correcto=true;
            //visitas(bpv(auxi.cordenada,auxi.padre),num_visita);
            auxi=buscar_padre_anchura(generar_coordenada(final.x,final.y));
            visitas(auxi,num_visita);
            ant=auxi;
            num_visita++;
            on_pushButton_3_clicked();
            activo=1;
            QMessageBox msg;
            msg.setText("Felicidades llego a su destino\nPara volver a recorrer el mapa presiona el boton reiniciar");
            msg.exec();

            validar_cordenada(final.x+1,final.y+1,campo[final.x][final.y].icono);
            on_pushButton_4_clicked();
            break;
        }

    }
}

bool MainWindow::expandir_A(int x, int y, string letra, int nivel, string xypadre)
{
    nodo hijo;
    personaje per;
    for(unsigned int i=0; i<persona.size(); i++){
        if(persona[i].estado==1){
            per=persona[i];
            break;
        }
    }

    if(letra=="d"||letra=="D"){
        if(y<14){

            if(validar_campo(campo[x][y+1],per)){

                string cor=generar_coordenada(x,y+1);
                if(cor!="z"){
                    nodo padre=buscar_padre_voraz(generar_coordenada(x,y),xypadre,nivel);
                    if(padre.cordenada!="z"){
                        if(generar_costo(campo[x][y].icono)!=-1){
                            if(existe_hijo_voraz(cor,xypadre, padre.nivel+1)){
                                if(existe_hijo(cor)){
                                    hijo.cordenada=cor;
                                    hijo.estado="abierto";
                                    hijo.color=padre.color+1;
                                    hijo.otro="";
                                    hijo.nivel=padre.nivel+1;
                                    hijo.costo=generar_costo(campo[x][y+1].icono);
                                    hijo.total=padre.total+hijo.costo;
                                    hijo.distancia=generar_distancia(cordenada.x,cordenada.y+1,final.x,final.y);
                                   // qDebug()<<QString::number(hijo.distancia);
                                    hijo.tot=hijo.total+hijo.distancia;
                                    hijo.padre=padre.cordenada;
                                    hijo.tab=padre.tab+"    ";
                                    insertar_en_costes(hijo,padre.nivel);
                                    return true;
                                }
                            }
                        }
                    }

                }
            }
        }
    }
    if(letra=="a"||letra=="A"){
        if(y>0){
            if(validar_campo(campo[x][y-1],per)){
                string cor=generar_coordenada(x,y-1);
                if(cor!="z"){
                    nodo padre=buscar_padre_voraz(generar_coordenada(x,y),xypadre,nivel);
                    if(padre.cordenada!="z"){
                        if(generar_costo(campo[x][y].icono)!=-1){
                            if(existe_hijo_voraz(cor,xypadre,padre.nivel+1)){
                                if(existe_hijo(cor)){
                                    hijo.cordenada=cor;
                                    hijo.estado="abierto";
                                    hijo.color=padre.color+1;
                                    hijo.otro="";
                                    hijo.nivel=padre.nivel+1;
                                    hijo.costo=generar_costo(campo[x][y-1].icono);
                                    hijo.total=padre.total+hijo.costo;
                                    hijo.distancia=generar_distancia(cordenada.x,cordenada.y-1,final.x,final.y);
                                   //  qDebug()<<QString::number(hijo.distancia);
                                    hijo.tot=hijo.total+hijo.distancia;
                                    hijo.padre=padre.cordenada;
                                    hijo.tab=padre.tab+"    ";
                                    insertar_en_costes(hijo,padre.nivel);
                                    return true;
                                }
                            }
                        }
                    }
                }
            }
        }
    }
    if(letra=="s"||letra=="S"){
        if(x<14){
            if(validar_campo(campo[x+1][y],per)){
                string cor=generar_coordenada(x+1,y);
                if(cor!="z"){
                    nodo padre=buscar_padre_voraz(generar_coordenada(x,y),xypadre,nivel);
                    if(padre.cordenada!="z"){
                        if(generar_costo(campo[x][y].icono)!=-1){
                            if(existe_hijo_voraz(cor,xypadre,padre.nivel+1)){
                                if(existe_hijo(cor)){
                                    hijo.cordenada=cor;
                                    hijo.estado="abierto";
                                    hijo.color=padre.color+1;
                                    hijo.otro="";
                                    hijo.nivel=padre.nivel+1;
                                    hijo.costo=generar_costo(campo[x+1][y].icono);
                                    hijo.total=padre.total+hijo.costo;
                                    hijo.distancia=generar_distancia(cordenada.x+1,cordenada.y,final.x,final.y);
                                    // qDebug()<<QString::number(hijo.distancia);
                                    hijo.tot=hijo.total+hijo.distancia;
                                    hijo.padre=padre.cordenada;
                                    hijo.tab=padre.tab+"    ";
                                    insertar_en_costes(hijo,padre.nivel);
                                    return true;
                                }
                            }
                        }
                    }
                }
            }
        }
    }
    if(letra=="w"||letra=="W"){
        if(x>0){
            if(validar_campo(campo[x-1][y],per)){
                string cor=generar_coordenada(x-1,y);
                if(cor!="z"){
                    nodo padre=buscar_padre_voraz(generar_coordenada(x,y),xypadre,nivel);
                    if(padre.cordenada!="z"){
                        if(generar_costo(campo[x][y].icono)!=-1){
                            if(existe_hijo_voraz(cor,xypadre,padre.nivel+1)){
                                if(existe_hijo(cor)){
                                    hijo.cordenada=cor;
                                    hijo.estado="abierto";
                                    hijo.color=padre.color+1;
                                    hijo.otro="";
                                    hijo.nivel=padre.nivel+1;
                                    hijo.costo=generar_costo(campo[x-1][y].icono);
                                    hijo.total=padre.total+hijo.costo;
                                    hijo.distancia=generar_distancia(cordenada.x-1,cordenada.y,final.x,final.y);
                                    hijo.tot=hijo.total+hijo.distancia;
                                    // qDebug()<<QString::number(hijo.distancia);
                                    hijo.padre=padre.cordenada;
                                    hijo.tab=padre.tab+"    ";
                                    insertar_en_costes(hijo,padre.nivel);
                                    return true;
                                }
                            }
                        }
                    }
                }
            }
        }
    }
    return false;
}

void MainWindow::mostrar_A()
{
    ui->plainTextEdit->clear();
    for(unsigned int i=0; i<marbol.size();i++){
        colorido(marbol[i].color);

        QString men=QString::fromStdString(marbol[i].tab)+QString::fromStdString(marbol[i].cordenada)+"  ";
        ui->plainTextEdit->insertPlainText(men);
        men="";

        for(unsigned int j=0; j<marbol[i].orden_visita.size(); j++){
            if(j==marbol[i].orden_visita.size()-1){
                ui->plainTextEdit->setTextColor(QColor("black"));
                men+=QString::number(marbol[i].orden_visita[j]);
            }
            else{
                men+=QString::number(marbol[i].orden_visita[j])+", ";
            }

        }
        ui->plainTextEdit->setTextColor(QColor("black"));
        ui->plainTextEdit->insertPlainText(men);
        men="     Distancia: "+QString::number(marbol[i].distancia)+ "     Costo: "+QString::number(marbol[i].total)+"    Total: "+QString::number(marbol[i].tot);
        ui->plainTextEdit->insertPlainText(men);
        ui->plainTextEdit->insertPlainText("\n");
    }
    ui->plainTextEdit->setTextColor(QColor("black"));
}

void MainWindow::ordenar_A()
{
    for(unsigned int i=0;i<pilaback.size()-1;i++)
    {
        for(unsigned int j=0;j<pilaback.size()-i-1;j++)
        {
            if(pilaback[j].tot>pilaback[j+1].tot)
            {
                nodo k=pilaback[j];
                pilaback[j]=pilaback[j+1];
                pilaback[j+1]=k;
            }
        }
    }
}

void MainWindow::A()
{
    coordenada f;
    coordenada auxpadre, auxhijo;
    nodo auxi;
    f.x=f.y=20;
 string orden=prioridad[0]+prioridad[1]+prioridad[2]+prioridad[3];
    while(true){

        if(pilaback.size()>0){
            visitas(pilaback[0],num_visita);
            num_visita++;
            on_pushButton_3_clicked();
            QTime dieTime= QTime::currentTime().addSecs(1);
            while (QTime::currentTime() < dieTime)
                QCoreApplication::processEvents(QEventLoop::AllEvents,1);
            auxhijo=generar_xy(pilaback[0].cordenada);
            nodo pilabac=pilaback[0];
            if(pilaback.size()>1)
            {
                auxi=pilaback[1];
                ant=auxi;
            }
            pop_front();
            if(orden=="abid"){
                expandir_A(cordenada.x,cordenada.y,"W",pilabac.nivel,pilabac.cordenada);
                expandir_A(cordenada.x,cordenada.y,"S",pilabac.nivel,pilabac.cordenada);
                expandir_A(cordenada.x,cordenada.y,"A",pilabac.nivel,pilabac.cordenada);
                expandir_A(cordenada.x,cordenada.y,"D",pilabac.nivel,pilabac.cordenada);
            }
            if(orden=="abdi"){
                expandir_A(cordenada.x,cordenada.y,"W",pilabac.nivel,pilabac.cordenada);
                expandir_A(cordenada.x,cordenada.y,"S",pilabac.nivel,pilabac.cordenada);
                expandir_A(cordenada.x,cordenada.y,"D",pilabac.nivel,pilabac.cordenada);
                expandir_A(cordenada.x,cordenada.y,"A",pilabac.nivel,pilabac.cordenada);
            }
            if(orden=="adbi"){
                expandir_A(cordenada.x,cordenada.y,"W",pilabac.nivel,pilabac.cordenada);
                expandir_A(cordenada.x,cordenada.y,"D",pilabac.nivel,pilabac.cordenada);
                expandir_A(cordenada.x,cordenada.y,"S",pilabac.nivel,pilabac.cordenada);
                expandir_A(cordenada.x,cordenada.y,"A",pilabac.nivel,pilabac.cordenada);
            }
            if(orden=="adib"){
                expandir_A(cordenada.x,cordenada.y,"W",pilabac.nivel,pilabac.cordenada);
                expandir_A(cordenada.x,cordenada.y,"D",pilabac.nivel,pilabac.cordenada);
                expandir_A(cordenada.x,cordenada.y,"A",pilabac.nivel,pilabac.cordenada);
                expandir_A(cordenada.x,cordenada.y,"S",pilabac.nivel,pilabac.cordenada);
            }
            if(orden=="aibd"){
                expandir_A(cordenada.x,cordenada.y,"W",pilabac.nivel,pilabac.cordenada);
                expandir_A(cordenada.x,cordenada.y,"A",pilabac.nivel,pilabac.cordenada);
                expandir_A(cordenada.x,cordenada.y,"S",pilabac.nivel,pilabac.cordenada);
                expandir_A(cordenada.x,cordenada.y,"D",pilabac.nivel,pilabac.cordenada);
            }
            if(orden=="aidb"){
                expandir_A(cordenada.x,cordenada.y,"W",pilabac.nivel,pilabac.cordenada);
                expandir_A(cordenada.x,cordenada.y,"A",pilabac.nivel,pilabac.cordenada);
                expandir_A(cordenada.x,cordenada.y,"D",pilabac.nivel,pilabac.cordenada);
                expandir_A(cordenada.x,cordenada.y,"S",pilabac.nivel,pilabac.cordenada);
            }

            if(orden=="baid"){
                expandir_A(cordenada.x,cordenada.y,"S",pilabac.nivel,pilabac.cordenada);
                expandir_A(cordenada.x,cordenada.y,"W",pilabac.nivel,pilabac.cordenada);
                expandir_A(cordenada.x,cordenada.y,"A",pilabac.nivel,pilabac.cordenada);
                expandir_A(cordenada.x,cordenada.y,"D",pilabac.nivel,pilabac.cordenada);
            }
            if(orden=="badi"){
                expandir_A(cordenada.x,cordenada.y,"S",pilabac.nivel,pilabac.cordenada);
                expandir_A(cordenada.x,cordenada.y,"W",pilabac.nivel,pilabac.cordenada);
                expandir_A(cordenada.x,cordenada.y,"D",pilabac.nivel,pilabac.cordenada);
                expandir_A(cordenada.x,cordenada.y,"A",pilabac.nivel,pilabac.cordenada);
            }
            if(orden=="biad"){
                expandir_A(cordenada.x,cordenada.y,"S",pilabac.nivel,pilabac.cordenada);
                expandir_A(cordenada.x,cordenada.y,"A",pilabac.nivel,pilabac.cordenada);
                expandir_A(cordenada.x,cordenada.y,"W",pilabac.nivel,pilabac.cordenada);
                expandir_A(cordenada.x,cordenada.y,"D",pilabac.nivel,pilabac.cordenada);
            }
            if(orden=="bida"){
                expandir_A(cordenada.x,cordenada.y,"S",pilabac.nivel,pilabac.cordenada);
                expandir_A(cordenada.x,cordenada.y,"A",pilabac.nivel,pilabac.cordenada);
                expandir_A(cordenada.x,cordenada.y,"D",pilabac.nivel,pilabac.cordenada);
                expandir_A(cordenada.x,cordenada.y,"W",pilabac.nivel,pilabac.cordenada);
            }
            if(orden=="bdai"){
                expandir_A(cordenada.x,cordenada.y,"S",pilabac.nivel,pilabac.cordenada);
                expandir_A(cordenada.x,cordenada.y,"D",pilabac.nivel,pilabac.cordenada);
                expandir_A(cordenada.x,cordenada.y,"W",pilabac.nivel,pilabac.cordenada);
                expandir_A(cordenada.x,cordenada.y,"A",pilabac.nivel,pilabac.cordenada);
            }
            if(orden=="bdia"){
                expandir_A(cordenada.x,cordenada.y,"S",pilabac.nivel,pilabac.cordenada);
                expandir_A(cordenada.x,cordenada.y,"D",pilabac.nivel,pilabac.cordenada);
                expandir_A(cordenada.x,cordenada.y,"A",pilabac.nivel,pilabac.cordenada);
                expandir_A(cordenada.x,cordenada.y,"W",pilabac.nivel,pilabac.cordenada);
            }

            if(orden=="iabd"){
                expandir_A(cordenada.x,cordenada.y,"A",pilabac.nivel,pilabac.cordenada);
                expandir_A(cordenada.x,cordenada.y,"W",pilabac.nivel,pilabac.cordenada);
                expandir_A(cordenada.x,cordenada.y,"S",pilabac.nivel,pilabac.cordenada);
                expandir_A(cordenada.x,cordenada.y,"D",pilabac.nivel,pilabac.cordenada);
            }
            if(orden=="iadb"){
                expandir_A(cordenada.x,cordenada.y,"A",pilabac.nivel,pilabac.cordenada);
                expandir_A(cordenada.x,cordenada.y,"W",pilabac.nivel,pilabac.cordenada);
                expandir_A(cordenada.x,cordenada.y,"D",pilabac.nivel,pilabac.cordenada);
                expandir_A(cordenada.x,cordenada.y,"S",pilabac.nivel,pilabac.cordenada);
            }
            if(orden=="ibad"){
                expandir_A(cordenada.x,cordenada.y,"A",pilabac.nivel,pilabac.cordenada);
                expandir_A(cordenada.x,cordenada.y,"S",pilabac.nivel,pilabac.cordenada);
                expandir_A(cordenada.x,cordenada.y,"W",pilabac.nivel,pilabac.cordenada);
                expandir_A(cordenada.x,cordenada.y,"D",pilabac.nivel,pilabac.cordenada);
            }
            if(orden=="ibda"){
                expandir_A(cordenada.x,cordenada.y,"A",pilabac.nivel,pilabac.cordenada);
                expandir_A(cordenada.x,cordenada.y,"S",pilabac.nivel,pilabac.cordenada);
                expandir_A(cordenada.x,cordenada.y,"D",pilabac.nivel,pilabac.cordenada);
                expandir_A(cordenada.x,cordenada.y,"W",pilabac.nivel,pilabac.cordenada);
            }
            if(orden=="idab"){
                expandir_A(cordenada.x,cordenada.y,"A",pilabac.nivel,pilabac.cordenada);
                expandir_A(cordenada.x,cordenada.y,"D",pilabac.nivel,pilabac.cordenada);
                expandir_A(cordenada.x,cordenada.y,"W",pilabac.nivel,pilabac.cordenada);
                expandir_A(cordenada.x,cordenada.y,"S",pilabac.nivel,pilabac.cordenada);
            }
            if(orden=="idba"){
                expandir_A(cordenada.x,cordenada.y,"A",pilabac.nivel,pilabac.cordenada);
                expandir_A(cordenada.x,cordenada.y,"D",pilabac.nivel,pilabac.cordenada);
                expandir_A(cordenada.x,cordenada.y,"S",pilabac.nivel,pilabac.cordenada);
                expandir_A(cordenada.x,cordenada.y,"W",pilabac.nivel,pilabac.cordenada);
            }

            if(orden=="dabi"){
                expandir_A(cordenada.x,cordenada.y,"D",pilabac.nivel,pilabac.cordenada);
                expandir_A(cordenada.x,cordenada.y,"W",pilabac.nivel,pilabac.cordenada);
                expandir_A(cordenada.x,cordenada.y,"S",pilabac.nivel,pilabac.cordenada);
                expandir_A(cordenada.x,cordenada.y,"A",pilabac.nivel,pilabac.cordenada);
            }
            if(orden=="daib"){
                expandir_A(cordenada.x,cordenada.y,"D",pilabac.nivel,pilabac.cordenada);
                expandir_A(cordenada.x,cordenada.y,"W",pilabac.nivel,pilabac.cordenada);
                expandir_A(cordenada.x,cordenada.y,"A",pilabac.nivel,pilabac.cordenada);
                expandir_A(cordenada.x,cordenada.y,"S",pilabac.nivel,pilabac.cordenada);
            }
            if(orden=="dbai"){
                expandir_A(cordenada.x,cordenada.y,"D",pilabac.nivel,pilabac.cordenada);
                expandir_A(cordenada.x,cordenada.y,"S",pilabac.nivel,pilabac.cordenada);
                expandir_A(cordenada.x,cordenada.y,"W",pilabac.nivel,pilabac.cordenada);
                expandir_A(cordenada.x,cordenada.y,"A",pilabac.nivel,pilabac.cordenada);
            }
            if(orden=="dbia"){
                expandir_A(cordenada.x,cordenada.y,"D",pilabac.nivel,pilabac.cordenada);
                expandir_A(cordenada.x,cordenada.y,"S",pilabac.nivel,pilabac.cordenada);
                expandir_A(cordenada.x,cordenada.y,"A",pilabac.nivel,pilabac.cordenada);
                expandir_A(cordenada.x,cordenada.y,"W",pilabac.nivel,pilabac.cordenada);
            }
            if(orden=="diab"){
                expandir_A(cordenada.x,cordenada.y,"D",pilabac.nivel,pilabac.cordenada);
                expandir_A(cordenada.x,cordenada.y,"A",pilabac.nivel,pilabac.cordenada);
                expandir_A(cordenada.x,cordenada.y,"W",pilabac.nivel,pilabac.cordenada);
                expandir_A(cordenada.x,cordenada.y,"S",pilabac.nivel,pilabac.cordenada);
            }
            if(orden=="diba"){
                expandir_A(cordenada.x,cordenada.y,"D",pilabac.nivel,pilabac.cordenada);
                expandir_A(cordenada.x,cordenada.y,"A",pilabac.nivel,pilabac.cordenada);
                expandir_A(cordenada.x,cordenada.y,"S",pilabac.nivel,pilabac.cordenada);
                expandir_A(cordenada.x,cordenada.y,"W",pilabac.nivel,pilabac.cordenada);
            }
            ordenar_A();


            auxpadre=generar_xy(pilaback[0].cordenada);
            mover(auxhijo.x,auxhijo.y,auxpadre.x,auxpadre.y,cordenada.nombre);
            desbloquear(auxpadre.x, auxpadre.y,f);
            string name=cordenada.nombre;
            cordenada=generar_xy(pilaback[0].cordenada);
            cordenada.nombre=name;
        }
        else {
            QMessageBox msg;
            activo=1;
            msg.setText("El algoritmo no encontro una solucion");
            msg.exec();
            correcto=false;
            break;
        }
        if(final.x==cordenada.x && final.y==cordenada.y){
            correcto=true;
            visitas(bpv(auxi.cordenada,auxi.padre),num_visita);
            num_visita++;
            on_pushButton_3_clicked();
            activo=1;
            QMessageBox msg;
            msg.setText("Felicidades llego a su destino\nPara volver a recorrer el mapa presiona el boton reiniciar");
            msg.exec();

            validar_cordenada(final.x+1,final.y+1,campo[final.x][final.y].icono);
            on_pushButton_4_clicked();
            break;
        }

    }
}

nodo MainWindow::bpv(string hijo,string padr){
    nodo padre;
    for(unsigned int i=0; i<marbol.size(); i++){
        if(marbol[i].cordenada==hijo&&marbol[i].padre==padr){
            padre=marbol[i];
            break;
        }
    }
    return padre;
}

