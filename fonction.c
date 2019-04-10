#include <stdlib.h>
#include <stdio.h>
#include <SDL/SDL.h>
#include <SDL/SDL_image.h>
#include <time.h>
#include "fonction.h"

int Alea()
{ 
    srand(time(NULL));
    int nbgen=rand()%6+1;    //entre 1-6
    return (nbgen);
}

int Enigme3 ()
{
SDL_Surface *ecran = NULL, *fond = NULL;
    SDL_Rect positionFond ;
    SDL_Event event;
    int answer,continuer=1,nb=0;
    int U=Alea();
    positionFond.x = 0;
    positionFond.y = 0;

    
    SDL_Init(SDL_INIT_VIDEO);

    ecran = SDL_SetVideoMode(900, 1140, 32, SDL_HWSURFACE | SDL_DOUBLEBUF);
    SDL_WM_SetCaption("Enigme 3", NULL);

    fond= IMG_Load("Enigme 3.png");
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
            if (U==6)
            {
                fond= IMG_Load("Good.png");
                SDL_BlitSurface(fond,NULL,ecran,&positionFond);
                SDL_Flip(ecran);
                SDL_Delay(2000);
                continuer = 0;
            }
            else 
            {
                fond= IMG_Load("False.png");
                SDL_BlitSurface(fond,NULL,ecran,&positionFond);
                SDL_Flip(ecran);
                SDL_Delay(2000);
                fond= IMG_Load("Enigme 2.png");
                SDL_BlitSurface(fond,NULL,ecran,&positionFond);
                SDL_Flip(ecran);
                continuer = 1;
                nb++;
            }
           break;

           case SDLK_DOWN: /* si appui sur flech bas */
            if (U!=1 && U!=3 && U!=6)
            {
                fond= IMG_Load("Good.png");
                SDL_BlitSurface(fond,NULL,ecran,&positionFond);
                SDL_Flip(ecran);
                SDL_Delay(2000);
                continuer = 0;
            }
            else 
            {
                fond= IMG_Load("False.png");
                SDL_BlitSurface(fond,NULL,ecran,&positionFond);
                SDL_Flip(ecran);
                SDL_Delay(2000);
                fond= IMG_Load("Enigme 2.png");
                SDL_BlitSurface(fond,NULL,ecran,&positionFond);
                SDL_Flip(ecran);
                continuer = 1;
                nb++;
            }
           break;

           case SDLK_RIGHT: /* si appui sur flech droit */
            if (U==1)
            {
                fond= IMG_Load("Good.png");
                SDL_BlitSurface(fond,NULL,ecran,&positionFond);
                SDL_Flip(ecran);
                SDL_Delay(2000);
                continuer = 0;
            }
            else 
            {
                fond= IMG_Load("False.png");
                SDL_BlitSurface(fond,NULL,ecran,&positionFond);
                SDL_Flip(ecran);
                SDL_Delay(2000);
                fond= IMG_Load("Enigme 2.png");
                SDL_BlitSurface(fond,NULL,ecran,&positionFond);
                SDL_Flip(ecran);
                continuer = 1;
                nb++;
            }
           break;

           case SDLK_LEFT: /* si appui sur flech haut */
            if (U==3)
            {
                fond= IMG_Load("Good.png");
                SDL_BlitSurface(fond,NULL,ecran,&positionFond);
                SDL_Flip(ecran);
                SDL_Delay(2000);
                continuer = 0;
            }
            else 
            {
                fond= IMG_Load("False.png");
                SDL_BlitSurface(fond,NULL,ecran,&positionFond);
                SDL_Flip(ecran);
                SDL_Delay(2000);
                fond= IMG_Load("Enigme 2.png");
                SDL_BlitSurface(fond,NULL,ecran,&positionFond);
                SDL_Flip(ecran);
                continuer = 1;
                nb++;
            }
           break;
    }
}
}
}
}
}