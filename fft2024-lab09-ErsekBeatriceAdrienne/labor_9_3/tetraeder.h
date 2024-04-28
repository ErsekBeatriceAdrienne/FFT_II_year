#ifndef TETRAEDER_H
#define TETRAEDER_H

/*#include <QApplication>
#include <QOpenGLWidget>
#include <QOpenGLFunctions>
#include <QKeyEvent>
#include <QOpenGLWindow>
#include <QOpenGLContext>
#include <QOpenGLPaintDevice>

class Tetraeder : public QOpenGLWidget, protected QOpenGLFunctions
{

public:
    Tetraeder(QWidget *parent = nullptr) : QOpenGLWidget(parent)
    {
        this->installEventFilter(this);
        setFocusPolicy(Qt::StrongFocus);
    }

protected:
    bool eventFilter(QObject *obj, QEvent *event) override {
        if (event->type() == QEvent::KeyPress) {
            QKeyEvent *keyEvent = static_cast<QKeyEvent *>(event);
            handleKeyPress(keyEvent);
            return true;
        }
        return QObject::eventFilter(obj, event);
    }

    void initializeGL() override {
        initializeOpenGLFunctions();
        glClearColor(0.0f, 0.0f, 0.0f, 1.0f);
        glEnable(GL_DEPTH_TEST);
        glEnable(GL_LIGHTING);
        glEnable(GL_LIGHT0);
        glEnable(GL_COLOR_MATERIAL);
        glEnable(GL_NORMALIZE);
    }

    void resizeGL(int w, int h) override {
        glViewport(0, 0, w, h);
        glMatrixMode(GL_PROJECTION);
        glLoadIdentity();
        glOrtho(-2.0 * (GLfloat)w / (GLfloat)h, 2.0 * (GLfloat)w / (GLfloat)h, -2.0, 2.0, -10.0, 10.0);
        glMatrixMode(GL_MODELVIEW);
        glLoadIdentity();
    }

    void paintGL() override {
        glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
        glLoadIdentity();
        glTranslatef(moveX, moveY, moveZ);
        glRotatef(rotationAngleX, 1.0f, 0.0f, 0.0f);
        glRotatef(rotationAngleY, 0.0f, 1.0f, 0.0f);

        glBegin(GL_TRIANGLES);

        // Front face
        glColor3f(1.0f, 0.0f, 0.0f); // Red
        glNormal3f(0.0f, 0.5f, 0.5f);
        glVertex3f(0.0f, 1.0f, 0.0f);
        glVertex3f(-1.0f, -1.0f, 1.0f);
        glVertex3f(1.0f, -1.0f, 1.0f);

        // Right face
        glColor3f(0.0f, 1.0f, 0.0f); // Green
        glNormal3f(0.5f, 0.5f, 0.0f);
        glVertex3f(0.0f, 1.0f, 0.0f);
        glVertex3f(1.0f, -1.0f, 1.0f);
        glVertex3f(1.0f, -1.0f, -1.0f);

        // Left face
        glColor3f(0.0f, 0.0f, 1.0f); // Blue
        glNormal3f(-0.5f, 0.5f, 0.0f);
        glVertex3f(0.0f, 1.0f, 0.0f);
        glVertex3f(-1.0f, -1.0f, -1.0f);
        glVertex3f(-1.0f, -1.0f, 1.0f);

        // Bottom face
        glColor3f(1.0f, 1.0f, 0.0f); // Yellow
        glNormal3f(0.0f, -0.5f, 0.0f);
        glVertex3f(0.0f, -1.0f, 0.0f);
        glVertex3f(1.0f, -1.0f, 1.0f);
        glVertex3f(-1.0f, -1.0f, 1.0f);

        glEnd();
    }

    void handleKeyPress(QKeyEvent *event) {
        switch (event->key()) {
        case Qt::Key_W:
            moveZ -= 0.1f;
            break;
        case Qt::Key_S:
            moveZ += 0.1f;
            break;
        case Qt::Key_A:
            moveX -= 0.1f;
            break;
        case Qt::Key_D:
            moveX += 0.1f;
            break;
        case Qt::Key_Q:
            moveY += 0.1f;
            break;
        case Qt::Key_E:
            moveY -= 0.1f;
            break;
        case Qt::Key_R:
            rotationAngleY += 5.0f;
            break;
        case Qt::Key_T:
            rotationAngleY -= 5.0f;
            break;
        default:
            break;
        }
        update();
    }

private:
    GLfloat moveX = 0.0f;
    GLfloat moveY = 0.0f;
    GLfloat moveZ = -5.0f;
    GLfloat rotationAngleX = 0.0f;
    GLfloat rotationAngleY = 0.0f;
};*/

