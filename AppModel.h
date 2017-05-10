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

    void savePlayer(ofstream& save);

    void insertString(ofstream& streamer, string value, int size);
    void insertInteger(ofstream& streamer, int value);
    void insertClass(ofstream& streamer, Class value);

    string fillBlankSpaces(string, int);
};