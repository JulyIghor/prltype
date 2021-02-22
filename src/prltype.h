//  This file is part of Prl Type
//      https://github.com/JulyIghor/prltype
//  Copyright (C) 2020-2021 July Ighor <julyighor@gmail.com>
//
//  This program is free software: you can redistribute it and/or modify
//  it under the terms of the GNU General Public License as published by
//  the Free Software Foundation, either version 3 of the License, or
//  (at your option) any later version.
//
//  In addition, as a special exception, the copyright holders give
//  permission to link the code of portions of this program with the
//  OpenSSL library under certain conditions as described in each
//  individual source file, and distribute linked combinations including
//  the two.
//
//  This program is distributed in the hope that it will be useful,
//  but WITHOUT ANY WARRANTY; without even the implied warranty of
//  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
//  GNU General Public License for more details.
//
//  You should have received a copy of the GNU General Public License
//  along with this program.  If not, see <http://www.gnu.org/licenses/>.

#ifndef PRLTYPE_H
#define PRLTYPE_H

#include "Parallels.h"
#include <list>

typedef std::list<std::pair<unsigned int, bool>> PrlTypeKeyList;

class PrlType
{
public:
    explicit PrlType();
    ~PrlType();
    bool connect(const char* name);
    bool disconnect();
    bool typeString(std::string string);

private:
    bool typeList(const PrlTypeKeyList& list);
    bool typePair(const std::pair<unsigned int, bool>& pair);
    const PrlTypeKeyList& stringToScanCode(std::string key);
    const PrlTypeKeyList& charToScanCode(char key);
    PRL_RESULT LoginLocal(PRL_HANDLE& hServer);
    PRL_RESULT LogOff(PRL_HANDLE& hServer);
    PRL_RESULT GetVm(PRL_HANDLE& hRetVm, PRL_HANDLE& hServer, const char* vmName);
    PRL_RESULT ConnectToConsole(PRL_HANDLE vm);
    PRL_RESULT DisconnectFromConsole(PRL_HANDLE vm);
    PRL_HANDLE hServer = PRL_INVALID_HANDLE;
    PRL_HANDLE hVm = PRL_INVALID_HANDLE;
};

#endif // PRLTYPE_H
