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

#define LENGHT_EXPRESSIONS 14

static const char EXPRESSIONS[LENGHT_EXPRESSIONS] = {'0', '1', '2', '3', '4', '5', '6', '7', '8', '9', '+', '-', ' ', 'x'};

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

/**
* Function for extracting component sign
* @hint: just search in the left side for sign. When the sign('+'/'-')
* is detected return the good value. Sometimes sign is omitted,
* so we need to break and return the good value at the first
* digit or 'x'.
*
* @param  {const char*}	- polynome
* @param  {int} 		- start position of component
* @param  {int} 		- end position of component
* @return {int}			- 1 if positive, -1 if negative
*/
int extract_sign(const char *_raw_poly, int _start_component);

/**
* Function for extracting number
* @hint: Sign MUST NOT be considered, only the coefficient
* 		 is important. we need to consider the first digit
*        starting by the left after the sign and stop when
*		 'x' or end position is reached. The conversion MUST
*		 be done.
*
* @param  {const char*}	- polynome
* @param  {int}			- start position of component
* @param  {int}			- end position of component
* @return {int}			- extracted number
*/
int extract_number(const char *_raw_poly, int _start_component, int _end_component);

/**
* Function for extraction power
* @hint: Extact the power of an component if this one is  a monome
*
* @param  {const char*}	- polynome
* @param  {int}			- start position of component
* @param  {int}			- end position of component
* @return {int}			- extracted power, 0 otherwise
*/
int extract_power(const char *_raw_poly, int _start_component, int _end_component);

#endif //H_PARSER_H
