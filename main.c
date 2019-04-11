#include <stdlib.h>
#include <stdio.h>
#include <SDL/SDL.h>
#include <SDL/SDL_image.h>
#include <SDL/SDL_ttf.h>
#include <string.h>
#include "fonction.h"

int main()
{
int resultat;

Enigme e,tmp;
SDL_Init(SDL_INIT_VIDEO);
TTF_Init();
TTF_Font *font=TTF_OpenFont("seoepr.ttf",20);
SDL_Surface *ecran;
SDL_Surface *Cadre;

e=init(); // initialisation de l enigme
afficher_Enigme(ecran, Cadre, tmp); // affichage de l enigme generee
resultat = Enigme2(); // 0 si juste | 1 si fausse

}
