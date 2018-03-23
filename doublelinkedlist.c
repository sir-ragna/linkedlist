
#include "doublelinkedlist.h"

dli_list * dli_list_new(const int value)
{
    dli_list * dlli;
    dlli = malloc(sizeof(dli_list));

    assert(dlli != NULL);

    dlli->value = value;

    /* Stop valgrind from complaining. */
    dlli->next = NULL;
    dlli->prev = NULL;

    return dlli;
}

void dli_list_push(dli_list ** dlli, int value)
{
    dli_list * new_dli;
    new_dli = dli_list_new(value);
    new_dli->next = *dlli;
    new_dli->next->prev = new_dli;
    *dlli = new_dli;
}

int dli_list_pop(dli_list ** dlli)
{
    int value;
    dli_list * current_head;
    current_head = *dlli;

    if (*dlli != NULL) {
        /* Make sure this is head.
         * We are leaking memory otherwise. */
        assert(current_head->prev == NULL);
        
        value = current_head->value;
        *dlli = current_head->next;

        if (current_head->next != NULL) {
            /* Clean up circular reference */
            current_head->next->prev = NULL;
        }

        free(current_head);
    }

    return value;
}

char * dli_list_to_string(dli_list * dlli)
{
    char * format = "[%d] => %d\n";
    int format_len = strlen(format);

    char * result;
    result = (char *)malloc(1);
    result[0] = 0x00;
    int i = 1;

    while (1) {
        int item_value = dlli->value;
        char * item_string;
        int var_char_length = int_length(item_value);

        int item_str_len = (
            format_len +
            var_char_length + 
            int_length(i) + 
            1
        );

        item_string = malloc(item_str_len);
        sprintf(item_string,
                format,
                i - 1, /* Starte enumeration from 0 */
                item_value
        );

        result = (char *) realloc(result, 
            (strlen(result) + /* Current length */
            item_str_len)     /* Length of str item
                               * includes terminator */
        );

        strcat(result, item_string);
        free(item_string);

        if (dlli->next) {
            i++;
            dlli = dlli->next;
        } else {
            break;
        }        
    }

    return result;
}

void dli_list_print(dli_list * dlli)
{
    char * str;
    str = dli_list_to_string(dlli);
    printf("%s\n", str);
    free(str);
}

void dli_list_delete_item(dli_list ** dlli)
{
    dli_list_pop(dlli);
}

void dli_list_delete_all(dli_list ** dlli)
{
    while (*dlli != NULL) {
        dli_list_delete_item(dlli);
    }
}

int dli_list_count(dli_list * dlli)
{
    if (dlli == NULL) {
        return 0;
    }

    int count = 1;

    while (dlli->next != NULL) {
        count++;
        dlli = dlli->next;
    }

    return count;
}