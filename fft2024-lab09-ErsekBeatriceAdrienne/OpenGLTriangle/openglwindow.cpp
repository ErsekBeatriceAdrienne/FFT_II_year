
#include "openglwindow.h"

#include <QOpenGLContext>
#include <QOpenGLPaintDevice>
#include <QPainter>

OpenGLWindow::OpenGLWindow(QWindow *parent)
    : QWindow(parent)
{
    setSurfaceType(QWindow::OpenGLSurface);
}

OpenGLWindow::~OpenGLWindow() {
    delete m_device;
}

void OpenGLWindow::render(QPainter *) {
}

void OpenGLWindow::initialize() {
}

void OpenGLWindow::render() {
    if (!m_device) {
        m_device = new QOpenGLPaintDevice;
    }

    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT | GL_STENCIL_BUFFER_BIT);

    m_device->setSize(size() * devicePixelRatio());
    m_device->setDevicePixelRatio(devicePixelRatio());

    QPainter painter(m_device);
    render(&painter);
}

void OpenGLWindow::renderLater() {
    requestUpdate();
}

bool OpenGLWindow::event(QEvent *event) {
    switch (event->type()) {
    case QEvent::UpdateRequest:
        renderNow();
        return true;
    default:
        return QWindow::event(event);
    }
}

void OpenGLWindow::exposeEvent(QExposeEvent *) {
    if (isExposed()) {
        renderNow();
    }
}

void OpenGLWindow::renderNow() {
    if (!isExposed()) {
        return;
    }

    bool needsInitialize = false;

    if (!m_context) {
        m_context = new QOpenGLContext(this);
        m_context->setFormat(requestedFormat());
        m_context->create();

        needsInitialize = true;
    }

    m_context->makeCurrent(this);

    if (needsInitialize) {
        initializeOpenGLFunctions();
        initialize();
    }

    render();

    m_context->swapBuffers(this);

    if (m_animating) {
        renderLater();
    }
}

void OpenGLWindow::setAnimating(bool animating) {
    m_animating = animating;

    if (animating) {
        renderLater();
    }
}
