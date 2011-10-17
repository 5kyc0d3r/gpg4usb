/*
 *      keylist.h
 *
 *      Copyright 2008 gpg4usb-team <gpg4usb@cpunk.de>
 *
 *      This program is free software; you can redistribute it and/or modify
 *      it under the terms of the GNU General Public License as published by
 *      the Free Software Foundation; either version 2 of the License, or
 *      (at your option) any later version.
 *
 *      This program is distributed in the hope that it will be useful,
 *      but WITHOUT ANY WARRANTY; without even the implied warranty of
 *      MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 *      GNU General Public License for more details.
 *
 *      You should have received a copy of the GNU General Public License
 *      along with this program; if not, write to the Free Software
 *      Foundation, Inc., 51 Franklin Street, Fifth Floor, Boston,
 *      MA 02110-1301, USA.
 */

#ifndef __KEYLIST_H__
#define __KEYLIST_H__

#include "context.h"

QT_BEGIN_NAMESPACE
class QWidget;
class QVBoxLayout;
class QLabel;
class QTableWidget;
class QMenu;
QT_END_NAMESPACE

class KeyList : public QWidget
{
    Q_OBJECT

public:
    KeyList(GpgME::Context *ctx, QString iconpath, QWidget *parent = 0);
    void setColumnWidth(int row, int size);
    void addMenuAction(QAction *act);

    QStringList *getChecked();
    QStringList *getPrivateChecked();
    GpgKey getKeyByFpr(QString fpr);

    void setChecked(QStringList *keyIds);
    //QStringList *getPrivateChecked();
    QStringList *getSelected();
    void markKeys(QStringList *keyIds);

public slots:
    void refresh();

private:
    GpgME::Context *mCtx;
    QTableWidget *mKeyList;
    QString iconPath;
    QMenu *popupMenu;

protected:
    void contextMenuEvent(QContextMenuEvent *event);
    void dragEnterEvent(QDragEnterEvent *event);
    void dropEvent(QDropEvent* event);};

#endif // __KEYLIST_H__
