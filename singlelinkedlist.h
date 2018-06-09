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

typedef struct single_linked_str_list {
    struct single_linked_str_list * next;
    char * value;
    size_t size;
} sls_list;

sls_list * sls_list_new(char * value, size_t size);
void sls_list_push(sls_list ** ll, char * value, size_t size);
void sls_list_pop(sls_list ** ll, char * result, size_t * rsize);
void sls_list_delete_item(sls_list ** ll);
void sls_list_delete_all(sls_list ** ll);
char * sls_list_to_string(sls_list * ll);
void sli_list_print(sli_list * ll);
int sls_list_count(sli_list * ll);


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
