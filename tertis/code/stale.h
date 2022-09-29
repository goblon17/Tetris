#ifndef stale
#define stale

#define GORA "q"
#define DOL "r"
#define LEWO "s"
#define PRAWO "t"
#define SPACJA "w"
#define ESC "m"

int log_10(int n);
int my_compare (const void * a, const void * b);
void przepiszKlocek(int w);
void przepiszWstawianyKlocek(int klocek, int w);
int losujKlocek();
bool inbound(int x, int y);
void pokazPole(int pole, int x, int y, int xShift, int yShift);
void pokazNastepnyKlocek();
void pokazTrzymanyKlocek();
bool sprawdzPozycje(int x, int y, int w);
bool sprawdzPozycjeTrzymanego(int klocek, int x, int y, int w);
void obrot(int w);
bool sprawdzObrot(int x, int y, int w);
void pokazPlansze();
void pokazWstawianyKlocek();
void wpiszDoPlanszy(int x, int y, int w);
int sprawdzTetris();
void wypiszNumer(int numer, int x, int y);
void pokazWynik();
void setup();
void drawScene0();
void drawScene1();
void drawScene2();
void drawScene3();
void drawScene4();
void drawScene5();

void zamien(int * a, int * b);
void silentSetup();
void cleanUp();
void EventHandler0();
void EventHandler1();
void EventHandler2();
void EventHandler3();
void EventHandler4();
void EventHandler5();

bool petla = true;

int SCENE = 1;
int WIDTH = 800;
int HEIGHT = 950;
int wielkosc = 30;
int wielkosc2 = 16;
int wielkosc4 = 8;
int wysokosc = 25;
int szerokosc = 10;

int frameCount = 0;
int predkosc = 60;
int copyPredkosc = 0;

int ** plansza;

int poczatek[2];

int pozycja[2];

int *** klocki;
int wielkosciKlockow[7] = {4,2,3,3,3,3,3};
int ** pomocniczyKlocek;
int ** pomocniczyWstawianyKlocek;

int nastepnyKlocek = 0;
int trzymanyKlocek = 0;
int wstawianyKlocek = 0;

int wynik = 0;
int* wyniki;
int poziom = 1;
int licznikTetris = 0;

FILE* plik;

SDL_Surface* windowSurface = NULL;
SDL_Window* window = NULL;

SDL_Surface* graySpace = NULL;
SDL_Surface* aquaSpace = NULL;
SDL_Surface* blueSpace = NULL;
SDL_Surface* greenSpace = NULL;
SDL_Surface* orangeSpace = NULL;
SDL_Surface* pinkSpace = NULL;
SDL_Surface* redSpace = NULL;
SDL_Surface* yellowSpace = NULL;
SDL_Surface* pausedText = NULL;
SDL_Surface* one = NULL;
SDL_Surface* two = NULL;
SDL_Surface* three = NULL;
SDL_Surface* four = NULL;
SDL_Surface* five = NULL;
SDL_Surface* six = NULL;
SDL_Surface* seven = NULL;
SDL_Surface* eight = NULL;
SDL_Surface* nine = NULL;
SDL_Surface* zero = NULL;
SDL_Surface* logoTetris = NULL;
SDL_Surface* playButton1 = NULL;
SDL_Surface* playButton2 = NULL;
SDL_Surface* htpButton1 = NULL;
SDL_Surface* htpButton2 = NULL;
SDL_Surface* wynikBMP = NULL;
SDL_Surface* scoresButton1 = NULL;
SDL_Surface* scoresButton2 = NULL;
SDL_Surface* menuButton1 = NULL;
SDL_Surface* menuButton2 = NULL;
SDL_Surface* restartButton1 = NULL;
SDL_Surface* restartButton2 = NULL;
SDL_Surface* score = NULL;
SDL_Surface* next = NULL;
SDL_Surface* swapp = NULL;

SDL_Surface* upText = NULL;
SDL_Surface* leftText = NULL;
SDL_Surface* rightText = NULL;
SDL_Surface* downText = NULL;
SDL_Surface* spaceText = NULL;
SDL_Surface* escText = NULL;
SDL_Surface* upWing = NULL;
SDL_Surface* leftWing = NULL;
SDL_Surface* rightWing = NULL;
SDL_Surface* downWing = NULL;
SDL_Surface* spaceWing = NULL;
SDL_Surface* escWing = NULL;

TTF_Font* czcionka = NULL;
TTF_Font* wingdings = NULL;

Uint32 szary;
Uint32 czarny;
Uint32 jszary;

SDL_Color czarnySDL = {.r = 0, .g = 0, .b = 0, .a = 255};

#endif
