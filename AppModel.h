#pragma once
#include <string>
#include <vector>
#include <sstream>
#include <utility>

#include <iostream>
#include <fstream>

#include "Player.h"
#include "Enemy.h"

using namespace std;

const string gameData = "saveData.bee";
const string stageData = "stages.txt";
const string itemData = "itens.txt";

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
    char type;
    string description;
    option options[3];
    Enemy* enemy = NULL;
    Item* item = NULL;
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
    static Item* itens;
    static saveSlots slots[3];
    static stageInfo* stages;
    static int saveSlot;
    static int stageVectorSize;
    static int scene[2];

private:
    int maxSaves = 3;
    int slotBites = 64;

    void savePlayer(ofstream& save);
    void loadPlayer(ifstream& load);

    void insertString(ofstream& streamer, string value, int size);
    void insertInteger(ofstream& streamer, int value);
    void insertClass(ofstream& streamer, Class value);

    string fillBlankSpaces(string, int);
};