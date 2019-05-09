/**
* @file partage.c
*/

#include <stdio.h>
#include <stdbool.h>

#include <stdlib.h>
#include "/usr/include/SDL/SDL_image.h"
#include "/usr/include/SDL/SDL_mixer.h"
#include "/usr/include/SDL/SDL_ttf.h"
#include <string.h>
#include <SDL/SDL_ttf.h>
/**
* @file partage.c
* @brief Testing Program.
* @author hama
* @version 0.1
* @date Apr 01, 2015
*
* Testing program for background scrollilng
*
*/
/**
* @brief To initialize the character .
* @param b the background
* @param url the url of the image
* @return Nothing
*/
void walk_anim(SDL_Surface *anim[])
{



anim[0]=IMG_Load("pics/1.png");
anim[1]=IMG_Load("pics/2.png");
anim[2]=IMG_Load("pics/3.png");
anim[3]=IMG_Load("pics/4.png");
anim[4]=IMG_Load("pics/5.png");
anim[5]=IMG_Load("pics/6.png");
anim[6]=IMG_Load("pics/7.png");




}
/**
* @brief To load the character .
* @param scren the screen
* @param b the background
* @return Nothing
*/

void walk_back(SDL_Surface *anim[])
{

anim[0]=IMG_Load("pics/17.png");
anim[1]=IMG_Load("pics/16.png");
anim[2]=IMG_Load("pics/15.png");
anim[3]=IMG_Load("pics/14.png");
anim[4]=IMG_Load("pics/13.png");
anim[5]=IMG_Load("pics/12.png");
anim[6]=IMG_Load("pics/11.png");


}
/**
* @brief To animate .
* @param scren the screen
* @param b the background
* @return Nothing
*/

int main()
{
 bool b[4]={0,0,0,0};
SDL_Surface*ecran=NULL,*bg=NULL,*pers=NULL,*walk[7];
SDL_Rect pos,pos1,posh,posb ;
int done=1, i=0,j=6;
//ecran=SetVideoMode(2048,297,)
ecran=SDL_SetVideoMode(800,448,32,SDL_HWSURFACE | SDL_DOUBLEBUF);
bg=SDL_LoadBMP("background.bmp");
pos.x=0;
pos.y=0;
posh.x=0;
posh.y=100;
posb.x=0;
posb.y=320;
pos1.x=0;
pos1.y=230;
pers=IMG_Load("img.png");
/*pos.w=ecran;
pos.h=ecran;*/
SDL_BlitSurface(bg,NULL,ecran,&pos);
SDL_BlitSurface(bg,NULL,ecran,&pos1);
SDL_BlitSurface(pers,NULL,ecran,&posh);
SDL_BlitSurface(pers,NULL,ecran,&posb);

SDL_Flip(ecran);

while(done)
{


SDL_Event event;
while(SDL_PollEvent(&event))
{

if(event.type==SDL_QUIT)
{

done=0;
break;
}
switch(event.type)
{

case SDL_KEYDOWN:
{
switch(event.key.keysym.sym)
{
case SDLK_UP:
b[0]=1;
break;
case SDLK_RIGHT:
b[1]=1;
break;

case SDLK_DOWN:
b[2]=1;
break;
case SDLK_LEFT:
b[3]=1;
break;

}

break;
}

case SDL_KEYUP:
{
switch(event.key.keysym.sym)
{
case SDLK_UP:
b[0]=0;
break;
case SDLK_LEFT:
b[1]=0;
break;
case SDLK_DOWN:
b[2]=0;
break;
case SDLK_RIGHT:
b[3]=0;
break;

}

break;
}


}
}
if(b[1])
{
printf("%d",b[1]);
walk_anim(walk);
SDL_BlitSurface(bg,NULL,ecran,&pos1);
SDL_BlitSurface(bg,NULL,ecran,&pos);
SDL_BlitSurface(walk[i],NULL,ecran,&posh);
SDL_BlitSurface(walk[i],NULL,ecran,&posb);
SDL_Flip(ecran);
i++;
posh.x+=10;
posb.x+=10;
SDL_Delay(1000/30);
if(i>=6)
{

i=0;

}

}

if(b[3])
{

walk_back(walk);
SDL_BlitSurface(bg,NULL,ecran,&pos1);
SDL_BlitSurface(bg,NULL,ecran,&pos);
SDL_BlitSurface(walk[j],NULL,ecran,&posh);
SDL_BlitSurface(walk[j],NULL,ecran,&posb);

SDL_Flip(ecran);
j--;
posh.x-=10;
posb.x-=10;
SDL_Delay(1000/30);

if(j==0)
{

j=6;

}

}


}
SDL_QUIT;
}
