#pragma once
#include "Character.h"

/// <summary>
/// Enumerador de possiveis classes para o jogador:
/// </summary>
enum Class {
    WARRIOR,
    MAGE,
    ROGUE
};

/// <summary>
/// Classe responsavel por a��es de jogador.
/// </summary>
class Player : public Character
{
public:
    Player();
    ~Player();

    /// </inheritdoc>
    int attack();

    /// </inheritdoc>
    void defend(int damage);

    /// <summary>
    /// Busca pontos disponiveis para distribuir nos atributos
    /// </summary>
    int getUsablePoints();

    /// <summary>
    /// <para>Inicia dados calculados do jogador ap�s sua cria��o</para>
    /// <para>Inclui sorte randomica e bonus de atributo por classe</para>
    /// </summary>
    void create();

    void setName(string value);
    string getName();

    void setTempDefence(int value);

    int getPointsToUse();

    void setLuck(int value = 0);
    int getLuck();

    int maxNameSize = 20;
    Class playerClass = WARRIOR;
private:
    int pointsToUse = 12;
    int tempDefence = 0;

    int luck = 0;

    string* name;
};