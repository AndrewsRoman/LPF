
all:	
	
	gcc -Wall -g -std=c90 -c -Wall libpilha.c
	gcc -Wall -g -std=c90 -c -Wall liblista.c
	gcc -Wall -g -std=c90 -c -Wall libfila.c
	gcc -Wall -g -std=c90 -c -Wall testa_pilha.c
	gcc -Wall -g -std=c90 -c -Wall testa_fila.c
	gcc -Wall -g -std=c90 -c -Wall testa_lista.c
	gcc -Wall -g -std=c90 testa_pilha.o libpilha.o -o testa_pilha
	gcc -Wall -g -std=c90 testa_lista.o liblista.o -o testa_lista
	gcc -Wall -g -std=c90 testa_fila.o libfila.o -o testa_fila
 
run:
	./testa_pilha
	./testa_fila
	./testa_lista
	

clean:
	rm *.o testa_pilha testa_lista testa_fila
	
	
