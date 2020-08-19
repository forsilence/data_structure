/**
 * This program is for accomplishing stack .
 * It's an array.
 * @data 2020-8-7.
 * @author forsilence.
 */

# ifndef _STACK_H
# define _STACK_H

// Max element this stack can store.
# define STACK_MAX_LEN 1 << 16

/**
 * define elem_type 
 * if have defined , element type will not be changed 
 * if not , element type will be defined to int by this.
 */
# ifndef elem_type
# define elem_type int
# endif
/**
 * markups for stack storage status.
 */
# define STACK_FULL 2       // stack can not store any more
# define STACK_NOT_FULL 3  // can store element
# define EMPTY 1

// stack data structure
typedef struct {
    elem_type data[STACK_MAX_LEN];
    int length;
} stack;

/**
 * stack methods
 */
// initialize a stack.
stack *init_stack();

// push element to stack
int push(stack* st,elem_type x);

// pop out element ,return pop element
elem_type pop(stack *st);

// stack is empty ?
int empty(stack *st);

# endif