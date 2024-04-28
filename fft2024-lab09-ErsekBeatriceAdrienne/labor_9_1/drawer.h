#ifndef DRAWER_H
#define DRAWER_H

#include <QApplication>
#include <QOpenGLWidget>
#include <QOpenGLFunctions>

class Drawer : public QOpenGLWidget, protected QOpenGLFunctions
{

public:
    Drawer(QWidget *parent = nullptr);

protected:
    void initializeGL() override;
    void resizeGL(int w, int h) override;
    void paintGL() override;

};

#endif // DRAWER_H
