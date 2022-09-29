#ifndef utility
#define utility

void zamien(int * a, int * b)
{
    int c = *a;
    *a = *b;
    *b = c;
}

void silentSetup()
{
    if(SDL_Init(SDL_INIT_VIDEO) < 0)
    {
        printf("SDL nie wlaczyl sie: %s\n" , SDL_GetError());
        exit(0);
    }

    printf(".");

    if(TTF_Init() < 0)
    {
        printf("SDL_ttf nie wlaczyl siê: %s\n", TTF_GetError());
        exit(0);
    }

    printf(".");

    window = SDL_CreateWindow("Tetris", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, WIDTH, HEIGHT, SDL_WINDOW_ALLOW_HIGHDPI);

    if(window == NULL)
    {
        printf("Nie udalo sie uruchomic okienka: %s\n", SDL_GetError());
        exit(0);
    }

    printf(".");

    SDL_Surface* icon = SDL_LoadBMP("resources\\icon.bmp");
    SDL_SetWindowIcon(window, icon);
    SDL_FreeSurface(icon);

    printf(".");

    plansza = malloc(sizeof(int*) * wysokosc);
    for(int i = 0; i<wysokosc; i++)
    {
        plansza[i] = malloc(sizeof(int) * szerokosc);
        for(int j = 0; j<szerokosc; j++)
        {
            plansza[i][j] = 0;
        }
    }

    printf(".");

    pomocniczyKlocek = malloc(sizeof(int *) * 4);
    for(int i = 0; i < 4; i++)
    {
        pomocniczyKlocek[i] = malloc(sizeof(int) * 4);
        for(int j = 0; j < 4; j++)
        {
            pomocniczyKlocek[i][j] = 0;
        }
    }

    pomocniczyWstawianyKlocek = malloc(sizeof(int *) * 4);
    for(int i = 0; i < 4; i++)
    {
        pomocniczyWstawianyKlocek[i] = malloc(sizeof(int) * 4);
        for(int j = 0; j < 4; j++)
        {
            pomocniczyWstawianyKlocek[i][j] = 0;
        }
    }

    printf(".");

    klocki = malloc(sizeof(int **) * 7);
    klocki[0] = malloc(sizeof(int *) * 4);
    for(int i = 0; i < 4; i++)
    {
        klocki[0][i] = malloc(sizeof(int) * 4);
        for(int j = 0; j < 4; j++)
        {
            klocki[0][i][j] = 0;
        }
    }
    klocki[0][0][1] = 1;
    klocki[0][1][1] = 1;
    klocki[0][2][1] = 1;
    klocki[0][3][1] = 1;

    printf(".");

    klocki[1] = malloc(sizeof(int *) * 2);
    for(int i = 0; i < 2; i++)
    {
        klocki[1][i] = malloc(sizeof(int) * 2);
        for(int j = 0; j < 2; j++)
        {
            klocki[1][i][j] = 0;
        }
    }
    klocki[1][0][0] = 2;
    klocki[1][0][1] = 2;
    klocki[1][1][0] = 2;
    klocki[1][1][1] = 2;

    printf(".");

    klocki[2] = malloc(sizeof(int *) * 3);
    for(int i = 0; i < 3; i++)
    {
        klocki[2][i] = malloc(sizeof(int) * 3);
        for(int j = 0; j < 3; j++)
        {
            klocki[2][i][j] = 0;
        }
    }
    klocki[2][0][1] = 3;
    klocki[2][1][1] = 3;
    klocki[2][2][1] = 3;
    klocki[2][2][2] = 3;

    printf(".");

    klocki[3] = malloc(sizeof(int *) * 3);
    for(int i = 0; i < 3; i++)
    {
        klocki[3][i] = malloc(sizeof(int) * 3);
        for(int j = 0; j < 3; j++)
        {
            klocki[3][i][j] = 0;
        }
    }
    klocki[3][0][1] = 4;
    klocki[3][1][1] = 4;
    klocki[3][1][2] = 4;
    klocki[3][2][2] = 4;

    printf(".");

    klocki[4] = malloc(sizeof(int *) * 3);
    for(int i = 0; i < 3; i++)
    {
        klocki[4][i] = malloc(sizeof(int) * 3);
        for(int j = 0; j < 3; j++)
        {
            klocki[4][i][j] = 0;
        }
    }
    klocki[4][0][2] = 5;
    klocki[4][1][1] = 5;
    klocki[4][1][2] = 5;
    klocki[4][2][1] = 5;

    printf(".");

    klocki[5] = malloc(sizeof(int *) * 3);
    for(int i = 0; i < 3; i++)
    {
        klocki[5][i] = malloc(sizeof(int) * 3);
        for(int j = 0; j < 3; j++)
        {
            klocki[5][i][j] = 0;
        }
    }
    klocki[5][1][0] = 6;
    klocki[5][1][1] = 6;
    klocki[5][1][2] = 6;
    klocki[5][2][1] = 6;

    printf(".");

    klocki[6] = malloc(sizeof(int *) * 3);
    for(int i = 0; i < 3; i++)
    {
        klocki[6][i] = malloc(sizeof(int) * 3);
        for(int j = 0; j < 3; j++)
        {
            klocki[6][i][j] = 0;
        }
    }
    klocki[6][0][1] = 7;
    klocki[6][1][1] = 7;
    klocki[6][2][0] = 7;
    klocki[6][2][1] = 7;

    printf(".");

    windowSurface = SDL_GetWindowSurface(window);
    graySpace = SDL_LoadBMP("resources\\gray.bmp");
    aquaSpace = SDL_LoadBMP("resources\\aqua.bmp");
    blueSpace = SDL_LoadBMP("resources\\blue.bmp");
    greenSpace = SDL_LoadBMP("resources\\green.bmp");
    orangeSpace = SDL_LoadBMP("resources\\orange.bmp");
    pinkSpace = SDL_LoadBMP("resources\\pink.bmp");
    redSpace = SDL_LoadBMP("resources\\red.bmp");
    yellowSpace = SDL_LoadBMP("resources\\yellow.bmp");
    pausedText = SDL_LoadBMP("resources\\paused.bmp");
    one = SDL_LoadBMP("resources\\one.bmp");
    two = SDL_LoadBMP("resources\\two.bmp");
    three = SDL_LoadBMP("resources\\three.bmp");
    four = SDL_LoadBMP("resources\\four.bmp");
    five = SDL_LoadBMP("resources\\five.bmp");
    six = SDL_LoadBMP("resources\\six.bmp");
    seven = SDL_LoadBMP("resources\\seven.bmp");
    eight = SDL_LoadBMP("resources\\eight.bmp");
    nine = SDL_LoadBMP("resources\\nine.bmp");
    zero = SDL_LoadBMP("resources\\zero.bmp");
    logoTetris = SDL_LoadBMP("resources\\tetris.bmp");
    playButton1 = SDL_LoadBMP("resources\\play1.bmp");
    playButton2 = SDL_LoadBMP("resources\\play2.bmp");
    htpButton1 = SDL_LoadBMP("resources\\howtoplay1.bmp");
    htpButton2 = SDL_LoadBMP("resources\\howtoplay2.bmp");
    wynikBMP = SDL_LoadBMP("resources\\wynik.bmp");
    scoresButton1 = SDL_LoadBMP("resources\\scores1.bmp");
    scoresButton2 = SDL_LoadBMP("resources\\scores2.bmp");
    menuButton1 = SDL_LoadBMP("resources\\menu1.bmp");
    menuButton2 = SDL_LoadBMP("resources\\menu2.bmp");
    restartButton1 = SDL_LoadBMP("resources\\restart1.bmp");
    restartButton2 = SDL_LoadBMP("resources\\restart2.bmp");
    score = SDL_LoadBMP("resources\\score.bmp");
    next = SDL_LoadBMP("resources\\next.bmp");
    swapp = SDL_LoadBMP("resources\\swap.bmp");

    czcionka = TTF_OpenFont("resources\\comic.ttf", wielkosc*2);
    wingdings = TTF_OpenFont("resources\\212Keyboard-lmRZ.otf", wielkosc*3.5);

    poczatek[0] =(WIDTH - wielkosc * szerokosc)/2;
    poczatek[1] = (HEIGHT - wielkosc * wysokosc)/2;

    szary = SDL_MapRGB(windowSurface->format, 128, 128, 128);
    czarny = SDL_MapRGB(windowSurface->format, 0, 0, 0);
    jszary = SDL_MapRGB(windowSurface->format, 155, 155, 155);

    upText = TTF_RenderText_Blended(czcionka, " : Obroc klocek", czarnySDL);
    leftText = TTF_RenderText_Blended(czcionka, " : Przesun klocek w lewo", czarnySDL);
    rightText = TTF_RenderText_Blended(czcionka, " : Przesun klocek w prawo", czarnySDL);
    downText = TTF_RenderText_Blended(czcionka, " : Przyspiesz spadanie", czarnySDL);
    spaceText = TTF_RenderText_Blended(czcionka, " : Zamien klocek", czarnySDL);
    escText = TTF_RenderText_Blended(czcionka, " : Pauza", czarnySDL);
    upWing = TTF_RenderText_Blended(wingdings, GORA, czarnySDL);
    leftWing = TTF_RenderText_Blended(wingdings, LEWO, czarnySDL);
    rightWing = TTF_RenderText_Blended(wingdings, PRAWO, czarnySDL);
    downWing = TTF_RenderText_Blended(wingdings, DOL, czarnySDL);
    spaceWing = TTF_RenderText_Blended(wingdings, SPACJA, czarnySDL);
    escWing = TTF_RenderText_Blended(wingdings, ESC, czarnySDL);

    wyniki = malloc(sizeof(int) * 6);
    plik = fopen("pliki\\wyniki.txt", "r");
    for(int i = 0; i < 6; i++)
    {
        fscanf(plik,"%d", &wyniki[i]);
    }
    fclose(plik);

    srand(time(NULL));
}

