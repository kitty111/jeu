affich:bc.o
		gcc back.o -o prog -g -lSDL -lSDL_image -lSDL_mixer -lSDL_ttf
bc.o:back.c
		gcc -c back.c -g -lSDL -lSDL_image -lSDL_mixer -lSDL_ttf
