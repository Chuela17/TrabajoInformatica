#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "normas.h"
#include "ventanainformacion.h"
#include "informacion.h"

using namespace std;
Partida mipartida("Jugador1", "Jugador2");
Jugador *jugador = mipartida.SiguienteJugador();

// Creación de la partida y definición de variables globales
MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    ui->pushButton_visible1->setStyleSheet("QPushButton{border-width: 3px; border-radius: 10px; border-style: solid; border-color: white;}");
    ui->pushButton_visible2->setStyleSheet("QPushButton{border-width: 3px; border-radius: 10px; border-style: solid; border-color: white;}");
    ui->pushButton_oros->setStyleSheet("QPushButton{border-width: 3px; border-radius: 10px; border-style: solid; border-color: white;}");
    ui->pushButton_copas->setStyleSheet("QPushButton{border-width: 3px; border-radius: 10px; border-style: solid; border-color: white;}");
    ui->pushButton_espadas->setStyleSheet("QPushButton{border-width: 3px; border-radius: 10px; border-style: solid; border-color: white;}");
    ui->pushButton_bastos->setStyleSheet("QPushButton{border-width: 3px; border-radius: 10px; border-style: solid; border-color: white;}");
    ui->pushButton_novisible1->setStyleSheet("QPushButton{image: url(:/new/prefix1/imagenes/reverso)}");
    ui->pushButton_novisible2->setStyleSheet("QPushButton{image: url(:/new/prefix1/imagenes/reverso)}");
    ui->pushButton_ver1->setStyleSheet("QPushButton{border-width: 3px; border-radius: 10px; border-style: solid; border-color: white;}");
    ui->pushButton_ver2->setStyleSheet("QPushButton{border-width: 3px; border-radius: 10px; border-style: solid; border-color: white;}");
}

MainWindow::~MainWindow() {
    delete ui;
}

void MainWindow::on_pushButton_novisible1_clicked() {
    jugador = mipartida.SiguienteJugador();

    if (jugador == mipartida.GetJugador2()) {
        return;
    }

    cartafuera1 = 1;
    ui->pushButton_ver1->setStyleSheet(QString::fromStdString(jugador->GetMontonNoVisible()->ConsultarCarta().GetDireccioncarta()));
    if (jugador->GetMontonNoVisible()->GetStackCartas().size() == 1) {
        ui->pushButton_novisible1->setStyleSheet("QPushButton{border-width: 3px; border-radius: 10px; border-style: solid; border-color: white;}");
    } else if (jugador->GetMontonNoVisible()->GetStackCartas().size() == 0 && jugador->GetMontonVisible()->GetStackCartas().size() != 0) {
        ui->pushButton_novisible1->setStyleSheet("QPushButton{image: url(:/new/prefix1/imagenes/reverso)}");
        ui->pushButton_ver1->setStyleSheet("QPushButton{border-width: 3px; border-radius: 10px; border-style: solid; border-color: white;}");
        ui->pushButton_visible1->setStyleSheet("QPushButton{border-width: 3px; border-radius: 10px; border-style: solid; border-color: white;}");
        jugador->GetMontonNoVisible()->DejarCarta(jugador->GetMontonVisible());
    }
}

void MainWindow::on_pushButton_novisible2_clicked() {
    jugador = mipartida.SiguienteJugador();

    if (jugador == mipartida.GetJugador1()) {
        return;
    }
    cartafuera2 = 1;
    ui->pushButton_ver2->setStyleSheet(QString::fromStdString(jugador->GetMontonNoVisible()->ConsultarCarta().GetDireccioncarta()));
    if (jugador->GetMontonNoVisible()->GetStackCartas().size() == 1) {
        ui->pushButton_novisible2->setStyleSheet("QPushButton{border-width: 3px; border-radius: 10px; border-style: solid; border-color: white;}");
    } else if (jugador->GetMontonNoVisible()->GetStackCartas().size() == 0 && jugador->GetMontonVisible()->GetStackCartas().size() != 0) {
        ui->pushButton_novisible2->setStyleSheet("QPushButton{image: url(:/new/prefix1/imagenes/reverso)}");
        ui->pushButton_ver2->setStyleSheet("QPushButton{border-width: 3px; border-radius: 10px; border-style: solid; border-color: white;}");
        ui->pushButton_visible2->setStyleSheet("QPushButton{border-width: 3px; border-radius: 10px; border-style: solid; border-color: white;}");
        jugador->GetMontonNoVisible()->DejarCarta(jugador->GetMontonVisible());
    }
}

