#ifndef H_POLY_H
#define H_POLY_H

struct __polynome {
    int 	degree;
    int*	components; 
};

typedef struct  __polynome * Polynome;

/**
 * Initializes polynomial. Allocates memory for the
 * new polynomial.
 *
 * @param  {int} _degree - The degree of the polynomial
 * @return {Polynome} - Pointer to the initialized polynomial
 */
Polynome Poly_init(int _degree);

/**
 * Free the allocated memory used by the polynomial
 *
 * @param {Polynome} _polynome - the polynomial
 */
void Poly_free(Polynome _polynome);

/**
 * Display polynomial.
 *
 * @param {Polynome} _polynome - The polynomial
 */
void Poly_print(Polynome _polynome);

#endif //H_POLY_H
