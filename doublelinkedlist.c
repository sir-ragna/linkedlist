
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

