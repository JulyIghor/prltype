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

#include "prltype.h"
#include <algorithm>
#include <chrono>
#include <iostream>
#include <thread>
#include <unordered_map>
#include <utility>
using namespace std::literals::chrono_literals;

PrlType::PrlType()
{
}

PrlType::~PrlType()
{
    disconnect();
}

const PrlTypeKeyList& PrlType::charToScanCode(char key)
{
    static const std::unordered_map<char, PrlTypeKeyList> keyHash = []()
    {
        std::unordered_map<char, PrlTypeKeyList> hash;

        hash['`'] = {std::make_pair(0x29, false), std::make_pair(0x29, true)};
        hash['1'] = {std::make_pair(0x02, false), std::make_pair(0x02, true)};
        hash['2'] = {std::make_pair(0x03, false), std::make_pair(0x03, true)};
        hash['3'] = {std::make_pair(0x04, false), std::make_pair(0x04, true)};
        hash['4'] = {std::make_pair(0x05, false), std::make_pair(0x05, true)};
        hash['5'] = {std::make_pair(0x06, false), std::make_pair(0x06, true)};
        hash['6'] = {std::make_pair(0x07, false), std::make_pair(0x07, true)};
        hash['7'] = {std::make_pair(0x08, false), std::make_pair(0x08, true)};
        hash['8'] = {std::make_pair(0x09, false), std::make_pair(0x09, true)};
        hash['9'] = {std::make_pair(0x0a, false), std::make_pair(0x0a, true)};
        hash['0'] = {std::make_pair(0x0b, false), std::make_pair(0x0b, true)};
        hash['-'] = {std::make_pair(0x0c, false), std::make_pair(0x0c, true)};
        hash['='] = {std::make_pair(0x0d, false), std::make_pair(0x0d, true)};

        hash['~'] = {std::make_pair(0x2a, false), std::make_pair(0x29, false), std::make_pair(0x29, true), std::make_pair(0x2a, true)};
        hash['!'] = {std::make_pair(0x2a, false), std::make_pair(0x02, false), std::make_pair(0x02, true), std::make_pair(0x2a, true)};
        hash['@'] = {std::make_pair(0x2a, false), std::make_pair(0x03, false), std::make_pair(0x03, true), std::make_pair(0x2a, true)};
        hash['#'] = {std::make_pair(0x2a, false), std::make_pair(0x04, false), std::make_pair(0x04, true), std::make_pair(0x2a, true)};
        hash['$'] = {std::make_pair(0x2a, false), std::make_pair(0x05, false), std::make_pair(0x05, true), std::make_pair(0x2a, true)};
        hash['%'] = {std::make_pair(0x2a, false), std::make_pair(0x06, false), std::make_pair(0x06, true), std::make_pair(0x2a, true)};
        hash['^'] = {std::make_pair(0x2a, false), std::make_pair(0x07, false), std::make_pair(0x07, true), std::make_pair(0x2a, true)};
        hash['&'] = {std::make_pair(0x2a, false), std::make_pair(0x08, false), std::make_pair(0x08, true), std::make_pair(0x2a, true)};
        hash['*'] = {std::make_pair(0x2a, false), std::make_pair(0x09, false), std::make_pair(0x09, true), std::make_pair(0x2a, true)};
        hash['('] = {std::make_pair(0x2a, false), std::make_pair(0x0a, false), std::make_pair(0x0a, true), std::make_pair(0x2a, true)};
        hash[')'] = {std::make_pair(0x2a, false), std::make_pair(0x0b, false), std::make_pair(0x0b, true), std::make_pair(0x2a, true)};
        hash['_'] = {std::make_pair(0x2a, false), std::make_pair(0x0c, false), std::make_pair(0x0c, true), std::make_pair(0x2a, true)};
        hash['+'] = {std::make_pair(0x2a, false), std::make_pair(0x0d, false), std::make_pair(0x0d, true), std::make_pair(0x2a, true)};

        hash['\''] = {std::make_pair(0x28, false), std::make_pair(0x28, true)};
        hash[','] = {std::make_pair(0x33, false), std::make_pair(0x33, true)};
        hash['.'] = {std::make_pair(0x34, false), std::make_pair(0x34, true)};
        hash['/'] = {std::make_pair(0x35, false), std::make_pair(0x35, true)};
        hash[';'] = {std::make_pair(0x27, false), std::make_pair(0x27, true)};
        hash['['] = {std::make_pair(0x1a, false), std::make_pair(0x1a, true)};
        hash['\\'] = {std::make_pair(0x2b, false), std::make_pair(0x2b, true)};
        hash[']'] = {std::make_pair(0x1b, false), std::make_pair(0x1b, true)};

        hash['\"'] = {std::make_pair(0x2a, false), std::make_pair(0x28, false), std::make_pair(0x28, true), std::make_pair(0x2a, true)};
        hash['<'] = {std::make_pair(0x2a, false), std::make_pair(0x33, false), std::make_pair(0x33, true), std::make_pair(0x2a, true)};
        hash['>'] = {std::make_pair(0x2a, false), std::make_pair(0x34, false), std::make_pair(0x34, true), std::make_pair(0x2a, true)};
        hash['?'] = {std::make_pair(0x2a, false), std::make_pair(0x35, false), std::make_pair(0x35, true), std::make_pair(0x2a, true)};
        hash[':'] = {std::make_pair(0x2a, false), std::make_pair(0x27, false), std::make_pair(0x27, true), std::make_pair(0x2a, true)};
        hash['{'] = {std::make_pair(0x2a, false), std::make_pair(0x1a, false), std::make_pair(0x1a, true), std::make_pair(0x2a, true)};
        hash['|'] = {std::make_pair(0x2a, false), std::make_pair(0x2b, false), std::make_pair(0x2b, true), std::make_pair(0x2a, true)};
        hash['}'] = {std::make_pair(0x2a, false), std::make_pair(0x1b, false), std::make_pair(0x1b, true), std::make_pair(0x2a, true)};

        hash['A'] = {std::make_pair(0x2a, false), std::make_pair(0x1e, false), std::make_pair(0x1e, true), std::make_pair(0x2a, true)};
        hash['B'] = {std::make_pair(0x2a, false), std::make_pair(0x30, false), std::make_pair(0x30, true), std::make_pair(0x2a, true)};
        hash['C'] = {std::make_pair(0x2a, false), std::make_pair(0x2e, false), std::make_pair(0x2e, true), std::make_pair(0x2a, true)};
        hash['D'] = {std::make_pair(0x2a, false), std::make_pair(0x20, false), std::make_pair(0x20, true), std::make_pair(0x2a, true)};
        hash['E'] = {std::make_pair(0x2a, false), std::make_pair(0x12, false), std::make_pair(0x12, true), std::make_pair(0x2a, true)};
        hash['F'] = {std::make_pair(0x2a, false), std::make_pair(0x21, false), std::make_pair(0x21, true), std::make_pair(0x2a, true)};
        hash['G'] = {std::make_pair(0x2a, false), std::make_pair(0x22, false), std::make_pair(0x22, true), std::make_pair(0x2a, true)};
        hash['H'] = {std::make_pair(0x2a, false), std::make_pair(0x23, false), std::make_pair(0x23, true), std::make_pair(0x2a, true)};
        hash['I'] = {std::make_pair(0x2a, false), std::make_pair(0x17, false), std::make_pair(0x17, true), std::make_pair(0x2a, true)};
        hash['J'] = {std::make_pair(0x2a, false), std::make_pair(0x24, false), std::make_pair(0x24, true), std::make_pair(0x2a, true)};
        hash['K'] = {std::make_pair(0x2a, false), std::make_pair(0x25, false), std::make_pair(0x25, true), std::make_pair(0x2a, true)};
        hash['L'] = {std::make_pair(0x2a, false), std::make_pair(0x26, false), std::make_pair(0x26, true), std::make_pair(0x2a, true)};
        hash['M'] = {std::make_pair(0x2a, false), std::make_pair(0x32, false), std::make_pair(0x32, true), std::make_pair(0x2a, true)};
        hash['N'] = {std::make_pair(0x2a, false), std::make_pair(0x31, false), std::make_pair(0x31, true), std::make_pair(0x2a, true)};
        hash['O'] = {std::make_pair(0x2a, false), std::make_pair(0x18, false), std::make_pair(0x18, true), std::make_pair(0x2a, true)};
        hash['P'] = {std::make_pair(0x2a, false), std::make_pair(0x19, false), std::make_pair(0x19, true), std::make_pair(0x2a, true)};
        hash['Q'] = {std::make_pair(0x2a, false), std::make_pair(0x10, false), std::make_pair(0x10, true), std::make_pair(0x2a, true)};
        hash['R'] = {std::make_pair(0x2a, false), std::make_pair(0x13, false), std::make_pair(0x13, true), std::make_pair(0x2a, true)};
        hash['S'] = {std::make_pair(0x2a, false), std::make_pair(0x1f, false), std::make_pair(0x1f, true), std::make_pair(0x2a, true)};
        hash['T'] = {std::make_pair(0x2a, false), std::make_pair(0x14, false), std::make_pair(0x14, true), std::make_pair(0x2a, true)};
        hash['U'] = {std::make_pair(0x2a, false), std::make_pair(0x16, false), std::make_pair(0x16, true), std::make_pair(0x2a, true)};
        hash['V'] = {std::make_pair(0x2a, false), std::make_pair(0x2f, false), std::make_pair(0x2f, true), std::make_pair(0x2a, true)};
        hash['W'] = {std::make_pair(0x2a, false), std::make_pair(0x11, false), std::make_pair(0x11, true), std::make_pair(0x2a, true)};
        hash['X'] = {std::make_pair(0x2a, false), std::make_pair(0x2d, false), std::make_pair(0x2d, true), std::make_pair(0x2a, true)};
        hash['Y'] = {std::make_pair(0x2a, false), std::make_pair(0x15, false), std::make_pair(0x15, true), std::make_pair(0x2a, true)};
        hash['Z'] = {std::make_pair(0x2a, false), std::make_pair(0x2c, false), std::make_pair(0x2c, true), std::make_pair(0x2a, true)};

        hash['a'] = {std::make_pair(0x1e, false), std::make_pair(0x1e, true)};
        hash['b'] = {std::make_pair(0x30, false), std::make_pair(0x30, true)};
        hash['c'] = {std::make_pair(0x2e, false), std::make_pair(0x2e, true)};
        hash['d'] = {std::make_pair(0x20, false), std::make_pair(0x20, true)};
        hash['e'] = {std::make_pair(0x12, false), std::make_pair(0x12, true)};
        hash['f'] = {std::make_pair(0x21, false), std::make_pair(0x21, true)};
        hash['g'] = {std::make_pair(0x22, false), std::make_pair(0x22, true)};
        hash['h'] = {std::make_pair(0x23, false), std::make_pair(0x23, true)};
        hash['i'] = {std::make_pair(0x17, false), std::make_pair(0x17, true)};
        hash['j'] = {std::make_pair(0x24, false), std::make_pair(0x24, true)};
        hash['k'] = {std::make_pair(0x25, false), std::make_pair(0x25, true)};
        hash['l'] = {std::make_pair(0x26, false), std::make_pair(0x26, true)};
        hash['m'] = {std::make_pair(0x32, false), std::make_pair(0x32, true)};
        hash['n'] = {std::make_pair(0x31, false), std::make_pair(0x31, true)};
        hash['o'] = {std::make_pair(0x18, false), std::make_pair(0x18, true)};
        hash['p'] = {std::make_pair(0x19, false), std::make_pair(0x19, true)};
        hash['q'] = {std::make_pair(0x10, false), std::make_pair(0x10, true)};
        hash['r'] = {std::make_pair(0x13, false), std::make_pair(0x13, true)};
        hash['s'] = {std::make_pair(0x1f, false), std::make_pair(0x1f, true)};
        hash['t'] = {std::make_pair(0x14, false), std::make_pair(0x14, true)};
        hash['u'] = {std::make_pair(0x16, false), std::make_pair(0x16, true)};
        hash['v'] = {std::make_pair(0x2f, false), std::make_pair(0x2f, true)};
        hash['w'] = {std::make_pair(0x11, false), std::make_pair(0x11, true)};
        hash['x'] = {std::make_pair(0x2d, false), std::make_pair(0x2d, true)};
        hash['y'] = {std::make_pair(0x15, false), std::make_pair(0x15, true)};
        hash['z'] = {std::make_pair(0x2c, false), std::make_pair(0x2c, true)};

        hash[' '] = {std::make_pair(0x39, false), std::make_pair(0x39, true)};
        hash['\n'] = {std::make_pair(0x1c, false), std::make_pair(0x1c, true)};
        hash['\t'] = {std::make_pair(0x0f, false), std::make_pair(0x0f, true)};

        return hash;
    }();

    static PrlTypeKeyList empty;

    auto it = keyHash.find(key);

    if (it == keyHash.end())
        return empty;

    return it->second;
}

