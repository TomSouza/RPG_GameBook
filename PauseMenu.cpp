#include "PauseMenu.h"

PauseMenu::PauseMenu()
{
    gRecursos.carregarSpriteSheet("background", "assets/bg/pause_menu.png");
    background.setSpriteSheet("background");

    gRecursos.carregarSpriteSheet("inventory", "assets/bg/inventorySlots.png");
    inventorySlots.setSpriteSheet("inventory");

    gRecursos.carregarSpriteSheet("equipaments", "assets/bg/equipableSlots.png");
    equipableSlots.setSpriteSheet("equipaments");

    initStatusResources();

    gRecursos.carregarSpriteSheet("save", "assets/buttons/newData.png", 3, 1);
    gRecursos.carregarSpriteSheet("load", "assets/buttons/loadData.png", 3, 1);

    gRecursos.carregarSpriteSheet("tabs", "assets/buttons/option.png", 3, 1);

    playerHealth.setFonte("gameFont");
    playerHealth.setCor(0, 0, 0, 255, true);

    saveActual.button.setSpriteSheet("load");
    saveActual.button.setPos(
        gJanela.getLargura() / 2,
        gJanela.getAltura() / 2 - 50
    );
    saveActual.label.setFonte("gameFont");
    saveActual.label.setCor(0, 0, 0, 255, true);
    saveActual.label.setString("Salvar");

    mainMenu.button.setSpriteSheet("load");
    mainMenu.button.setPos(
        gJanela.getLargura() / 2,
        gJanela.getAltura() / 2 + 50

    );
    mainMenu.label.setFonte("gameFont");
    mainMenu.label.setCor(0, 0, 0, 255, true);
    mainMenu.label.setString("Menu Inicial");

    int tabPosX = -230;

    for (int i = 0; i < 3; i++) {

        tabs[i].setSpriteSheet("tabs");
        tabs[i].setPos(
            gJanela.getLargura() / 2 + tabPosX,
            gJanela.getAltura() / 2 - 200
        );

        tabsLabel[i].setFonte("gameFont");
        tabsLabel[i].setCor(0, 0, 0, 255, true);
        if (i == 0) {
            tabsLabel[i].setString("Status");
        }
        else if (i == 1) {
            tabsLabel[i].setString("Itens");
        }
        else {
            tabsLabel[i].setString("Save");
        }

        tabPosX += 110;
    }
}

PauseMenu::~PauseMenu()
{
}

void PauseMenu::start()
{
    sceneChange = KEEP;
    started = true;
    checkSaves();
}

void PauseMenu::finish()
{
    sceneChange = KEEP;
    started = false;
}

Scenes PauseMenu::update()
{
    if (*player == NULL) {
        actualScreen = DATA_MANAGER;
    }

    draw();

    if (inGame) {
        drawTabs();
    }

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

void PauseMenu::setNewGame(bool value)
{
    newGame = value;
}

void PauseMenu::setInGame(bool value)
{
    inGame = value;
}

void PauseMenu::setState(Screens state)
{
    actualScreen = state;
}

void PauseMenu::draw()
{
    background.desenhar(
        gJanela.getLargura() / 2,
        gJanela.getAltura() / 2
    );
}

void PauseMenu::initStatusResources()
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

    gRecursos.carregarSpriteSheet("plus", "assets/buttons/plus.png", 3, 1);
    gRecursos.carregarSpriteSheet("minus", "assets/buttons/minus.png", 3, 1);

    int pos = -100;

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

    gRecursos.carregarSpriteSheet("warrior", "assets/buttons/warrior_class.png", 3, 1);
    warrior.setSpriteSheet("warrior");

    gRecursos.carregarSpriteSheet("mage", "assets/buttons/mage_class.png", 3, 1);
    mage.setSpriteSheet("mage");

    gRecursos.carregarSpriteSheet("rogue", "assets/buttons/rogue_class.png", 3, 1);
    rogue.setSpriteSheet("rogue");

    gRecursos.carregarSpriteSheet("confirm", "assets/buttons/confirm.png", 3, 1);
    confirm.setSpriteSheet("confirm");

    warrior.setPos(
        gJanela.getLargura() / 2 -100,
        gJanela.getAltura() / 2 + 140
    );

    mage.setPos(
        gJanela.getLargura() / 2,
        gJanela.getAltura() / 2 + 140
    );

    rogue.setPos(
        gJanela.getLargura() / 2 + 100,
        gJanela.getAltura() / 2 + 140
    );

    confirm.setPos(
        gJanela.getLargura() / 2 + 230,
        gJanela.getAltura() / 2 + 160
    );
}

void PauseMenu::inventory()
{

    equipableSlots.desenhar(
        gJanela.getLargura() / 2 - 150,
        gJanela.getAltura() / 2
    );

    inventorySlots.desenhar(
        gJanela.getLargura() / 2 + 120,
        gJanela.getAltura() / 2
    );

    AppModel::player->inventory->showItens();
}

void PauseMenu::status()
{
    inputUpdate();
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
    if (inGame) {
        saveActual.button.atualizar();

        if (saveActual.button.estaClicado() == true) {
            model.saveBinary();
        }

        saveActual.button.desenhar();
        saveActual.label.desenhar(
            saveActual.button.getX(),
            saveActual.button.getY()
        );

        mainMenu.button.atualizar();

        if (mainMenu.button.estaClicado() == true) {
            sceneChange = MAIN_MENU;
        }

        mainMenu.button.desenhar();
        mainMenu.label.desenhar(
            mainMenu.button.getX(),
            mainMenu.button.getY()
        );

        return;
    }

    for (int i = 0; i < 3; i++) {
        saveLoad[i].atualizar();

        if (
            saveLoad[i].estaClicado() &&
            AppModel::slots[i].empty &&
            newGame
        ) {
            *player = new Player;
            AppModel::saveSlot = i;
            actualScreen = STATUS;
        }
        else if (
            saveLoad[i].estaClicado() &&
            !AppModel::slots[i].empty &&
            !newGame && !inGame
        ) {
            AppModel::saveSlot = i;
            model.loadBinary();
            sceneChange = NARRATIVE;
        }

        saveLoad[i].desenhar();

        if (loadName[i].getString().size()) {
            loadName[i].desenhar(saveLoad[i].getX(), saveLoad[i].getY());
        }
    }
}

