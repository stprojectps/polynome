#include <stdlib.h>
#include "poly.h"

Polynome Poly_init(int _degree)
{
    Polynome poly = (Polynome) malloc(sizeof(struct __polynome));
    poly->degree = _degree;
    poly->components = (int *) malloc(sizeof(int) * (_degree + 1));
    
    int i;
    for ( i = 0; i <= poly->degree; i++)
    {
        poly->components[i] = 0;
    }
    
    return poly;
}

void Poly_free(Polynome _polynome)
{
    if (_polynome)
    {
        free(_polynome->components);
        free(_polynome);
    }
}
