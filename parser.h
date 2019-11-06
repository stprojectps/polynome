#ifndef H_PARSER_H
#define H_PARSER_H

#define LENGHT_EXPRESSIONS 13

char EXPRESSIONS[LENGHT_EXPRESSIONS] = {'0', '1', '2', '3', '4', '5', '6', '7', '8', '9', '+', '-', ' '};

/**
 * Checks if the given parameter is 
 * valid. It's consider as if it's a 
 * space,minus/plus sign, a digit or x
 * 
 * @param  {const char} - a character 
 * @return {int}        - 1 if valid char, 0 otherwise
 */
int is_valid_char(const char _c);
#endif //H_PARSER_H