#include <stdio.h>
#include "lotka_volterra_function.h"


point_t lotka_volterra_function(double x, double y, double alpha, double beta, double sigma, double gamma) {

	point_t point ;
	point.x = x * (alpha-beta*y) ;
	point.y = y * (sigma*x-gamma) ;
	return point ;
}