void MainWindow::on_pushButton_reglas_clicked() {
    Normas *normas = new Normas();
    normas->show();
}

void MainWindow::BotonOros(QPushButton *q_boton_ver, QPushButton *q_boton_visible) {
    if ((cartafuera1 == 1 || cartafuera2 == 1) && mipartida.ComprobarDejarCarta(jugador->GetMontonNoVisible()->ConsultarCarta(), jugador) == 6){
       ui->pushButton_oros->setStyleSheet(QString::fromStdString(jugador->GetMontonNoVisible()->ConsultarCarta().GetDireccioncarta()));
       mipartida.DejarCarta(jugador->GetMontonNoVisible()->ConsultarCarta(), jugador, boton, ui->label_estado);
       jugador->DejarCarta(jugador->GetMontonNoVisible()->ConsultarCarta(), mipartida.GetOros());
       jugador->GetMontonNoVisible()->CogerCarta();
       q_boton_ver->setStyleSheet("QPushButton{border-width: 3px; border-radius: 10px; border-style: solid; border-color: white;}");
    } else if((cartafuera1 == 1 || cartafuera2 == 1) && mipartida.ComprobarDejarCarta(jugador->GetMontonNoVisible()->ConsultarCarta(), jugador) == 0){
       q_boton_visible->setStyleSheet(QString::fromStdString(jugador->GetMontonNoVisible()->ConsultarCarta().GetDireccioncarta()));
       if (jugador == mipartida.GetJugador1()){
           mipartida.DejarCarta(jugador->GetMontonNoVisible()->ConsultarCarta(), jugador, boton, ui->label_estado);
           jugador->DejarCarta(jugador->GetMontonNoVisible()->ConsultarCarta(), mipartida.GetJugador1()->GetMontonVisible());
       } else if (jugador == mipartida.GetJugador2()){
           mipartida.DejarCarta(jugador->GetMontonNoVisible()->ConsultarCarta(), jugador, boton, ui->label_estado);
           jugador->DejarCarta(jugador->GetMontonNoVisible()->ConsultarCarta(), mipartida.GetJugador2()->GetMontonVisible());
       }
       jugador->GetMontonNoVisible()->CogerCarta();
       q_boton_ver->setStyleSheet("QPushButton{border-width: 3px; border-radius: 10px; border-style: solid; border-color: white;}");
    } else if ((cartafuera1 == 1 || cartafuera2 == 1) && mipartida.ComprobarDejarCarta(jugador->GetMontonNoVisible()->ConsultarCarta(), jugador) != boton){
        q_boton_visible->setStyleSheet(QString::fromStdString(jugador->GetMontonNoVisible()->ConsultarCarta().GetDireccioncarta()));
        mipartida.DejarCarta(jugador->GetMontonNoVisible()->ConsultarCarta(), jugador, boton, ui->label_estado);
        jugador->DejarCarta(jugador->GetMontonNoVisible()->ConsultarCarta(), mipartida.GetJugador1()->GetMontonVisible());
        jugador->GetMontonNoVisible()->CogerCarta();
        q_boton_ver->setStyleSheet("QPushButton{border-width: 3px; border-radius: 10px; border-style: solid; border-color: white;}");
    }
}


void MainWindow::on_pushButton_oros_clicked() {
    boton = 6;

    if (mipartida.SiguienteJugador() == mipartida.GetJugador1()) {
        this->BotonOros(ui->pushButton_ver1, ui->pushButton_visible1);
    } else {
        this->BotonOros(ui->pushButton_ver2, ui->pushButton_visible2);
    }

    cartafuera1 = 0;
    cartafuera2 = 0;
}

