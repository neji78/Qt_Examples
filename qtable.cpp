#include "qtable.h"
#include <QDebug>
#include <QSqlError>

QTable::QTable(QSqlDatabase &qry,QString tname) : QObject()
{
    query = new QSqlQuery(qry);
    table_name = tname;
    table_format = qry.record(table_name);
    for(int i = 0;i < table_format.count();i++){
        qDebug()<<table_format.fieldName(i);
    }
}

/*void QTable::update(struct word_key_ packet)
{
    if(!(query->exec("UPDATE "+table_name+" SET mean = '"+packet.mean+"',key = '"+packet.key+"' WHERE word = '"+packet.word+"';")))
        qDebug()<<query->lastError().text();
}*/

void QTable::add_column(QString column)
{

}

QSqlQuery *QTable::get_data(QString variable,QString key)
{
    if(query->exec("SELECT * FROM "+table_name+" WHERE "+variable+" LIKE "+ key))
        return query;
    else
        qDebug()<<"not found";

}

int QTable::get_count_data()
{
   if(query->exec("SELECT COUNT(*) FROM "+table_name+";")){
       query->first();
       return query->value(0).toInt();
   }else{
       return 0;
   }
}

QSqlQuery *QTable::get_all_data()
{
    if(query->exec("SELECT * FROM "+table_name))
        return query;
    else
        qDebug()<<"not found";

}