void cleanUp()
{
    plik = fopen("pliki\\wyniki.txt", "w");
    for(int i = 0; i < 6; i++)
    {
        fprintf(plik, "%d\n", wyniki[i]);
    }
    fclose(plik);

    for(int i = 0; i < wysokosc; i++)
    {
        free(plansza[i]);
    }
    free(plansza);

    for(int i = 0; i < 7; i++)
    {
        for(int j = 0; j < wielkosciKlockow[i]; j++)
        {
            free(klocki[i][j]);
        }
        free(klocki[i]);
    }
    free(klocki);

    for(int i = 0; i < 4; i++)
    {
        free(pomocniczyKlocek[i]);
    }
    free(pomocniczyKlocek);

    for(int i = 0; i < 4; i++)
    {
        free(pomocniczyWstawianyKlocek[i]);
    }
    free(pomocniczyWstawianyKlocek);

    free(wyniki);

    SDL_FreeSurface(windowSurface);
    SDL_FreeSurface(graySpace);
    SDL_FreeSurface(aquaSpace);
    SDL_FreeSurface(blueSpace);
    SDL_FreeSurface(greenSpace);
    SDL_FreeSurface(orangeSpace);
    SDL_FreeSurface(pinkSpace);
    SDL_FreeSurface(redSpace);
    SDL_FreeSurface(yellowSpace);
    SDL_FreeSurface(pausedText);
    SDL_FreeSurface(one);
    SDL_FreeSurface(two);
    SDL_FreeSurface(three);
    SDL_FreeSurface(four);
    SDL_FreeSurface(five);
    SDL_FreeSurface(six);
    SDL_FreeSurface(seven);
    SDL_FreeSurface(eight);
    SDL_FreeSurface(nine);
    SDL_FreeSurface(zero);
    SDL_FreeSurface(logoTetris);
    SDL_FreeSurface(playButton1);
    SDL_FreeSurface(playButton2);
    SDL_FreeSurface(htpButton1);
    SDL_FreeSurface(htpButton2);
    SDL_FreeSurface(wynikBMP);
    SDL_FreeSurface(scoresButton1);
    SDL_FreeSurface(scoresButton2);
    SDL_FreeSurface(menuButton1);
    SDL_FreeSurface(menuButton2);
    SDL_FreeSurface(restartButton1);
    SDL_FreeSurface(restartButton2);
    SDL_FreeSurface(score);
    SDL_FreeSurface(next);
    SDL_FreeSurface(swapp);

    SDL_FreeSurface(upText);
    SDL_FreeSurface(leftText);
    SDL_FreeSurface(rightText);
    SDL_FreeSurface(downText);
    SDL_FreeSurface(spaceText);
    SDL_FreeSurface(escText);
    SDL_FreeSurface(upWing);
    SDL_FreeSurface(leftWing);
    SDL_FreeSurface(rightWing);
    SDL_FreeSurface(downWing);
    SDL_FreeSurface(spaceWing);
    SDL_FreeSurface(escWing);

    TTF_CloseFont(czcionka);
    TTF_CloseFont(wingdings);

    SDL_DestroyWindow(window);
    SDL_Quit();
    TTF_Quit();
}

