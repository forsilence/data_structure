/**
 * This program is for function body.
 */

# include"stack.h"
# include<stdlib.h>
/**
 * stack methods
 */
// initialize a stack.
stack *init_stack()
{
    stack * st = (stack*)malloc(sizeof(stack));
    st->length =0;
    return st;
}

// push element to stack
int push(stack* st,elem_type x)
{
    if (st->length == STACK_MAX_LEN)    // stack is full?
        return STACK_FULL;
    // not full , push element into it.
    st->data[st->length] = x;
    st->length++;
    return STACK_NOT_FULL;
}

/**
 *  when stack is empty,it will return EMPTY;
 *  else pop and return STACK_NOT_FULL.
 */
elem_type pop(stack *st)
{
    if (empty(st) == EMPTY)
        return st->data[STACK_MAX_LEN];
    st->length--;
    return st->data[st->length+1];
}

// empty ?
int empty(stack *st)
{
    if (st->length == 0)
        return EMPTY;
    else 
        return !EMPTY;
}