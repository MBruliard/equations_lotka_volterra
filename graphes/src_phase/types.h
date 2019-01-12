#ifndef _TYPES_HEADER_
#define _TYPES_HEADER_

#define DRAWING_STRING "\\draw[thin,Cyan!50,->]"

typedef struct point_t point_t ;
struct point_t {
    double x ;
    double y ;
} ;

typedef struct grid_t grid_t ;
struct grid_t {
    int nb_lines ;
    int nb_cols ;
    point_t** elements ;
} ;

#endif
