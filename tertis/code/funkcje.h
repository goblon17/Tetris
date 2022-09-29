#ifndef funkcje
#define funkcje


int log_10(int n)
{
    if(n == 0)
    {
        return 1;
    }
    int w = 0;
    while(n > 0)
    {
        n /= 10;
        w ++;
    }
    return w;
}

int myCompare (const void * a, const void * b)
{
    int _a = *(int*)a;
    int _b = *(int*)b;
    if(_a < _b) return -1;
    else if(_a == _b) return 0;
    else return 1;
}

void przepiszKlocek(int w)
{
    for(int i = 0; i < w; i++)
    {
        for(int j = 0; j < w; j++)
        {
            pomocniczyKlocek[i][j] = pomocniczyWstawianyKlocek[i][j];
        }
    }
}

void przepiszWstawianyKlocek(int klocek, int w)
{
    for(int i = 0; i < w; i++)
    {
        for(int j = 0; j < w; j++)
        {
            pomocniczyWstawianyKlocek[i][j] = klocki[klocek][i][j];
        }
    }
}

int losujKlocek()
{
    return rand()%7;
}

bool inbound(int x, int y)
{
    if(x < 0 || y < 0 || x > szerokosc - 1 || y > wysokosc - 1)
    {
        return false;
    }
    return true;
}

void pokazPole(int pole, int x, int y, int xShift, int yShift)
{
    if(!inbound(x,y))
    {
        return;
    }
    SDL_Surface * Pole;
    SDL_Rect pos = {.x = xShift + x*wielkosc, .y = yShift + y*wielkosc, .w = wielkosc, .h = wielkosc};
    switch(pole)
    {
        case 1: Pole = aquaSpace; break;
        case 2: Pole = yellowSpace; break;
        case 3: Pole = orangeSpace; break;
        case 4: Pole = greenSpace; break;
        case 5: Pole = redSpace; break;
        case 6: Pole = pinkSpace; break;
        case 7: Pole = blueSpace; break;
        default: Pole = graySpace; break;
    };
    SDL_BlitScaled(Pole, NULL, windowSurface, &pos);
}

void pokazNastepnyKlocek()
{
    int xShift = poczatek[0] + wielkosc * szerokosc + 50;
    int yShift = poczatek[1] + 50;
    SDL_Rect otoczka = {.x = xShift - wielkosc/6, .y = yShift - wielkosc/6, .h = wielkosc/3 + 4*wielkosc, .w = wielkosc/3 + 4*wielkosc};
    SDL_Rect nextRect = {.x = xShift - wielkosc4/2, .y = yShift - 6*wielkosc4, .h = 5*wielkosc4, .w = 16*wielkosc4};
    SDL_BlitScaled(next, NULL, windowSurface, &nextRect);
    SDL_FillRect(windowSurface, &otoczka, czarny);
    int newXShift;
    int newYShift;
    if(nastepnyKlocek == 1 || nastepnyKlocek == 6)
    {
        newXShift = xShift + wielkosc;
        newYShift = yShift + wielkosc;
    }
    else if (nastepnyKlocek == 2 || nastepnyKlocek == 4)
    {
        newXShift = xShift;
        newYShift = yShift + wielkosc;
    }
    else
    {
        newXShift = xShift;
        newYShift = yShift;
    }
    for(int i = 0; i < 4; i++)
    {
        for(int j = 0; j < 4; j++)
        {
            pokazPole(0,i,j,xShift,yShift);
        }
    }
    for(int i = 0; i < wielkosciKlockow[nastepnyKlocek]; i++)
    {
        for(int j = 0; j < wielkosciKlockow[nastepnyKlocek]; j++)
        {
            pokazPole(klocki[nastepnyKlocek][j][i], i, j, newXShift, newYShift);
        }
    }
}

