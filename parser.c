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
