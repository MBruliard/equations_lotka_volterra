#include<stdio.h>
#include <stdlib.h>
#include "systemeLV.h"
#include "runge_kutta4.h"

lotkav_t RungeKutta4LV (lotkav_t z0, double alpha, double beta, double sigma, double gamma, double deltaT)
{
	lotkav_t res, z1, z2, z3;
	lotkav_t k1, k2, k3, k4;
	
	k1 = LotkaVolterra (z0, alpha, beta, sigma, gamma);
	
	/*on change z1 = z0 + deltaT/2*k1*/
	z1.x = z0.x + deltaT/2*k1.x;
	z1.y = z0.y + deltaT/2*k1.y;
	
	k2 = LotkaVolterra (z1, alpha, beta, sigma, gamma);
	
	/*on change z2 pour z0 + deltaT/2*k2*/
	z2.x = z0.x + deltaT/2*k2.x;
	z2.y = z0.y + deltaT/2*k2.y;
	
	k3 = LotkaVolterra (z2, alpha, beta, sigma, gamma);
	
	/*z3 = z0 + deltaT*k3*/
	z3.x = z0.x + deltaT*k3.x;
	z3.y = z0.y + deltaT*k3.y;
	
	k4 = LotkaVolterra (z3, alpha, beta, sigma, gamma);

	/*calcul du terme z_n+1*/
	res.x = z0.x + deltaT/6*(k1.x + 2*k2.x + 2*k3.x + k4.x);
	res.y = z0.y + deltaT/6*(k1.y + 2*k2.y + 2*k3.y + k4.y);

	return res;
}



void AffichageRungeKutta4Param (lotkav_t z0, double deltaT, int nbr_pas, double alpha, double beta, double sigma, double gamma)
{
	int i; 
	double t=0;
	lotkav_t z_i;
	
	
	printf ("%lg %lg\n", z0.x, z0.y);
	t = t + deltaT;
	for (i=1; i<=nbr_pas; i++)
	{
		z_i = RungeKutta4LV (z0, alpha, beta, sigma, gamma, deltaT);
		printf ("%lg %lg\n", z_i.x, z_i.y);
		t = t + deltaT;
		z0.x = z_i.x;
		z0.y = z_i.y;
	}

}