void pokazTrzymanyKlocek()
{
    int xShift = poczatek[0] - 4*wielkosc - 50;
    int yShift = poczatek[1] + 50;
    SDL_Rect otoczka = {.x = xShift - wielkosc/6, .y = yShift - wielkosc/6, .h = wielkosc/3 + 4*wielkosc, .w = wielkosc/3 + 4*wielkosc};
    SDL_Rect swapRect = {.x = xShift - wielkosc4/2, .y = yShift - 6*wielkosc4, .h = 5*wielkosc4, .w = 16*wielkosc4};
    SDL_BlitScaled(swapp, NULL, windowSurface, &swapRect);
    SDL_FillRect(windowSurface, &otoczka, czarny);
    int newXShift;
    int newYShift;
    if(trzymanyKlocek == 1 || trzymanyKlocek == 6)
    {
        newXShift = xShift + wielkosc;
        newYShift = yShift + wielkosc;
    }
    else if (trzymanyKlocek == 2 || trzymanyKlocek == 4)
    {
        newXShift = xShift;
        newYShift = yShift + wielkosc;
    }
    else
    {
        newXShift = xShift;
        newYShift = yShift;
    }
    for(int i = 0; i < 4; i++)
    {
        for(int j = 0; j < 4; j++)
        {
            pokazPole(0,i,j,xShift,yShift);
        }
    }
    for(int i = 0; i < wielkosciKlockow[trzymanyKlocek]; i++)
    {
        for(int j = 0; j < wielkosciKlockow[trzymanyKlocek]; j++)
        {
            pokazPole(klocki[trzymanyKlocek][j][i], i, j, newXShift, newYShift);
        }
    }
}

bool sprawdzPozycje(int x, int y, int w)
{
    for(int i = 0; i < w; i++)
    {
        for(int j = 0; j < w; j++)
        {
            if( inbound(x+j, y+i) && plansza[y+i][x+j] > 0 && pomocniczyWstawianyKlocek[i][j] > 0)
            {
                return false;
            }
            if( pomocniczyWstawianyKlocek[i][j] > 0 && y+i > wysokosc - 1)
            {
                return false;
            }
            if( pomocniczyWstawianyKlocek[i][j] > 0 && ( x+j < 0 || x+j > szerokosc - 1 ))
            {
                return false;
            }
        }
    }
    return true;
}

bool sprawdzPozycjeTrzymanego(int klocek, int x, int y, int w)
{
    for(int i = 0; i < w; i++)
    {
        for(int j = 0; j < w; j++)
        {
            if( inbound(x+j, y+i) && plansza[y+i][x+j] > 0 && klocki[klocek][i][j] > 0)
            {
                return false;
            }
            if( klocki[klocek][i][j] > 0 && y+i > wysokosc - 1)
            {
                return false;
            }
            if( klocki[klocek][i][j] > 0 && ( x+j < 0 || x+j > szerokosc - 1 ))
            {
                return false;
            }
        }
    }
    return true;
}

void obrot(int w)
{
    przepiszKlocek(w);
    for(int i = 0; i < w; i++)
    {
        for(int j = 0; j < w; j++)
        {
            pomocniczyWstawianyKlocek[i][j] = pomocniczyKlocek[w - 1 - j][i];
        }
    }
}

bool sprawdzObrot(int x, int y, int w)
{
    for(int i = 0; i < w; i++)
    {
        for(int j = 0; j < w; j++)
        {
            pomocniczyKlocek[i][j] = pomocniczyWstawianyKlocek[w - 1 - j][i];
        }
    }
    for(int i = 0; i < w; i++)
    {
        for(int j = 0; j < w; j++)
        {
            if( inbound(x+j, y+i) && plansza[y+i][x+j] > 0 && pomocniczyKlocek[i][j] > 0)
            {
                return false;
            }
            if( pomocniczyKlocek[i][j] > 0 && y+i > wysokosc - 1)
            {
                return false;
            }
            if( pomocniczyKlocek[i][j] > 0 && ( x+j < 0 || x+j > szerokosc - 1 ))
            {
                return false;
            }
        }
    }
    return true;
}

void pokazPlansze()
{
    SDL_Rect otoczka = {.x = poczatek[0] - wielkosc/6, .y = poczatek[1] - wielkosc/6, .w = wielkosc/3 + szerokosc*wielkosc, .h = wielkosc/3 + wysokosc*wielkosc};
    SDL_FillRect(windowSurface, &otoczka, czarny);
    for(int i = 0; i < wysokosc; i++)
    {
        for(int j = 0; j<szerokosc; j++)
        {
            pokazPole(plansza[i][j], j, i, poczatek[0], poczatek[1]);
        }
    }
}

