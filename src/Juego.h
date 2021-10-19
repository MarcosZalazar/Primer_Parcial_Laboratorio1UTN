
#ifndef JUEGO_H_
#define JUEGO_H_

#define JUEGO_LEN 63

typedef struct {
	char nombreJuego[JUEGO_LEN];
	int isEmpty;
}Juego;

int inicializarJuegos(Juego* listaJuegos,int lenListaJuegos);
int estaElJuegoEnLaLista(Juego* listaJuegos,int lenListaJuegos,char juegoAEvaluar[]);


#endif /* JUEGO_H_ */
