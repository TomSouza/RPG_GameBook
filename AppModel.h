#pragma once
#include <string>
#include <vector>
#include <sstream>
#include <utility>

#include <iostream>
#include <fstream>

#include "Player.h"

using namespace std;

const string gameData = "saveData.bee";
const string stageData = "stages.txt";

struct saveSlots {
    int slot;
    bool empty;
    string name;
};

struct option {
    int value;
    string description;
};

struct stageInfo {
    int nivel;
    int ident;
    string description;
    option options[3];
};

class AppModel
{
public:
    AppModel();
    ~AppModel();

    void save(const char* file);
    void saveBinary();

    void load();
    void loadBinary();

    void checkSlots();

    static Player* player;
    static saveSlots slots[3];
    static stageInfo* stages;
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