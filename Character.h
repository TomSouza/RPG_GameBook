#pragma once
#include "Inventory.h"
#include <time.h>

/// <summary>
/// Classe base para implementação de personagens
/// </summary>
class Character
{
protected:
    //Attributes
    int strength = 0, ability = 0, endurance = 0, armor = 0, fire_power = 0;
    // Combat
    int AP = 0, DP = 0;
    int hp = 0, mp = 0;

    int experience = 0;

    string name;

public:
    Character();
    ~Character();

    Inventory *inventory = NULL;

    /// <summary>
    /// Calcula o dano que o personagem causara
    /// </summary>
    virtual int attack() = 0;

    /// <summary>
    /// Defende de um golpe
    /// </summary>
    /// <param name="damage"> Quantia de dano recebido </param>
    virtual void defend(int damage) = 0;

    /// <summary>
    /// Define o nome do personagem
    /// </summary>
    /// <param name="value"> Nome </param>
    void setName(string value);

    /// <summary>
    /// Busca nome do personagem
    /// </summary>
    string getName();

    /// <summary>
    /// Define a força do personagem
    /// </summary>
    /// <param name="value"> Força </param>
    void setStrength(int value);

    /// <summary>
    /// Busca força do personagem
    /// </summary>
    int getStrength();

    /// <summary>
    /// Define a habilidade do personagem
    /// </summary>
    /// <param name="value"> Habilidade </param>
    void setAbility(int value);

    /// <summary>
    /// Busca habilidade do personagem
    /// </summary>
    int getAbility();

    /// <summary>
    /// Define a resistencia do personagem
    /// </summary>
    /// <param name="value"> Resistencia </param>
    void setEndurance(int value);

    /// <summary>
    /// Busca resistencia do personagem
    /// </summary>
    int getEndurance();

    /// <summary>
    /// Define o nivel de armadura do personagem
    /// </summary>
    /// <param name="value"> Armadura </param>
    void setArmor(int value);

    /// <summary>
    /// Busca pontos de armadura do personagem
    /// </summary>
    int getArmor();

    /// <summary>
    /// Define o poder de fogo do personagem
    /// </summary>
    /// <param name="value"> Poder de Fogo </param>
    void setFirePower(int value);

    /// <summary>
    /// Busca poder de fogo do personagem
    /// </summary>
    int getFirePower();

    /// <summary>
    /// Atribui experiencia ao personagem
    /// </summary>
    /// <param name="value"> Experiencia </param>
    void setExperience(int value);

    /// <summary>
    /// Busca experiencia do personagem
    /// </summary>
    int getExperience();

    /// <summary>
    /// Define a saude do personagem
    /// </summary>
    /// <param name="value"> Saude </param>
    void setHp(int value);

    /// <summary>
    /// Busca saude do personagem
    /// </summary>
    int getHp();

    /// <summary>
    /// Define os pontos de mana do personagem
    /// </summary>
    /// <param name="value"> Mana </param>
    void setMp(int value);

    /// <summary>
    /// Busca pontos de mana do personagem
    /// </summary>
    int getMp();

    /// <summary>
    /// Busca poder de ataque do personagem
    /// </summary>
    int getAP();

    /// <summary>
    /// Busca poder de defesa do personagem
    /// </summary>
    int getDP();
};

