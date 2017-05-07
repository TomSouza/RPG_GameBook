#include "PauseMenu.h"

PauseMenu::PauseMenu()
{
    gRecursos.carregarSpriteSheet("gameInput", "assets/icons/nameInput.png");
    nameinput.setSpriteSheet("gameInput");

    gRecursos.carregarFonte("gameFont", "assets/fonts/vineritc.ttf", 24);
    playerName.setFonte("gameFont");
    playerName.setString("");
    playerName.setCor(0, 0, 0, 255, true);

    nameLabel.setFonte("gameFont");
    nameLabel.setString("Nome: ");
    nameLabel.setCor(0, 0, 0, 255, true);

    remainingPoints.setFonte("gameFont");
    remainingPoints.setCor(0, 0, 0, 255, true);

    gRecursos.carregarSpriteSheet("background", "assets/bg/pause_menu.png");
    background.setSpriteSheet("background");

    gRecursos.carregarSpriteSheet("save", "assets/buttons/newData.png", 3, 1);
    gRecursos.carregarSpriteSheet("load", "assets/buttons/loadData.png", 3, 1);

    int pos = -100;

    for (int i = 0; i < 3; i++) {
        saveLoad[i].setSpriteSheet("save");

        saveLoad[i].setPos(
            gJanela.getLargura() / 2,
            gJanela.getAltura() / 2 + pos
        );

        pos += 100;
    }

    gRecursos.carregarSpriteSheet("plus", "assets/buttons/plus.png", 3, 1);
    gRecursos.carregarSpriteSheet("minus", "assets/buttons/minus.png", 3, 1);

    pos = -100;

    for (int i = 0; i < 5; i++) {
        plus[i].setSpriteSheet("plus");
        minus[i].setSpriteSheet("minus");

        plus[i].setPos(
            gJanela.getLargura() / 2 + 100,
            gJanela.getAltura() / 2 + pos
        );

        minus[i].setPos(
            gJanela.getLargura() / 2 + 125,
            gJanela.getAltura() / 2 + pos
        );

        attributesLabel[i].setFonte("gameFont");
        attributesLabel[i].setEscala(0.8f, 0.8f);
        attributesLabel[i].setCor(0, 0, 0, 255, true);

        pos += 40;
    }

    gRecursos.carregarSpriteSheet("confirm", "assets/buttons/confirm.png", 3, 1);
    confirm.setSpriteSheet("confirm");

    confirm.setPos(
        gJanela.getLargura() / 2 + 230,
        gJanela.getAltura() / 2 + 160
    );
}

PauseMenu::~PauseMenu()
{
}

void PauseMenu::start()
{
}

void PauseMenu::finish()
{
}

Scenes PauseMenu::update()
{
    if (*player == NULL) {
        actualScreen = DATA_MANAGER;
    }

    draw();

    switch (actualScreen)
    {
    case DATA_MANAGER:
        dataManager();
        break;
    case STATUS:
        status();
        break;
    case INVENTORY:
        inventory();
        break;
    default:
        break;
    }

    return sceneChange;
}

void PauseMenu::draw()
{
    background.desenhar(
        gJanela.getLargura() / 2,
        gJanela.getAltura() / 2
    );
}

void PauseMenu::inventory()
{
}

void PauseMenu::status()
{
    if (newGame) {
        inputUpdate();
    }
    inputDraw();

    showAttributes();

    if (
        !player[0]->getPointsToUse() &&
        playerName.getString().size() > 0 &&
        newGame
    ) {
        confirm.atualizar();

        if (confirm.estaClicado()) {
            createNewGame();
        }

        confirm.desenhar();
    }
}

void PauseMenu::dataManager()
{
    for (int i = 0; i < 3; i++) {
        saveLoad[i].atualizar();

        if (saveLoad[i].estaClicado()) {
            *player = new Player;
            AppModel::saveSlot = i;
            newGame = true;
            actualScreen = STATUS;
        }

        saveLoad[i].desenhar();
    }
}

void PauseMenu::createNewGame()
{
    player[0]->create();
    model.saveBinary("saveData.bee");
}