const PrlTypeKeyList& PrlType::stringToScanCode(std::string key)
{
    static const std::unordered_map<std::string, PrlTypeKeyList> keyHash = []()
    {
        std::unordered_map<std::string, PrlTypeKeyList> hash;

        hash["backspace"] = {std::make_pair(0x0e, false), std::make_pair(0x0e, true)};
        hash["bs"] = hash["backspace"];
        hash["capslock"] = {std::make_pair(0x3a, false), std::make_pair(0x3a, true)};

        hash["f1"] = {std::make_pair(0x3b, false), std::make_pair(0x3b, true)};
        hash["f2"] = {std::make_pair(0x3c, false), std::make_pair(0x3c, true)};
        hash["f3"] = {std::make_pair(0x3d, false), std::make_pair(0x3d, true)};
        hash["f4"] = {std::make_pair(0x3e, false), std::make_pair(0x3e, true)};
        hash["f5"] = {std::make_pair(0x3f, false), std::make_pair(0x3f, true)};
        hash["f6"] = {std::make_pair(0x40, false), std::make_pair(0x40, true)};
        hash["f7"] = {std::make_pair(0x41, false), std::make_pair(0x41, true)};
        hash["f8"] = {std::make_pair(0x42, false), std::make_pair(0x42, true)};
        hash["f9"] = {std::make_pair(0x43, false), std::make_pair(0x43, true)};
        hash["f10"] = {std::make_pair(0x44, false), std::make_pair(0x44, true)};
        hash["f11"] = {std::make_pair(0x57, false), std::make_pair(0x57, true)};
        hash["f12"] = {std::make_pair(0x58, false), std::make_pair(0x58, true)};

        hash["enter"] = {std::make_pair(0x1c, false), std::make_pair(0x1c, true)};
        hash["tab"] = {std::make_pair(0x0f, false), std::make_pair(0x0f, true)};
        hash["esc"] = {std::make_pair(0x01, false), std::make_pair(0x01, true)};
        hash["lalt"] = {std::make_pair(0x38, false), std::make_pair(0x38, true)};
        hash["lctrl"] = {std::make_pair(0x1d, false), std::make_pair(0x1d, true)};
        hash["lshift"] = {std::make_pair(0x2a, false), std::make_pair(0x2a, true)};
        hash["numlock"] = {std::make_pair(0x45, false), std::make_pair(0x45, true)};
        hash["rshift"] = {std::make_pair(0x36, false), std::make_pair(0x36, true)};
        hash["scrolllock"] = {std::make_pair(0x46, false), std::make_pair(0x46, true)};
        hash["space"] = {std::make_pair(0x39, false), std::make_pair(0x39, true)};

        hash["delete"] = {std::make_pair(0xe053, false), std::make_pair(0xe053, true)};
        hash["up"] = {std::make_pair(0xe048, false), std::make_pair(0xe048, true)};
        hash["down"] = {std::make_pair(0xe050, false), std::make_pair(0xe050, true)};
        hash["left"] = {std::make_pair(0xe04b, false), std::make_pair(0xe04b, true)};
        hash["right"] = {std::make_pair(0xe04d, false), std::make_pair(0xe04d, true)};
        hash["end"] = {std::make_pair(0xe04f, false), std::make_pair(0xe04f, true)};
        hash["home"] = {std::make_pair(0xe047, false), std::make_pair(0xe047, true)};
        hash["insert"] = {std::make_pair(0xe052, false), std::make_pair(0xe052, true)};
        hash["pgdn"] = {std::make_pair(0xe051, false), std::make_pair(0xe051, true)};
        hash["pgup"] = {std::make_pair(0xe049, false), std::make_pair(0xe049, true)};
        hash["power"] = {std::make_pair(0xe05e, false), std::make_pair(0xe05e, true)};
        hash["prtscr"] = {std::make_pair(0xe037, false), std::make_pair(0xe037, true)};
        hash["del"] = hash["delete"];

        hash["pause"] = {std::make_pair(0xe11d45, false), std::make_pair(0xe11d45, true)};
        hash["lwin"] = {std::make_pair(0xe05b, false), std::make_pair(0xe05b, true)};
        hash["ralt"] = {std::make_pair(0xe038, false), std::make_pair(0xe038, true)};
        hash["rctrl"] = {std::make_pair(0xe01d, false), std::make_pair(0xe01d, true)};
        hash["rwin"] = {std::make_pair(0xe05c, false), std::make_pair(0xe05c, true)};
        hash["sleep"] = {std::make_pair(0xe05f, false), std::make_pair(0xe05f, true)};
        hash["wake"] = {std::make_pair(0xe063, false), std::make_pair(0xe063, true)};

        hash["alt"] = hash["lalt"];
        hash["ctl"] = hash["lctrl"];
        hash["shift"] = hash["lshift"];
        hash["win"] = hash["lwin"];

        return hash;
    }();

    static PrlTypeKeyList empty;

    std::transform(key.begin(), key.end(), key.begin(), [](unsigned char c) { return std::tolower(c); });

    auto it = keyHash.find(key);

    if (it == keyHash.end())
        return empty;

    return it->second;
}