void pokazWstawianyKlocek()
{
    for(int i = 0; i < wielkosciKlockow[wstawianyKlocek]; i++)
    {
        for(int j = 0; j < wielkosciKlockow[wstawianyKlocek]; j++)
        {
            if(pomocniczyWstawianyKlocek[i][j] > 0)
            {
                pokazPole(pomocniczyWstawianyKlocek[i][j], j+pozycja[0], i+pozycja[1], poczatek[0], poczatek[1]);
            }
        }
    }
}

void wpiszDoPlanszy(int x, int y, int w)
{
    for(int i = 0; i < w; i++)
    {
        for(int j = 0; j < w; j++)
        {
            if(pomocniczyWstawianyKlocek[i][j] > 0)
            {
                plansza[y+i][x+j] = pomocniczyWstawianyKlocek[i][j];
            }
        }
    }
}

int sprawdzTetris()
{
    int n = 0;
    bool t = true;
    for(int i = 0; i < wysokosc; i++)
    {
        t = true;
        for(int j = 0; j < szerokosc && t; j++)
        {
            if(plansza[i][j] == 0)
            {
                t = false;
            }
        }
        if(t)
        {
            for(int l = 0; l < szerokosc; l++)
            {
                plansza[i][l] = 0;
            }
            for(int k = i-1; k >= 0; k--)
            {
                for(int l = 0; l < szerokosc; l++)
                {
                    zamien(&plansza[k+1][l],&plansza[k][l]);
                }
            }
            n += 1;
        }
    }
    return n;
}

void wypiszNumer(int numer, int x, int y)
{
    SDL_Surface* pom;
    int tmp = numer;
    int n = 0;
    SDL_Rect w = {.w = 3*wielkosc2, .h = 5*wielkosc2, .x = x, .y = y};
    if(numer == 0)
    {
        SDL_BlitScaled(zero, NULL, windowSurface, &w);
        return;
    }
    while(tmp > 0)
    {
        n = tmp%10;
        tmp /= 10;
        switch(n)
        {
            case 0:
                pom = zero;
                break;
            case 1:
                pom = one;
                break;
            case 2:
                pom = two;
                break;
            case 3:
                pom = three;
                break;
            case 4:
                pom = four;
                break;
            case 5:
                pom = five;
                break;
            case 6:
                pom = six;
                break;
            case 7:
                pom = seven;
                break;
            case 8:
                pom = eight;
                break;
            case 9:
                pom = nine;
                break;
        }
        SDL_BlitScaled(pom, NULL, windowSurface, &w);
        w.x -= wielkosc2*4;
    }
}

void pokazWynik()
{
    int b = wielkosc2 / 2;
    SDL_Rect wy = {.w = 22*b, .h = 5*b, .x = poczatek[0] + wielkosc*szerokosc + 20, .y = HEIGHT - b*2*5 - b*2 - b - b*5};
    SDL_BlitScaled(wynikBMP, NULL, windowSurface, &wy);
    wypiszNumer(wynik, poczatek[0] + wielkosc * szerokosc + 50 + wielkosc*4, HEIGHT - wielkosc2*5 - wielkosc2/2);
}

bool inRect(SDL_Rect rect, int x, int y)
{
    if(x < rect.x || x > rect.x + rect.w || y < rect.y || y > rect.y + rect.h)
    {
        return false;
    }
    return true;
}

void setup()
{
    for(int i = 0; i < wysokosc; i++)
    {
        for(int j = 0; j < szerokosc; j++)
        {
            plansza[i][j] = 0;
        }
    }

    nastepnyKlocek = losujKlocek();
    trzymanyKlocek = losujKlocek();
    wstawianyKlocek = losujKlocek();
    przepiszWstawianyKlocek(wstawianyKlocek, wielkosciKlockow[wstawianyKlocek]);
    pozycja[0] = szerokosc/2 - 1;
    pozycja[1] = -wielkosciKlockow[wstawianyKlocek];
    predkosc = 60;
    copyPredkosc = predkosc;

    wynik = 0;
    poziom = 1;
    licznikTetris = 0;
}

