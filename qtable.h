#ifndef QTABLE_H
#define QTABLE_H

#include <QObject>
#include <QSqlQuery>
#include <QSqlRecord>

class QTable : public QObject
{
    Q_OBJECT
private:
    QString table_name;
    QSqlRecord table_format;
    QSqlQuery *query;
public:
    explicit QTable(QSqlDatabase &qry,QString tname);
    void update(struct word_key_ packet);
    void add_column(QString column);
    QSqlQuery *get_data(QString variable,QString key);
    QSqlRecord get_table_format(){return table_format;}
    QString get_table_name(){return table_name;}
    int get_count_data();
    QSqlQuery *get_all_data();

signals:

};

#endif // QTABLE_H
