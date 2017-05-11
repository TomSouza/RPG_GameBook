#pragma once
#include <string>
#include <iostream>
#include <fstream>

#include "Player.h"

using namespace std;

struct saveSlots {
    int slot;
    bool empty;
    string name;
};

class AppModel
{
public:
    AppModel();
    ~AppModel();

    void save(const char* file);
    void saveBinary(const char* file);

    void load(const char* file);
    void loadBinary(const char* file);

    void checkSlots();

    static Player* player;
    static saveSlots slots[3];
    static int saveSlot;

private:
    int maxSaves = 3;
    int slotBites = 56;

    void savePlayer(ofstream& save);
    void loadPlayer(ifstream& load);

    void insertString(ofstream& streamer, string value, int size);
    void insertInteger(ofstream& streamer, int value);
    void insertClass(ofstream& streamer, Class value);

    string fillBlankSpaces(string, int);
};