#include <stdio.h>
#include "crank_nicolson.h"
#include "functions.h"


void crank_nicolson(vector_t* solution, double h, double alpha, double beta, double gamma, double sigma, int N) {
    int i ;    
    for (i = 1 ; i < N ; ++i) {
	double fixed_point_X ;
	double fixed_point_Y ;
	fixed_point_method(&fixed_point_X, &fixed_point_Y, solution[i-1], alpha, beta, gamma, sigma, h) ;
	solution[i].X = solution[i-1].X + h/2 * (solution[i-1].X * (alpha - beta * solution[i-1].Y) + fixed_point_X * (alpha - beta * fixed_point_Y)) ;
	solution[i].Y = solution[i-1].Y + h/2 * (solution[i-1].Y * (sigma * solution[i-1].X - gamma) + fixed_point_Y * (sigma * fixed_point_X - gamma)) ;
    }
}



void fixed_point_method(double* fixed_point_X, double* fixed_point_Y, vector_t solution, double alpha, double beta, double gamma, double sigma, double h) {
    /* The approximation of the fixed point at i-1 is
       previous_[X,Y] and *fixed_point_[X,Y] at i */
    
    double previous_X ;
    double previous_Y ;
    *fixed_point_X = solution.X ;
    *fixed_point_Y = solution.Y ;
    do {
	previous_X = *fixed_point_X ;
	previous_Y = *fixed_point_Y ;
	*fixed_point_X = solution.X + h/2 * (solution.X * (alpha - beta * solution.Y) + *fixed_point_X * (alpha - beta * *fixed_point_Y)) ;
	*fixed_point_Y = solution.Y + h/2 * (solution.Y * (sigma * solution.X - gamma) + *fixed_point_Y * (sigma * *fixed_point_X - gamma)) ;
    } while (EPSILON < norm2(*fixed_point_X, *fixed_point_Y, previous_X, previous_Y)) ;
}
