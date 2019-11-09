#include <stdio.h>
#include "parser.h"

int is_valid_char(const char _c)
{
    int i ;

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
    sign = 0,
    digits = 0,
    x = 0;
    
    int i;
    for(i = _start_component; i <= _end_component || *(_raw_poly+i); i++)
    {
        if(sign || digits || x)
        {
            if(*(_raw_poly+i) == '+' || *(_raw_poly+i) == '-')
            {
                return 0;
            }
        }

        if(x)
        {
            if(*(_raw_poly+i) == 'x')
            {
                return 0;
            }
        }

        if(*(_raw_poly+i) == 'x') { x = 1; }
        
        if(*(_raw_poly+i) == '+' || *(_raw_poly+i) == '-') { sign = 1; }

        if(*(_raw_poly+i) >= '0' && *(_raw_poly+i) <= '9') { digits = 1; }
    }

    return 1;
}

int extract_sign(const char *_raw_poly, int _start_component)
{
    if(*(_raw_poly+_start_component) == '-')
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
        if(*(_raw_poly+i) == ' ' || *(_raw_poly+i) == '+' || *(_raw_poly+i) == '-')
        {
            continue;
        }

        if(*(_raw_poly+i) == 'x')
        {
            if(number == 0)
            {
                number++;
            }

            break;
        }
        
        number = (number*10)+(*(_raw_poly+i)-'0');
    }
    
    return number;
}

int extract_power(const char *_raw_poly, int _start_component, int _end_component)
{
    int power = 1;
    int i;
    int j;

    for(i = _start_component; i <= _end_component; i++)
    {
        if(*(_raw_poly+i) == 'x')
        {    
            for(j = i+1; j <= _end_component; j++)
            {
                printf("\ni=%d => %d => power = %d\n", i, j, power);
                power = (power*10)+(*(_raw_poly+j)-'0');
            }

            return power;
        }      
    }
    
    return 0;
}
