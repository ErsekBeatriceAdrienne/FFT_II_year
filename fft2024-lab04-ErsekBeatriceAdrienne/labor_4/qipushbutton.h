#ifndef QIPUSHBUTTON_H
#define QIPUSHBUTTON_H

#include <QObject>
#include <QPushButton>
#include <QMouseEvent>
#include <QMessageBox>

class QIPushButton : public QPushButton
{
    Q_OBJECT

public:
    explicit QIPushButton(QWidget *window);

private:
    QPushButton *button;

public slots:
    void mousePressEvent(QMouseEvent *event) override;
};

#endif // QIPUSHBUTTON_H