void PauseMenu::inputUpdate()
{
    if (!gTeclado.inputTexto.estaHabilitado()) {
        gTeclado.inputTexto.habilitar();
    }

    if (gTeclado.pressionou[TECLA_VOLTAR]) {
        gTeclado.inputTexto.apagar();
    }

    if (gTeclado.pressionou[TECLA_DELETE]) {
        if (gTeclado.inputTexto.getTamanhoSelecao() != 0) {
            gTeclado.inputTexto.apagar();
        }
        else if (gTeclado.inputTexto.getPosCursor() < gTeclado.inputTexto.getString().size())
        {
            gTeclado.inputTexto.moverPosCursorParaDir();
            gTeclado.inputTexto.apagar();
        }
    }

    if (gTeclado.segurando[TECLA_SHIFT_ESQ]) {
        if (gTeclado.pressionou[TECLA_ESQ]) {
            gTeclado.inputTexto.moverSelecaoParaEsq();
        }
        if (gTeclado.pressionou[TECLA_DIR]) {
            gTeclado.inputTexto.moverSelecaoParaDir();
        }
        if (gTeclado.pressionou[TECLA_HOME]) {
            gTeclado.inputTexto.moverSelecaoParaInicio();
        }
        if (gTeclado.pressionou[TECLA_END]) {
            gTeclado.inputTexto.moverSelecaoParaFim();
        }
    }
    else
    {
        if (gTeclado.pressionou[TECLA_ESQ]) {
            gTeclado.inputTexto.moverPosCursorParaEsq();
        }
        if (gTeclado.pressionou[TECLA_DIR]) {
            gTeclado.inputTexto.moverPosCursorParaDir();
        }
        if (gTeclado.pressionou[TECLA_HOME]) {
            gTeclado.inputTexto.moverPosCursorParaInicio();
        }
        if (gTeclado.pressionou[TECLA_END]) {
            gTeclado.inputTexto.moverPosCursorParaFim();
        }
    }

    if (gTeclado.inputTexto.getString().size() <= player[0]->maxNameSize) {
        playerName.setString(gTeclado.inputTexto.getString());
    }
}

void PauseMenu::inputDraw()
{
    int xReducer = 50;
    int yReducer = 150;

    nameLabel.desenhar(
        gJanela.getLargura() / 2 - 235,
        gJanela.getAltura() / 2 - yReducer
    );

    nameinput.desenhar(
        gJanela.getLargura() / 2 - xReducer,
        gJanela.getAltura() / 2 - yReducer
    );

    playerName.desenhar(
        gJanela.getLargura() / 2 - xReducer,
        gJanela.getAltura() / 2 - yReducer
    );

    if (newGame) {

        int altCursor = playerName.getFonte()->getAlturaGlifos();
        int xCursor = (gJanela.getLargura() / 2 - xReducer) - playerName.getLargura() / 2;
        int yCursor = (gJanela.getAltura() / 2 - yReducer) - altCursor / 2;
        int pos = gTeclado.inputTexto.getPosCursor();

        for (int i = 0; i < pos; ++i) {
            if (pos >= player[0]->maxNameSize) {
                break;
            }
            xCursor += playerName.getLetra(i)->glifo->avanco*playerName.getEscalaX();
        }
    
        gGraficos.desenharLinha(xCursor, yCursor, xCursor, yCursor + altCursor, 0, 0, 0);
    }
}

void PauseMenu::showAttributes()
{
    int pos = -100;

    remainingPoints.setString(
        "Pontos: " + to_string(player[0]->getPointsToUse())
    );
    remainingPoints.desenhar(
        gJanela.getLargura() / 2 + 210,
        gJanela.getAltura() / 2 - 150
    );

    for (int i = 0; i < 5; i++) {

        if (player[0]->getPointsToUse() > 0) {
            plus[i].atualizar();
        }
        minus[i].atualizar();

        checkAttributesButtons(i);

        setAttributesLabel(i);
        attributesLabel[i].desenhar(
            gJanela.getLargura() / 2 - 150,
            gJanela.getAltura() / 2 + pos
        );

        if (player[0]->getPointsToUse() > 0) {
            plus[i].desenhar();
        }

        minus[i].desenhar();

        pos += 40;
    }
}

void PauseMenu::setAttributesLabel(int position)
{
    string label = "";

    switch (position) {
    case 0:
        label = "Força: " + to_string(player[0]->getStrength());
        break;
    case 1:
        label = "Habilidade: " + to_string(player[0]->getAbility());
        break;
    case 2:
        label = "Resistencia: " + to_string(player[0]->getEndurance());
        break;
    case 3:
        label = "Armadura: " + to_string(player[0]->getArmor());
        break;
    case 4:
        label = "Poder de Fogo: " + to_string(player[0]->getFirePower());
        break;
    }

    attributesLabel[position].setString(label);
}

void PauseMenu::checkAttributesButtons(int position)
{
    int new_value = 0;

    if (plus[position].estaClicado() && player[0]->getPointsToUse() > 0) {
        new_value = 1;
    }
    else if (minus[position].estaClicado() && newGame) {
        new_value = -1;
    }

    if (new_value != 0) {
        switch (position) {
        case 0:
            player[0]->setStrength(
                new_value + player[0]->getStrength()
            );
            break;
        case 1:
            player[0]->setAbility(
                new_value + player[0]->getAbility()
            );
            break;
        case 2:
            player[0]->setEndurance(
                new_value + player[0]->getEndurance()
            );
            break;
        case 3:
            player[0]->setArmor(
                new_value + player[0]->getArmor()
            );
            break;
        case 4:
            player[0]->setFirePower(
                new_value + player[0]->getFirePower()
            );
            break;
        }
    }    
}
