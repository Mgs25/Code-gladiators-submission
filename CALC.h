/*----- FILE CALC.H --------------------------------------------------*/
/*                                                                    */
/* Header file for CALC.C PUSHPOP.C READTOKN.C                        */
/* a simple calculator                                                */
/*--------------------------------------------------------------------*/

#ifndef _CALC_H_                                                // Added header guards to prevent multiple definition
#define _CALC_H_                                                // entities in CALC.h will not be defined more than once
// Header guards

/*--------------------------------------------------------------------*/
/* CHANGES IN "CALC.h"                                                */
/* Added header guards to prevent multiple definition of methods     */
/*--------------------------------------------------------------------*/

typedef enum toks {
    T_INTEGER,
    T_PLUS,
    T_TIMES,
    T_MINUS,
    T_DIVIDE,
    T_EQUALS,
    T_STOP
} Token;

Token read_token(char buf[]);

typedef struct int_link  {
    struct int_link* next;
    int i;
} IntLink;

typedef struct int_stack {
    IntLink* top;
} IntStack;

extern void push(IntStack* , int);                    
extern int pop(IntStack*);                         

#endif
