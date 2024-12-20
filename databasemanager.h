#ifndef DATABASEMANAGER_H
#define DATABASEMANAGER_H

#include <QObject>
#include <QSqlDatabase>
#include <QSqlQuery>
#include <QSqlError>
#include <QVariant>
#include <QDebug>

class DatabaseManager : public QObject
{
    Q_OBJECT
public:
    explicit DatabaseManager(QObject *parent = nullptr);
    ~DatabaseManager();

    bool connectToDatabase();
    bool addItem(const QString &id, const QString &name);
    QString getItemName(const QString &id);
    bool updateItem(const QString &id, const QString &name);
    bool deleteItem(const QString &id);

private:
    QSqlDatabase db;
};

#endif // DATABASEMANAGER_H