void MainWindow::BotonCopas(QPushButton *q_boton_ver, QPushButton *q_boton_visible) {
    if ((cartafuera1 == 1 || cartafuera2 == 1) && mipartida.ComprobarDejarCarta(jugador->GetMontonNoVisible()->ConsultarCarta(), jugador) == 5){
       ui->pushButton_copas->setStyleSheet(QString::fromStdString(jugador->GetMontonNoVisible()->ConsultarCarta().GetDireccioncarta()));
       mipartida.DejarCarta(jugador->GetMontonNoVisible()->ConsultarCarta(), jugador, boton, ui->label_estado);
       jugador->DejarCarta(jugador->GetMontonNoVisible()->ConsultarCarta(), mipartida.GetCopas());
       jugador->GetMontonNoVisible()->CogerCarta();
       q_boton_ver->setStyleSheet("QPushButton{border-width: 3px; border-radius: 10px; border-style: solid; border-color: white;}");
    } else if((cartafuera1 == 1 || cartafuera2 == 1) && mipartida.ComprobarDejarCarta(jugador->GetMontonNoVisible()->ConsultarCarta(), jugador) == 0){
        q_boton_visible->setStyleSheet(QString::fromStdString(jugador->GetMontonNoVisible()->ConsultarCarta().GetDireccioncarta()));
        if (jugador == mipartida.GetJugador1()){
            mipartida.DejarCarta(jugador->GetMontonNoVisible()->ConsultarCarta(), jugador, boton, ui->label_estado);
            jugador->DejarCarta(jugador->GetMontonNoVisible()->ConsultarCarta(), mipartida.GetJugador1()->GetMontonVisible());
        } else if (jugador == mipartida.GetJugador2()){
            mipartida.DejarCarta(jugador->GetMontonNoVisible()->ConsultarCarta(), jugador, boton, ui->label_estado);
            jugador->DejarCarta(jugador->GetMontonNoVisible()->ConsultarCarta(), mipartida.GetJugador2()->GetMontonVisible());
        }
        jugador->GetMontonNoVisible()->CogerCarta();
        q_boton_ver->setStyleSheet("QPushButton{border-width: 3px; border-radius: 10px; border-style: solid; border-color: white;}");
    } else if ((cartafuera1 == 1 || cartafuera2 == 1) && mipartida.ComprobarDejarCarta(jugador->GetMontonNoVisible()->ConsultarCarta(),jugador) != boton){
        q_boton_visible->setStyleSheet(QString::fromStdString(jugador->GetMontonNoVisible()->ConsultarCarta().GetDireccioncarta()));
        mipartida.DejarCarta(jugador->GetMontonNoVisible()->ConsultarCarta(), jugador, boton, ui->label_estado);
        jugador->DejarCarta(jugador->GetMontonNoVisible()->ConsultarCarta(), mipartida.GetJugador1()->GetMontonVisible());
        jugador->GetMontonNoVisible()->CogerCarta();
        q_boton_ver->setStyleSheet("QPushButton{border-width: 3px; border-radius: 10px; border-style: solid; border-color: white;}");
    }
}

void MainWindow::on_pushButton_copas_clicked() {
    boton = 5;

    if (mipartida.SiguienteJugador() == mipartida.GetJugador1()) {
        this->BotonCopas(ui->pushButton_ver1, ui->pushButton_visible1);
    } else {
        this->BotonCopas(ui->pushButton_ver2, ui->pushButton_visible2);
    }

    cartafuera1 = 0;
    cartafuera2 = 0;
}

