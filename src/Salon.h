
#ifndef SALON_H_
#define SALON_H_

#define NOMBRE_LEN 100
#define DIRECCION_LEN 100
#define TIPO_SHOPPING	1
#define TIPO_LOCAL	2

#define VACIO 1
#define OCUPADO 0

typedef struct {
	char nombre[NOMBRE_LEN];
	char direccion[DIRECCION_LEN];
	int tipoDeSalon;
	int idSalon;
	int isEmpty;
}Salon;

int inicializarSalones(Salon* listaSalones,int lenlistaSalones);
int buscarLugarVacioSalones(Salon* listaSalones,int lenlistaSalones);
int generadorDeIDSalon(void);
int altaSalones(Salon* listaSalones,int lenlistaSalones, int indiceVacio);
int altaForzadaSalon(Salon* listaSalones,int lenlistaSalones, int indiceF,char nombreF[],char direccionF[],int tipoDeSalonF,int idSalonF,int isEmptyF);

int imprimirSalones(Salon* listaSalones,int len, int tipoImpresion);
int buscarPorIdSalon(Salon* listaSalones,int len, int IdBuscado);
int bajaSalon(Salon* listaSalones,int lenlistaSalones, int indiceBuscadoSalon);

#endif /* SALON_H_ */
