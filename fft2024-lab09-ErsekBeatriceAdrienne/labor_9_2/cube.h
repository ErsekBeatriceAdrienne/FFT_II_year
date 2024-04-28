#ifndef CUBE_H
#define CUBE_H

#include <QMainWindow>
#include <QTimer>
#include <QVBoxLayout>
#include <QOpenGLWidget>
#include <QOpenGLFunctions>

class Cube : public QOpenGLWidget, protected QOpenGLFunctions
{

public:

    Cube(QWidget *parent = nullptr) : QOpenGLWidget(parent) {}

protected:
    void initializeGL() override {
        initializeOpenGLFunctions();
        glClearColor(0.0f, 0.0f, 0.0f, 1.0f);
        glEnable(GL_DEPTH_TEST);
    }

    void resizeGL(int w, int h) override {
        glViewport(0, 0, w, h);
        glMatrixMode(GL_PROJECTION);
        glLoadIdentity();
        glPerspective(45.0, (GLfloat)w / (GLfloat)h, 0.1, 100.0);
        glMatrixMode(GL_MODELVIEW);
        glLoadIdentity();
    }

    void paintGL() override {
        glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
        glLoadIdentity();
        glTranslatef(0.0f, 0.0f, -10.0f); // Eltoljuk a kockát távolabb a nézőtől
        glRotatef(rotationAngle, 1.0f, 1.0f, 1.0f);

        glBegin(GL_QUADS);

        glColor3f(1.0f, 0.0f, 0.0f); // Red
        glVertex3f(2.0f, 2.0f, -2.0f);
        glVertex3f(-2.0f, 2.0f, -2.0f);
        glVertex3f(-2.0f, 2.0f, 2.0f);
        glVertex3f(2.0f, 2.0f, 2.0f);

        glColor3f(0.0f, 1.0f, 0.0f); // Green
        glVertex3f(2.0f, -2.0f, 2.0f);
        glVertex3f(-2.0f, -2.0f, 2.0f);
        glVertex3f(-2.0f, -2.0f, -2.0f);
        glVertex3f(2.0f, -2.0f, -2.0f);

        glColor3f(0.0f, 0.0f, 1.0f); // Blue
        glVertex3f(2.0f, 2.0f, 2.0f);
        glVertex3f(-2.0f, 2.0f, 2.0f);
        glVertex3f(-2.0f, -2.0f, 2.0f);
        glVertex3f(2.0f, -2.0f, 2.0f);

        glColor3f(1.0f, 1.0f, 0.0f); // Yellow
        glVertex3f(2.0f, -2.0f, -2.0f);
        glVertex3f(-2.0f, -2.0f, -2.0f);
        glVertex3f(-2.0f, 2.0f, -2.0f);
        glVertex3f(2.0f, 2.0f, -2.0f);

        glColor3f(1.0f, 0.0f, 1.0f); // Magenta
        glVertex3f(-2.0f, 2.0f, 2.0f);
        glVertex3f(-2.0f, 2.0f, -2.0f);
        glVertex3f(-2.0f, -2.0f, -2.0f);
        glVertex3f(-2.0f, -2.0f, 2.0f);

        glColor3f(0.0f, 1.0f, 1.0f); // Cyan
        glVertex3f(2.0f, 2.0f, -2.0f);
        glVertex3f(2.0f, 2.0f, 2.0f);
        glVertex3f(2.0f, -2.0f, 2.0f);
        glVertex3f(2.0f, -2.0f, -2.0f);

        glEnd();
        rotationAngle += 1.0f;
        if (rotationAngle >= 360.0f)
            rotationAngle -= 360.0f;
        update();
    }

private:
    GLfloat rotationAngle = 0.0f;

    void glPerspective(GLdouble fov, GLdouble aspectRatio, GLdouble zNear, GLdouble zFar) {
        GLdouble rFov = fov * 3.14159265 / 180.0;
        glFrustum(-zNear * tan(rFov / 2.0) * aspectRatio,
                  zNear * tan(rFov / 2.0) * aspectRatio,
                  -zNear * tan(rFov / 2.0),
                  zNear * tan(rFov / 2.0),
                  zNear, zFar);
    }
};

#endif // CUBE_H
