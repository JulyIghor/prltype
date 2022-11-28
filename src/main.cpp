//  This file is a part of Prl Type
//      https://github.com/JulyIghor/prltype
//  Copyright (C) 2020-2022 July Ighor <julyighor@gmail.com>
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

#include "prltype.h"
#include <iostream>
#include <unordered_map>

int main(int argc, char* argv[])
{
    if (argc < 2)
    {
        std::cout << "PrlType v1.1\nhttps://github.com/JulyIghor/prltype\n\nUsage: " << argv[0] << " <VM Name> <text/command>" << std::endl;
        return -1;
    }

    PrlType prl;

    if (!prl.connect(argv[1]))
    {
        std::cout << "Can't connect to VM " << argv[1] << std::endl;
        return -1;
    }

    for (int w = 2; w < argc; w++)
        if (!prl.typeString(argv[w]))
        {
            std::cout << "Failed to type " << argv[w] << std::endl;
            return 1;
        }
    return 0;
}
