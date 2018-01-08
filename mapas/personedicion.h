#ifndef PERSONEDICION_H
#define PERSONEDICION_H

#include <QMainWindow>
#include <iostream>
#include "principal.h"

using namespace std;

namespace Ui {
class personedicion;
}

class personedicion : public QMainWindow
{
    Q_OBJECT

public:
    explicit personedicion(QWidget *parent = 0);
    ~personedicion();

    void cargar_personajes();
    QIcon generar_icono_personaje(string);
    void generar_personaje();
    void activar_valores();
    //void validar_valores();
    void cargar_repetidos();
    void colocar_valores(int);
    int perso=0;
    void guardar_valores();

    vector <personaje> persona;
    vector <terreno> campo;

private slots:
    void on_pushButton_11_clicked();

    void on_pushButton_12_clicked();

    void on_pushButton_13_clicked();

    void on_pushButton_14_clicked();

    void on_lineEdit_cursorPositionChanged(int arg1, int arg2);

    void on_lineEdit_2_cursorPositionChanged(int arg1, int arg2);

    void on_lineEdit_3_cursorPositionChanged(int arg1, int arg2);

    void on_lineEdit_4_cursorPositionChanged(int arg1, int arg2);

    void on_lineEdit_5_cursorPositionChanged(int arg1, int arg2);

    void on_lineEdit_6_cursorPositionChanged(int arg1, int arg2);

    void on_lineEdit_7_cursorPositionChanged(int arg1, int arg2);

    void on_lineEdit_8_cursorPositionChanged(int arg1, int arg2);

    void on_lineEdit_9_cursorPositionChanged(int arg1, int arg2);

    void on_lineEdit_10_cursorPositionChanged(int arg1, int arg2);

    void on_pushButton_15_clicked();

private:
    Ui::personedicion *ui;
};

#endif // PERSONEDICION_H
