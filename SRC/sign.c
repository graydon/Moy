/*
    module  : sign.c
    version : 1.2
    date    : 05/06/16
*/
#include "interp.h"

/*
sign  :  N1  ->  N2
Integer N2 is the sign (-1 or 0 or +1) of integer N1,
or float N2 is the sign (-1.0 or 0.0 or 1.0) of float N1.
*/
/* sign.c */
PRIVATE double fsgn(double f)
{
    if (f < 0)
	return -1.0;
    else if (f > 0)
	return 1.0;
    else
	return 0.0;
}

PRIVATE void sign_(void)
{
    ONEPARAM("sign");
    FLOAT("sign");
    if (OUTSIDE) {
	if (stk->op == FLOAT_)
	    stk->u.dbl = fsgn(stk->u.dbl);
	else if (stk->u.num < 0 || stk->u.num > 1)
	    stk->u.num = stk->u.num > 0 ? 1 : -1;
    } else if (stk->op == FLOAT_)
	UNARY(FLOAT_NEWNODE, fsgn(FLOATVAL));
    else if (stk->u.num < 0 || stk->u.num > 1)
	UNARY(INTEGER_NEWNODE, stk->u.num > 0 ? 1 : -1);
}