bool PrlType::typeString(std::string string)
{
    if (string.size() > 2 && string[0] == '<' && string[string.size() - 1] == '>')
    {
        string = string.substr(1, string.size() - 2);
        std::transform(string.begin(), string.end(), string.begin(), [](unsigned char c) { return std::tolower(c); });
        if (string == "wait")
        {
            std::this_thread::sleep_for(1s);
            return true;
        }

        return typeList(stringToScanCode(string));
    }

    for (auto symbol : string)
        if (!typeList(charToScanCode(symbol)))
            return false;

    return true;
}

bool PrlType::typeList(const PrlTypeKeyList& list)
{
    if (list.empty())
        return true;

    for (auto it : list)
        if (!typePair(it))
            return false;

    return true;
}

bool PrlType::typePair(const std::pair<unsigned int, bool>& pair)
{
    if (hVm == PRL_INVALID_HANDLE)
        return false;

    std::this_thread::sleep_for(50ms);

    PRL_RESULT err = PrlDevKeyboard_SendKeyEvent(hVm, pair.first, pair.second ? PKE_RELEASE : PKE_PRESS);

    if (PRL_FAILED(err))
    {
        fprintf(stderr, "PrlDevKeyboard_SendKeyEvent returned with error: %s.\n", prl_result_to_string(err));
        return false;
    }

    return true;
}

