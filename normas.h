#ifndef NORMAS_H
#define NORMAS_H

#include <QDialog>

namespace Ui {
class Normas;
}

class Normas : public QDialog
{
    Q_OBJECT

public:
    explicit Normas(QWidget *parent = nullptr);
    ~Normas();

private:
    Ui::Normas *ui;
};

#endif // NORMAS_H
