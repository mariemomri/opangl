#ifndef OPENGLFRAMEBUFFEROBJECT_H
#define OPENGLFRAMEBUFFEROBJECT_H

#include <QOpenGLFramebufferObject>
#include <QOpenGLFunctions>
#include <QObject>  // Ajout de QObject pour la gestion des signaux et slots

class OpenGLFramebufferObject : public QObject, public QOpenGLFramebufferObject, protected QOpenGLFunctions
{
    Q_OBJECT  // Nécessaire pour utiliser le système de signaux/slots de Qt

public:
    OpenGLFramebufferObject(int width, int height);
    ~OpenGLFramebufferObject();

    void initializeOpenGL();
    void render();
};

#endif // OPENGLFRAMEBUFFEROBJECT_H