bool PrlType::connect(const char* name)
{
    hServer = PRL_INVALID_HANDLE;
    PRL_RESULT err = LoginLocal(hServer);

    if (PRL_FAILED(err))
        return false;

    hVm = PRL_INVALID_HANDLE;
    err = GetVm(hVm, hServer, name);

    if (PRL_FAILED(err))
        return false;

    err = ConnectToConsole(hVm);

    if (PRL_FAILED(err))
        return false;

    return true;
}

bool PrlType::disconnect()
{
    if (hVm == PRL_INVALID_HANDLE || hServer == PRL_INVALID_HANDLE)
        return true;

    PRL_RESULT err = DisconnectFromConsole(hVm);

    if (PRL_FAILED(err))
        return false;

    hVm = PRL_INVALID_HANDLE;

    err = LogOff(hServer);

    if (PRL_FAILED(err))
        return false;

    hServer = PRL_INVALID_HANDLE;
    return true;
}

PRL_RESULT PrlType::LoginLocal(PRL_HANDLE& hServer)
{
    PRL_HANDLE hJob = PRL_INVALID_HANDLE;
    PRL_RESULT err, nJobReturnCode = PRL_ERR_UNINITIALIZED;

    err = PrlApi_InitEx(PARALLELS_API_VER, PAM_DESKTOP, 0, 0);

    if (PRL_FAILED(err))
    {
        std::cout << "PrlApi_InitEx returned with error: " << prl_result_to_string(err) << std::endl;
        PrlApi_Deinit();
        return err;
    }

    err = PrlSrv_Create(&hServer);

    if (PRL_FAILED(err))
    {
        std::cout << "PrlSvr_Create failed, error: " << prl_result_to_string(err) << std::endl;
        PrlApi_Deinit();
        return err;
    }

    hJob = PrlSrv_LoginLocal(hServer, NULL, 0, PSL_NORMAL_SECURITY);
    err = PrlJob_Wait(hJob, 1000);

    if (PRL_FAILED(err))
    {
        std::cout << "PrlJob_Wait for PrlSrv_Login returned with error: " << prl_result_to_string(err) << std::endl;
        PrlHandle_Free(hJob);
        PrlHandle_Free(hServer);
        PrlApi_Deinit();
        return err;
    }

    err = PrlJob_GetRetCode(hJob, &nJobReturnCode);

    if (PRL_FAILED(err))
    {
        std::cout << "PrlJob_GetRetCode returned with error: " << prl_result_to_string(err) << std::endl;
        PrlHandle_Free(hJob);
        PrlHandle_Free(hServer);
        PrlApi_Deinit();
        return err;
    }

    if (PRL_FAILED(nJobReturnCode))
    {
        PrlHandle_Free(hJob);
        PrlHandle_Free(hServer);
        std::cout << "Login job returned with error: " << prl_result_to_string(nJobReturnCode) << std::endl;
        PrlHandle_Free(hJob);
        PrlHandle_Free(hServer);
        PrlApi_Deinit();
        return err;
    }

    return PRL_ERR_SUCCESS;
}

