/*
    module  : not.c
    version : 1.2
    date    : 05/06/16
*/
#include "interp.h"

/*
not  :  X  ->  Y
Y is the complement of set X, logical negation for truth values.
*/
/* not.c */
PRIVATE void not_(void)
{
    int num = 0;

    ONEPARAM("not");
    switch (stk->op) {
    case SET_:
	if (OUTSIDE)
	    stk->u.set = ~stk->u.set;
	else
	    UNARY(SET_NEWNODE, ~stk->u.set);
	return;
    case STRING_:
	num = stk->u.str && *stk->u.str != 0;
	break;
    case LIST_:
	num = !stk->u.lis;
	break;
    case BOOLEAN_:
    case CHAR_:
    case INTEGER_:
	num = !stk->u.num;
	break;
    case FLOAT_:
	num = !stk->u.dbl;
	break;
    case FILE_:
	num = !stk->u.fil;
	break;
    default:
	BADDATA("not");
    }
    if (OUTSIDE) {
	stk->u.num = num;
	stk->op = BOOLEAN_;
    } else
	UNARY(BOOLEAN_NEWNODE, num);
}
