#ifndef PRINCIPAL_H
#define PRINCIPAL_H

#include <QMainWindow>
#include <vector>
#include <iostream>

using namespace std;

struct terreno{
    int valor;
    string nombre;
    string icono;

};
struct coordenada{
    int x;
    int y;
    string nombre;
};

struct personaje{
    string nombre;
    string icono;
    string ciudad;
    string mar;
    string playa;
    string desierto;
    string bosque;
    string montana;
    string pueblo;
    string loma;
    string nieve;
    string pared;
    int estado;


};

namespace Ui {
class principal;
}

class principal : public QMainWindow
{
    Q_OBJECT

public:
    explicit principal(QWidget *parent = 0);
    ~principal();
    int valores[15][15];
    vector <int> repetidos;
    terreno mapa[15][15];
    vector <personaje> persona;
    vector <terreno> campo;
    int cant_per;
    int pers=0;
    int cp=0;

    void cargar_valores(string );
    void checar_repetidos();
    void generar_linedits_terrenos();
    void desactivar_lineedit_terrenos();
    void activar_valores();
    void activar_botones();
    void validar_valores();
    void guardar_personajes();
    void guardar_terreno();
    void bloquear_valores();
    void generar_terreno();
    void guardar_repetidos();

private slots:

    void on_pb_cargarValores_clicked();

    void on_pb_iniciar_clicked();

    void on_spinBox_valueChanged(int arg1);

    void on_pb_crearTerrenos_clicked();

    void on_pb_asignarValores_clicked();

    void on_lineEdit_cursorPositionChanged(int arg1, int arg2);

    void on_le_valor_2_cursorPositionChanged(int arg1, int arg2);

    void on_le_valor_3_cursorPositionChanged(int arg1, int arg2);

    void on_le_valor_4_cursorPositionChanged(int arg1, int arg2);

    void on_le_valor_5_cursorPositionChanged(int arg1, int arg2);

    void on_le_valor_6_cursorPositionChanged(int arg1, int arg2);

    void on_le_valor_7_cursorPositionChanged(int arg1, int arg2);

    void on_le_valor_8_cursorPositionChanged(int arg1, int arg2);

    void on_le_valor_9_cursorPositionChanged(int arg1, int arg2);

    void on_le_valor_10_cursorPositionChanged(int arg1, int arg2);

    void on_pb_crear_personaje_clicked();

    void on_pb_buscar_clicked();

    void on_le_personaje_cursorPositionChanged(int arg1, int arg2);

    void on_le_personaje_2_cursorPositionChanged(int arg1, int arg2);

    void on_le_personaje_3_cursorPositionChanged(int arg1, int arg2);

    void on_le_terreno_cursorPositionChanged(int arg1, int arg2);

    void on_le_terreno_2_cursorPositionChanged(int arg1, int arg2);

    void on_le_terreno_3_cursorPositionChanged(int arg1, int arg2);

    void on_le_terreno_4_cursorPositionChanged(int arg1, int arg2);

    void on_le_terreno_5_cursorPositionChanged(int arg1, int arg2);

    void on_le_terreno_6_cursorPositionChanged(int arg1, int arg2);

    void on_le_terreno_7_cursorPositionChanged(int arg1, int arg2);

    void on_le_terreno_8_cursorPositionChanged(int arg1, int arg2);

    void on_le_terreno_9_cursorPositionChanged(int arg1, int arg2);

    void on_le_terreno_10_cursorPositionChanged(int arg1, int arg2);

    void on_le_valor_cursorPositionChanged(int arg1, int arg2);

private:
    Ui::principal *ui;
};

#endif // PRINCIPAL_H