void EventHandler0()
{
    SDL_Event event;
    while(SDL_PollEvent(&event) )
    {
        switch(event.type)
        {
            case SDL_QUIT:
                petla = false;
                break;

            case SDL_KEYDOWN:
                switch(event.key.keysym.sym)
                {
                    case SDLK_DOWN:
                        predkosc = 5;
                        break;

                    case SDLK_RIGHT:
                        if(sprawdzPozycje(pozycja[0]+1, pozycja[1], wielkosciKlockow[wstawianyKlocek]))
                        {
                            pozycja[0] += 1;
                        }
                        break;

                    case SDLK_LEFT:
                        if(sprawdzPozycje(pozycja[0]-1, pozycja[1], wielkosciKlockow[wstawianyKlocek]))
                        {
                            pozycja[0] -= 1;
                        }
                        break;

                    case SDLK_SPACE:
                        if(sprawdzPozycjeTrzymanego(trzymanyKlocek, pozycja[0], pozycja[1], wielkosciKlockow[trzymanyKlocek]))
                        {
                            przepiszWstawianyKlocek(trzymanyKlocek, wielkosciKlockow[trzymanyKlocek]);
                            zamien(&trzymanyKlocek, &wstawianyKlocek);
                        }
                        break;

                    case SDLK_UP:
                        if(sprawdzObrot(pozycja[0], pozycja[1], wielkosciKlockow[wstawianyKlocek]))
                        {
                            obrot(wielkosciKlockow[wstawianyKlocek]);
                        }
                        break;

                    case SDLK_ESCAPE:
                        SCENE = 2;
                        break;

                    default:
                        break;
                }
                break;

            case SDL_KEYUP:
                switch(event.key.keysym.sym)
                {
                    case SDLK_DOWN:
                        predkosc = copyPredkosc;
                        break;

                    default:
                        break;
                }

            default:
                break;
        }
    }
}

