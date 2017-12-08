
#include "singlelinkedlist.h"

sli_list * sli_list_new(const int value)
{
    sli_list * ll;
    ll = malloc(sizeof(sli_list));

    /* If malloc fails,
     * simply give up */
    assert(ll != NULL);

    ll->value = value;

    /* To stop valgrind from complaining.
     * "Conditional jump or move depends on uninitialised value" */
    ll->next = NULL; 
    return ll;
}

void sli_list_push(sli_list ** ll, int value)
{
    sli_list * new_ll;
    new_ll = sli_list_new(value);

    new_ll->next = *ll;
    *ll = new_ll;
}

int sli_list_pop(sli_list ** ll)
{
    int value;
    sli_list * current_head;
    current_head = *ll;

    if (*ll != NULL) {
        value = current_head->value;
        *ll = current_head->next;    
        free(current_head);
    }

    return value;
}

char * sli_list_to_string(sli_list * ll)
{
    char * format = "[%d] => %d\n";
    int format_len = strlen(format);

    char * result;
    result = (char *)malloc(1);
    result[0] = 0x00;
    int i = 1; /* Start from 1 because log10 of '0' is -infinite */

    while (1) {
        int val = ll->value;
        char * ll_value_s;

        /* Calculate the length these integers have
         * when they are converted to characters. */
        int val_char_length = (val < 0 ? 
            ((int) floor(log10(abs(val)) + 1)) + 1 : /* Add 1 char for the minus sign '-' */
            (int) floor(log10(val) + 1)
        );
        int i_char_length = (int) floor(log10(i) + 1);

        ll_value_s = malloc(
            format_len +       /* Length of the format string */
            val_char_length +  /* Length of the value integer in char */
            i_char_length +    /* Length of the index integer in char */
            1                  /* Zero byte terminator */
        );
        
        /* Append & format the string to our result */
        sprintf(ll_value_s, 
                format, 
                i - 1,  /* We subtract 1 to enumerate from 0 */
                val);

        int new_str_size = (
            strlen(result) +   /* Current str Length */
            format_len +       /* Length of the format string */
            val_char_length +  /* Length of the value integer in char */
            i_char_length +    /* Length of the index integer in char */
            1                  /* Zero byte terminator */
        );

        /* Realocate memory for our our string */
        result = (char *) realloc(result, new_str_size);

        strcat(result, ll_value_s);

        free(ll_value_s);

        if (ll->next) {
            i++;
            ll = ll->next;
        } else {
            break;
        }
    }

    return result;
}

void sli_list_print(sli_list * ll)
{
    char * str;
    str = sli_list_to_string(ll);
    printf("%s", str);
    free(str);
}

void sli_list_delete_item(sli_list ** ll)
{
    sli_list_pop(ll);
}

void sli_list_delete_all(sli_list ** ll)
{
    while(*ll != NULL) {
        sli_list_delete_item(ll);
    }
}

int sli_list_count(sli_list * ll)
{
    if (ll == NULL) {
        return 0;
    }
    
    int count = 1;

    while(ll->next != NULL) {
        count++;
        ll = ll->next;
    }

    return count;
}
