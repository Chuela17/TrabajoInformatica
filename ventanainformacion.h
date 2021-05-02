#ifndef VENTANAINFORMACION_H
#define VENTANAINFORMACION_H

#include <QDialog>
#include "partida.h"

namespace Ui {
class Ventanainformacion;
}

class Ventanainformacion : public QDialog
{
    Q_OBJECT

public:
    explicit Ventanainformacion(QWidget *parent = nullptr);
    ~Ventanainformacion();

private:
    Ui::Ventanainformacion *ui;
};

#endif // VENTANAINFORMACION_H