void drawScene0()
{
    SDL_FillRect(windowSurface, NULL, szary);
    pokazPlansze();
    pokazNastepnyKlocek();
    pokazTrzymanyKlocek();
    pokazWstawianyKlocek();
    pokazWynik();

    if(poziom > predkosc)
    {
        poziom = predkosc;
    }
    if(poziom < 1)
    {
        poziom = 1;
    }
    if(frameCount % (predkosc/poziom) == 0)
    {
        if(sprawdzPozycje(pozycja[0], pozycja[1] + 1, wielkosciKlockow[wstawianyKlocek]))
        {
            pozycja[1] += 1;
        }
        else if(pozycja[1] < 0)
        {
            wyniki[0] = wynik;
            qsort(wyniki, 6, sizeof(int), myCompare);
            SCENE = 3;
        }
        else
        {
            wpiszDoPlanszy(pozycja[0], pozycja[1], wielkosciKlockow[wstawianyKlocek]);
            wstawianyKlocek = nastepnyKlocek;
            nastepnyKlocek = losujKlocek();
            przepiszWstawianyKlocek(wstawianyKlocek, wielkosciKlockow[wstawianyKlocek]);
            pozycja[0] = szerokosc/2 -1;
            pozycja[1] = -wielkosciKlockow[wstawianyKlocek];
        }
    }

    int w = sprawdzTetris();
    licznikTetris += w;
    switch(w)
    {
        case 1:
            wynik += 100 * poziom;
            break;
        case 2:
            wynik += 300 * poziom;
            break;
        case 3:
            wynik += 500 * poziom;
        case 4:
            wynik += 800 * poziom;
        default:
            break;
    }
    if(licznikTetris > 7)
    {
        licznikTetris = 0;
        poziom += 1;
    }
}

void drawScene1()
{
    SDL_FillRect(windowSurface, NULL, szary);
    SDL_Rect logoRect = {.x = (WIDTH - wielkosc2*25) / 2, .y = wielkosc2*2, .h = wielkosc2*7, .w = wielkosc2*25};
    SDL_BlitScaled(logoTetris, NULL, windowSurface, &logoRect);
    SDL_Rect playRect = {.x = (WIDTH - wielkosc2*17)/2, .y = wielkosc2*2 + (wielkosc2*7 + wielkosc2*3)*1 , .h = wielkosc2*7, .w = wielkosc2*17};
    SDL_Rect htpRect = {.x = (WIDTH - wielkosc2*33)/2, .y = wielkosc2*2 + (wielkosc2*7 + wielkosc2*3)*2, .h = wielkosc2*7, .w = wielkosc2*33};
    SDL_Rect scoresRect = {.x = (WIDTH - wielkosc2*28)/2, .y = wielkosc2*2 + (wielkosc2*7 + wielkosc2*3)*3, .h = wielkosc2*7, .w = wielkosc2*28};
    int x,y;
    SDL_GetMouseState(&x, &y);
    if(!inRect(playRect, x, y))
    {
        SDL_BlitScaled(playButton1, NULL, windowSurface, &playRect);
    }
    else
    {
        SDL_BlitScaled(playButton2, NULL, windowSurface, &playRect);
    }
    if(inRect(htpRect, x, y))
    {
        SDL_BlitScaled(htpButton2, NULL, windowSurface, &htpRect);
    }
    else
    {
        SDL_BlitScaled(htpButton1, NULL, windowSurface, &htpRect);
    }
    if(inRect(scoresRect, x, y))
    {
        SDL_BlitScaled(scoresButton2, NULL, windowSurface, &scoresRect);
    }
    else
    {
        SDL_BlitScaled(scoresButton1, NULL, windowSurface, &scoresRect);
    }
}

