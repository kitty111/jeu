prog:scroll.o
		gcc scroll.o -o prog -g -lSDL -lSDL_image -lSDL_mixer -lSDL_ttf
scroll.o:scroll.c
		gcc -c scroll.c -g -lSDL -lSDL_image -lSDL_mixer -lSDL_ttf
