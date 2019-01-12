/*DECLARATION DES FONCTIONNALITES SUPPLEMENTAIRES*/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "euler_exp.h"
#include "runge_kutta4.h"
#include "systemeLV.h"


/*FONCTION PRINCIPALE*/
int main (int argc, char *argv[])
{
	/*verification arguments main*/
	if (argc != 2) 
	{
		printf("\nLe programme doit recevoir un seul argument\n");
		return(EXIT_FAILURE);
	}
	
	/*declaration et initialisation des valeurs*/
	double nbr_pas, Tmax, alpha, beta, sigma, gamma;
	FILE* fichier = NULL;
	double deltaT;
	lotkav_t z0;
	int menu;
	
	
	/*Recuperation des données dans le fichier donnéesLV.txt*/
	fichier = fopen(argv[1],"r");
	if (fichier == NULL)
	{
		printf("Impossible d’ouvrir le fichier %s \n",argv[1]);
		return(EXIT_FAILURE);
	}
	fscanf(fichier, "%lg %lg %lg %lg %lg %lg %lg %lg", &nbr_pas, &Tmax, &alpha , &beta, &sigma , &gamma, &z0.x, &z0.y);
	fclose (fichier);
	
	/*calcul de deltaT*/
	deltaT = Tmax/nbr_pas;
		
	/*MISE EN PLACE DU MENU*/
	do
	{
		printf ("QUELLE METHODE DE RESOLUTION NUMERIQUE UTILISÉE ?\n");
		printf (" (1) EULER EXPLICITE\n (2) RUNGE-KUTTA 4\n (0) QUITTER\n");
		scanf ("%d", &menu);
		
		if (menu == 1)
		{
			AffichageEulerExplParam ( z0, deltaT, nbr_pas, alpha, beta, sigma, gamma);
		}
		if (menu == 2)
		{
			AffichageRungeKutta4Param ( z0, deltaT, nbr_pas, alpha, beta, sigma, gamma);
		}
		
	}
	while ((menu != 0) && (menu != 1) && (menu != 2));
	
	
	
	/*Retpur de programme*/
	return EXIT_SUCCESS;
}
