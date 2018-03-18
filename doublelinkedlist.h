#ifndef DOUBLELINKEDLIST
#define DOUBLELINKEDLIST

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <assert.h>
#include <math.h>

typedef struct double_linked_int_list {
    int value;
    struct double_linked_int_list * prev;
    struct double_linked_int_list * next;
} dli_list;

dli_list * dli_list_new(const int value);

void dli_list_delete_item(dli_list ** ll);
void dli_list_delete_all(dli_list ** ll);
char * dli_list_to_string(dli_list * ll);
void dli_list_count(dli_list * ll);
void dli_list_push(dli_list ** ll, int value);
int dli_list_pop(dli_list ** ll);

#endif
