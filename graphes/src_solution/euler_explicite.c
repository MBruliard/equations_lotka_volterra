#include "euler_explicite.h"



void euler_explicite(vector_t* solution, double h, double alpha, double beta, double gamma, double sigma, int N) {
    int i ;
    for (i = 1 ; i < N ; ++i) {
	solution[i].X = solution[i-1].X + (alpha - beta * solution[i-1].Y) * h * solution[i-1].X;
	solution[i].Y = solution[i-1].Y - (gamma - sigma * solution[i-1].X) * h * solution[i-1].Y ;
    }
}
