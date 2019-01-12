#include <stdlib.h>
#include <stdio.h>
#include <math.h>
#include "types.h"
#include "grid_functions.h"
#include "lotka_volterra_function.h"


grid_t* init_grid(int nb_lines, int nb_cols) {

    grid_t* grid = NULL ;
    grid = (grid_t*) malloc(sizeof(grid_t)) ;
    if (NULL == grid) {
	return NULL ;
    }
    grid->elements = NULL ;
    grid->nb_lines = nb_lines ;
    grid->nb_cols = nb_cols ;
    grid->elements = (point_t**) malloc(nb_lines * sizeof(point_t*)) ;
    if (NULL == grid->elements) {
	free_grid(grid) ;
	return NULL ;
    }
    int i ;
    for (i = 0 ; i < nb_lines ; ++i) {
	grid->elements[i] = NULL ;
	grid->elements[i] = (point_t*) malloc(nb_cols * sizeof(point_t)) ;
	if (NULL == grid->elements[i]) {
	    free_grid(grid) ;
	    return NULL ;
	}
    }
    return grid ;
}


void free_grid(grid_t* grid) {
    if (NULL != grid) {
	if (NULL != grid->elements) {
	    int i ;
	    for (i = 0 ; i < grid->nb_lines ; ++i) {
		if (NULL != grid->elements[i]) {
		    free(grid->elements[i]) ;
		    grid->elements[i] = NULL ;
		}
	    }
	    free(grid->elements) ;
	    grid->elements = NULL ;
	}
	free(grid) ;
	grid = NULL ;
    }
}


double linespace(grid_t* grid) {

    int i, j ;
    double line_step = (double) 5/(grid->nb_lines-1) ;
    double col_step = (double) 5/(grid->nb_cols-1) ;
    for (i = 0 ; i < grid->nb_lines ; ++i) {
	for (j = 0 ; j < grid->nb_cols ; ++j) {
	    grid->elements[i][j].x = -2.5 + j*col_step ;
	    grid->elements[i][j].y = -2.5 + i*line_step ;
	}
    }
    if (line_step < col_step) {
	    return line_step ;
    }
    return col_step ;
}



void solve_lotka_volterra(grid_t* start_grid, grid_t* transform_grid, double alpha, double beta, double sigma, double gamma) {

	int i, j ;
	
	for (i = 0 ; i < start_grid->nb_lines ; ++i) {
		for (j = 0 ; j < start_grid->nb_cols ; ++j) {
			transform_grid->elements[i][j] = lotka_volterra_function(start_grid->elements[i][j].x + gamma/sigma, start_grid->elements[i][j].y + alpha/beta, alpha, beta, sigma, gamma) ;
		}
	}
}


void plot_field(grid_t* start_grid, grid_t* transform_grid) {

	int i, j ;

	for (i = 0 ; i < start_grid->nb_lines ; ++i) {
		for (j = 0 ; j < start_grid->nb_cols ; ++j) {
			printf("%s (%lf,%lf) -- (%lf,%lf) ;\n", DRAWING_STRING, start_grid->elements[i][j].x, start_grid->elements[i][j].y, start_grid->elements[i][j].x + transform_grid->elements[i][j].x, start_grid->elements[i][j].y + transform_grid->elements[i][j].y) ;
		}
	}
}
