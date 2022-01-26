all:main

main:
	gcc app.c board.c gameloop.c netcode.c -o app.exe -lm
	./app.exe