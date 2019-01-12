#include <stdlib.h>
#include <stdio.h>
#include "types.h"
#include "grid_functions.h"
#include "normalize_functions.h"


int main(int argc, char* argv[]) {

	if (7 != argc) {
		printf("# Erreur : le programme est supposé prendre deux entiers et quatre doubles en arguments :\n") ;
		printf("# %s NB_LIGNES NB_COLONNES ALPHA BETA SIGMA GAMMA\n", argv[0]) ;
		return EXIT_FAILURE ;
	}

	int nb_lines = atoi(argv[1]) ;
	int nb_cols = atoi(argv[2]) ;
	double alpha = atof(argv[3]) ;
	double beta = atof(argv[4]) ;
	double sigma = atof(argv[5]) ;
	double gamma = atof(argv[6]) ;

	grid_t* start_grid = init_grid(nb_lines, nb_cols) ;
	if (NULL == start_grid) {
		printf("Erreur : impossible d'allouer la mémoire à start_grid\n") ;
		return EXIT_FAILURE ;
	}
	grid_t* transform_grid = init_grid(nb_lines, nb_cols) ;
        if (NULL == start_grid) {
		printf("Erreur : impossible d'allouer la mémoire à transform_grid\n") ;
		free_grid(start_grid) ;
		return EXIT_FAILURE ;
	}

	double max_length_tolerance = 0.9 * linespace(start_grid) ;
	solve_lotka_volterra(start_grid, transform_grid, alpha, beta, sigma, gamma) ;

	normalize(transform_grid, max_length_tolerance) ;

	plot_field(start_grid, transform_grid) ;
    
	free_grid(start_grid) ;
	free_grid(transform_grid) ;

	return EXIT_SUCCESS ;
}
