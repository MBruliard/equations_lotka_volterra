/*DECLARATION DES FONCTIONNALITES SUPPLEMENTAIRES*/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "euler_exp.h"
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
		
	
	/*Affichage Terminal*/
	AffichageEulerExplSimple (z0, deltaT, nbr_pas, alpha, beta, sigma, gamma);
	
	
	
	/*Retpur de programme*/
	return EXIT_SUCCESS;
}
