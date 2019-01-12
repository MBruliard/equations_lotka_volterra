#include "runge_kutta_4.h"



void runge_kutta_4(vector_t* solution, double h, double alpha, double beta, double gamma, double sigma, int N) {

    int i ;
    vector_t u1, u2, u3, u4 ;
    for (i = 1 ; i < N ; ++i) {	
	u1.X = (alpha - beta * solution[i-1].Y) * solution[i-1].X ;
	u1.Y = (sigma * solution[i-1].X - gamma) * solution[i-1].Y ;
	u2.X = (alpha - beta * (solution[i-1].Y + h/2*u1.Y)) * (solution[i-1].X + h/2*u1.X) ;
	u2.Y = (sigma * (solution[i-1].X + h/2*u1.X) - gamma) * (solution[i-1].Y + h/2*u1.Y) ;
	u3.X = (alpha - beta * (solution[i-1].Y + h/2*u2.Y)) * (solution[i-1].X + h/2*u2.X) ;
	u3.Y = (sigma * (solution[i-1].X + h/2*u2.X) - gamma) * (solution[i-1].Y + h/2*u2.Y) ;
	u4.X = (alpha - beta * (solution[i-1].Y + h/2*u3.Y)) * (solution[i-1].X + h/2*u3.X) ;
	u4.Y = (sigma * (solution[i-1].X + h/2*u3.X) - gamma) * (solution[i-1].Y + h/2*u3.Y) ;

	solution[i].X = solution[i-1].X + h/6 * (u1.X + 2*u2.X + 2*u3.X + u4.X) ;
	solution[i].Y = solution[i-1].Y + h/6 * (u1.Y + 2*u2.Y + 2*u3.Y + u4.Y) ;
    }
}
