#ifndef CONTENTMODEL_H
#define CONTENTMODEL_H

#include <QAbstractListModel>
#include <QSqlQuery>
#include <QModelIndex>
#include <QObject>

struct MyListItem
{
    QString AlbumId;
    QString Title;
    QString ArtistId;
};
class ContentModel : public QAbstractListModel
{
    Q_OBJECT
    Q_ENUMS(MyRoles)
public:
    enum MyRoles {
        AlbumIdRole = Qt::UserRole + 1,
        TitleRole,
        ArtistIdRole
    };
    using QAbstractListModel::QAbstractListModel;

    QHash<int,QByteArray> roleNames() const override {
        return { { AlbumIdRole, "AlbumId" },
            { TitleRole, "Title" },
            { ArtistIdRole, "ArtistId" },
        };
    }
public:
    ContentModel(QObject *parent = nullptr);

public:
   QVariant data(const QModelIndex &index, int role) const override;
   int rowCount(const QModelIndex &parent = QModelIndex()) const override;
   void load_data(QSqlQuery *query);

private:
   QVector<MyListItem> m_list;
};

#endif // CONTENTMODEL_H
