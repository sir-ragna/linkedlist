#ifndef DOUBLELINKEDLIST
#define DOUBLELINKEDLIST

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <assert.h>
#include <math.h>

#include "linkedlistutils.h"

typedef struct double_linked_int_list {
    int value;
    struct double_linked_int_list * prev;
    struct double_linked_int_list * next;
} dli_list;

dli_list * dli_list_new(const int value);

void dli_list_delete_item(dli_list ** dlli);
void dli_list_delete_all(dli_list ** dlli);
char * dli_list_to_string(dli_list * dlli);
void dli_list_print(dli_list * dlli);
int dli_list_count(dli_list * dlli);
void dli_list_push(dli_list ** dlli, int value);
int dli_list_pop(dli_list ** dlli);

#endif
