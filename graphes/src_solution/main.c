#include <stdlib.h>
#include <stdio.h>
#include "functions.h"
#include "euler_explicite.h"
#include "crank_nicolson.h"
#include "runge_kutta_4.h"



/* MAIN FUNCTION */

int main(int argc, char* argv[]) {

    if (2 != argc) {
	printf("Erreur : il faut renseigner l'adresse du fichier :\n") ;
	printf("%s ADRESSE_DU_FICHIER\n", argv[0]) ;
	return EXIT_FAILURE ;
    }

    printf("EULER PROGRAM\n") ;

    FILE* f_XY = NULL ;
    f_XY = fopen("./data/resXY.dat", "w") ;
    if (NULL == f_XY) {
	printf("Error: impossible to open data file \"data/resXY.dat\"\n") ;
	return EXIT_FAILURE ;
    }

    FILE* f_Xt = NULL ;
    f_Xt = fopen("./data/resXt.dat", "w") ;
    if (NULL == f_Xt) {
	printf("Error: impossible to open data file \"data/resXt.dat\"\n") ;
	fclose(f_XY) ;
	return EXIT_FAILURE ;
    }

    FILE* f_Yt = NULL ;
    f_Yt = fopen("./data/resYt.dat", "w") ;
    if (NULL == f_Yt) {
	printf("Error: impossible to open data file \"data/resYt.dat\"\n") ;
	fclose(f_XY) ;
	fclose(f_Xt) ;
	return EXIT_FAILURE ;
    }

    FILE* file = NULL ;
    file = fopen(argv[1], "r") ;
    if (NULL == file) {
	printf("Error: impossible to open data file \"%s\"\n", argv[1]) ;
    }
    
    double x_0, y_0, alpha, beta, gamma, sigma, a, b ;
    int N ;

    fscanf(file, "%lf %lf %lf %lf %lf %lf %lf %lf %d", &x_0 , &y_0, &alpha, &beta , &gamma, &sigma, &a, &b, &N) ;

    /* double x_0 = 50 ;	 */
    /* double y_0 = 20 ;	 */
    /* double alpha = 1.2 ; */
    /* double beta = 0.5/y_0 ;	 */
    /* double gamma = 1.05 ; */
    /* double sigma = 0.8/x_0 ; */


    /* int N = 100000 ; */
    /* double a = 0 ; */
    /* double b = 14 ; */
    double h = (double)(b-a)/N ;

    vector_t* solution = NULL ;

    printf("Parameters :\n") ;
    printf("alpha = %lf\tx_0 = %lf\nbeta  = %lf\ty_0 = %lf\ngamma = %lf\nsigma = %lf\n", alpha, x_0, beta, y_0, gamma, sigma) ;
    
    if (0 == _initVector(&solution, N)) {
	printf("Error: impossible to allocate the memory\n") ;
	fclose(f_XY) ;
	fclose(f_Xt) ;
	fclose(f_Yt) ;
	fclose(file) ;
	return EXIT_FAILURE ;
    }

    printf("Approximation of the solution on the interval [%lf;%lf] with a sample of %d points (step of %lf)\n", a, b, N, h) ;

    /* int i ; */
    /* for (i = 0 ; i < 16 ; ++i) { */
    /* 	fprintf(f_XY, "\n") ; */
    /* 	fprintf(f_Xt, "\n") ; */
    /* 	fprintf(f_Yt, "\n") ; */
    /* 	solution[0].X = x_0 + 1*i ; */
    /* 	solution[0].Y = y_0 + 1.8*i ; */
    /* 	euler_explicite(solution, h, alpha, beta, gamma, sigma, N) ; */
    /* 	printSolutionXY(solution, N, f_XY) ; */
    /* 	printSolutionXt(solution, a, h, N, f_Xt) ; */
    /* 	printSolutionYt(solution, a, h, N, f_Yt) ; */
    /* } */

    fprintf(f_XY, "\n") ;
    fprintf(f_Xt, "\n") ;
    fprintf(f_Yt, "\n") ;
    solution[0].X = x_0 ;
    solution[0].Y = y_0 ;
    // euler_explicite(solution, h, alpha, beta, gamma, sigma, N) ;
    crank_nicolson(solution, h, alpha, beta, gamma, sigma, N) ;
    // runge_kutta_4(solution, h, alpha, beta, gamma, sigma, N) ;
    printSolutionXY(solution, N, f_XY) ;
    printSolutionXt(solution, a, h, N, f_Xt) ;
    printSolutionYt(solution, a, h, N, f_Yt) ;

    /* printf("\n") ; */
    /* for (i = 0 ; i < 16 ; ++i) { */
    /* 	printf("%lf %lf\n", x_0+i*1, y_0+i*1.8) ; */
    /* } */

    
    _freeVector(solution) ;
    fclose(f_XY) ;
    fclose(f_Xt) ;
    fclose(f_Yt) ;
    fclose(file) ;
    return EXIT_SUCCESS ;
}




