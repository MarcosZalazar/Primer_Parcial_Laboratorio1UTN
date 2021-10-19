

#ifndef INFORMES_H_
#define INFORMES_H_

int generarListaDeJuegos(Juego* listaJuegos,int lenListaJuegos,Arcade* listaArcades,int lenListaArcade);
int imprimirJuegos(Arcade* listaArcades,int lenListaArcade);

int imprimirListaArcadeConInfoSalon(Arcade* listaArcades,int lenListaArcade,Salon* listaSalones,int lenlistaSalones);
int estaElSalonEnLaLista(Salon* listaSalones,int lenlistaSalones,int idAComparar);
int generarListaDeSalones(Salon* listaSalones,int lenlistaSalones,Arcade* listaArcades,int lenListaArcade);
int getCantidadDeArcadesPorSalon(Arcade* listaArcades,int lenListaArcade,int idSalonBuscado);
int informeSalonesMasdeCuatroArcades(Arcade* listaArcades,int lenListaArcade,Salon* listaSalones,int lenlistaSalones);
int informeArcadeParaMasdeDosJugadores(Arcade* listaArcades,int lenListaArcade,Salon* listaSalones,int lenlistaSalones);
int informeCompletodeSalon(Arcade* listaArcades,int lenListaArcade,Salon* listaSalones,int lenlistaSalones,int idSalonAInformar);
int informeArcadesPorSalon(Arcade* listaArcades,int lenListaArcade,Salon* listaSalones,int lenlistaSalones,int idSalonAInformar);
int informeSalonConMasArcades(Arcade* listaArcades,int lenListaArcade,Salon* listaSalones,int lenlistaSalones);
int informeRecaudacionMaximaPorSalon(Arcade* listaArcades,int lenListaArcade,int idSalonBuscado, float precioFicha);
int informeCantArcadesPorJuego(Arcade* listaArcades,int lenListaArcade,char nombreJuegoABuscar[]);

#endif /* INFORMES_H_ */