void MainWindow::BotonEspadas(QPushButton *q_boton_ver, QPushButton *q_boton_visible) {
    if ((cartafuera1 == 1 || cartafuera2 == 1) && mipartida.ComprobarDejarCarta(jugador->GetMontonNoVisible()->ConsultarCarta(), jugador) == 4){
       ui->pushButton_espadas->setStyleSheet(QString::fromStdString(jugador->GetMontonNoVisible()->ConsultarCarta().GetDireccioncarta()));
       mipartida.DejarCarta(jugador->GetMontonNoVisible()->ConsultarCarta(), jugador, boton, ui->label_estado);
       jugador->DejarCarta(jugador->GetMontonNoVisible()->ConsultarCarta(), mipartida.GetEspadas());
       jugador->GetMontonNoVisible()->CogerCarta();
       q_boton_ver->setStyleSheet("QPushButton{border-width: 3px; border-radius: 10px; border-style: solid; border-color: white;}");
    } else if((cartafuera1 == 1 || cartafuera2 == 1) && mipartida.ComprobarDejarCarta(jugador->GetMontonNoVisible()->ConsultarCarta(), jugador) == 0){
        q_boton_visible->setStyleSheet(QString::fromStdString(jugador->GetMontonNoVisible()->ConsultarCarta().GetDireccioncarta()));
        if (jugador == mipartida.GetJugador1()){
            mipartida.DejarCarta(jugador->GetMontonNoVisible()->ConsultarCarta(), jugador, boton, ui->label_estado);
            jugador->DejarCarta(jugador->GetMontonNoVisible()->ConsultarCarta(), mipartida.GetJugador1()->GetMontonVisible());
        } else if (jugador == mipartida.GetJugador2()){
            mipartida.DejarCarta(jugador->GetMontonNoVisible()->ConsultarCarta(), jugador, boton, ui->label_estado);
            jugador->DejarCarta(jugador->GetMontonNoVisible()->ConsultarCarta(), mipartida.GetJugador2()->GetMontonVisible());
        }
        jugador->GetMontonNoVisible()->CogerCarta();
        q_boton_ver->setStyleSheet("QPushButton{border-width: 3px; border-radius: 10px; border-style: solid; border-color: white;}");
    } else if ((cartafuera1 == 1 || cartafuera2 == 1) && mipartida.ComprobarDejarCarta(jugador->GetMontonNoVisible()->ConsultarCarta(), jugador) != boton){
            q_boton_visible->setStyleSheet(QString::fromStdString(jugador->GetMontonNoVisible()->ConsultarCarta().GetDireccioncarta()));
            mipartida.DejarCarta(jugador->GetMontonNoVisible()->ConsultarCarta(), jugador, boton, ui->label_estado);
            jugador->DejarCarta(jugador->GetMontonNoVisible()->ConsultarCarta(), mipartida.GetJugador1()->GetMontonVisible());
            jugador->GetMontonNoVisible()->CogerCarta();
            q_boton_ver->setStyleSheet("QPushButton{border-width: 3px; border-radius: 10px; border-style: solid; border-color: white;}");
    }
}


void MainWindow::on_pushButton_espadas_clicked() {
    boton = 4;

    if (mipartida.SiguienteJugador() == mipartida.GetJugador1()) {
        this->BotonEspadas(ui->pushButton_ver1, ui->pushButton_visible1);
    } else {
        this->BotonEspadas(ui->pushButton_ver2, ui->pushButton_visible2);
    }

    cartafuera1 = 0;
    cartafuera2 = 0;
}

void MainWindow::BotonBastos(QPushButton *q_boton_ver, QPushButton *q_boton_visible) {
    if ((cartafuera1 == 1 || cartafuera2 == 1) && mipartida.ComprobarDejarCarta(jugador->GetMontonNoVisible()->ConsultarCarta(), jugador) == 3){
       ui->pushButton_bastos->setStyleSheet(QString::fromStdString(jugador->GetMontonNoVisible()->ConsultarCarta().GetDireccioncarta()));
       mipartida.DejarCarta(jugador->GetMontonNoVisible()->ConsultarCarta(), jugador, boton, ui->label_estado);
       jugador->DejarCarta(jugador->GetMontonNoVisible()->ConsultarCarta(), mipartida.GetBastos());
       jugador->GetMontonNoVisible()->CogerCarta();
       q_boton_ver->setStyleSheet("QPushButton{border-width: 3px; border-radius: 10px; border-style: solid; border-color: white;}");
    } else if((cartafuera1 == 1 || cartafuera2 == 1) && mipartida.ComprobarDejarCarta(jugador->GetMontonNoVisible()->ConsultarCarta(), jugador) == 0){
        q_boton_visible->setStyleSheet(QString::fromStdString(jugador->GetMontonNoVisible()->ConsultarCarta().GetDireccioncarta()));
        if (jugador == mipartida.GetJugador1()){
            mipartida.DejarCarta(jugador->GetMontonNoVisible()->ConsultarCarta(), jugador, boton, ui->label_estado);
            jugador->DejarCarta(jugador->GetMontonNoVisible()->ConsultarCarta(), mipartida.GetJugador1()->GetMontonVisible());
        } else if (jugador == mipartida.GetJugador2()){
            mipartida.DejarCarta(jugador->GetMontonNoVisible()->ConsultarCarta(), jugador, boton, ui->label_estado);
            jugador->DejarCarta(jugador->GetMontonNoVisible()->ConsultarCarta(), mipartida.GetJugador2()->GetMontonVisible());
        }
        jugador->GetMontonNoVisible()->CogerCarta();
        q_boton_ver->setStyleSheet("QPushButton{border-width: 3px; border-radius: 10px; border-style: solid; border-color: white;}");
    } else if ((cartafuera1 == 1 || cartafuera2 == 1) && mipartida.ComprobarDejarCarta(jugador->GetMontonNoVisible()->ConsultarCarta(), jugador) != boton){
        q_boton_visible->setStyleSheet(QString::fromStdString(jugador->GetMontonNoVisible()->ConsultarCarta().GetDireccioncarta()));
        mipartida.DejarCarta(jugador->GetMontonNoVisible()->ConsultarCarta(), jugador, boton, ui->label_estado);
        jugador->DejarCarta(jugador->GetMontonNoVisible()->ConsultarCarta(), mipartida.GetJugador1()->GetMontonVisible());
        jugador->GetMontonNoVisible()->CogerCarta();
        q_boton_visible->setStyleSheet("QPushButton{border-width: 3px; border-radius: 10px; border-style: solid; border-color: white;}");
    }
}

