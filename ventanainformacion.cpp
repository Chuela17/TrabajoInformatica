#include "ventanainformacion.h"
#include "ui_ventanainformacion.h"
#include "partida.h"
#include "informacion.h"

using namespace std;

Ventanainformacion::Ventanainformacion(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Ventanainformacion)
{
    ui->setupUi(this);
    Jugador *jugador1 = mipartida.GetJugador1();
    int numerojugador1 = 1;

    Informacion mi_informacion(numerojugador1);
    string s1 = mi_informacion.ObtenerInformacion1(jugador1);

    QString texto_etiqueta = QString::fromLocal8Bit(s1.c_str());
    ui->label->setText(texto_etiqueta);

    Jugador *jugador2 = mipartida.GetJugador2();
    int numerojugador2 = 2;

    Informacion mi_informacion2(numerojugador2);
    string s2 = mi_informacion2.ObtenerInformacion2(jugador2);

    QString texto_etiqueta2 = QString::fromLocal8Bit(s2.c_str());
    ui->label_2->setText(texto_etiqueta2);
}

Ventanainformacion::~Ventanainformacion()
{
    delete ui;
}
