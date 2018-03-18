
#include "linkedlistutils.h"

int int_length(const int number)
{
    return (int) (number < 0 ?
            (floor(log10(abs(number)) + 1)) + 1  
            /* ^ Add 1 for the minus sign '-' */
        :
            floor(log10(number) + 1)
    );
}