void drawScene2()
{
    SDL_FillRect(windowSurface, NULL, szary);
    pokazPlansze();
    pokazNastepnyKlocek();
    pokazTrzymanyKlocek();
    pokazWstawianyKlocek();
    pokazWynik();
    int x,y;
    SDL_GetMouseState(&x, &y);
    SDL_Rect pausedRect = {.x = (WIDTH - 25 * wielkosc2)/2, .y = (HEIGHT - 7 * wielkosc2) / 2, .w = 25 * wielkosc2, .h = 7 * wielkosc2};
    SDL_Rect restartRect = {.x = (WIDTH - 29 * wielkosc2)/2, .y = (HEIGHT - 7 * wielkosc2)/2 + 7*wielkosc2 + 3*wielkosc2, .w = 29*wielkosc2, .h = 7*wielkosc2};
    SDL_Rect menuRect = {.x = (WIDTH - 20 * wielkosc2)/2, .y = (HEIGHT - 7 * wielkosc2)/2 + (7*wielkosc2 + 3*wielkosc2)*2 , .w = 20*wielkosc2, .h = 7*wielkosc2};
    if(inRect(restartRect, x, y))
    {
        SDL_BlitScaled(restartButton2, NULL, windowSurface, &restartRect);
    }
    else
    {
        SDL_BlitScaled(restartButton1, NULL, windowSurface, &restartRect);
    }
    if(inRect(menuRect, x, y))
    {
        SDL_BlitScaled(menuButton2, NULL, windowSurface, &menuRect);
    }
    else
    {
        SDL_BlitScaled(menuButton1, NULL, windowSurface, &menuRect);
    }

    SDL_BlitScaled(pausedText, NULL, windowSurface, &pausedRect);
}

void drawScene3()
{
    int x,y;
    SDL_GetMouseState(&x, &y);
    SDL_Rect scoreRect = {.x = (WIDTH - 24*wielkosc2)/2, .y = (HEIGHT - 7*wielkosc2 - 6*wysokosc)/2, .w = 24*wielkosc2, .h = 7*wielkosc2};
    SDL_BlitScaled(score, NULL, windowSurface, &scoreRect);
    int n = log_10(wynik)-2;
    SDL_Rect scoreOtoczka1 = {.x = 0, .y = (HEIGHT)/2, .w = WIDTH, .h = 7*wielkosc2};
    SDL_FillRect(windowSurface, &scoreOtoczka1, jszary);
    wypiszNumer(wynik, (WIDTH + n*(4*wielkosc2))/2, (HEIGHT + 2*wielkosc2)/2);
    SDL_Rect restartRect = {.x = (WIDTH - 29 * wielkosc2)/2, .y = (HEIGHT - wielkosc2)/2 + 10*wielkosc2, .w = 29*wielkosc2, .h = 7*wielkosc2};
    SDL_Rect menuRect = {.x = (WIDTH - 20 * wielkosc2)/2, .y = (HEIGHT - wielkosc2)/2 + (10*wielkosc2)*2 , .w = 20*wielkosc2, .h = 7*wielkosc2};
    if(inRect(restartRect, x, y))
    {
        SDL_BlitScaled(restartButton2, NULL, windowSurface, &restartRect);
    }
    else
    {
        SDL_BlitScaled(restartButton1, NULL, windowSurface, &restartRect);
    }
    if(inRect(menuRect, x, y))
    {
        SDL_BlitScaled(menuButton2, NULL, windowSurface, &menuRect);
    }
    else
    {
        SDL_BlitScaled(menuButton1, NULL, windowSurface, &menuRect);
    }
}

