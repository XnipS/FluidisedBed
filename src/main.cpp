#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include <SDL2/SDL_rect.h>
#include <SDL2/SDL_render.h>
#include <SDL2/SDL_timer.h>

#include <cstdio>
#include <iostream>

#include "../include/core.h"
#include "../include/renderEngine.h"

renderEngine* renderer = nullptr;
Uint32 frameStart;
int currentTickTime;

int main(int argc, char* args[]) {
  renderer = new renderEngine();

  renderer->Initialise("Fluidised Bed Engine", 0, 0, 800, 640, false);

  while (renderer->Running()) {
    frameStart = SDL_GetTicks();
    renderer->Events();
    renderer->Update();
    renderer->Render();

    currentTickTime = SDL_GetTicks() - frameStart;
    if (RE_TICKRATE_TIME > currentTickTime) {
      SDL_Delay(RE_TICKRATE_TIME - currentTickTime);
    } else {
      std::cout << "Tickrate lagging: ";
      std::cout << (currentTickTime - RE_TICKRATE_TIME);
      std::cout << "ms behind!" << std::endl;
    }
  }

  renderer->Clean();
  return 0;
}