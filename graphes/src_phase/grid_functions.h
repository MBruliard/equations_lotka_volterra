#ifndef _GRID_FUNCTIONS_HEADER_
#define _GRID_FUNCTIONS_HEADER_

grid_t* init_grid(int nb_lines, int nb_cols) ;
void free_grid(grid_t* grid) ;
double linespace(grid_t* grid) ;
void solve_lotka_volterra(grid_t* start_grid, grid_t* transform_grid, double alpha, double beta, double sigma, double gamma) ;
void plot_field(grid_t* start_grid, grid_t* transform_grid) ;

#endif
