/**
 * double linked list
 * @date 2020-8-8
 * @author forsilence
 */

# ifndef _DLLIST_H
# define _DLLIST_H
#include<stdbool.h>

// element type 
# ifndef elem_type
# define elem_type int
# endif

// structure
/**
 *   forword <-- node(value) --> backword
 */
typedef struct dllnode{
    struct dllnode *forword;
    struct dllnode *backword;
    elem_type value;
}dllnode;
typedef dllnode dllist;

/**
 * opertation in dllist
 */

// create a dll
dllnode *init_dll();

// add node to dll
bool push_dllnode(dllist *dll,elem_type x);


// delete node from dll
elem_type de_dll(dllist *dll,int loc);

// length of dll
int dll_len(dllist *dll);

// find element in loc location
dllnode *dll_locate(dllist *dll,int loc);

// last node
dllnode *dll_last(dllist *dll);

// print all element
void print(dllist *dll);

# endif