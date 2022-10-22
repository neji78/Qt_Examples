#include "contentmodel.h"
#include <QDebug>

ContentModel::ContentModel(QObject *parent):QAbstractListModel(parent)
{
    /*while(query->next()){
        qDebug()<<query->value(0);
    }*/
}

QVariant ContentModel::data(const QModelIndex &index, int role) const
{
    if (!hasIndex(index.row(), index.column(), index.parent()))
        return {};

    const MyListItem &item = m_list.at(index.row());
    if (role == TitleRole) return item.Title;
    if (role == AlbumIdRole) return item.AlbumId;
    if (role == ArtistIdRole) return item.ArtistId;

    return {};
}

int ContentModel::rowCount(const QModelIndex &parent) const
{
    if (parent.isValid())
        return 0;
    return m_list.size();
}

void ContentModel::load_data(QSqlQuery *query)
{
    MyListItem data_moc;
    while(query->next()){
        data_moc.AlbumId = query->value(0).toString();
        data_moc.Title = query->value(1).toString();
        data_moc.ArtistId = query->value(2).toString();
        m_list.append(data_moc);
    }
}



