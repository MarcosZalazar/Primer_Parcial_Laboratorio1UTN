#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "utn.h"
#include "Arcade.h"


int inicializarArcades(Arcade* listaArcades,int lenListaArcades)
{
	int retorno = -1;
	int i;

	if(listaArcades != NULL && lenListaArcades > 0)
	{
		retorno = 0;
		for(i=0;i<lenListaArcades;i++)
		{
			listaArcades[i].isEmpty = 1;
		}
	}
	return retorno;
}

int buscarLugarVacioArcades(Arcade* listaArcades,int lenListaArcades)
{
	int retorno = -1;
	int i;

	if(listaArcades != NULL && lenListaArcades > 0)
	{
		for(i=0;i<lenListaArcades;i++)
		{
			if(listaArcades[i].isEmpty == 1)
			{
				retorno = i;
				break;
			}
		}
	}
	return retorno;
}

int generadorDeIDArcade(void)
{
	static int contadorId=0;

	return contadorId++;
}

int altaArcade(Arcade* listaArcades,int lenListaArcades, int indiceVacio, int idDeSalonACargar)
{
	int retorno=-1;
	Arcade bufferArcade;

	if(listaArcades!=NULL && lenListaArcades>0 && indiceVacio< lenListaArcades && indiceVacio>=0 && idDeSalonACargar>=0)
	{
		if(utn_getChar(bufferArcade.nacionalidad,"\nIngrese la nacionalidad: ","\nError",NACIONALIDAD_LEN,3)==0 &&
		   utn_getNumeroInt(&bufferArcade.tipoDeSonido,"\nIngrese el tipo de sonido (MONO:1 STEREO:2)", "\nError",1,2,3)==0 &&
		   utn_getNumeroInt(&bufferArcade.cantidadDeJugadores,"\nIngrese la cantidad de jugadores(1 a 4)", "\nError",1,4,3)==0 &&
		   utn_getNumeroInt(&bufferArcade.capacidadMaximaFichas,"\nIngrese la capacidad máxima de fichas", "\nError",1,100000,3)==0 &&
		   utn_getDescripcion(bufferArcade.nombreJuego,"\nIngrese el nombre del juego: ","\nError",JUEGO_LEN,3)==0)
		{
			bufferArcade.idSalon=idDeSalonACargar;
			bufferArcade.idArcade=generadorDeIDArcade();
			bufferArcade.isEmpty=0;
			listaArcades[indiceVacio]=bufferArcade;
			retorno=0;
		}
	}
	return retorno;
}

int altaForzadaArcade(Arcade* listaArcades,int lenListaArcades, int indiceF, char nacionalidadF[], int tipoDeSonidoF,int cantidadDeJugadoresF,int capacidadMaximaFichasF,int idSalonF,char nombreJuegoF[],int idArcadeF,int isEmptyF)
{
	int retorno=-1;
	Arcade bufferArcade;

	if(listaArcades!=NULL && lenListaArcades>0 && indiceF< lenListaArcades && indiceF>=0 && nacionalidadF!=NULL && (tipoDeSonidoF==1||tipoDeSonidoF==2) && idSalonF>=0 && nombreJuegoF!=NULL && idArcadeF>=0 && (isEmptyF==0||isEmptyF==1))
	{
		strncpy(listaArcades[indiceF].nacionalidad,nacionalidadF,NACIONALIDAD_LEN);
		bufferArcade.tipoDeSonido=tipoDeSonidoF;
		bufferArcade.cantidadDeJugadores=cantidadDeJugadoresF;
		bufferArcade.capacidadMaximaFichas=capacidadMaximaFichasF;
		bufferArcade.idSalon=idSalonF;
		strncpy(bufferArcade.nombreJuego,nombreJuegoF,JUEGO_LEN);
		bufferArcade.idArcade=idArcadeF;
		bufferArcade.isEmpty=isEmptyF;
		listaArcades[indiceF]=bufferArcade;
		retorno=0;
	}
	return retorno;
}

int buscarIdArcade(Arcade* listaArcades,int lenListaArcades, int idBuscado)
{
	int retorno = -1;
	int i;

	if(listaArcades != NULL && lenListaArcades > 0 && idBuscado >= 0)
	{
		retorno = -2;
		for(i=0;i<lenListaArcades;i++)
		{
			if(listaArcades[i].idArcade == idBuscado)
			{
				retorno = i;
				break;
			}
		}
	}
	return retorno;
}


