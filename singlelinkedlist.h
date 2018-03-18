#ifndef SINGLELINKEDLIST
#define SINGLELINKEDLIST

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <assert.h>
#include <math.h>

#include "linkedlistutils.h"

typedef struct single_linked_int_list {
    int value;
    struct single_linked_int_list * next;
} sli_list;

/* Allocate a new single linked integer list. */
sli_list * sli_list_new(const int value);

/* Remove the first single list item and free the memory. */
void sli_list_delete_item(sli_list ** ll);

/* Deallocate the complete single list */
void sli_list_delete_all(sli_list ** ll);

char * sli_list_to_string(sli_list * ll);
void sli_list_print(sli_list * ll);
int sli_list_count(sli_list * ll);
void sli_list_push(sli_list ** ll, int value);
int sli_list_pop(sli_list ** ll);

#endif