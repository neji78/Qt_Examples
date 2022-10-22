#ifndef QDBFILE_H
#define QDBFILE_H

#include <QObject>
#include "qtable.h"
#include <QSqlError>

class QDBFile : public QObject
{
    Q_OBJECT
private:
    QString dbfilename;
    QTable *current_table;
    QStringList tables;
    QSqlDatabase db;
public:
    explicit QDBFile(QString name);
    QString get_dbfile_name(){return dbfilename;}
    QTable *get_current_table(){return current_table;}
    void set_current_table(QString table_name);
    //void create_table(QString table_name);

signals:

};

#endif // QDBFILE_H
