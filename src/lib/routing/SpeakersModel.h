//
// This file is part of the Marble Virtual Globe.
//
// This program is free software licensed under the GNU LGPL. You can
// find a copy of this license in LICENSE.txt in the top directory of
// the source code.
//
// Copyright 2012      Dennis Nienhüser <earthwings@gentoo.org>
//

#ifndef MARBLE_SPEAKERSMODEL_H
#define MARBLE_SPEAKERSMODEL_H

#include <QtCore/QAbstractListModel>
#include <QtCore/QFileInfo>

namespace Marble
{

class SpeakersModel : public QAbstractListModel
{
    Q_OBJECT

public:
    /** Constructor */
    explicit SpeakersModel( QObject *parent = 0 );

    /** Destructor */
    ~SpeakersModel();

    /** Overload of QAbstractListModel */
    int rowCount ( const QModelIndex &parent = QModelIndex() ) const;

    /** Overload of QAbstractListModel */
    QVariant data ( const QModelIndex &index, int role = Qt::DisplayRole ) const;

    int indexOf( const QString &name );

private:
    void fillModel();

    QList<QFileInfo> m_speakers;
};

}

#endif // MARBLE_SPEAKERSMODEL_H