void MainWindow::on_pushButton_bastos_clicked() {
    boton = 3;

    if (mipartida.SiguienteJugador() == mipartida.GetJugador1()) {
        this->BotonBastos(ui->pushButton_ver1, ui->pushButton_visible1);
    } else {
        this->BotonBastos(ui->pushButton_ver2, ui->pushButton_visible2);
    }

    cartafuera1 = 0;
    cartafuera2 = 0;
}

void MainWindow::BotonVisible2(QPushButton *q_boton_ver, QPushButton *q_boton_visible) {
    if ((cartafuera1 == 1 || cartafuera2 == 1) && mipartida.ComprobarDejarCarta(jugador->GetMontonNoVisible()->ConsultarCarta(), jugador) == 2){
       ui->pushButton_visible2->setStyleSheet(QString::fromStdString(jugador->GetMontonNoVisible()->ConsultarCarta().GetDireccioncarta()));
       mipartida.DejarCarta(jugador->GetMontonNoVisible()->ConsultarCarta(), jugador, boton, ui->label_estado);
       jugador->DejarCarta(jugador->GetMontonNoVisible()->ConsultarCarta(), mipartida.GetJugador2()->GetMontonVisible());
       jugador->GetMontonNoVisible()->CogerCarta();
       q_boton_ver->setStyleSheet("QPushButton{border-width: 3px; border-radius: 10px; border-style: solid; border-color: white;}");
    } else if((cartafuera1 == 1 || cartafuera2 == 1) && mipartida.ComprobarDejarCarta(jugador->GetMontonNoVisible()->ConsultarCarta(), jugador) == 0){
        q_boton_visible->setStyleSheet(QString::fromStdString(jugador->GetMontonNoVisible()->ConsultarCarta().GetDireccioncarta()));
        if (jugador == mipartida.GetJugador1()){
            mipartida.DejarCarta(jugador->GetMontonNoVisible()->ConsultarCarta(), jugador, boton, ui->label_estado);
            jugador->DejarCarta(jugador->GetMontonNoVisible()->ConsultarCarta(), mipartida.GetJugador1()->GetMontonVisible());
        } else if (jugador == mipartida.GetJugador2()){
            mipartida.DejarCarta(jugador->GetMontonNoVisible()->ConsultarCarta(), jugador, boton, ui->label_estado);
            jugador->DejarCarta(jugador->GetMontonNoVisible()->ConsultarCarta(), mipartida.GetJugador2()->GetMontonVisible());
        }
        jugador->GetMontonNoVisible()->CogerCarta();
        q_boton_ver->setStyleSheet("QPushButton{border-width: 3px; border-radius: 10px; border-style: solid; border-color: white;}");
    } else if ((cartafuera1 == 1 || cartafuera2 == 1) && mipartida.ComprobarDejarCarta(jugador->GetMontonNoVisible()->ConsultarCarta(), jugador) != boton){
        q_boton_visible->setStyleSheet(QString::fromStdString(jugador->GetMontonNoVisible()->ConsultarCarta().GetDireccioncarta()));
        mipartida.DejarCarta(jugador->GetMontonNoVisible()->ConsultarCarta(), jugador, boton, ui->label_estado);
        jugador->DejarCarta(jugador->GetMontonNoVisible()->ConsultarCarta(), mipartida.GetJugador1()->GetMontonVisible());
        jugador->GetMontonNoVisible()->CogerCarta();
        q_boton_ver->setStyleSheet("QPushButton{border-width: 3px; border-radius: 10px; border-style: solid; border-color: white;}");
    }
}


