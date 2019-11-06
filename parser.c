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