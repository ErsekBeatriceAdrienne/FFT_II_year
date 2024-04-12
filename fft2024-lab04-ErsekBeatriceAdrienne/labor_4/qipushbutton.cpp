#include "qipushbutton.h"

QIPushButton :: QIPushButton (QWidget *window) : QPushButton(window) {}

void QIPushButton :: mousePressEvent (QMouseEvent *event)
{
    if (event->button() == Qt :: RightButton) {
        QMessageBox :: information(this, "Information","Right Click");
    }
}
