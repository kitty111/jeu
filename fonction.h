#ifndef FONCTION_INCLUDED
#define FONCTION_INCLUDED

typedef struct 
{
    char Question1[200], Answer1[200], Question2[200], Answer2[200], Question3[200], Answer3[200] ;
    SDL_Rect Question1Pos, Answer1Pos, Question2Pos, Answer2Pos, Question3Pos, Answer3Pos;
    TTF_Font *Font;
} Enigme;

void Replace_Hyphen(char *str);
Enigme init();
Enigme Alea(Enigme e);
void afficher_Enigme(SDL_Surface* ecran, SDL_Surface *Cadre, Enigme e);
int Enigme2 ();

 #endif // FONCTION_INCLUDED