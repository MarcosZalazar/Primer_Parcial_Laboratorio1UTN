#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "utn.h"
#include "Salon.h"


int inicializarSalones(Salon* listaSalones,int lenlistaSalones)
{
	int retorno = -1;
	int i;

	if(listaSalones != NULL && lenlistaSalones > 0)
	{
		retorno = 0;
		for(i=0;i<lenlistaSalones;i++)
		{
			listaSalones[i].isEmpty = VACIO;
		}
	}
	return retorno;
}

int buscarLugarVacioSalones(Salon* listaSalones,int lenlistaSalones)
{
	int retorno=-1;
	int i;

	if(listaSalones!= NULL && lenlistaSalones>=0)
	{
		for(i=0;i<lenlistaSalones;i++)
		{
			if(listaSalones[i].isEmpty==VACIO)
			{
				retorno=i;
				break;
			}
		}
	}
	return retorno;
}

int generadorDeIDSalon(void)
{
	static int contadorId=0;

	return contadorId++;
}

int altaSalones(Salon* listaSalones,int lenlistaSalones, int indiceVacio)
{
	int retorno=-1;
	char auxiliarNombre[128];
	char auxiliarDireccion[128];
	int auxiliarTipo;

	if(listaSalones!=NULL && lenlistaSalones>0 && indiceVacio< lenlistaSalones && indiceVacio>=0)
	{
		if(utn_getDescripcion(auxiliarNombre,"Ingrese el nombre: ","Error",NOMBRE_LEN,3)==0)
		{
			if(utn_getDescripcion(auxiliarDireccion,"Ingrese la direccion: ", "Error",DIRECCION_LEN,3)==0)
			{
				if(utn_getNumeroInt(&auxiliarTipo,"Ingrese el tipo de salon (SHOPPING:1 LOCAL:2)", "Error",1,2,3)==0)
				{
					strncpy(listaSalones[indiceVacio].nombre,auxiliarNombre,sizeof(listaSalones->nombre));
					strncpy(listaSalones[indiceVacio].direccion,auxiliarDireccion,sizeof(listaSalones->direccion));
					listaSalones[indiceVacio].tipoDeSalon=auxiliarTipo;
					listaSalones[indiceVacio].idSalon=generadorDeIDSalon();
					listaSalones[indiceVacio].isEmpty=OCUPADO;
					retorno=0;
				}
			}
		}
	}
	return retorno;
}

int altaForzadaSalon(Salon* listaSalones,int lenlistaSalones, int indiceF,char nombreF[],char direccionF[],int tipoDeSalonF,int idSalonF,int isEmptyF)
{
	int retorno=-1;

	if(listaSalones!=NULL && lenlistaSalones>0 && indiceF< lenlistaSalones && indiceF>=0 && nombreF!=NULL && direccionF!=NULL && (tipoDeSalonF==1||tipoDeSalonF==2) && idSalonF>=0 && (isEmptyF==0||isEmptyF==1))
	{
		strncpy(listaSalones[indiceF].nombre,nombreF,NOMBRE_LEN);
		strncpy(listaSalones[indiceF].direccion,direccionF,DIRECCION_LEN);
		listaSalones[indiceF].tipoDeSalon=tipoDeSalonF;
		listaSalones[indiceF].idSalon=idSalonF;
		listaSalones[indiceF].isEmpty=isEmptyF;
		retorno=0;
	}
	return retorno;
}

int imprimirSalones(Salon* listaSalones,int lenlistaSalones, int tipoImpresion)
{
	int retorno = -1;
	int i;

	if(listaSalones != NULL && lenlistaSalones > 0)
	{
		retorno = 0;
		for(i=0;i<lenlistaSalones;i++)
		{
			switch(tipoImpresion)
			{
				case 1:
					if(listaSalones[i].isEmpty==0)
					{
						printf("\nId del salon: %d - Nombre: %s - Direccion: %s\n", listaSalones[i].idSalon,listaSalones[i].nombre,listaSalones[i].direccion);
					}
					break;
				case 2:
					if(listaSalones[i].isEmpty==0)
					{
						printf("\nNombre del salon: %s - Direccion: %s - Tipo del salon: %d\n", listaSalones[i].nombre,listaSalones[i].direccion,listaSalones[i].tipoDeSalon);
					}
					break;
			}
		}
	}
	return retorno;
}

int buscarPorIdSalon(Salon* listaSalones,int lenlistaSalones, int IdBuscado)
{
	int retorno=-1;
	int i;

	if(listaSalones!=NULL && lenlistaSalones>=0 && IdBuscado>=0)
	{
		for(i=0;i<lenlistaSalones;i++)
		{
			if(listaSalones[i].idSalon==IdBuscado && listaSalones[i].isEmpty==OCUPADO)
			{
				retorno=i;
				break;
			}
		}
	}
	return retorno;
}

int bajaSalon(Salon* listaSalones,int lenlistaSalones, int indiceBuscadoSalon)
{
	int retorno = -1;

	if(listaSalones != NULL && lenlistaSalones > 0 && indiceBuscadoSalon < lenlistaSalones && indiceBuscadoSalon >= 0 && listaSalones[indiceBuscadoSalon].isEmpty == OCUPADO)
	{
		listaSalones[indiceBuscadoSalon].isEmpty = VACIO;
		retorno = 0;
	}
	return retorno;
}
