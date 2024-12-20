#include "OpenGLItem.h"
#include <QOpenGLShader>
#include <QSGNode>
#include <QOpenGLBuffer>

OpenGLItem::OpenGLItem()
{
    setFlag(ItemHasContents, true);  // Indique qu'on va avoir un contenu OpenGL
}

OpenGLItem::~OpenGLItem()
{
    shaderProgram.removeAllShaders();
    vertexBuffer.destroy();
}

QSGNode* OpenGLItem::updatePaintNode(QSGNode *node, UpdatePaintNodeData *)
{
    if (!node) {
        node = new QSGNode;
    }

    initializeOpenGLFunctions();  // Initialisation des fonctions OpenGL

    // Création du shader (vertex et fragment)
    const char *vertexShaderSource = R"(
        #version 300 es
        in vec2 position;
        void main() {
            gl_Position = vec4(position, 0.0, 1.0);
        })";

    const char *fragmentShaderSource = R"(
        #version 300 es
        precision mediump float;
        out vec4 fragColor;
        void main() {
            fragColor = vec4(1.0, 0.0, 0.0, 1.0);  // Rouge
        })";

    shaderProgram.addShaderFromSourceCode(QOpenGLShader::Vertex, vertexShaderSource);
    shaderProgram.addShaderFromSourceCode(QOpenGLShader::Fragment, fragmentShaderSource);
    shaderProgram.link();
    shaderProgram.bind();  // Lier le shader

    // Définir les sommets du rectangle
    GLfloat vertices[] = {
        -0.5f,  0.5f,
        0.5f,  0.5f,
        -0.5f, -0.5f,
        0.5f, -0.5f
    };

    // Allocation du tampon de vertex
    vertexBuffer.create();
    vertexBuffer.bind();
    vertexBuffer.allocate(vertices, sizeof(vertices));

    // Effacer l'écran (le tampon de couleur)
    glClear(GL_COLOR_BUFFER_BIT);

    // Lier et dessiner le rectangle
    shaderProgram.bind();
    vertexBuffer.bind();
    shaderProgram.setAttributeBuffer("position", GL_FLOAT, 0, 2, sizeof(GLfloat) * 2);
    shaderProgram.enableAttributeArray("position");

    // Dessiner le rectangle
    glDrawArrays(GL_TRIANGLE_STRIP, 0, 4);

    return node;  // Retourner le node pour la scène
}
