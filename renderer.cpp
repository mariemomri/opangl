#include "renderer.h"
#include <QOpenGLShaderProgram>
#include <QOpenGLFramebufferObject>
#include <QOpenGLFunctions_3_3_Core> // Si vous utilisez OpenGL 3.3 ou supérieur

Renderer::Renderer()
    : m_program(nullptr), m_fbo(nullptr), m_texture(0), m_angle(0.0f)
{
    // Initialisation des membres
}

Renderer::~Renderer()
{
    // Libérer les ressources
    if (m_program) {
        delete m_program;
    }
    if (m_fbo) {
        delete m_fbo;
    }
}

void Renderer::initialize()
{
    initializeOpenGLFunctions();

    // Initialiser votre programme shader
    m_program = new QOpenGLShaderProgram();
    m_program->addShaderFromSourceFile(QOpenGLShader::Vertex, ":/shaders/vertex_shader.glsl");
    m_program->addShaderFromSourceFile(QOpenGLShader::Fragment, ":/shaders/fragment_shader.glsl");
    m_program->link();

    // Initialisation des buffers et objets OpenGL
    glGenVertexArrays(1, &m_vao);
    glGenBuffers(1, &m_vbo);
    glGenBuffers(1, &m_ibo);
}

void Renderer::render()
{
    // Code de rendu OpenGL
    m_program->bind();
    // Configurez vos matrices et autres paramètres
    // Rendu des objets
    m_program->release();
}

QOpenGLFramebufferObject* Renderer::createFramebufferObject(const QSize &size)
{
    if (m_fbo) {
        delete m_fbo;
    }
    m_fbo = new QOpenGLFramebufferObject(size);
    return m_fbo;
}
