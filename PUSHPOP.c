/*----- FILE PUSHPOP.C -----------------------------------------------*/
/*                                                                    */
/* A push and pop function for a stack of integers                    */
/*--------------------------------------------------------------------*/
#include "calc.h"
#include <stdlib.h>

/*--------------------------------------------------------------------*/
/* input:  stk - stack of integers                                    */
/*         num - value to push on the stack                           */
/* action: get a link to hold the pushed value, push link on stack    */
/*                                                                    */
void push(IntStack* stk, const int num) {                                   // Improved const-correctness, number is not modified in push function
    IntLink* ptr;
    ptr       = (IntLink*)malloc(sizeof(IntLink));                          // Replaced illegal character '-', '/' with
    ptr->i    = num;
    ptr->next = stk->top;
    stk->top  = ptr;
}

/*--------------------------------------------------------------------*/
/* return: int value popped from stack                                */
/* action: pops top element from stack and gets return value from it  */
/*--------------------------------------------------------------------*/
int pop(IntStack* stk) {
    IntLink* ptr;
    int num;
    ptr      = stk->top;
    num      = ptr->i;
    stk->top = ptr->next;
    free(ptr);
    return num;
}
