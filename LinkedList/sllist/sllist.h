/**
 * This a single linked list.
 * @date 2020-8-8
 * @author forsilence
 */

# ifndef _SLLIST_H
# define _SLLIST_H
# include<stdbool.h>
# include<stdio.h>

/**
 * This will define element type as int by default,if have not defined.
 */
# ifndef elem_type
# define elem_type int
# endif

// single linked list structure
typedef struct node{
    elem_type value;
    struct node *next;
}sllnode;

typedef sllnode sllist;
/**
 * operation in single linked list
 */

// initialize a single linked list
sllist *init_sllist();

// add node to sllist
bool add_node(sllnode *sl,elem_type x);

// delete node
elem_type denode(sllnode *sl,int loc);

// single linked list length
int sll_len(sllist *sl);

// last node
sllnode *last(sllist *sl);

// node in location
sllnode *locate(sllist *sl,int loc);

// show all elements
void print(sllist *sl);

# endif