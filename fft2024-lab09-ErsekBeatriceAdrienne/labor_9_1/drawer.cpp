#include "drawer.h"

Drawer :: Drawer(QWidget *parent) : QOpenGLWidget(parent) {}

void Drawer :: initializeGL()
{
    initializeOpenGLFunctions();
    glClearColor(0.0f, 0.0f, 0.0f, 1.0f);
}

void Drawer :: resizeGL(int w, int h)
{
    glViewport(0, 0, w, h);
}


/*Írjunk egy programot, mely OpenGL segítségével megjelenít és kiszínez egy téglalapot és egy háromszöget.*/
void Drawer :: paintGL()
{
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

    // Téglalap kirajzolása gradient RGB színekkel
    glBegin(GL_QUADS);
    glColor3f(1.0f, 0.0f, 0.0f); // Piros
    glVertex3f(-1.0f, -1.0f, 0.0f);
    glColor3f(0.0f, 1.0f, 0.0f); // Zöld
    glVertex3f(1.0f, -1.0f, 0.0f);
    glColor3f(0.0f, 0.0f, 1.0f); // Kék
    glVertex3f(1.0f, 1.0f, 0.0f);
    glColor3f(1.0f, 1.0f, 0.0f); // Sárga
    glVertex3f(-1.0f, 1.0f, 0.0f);
    glEnd();

    // Háromszög kirajzolása gradient RGB színekkel
    glBegin(GL_TRIANGLES);
    glColor3f(1.0f, 0.0f, 0.0f); // Piros
    glVertex3f(0.0f, 1.5f, 0.0f);
    glColor3f(0.0f, 1.0f, 0.0f); // Zöld
    glVertex3f(-1.5f, -1.5f, 0.0f);
    glColor3f(0.0f, 0.0f, 1.0f); // Kék
    glVertex3f(1.5f, -1.5f, 0.0f);
    glEnd();
}
