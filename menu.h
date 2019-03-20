#ifndef MENU_H_INCLUDE
#define MENU_H_INCLUDE

typedef struct {
	SDL_Surface *img;
	SDL_Rect pos;
}bg;



typedef struct {
	SDL_Surface *img,*imgover,*imgclick;
	SDL_Rect pos;
	int soundover,soundclick;

}btn;

void init(SDL_Surface* *screen,Mix_Music* *MenuMusic,Mix_Chunk* *btnMenu,bg *menu, btn* buttons);
int menug(SDL_Surface* screen,Mix_Music* MenuMusic,Mix_Chunk* btnMenu,bg menu,btn* buttons);
#endif