#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <iostream>
#include <QLineEdit>
#include <QWidget>
#include <QIcon>
#include "principal.h"
#include "nodo.h"

using namespace std;

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

    terreno campo[15][15];
    terreno campaux[15][15];
    vector <personaje> persona;
    //personaje per;
    bool validar_campo(terreno, personaje);

public:
    vector <terreno> terren;
    coordenada cordenada;
    coordenada final;
    coordenada inicial;
    vector <string> prioridad;
    nodo ant;
    nodo bpv(string hijo, string padr);



    void cargar_terreno();
    void cargar_personajes();
    void generar_terreno();
    QIcon generar_icono(string);
    void generar_personajes();
    void validar_cordenada(int, int, string);
    void desbloquear(int, int, coordenada);
    void desbloquear_final(coordenada);
    void bloquear_botones();
    void cargar_repetidos();
    bool mover(int,int,int,int,string);
    int num_visita;
    int activo=0;
    int orden=1;
    int color=0;
    void colorido(int color);
    vector <nodo> marbol;
    vector <nodo> pilaback;

    string generar_coordenada(int x, int y);
    void insertar_en_pila(nodo hijo);
    nodo buscar_padre(string xy);
    void backtracking();
    bool mover2(string letra);
    bool expandir(int x, int y, string letra);
    coordenada generar_xy(string cord);
    bool existe_hijo(string xy);
    void marcar_solucion(coordenada cor);

    //
    void anchura();
    void pop_front();
    void solucion();
    nodo buscar_padre_anchura(string xy);
    int algoritmo;
    int tipo=0;
    bool correcto;
    void mostrar_arbol();

    //
    void visitas(nodo aux, int visita);
    void profundidad();
    void pop_profundidad();

    //costes uniformes

    float generar_costo(string nomre);
    void insertar_en_costes(nodo hijo, int nivel);
    bool expandir_voraz(int x, int y, string letra, int nivel, string xypadre);
    void ordenar();
    void costes_uniformes();
    nodo buscar_padre_voraz(string xy,string xypadre, int nivel);
    bool existe_hijo_voraz(string xy,string xypadre, int nivel);
    void mostrar_voraz();
    void solucion_voraz();

    //voraz primero el mejor

    float generar_distancia(int x1, int y1, int x2, int y2);
    bool expandir_distancia(int x, int y, string letra, int nivel, string xypadre);
    void mostrar_distancia();
    void solucion_distancia();
    void ordenar_distancia();
    vector <nodo> distancia;
    void primero_mejor();
    //void A*
    bool expandir_A(int x, int y, string letra, int nivel, string xypadre);
    void mostrar_A();
    void solucion_A();
    void ordenar_A();
    void A();




