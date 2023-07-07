#include "../include/renderEngine.h"

#include <SDL2/SDL.h>
#include <SDL2/SDL_render.h>
#include <SDL2/SDL_surface.h>
#include <SDL2/SDL_video.h>
#include <string.h>

#include <cstddef>
#include <cstdint>
#include <cstring>
#include <iostream>
#include <string>

SDL_Texture* playerTexture;
SDL_Rect srcR, destR;

SDL_Renderer* renderEngine::renderer = nullptr;

renderEngine::renderEngine() {}
renderEngine::~renderEngine() {}

// Simulation Output
SDL_Rect srcRect, destRect;
SDL_Texture* tex;
SDL_Surface* surface;

void renderEngine::Initialise(const char* title, int xpos, int ypos, int w,
                              int h, bool fullscreen) {
  int flags = 0;
  if (fullscreen) {
    flags = SDL_WINDOW_FULLSCREEN;
  }
  if (SDL_Init(SDL_INIT_EVERYTHING) == 0) {
    std::cout << "SDL Initialised!" << std::endl;

    window = SDL_CreateWindow(title, xpos, ypos, w, h, flags);
    if (window) {
      std::cout << "Window instantiated!" << std::endl;
    }
    renderer = SDL_CreateRenderer(window, -1, 0);
    if (renderer) {
      SDL_SetRenderDrawColor(renderer, 255, 0, 255, 255);
      std::cout << "Renderer instantiated!" << std::endl;
    }
    isRunning = true;
  } else {
    isRunning = false;
  }

  // Simulation Output
  // SDL_Surface* tmp_surface = IMG_Load("../player.png");
  // tex = SDL_CreateTextureFromSurface(renderer, tmp_surface);
  // SDL_FreeSurface(tmp_surface);
  int img_width = 32;
  int img_height = 32;
  int channels = 3;  // for a RGB image
  char* pixels = new char[img_width * img_height * channels];

  for (int x = 0; x < img_width; x++) {
    for (int y = 0; y < img_width; y++) {
      if ((x + y) % 2 == 0) {
        pixels[x + (y * img_width)] = 0b11111000;
      } else {
        pixels[x + (y * img_width)] = 0b11111000;
      }
    }
  }

  surface = SDL_CreateRGBSurfaceFrom((void*)pixels, img_width, img_height,
                                     channels * 8,  // bits per pixel = 24
                                     img_width * channels,  // pitch
                                     0x0000FF,              // red mask
                                     0x00FF00,              // green mask
                                     0xFF0000,              // blue mask
                                     0);                    // alpha mask (none)

  tex = SDL_CreateTextureFromSurface(renderer, surface);
  SDL_FreeSurface(surface);

  srcRect.h = 32;
  srcRect.w = 32;
  srcRect.x = 0;
  srcRect.y = 0;

  destRect.x = 0;
  destRect.y = 0;
  destRect.w = 800;
  destRect.h = 640;
}

void renderEngine::Events() {
  SDL_Event event;
  SDL_PollEvent(&event);
  switch (event.type) {
    case SDL_QUIT:
      isRunning = false;
      break;
    default:
      break;
  }
}

void renderEngine::Update() {
  tick++;
  // std::cout << tick << std::endl;
}

void renderEngine::Render() {
  SDL_RenderClear(renderer);
  SDL_RenderCopy(renderer, tex, &srcRect, &destRect);
  SDL_RenderPresent(renderer);
}

void renderEngine::Clean() {
  SDL_DestroyWindow(window);
  SDL_DestroyRenderer(renderer);
  SDL_Quit();
  std::cout << "Engine Cleaned!" << std::endl;
}