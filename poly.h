#ifndef H_POLY_H
#define H_POLY_H

struct __polynome {
    int 	degree;
    int*	components; 
};

typedef struct  __polynome * Polynome;

Polynome Poly_init(int _degree);

void Poly_free(Polynome _polynome);

#endif //H_POLY_H