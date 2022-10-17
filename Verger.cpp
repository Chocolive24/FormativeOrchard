#include <iostream>

#include "models/audioManager/AudioManager.h"
#include "models/game/Game.h"

int main()
{
    AudioManager::Play("assets/music/main_theme.wav", true);

    Game game;

    game.PlayGame();
}