#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "utn.h"
#include "Juego.h"

int inicializarJuegos(Juego* listaJuegos,int lenListaJuegos)
{
	int retorno = -1;
	int i;

	if(listaJuegos != NULL && lenListaJuegos > 0)
	{
		retorno = 0;
		for(i=0;i<lenListaJuegos;i++)
		{
			listaJuegos[i].isEmpty = 1;
		}
	}
	return retorno;
}

int estaElJuegoEnLaLista(Juego* listaJuegos,int lenListaJuegos,char juegoAEvaluar[])
{
	int retorno = 0;
	int i;

	if(listaJuegos != NULL && lenListaJuegos > 0 && juegoAEvaluar != NULL)
	{
		for(i=0;i<lenListaJuegos;i++)
		{
			if(listaJuegos[i].isEmpty==0)
			{
				if(strncmp(listaJuegos[i].nombreJuego,juegoAEvaluar,JUEGO_LEN)==0)
				{
					retorno = 1;
					break;
				}
			}
		}
	}
	return retorno;
}
