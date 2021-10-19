#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "utn.h"
#include "Salon.h"
#include "Arcade.h"
#include "Juego.h"
#include "Informes.h"

int generarListaDeJuegos(Juego* listaJuegos,int lenListaJuegos,Arcade* listaArcades,int lenListaArcade)
{
	int i;
	int indiceListaJuegos=0;
	int retorno=0;

	inicializarJuegos(listaJuegos,lenListaJuegos);

	for(i=0;i<lenListaArcade;i++)
	{
		if(listaArcades[i].isEmpty==0 && estaElJuegoEnLaLista(listaJuegos,lenListaJuegos,listaArcades[i].nombreJuego)==0 )
		{
			strncpy(listaJuegos[indiceListaJuegos].nombreJuego,listaArcades[i].nombreJuego,JUEGO_LEN);
			listaJuegos[indiceListaJuegos].isEmpty=0;
			indiceListaJuegos++;
		}
	}
	return retorno;
}

int imprimirJuegos(Arcade* listaArcades,int lenListaArcade)
{
	int retorno = -1;
	int i;
	Juego listaDeJuegosAInformar[1000];

	generarListaDeJuegos(listaDeJuegosAInformar,1000,listaArcades,lenListaArcade);

	if(listaDeJuegosAInformar[0].isEmpty==0)
	{
		if(listaArcades != NULL && lenListaArcade > 0)
		{
			retorno = 0;
			printf("\nLista de juegos cargados en el sistema\n\n");

			for(i=0;i<1000;i++)
			{
				if(listaDeJuegosAInformar[i].isEmpty==0)
				{
					printf("%s\n",listaDeJuegosAInformar[i].nombreJuego);
				}
			}
		}
	}
	else
	{
		printf("No hay juegos cargados");
	}
	return retorno;
}

int imprimirListaArcadeConInfoSalon(Arcade* listaArcades,int lenListaArcade,Salon* listaSalones,int lenlistaSalones)
{
	int retorno = -1;
	int i;
	int indiceArraySalones;

	if(listaArcades != NULL && lenListaArcade > 0 && listaSalones != NULL && lenlistaSalones > 0)
	{
		imprimirArcades(listaArcades,lenListaArcade);
		for(i=0;i<lenListaArcade;i++)
		{
			if(listaArcades[i].isEmpty == 0)
			{
				indiceArraySalones=buscarPorIdSalon(listaSalones,lenlistaSalones, listaArcades[i].idArcade);
				printf("\nNombre del salon: %s - Direccion: %s - Tipo de salon: %d\n", listaSalones[indiceArraySalones].nombre,listaSalones[indiceArraySalones].direccion,listaSalones[indiceArraySalones].tipoDeSalon);
				retorno = 0;
			}
		}
	}
	return retorno;
}

int estaElSalonEnLaLista(Salon* listaSalones,int lenlistaSalones,int idAComparar)
{
	int retorno = 0;
	int i;

	if(listaSalones != NULL && lenlistaSalones > 0 && idAComparar >= 0)
	{
		for(i=0;i<lenlistaSalones;i++)
		{
			if(listaSalones[i].isEmpty==0)
			{
				if(listaSalones[i].idSalon==idAComparar)
				{
					retorno = 1;
					break;
				}
			}
		}
	}
	return retorno;
}

int generarListaDeSalones(Salon* listaSalones,int lenlistaSalones,Arcade* listaArcades,int lenListaArcade)
{
	int i;
	int indiceListaSalones=0;
	int retorno=0;

	inicializarSalones(listaSalones,lenlistaSalones);

	for(i=0;i<lenListaArcade;i++)
	{
		if(listaArcades[i].isEmpty==0 && estaElSalonEnLaLista(listaSalones,lenlistaSalones,listaArcades[i].idSalon)==0 )
		{
			listaSalones[indiceListaSalones].idSalon=listaArcades[i].idSalon;
			listaSalones[indiceListaSalones].isEmpty=0;
			indiceListaSalones++;
		}
	}
	return retorno;
}

int getCantidadDeArcadesPorSalon(Arcade* listaArcades,int lenListaArcade,int idSalonBuscado)
{
	int contadorArcades;
	int i;

	contadorArcades=0;

	if(listaArcades != NULL && lenListaArcade > 0 && idSalonBuscado >= 0)
	{
		for(i=0;i<lenListaArcade;i++)
		{
			if(listaArcades[i].idSalon == idSalonBuscado && listaArcades[i].isEmpty == 0)
			{
				contadorArcades++;
			}
		}
	}
	return contadorArcades;
}