int modificarArcade(Arcade* listaArcades,int lenListaArcades, int indiceAModificar, int opcionElegida)
{
	int retorno=-1;
	Arcade bufferArcade;

	if(listaArcades!= NULL && lenListaArcades >=0 && indiceAModificar >=0 && (opcionElegida==11 ||opcionElegida==12) && listaArcades[indiceAModificar].isEmpty==0)
	{
		switch(opcionElegida)
		{
			case 11:
				if(utn_getNumeroInt(&bufferArcade.cantidadDeJugadores,"\nIngrese la cantidad de jugadores", "\nCantidad inválida",1,4,3)==0)
				{
					listaArcades[indiceAModificar].cantidadDeJugadores=bufferArcade.cantidadDeJugadores;
					retorno=0;
				}
				break;
			case 12:
				if(utn_getDescripcion(bufferArcade.nombreJuego,"\nIngrese el nuevo nombre del juego","\nNombre inválido",JUEGO_LEN,3)==0)
				{
					strncpy(listaArcades[indiceAModificar].nombreJuego,bufferArcade.nombreJuego,sizeof(listaArcades[indiceAModificar].nombreJuego));
					retorno=0;
				}
				break;
		}
	}
	return retorno;
}


int bajaArcade(Arcade* listaArcades,int lenListaArcades, int indiceBuscadoArcade)
{
	int retorno = -1;

	if(listaArcades != NULL && lenListaArcades > 0 && indiceBuscadoArcade >= 0 && listaArcades[indiceBuscadoArcade].isEmpty == 0)
	{
		listaArcades[indiceBuscadoArcade].isEmpty = 1;
		retorno = 0;
	}
	return retorno;
}

int bajaArcadePorSalon(Arcade* listaArcades,int lenListaArcades, int idSalonAEliminar)
{
	int retorno = -1;
	int i;

	if(listaArcades != NULL && lenListaArcades > 0 && idSalonAEliminar >= 0)
	{
		for(i=0;i<lenListaArcades;i++)
		{
			if(listaArcades[i].idSalon == idSalonAEliminar && listaArcades[i].isEmpty==0)
			{
				listaArcades[i].isEmpty = 1;
				retorno = 0;
			}
		}
	}
	return retorno;
}


int imprimirArcades(Arcade* listaArcades,int lenListaArcades)
{
	int retorno = -1;
	int i;

	if(listaArcades != NULL && lenListaArcades >=0)
	{
		retorno = 0;
		for(i=0;i<lenListaArcades;i++)
		{
			if(listaArcades[i].isEmpty==0)
			{
				printf("\nID del arcade: %d - Tipo de sonido: %d - Cantidad de jugadores: %d - Capacidad máxima de fichas: %d - Nombre del juego: %s - Id del Salon: %d\n", listaArcades[i].idArcade,listaArcades[i].tipoDeSonido,listaArcades[i].cantidadDeJugadores,listaArcades[i].capacidadMaximaFichas,listaArcades[i].nombreJuego,listaArcades[i].idSalon);
			}
		}
	}
	return retorno;
}

int imprimirUnArcade(Arcade* listaArcades,int indiceArcadeAImprimir)
{
	int retorno = -1;

	if(listaArcades != NULL && indiceArcadeAImprimir>=0 && listaArcades[indiceArcadeAImprimir].isEmpty==0)
	{
		retorno = 0;
		printf("\nID del arcade: %d - Tipo de sonido: %d - Cantidad de jugadores: %d - Capacidad máxima de fichas: %d - Nombre del juego: %s - Id del Salon: %d\n", listaArcades[indiceArcadeAImprimir].idArcade,listaArcades[indiceArcadeAImprimir].tipoDeSonido,listaArcades[indiceArcadeAImprimir].cantidadDeJugadores,listaArcades[indiceArcadeAImprimir].capacidadMaximaFichas,listaArcades[indiceArcadeAImprimir].nombreJuego,listaArcades[indiceArcadeAImprimir].idSalon);
	}
	return retorno;
}
