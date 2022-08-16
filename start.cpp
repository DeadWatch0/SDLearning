#include "start_functions.hpp"

int main(int argc, char *args[])
{
    bool quit = false;

    SDL_Event event;

    gCurrentSurface = gKeyPressSurfaces[KEY_PRESS_SURFACE_DEFAULT];

    if (!init())
    {
        printf("Failed to initialize!\n");
    }

    else
    {
        if (!loadMedia())
        {
            printf("Failed to load media!\n");
        }
        else
        {
            SDL_BlitSurface(gLoadSurface("brik.jpg"), NULL, gScreenSurface, NULL);
            SDL_UpdateWindowSurface(gWindow);

            while (!quit)
            {
                while (SDL_PollEvent(&event) != 0)
                {
                    // User requests quit
                    if (event.type == SDL_QUIT)
                    {
                        quit = true;
                    }

                    else if (event.type == SDL_KEYDOWN)
                    {
                        switch (event.key.keysym.sym)
                        {
                        case SDLK_UP:
                            gCurrentSurface = gKeyPressSurfaces[KEY_PRESS_SURFACE_UP];
                            break;

                        case SDLK_DOWN:
                            gCurrentSurface = gKeyPressSurfaces[KEY_PRESS_SURFACE_DOWN];
                            break;

                        case SDLK_LEFT:
                            gCurrentSurface = gKeyPressSurfaces[KEY_PRESS_SURFACE_LEFT];
                            break;

                        case SDLK_RIGHT:
                            gCurrentSurface = gKeyPressSurfaces[KEY_PRESS_SURFACE_RIGHT];
                            break;

                        case SDLK_ESCAPE:
                            close();
                            break;

                        default:
                            gCurrentSurface = gKeyPressSurfaces[KEY_PRESS_SURFACE_DEFAULT];
                            break;
                        }
                    }
                }

                SDL_BlitSurface(gCurrentSurface, NULL, gScreenSurface, NULL);

                SDL_UpdateWindowSurface(gWindow);
            }
        }
    }

    close();

    return 0;
}