void EventHandler1()
{
    SDL_Event event;
    int x,y;
    SDL_GetMouseState(&x,&y);
    SDL_Rect playRect = {.x = (WIDTH - wielkosc2*17)/2, .y = wielkosc2*2 + wielkosc2*7 + wielkosc2*3 , .h = wielkosc2*7, .w = wielkosc2*17};
    SDL_Rect htpRect = {.x = (WIDTH - wielkosc2*33)/2, .y = wielkosc2*2 + (wielkosc2*7 + wielkosc2*3)*2, .h = wielkosc2*7, .w = wielkosc2*33};
    SDL_Rect scoresRect = {.x = (WIDTH - wielkosc2*28)/2, .y = wielkosc2*2 + (wielkosc2*7 + wielkosc2*3)*3, .h = wielkosc2*7, .w = wielkosc2*28};
    while(SDL_PollEvent(&event) )
    {
        switch(event.type)
        {
            case SDL_QUIT:
                petla = false;
                break;

            case SDL_MOUSEBUTTONDOWN:
                switch(event.button.button)
                {
                    case SDL_BUTTON_LEFT:
                        if(inRect(playRect, x, y))
                        {
                            setup();
                            SCENE = 0;
                        }
                        if(inRect(htpRect, x, y))
                        {
                            SCENE = 4;
                        }
                        if(inRect(scoresRect, x, y))
                        {
                            SCENE = 5;
                        }
                        break;

                    default:
                        break;
                }
                break;

            default:
                break;
        }
    }
}

