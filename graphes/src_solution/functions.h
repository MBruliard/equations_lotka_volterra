#ifndef _FUNCTIONS_HEADER_
#define _FUNCTIONS_HEADER_

#include "types.h"


/* USER'S FUNCTIONS */

double norm2(double vector_X2, double vector_Y2, double vector_X1, double vector_Y1) ;
void printSolutionXt(vector_t* solution, double a, double h, int N, FILE* f) ;
void printSolutionYt(vector_t* solution, double a, double h, int N, FILE* f) ;
void printSolutionXY(vector_t* solution, int N, FILE* f) ;
void _freeVector(vector_t* vect) ;
int  _initVector(vector_t** vect, int N) ;


#endif
