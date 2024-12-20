#include "OpenGLWidget.h"

OpenGLWidget::OpenGLWidget(QWidget* parent)
    : QOpenGLWidget(parent), m_fboObject(nullptr) {
    m_fboObject = new OpenGLFramebufferObject(640, 480);
}

OpenGLWidget::~OpenGLWidget() {
    delete m_fboObject;
}

void OpenGLWidget::initializeGL() {
    // Initialiser OpenGL et le FBO
    m_fboObject->initializeOpenGLFunctions();
}

void OpenGLWidget::resizeGL(int w, int h) {
    // Redimensionner le FBO
    m_fboObject->resizeGL(w, h);
}

void OpenGLWidget::paintGL() {
    // Dessiner dans le FBO
    m_fboObject->paintGL();
    // Vous pouvez également dessiner ici tout ce que vous souhaitez sur l'écran principal
}
