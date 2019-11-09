#include <stdio.h>
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

int is_valid_component(const char* _raw_poly, int _start_component, int _end_component)
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
