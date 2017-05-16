#pragma once
#include "Character.h"

/// <summary>
/// Classe responsavel por a��es de inimigos.
/// </summary>
class Enemy : public Character
{
private:

public:
    Enemy();
    ~Enemy();

    /// </inheritdoc>
    int attack();

    /// </inheritdoc>
    void defend(int damage);

    /// <summary>
    /// Inicia dados calculados do inimigo ap�s seu carregamento
    /// </summary>
    void create();
};