int informeSalonesMasdeCuatroArcades(Arcade* listaArcades,int lenListaArcade,Salon* listaSalones,int lenlistaSalones)
{
	int retorno = -1;
	int i;
	int cantArcades;
	int auxiliarIndiceSalon;
	Salon listaIrrepetibleSalones[1000];

	generarListaDeSalones(listaIrrepetibleSalones,1000,listaArcades,lenListaArcade);


	if(listaIrrepetibleSalones[0].isEmpty==0)
	{
		if(listaArcades != NULL && lenListaArcade >=0 && listaSalones != NULL && lenlistaSalones >=0)
		{
			for(i=0;i<1000;i++)
			{
				cantArcades=getCantidadDeArcadesPorSalon(listaArcades,lenListaArcade,listaIrrepetibleSalones[i].idSalon);
				auxiliarIndiceSalon=buscarPorIdSalon(listaSalones,lenlistaSalones, listaIrrepetibleSalones[i].idSalon);
				if(cantArcades>4)
				{
					printf("\nId del salon: %d - Nombre: %s Direccion: %s Tipo de salon: %d\n", listaIrrepetibleSalones[i].idSalon,listaSalones[auxiliarIndiceSalon].nombre,listaSalones[auxiliarIndiceSalon].direccion,listaSalones[auxiliarIndiceSalon].tipoDeSalon);
				}
			}
		}

	}
	else
	{
		printf("No hay salones cargados");
	}
	return retorno;
}

int informeArcadeParaMasdeDosJugadores(Arcade* listaArcades,int lenListaArcade,Salon* listaSalones,int lenlistaSalones)
{
	int retorno = -1;
	int i;
	int auxiliarIndiceSalonAinformar;

	if(listaArcades != NULL && lenListaArcade > 0 && listaSalones != NULL && lenlistaSalones > 0)
	{
		printf("\nListado de arcades para mas de 2 jugadores\n\n");
		for(i=0;i<lenListaArcade;i++)
		{
			if(listaArcades[i].isEmpty == 0 && listaArcades[i].cantidadDeJugadores > 2)
			{
				retorno = 0;
				auxiliarIndiceSalonAinformar=buscarPorIdSalon(listaSalones,lenlistaSalones, listaArcades[i].idSalon);
				printf("\nID Arcade: %d - Cantidad de jugadores: %d - Nombre del juego: %s - Nombre del salón: %s\n",listaArcades[i].idArcade,listaArcades[i].cantidadDeJugadores,listaArcades[i].nombreJuego,listaSalones[auxiliarIndiceSalonAinformar].nombre);
			}
		}
	}
	return retorno;
}

int informeCompletodeSalon(Arcade* listaArcades,int lenListaArcade,Salon* listaSalones,int lenlistaSalones,int idSalonAInformar)
{
	int retorno = -1;
	int cantArcades;
	int auxiliarIndiceSalonAinformar;

	if(listaArcades != NULL && lenListaArcade>=0 && listaSalones != NULL && idSalonAInformar>=0)
	{
		auxiliarIndiceSalonAinformar=buscarPorIdSalon(listaSalones,lenlistaSalones,idSalonAInformar);

		if(listaSalones[auxiliarIndiceSalonAinformar].isEmpty==0)
		{
			retorno = 0;
			cantArcades=getCantidadDeArcadesPorSalon(listaArcades,lenListaArcade,idSalonAInformar);
			printf("\nID del salon: %d - Nombre:  %s - Tipo: %d - Direccion: %s - Cantidad de arcades: %d\n", listaSalones[auxiliarIndiceSalonAinformar].idSalon,listaSalones[auxiliarIndiceSalonAinformar].nombre,listaSalones[auxiliarIndiceSalonAinformar].tipoDeSalon,listaSalones[auxiliarIndiceSalonAinformar].direccion,cantArcades);
		}
	}
	return retorno;
}

