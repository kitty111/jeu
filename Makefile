jeu:menu.o main.o
	gcc menu.o main.o -o jeu -g -lSDL -lSDL_image -lSDL_mixer -lSDL_ttf

menu.o:resource/menu.c
		gcc -c resource/menu.c -g -lSDL -lSDL_image -lSDL_mixer -lSDL_ttf

main.o:main.c
		gcc -c main.c -g -lSDL -lSDL_image -lSDL_mixer -lSDL_ttf