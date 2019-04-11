#include <stdlib.h>
#include <stdio.h>
#include <SDL/SDL.h>
#include <SDL/SDL_image.h>
#include <SDL/SDL_ttf.h>
#include <string.h>
#include "fonction.h"


void Replace_Hyphen(char *str) //Remplacer les _ par des espaces (tsahel el khedma bel str)
{
    int i, len = strlen(str);

    for( i = 0; i < len; i++ )
        if( str[i] == '_' )
            str[i] = ' ' ;
}


Enigme init()
{
Enigme E;
sprintf(E.Question1, "");
sprintf(E.Question2, "");
sprintf(E.Question3, "");

sprintf(E.Answer1, "") ;
sprintf(E.Answer2, "") ;
sprintf(E.Answer3, "") ;
TTF_OpenFont("segoepr.ttf", 60);
    E.Question1Pos.x = 0 ;
    E.Question1Pos.y = 0 ;
    E.Question2Pos.x = 0 ;
    E.Question2Pos.y = 0 ;
    E.Question3Pos.x = 0 ;
    E.Question3Pos.y = 0 ;
    E.Answer1Pos.x = 0 ;
    E.Answer1Pos.y = 0 ;
    E.Answer2Pos.x = 0 ;
    E.Answer2Pos.y = 0 ;
    E.Answer3Pos.x = 0 ;
    E.Answer3Pos.y = 0 ;
    return E ;
}


Enigme Alea(Enigme e)
{
    int i = rand() % 3 + 1 ;
    char filename[50];
    sprintf( filename, "enigmes/%d.txt", i);
    FILE *f = fopen(filename, "r");
    fscanf(f, "%s", e.Question1);
    fscanf(f, "%s", e.Question2);
    fscanf(f, "%s", e.Question3);
    fscanf(f, "%s", e.Answer1);
    fscanf(f, "%s", e.Answer2);
    fscanf(f, "%s", e.Answer3);
    Replace_Hyphen(e.Question1 ) ;
    Replace_Hyphen(e.Question2 ) ;
    Replace_Hyphen(e.Question3 ) ;
    Replace_Hyphen(e.Answer1) ;
    Replace_Hyphen(e.Answer2) ;
    Replace_Hyphen(e.Answer3) ;
    fclose(f);
    return e ;
}


void afficher_Enigme(SDL_Surface* ecran, SDL_Surface *Cadre, Enigme e)
{
    SDL_Color couleur = {0, 0, 0} ;
    SDL_Rect CadrePos ;
    SDL_Surface * tmp = TTF_RenderText_Blended("segoepr.tff", e.Question1, couleur);

    CadrePos.x = 0.02 ;
    CadrePos.y = 0.60 ;
    SDL_BlitSurface(Cadre, NULL, ecran, &CadrePos);
    e.Question1Pos.x = ecran->w * 0.07 ;
    e.Question1Pos.y = ecran->h * 0.65 ;
    SDL_BlitSurface(tmp, NULL, ecran, &e.Question1Pos);
    SDL_FreeSurface(tmp);
    tmp = TTF_RenderText_Blended(e.Font, e.Question2, couleur);
    e.Question2Pos.x = ecran->w * 0.07 ;
    e.Question2Pos.y = ecran->h * 0.70 ;
    SDL_BlitSurface(tmp, NULL, ecran, &e.Question2Pos);
    SDL_FreeSurface(tmp);
    tmp = TTF_RenderText_Blended(e.Font, e.Question3, couleur);
    e.Question3Pos.x = ecran->w * 0.07 ;
    e.Question3Pos.y = ecran->h * 0.75 ;
    SDL_BlitSurface(tmp, NULL, ecran, &e.Question3Pos);
    SDL_FreeSurface(tmp);
    tmp = TTF_RenderText_Blended(e.Font, e.Answer1, couleur);
    e.Answer1Pos.x = ecran->w * 0.2 ;
    e.Answer1Pos.y = ecran->h * 0.8 ;
    SDL_BlitSurface(tmp, NULL, ecran, &e.Answer1Pos);
    SDL_FreeSurface(tmp);
    tmp = TTF_RenderText_Blended(e.Font, e.Answer2, couleur);
    e.Answer2Pos.x = ecran->w * 0.2 ;
    e.Answer2Pos.y = ecran->h * 0.85 ;
    SDL_BlitSurface(tmp, NULL, ecran, &e.Answer2Pos);
    SDL_FreeSurface(tmp);
    tmp = TTF_RenderText_Blended(e.Font, e.Answer3, couleur);
    e.Answer3Pos.x = ecran->w * 0.2 ;
    e.Answer3Pos.y = ecran->h * 0.9 ;
    SDL_BlitSurface(tmp, NULL, ecran, &e.Answer3Pos);
    SDL_FreeSurface(tmp);
}


int Enigme2 ()
{
SDL_Surface *ecran = NULL, *fond = NULL;
    SDL_Rect positionFond ;
    Enigme e,tmp;
    SDL_Surface *Cadre;
    SDL_Event event;
    int answer,continuer=1,nb=0;
    positionFond.x = 0;
    positionFond.y = 0;
    SDL_Init(SDL_INIT_VIDEO);
    tmp= Alea(e);
    ecran = SDL_SetVideoMode(900, 1140, 32, SDL_HWSURFACE | SDL_DOUBLEBUF);
    SDL_WM_SetCaption("Enigme 1", NULL);
    afficher_Enigme(&ecran, &Cadre, tmp);
    while (continuer) //tant qu elle ne vaut pas 0
{
    while(SDL_PollEvent(&event))//lors de l appui sur la touche 
 
{
if(event.type ==SDL_QUIT)   
{
continuer=0;
break;
}

switch(event.type)
{
case SDL_QUIT:
continuer=0;
break;
case SDL_KEYDOWN:
{  
 switch(event.key.keysym.sym)
    {
        case SDLK_a: /* si appui sur a */
            fond= IMG_Load("Good.png");
            SDL_BlitSurface(fond,NULL,ecran,&positionFond);
            SDL_Flip(ecran);
            SDL_Delay(2000);
            continuer = 0;
           
            break;

        case SDLK_b: /* Si appui sur b */
            fond= IMG_Load("False.png");
            SDL_BlitSurface(fond,NULL,ecran,&positionFond);
            SDL_Flip(ecran);
            SDL_Delay(2000);
            fond=NULL;
            SDL_BlitSurface(fond,NULL,ecran,&positionFond);
            SDL_Flip(ecran);
            afficher_Enigme(&ecran, &Cadre, tmp);           
            continuer = 1;
            nb++;
            break;

        case SDLK_c: /* Si appui sur c */
            fond= IMG_Load("False.png");
            SDL_BlitSurface(fond,NULL,ecran,&positionFond);
            SDL_Flip(ecran);
            SDL_Delay(2000);
            fond=NULL;
            SDL_BlitSurface(fond,NULL,ecran,&positionFond);
            SDL_Flip(ecran);
            afficher_Enigme(&ecran, &Cadre, tmp);           
            continuer = 1;
            nb++;
            break;
    }
}
}
}
}

    
    return (continuer);
}
