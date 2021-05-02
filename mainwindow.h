#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QPushButton>
#include "partida.h"

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
    void on_pushButton_novisible1_clicked();

    void on_pushButton_novisible2_clicked();

    void on_pushButton_reglas_clicked();

    void BotonOros(QPushButton *, QPushButton *);

    void on_pushButton_oros_clicked();

    void BotonCopas(QPushButton *, QPushButton *);

    void on_pushButton_copas_clicked();

    void BotonEspadas(QPushButton *, QPushButton *);

    void on_pushButton_espadas_clicked();

    void BotonBastos(QPushButton *, QPushButton *);

    void on_pushButton_bastos_clicked();

    void BotonVisible2(QPushButton *, QPushButton *);

    void on_pushButton_visible2_clicked();

    void BotonVisible1(QPushButton *, QPushButton *);

    void on_pushButton_visible1_clicked();

    void on_pushButton_informacion_clicked();


private:
    Ui::MainWindow *ui;
    int boton = 0;
    int cartafuera1 = 0;
    int cartafuera2 = 0;
};
#endif // MAINWINDOW_H
