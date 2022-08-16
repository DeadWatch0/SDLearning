
#include <SDL2\SDL.h>
#include <SDL2\SDL_image.h>
#include <stdio.h>
#include <string>

#ifndef START_FUNCTIONS_HPP
#define START_FUNCTIONS_HPP

using namespace std;

// define window properties
const int SCREEN_WIDTH = 640;
const int SCREEN_HEIGHT = 480;

enum KeyPressSurfaces
{
    KEY_PRESS_SURFACE_DEFAULT,
    KEY_PRESS_SURFACE_UP,
    KEY_PRESS_SURFACE_DOWN,
    KEY_PRESS_SURFACE_LEFT,
    KEY_PRESS_SURFACE_RIGHT,
    KEY_PRESS_SURFACE_TOTAL
};

SDL_Window *gWindow = NULL;

SDL_Surface *gScreenSurface = NULL;

SDL_Surface *gLoadSurface(std::string path);

SDL_Surface *gKeyPressSurfaces[KEY_PRESS_SURFACE_TOTAL];

SDL_Surface *gCurrentSurface = NULL;

bool init();

bool loadMedia();

void close();

// support funcrtions

// Initialization video
bool init()
{
    bool success = true;

    if (SDL_Init(SDL_INIT_VIDEO) < 0)
    {
        printf("SDL could not initialize! SDL_Error: %s\n", SDL_GetError());
        success = false;
    }
    else
    {
        if (IMG_Init(IMG_INIT_JPG) < 0)
        {
            printf("SDL could not initialize! SDL_Error: %s\n", SDL_GetError());
            success = false;
        }
        else
        {
            gWindow = SDL_CreateWindow("SDL Tutorial", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, SCREEN_WIDTH, SCREEN_HEIGHT, SDL_WINDOW_SHOWN);
            if (gWindow == NULL)
            {
                printf("Window could not be created! SDL_Error: %s\n", SDL_GetError());
                success = false;
            }
            else
            {
                gScreenSurface = SDL_GetWindowSurface(gWindow);
            }
        }
    }

    return success;
}

SDL_Surface *gLoadSurface(std::string path)
{
    SDL_Surface *loadedSurface = IMG_Load(path.c_str());

    if (loadedSurface == NULL)
    {
        printf("Unable to load image %s! SDL Error: %s\n", loadedSurface, SDL_GetError());
    }

    return loadedSurface;
}

bool loadMedia()
{
    bool success = true;

    gKeyPressSurfaces[KEY_PRESS_SURFACE_DEFAULT] = gLoadSurface("quiting.jpg");
    if (gKeyPressSurfaces[KEY_PRESS_SURFACE_DEFAULT] == NULL)
    {
        printf("Failed to load default image!\n");
        success = false;
    }

    gKeyPressSurfaces[KEY_PRESS_SURFACE_UP] = gLoadSurface("personUP.png");
    if (gKeyPressSurfaces[KEY_PRESS_SURFACE_UP] == NULL)
    {
        printf("Failed to load up image!\n");
        success = false;
    }

    gKeyPressSurfaces[KEY_PRESS_SURFACE_DOWN] = gLoadSurface("personDOWN.png");
    if (gKeyPressSurfaces[KEY_PRESS_SURFACE_DOWN] == NULL)
    {
        printf("Failed to load down image!\n");
        success = false;
    }

    gKeyPressSurfaces[KEY_PRESS_SURFACE_LEFT] = gLoadSurface("personLEFT.png");
    if (gKeyPressSurfaces[KEY_PRESS_SURFACE_LEFT] == NULL)
    {
        printf("Failed to load left image!\n");
        success = false;
    }

    gKeyPressSurfaces[KEY_PRESS_SURFACE_RIGHT] = gLoadSurface("personRIGHT.png");
    if (gKeyPressSurfaces[KEY_PRESS_SURFACE_RIGHT] == NULL)
    {
        printf("Failed to load right image!\n");
        success = false;
    }

    return success;
}

// Closing function
void close()
{
    SDL_DestroyWindow(gWindow);
    gWindow = NULL;

    IMG_Quit();
    SDL_Quit();
}

#endif