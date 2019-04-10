#include <stdlib.h>
#include <stdio.h>
#include <SDL/SDL.h>
#include <SDL/SDL_image.h>
#include <time.h>
#include "fonction.h"

int main()
{
SDL_Init(SDL_INIT_VIDEO);

SDL_Surface *ecran = NULL, *fond = NULL;
    SDL_Rect positionFond ;
    SDL_Event event;
    int resultat;
    positionFond.x = 0;
    positionFond.y = 0;

    resultat=Enigme3(); //1 si elle est fausse  / 0 si elle est juste 



 }