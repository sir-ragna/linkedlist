
#include <stdio.h>
#include "singlelinkedlist.h"


int main(int argc, char ** argv)
{
    sli_list *  ll;
    ll = sli_list_new(999999);
    sli_list_push((sli_list **) &ll, 22);
    sli_list_push((sli_list **) &ll, 1);

    sli_list_print(ll);

    sli_list_delete_all((sli_list **) &ll);

    ll = sli_list_new(123);
    sli_list_push((sli_list **) &ll, 0xFF);
    sli_list_push((sli_list **) &ll, 044);
    sli_list_push((sli_list **) &ll, -12);
    sli_list_push((sli_list **) &ll, 1);

    sli_list_print(ll);
    printf("Amount: %d", sli_list_count(ll));

    sli_list_delete_item((sli_list **) &ll);
    sli_list_delete_item((sli_list **) &ll);
    sli_list_delete_item((sli_list **) &ll);
    sli_list_print(ll);
    sli_list_delete_item((sli_list **) &ll);
    sli_list_delete_item((sli_list **) &ll);
    sli_list_delete_item((sli_list **) &ll); // One too many :D


    return 0;
}