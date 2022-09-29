#include <stdio.h>
#include <SDL.h>
#include <SDL_ttf.h>
#include <windows.h>
#include <stdbool.h>
#include <math.h>
#include <time.h>

#include "code\stale.h"
#include "code\funkcje.h"
#include "code\utility.h"

int main(int argc, char *argv[])
{
    silentSetup();

    setup();

    while (petla)
    {
        Uint64 start = SDL_GetPerformanceCounter();

        switch(SCENE)
        {
            case 0: //gra
                EventHandler0();
                drawScene0();
                break;
            case 1: //menu
                EventHandler1();
                drawScene1();
                break;
            case 2: //pauza
                EventHandler2();
                drawScene2();
                break;
            case 3: //przegrana
                EventHandler3();
                drawScene3();
                break;
            case 4: //jak grac
                EventHandler4();
                drawScene4();
                break;
            case 5: //wyniki
                EventHandler5();
                drawScene5();
                break;
        }

        Uint64 end = SDL_GetPerformanceCounter();
        float elapsedMS = (end - start) / (float)SDL_GetPerformanceFrequency() * 1000.0f;
        if(petla && elapsedMS < 16.666f)
        {
            SDL_Delay(floor(16.666f - elapsedMS));
        }

        frameCount += 1;

        SDL_UpdateWindowSurface(window);
    }

    cleanUp();

    return 0;
}
