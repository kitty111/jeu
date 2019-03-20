#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "/usr/include/SDL/SDL.h"
#include "/usr/include/SDL/SDL_image.h"
#include "/usr/include/SDL/SDL_mixer.h"
#include "/usr/include/SDL/SDL_ttf.h"
#include "resource/menu.h"
int main()
{
	SDL_Surface *screen;
	Mix_Music *MenuMusic;
	Mix_Chunk *btnMenu;
	btn buttons[10];
	bg menu;
	int done = 0, choix;
	init(&screen,&MenuMusic,&btnMenu,&menu, buttons);
	/*TTF_Init();
	SDL_Surface *message=NULL;
	char *text="Copyrights CyberPanteya";
	TTF_Font*font=NULL;
	SDL_Color textColor={255,165,0};
	font=TTF_OpenFont("arial.ttf",72);
	SDL_Rect posText;
	posText.x=40;
	posText.y=370;
	posText.w = 100; // controls the width of the rect
    posText.h = 100;*/
	//SDL_BlitSurface(message,NULL,screen,&posText);

  //SDL_BlitSurface(message,NULL,screen,NULL); 
	//SDL_Flip(screen);
	Mix_PlayMusic(MenuMusic,-1);
	//SDL_Surface* redirec=SDL_SetVideoMode(950,700,32,SDL_HWSURFACE | SDL_DOUBLEBUF);
	int choix2=0;
	while(!done)
	{
		
		choix = menug(screen,MenuMusic,btnMenu,menu, buttons);



		
		switch(choix){
			case 1:
			choix2=redirection(screen,MenuMusic,btnMenu,menu,buttons);
			//SDL_BlitSurface(message,NULL,screen,&posText);
				break;
			case 2:
			choix2=redirection(screen,MenuMusic,btnMenu,menu,buttons);
			
			//SDL_BlitSurface(message,NULL,screen,&posText);
				break;
			
			case 3:
			choix2=redirection(screen,MenuMusic,btnMenu,menu,buttons);
			
			//SDL_BlitSurface(message,NULL,screen,&posText);
				break;
			case 4:
				{
				


					done = 1;
				/*SDL_BlitSurface(message,NULL,screen,&posText);
				SDL_Flip(screen);*/
				//SDL_Delay(8000);
				break;}
		}

	}
	//SDL_Delay(8000);

	SDL_FreeSurface(screen);
	//SDL_FreeSurface(message); 
	SDL_FreeSurface(menu.img);
	Mix_FreeMusic(MenuMusic);
	Mix_FreeChunk(btnMenu);
	

}