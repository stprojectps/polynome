/**
 * THIS IS A POLYNOME PARSER PROJECT
 * THE PARSER CAN PARSE SOME POLYNOMES
 * RESPECTING THE FOLLOWING RULES:
 * 
 *  - MONOMES WHICH CONSTITUTE THE
 *    POLYNOME MUST APPEAR IN DECREASING
 *    ORDER STARTING BY THE LEFT
 *  - THE POLYNOME MUST BE A POLYNOME WITH
 *    ONE VARIABLE
 * 
 * 
 */

#ifndef H_PARSER_H
#define H_PARSER_H

#include "./poly.h"

#define LENGHT_EXPRESSIONS 13

static const char EXPRESSIONS[LENGHT_EXPRESSIONS] = {'0', '1', '2', '3', '4', '5', '6', '7', '8', '9', '+', '-', ' '};

/**
 * Checks if the given parameter is 
 * valid. It's consider as if it's a 
 * space,minus/plus sign, a digit or x
 * 
 * @param  {const char} - a character 
 * @return {int}        - 1 if valid char, 0 otherwise
 */
int is_valid_char(const char _c);

/**
 * Checks if a component is valid.
 * 
 * @param  {const char*}    - raw polynome
 * @param  {int}            - start position of component
 * @param  {int}            - end position of component
 * @return {int}            - 1 if valid component, 0 otherwise
 */
int is_valid_component(const char* _raw_poly, int _start_component, int _end_component);

#endif //H_PARSER_H
