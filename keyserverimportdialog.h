/*
 *
 *      keyserverimportdialog.h
 *
 *      Copyright 2008 gpg4usb-team <gpg4usb@cpunk.de>
 *
 *      This file is part of gpg4usb.
 *
 *      Gpg4usb is free software: you can redistribute it and/or modify
 *      it under the terms of the GNU General Public License as published by
 *      the Free Software Foundation, either version 3 of the License, or
 *      (at your option) any later version.
 *
 *      Gpg4usb is distributed in the hope that it will be useful,
 *      but WITHOUT ANY WARRANTY; without even the implied warranty of
 *      MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 *      GNU General Public License for more details.
 *
 *      You should have received a copy of the GNU General Public License
 *      along with gpg4usb.  If not, see <http://www.gnu.org/licenses/>
 */

#ifndef __KEYSERVERIMPORTDIALOG_H__
#define __KEYSERVERIMPORTDIALOG_H__

#include "gpgcontext.h"
#include "keyimportdetaildialog.h"
#include "keylist.h"
#include <QNetworkAccessManager>
#include <QtNetwork>

QT_BEGIN_NAMESPACE
class QDialog;
class QDir;
class QUrl;
class QtGui;
class QPixmap;
class QNetworkReply;
class QComboBox;
class QLabel;
class QPushButton;
class QTableWidget;
class QTableWidgetItem;
class QLineEdit;
class QPalette;
class QTreeWidget;
class QTreeWidgetItem;
QT_END_NAMESPACE

class KeyServerImportDialog : public QDialog
{
    Q_OBJECT

public:
    KeyServerImportDialog(GpgME::GpgContext *ctx, KeyList *keyList, QWidget *parent = 0);
    void slotImport(QStringList keyIds);
    void slotImport(QStringList keyIds, QUrl keyserverUrl);

private slots:
    void slotImport();
    void slotSearchFinished();
    void slotImportFinished();
    void slotSearch();

private:
    void createKeysTable();
    void setMessage(const QString &text, bool error);
    void close();
    void importKeys(QByteArray inBuffer);

    QPushButton *createButton(const QString &text, const char *member);
    QComboBox *createComboBox();
    GpgME::GpgContext *mCtx;
    KeyList *mKeyList;
    QLineEdit *searchLineEdit;
    QComboBox *keyServerComboBox;
    QLabel *searchLabel;
    QLabel *keyServerLabel;
    QLabel *message;
    QLabel *icon;
    QPushButton *closeButton;
    QPushButton *importButton;
    QPushButton *searchButton;
    QTableWidget *keysTable;
    QUrl url;
    QNetworkAccessManager *qnam;

};
#endif // __KEYSERVERIMPORTDIALOG_H__