void PauseMenu::checkSaves()
{
    int pos = -100;

    for (int i = 0; i < 3; i++) {

        if (AppModel::slots[i].empty) {
            saveLoad[i].setSpriteSheet("save");
        }
        else {
            saveLoad[i].setSpriteSheet("load");

            loadName[i].setFonte("gameFont");
            loadName[i].setCor(0, 0, 0, 255, true);
            loadName[i].setString(AppModel::slots[i].name);
        }

        saveLoad[i].setPos(
            gJanela.getLargura() / 2,
            gJanela.getAltura() / 2 + pos
        );

        pos += 100;
    }
}

void PauseMenu::createNewGame()
{
    player[0]->setName(playerName.getString());
    player[0]->create();

    switch (player[0]->playerClass)
    {
    case WARRIOR:
        player[0]->inventory->pickUp(AppModel::itens[SWORD]);
        break;
    default:
        break;
    }

    AppModel::scene[0] = 1;
    AppModel::scene[1] = 1;

    model.saveBinary();

    sceneChange = NARRATIVE;
}

void PauseMenu::inputUpdate()
{
    if (!newGame) {
        playerName.setString(player[0]->getName());
        return;
    }

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

    if (newGame || player[0]->getPointsToUse() > 0) {
        remainingPoints.setString(
            "Pontos: " + to_string(player[0]->getPointsToUse())
        );
        remainingPoints.desenhar(
            gJanela.getLargura() / 2 + 210,
            gJanela.getAltura() / 2 - 150
        );
    }

    for (int i = 0; i < 5; i++) {

        if (newGame || player[0]->getPointsToUse() > 0) {
            if (player[0]->getPointsToUse() > 0) {
                plus[i].atualizar();
            }
            minus[i].atualizar();
        }       

        checkAttributesButtons(i);

        setAttributesLabel(i);
        attributesLabel[i].desenhar(
            gJanela.getLargura() / 2 - 150,
            gJanela.getAltura() / 2 + pos
        );

        if (newGame || player[0]->getPointsToUse() > 0) {
            if (player[0]->getPointsToUse() > 0) {
                plus[i].desenhar();
            }

            minus[i].desenhar();
        }

        pos += 40;
    }

    if (newGame) {
        warrior.atualizar();
        mage.atualizar();
        rogue.atualizar();

        if (warrior.estaClicado()) {
            player[0]->playerClass = WARRIOR;
        }
        else if (mage.estaClicado()) {
            player[0]->playerClass = MAGE;
        }
        else if (rogue.estaClicado()) {
            player[0]->playerClass = ROGUE;
        }
    }

    warrior.setAnimacaoDoEstadoNormal(0);
    mage.setAnimacaoDoEstadoNormal(0);
    rogue.setAnimacaoDoEstadoNormal(0);

    switch (player[0]->playerClass)
    {
    case WARRIOR:
        warrior.setAnimacaoDoEstadoNormal(1);

        warrior.desenhar();
        if (newGame) {
            mage.desenhar();
            rogue.desenhar();
        }
        break;
    case MAGE:
        mage.setAnimacaoDoEstadoNormal(1);

        mage.desenhar();
        if (newGame) {
            warrior.desenhar();
            rogue.desenhar();
        }
        break;
    case ROGUE:
        rogue.setAnimacaoDoEstadoNormal(1);

        rogue.desenhar();
        if (newGame) {
            warrior.desenhar();
            mage.desenhar();
        }
        break;
    default:
        break;
    }

    if (inGame) {
        playerHealth.setString("HP : " + to_string(player[0]->getHp()));
        playerHealth.desenhar(
            gJanela.getLargura() / 2 + 200,
            gJanela.getAltura() / 2 - 100
        );
    }
}

void PauseMenu::setAttributesLabel(int position)
{
    string label = "";

    switch (position) {
    case 0:
        label = "Força: " + to_string(player[0]->getStrength());

        if (player[0]->playerClass == WARRIOR) {
            label += " + 2";
        }

        break;
    case 1:
        label = "Habilidade: " + to_string(player[0]->getAbility());

        if (player[0]->playerClass == MAGE) {
            label += " + 2";
        } else if (player[0]->playerClass == ROGUE) {
            label += " + 3";
        }

        break;
    case 2:
        label = "Resistencia: " + to_string(player[0]->getEndurance());
        break;
    case 3:
        label = "Armadura: " + to_string(player[0]->getArmor());

        if (player[0]->playerClass == WARRIOR) {
            label += " + 2";
        }

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

void PauseMenu::drawTabs()
{
    for (int i = 0; i < 3; i++)
    {
        tabs[i].atualizar();

        if (tabs[i].estaClicado() == true) {
            switch (i)
            {
            case 0:
                actualScreen = STATUS;
                break;
            case 1:
                actualScreen = INVENTORY;
                break;
            case 2:
                actualScreen = DATA_MANAGER;
            default:
                break;
            }
        }

        tabs[i].desenhar();
        tabsLabel[i].desenhar(
            tabs[i].getX(),
            tabs[i].getY()
        );
    }
}
