#ifndef __EULER_EXP_H___
#define __EULER_EXP_H___

#include "systemeLV.h"

lotkav_t RungeKutta4LV (lotkav_t z0, double alpha, double beta, double sigma, double gamma, double deltaT);

void AffichageRungeKutta4Param (lotkav_t z0, double deltaT, int nbr_pas, double alpha, double beta, double sigma, double gamma);


#endif
