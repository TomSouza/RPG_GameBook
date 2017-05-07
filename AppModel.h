#pragma once
#include <string>
#include <iostream>
#include <fstream>

#include "Player.h"

using namespace std;

class AppModel
{
public:
    AppModel();
    ~AppModel();

    void save(const char* file);
    void saveBinary(const char* file);

    void load(const char* file);
    void loadBinary(const char* file);

    static Player* player;
    static int saveSlot;

private:
    int maxSaves = 3;
};

