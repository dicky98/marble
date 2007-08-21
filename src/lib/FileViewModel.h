//
// This file is part of the Marble Desktop Globe.
//
// This program is free software licensed under the GNU LGPL. You can
// find a copy of this license in LICENSE.txt in the top directory of
// the source code.
//
// Copyright 2007      Murad Tagirov <tmurad@gmail.com>
//


#ifndef FILEVIEWMODEL_H
#define FILEVIEWMODEL_H

#include <QtCore/QAbstractListModel>
#include <QtCore/QList>

class AbstractFileViewItem;

class FileViewModel : public QAbstractListModel
{
    Q_OBJECT

  public:
    FileViewModel( QObject* parent = 0 );
    ~FileViewModel();

    virtual int rowCount( const QModelIndex& parent = QModelIndex() ) const;
    virtual QVariant data( const QModelIndex& index, int role = Qt::DisplayRole ) const;
    virtual Qt::ItemFlags flags( const QModelIndex& index ) const;
    virtual bool setData (const QModelIndex& index, const QVariant& value, int role = Qt::EditRole );

    void setSelectedIndex( const QModelIndex& index );
    void append ( AbstractFileViewItem* item );

  public slots:
    void saveFile();
    void closeFile();

  private:
    QModelIndex m_selectedIndex;
    QList < AbstractFileViewItem* > m_itemList;
};

#endif
