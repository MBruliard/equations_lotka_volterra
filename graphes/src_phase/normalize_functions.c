#include <math.h>
#include "normalize_functions.h"


double Norm2(point_t point) {
	double result = sqrt(point.x*point.x + point.y*point.y) ;
	return result ;
}



void normalize(grid_t* grid, double max_length_tolerance) {

	int i, j ;

	double max_length = 0 ;
	
	for (i = 0 ; i < grid->nb_lines ; ++i) {
		for (j = 0 ; j < grid->nb_cols ; ++j) {
			if (max_length < Norm2(grid->elements[i][j])) {
				max_length = Norm2(grid->elements[i][j]) ;
			}
		}
	}

	double normalize_coefficient = max_length_tolerance / max_length ;

	for (i = 0 ; i < grid->nb_lines ; ++i) {
		for (j = 0 ; j < grid->nb_cols ; ++j) {
			grid->elements[i][j].x = normalize_coefficient * grid->elements[i][j].x ;
			grid->elements[i][j].y = normalize_coefficient * grid->elements[i][j].y ;
		}
	}
}
