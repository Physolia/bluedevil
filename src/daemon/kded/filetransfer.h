/***************************************************************************
 *   Copyright (C) 2010 Alejandro Fiestas Olivares <afiestas@kde.org>      *
 *   Copyright (C) 2010 UFO Coders <info@ufocoders.com>                    *
 *                                                                         *
 *   This program is free software; you can redistribute it and/or modify  *
 *   it under the terms of the GNU General Public License as published by  *
 *   the Free Software Foundation; either version 2 of the License, or     *
 *   (at your option) any later version.                                   *
 *                                                                         *
 *   This program is distributed in the hope that it will be useful,       *
 *   but WITHOUT ANY WARRANTY; without even the implied warranty of        *
 *   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the         *
 *   GNU General Public License for more details.                          *
 *                                                                         *
 *   You should have received a copy of the GNU General Public License     *
 *   along with this program; if not, write to the                         *
 *   Free Software Foundation, Inc.,                                       *
 *   51 Franklin Street, Fifth Floor, Boston, MA 02110-1301 USA            *
 ***************************************************************************/

#ifndef FILETRANSFER_H
#define FILETRANSFER_H

#include "obexd_interface.h"

#include <QObject>


class QDBusObjectPath;
class QDBusPendingCallWatcher;
class FileTransfer : public QObject
{

Q_OBJECT
public:
    FileTransfer(QObject *parent);
    virtual ~FileTransfer();

public Q_SLOTS:
    void initFileTransfer(QDBusPendingCallWatcher *watcher);
    void SessionCreated(QDBusObjectPath );
    void SessionRemoved(QDBusObjectPath );
    void TransferStarted(QDBusObjectPath);
    void TransferCompleted(QDBusObjectPath,bool);

private:
    org::openobex::Manager *m_manager;
};

#endif // FILETRANSFER_H