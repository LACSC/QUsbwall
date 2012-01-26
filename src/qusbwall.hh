/*
** File qusbwall.h for project qusbwall
**
** Made by Philippe THIERRY
** Login   <phil@reseau-libre.net>
**
** Started on  sam. 21 janv. 2012 17:34:23 CET Philippe THIERRY
** Last update sam. 21 janv. 2012 18:32:39 CET Philippe THIERRY
**
** Copyright (C) 2009 - Philippe THIERRY
**
** This program is free software; you can redistribute it and/or
** modify it under the terms of the GNU Lesser General Public License
** as published by the Free Software Foundation; either version 2
** of the License, or (at your option) any later version.
**
** This program is distributed in the hope that it will be useful,
** but WITHOUT ANY WARRANTY; without even the implied warranty of
** MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
** GNU General Public License for more details.
**
** You should have received a copy of the GNU General Public License
** along with this program; if not, write to the Free Software
** Foundation, Inc., 59 Temple Place - Suite 330, Boston, MA  02111-1307, USA.
*/
/**
** \file qusbwall.h
**
** Brief documentation on one line
** Detailed documentation
** On multiple lines...
**
** \author Philippe THIERRY
**
** \requirements
** This header is compliant of the following requirements :
** REQ_CODE_QUALITY_130
** REQ_CODE_QUALITY_140
** REQ_CODE_QUALITY_150
*/

#ifndef QUSBWALL_H_
# define QUSBWALL_H_

#include <QFile>
#include <iostream>
#include "ui_qusbwall.h"

class QUsbwallMaster : public QMainWindow, private Ui::QUsbwall
{
    Q_OBJECT

public slots:
    void LoadKeyfile(void);
    void LoadAllKeys(void);

public:
    QUsbwallMaster(QWidget *parent = 0);

private:
    QFile keyfile;

};

#endif /* !QUSBWALL_H_ */
