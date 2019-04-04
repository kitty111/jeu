enigme2:fonction.o main.o
		gcc fonction.o main.o -o enigme2 -g -lSDL -lSDL_image -lSDL_mixer -lSDL_ttf

fonction.o:fonction.c
		gcc -c fonction.c -g -lSDL -lSDL_image -lSDL_mixer -lSDL_ttf

main.o:main.c
		gcc -c main.c -g -lSDL -lSDL_image -lSDL_mixer -lSDL_ttf