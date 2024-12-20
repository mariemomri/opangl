#include "databasemanager.h"
#include <QSqlError>
#include <QSqlQuery>

DatabaseManager::DatabaseManager(QObject *parent) : QObject(parent)
{
    connectToDatabase();
}

DatabaseManager::~DatabaseManager()
{
    if (db.isOpen()) {
        db.close();
    }
}

bool DatabaseManager::connectToDatabase()
{
    db = QSqlDatabase::addDatabase("QMYSQL");
    db.setHostName("dengtech.systems");  // Modifiez selon votre configuration
    db.setDatabaseName("admin_test");
    db.setUserName("admin_mounir");
    db.setPassword("123456mounir");

    if (!db.open()) {
        qDebug() << "Database connection failed:" << db.lastError().text();
        return false;
    }
    return true;
}

bool DatabaseManager::addItem(const QString &id, const QString &name)
{
    QSqlQuery query;
    query.prepare("INSERT INTO items (id, name) VALUES (?, ?)");
    query.addBindValue(id);
    query.addBindValue(name);
    return query.exec();
}

QString DatabaseManager::getItemName(const QString &id)
{
    QSqlQuery query;
    query.prepare("SELECT name FROM items WHERE id = ?");
    query.addBindValue(id);

    if (query.exec() && query.next()) {
        return query.value(0).toString();
    }
    return QString();
}

bool DatabaseManager::updateItem(const QString &id, const QString &name)
{
    QSqlQuery query;
    query.prepare("UPDATE items SET name = ? WHERE id = ?");
    query.addBindValue(name);
    query.addBindValue(id);
    return query.exec();
}

bool DatabaseManager::deleteItem(const QString &id)
{
    QSqlQuery query;
    query.prepare("DELETE FROM items WHERE id = ?");
    query.addBindValue(id);
    return query.exec();
}
