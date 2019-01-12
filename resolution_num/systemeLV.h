#ifndef __SYSTEMELV_H___
#define __SYSTEMELV_H___

struct lotkav_s
{
	double x;
	double y;
};
typedef struct lotkav_s lotkav_t;

/*fonctions sur lotka-volterra*/
lotkav_t LotkaVolterra (lotkav_t z, double alpha, double beta, double sigma, double gamma);



#endif
