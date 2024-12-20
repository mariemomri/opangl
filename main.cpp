#include <QGuiApplication>
#include <QQmlApplicationEngine>
#include <QQmlContext>
#include <QSurfaceFormat>
#include "databasemanager.h"
#include "openglframebufferobject.h"

int main(int argc, char *argv[])
{
    QGuiApplication app(argc, argv);

    // Initialisation de OpenGL
    QSurfaceFormat format;
    format.setDepthBufferSize(24);  // Réglage du tampon de profondeur
    QSurfaceFormat::setDefaultFormat(format);

    // Créer une instance de DatabaseManager
    DatabaseManager dbManager;

    // Exposez l'instance à QML
    QQmlApplicationEngine engine;
    engine.rootContext()->setContextProperty("dbManager", &dbManager);

    const QUrl url(QStringLiteral("qrc:/main.qml"));
    engine.load(url);

    if (engine.rootObjects().isEmpty())
        return -1;

    return app.exec();
}