PRL_RESULT PrlType::LogOff(PRL_HANDLE& hServer)
{
    PRL_HANDLE hJob = PRL_INVALID_HANDLE;
    PRL_RESULT err, nJobReturnCode = PRL_ERR_UNINITIALIZED;
    std::this_thread::sleep_for(100ms);

    hJob = PrlSrv_Logoff(hServer);
    err = PrlJob_Wait(hJob, 1000);

    if (PRL_FAILED(err))
    {
        std::cout << "PrlJob_Wait for PrlSrv_Logoff returned error: " << prl_result_to_string(err) << std::endl;
        PrlHandle_Free(hJob);
        PrlHandle_Free(hServer);
        PrlApi_Deinit();
        return err;
    }

    err = PrlJob_GetRetCode(hJob, &nJobReturnCode);

    if (PRL_FAILED(err))
    {
        std::cout << "PrlJob_GetRetCode failed for PrlSrv_Logoff with error: " << prl_result_to_string(err) << std::endl;
        PrlHandle_Free(hJob);
        PrlHandle_Free(hServer);
        PrlApi_Deinit();
        return err;
    }

    if (PRL_FAILED(nJobReturnCode))
    {
        std::cout << "PrlSrv_Logoff failed with error: " << prl_result_to_string(nJobReturnCode) << std::endl;
        PrlHandle_Free(hJob);
        PrlHandle_Free(hServer);
        PrlApi_Deinit();
        return err;
    }

    PrlHandle_Free(hJob);
    PrlHandle_Free(hServer);
    PrlApi_Deinit();
    return PRL_ERR_SUCCESS;
}

