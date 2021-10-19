
#ifndef ARCADE_H_
#define ARCADE_H_

#define NACIONALIDAD_LEN 100
#define TIPO_MONO	1
#define TIPO_ESTEREO 2
#define JUEGO_LEN 63

typedef struct {
	char nacionalidad[NACIONALIDAD_LEN];
	int tipoDeSonido;
	int cantidadDeJugadores;
	int capacidadMaximaFichas;
	int idSalon;
	char nombreJuego[JUEGO_LEN];
	int idArcade;
	int isEmpty;
}Arcade;

int inicializarArcades(Arcade* listaArcades,int lenListaArcades);
int buscarLugarVacioArcades(Arcade* listaArcades,int lenListaArcades);
int generadorDeIDArcade(void);
int altaArcade(Arcade* listaArcades,int lenListaArcades, int indiceVacio, int idDeSalonACargar);
int altaForzadaArcade(Arcade* listaArcades,int lenListaArcades, int indiceF, char nacionalidadF[], int tipoDeSonidoF,int cantidadDeJugadoresF,int capacidadMaximaFichasF,int idSalonF,char nombreJuegoF[],int idArcadeF,int isEmptyF);

int buscarIdArcade(Arcade* listaArcades,int lenListaArcades, int idBuscado);
int modificarArcade(Arcade* listaArcades,int lenListaArcades, int indiceAModificar, int opcionElegida);

int imprimirArcades(Arcade* listaArcades,int lenListaArcades);
int imprimirUnArcade(Arcade* listaArcades,int indiceArcadeAImprimir);
int bajaArcade(Arcade* listaArcades,int lenListaArcades, int indiceBuscadoArcade);
int bajaArcadePorSalon(Arcade* listaArcades,int lenListaArcades, int idSalonAEliminar);

#endif /* ARCADE_H_ */
