/*
 ============================================================================
 Name        : PrimerParcialLabo1.c
 Author      : Marcos Zalazar
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "utn.h"
#include "Salon.h"
#include "Arcade.h"
#include "Juego.h"
#include "Informes.h"

#define CANTIDAD_SALONES 100
#define CANTIDAD_ARCADES 1000


int main(void)
{
	Salon arraySalones[CANTIDAD_SALONES];
	Arcade arrayArcades[CANTIDAD_ARCADES];

	int opcion;
	int auxiliarIndiceSalon;
	int auxiliarIdSalon;
	int auxiliarIndiceArcade;
	int auxiliarIdArcade;
	int opcionCampoAModificar;
	char respuesta;
	char informeAMostrar;
	char juegoSeleccionado[JUEGO_LEN];
	float valorFicha;

	setbuf(stdout, NULL);

	if(inicializarSalones(arraySalones,CANTIDAD_SALONES)==0)
	{
		printf("\nArray de salones inicializado correctamente\n");
	}

	if(inicializarArcades(arrayArcades,CANTIDAD_ARCADES)==0)
	{
		printf("Array de arcades inicializado correctamente\n");
	}

	altaForzadaArcade(arrayArcades,CANTIDAD_ARCADES, 0,"Argentina",1,2,100,0,"Pacman",0,0);
	altaForzadaArcade(arrayArcades,CANTIDAD_ARCADES, 1,"Argentina",1,2,100,0,"Street fighters",1,0);
	altaForzadaArcade(arrayArcades,CANTIDAD_ARCADES, 2,"Brasil",2,1,200,1,"Galaga",2,0);
	altaForzadaArcade(arrayArcades,CANTIDAD_ARCADES, 3,"Chile",1,4,150,1,"Wonderboy",3,0);
	altaForzadaArcade(arrayArcades,CANTIDAD_ARCADES, 4,"Argentina",2,2,150,1,"Mario Bros",4,0);
	altaForzadaArcade(arrayArcades,CANTIDAD_ARCADES, 5,"Japon",1,3,100,1,"Pacman",5,0);
	altaForzadaArcade(arrayArcades,CANTIDAD_ARCADES, 6,"China",2,2,200,2,"Galaga",6,0);
	altaForzadaArcade(arrayArcades,CANTIDAD_ARCADES, 7,"Mexico",2,4,100,2,"Mario Bros",7,0);
	altaForzadaArcade(arrayArcades,CANTIDAD_ARCADES, 8,"Argentina",1,2,500,2,"Centipede",8,0);
	altaForzadaArcade(arrayArcades,CANTIDAD_ARCADES, 9,"Mexico",2,4,100,2,"Snowbros",9,0);
	altaForzadaArcade(arrayArcades,CANTIDAD_ARCADES, 10,"Argentina",1,2,500,2,"Sunset Riders",10,0);
	altaForzadaArcade(arrayArcades,CANTIDAD_ARCADES, 11,"Mexico",2,4,100,3,"Gi Joe",11,0);
	altaForzadaArcade(arrayArcades,CANTIDAD_ARCADES, 12,"Argentina",1,2,500,3,"Pacman",12,0);

	altaForzadaSalon(arraySalones,CANTIDAD_SALONES,0,"Sacoa","Suipacha 1200",1,0,0);
	altaForzadaSalon(arraySalones,CANTIDAD_SALONES,1,"Digimax","Suipacha 100",1,1,0);
	altaForzadaSalon(arraySalones,CANTIDAD_SALONES,2,"Digitex","Mexico 200",2,2,0);
	altaForzadaSalon(arraySalones,CANTIDAD_SALONES,3,"Palacio digital","Esmeralda 233",1,3,0);
	altaForzadaSalon(arraySalones,CANTIDAD_SALONES,4,"Juegatron","Santa Fe 234",2,4,0);
	altaForzadaSalon(arraySalones,CANTIDAD_SALONES,5,"Matrix","Corrientes 123",1,5,0);
	altaForzadaSalon(arraySalones,CANTIDAD_SALONES,6,"Digiplace","Medrano 123",2,6,0);
	altaForzadaSalon(arraySalones,CANTIDAD_SALONES,7,"Juego Center","Tacuari 234",1,7,0);
	altaForzadaSalon(arraySalones,CANTIDAD_SALONES,8,"Speed","Diaz Velez 234",2,8,0);
	altaForzadaSalon(arraySalones,CANTIDAD_SALONES,9,"Destruction","Cordoba 342",1,9,0);
	altaForzadaSalon(arraySalones,CANTIDAD_SALONES,10,"Mad games","Mitre 344",2,10,0);

	do{
		printf("\n1) Alta de salon\n");
		printf("2) Eliminar salon\n");
		printf("3) Imprimir salones\n");
		printf("4) Incorporar arcade\n");
		printf("5) Modificar arcade\n");
		printf("6) Eliminar arcade\n");
		printf("7) Imprimir arcades\n");
		printf("8) Imprimir juegos\n");
		printf("9) Informes\n");
		printf("10) Salir\n");

		if(utn_getNumeroInt(&opcion,"\nIngrese la opción\n","\nOpción inválida\n",1,9,3)==0)
		{
			switch(opcion)
			{
				case 1:
					auxiliarIndiceSalon=buscarLugarVacioSalones(arraySalones,CANTIDAD_SALONES);
					if(auxiliarIndiceSalon >= 0)
					{
						if(altaSalones(arraySalones,CANTIDAD_SALONES,auxiliarIndiceSalon)==0)
						{
							printf("\nCarga realizada con éxito\n\n");
						}
					}
					else
					{
						printf("\nNo hay salones vacios\n\n");
					}
					break;
				case 2:
					imprimirSalones(arraySalones,CANTIDAD_SALONES,1);
					if(utn_getNumeroInt(&auxiliarIdSalon,"\nIngrese el ID del salon a eliminar","\nId inválido",0,100000000,3)==0)
					{
						auxiliarIndiceSalon =buscarPorIdSalon(arraySalones,CANTIDAD_SALONES, auxiliarIdSalon);

						if(auxiliarIndiceSalon >= 0 && bajaSalon(arraySalones,CANTIDAD_SALONES,auxiliarIndiceSalon)== 0)
						{
							if(bajaArcadePorSalon(arrayArcades,CANTIDAD_ARCADES,auxiliarIdSalon)== 0)
							{
								printf("\nBaja de arcades del salon realizada con éxito\n");
							}
							else
							{
								printf("\nNo hay arcades del salon a dar de baja\n");
							}
						}
						else
						{
							printf("\nNo se pudo dar de baja al salon.Verifique el Id\n");
						}
					}
					else
					{
						printf("\nNo se encontró el ID\n");
					}
					break;
				case 3:
					imprimirSalones(arraySalones,CANTIDAD_SALONES,2);
					break;
				case 4:
					auxiliarIndiceArcade = buscarLugarVacioArcades(arrayArcades,CANTIDAD_ARCADES);
					if(auxiliarIndiceArcade >= 0)
					{
						imprimirSalones(arraySalones,CANTIDAD_SALONES,1);
						if(utn_getNumeroInt(&auxiliarIdSalon,"\nIngrese el Id del salón: ","\nError",0,100000,3) == 0 &&
								buscarPorIdSalon(arraySalones,CANTIDAD_SALONES,auxiliarIdSalon) != -1)
						{
							if(altaArcade(arrayArcades,CANTIDAD_ARCADES,auxiliarIndiceArcade,auxiliarIdSalon)==0)
							{
								printf("\nArcade cargado exitosamente\n");
							}
						}
						else
						{
							printf("\nNo se encontró el ID de salón ingresado\n");
						}
					}
					break;
				case 5:
					imprimirArcades(arrayArcades,CANTIDAD_ARCADES);
					if(utn_getNumeroInt(&auxiliarIdArcade,"\nIngrese el ID de arcade a modificar","\nERROR",0,100000,3)==0)
					{
						auxiliarIndiceArcade = buscarIdArcade(arrayArcades,CANTIDAD_ARCADES,auxiliarIdArcade);
						if(auxiliarIndiceArcade >=0)
						{
							do{
								printf("**************************************************\n");
								printf("¿Cual campo desea modificar?\n");
								printf("11) Cantidad de jugadores\n");
								printf("12) Juego que contiene\n");
								printf("13) Ninguno, volver al menu principal\n");
								printf("**************************************************\n");

								utn_getNumeroInt(&opcionCampoAModificar,"\nIngrese la opción","\nOpción inválida",11,13,3);

								switch(opcionCampoAModificar)
								{
									case 11:
										modificarArcade(arrayArcades,CANTIDAD_ARCADES,auxiliarIndiceArcade,opcionCampoAModificar);
										printf("\nModificación de arcade exitosa\n");
										break;
									case 12:
										imprimirJuegos(arrayArcades,CANTIDAD_ARCADES);
										modificarArcade(arrayArcades,CANTIDAD_ARCADES,auxiliarIndiceArcade,opcionCampoAModificar);
										printf("\nModificación de arcade exitosa\n");
										break;
								}
							}while(opcionCampoAModificar!=13);
						}
						else
						{
							printf("\nId no encontrado");
						}
					}
					break;
				case 6:
					imprimirListaArcadeConInfoSalon(arrayArcades,CANTIDAD_ARCADES,arraySalones,CANTIDAD_SALONES);
					if(utn_getNumeroInt(&auxiliarIdArcade,"\nID de arcade a dar de baja? ","\nERROR",0,100000,3)==0)
					{
						auxiliarIndiceArcade = buscarIdArcade(arrayArcades,CANTIDAD_ARCADES,auxiliarIdArcade);
						if(auxiliarIndiceArcade >= 0)
						{
							printf("\nArcade a eliminar:");
							imprimirUnArcade(arrayArcades,auxiliarIndiceArcade);
							utn_getChar(&respuesta,"\nEsta seguro que desea eliminar el arcade?(s=SI n=NO)\n","\nOpción invalida",2,3);

							if(respuesta=='s')
							{
								bajaArcade(arrayArcades,CANTIDAD_ARCADES,auxiliarIndiceArcade);
								printf("\nBaja realizada con éxito\n");
							}
							else
							{
								printf("\nBaja cancelada\n");
							}
						}
						else
						{
							printf("\nId no encontrado\n");
						}
					}
					break;
				case 7:
					imprimirArcades(arrayArcades,CANTIDAD_ARCADES);
					break;
				case 8:
					imprimirJuegos(arrayArcades,CANTIDAD_ARCADES);
					break;
				case 9:
					do{
						printf("**************************************************\n");
						printf("¿Cual informe desea?\n");
						printf("A) Salones con mas de 4 arcades\n");
						printf("B) Arcades para mas de 2 jugadores\n");
						printf("C) Informacion de un salon especifico\n");
						printf("D) Todos los arcades de un salon\n");
						printf("E) Salon con mas cantidad de arcades\n");
						printf("F) Maximo de recaudacion de un salon\n");
						printf("G) Juegos que contienen un determinado arcade\n");
						printf("Z) Salir\n");
						printf("**************************************************\n");

						utn_getChar(&informeAMostrar,"\nSeleccione el informe que desea","\nInforme invalido",2,3);

						switch(informeAMostrar)
						{
							case 'A':
								informeSalonesMasdeCuatroArcades(arrayArcades,CANTIDAD_ARCADES,arraySalones,CANTIDAD_SALONES);
								break;
							case 'B':
								informeArcadeParaMasdeDosJugadores(arrayArcades,CANTIDAD_ARCADES,arraySalones,CANTIDAD_SALONES);
								break;
							case 'C':
								if(utn_getNumeroInt(&auxiliarIdSalon,"\nIngrese el Id del Salón: ","\nError",0,100000,3) ==0)
								{
									informeCompletodeSalon(arrayArcades,CANTIDAD_ARCADES,arraySalones,CANTIDAD_SALONES,auxiliarIdSalon);
								}
								break;
							case 'D':
								if(utn_getNumeroInt(&auxiliarIdSalon,"\nIngrese el Id del Salón: ","\nError",0,100000,3) ==0)
								{
									informeArcadesPorSalon(arrayArcades,CANTIDAD_ARCADES,arraySalones,CANTIDAD_SALONES,auxiliarIdSalon);
								}
								break;
							case 'E':
								informeSalonConMasArcades(arrayArcades,CANTIDAD_ARCADES,arraySalones,CANTIDAD_SALONES);
								break;
							case 'F':
								if(utn_getNumeroInt(&auxiliarIdSalon,"\nId Salón: ","\nError",0,100000,3) ==0 &&
								   utn_getNumeroFlotante(&valorFicha, "\nIngrese el valor de la ficha: ","\nError",1,100000,3)==0)
								{
									informeRecaudacionMaximaPorSalon(arrayArcades,CANTIDAD_ARCADES,auxiliarIdSalon,valorFicha);
								}
								break;
							case 'G':
								if(utn_getDescripcion(juegoSeleccionado,"\nSeleccione el juego a informar","\nJuego invalido",JUEGO_LEN,3)==0)
								{
									informeCantArcadesPorJuego(arrayArcades,CANTIDAD_ARCADES,juegoSeleccionado);
								}
								break;
						}
					}while(informeAMostrar!='Z');

					break;
				default:
					printf("\nOpción inválida. Elija las opciones de la 1 a la 10, por favor\n");
					break;
			}
		}

	}while(opcion!=10);

	return EXIT_SUCCESS;
}

