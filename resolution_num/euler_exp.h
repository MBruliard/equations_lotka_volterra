#ifndef __EULER_EXP_H___
#define __EULER_EXP_H___

#include "systemeLV.h"

lotkav_t EulerExplLV (lotkav_t z0, double alpha, double beta, double sigma, double gamma, double deltaT);

/*fonctions affichage resultats*/
void AffichageEulerExplLikeKokh (lotkav_t z0, double deltaT, int nbr_pas, double alpha, double beta, double sigma, double gamma);
void AffichageEulerExplSimple (lotkav_t z0, double deltaT, int nbr_pas, double alpha, double beta, double sigma, double gamma);
void AffichageEulerExplParam (lotkav_t z0, double deltaT, int nbr_pas, double alpha, double beta, double sigma, double gamma);

#endif
