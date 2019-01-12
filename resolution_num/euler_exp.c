#include <stdio.h>
#include <stdlib.h>
#include "euler_exp.h"
#include "systemeLV.h"

/**
Fonction calculant le rang suivant de la suite z_n par le schéma Euler Explicite pour la fonction de Lotka-Volterra
*/
lotkav_t EulerExplLV (lotkav_t z0, double alpha, double beta, double sigma, double gamma, double deltaT)
{
	lotkav_t z1; 
	lotkav_t dz0 = LotkaVolterra (z0, alpha, beta, sigma, gamma);
	
	z1.x = z0.x + deltaT*dz0.x;
	z1.y = z0.y + deltaT*dz0.y;
	
	return z1;
}


/**
Fonction affichage basée sur le modèle fait lors du TP noté de Langage C avancé. Essai pour la transformation de l'affichage terminal en fichier .dat pour l'utilisation ultérieure de gnuplot
*/
void AffichageEulerExplLikeKokh (lotkav_t z0, double deltaT, int nbr_pas, double alpha, double beta, double sigma, double gamma)
{
	int i; 
	double t=0;
	lotkav_t z_i;


		/*affichage des step number*/
	for (i=0; i<=nbr_pas; i++)
	{
		printf("# step number = %d t = %lg\n", i, t);
		t = t + deltaT;
	}
	
		/*Affichage des z_n*/
	z_i.x = z0.x;
	z_i.y = z0.y;
	printf (";%lg %lg\n", z_i.x, z_i.y);
	for (i=1; i<=nbr_pas; i++)
	{
		z_i = EulerExplLV (z_i, alpha, beta, sigma, gamma, deltaT);
		printf ("%lg %lg\n", z_i.x, z_i.y);
	}

}

/**
Fonction alternative sur l'affichage terminal des résultats
*/
void AffichageEulerExplSimple (lotkav_t z0, double deltaT, int nbr_pas, double alpha, double beta, double sigma, double gamma)
{
	int i; 
	double t=0;
	lotkav_t z_i;
	
	printf ("%lg %lg %lg\n", t, z0.x, z0.y);
	t = t + deltaT;
	for (i=1; i<=nbr_pas; i++)
	{
		z_i = EulerExplLV (z0, alpha, beta, sigma, gamma, deltaT);
		printf ("%lg %lg %lg\n", t, z_i.x, z_i.y);
		t = t + deltaT;
		z0.x = z_i.x;
		z0.y = z_i.y;
	}
}

void AffichageEulerExplParam (lotkav_t z0, double deltaT, int nbr_pas, double alpha, double beta, double sigma, double gamma)
{
	int i; 
	double t=0;
	lotkav_t z_i;
	
	printf ("%lg %lg\n", z0.x, z0.y);
	t = t + deltaT;
	for (i=1; i<=nbr_pas; i++)
	{
		z_i = EulerExplLV (z0, alpha, beta, sigma, gamma, deltaT);
		printf ("%lg %lg\n", z_i.x, z_i.y);
		t = t + deltaT;
		z0.x = z_i.x;
		z0.y = z_i.y;
	}

}




