#include "systemeLV.h"



/**
Fonction du système de Lotka-Volterra
@alpha, @beta, @sigma, @gamma sont les données appliquées au systeme
@z est le vecteur (x, y) du système
@dz 
*/
lotkav_t LotkaVolterra (lotkav_t z, double alpha, double beta, double sigma, double gamma)
{
	lotkav_t dz;
	
	dz.x = alpha*z.x - beta*z.x*z.y;
	dz.y = sigma*z.y*z.x - gamma*z.y;

	return dz;
}