void EventHandler2()
{
    SDL_Event event;
    int x,y;
    SDL_GetMouseState(&x,&y);
    SDL_Rect restartRect = {.x = (WIDTH - 29 * wielkosc2)/2, .y = (HEIGHT - 7 * wielkosc2)/2 + 7*wielkosc2 + 3*wielkosc2, .w = 29*wielkosc2, .h = 7*wielkosc2};
    SDL_Rect menuRect = {.x = (WIDTH - 20 * wielkosc2)/2, .y = (HEIGHT - 7 * wielkosc2)/2 + (7*wielkosc2 + 3*wielkosc2)*2 , .w = 20*wielkosc2, .h = 7*wielkosc2};
    while(SDL_PollEvent(&event) )
    {
        switch(event.type)
        {
            case SDL_QUIT:
                petla = false;
                break;

            case SDL_KEYDOWN:
                switch(event.key.keysym.sym)
                {
                    case SDLK_ESCAPE:
                        SCENE = 0;
                        break;

                    default:
                        break;
                }

            case SDL_MOUSEBUTTONDOWN:
                switch(event.button.button)
                {
                    case SDL_BUTTON_LEFT:
                        if(inRect(menuRect, x, y))
                        {
                            SCENE = 1;
                        }
                        if(inRect(restartRect, x, y))
                        {
                            setup();
                            SCENE = 0;
                        }
                        break;

                    default:
                        break;
                }
                break;

            default:
                break;
        }
    }
}

void EventHandler3()
{
    SDL_Event event;
    int x,y;
    SDL_GetMouseState(&x,&y);
    SDL_Rect restartRect = {.x = (WIDTH - 29 * wielkosc2)/2, .y = (HEIGHT - wielkosc2)/2 + 10*wielkosc2, .w = 29*wielkosc2, .h = 7*wielkosc2};
    SDL_Rect menuRect = {.x = (WIDTH - 20 * wielkosc2)/2, .y = (HEIGHT - wielkosc2)/2 + (10*wielkosc2)*2 , .w = 20*wielkosc2, .h = 7*wielkosc2};
    while(SDL_PollEvent(&event) )
    {
        switch(event.type)
        {
            case SDL_QUIT:
                petla = false;
                break;

            case SDL_MOUSEBUTTONDOWN:
                switch(event.button.button)
                {
                    case SDL_BUTTON_LEFT:
                        if(inRect(menuRect, x, y))
                        {
                            SCENE = 1;
                        }
                        if(inRect(restartRect, x, y))
                        {
                            setup();
                            SCENE = 0;
                        }
                        break;

                    default:
                        break;
                }
                break;

            default:
                break;
        }
    }
}

void EventHandler4()
{
    SDL_Event event;
    int x,y;
    SDL_GetMouseState(&x,&y);
    SDL_Rect menuRect = {.x = WIDTH - wielkosc2*21, .y = HEIGHT - wielkosc2*8, .w = 20*wielkosc2, .h = 7*wielkosc2};
    while(SDL_PollEvent(&event) )
    {
        switch(event.type)
        {
            case SDL_QUIT:
                petla = false;
                break;

            case SDL_MOUSEBUTTONDOWN:
                switch(event.button.button)
                {
                    case SDL_BUTTON_LEFT:
                        if(inRect(menuRect, x, y))
                        {
                            SCENE = 1;
                        }
                        break;

                    default:
                        break;
                }
                break;

            default:
                break;
        }
    }
}

void EventHandler5()
{
    SDL_Event event;
    int x,y;
    SDL_GetMouseState(&x,&y);
    SDL_Rect menuRect = {.x = WIDTH - wielkosc2*21, .y = HEIGHT - wielkosc2*8, .w = 20*wielkosc2, .h = 7*wielkosc2};
    while(SDL_PollEvent(&event) )
    {
        switch(event.type)
        {
            case SDL_QUIT:
                petla = false;
                break;

            case SDL_MOUSEBUTTONDOWN:
                switch(event.button.button)
                {
                    case SDL_BUTTON_LEFT:
                        if(inRect(menuRect, x, y))
                        {
                            SCENE = 1;
                        }
                        break;

                    default:
                        break;
                }
                break;

            default:
                break;
        }
    }
}

#endif
