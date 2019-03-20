#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "/usr/include/SDL/SDL.h"
#include "/usr/include/SDL/SDL_image.h"
#include "/usr/include/SDL/SDL_mixer.h"
#include "/usr/include/SDL/SDL_ttf.h"
#include "menu.h"

void init(SDL_Surface* *screen,Mix_Music* *MenuMusic,Mix_Chunk* *btnMenu,bg *menu,btn* buttons)
{
	if(SDL_Init(SDL_INIT_EVERYTHING) != 0){
		printf("Unable to init SDL: %s\n", SDL_GetError());
		exit(EXIT_FAILURE);
	}

	*screen = SDL_SetVideoMode(950,700,32,SDL_HWSURFACE | SDL_DOUBLEBUF);
	if(*screen == NULL){
		printf("Unable to Set video Mode : %s\n", SDL_GetError());
		exit(EXIT_FAILURE);
	}


	menu->img = SDL_LoadBMP("background.bmp");
	if(menu->img == NULL){
		printf("Unable to LOAD background : %s\n", SDL_GetError());
		exit(EXIT_FAILURE);
	}
	menu->pos.x = 0;
	menu->pos.y = 0;

if(Mix_OpenAudio(44100,MIX_DEFAULT_FORMAT,MIX_DEFAULT_CHANNELS,1024)==-1)
{
   printf("%s",Mix_GetError());
}


	*MenuMusic = Mix_LoadMUS("resource/soundtrack.mp3");


	*btnMenu = Mix_LoadWAV("resource/click.wav");
	buttons[0].img = IMG_Load("play.png");
	buttons[0].imgover = IMG_Load("play1.png");
	buttons[0].imgclick = IMG_Load("play2.png");
	if((buttons[0].img == NULL)|| (buttons[0].imgover == NULL) || (buttons[0].imgclick == NULL)){
		printf("Unable to LOAD buttons 0 : %s\n", SDL_GetError());
		exit(EXIT_FAILURE);
	}
	buttons[0].pos.x = 40;
	buttons[0].pos.y = 170;

	buttons[0].soundover = 0;
	buttons[0].soundclick = 0;

	buttons[1].img = IMG_Load("options.png");
	buttons[1].imgover = IMG_Load("options1.png");
	buttons[1].imgclick = IMG_Load("option2.png");
	if((buttons[1].img == NULL) || (buttons[1].imgover == NULL) || (buttons[1].imgclick) == NULL){
		printf("Unable to LOAD buttons 0 : %s\n", SDL_GetError());
		exit(EXIT_FAILURE);
	}
	buttons[1].pos.x = 40;
	buttons[1].pos.y = 270;

	buttons[1].soundover = 0;
	buttons[1].soundclick = 0;


	buttons[2].img = IMG_Load("credits.png");
	buttons[2].imgover = IMG_Load("credits1.png");
	buttons[2].imgclick = IMG_Load("credit2.png");
	if((buttons[2].img == NULL)|| (buttons[2].imgover == NULL)){
		printf("Unable to LOAD buttons 0 : %s\n", SDL_GetError());
		exit(EXIT_FAILURE);
	}
	buttons[2].pos.x = 40;
	buttons[2].pos.y = 370;

	buttons[2].soundover = 0;
	buttons[2].soundclick = 0;

	buttons[3].img = IMG_Load("exit.png");
	buttons[3].imgover = IMG_Load("exit1.png");
	buttons[3].imgclick = IMG_Load("exit2.png");
	if((buttons[3].img == NULL)|| (buttons[3].imgover == NULL)){
		printf("Unable to LOAD buttons 0 : %s\n", SDL_GetError());
		exit(EXIT_FAILURE);
	}
	buttons[3].pos.x = 40;
	buttons[3].pos.y = 470;

	buttons[3].soundover = 0;
	buttons[3].soundclick = 0;
	

}

int over(int x,int y,SDL_Rect pos){
	return (x > pos.x && x < pos.x + pos.w && y > pos.y && y < pos.y + pos.h);
}

int menug(SDL_Surface* screen,Mix_Music* MenuMusic,Mix_Chunk* btnMenu,bg menu,btn* buttons){
	Uint8 p;
	int choix = -1,x,y;
	SDL_Event event;
	
	do{
		SDL_PumpEvents();
		p = SDL_GetMouseState(&x,&y);
		SDL_BlitSurface(menu.img,NULL,screen,&menu.pos);

//continuer=0;

		for(int i = 0 ;i < 4;i++){


switch(event.type)
{
	case SDL_KEYDOWN:
switch (event.key.keysym.sym)
{
	case SDLK_UP:
//Mix_PlayChannel(1,button);
    if(buttons[i].soundover==3)
        buttons[i].soundover=1;
     else
         buttons[i].soundover++;
break;}
case SDLK_DOWN:
//Mix_PlayChannel(1,button,0);
if(buttons[i].soundover==1)
buttons[i].soundover=3;
else
 buttons[i].soundover--;
break;}
//case SDLK_RETURN:





			if(!over(x,y,buttons[i].pos)){
				SDL_BlitSurface(buttons[i].img,NULL,screen,&buttons[i].pos);
				buttons[i].soundover = 0;
	            buttons[i].soundclick = 0;

			}else{
				SDL_BlitSurface(buttons[i].imgover,NULL,screen,&buttons[i].pos);
				if(!buttons[i].soundover){
						Mix_PlayChannel(-1,btnMenu,0);
						buttons[i].soundover = 1;
				}
				if (SDL_GetMouseState(NULL, NULL) & SDL_BUTTON(SDL_BUTTON_LEFT)) {
					if (SDL_BUTTON_LEFT)
					{
						SDL_BlitSurface(buttons[i].imgclick,NULL,screen,&buttons[i].pos);
					}
					if(!buttons[i].soundclick){
						Mix_PlayChannel(-1,btnMenu,0);
						buttons[i].soundclick = 1;

					}
					choix = i+1;
				
				}

			}

		}
		SDL_Flip(screen);
	}while(choix == -1);
	return choix;
}



int redirection(SDL_Surface* screen,Mix_Music* MenuMusic,Mix_Chunk* btnMenu,bg menu,btn* buttons)
{
	Uint8 p;
	int choix = -1,x,y;
	int i=3;
   SDL_Event event;
	do{
		SDL_PumpEvents();
		p = SDL_GetMouseState(&x,&y);
		SDL_BlitSurface(menu.img,NULL,screen,&menu.pos);
		SDL_WaitEvent(&event);


			if(!over(x,y,buttons[i].pos)){
				SDL_BlitSurface(buttons[i].img,NULL,screen,&buttons[i].pos);
				buttons[i].soundover = 0;
	            buttons[i].soundclick = 0;

			}else{
				SDL_BlitSurface(buttons[i].imgover,NULL,screen,&buttons[i].pos);
				if(!buttons[i].soundover){
						Mix_PlayChannel(-1,btnMenu,0);
						buttons[i].soundover = 1;
				}
				if (SDL_GetMouseState(NULL, NULL) & SDL_BUTTON(SDL_BUTTON_LEFT)) {
					if (SDL_BUTTON_LEFT)
					{
						SDL_BlitSurface(buttons[i].imgclick,NULL,screen,&buttons[i].pos);
					}
					if(!buttons[i].soundclick){
						Mix_PlayChannel(-1,btnMenu,0);
						buttons[i].soundclick = 1;

					}
					choix = i+1;
				
				}

			}

		
		SDL_Flip(screen);
	}while(choix == -1);
	return choix;
}

