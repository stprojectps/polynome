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
        int * components = _polynome->components;
        int coef;

        for(int i = power; i >= 0; i--)
        {
            if(components[i] != 0)
            {
                coef = components[i];
                if(coef > 0) /* display positive sign except for the first*/
                {
                    if(i != _polynome->degree)
                        printf("+");
                }
                else /* display positive sign execpt for the first*/
                {
                    coef *= -1;
                    printf("-");
                }

                if(i != _polynome->degree) printf(" "); /* display space between coef and sign except the first coef */

                /* display component without sign*/
                if (coef > 1 && i > 1) /* example component = 2x3 */
                {
                    printf("%dx%d ", coef, i);
                }
                else if(coef > 1 && i == 1) /* example component = 2x */
                {
                    printf("%dx ", coef);
                }
                else if(coef == 1 && i > 1) /* example component = x3 */
                {
                    printf("x%d ", i);
                }
                else if(coef == 1 && i == 1) /* example component = x */
                {
                    printf("x ");
                }
                else /* example component = 10 */
                {
                    printf("%d ", coef);
                }
            }
        }
        printf("\n");
    }
    else printf("The given polynomial is null\n");
}
