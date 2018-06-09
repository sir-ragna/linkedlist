
#include <stdio.h>
#include "singlelinkedlist.h"
#include "doublelinkedlist.h"

/* Used to test the other linked list code */

int main(int argc, char ** argv)
{
    printf("Example usage of the single linked integer list\n");
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
    printf("Amount: %d items\n", sli_list_count(ll));

    sli_list_delete_item((sli_list **) &ll);
    sli_list_delete_item((sli_list **) &ll);
    sli_list_delete_item((sli_list **) &ll);
    sli_list_print(ll);
    sli_list_delete_item((sli_list **) &ll);
    sli_list_delete_item((sli_list **) &ll);
    sli_list_delete_item((sli_list **) &ll); // One too many :D

    printf("Example usage of the double linked integer list\n");
    dli_list * dlli;
    dlli = dli_list_new(4444);
    dli_list_push((dli_list **) &dlli, 1234);
    dli_list_push((dli_list **) &dlli, 431);
    dli_list_push((dli_list **) &dlli, 0xFF);
    dli_list_push((dli_list **) &dlli, 1);
    dli_list_push((dli_list **) &dlli, -0xC0);

    printf("Amount: %d items\n", dli_list_count(dlli));
    dli_list_print(dlli);

    dli_list_pop((dli_list **) &dlli);
    dli_list_pop((dli_list **) &dlli);
    dli_list_pop((dli_list **) &dlli);
    dli_list_pop((dli_list **) &dlli);
    dli_list_pop((dli_list **) &dlli);
    dli_list_pop((dli_list **) &dlli);
    dli_list_pop((dli_list **) &dlli); 
    /* ^ One too many. Doesn't crash, needs logging though. 
     * Maybe I should add a macro you to choose between logging
     * or crashing.
     */

    assert(dlli == NULL);
    printf("%s\n", "The double linked integer list has been cleaned up.");
    
    char retstr[] = "Hello <o(°_-_°)ô\r\n";

    printf(retstr);
    

    sls_list * mystringlinkedlist = NULL;
    mystringlinkedlist = sls_list_new(retstr, sizeof(retstr));

    char * azert = NULL;
    size_t len = 0;
    sls_list_pop((sls_list **) &mystringlinkedlist, azert, len);

    sls_list_push((sls_list **) &mystringlinkedlist, azert, len);
    sls_list_push((sls_list **) &mystringlinkedlist, "Foo Bar", sizeof("Foo Bar"));
    sls_list_push((sls_list **) &mystringlinkedlist, azert, len);



    return 0;
}