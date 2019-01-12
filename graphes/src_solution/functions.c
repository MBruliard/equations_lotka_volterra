#include <stdlib.h>
#include <stdio.h>
#include <math.h>
#include "functions.h"



/* FUNCTIONS' DEFINITION */


double norm2(double vector_X2, double vector_Y2, double vector_X1, double vector_Y1) {
    return sqrt((vector_X2 - vector_X1) * (vector_X2 - vector_X1) + (vector_Y2 - vector_Y1) * (vector_Y2 - vector_Y1)) ;
}


void printSolutionXt(vector_t* solution, double a, double h, int N, FILE* f) {
    int i ;
    for (i = 0 ; i < N ; ++i) {
	fprintf(f, "%lf %lf\n", a + i*h, solution[i].X) ;
    }
}


void printSolutionYt(vector_t* solution, double a, double h, int N, FILE* f) {
    int i ;
    for (i = 0 ; i < N ; ++i) {
	fprintf(f, "%lf %lf\n", a + i*h, solution[i].Y) ;
    }
}


void printSolutionXY(vector_t* solution, int N, FILE* f) {
    int i ;
    for (i = 0 ; i < N ; ++i) {
	fprintf(f, "%lf %lf\n", solution[i].X, solution[i].Y) ;
    }
}


void _freeVector(vector_t* vect) {
    if (NULL != vect) {
	free(vect) ;
	vect = NULL ;
    }
}


int _initVector(vector_t** vect, int N) {
    *vect = (vector_t*)malloc(N * sizeof(vector_t)) ;
    if (NULL == *vect) {
	return 0 ;
    }
    return 1 ;
}
