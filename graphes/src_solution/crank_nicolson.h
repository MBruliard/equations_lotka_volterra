#ifndef _CRANK_NICOLSON_HEADER_
#define _CRANK_NICOLSON_HEADER_

#include "types.h"

void crank_nicolson(vector_t* solution, double h, double alpha, double beta, double gamma, double sigma, int N) ;

void fixed_point_method(double* fixed_point_X, double* fixed_point_Y, vector_t solution, double alpha, double beta, double gamma, double sigma, double h) ;

#endif
