#ifndef OPENGLITEM_H
#define OPENGLITEM_H

#include <QQuickItem>
#include <QOpenGLFunctions>
#include <QOpenGLShaderProgram>
#include <QOpenGLBuffer>
#include <QSGNode>

class OpenGLItem : public QQuickItem, protected QOpenGLFunctions
{
    Q_OBJECT

public:
    OpenGLItem();
    ~OpenGLItem();

protected:
    QSGNode* updatePaintNode(QSGNode *node, UpdatePaintNodeData *) override;

private:
    QOpenGLShaderProgram shaderProgram;
    QOpenGLBuffer vertexBuffer;
};

#endif // OPENGLITEM_H
