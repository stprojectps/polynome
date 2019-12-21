#include <stdio.h>
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

void Poly_print(Polynome _polynome)
{
    if(_polynome)
    {
        int power = _polynome->degree;
        int * components =_polynome->components; 

        for(int i = power; i >= 0; i--)
        {
            if(components[i] != 0)
            {
                if(components[i]>0)
                {
                    printf("+");
                }

                printf("%d", components[i]);

                if(i == 1) printf("x ");

                else if(i == 0) break;
                
                else printf("x%d ", i);
            }
        }
        printf("\n");
    }
    else printf("Veuillez revoir votre parametre");
}