PRL_RESULT PrlType::GetVm(PRL_HANDLE& hRetVm, PRL_HANDLE& hServer, const char* vmName)
{
    PRL_HANDLE hJob, hJobResult = PRL_INVALID_HANDLE;
    PRL_RESULT ret, nJobReturnCode = PRL_ERR_UNINITIALIZED;
    hJob = PrlSrv_GetVmList(hServer);
    ret = PrlJob_Wait(hJob, 10000);

    if (PRL_FAILED(ret))
    {
        std::cout << "PrlJob_Wait for PrlSrv_GetVmList returned with error: " << prl_result_to_string(ret) << std::endl;
        PrlHandle_Free(hJob);
        return ret;
    }

    ret = PrlJob_GetRetCode(hJob, &nJobReturnCode);

    if (PRL_FAILED(ret))
    {
        std::cout << "PrlJob_GetRetCode returned with error: " << prl_result_to_string(ret) << std::endl;
        PrlHandle_Free(hJob);
        return ret;
    }

    if (PRL_FAILED(nJobReturnCode))
    {
        std::cout << "PrlSrv_GetVmList returned with error: " << prl_result_to_string(ret) << std::endl;
        PrlHandle_Free(hJob);
        return ret;
    }

    ret = PrlJob_GetResult(hJob, &hJobResult);

    if (PRL_FAILED(ret))
    {
        std::cout << "PrlJob_GetResult returned with error: " << prl_result_to_string(ret) << std::endl;
        PrlHandle_Free(hJob);
        return ret;
    }

    PrlHandle_Free(hJob);
    PRL_UINT32 nParamsCount = 0;
    ret = PrlResult_GetParamsCount(hJobResult, &nParamsCount);

    for (PRL_UINT32 i = 0; i < nParamsCount; ++i)
    {
        PRL_HANDLE hVm = PRL_INVALID_HANDLE;
        PrlResult_GetParamByIndex(hJobResult, i, &hVm);
        char szVmNameReturned[1024];
        PRL_UINT32 nBufSize = sizeof(szVmNameReturned);
        ret = PrlVmCfg_GetName(hVm, szVmNameReturned, &nBufSize);

        if (PRL_FAILED(ret))
            std::cout << "PrlVmCfg_GetName returned with error: " << prl_result_to_string(ret) << std::endl;
        else
        {
            if (strcmp(vmName, szVmNameReturned) == 0)
            {
                hRetVm = hVm;
                return PRL_ERR_SUCCESS;
            }
        }

        PrlHandle_Free(hVm);
    }

    std::cout << "VM: " << vmName << " not found." << std::endl;
    return PRL_ERR_OPERATION_FAILED;
}