private slots:

    void on_A1_clicked();
    void on_A2_clicked();
    void on_A3_clicked();
    void on_A4_clicked();
    void on_A5_clicked();
    void on_A6_clicked();
    void on_A7_clicked();
    void on_A8_clicked();
    void on_A9_clicked();
    void on_A10_clicked();
    void on_A11_clicked();
    void on_A12_clicked();
    void on_A13_clicked();
    void on_A14_clicked();
    void on_A15_clicked();

    void on_B1_clicked();
    void on_B2_clicked();
    void on_B3_clicked();
    void on_B4_clicked();
    void on_B5_clicked();
    void on_B6_clicked();
    void on_B7_clicked();
    void on_B8_clicked();
    void on_B9_clicked();
    void on_B10_clicked();
    void on_B11_clicked();
    void on_B12_clicked();
    void on_B13_clicked();
    void on_B14_clicked();
    void on_B15_clicked();

    void on_C1_clicked();
    void on_C2_clicked();
    void on_C3_clicked();
    void on_C4_clicked();
    void on_C5_clicked();
    void on_C6_clicked();
    void on_C7_clicked();
    void on_C8_clicked();
    void on_C9_clicked();
    void on_C10_clicked();
    void on_C11_clicked();
    void on_C12_clicked();
    void on_C13_clicked();
    void on_C14_clicked();
    void on_C15_clicked();

    void on_D1_clicked();
    void on_D2_clicked();
    void on_D3_clicked();
    void on_D4_clicked();
    void on_D5_clicked();
    void on_D6_clicked();
    void on_D7_clicked();
    void on_D8_clicked();
    void on_D9_clicked();
    void on_D10_clicked();
    void on_D11_clicked();
    void on_D12_clicked();
    void on_D13_clicked();
    void on_D14_clicked();
    void on_D15_clicked();

    void on_E1_clicked();
    void on_E2_clicked();
    void on_E3_clicked();
    void on_E4_clicked();
    void on_E5_clicked();
    void on_E6_clicked();
    void on_E7_clicked();
    void on_E8_clicked();
    void on_E9_clicked();
    void on_E10_clicked();
    void on_E11_clicked();
    void on_E12_clicked();
    void on_E13_clicked();
    void on_E14_clicked();
    void on_E15_clicked();

    void on_F1_clicked();
    void on_F2_clicked();
    void on_F3_clicked();
    void on_F4_clicked();
    void on_F5_clicked();
    void on_F6_clicked();
    void on_F7_clicked();
    void on_F8_clicked();
    void on_F9_clicked();
    void on_F10_clicked();
    void on_F11_clicked();
    void on_F12_clicked();
    void on_F13_clicked();
    void on_F14_clicked();
    void on_F15_clicked();
    ///g
    void on_G1_clicked();
    void on_G2_clicked();
    void on_G3_clicked();
    void on_G4_clicked();
    void on_G5_clicked();
    void on_G6_clicked();
    void on_G7_clicked();
    void on_G8_clicked();
    void on_G9_clicked();
    void on_G10_clicked();
    void on_G11_clicked();
    void on_G12_clicked();
    void on_G13_clicked();
    void on_G14_clicked();
    void on_G15_clicked();
    ///h
    void on_H1_clicked();
    void on_H2_clicked();
    void on_H3_clicked();
    void on_H4_clicked();
    void on_H5_clicked();
    void on_H6_clicked();
    void on_H7_clicked();
    void on_H8_clicked();
    void on_H9_clicked();
    void on_H10_clicked();
    void on_H11_clicked();
    void on_H12_clicked();
    void on_H13_clicked();
    void on_H14_clicked();
    void on_H15_clicked();
    //i
    void on_I1_clicked();
    void on_I2_clicked();
    void on_I3_clicked();
    void on_I4_clicked();
    void on_I5_clicked();
    void on_I6_clicked();
    void on_I7_clicked();
    void on_I8_clicked();
    void on_I9_clicked();
    void on_I10_clicked();
    void on_I11_clicked();
    void on_I12_clicked();
    void on_I13_clicked();
    void on_I14_clicked();
    void on_I15_clicked();
    //j
    void on_J1_clicked();
    void on_J2_clicked();
    void on_J3_clicked();
    void on_J4_clicked();
    void on_J5_clicked();
    void on_J6_clicked();
    void on_J7_clicked();
    void on_J8_clicked();
    void on_J9_clicked();
    void on_J10_clicked();
    void on_J11_clicked();
    void on_J12_clicked();
    void on_J13_clicked();
    void on_J14_clicked();
    void on_J15_clicked();
    //k
    void on_K1_clicked();
    void on_K2_clicked();
    void on_K3_clicked();
    void on_K4_clicked();
    void on_K5_clicked();
    void on_K6_clicked();
    void on_K7_clicked();
    void on_K8_clicked();
    void on_K9_clicked();
    void on_K10_clicked();
    void on_K11_clicked();
    void on_K12_clicked();
    void on_K13_clicked();
    void on_K14_clicked();
    void on_K15_clicked();
    //L
    void on_L1_clicked();
    void on_L2_clicked();
    void on_L3_clicked();
    void on_L4_clicked();
    void on_L5_clicked();
    void on_L6_clicked();
    void on_L7_clicked();
    void on_L8_clicked();
    void on_L9_clicked();
    void on_L10_clicked();
    void on_L11_clicked();
    void on_L12_clicked();
    void on_L13_clicked();
    void on_L14_clicked();
    void on_L15_clicked();
    //m
    void on_M1_clicked();
    void on_M2_clicked();
    void on_M3_clicked();
    void on_M4_clicked();
    void on_M5_clicked();
    void on_M6_clicked();
    void on_M7_clicked();
    void on_M8_clicked();
    void on_M9_clicked();
    void on_M10_clicked();
    void on_M11_clicked();
    void on_M12_clicked();
    void on_M13_clicked();
    void on_M14_clicked();
    void on_M15_clicked();
    //n
    void on_N1_clicked();
    void on_N2_clicked();
    void on_N3_clicked();
    void on_N4_clicked();
    void on_N5_clicked();
    void on_N6_clicked();
    void on_N7_clicked();
    void on_N8_clicked();
    void on_N9_clicked();
    void on_N10_clicked();
    void on_N11_clicked();
    void on_N12_clicked();
    void on_N13_clicked();
    void on_N14_clicked();
    void on_N15_clicked();
    //o
    void on_O1_clicked();
    void on_O2_clicked();
    void on_O3_clicked();
    void on_O4_clicked();
    void on_O5_clicked();
    void on_O6_clicked();
    void on_O7_clicked();
    void on_O8_clicked();
    void on_O9_clicked();
    void on_O10_clicked();
    void on_O11_clicked();
    void on_O12_clicked();
    void on_O13_clicked();
    void on_O14_clicked();
    void on_O15_clicked();

    void on_pushButton_iniciar_clicked();

    void on_lineEdit_cursorPositionChanged(int arg1, int arg2);

    void on_pushButton_clicked();

    void on_pushButton_2_clicked();

    void on_comboBox_currentIndexChanged(int index);

    void on_comboBox_currentTextChanged(const QString &arg1);

    void on_pb_reiniciar_clicked();

    void on_pb_cerrar_clicked();

    void on_pb_arriba_clicked();

    void on_pb_abajo_clicked();

    void on_pb_izquierda_clicked();

    void on_pb_derecha_clicked();

    void on_pushButton_3_clicked();

    void on_pushButton_4_clicked();

    void on_pb_personaje_clicked();

    void on_pb_personaje_2_clicked();

    void on_pb_personaje3_clicked();

    void on_comboBox_2_currentIndexChanged(int index);

private:
    Ui::MainWindow *ui;
};

#endif // MAINWINDOW_H
