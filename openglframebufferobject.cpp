#include "openglframebufferobject.h"
#include <QOpenGLShaderProgram>

OpenGLFramebufferObject::OpenGLFramebufferObject(int width, int height)
    : QOpenGLFramebufferObject(width, height)
{
    initializeOpenGL();
}

OpenGLFramebufferObject::~OpenGLFramebufferObject() {}

void OpenGLFramebufferObject::initializeOpenGL()
{
    initializeOpenGLFunctions();
    glEnable(GL_DEPTH_TEST);
}

void OpenGLFramebufferObject::render()
{
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    // Ajoutez ici le code pour rendre vos objets 3D
}