PRL_RESULT PrlType::ConnectToConsole(PRL_HANDLE vm)
{
    PRL_RESULT err, nJobReturnCode = PRL_ERR_UNINITIALIZED;
    PRL_HANDLE hJob = PrlDevDisplay_ConnectToVm(vm, PDCT_LOW_QUALITY_WITHOUT_COMPRESSION);
    err = PrlJob_Wait(hJob, 10000);

    if (PRL_FAILED(err))
    {
        std::cout << "PrlJob_Wait for PrlDevDisplay_ConnectToVm returned with error: " << prl_result_to_string(err) << std::endl;
        PrlHandle_Free(hJob);
        return err;
    }

    err = PrlJob_GetRetCode(hJob, &nJobReturnCode);

    if (PRL_FAILED(err))
    {
        std::cout << "PrlJob_GetRetCode returned with error: " << prl_result_to_string(err) << std::endl;
        PrlHandle_Free(hJob);
        return err;
    }

    if (PRL_FAILED(nJobReturnCode))
    {
        std::cout << "PrlDevDisplay_ConnectToVm returned with error: " << prl_result_to_string(nJobReturnCode) << std::endl;
        PrlHandle_Free(hJob);
        return nJobReturnCode;
    }

    return PRL_ERR_SUCCESS;
}

PRL_RESULT PrlType::DisconnectFromConsole(PRL_HANDLE vm)
{
    std::this_thread::sleep_for(100ms);
    PRL_RESULT err = PrlDevDisplay_DisconnectFromVm(vm);

    if (PRL_FAILED(err))
        std::cout << "PrlDevDisplay_DisconnectFromVm returned with error: " << prl_result_to_string(err) << std::endl;

    PrlHandle_Free(hVm);
    return err;
}
