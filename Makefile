all: main clean

main: main.o arvore.o loja.o
	gcc -o main main.o arvore.o loja.o

loja.o: loja.c loja.h arvorebinaria.h
	gcc -o loja.o -c loja.c

arvore.o: arvorebinaria.c arvorebinaria.h
	gcc -o arvore.o -c arvorebinaria.c

main.o: main.c arvorebinaria.h loja.h
	gcc -o main.o -c main.c

clean:
	rm *.o
