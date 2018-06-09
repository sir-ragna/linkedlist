
#include "singlelinkedlist.h"

sls_list * sls_list_new(char * value, size_t size)
{
    sls_list * ll;
    ll = malloc(sizeof(sls_list));

    assert(ll != NULL);

    ll->value = value;
    ll->size = size;
    ll->next = NULL;
    return ll;
}

void sls_list_push(sls_list ** ll, char * value, size_t size)
{
    sls_list * new_ll;
    new_ll = sls_list_new(value, size);

    new_ll->next = *ll;
    *ll = new_ll;
}

void sls_list_pop  (sls_list ** ll, char * value, size_t * size)
{
    sls_list * current_head;
    current_head = *ll;

    if (*ll != NULL) {
        value = current_head->value;
        
        size = &current_head->size;
        *ll = current_head->next;
        free(current_head);
    }
}
/*
char * sls_list_to_string(sls_list * ll)
{
    char * format = "[%d] => %s\n";
    int format_len = strlen(format);

    char * result;
    result = (char *)malloc(1);
    result[0] = 0x00;
    int i = 1; 

    while(1) {
        int item_value = ll->value;
        char * item_value;

        int val_char_length = int_length(item_value); 

    }
}
*/
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
        int item_value = ll->value;
        char * item_string;

        int val_char_length = int_length(item_value);

        int item_str_len = (
            format_len +      /* Length of the format string */
            val_char_length + /* Length of the value integer in char */
            int_length(i) +   /* Length of the index integer */
            1   /* Zero byte terminator */
        );

        item_string = malloc(item_str_len);
        
        /* Append & format the string to our result */
        sprintf(item_string, 
                format, 
                i - 1,  /* We subtract 1 to enumerate from 0 */
                item_value);

        /* Realocate memory for our result string */
        result = (char *) realloc(result, (
            strlen(result) + /* Current str length */
            item_str_len     /* Length of this item str 
                              * (terminator included) */
        ));

        strcat(result, item_string);

        free(item_string);

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
    printf("%s\n", str);
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