int informeArcadesPorSalon(Arcade* listaArcades,int lenListaArcade,Salon* listaSalones,int lenlistaSalones,int idSalonAInformar)
{
	int retorno = -1;
	int i;
	int auxiliarIndiceSalonAinformar;

	if(listaArcades != NULL && lenListaArcade>=0 && listaSalones != NULL && idSalonAInformar>=0 && idSalonAInformar>=0)
	{
		auxiliarIndiceSalonAinformar=buscarPorIdSalon(listaSalones,lenlistaSalones,idSalonAInformar);
		printf("\nID del salon: %d - Nombre:  %s - Tipo: %d \n\n", listaSalones[auxiliarIndiceSalonAinformar].idSalon,listaSalones[auxiliarIndiceSalonAinformar].nombre,listaSalones[auxiliarIndiceSalonAinformar].tipoDeSalon);
		printf("Listado de arcades del salon\n");
		for(i=0;i<lenListaArcade;i++)
		{
			if(listaArcades[i].isEmpty == 0 && listaArcades[i].idSalon == idSalonAInformar)
			{
				retorno = 0;
				printf("\nID del arcade: %d - Tipo de sonido: %d - Cantidad de jugadores: %d - Capacidad máxima de fichas: %d - Nombre del juego: %s\n", listaArcades[i].idArcade,listaArcades[i].tipoDeSonido,listaArcades[i].cantidadDeJugadores,listaArcades[i].capacidadMaximaFichas,listaArcades[i].nombreJuego);
			}

		}
	}
	return retorno;
}

int informeSalonConMasArcades(Arcade* listaArcades,int lenListaArcade,Salon* listaSalones,int lenlistaSalones)
{
	int retorno = -1;
	int i;
	int maximoArcades;
	int idMaximoArcades;
	int cantidadAComparar;
	Salon listaDeSalonesMasArcades[1000];

	generarListaDeSalones(listaDeSalonesMasArcades,1000,listaArcades,lenListaArcade);

	if(listaDeSalonesMasArcades[0].isEmpty==0)
	{
		if(listaArcades != NULL && lenListaArcade > 0)
		{
			maximoArcades=getCantidadDeArcadesPorSalon(listaArcades,lenListaArcade,listaDeSalonesMasArcades[0].idSalon);
			for(i=0;i<1000;i++)
			{
				if(listaDeSalonesMasArcades[i].isEmpty==0)
				{
					cantidadAComparar=getCantidadDeArcadesPorSalon(listaArcades,lenListaArcade,listaDeSalonesMasArcades[i].idSalon);
					if(cantidadAComparar>maximoArcades)
					{
						maximoArcades=cantidadAComparar;
						idMaximoArcades=listaDeSalonesMasArcades[i].idSalon;
					}
				}
			}
			printf("El salon con mas cantidad de arcades es el siguiente:\n");
			informeCompletodeSalon(listaArcades,lenListaArcade,listaSalones,lenlistaSalones,idMaximoArcades);
			retorno = 0;
		}
	}
	else
	{
		printf("No hay salones cargados");
	}
	return retorno;
}

int informeRecaudacionMaximaPorSalon(Arcade* listaArcades,int lenListaArcade,int idSalonBuscado, float precioFicha)
{
	int i;
	int acumuladorFichas;
	float recaudacionTotal;
	int retorno=-1;

	acumuladorFichas=0;

	if(listaArcades != NULL && lenListaArcade > 0 && idSalonBuscado >= 0 && precioFicha > 0)
	{
		for(i=0;i<lenListaArcade;i++)
		{
			if(listaArcades[i].idSalon == idSalonBuscado && listaArcades[i].isEmpty == 0)
			{
				acumuladorFichas=acumuladorFichas+listaArcades[i].capacidadMaximaFichas;
			}
		}
		recaudacionTotal=acumuladorFichas*precioFicha;
		printf("\nEl ingreso maximo que puede recaudar el salon id %d es: %.2f\n\n",idSalonBuscado,recaudacionTotal);
		retorno=0;
	}
	return retorno;
}

int informeCantArcadesPorJuego(Arcade* listaArcades,int lenListaArcade,char nombreJuegoABuscar[])
{
	int retorno=-1;
	int contadorArcades;
	int i;

	contadorArcades=0;

	if(listaArcades != NULL && lenListaArcade > 0 && nombreJuegoABuscar != NULL)
	{
		for(i=0;i<lenListaArcade;i++)
		{
			if(strncmp(listaArcades[i].nombreJuego,nombreJuegoABuscar,JUEGO_LEN) == 0 && listaArcades[i].isEmpty == 0)
			{
				contadorArcades++;
			}
		}
		printf("\nLa cantidad de arcades que contienen el juego %s son: %d\n\n",nombreJuegoABuscar,contadorArcades);
		retorno=0;
	}
	return retorno;
}
