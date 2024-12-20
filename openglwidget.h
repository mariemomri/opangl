#ifndef OPENGLWIDGET_H
#define OPENGLWIDGET_H

#include <QOpenGLWidget>
#include <QOpenGLFramebufferObject>
#include "openglframebufferobject.h"

class OpenGLWidget : public QOpenGLWidget {
    Q_OBJECT

public:
    explicit OpenGLWidget(QWidget* parent = nullptr);
    ~OpenGLWidget();

protected:
    void initializeGL() override;
    void resizeGL(int w, int h) override;
    void paintGL() override;

private:
    OpenGLFramebufferObject* m_fboObject;
};

#endif // OPENGLWIDGET_H
