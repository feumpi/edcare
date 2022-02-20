output: cuidador.o edcare.o idoso.o leitura.o lista.o main.o
	gcc cuidador.o edcare.o idoso.o leitura.o lista.o main.o -o main -lm -Wall

cuidador.o: cuidador.c cuidador.h
	gcc -c cuidador.c 

edcare.o: edcare.c edcare.h
	gcc -c edcare.c

idoso.o: idoso.c idoso.h
	gcc -c idoso.c

leitura.o: leitura.c leitura.h
	gcc -c leitura.c

lista.o: lista.c lista.h
	gcc -c lista.c

main.o: main.c
	gcc -c main.c

clean:
	rm *.o main