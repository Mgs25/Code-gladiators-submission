/*----- FILE READTOKN.C ----------------------------------------------*/
/*                                                                    */
/* A function to read input and tokenize it for a simple calculator   */
/*--------------------------------------------------------------------*/
#include "CALC.h"
#include <ctype.h>
#include <stdio.h>
/*--------------------------------------------------------------------*/
/* action: get next input char, update index for next call            */
/* return: next input char                                            */
/*--------------------------------------------------------------------*/

static const char nextchar() {                                          // Removed void parameter to maintain consistency 
/*--------------------------------------------------------------------*/
/* input  action:                                                     */
/*    2      push 2 on stack                                          */
/*    18     push 18                                                  */
/*    +      pop 2, pop 18, add, push result (20)                     */
/*    =      output value on the top of the stack (20)                */
/*    5      push 5                                                   */
/*    ⁄      pop 5, pop 20, divide, push result (4)                   */
/*    =      output value on the top of the stack (4)                 */
/*--------------------------------------------------------------------*/

  const char* buf_in  = "2 18 + = 5 / ="; // Input buffer               // Modified char* buf_in to const char* buf_in, to avoid problematic conversion
                                                                        // from string constant (const char*) to char*
  
  /********************* Testing *******************************/
  /* //const char* buf_in  = "2 18 + = 5 / = 80 80 + = 40 + =" */
  /* const char* buf_in  = "6 5 * = ";    //Output = 30        */
  /* const char* buf_in  = "10 10 + = ";  //Output = 20        */
  /* const char* buf_in  = "20 2 / =";    //Output = 10        */
  /* const char* buf_in  = "20 30 - =";   //Output = 10        */
  /*************************************************************/
  
  static int index;     /* starts at 0 */
  char ret;
  ret = buf_in[index];
  ++index;
  return ret;
}

/*--------------------------------------------------------------------*/
/* output: buf - null terminated token                                */
/* return: token type                                                 */
/* action: reads chars through nextchar() and tokenizes them          */
/*--------------------------------------------------------------------*/
const Token read_token(char buf[]) {
  int i;
  char c;
  
  /* skip leading white space */
  c = nextchar();                                                       // Replaces for() loop with while() to improve readabiltiy
  while (c == ' ')
      c = nextchar();
  
  buf[0] = c;  /* get ready to return single char e.g."+" */
  buf[1] = 0;
  
  switch(c) {
    case '+' : return T_PLUS;
    case '-' : return T_MINUS;
    case '*' : return T_TIMES;
    case '/' : return T_DIVIDE;
    case '=' : return T_EQUALS;
    default:
    // Read digits
      i = 0;
      while (isdigit(c)) {
        buf[i++] = c;
        c = nextchar();
      }
      buf[i] = 0;
      
      if (i==0)
        return T_STOP;
      else
        return T_INTEGER;
  }
}