void drawScene4()
{
    int x,y;
    SDL_GetMouseState(&x, &y);
    SDL_FillRect(windowSurface, NULL, szary);
    SDL_Rect menuRect = {.x = WIDTH - wielkosc2*21, .y = HEIGHT - wielkosc2*8, .w = 20*wielkosc2, .h = 7*wielkosc2};
    SDL_Rect htpRect = {.x = (WIDTH - wielkosc2*33)/2, .y = wielkosc2, .h = wielkosc2*7, .w = wielkosc2*33};
    SDL_Rect upWingRect = {.x = wielkosc4, .y = wielkosc2 + wielkosc2*10};
    SDL_Rect upTextRect = {.x = wielkosc4 + upWing->w, .y = wielkosc2 + wielkosc2*10};
    SDL_Rect leftWingRect = {.x = wielkosc4, .y = wielkosc2 + wielkosc2*10 + upText->h};
    SDL_Rect leftTextRect = {.x = wielkosc4 + leftWing->w, .y = wielkosc2 + wielkosc2*10 + upText->h};
    SDL_Rect rightWingRect = {.x = wielkosc4, .y = wielkosc2 + wielkosc2*10 + upText->h + leftText->h};
    SDL_Rect rightTextRect = {.x = wielkosc4 + rightWing->w, .y = wielkosc2 + wielkosc2*10 + upText->h + leftText->h};
    SDL_Rect downWingRect = {.x = wielkosc4, .y = wielkosc2 + wielkosc2*10 + upText->h + leftText->h + rightText->h};
    SDL_Rect downTextRect = {.x = wielkosc4 + downWing->w, .y = wielkosc2 + wielkosc2*10 + upText->h + leftText->h + rightText->h};
    SDL_Rect spaceWingRect = {.x = wielkosc4, .y = wielkosc2 + wielkosc2*10 + upText->h + leftText->h + rightText->h + downText->h};
    SDL_Rect spaceTextRect = {.x = wielkosc4 + spaceWing->w, .y = wielkosc2 + wielkosc2*10 + upText->h + leftText->h + rightText->h + downText->h};
    SDL_Rect escWingRect = {.x = wielkosc4, .y = wielkosc2 + wielkosc2*10 + upText->h + leftText->h + rightText->h + downText->h + spaceText->h};
    SDL_Rect escTextRect = {.x = wielkosc4 + escWing->w, .y = wielkosc2 + wielkosc2*10 + upText->h + leftText->h + rightText->h + downText->h + spaceText->h};
    SDL_BlitScaled(htpButton1, NULL, windowSurface, &htpRect);
    if(inRect(menuRect, x, y))
    {
        SDL_BlitScaled(menuButton2, NULL, windowSurface, &menuRect);
    }
    else
    {
        SDL_BlitScaled(menuButton1, NULL, windowSurface, &menuRect);
    }
    SDL_BlitSurface(upWing, NULL, windowSurface, &upWingRect);
    SDL_BlitSurface(upText, NULL, windowSurface, &upTextRect);
    SDL_BlitSurface(leftWing, NULL, windowSurface, &leftWingRect);
    SDL_BlitSurface(leftText, NULL, windowSurface, &leftTextRect);
    SDL_BlitSurface(rightWing, NULL, windowSurface, &rightWingRect);
    SDL_BlitSurface(rightText, NULL, windowSurface, &rightTextRect);
    SDL_BlitSurface(downWing, NULL, windowSurface, &downWingRect);
    SDL_BlitSurface(downText, NULL, windowSurface, &downTextRect);
    SDL_BlitSurface(spaceWing, NULL, windowSurface, &spaceWingRect);
    SDL_BlitSurface(spaceText, NULL, windowSurface, &spaceTextRect);
    SDL_BlitSurface(escWing, NULL, windowSurface, &escWingRect);
    SDL_BlitSurface(escText, NULL, windowSurface, &escTextRect);
}

void drawScene5()
{
    int x,y;
    SDL_GetMouseState(&x, &y);
    SDL_FillRect(windowSurface, NULL, szary);
    SDL_Rect menuRect = {.x = WIDTH - wielkosc2*21, .y = HEIGHT - wielkosc2*8, .w = 20*wielkosc2, .h = 7*wielkosc2};
    SDL_Rect scoresRect = {.x = (WIDTH - wielkosc2*28)/2, .y = wielkosc2, .h = wielkosc2*7, .w = wielkosc2*28};
    SDL_BlitScaled(scoresButton1, NULL, windowSurface, &scoresRect);
    if(inRect(menuRect, x, y))
    {
        SDL_BlitScaled(menuButton2, NULL, windowSurface, &menuRect);
    }
    else
    {
        SDL_BlitScaled(menuButton1, NULL, windowSurface, &menuRect);
    }
    for(int i = 5; i >= 0; i--)
    {
        wypiszNumer(wyniki[i], WIDTH - wielkosc2*5 , (wielkosc2 * 7) * (5-i) + wielkosc2*9);
    }
}

#endif
