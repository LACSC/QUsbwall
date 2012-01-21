/*
** File main.h for project 
**
** Made by Philippe THIERRY
** Login   <phil@reseau-libre.net>
**
** Started on  mer. 11 mai 2011 16:45:48 CEST Philippe THIERRY
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
/*
** \file main.h
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

#ifndef MAIN_H_
# define MAIN_H_

extern "C" {
#include <stdio.h>
#include <cm_libcommon.h>
#include <common/cm_libdebug.h>
#include <inttypes.h>
#include <unistd.h>
#include <sys/wait.h>
#include <sched.h>
#include "debug.h"
#include "init.h"
#include "options.h"
#include "measurement.h"
#include "help.h"

const struct cm_s_type_errno*
get_perrno(void);

int
get_gui_token(void);

}
#endif /* !MAIN_H_ */
