#include <stdlib.h>
#include "parser.h"

int is_valid_char(const char _c)
{
    int i;

    for (i = 0; i < LENGHT_EXPRESSIONS; i++)
    {
        if (EXPRESSIONS[i] == _c)
        {
            return 1;
        }
    }

    return 0;
}

int is_valid_component(const char* _raw_poly, int _start_component, int _end_component, int _n_component)
{
    int
    i,
    sign = 0,
    digits = 0,
    x = 0;

    for(i = _start_component; i <= _end_component; i++)
    {
        char current_char = _raw_poly[i];

        // checks if the char is valid
        if(!is_valid_char(current_char))
        {
            return 0;
        }

        // checks that sign is not followed by another sign
        if(sign || digits || x)
        {
            if(current_char == '+' || current_char == '-') { return 0; }
        }

        // checks that 'x' is not followed by another 'x'
        if(x)
        {
            if(current_char == 'x') { return 0; }
        }

        // checks that digit or 'x' is not followed by space
        if(digits || x)
        {
            if(current_char == ' ') { return 0; }
        }

        if(current_char == 'x') { x = 1; }

        if(current_char == '+' || current_char == '-') { sign = 1; }

        if(current_char >= '0' && current_char <= '9') { digits = 1; }
    }

    //checks if the first component is not a constant
    if(_n_component == 1 && x != 1) { return 0; }

    //
    if(_n_component != 1 && sign == 0) { return 0; }

    return 1;
}

int extract_sign(const char *_raw_poly, int _start_component)
{
    if(_raw_poly[_start_component] == '-')
    {
        return -1;
    }

    return 1;
}

int extract_number(const char *_raw_poly, int _start_component, int _end_component)
{
    int number = 0;
    int i;

    for(i = _start_component; i <= _end_component; i++)
    {
        char current_char = _raw_poly[i];

        if(current_char == ' ' || current_char == '+' || current_char == '-')
        {
            continue;
        }

        if(current_char == 'x')
        {
            if(number == 0)
            {
                number = 1;
            }

            break;
        }

        number = (number * 10) + (current_char - '0');
    }

    return number;
}

int extract_power(const char *_raw_poly, int _start_component, int _end_component)
{
    int
    i,
    power = 0,
    x = 0;

    for(i = _start_component; i <= _end_component; i++)
    {
        char current_char = _raw_poly[i];

        if(current_char == 'x')
        {
            x = 1;
            continue;
        }

        if(x)
        {
            power = (power * 10) + (current_char - '0');
        }
    }

    if(x && !power) { power = 1; }

    return power;
}

void find_component(const char *_raw_poly, int *_start_component, int *_end_component)
{
    int i,
    x = 0;
    char c;

    for(i = *(_start_component);; i++)
    {
        if(_raw_poly[i] != ' ' || _raw_poly[i] == '\0')
        {
           *_start_component = i;
           break;
        }
    }

    if(_raw_poly[*_start_component] == '\0')
    {
        *_end_component = *_start_component;
        return;
    }

    for(i = 1;; i++)
    {
        c = _raw_poly[i + *_start_component];

        if((c >= '0' && c <= '9') || (c == 'x'))
        {
            x = 1;
        }

        if(c == ' ' && x)
        {
            *_end_component = *_start_component + i -1;
            break;
        }

        if(c == '+' || c== '-' || c == '\0')
        {
            *_end_component = *_start_component + i -1;
            break;
        }
    }
}

void add_component(int _sign, int _coef, int _power, Polynome _polynome)
{
    if (_polynome == NULL)
    {
        return;
    }

    _polynome->components[_power] = _sign * _coef;
}

Polynome parser(const char * _raw_poly)
{
    int sign, number, power, n_component = 1, start = 0, end = -1, previous_power = 0;
    Polynome polynome = NULL;

    while(_raw_poly[end+1] != '\0')
    {
        // finds component start and end
        find_component(_raw_poly, &start, &end);

        //
        if(_raw_poly[start] == '\0') { break; }

        // checks if the component is valid
        if(!is_valid_component(_raw_poly, start, end, n_component)) { return NULL; }

        // extracts relevant information about component
        sign = extract_sign(_raw_poly, start);
        number = extract_number(_raw_poly, start, end);
        power = extract_power(_raw_poly, start, end);

        // initializes polynome one time
        if(n_component == 1 && polynome == NULL) { polynome = Poly_init(power); }

        // checks if previous power is grater than current power
        if(n_component > 1 && previous_power <= power)
        {
            Poly_free(polynome);
            return NULL;
        }

        // add new component to polynome
        add_component(sign, number, power, polynome);

        // incrementations
        start = end + 1;
        end = start;
        previous_power = power;
        n_component++;
    }

    return polynome;
}