void MainWindow::on_pushButton_visible2_clicked() {
    boton = 2;

    if (mipartida.SiguienteJugador() == mipartida.GetJugador1()) {
        this->BotonVisible2(ui->pushButton_ver1, ui->pushButton_visible1);
    } else {
        this->BotonVisible2(ui->pushButton_ver2, ui->pushButton_visible2);
    }

    cartafuera1 = 0;
    cartafuera2 = 0;
}

void MainWindow::BotonVisible1(QPushButton *q_boton_ver, QPushButton *q_boton_visible) {
    if ((cartafuera1 == 1 || cartafuera2 == 1) && mipartida.ComprobarDejarCarta(jugador->GetMontonNoVisible()->ConsultarCarta(), jugador) == 1){
       ui->pushButton_visible1->setStyleSheet(QString::fromStdString(jugador->GetMontonNoVisible()->ConsultarCarta().GetDireccioncarta()));
       mipartida.DejarCarta(jugador->GetMontonNoVisible()->ConsultarCarta(), jugador, boton, ui->label_estado);
       jugador->DejarCarta(jugador->GetMontonNoVisible()->ConsultarCarta(), mipartida.GetJugador1()->GetMontonVisible());
       jugador->GetMontonNoVisible()->CogerCarta();
       q_boton_ver->setStyleSheet("QPushButton{border-width: 3px; border-radius: 10px; border-style: solid; border-color: white;}");
    } else if((cartafuera1 == 1 || cartafuera2 == 1) && mipartida.ComprobarDejarCarta(jugador->GetMontonNoVisible()->ConsultarCarta(), jugador) == 0){
        q_boton_visible->setStyleSheet(QString::fromStdString(jugador->GetMontonNoVisible()->ConsultarCarta().GetDireccioncarta()));
        if (jugador == mipartida.GetJugador1()){
            mipartida.DejarCarta(jugador->GetMontonNoVisible()->ConsultarCarta(), jugador, boton, ui->label_estado);
            jugador->DejarCarta(jugador->GetMontonNoVisible()->ConsultarCarta(), mipartida.GetJugador1()->GetMontonVisible());
        } else if (jugador == mipartida.GetJugador2()){
            mipartida.DejarCarta(jugador->GetMontonNoVisible()->ConsultarCarta(), jugador, boton, ui->label_estado);
            jugador->DejarCarta(jugador->GetMontonNoVisible()->ConsultarCarta(), mipartida.GetJugador2()->GetMontonVisible());
        }
        jugador->GetMontonNoVisible()->CogerCarta();
        q_boton_ver->setStyleSheet("QPushButton{border-width: 3px; border-radius: 10px; border-style: solid; border-color: white;}");
    } else if ((cartafuera1 == 1 || cartafuera2 == 1) && mipartida.ComprobarDejarCarta(jugador->GetMontonNoVisible()->ConsultarCarta(), jugador) != boton){
        q_boton_visible->setStyleSheet(QString::fromStdString(jugador->GetMontonNoVisible()->ConsultarCarta().GetDireccioncarta()));
        mipartida.DejarCarta(jugador->GetMontonNoVisible()->ConsultarCarta(), jugador, boton, ui->label_estado);
        jugador->DejarCarta(jugador->GetMontonNoVisible()->ConsultarCarta(), mipartida.GetJugador1()->GetMontonVisible());
        jugador->GetMontonNoVisible()->CogerCarta();
        q_boton_ver->setStyleSheet("QPushButton{border-width: 3px; border-radius: 10px; border-style: solid; border-color: white;}");
    }
}

void MainWindow::on_pushButton_visible1_clicked() {
    boton = 1;

    if (mipartida.SiguienteJugador() == mipartida.GetJugador1()) {
        this->BotonVisible1(ui->pushButton_ver1, ui->pushButton_visible1);
    } else {
        this->BotonVisible1(ui->pushButton_ver2, ui->pushButton_visible2);
    }

    cartafuera1 = 0;
    cartafuera2 = 0;
}


void MainWindow::on_pushButton_informacion_clicked() {
    Ventanainformacion *ventanainformacion = new Ventanainformacion();
    ventanainformacion->show();
}


