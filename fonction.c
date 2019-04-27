#include <stdlib.h>
#include <stdio.h>
#include <SDL/SDL.h>
#include <SDL/SDL_image.h>
#include "fonction.h"

int Enigme2 ()
{
SDL_Surface *ecran = NULL, *fond = NULL;
    SDL_Rect positionFond ;
    SDL_Event event;
    int answer,continuer=1,nb=0;
    positionFond.x = 0;
    positionFond.y = 0;

    
    SDL_Init(SDL_INIT_VIDEO);

    ecran = SDL_SetVideoMode(900, 1140, 32, SDL_HWSURFACE | SDL_DOUBLEBUF);
    SDL_WM_SetCaption("Enigme 1", NULL);

    fond= IMG_Load("Enigme 1.png");
    SDL_BlitSurface(fond,NULL,ecran,&positionFond);
    SDL_Flip(ecran);
    
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
        case SDLK_UP: /* si appui sur flech haut */
            fond= IMG_Load("Good.png");
            SDL_BlitSurface(fond,NULL,ecran,&positionFond);
SDL_Flip(ecran);

SDL_Delay(2000);
 continuer = 0;
           
            break;

        case SDLK_DOWN: /* Si appui sur fleche bas */
            fond= IMG_Load("False.png");
            SDL_BlitSurface(fond,NULL,ecran,&positionFond);
SDL_Flip(ecran);

SDL_Delay(2000);

    fond= IMG_Load("Enigme 1.png");
    SDL_BlitSurface(fond,NULL,ecran,&positionFond);
    SDL_Flip(ecran);
            continuer = 1;
            nb++;
            break;

        case SDLK_RIGHT: /* Si appui sur fleche droit */
            fond= IMG_Load("False.png");
            SDL_BlitSurface(fond,NULL,ecran,&positionFond);
SDL_Flip(ecran);

SDL_Delay(2000);

    fond= IMG_Load("Enigme 1.png");
    SDL_BlitSurface(fond,NULL,ecran,&positionFond);
    SDL_Flip(ecran);
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