#include <QApplication>
#include <QKeyEvent>
#include <QOpenGLWindow>
#include <QOpenGLFunctions>
#include <QOpenGLContext>
#include <QOpenGLPaintDevice>
#include <QPainter>

class Tetraeder : public QOpenGLWindow, protected QOpenGLFunctions
{
    Tetraeder(QWidget *parent = nullptr) : QOpenGLWindow(NoPartialUpdate, parent) {
        setSurfaceType(OpenGLSurface);
        xRot = yRot = zRot = 0;
        xTrans = yTrans = zTrans = 0;
    }

protected:
    void initializeGL() override {
        initializeOpenGLFunctions();
        glEnable(GL_DEPTH_TEST);
        glEnable(GL_LIGHTING);
        glEnable(GL_LIGHT0);
        glEnable(GL_COLOR_MATERIAL);
        glShadeModel(GL_SMOOTH);
    }

    void resizeGL(int width, int height) override {
        glViewport(0, 0, width, height);
        glMatrixMode(GL_PROJECTION);
        glLoadIdentity();
        gluPerspective(45.0, (float)width / height, 0.1, 100.0);
        glMatrixMode(GL_MODELVIEW);
        glLoadIdentity();
    }

    void paintGL() override {
        glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
        glLoadIdentity();
        glTranslatef(xTrans, yTrans, -10.0f);
        glRotatef(xRot, 1.0f, 0.0f, 0.0f);
        glRotatef(yRot, 0.0f, 1.0f, 0.0f);
        glRotatef(zRot, 0.0f, 0.0f, 1.0f);
        drawTetrahedron();
    }

    void drawTetrahedron() {
        static const GLfloat tetrahedron[4][3] = {
            { 1.0f, 1.0f, 1.0f },
            { -1.0f, -1.0f, 1.0f },
            { -1.0f, 1.0f, -1.0f },
            { 1.0f, -1.0f, -1.0f }
        };

        static const GLfloat colors[4][3] = {
            { 1.0f, 0.0f, 0.0f },
            { 0.0f, 1.0f, 0.0f },
            { 0.0f, 0.0f, 1.0f },
            { 1.0f, 1.0f, 0.0f }
        };

        glBegin(GL_TRIANGLES);
        for (int i = 0; i < 4; ++i) {
            glColor3fv(colors[i]);
            glVertex3fv(tetrahedron[i]);
            for (int j = i + 1; j < 4; ++j) {
                glVertex3fv(tetrahedron[j]);
                for (int k = j + 1; k < 4; ++k) {
                    glVertex3fv(tetrahedron[k]);
                }
            }
        }
        glEnd();
    }

    void keyPressEvent(QKeyEvent *event) override {
        switch (event->key()) {
        case Qt::Key_W:
            xTrans += 0.1f;
            break;
        case Qt::Key_S:
            xTrans -= 0.1f;
            break;
        case Qt::Key_A:
            yTrans += 0.1f;
            break;
        case Qt::Key_D:
            yTrans -= 0.1f;
            break;
        case Qt::Key_Q:
            zTrans += 0.1f;
            break;
        case Qt::Key_E:
            zTrans -= 0.1f;
            break;
        case Qt::Key_R:
            zRot += 5.0f;
            break;
        case Qt::Key_T:
            zRot -= 5.0f;
            break;
        default:
            QOpenGLWindow::keyPressEvent(event);
        }
        update();
    }

private:
    GLfloat xRot, yRot, zRot;
    GLfloat xTrans, yTrans, zTrans;
};

#endif // TETRAEDER_H
