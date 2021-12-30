all: build

build:
	gcc -Iinclude -Iinclude/sdl2 -Iinclude/headers -Llib -o build src/*.c -lmingw32 -lSDL2main -lSDL2 -lSDL2_image -g

clean:
	del build.exe
	